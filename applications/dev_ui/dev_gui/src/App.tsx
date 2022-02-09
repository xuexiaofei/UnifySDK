import React, { Component } from 'react';
import { BrowserRouter, Redirect, Route, Switch } from 'react-router-dom';
import './app.css';
import 'react-toastify/dist/ReactToastify.css';
import Header from './components/header/header';
import Navbar from './components/navbar/navbar';
import { ToastContainer, toast } from 'react-toastify';
import { AppState, LocalStorage } from './app-types';
import SmartStart from './pages/smart-start/smart-start';
import { Nodes } from './pages/nodes/nodes';
import BaseClusters from './pages/base-clusters/base-clusters';
import { ClusterTypeAttrs } from './cluster-types/cluster-type-attributes';
import { ClusterTypes } from './cluster-types/cluster-types';
import { ClusterViewOverrides } from './pages/base-clusters/cluster-view-overrides';
import { NavbarItems } from './components/navbar/navbar-items';
import Groups from './pages/groups/groups';
import OTA from './pages/ota/ota';
import { Image } from "./pages/ota/ota-types";
import * as IoIcons from 'react-icons/io';
import RFTelemetryList from './pages/rf-telemetry/rf-telemetry-list/rf-telemetry-list';
import RFTelemetry from './pages/rf-telemetry/rf-telemetry/rf-telemetry';
import UPTI from './pages/upti/upti-list/upti-list';
import UPTITrace from './pages/upti/upti-trace/upti-trace';
import Locators from './pages/locators/locators';

class App extends Component<{}, AppState> {
  constructor(props: {}) {
    super(props)
    if (!localStorage.uic)
      localStorage.uic = JSON.stringify({});

    this.onMessage = this.onMessage.bind(this);
    this.state = {
      SocketServer: {} as WebSocket,
      IsConnected: false,
      IsSideBarCollapsed: true,
      NodeList: [],
      GroupList: [],
      SmartStartList: [],
      OTAImageList: ([] as Image[]),
      UPTI: { List: [], Trace: {} }
    }
    this.changeHeader = React.createRef();
    this.changeNodes = React.createRef();
    this.changeGroups = React.createRef();
    this.changeTelemetry = React.createRef();
    this.changeOTA = React.createRef();
    this.changeSmartStart = React.createRef();
    this.changeClusters = React.createRef();
    this.changeUPTI = React.createRef();
    this.changeUPTITrace = React.createRef();
    setTimeout(() => this.initWebSocket(), 100);
    this.handleIsConnectedChange = this.handleIsConnectedChange.bind(this);
  }

  changeHeader: any;
  changeNodes: any;
  changeGroups: any;
  changeTelemetry: any;
  changeOTA: any;
  changeSmartStart: any;
  changeClusters: any;
  changeUPTI: any;
  changeUPTITrace: any;
  attemptsCount = 0;

  resetState() {
    this.handleNodesChange([]);
    this.handleSmartStartChange([]);
    this.handleOTAChange([]);
    this.handleGroupsChange([]);
    this.handleUPTIChange([]);
    this.setState({ UPTI: { List: [], Trace: {} } });
  }

  handleIsConnectedChange(isConnected: boolean) {
    this.setState({ IsConnected: isConnected });
    if (isConnected !== null)
      this.changeHeader?.current.toggleCollapse(isConnected)
  }

  handleNodesChange(list: any[]) {
    if (this.state.NodeList && this.state.NodeList.length)
      list.forEach(i => {
        let currentNode = (this.state.NodeList as any[]).find(j => j.Unid === i.Unid) as any;

        if (currentNode && currentNode.NetworkStatus !== i.NetworkStatus && !this.changeNodes.current?.state.InclusionProccess
          && ((currentNode as any).NetworkStatus === "Offline" || (currentNode as any).NetworkStatus === "Unavailable"
            || i.NetworkStatus === "Offline" || i.NetworkStatus === "Unavailable"))
          i.NetworkStatus === "Offline" || i.NetworkStatus === "Unavailable"
            ? toast(`${currentNode.ClusterTypes.join(", ") || ""} [${currentNode.Unid}] went offline`, { type: "warning" })
            : toast(`${currentNode.ClusterTypes.join(", ") || ""} [${currentNode.Unid}] is back online`, { type: "success" });
      });
    this.setState({ NodeList: list });
    if (this.changeNodes.current)
      this.changeNodes.current.search(list);
    if (this.changeGroups.current)
      this.changeGroups.current.updateState(this.state.GroupList, list);
    if (this.changeOTA.current)
      this.changeOTA.current.updateNodeList(list);
    if (this.changeClusters.current)
      this.changeClusters.current.updateState(list);
  }

  handleSmartStartChange(list: any) {
    this.setState({ SmartStartList: list });
    if (this.changeSmartStart.current)
      this.changeSmartStart.current.search([...list]);
  }

  handleUPTIChange(list: any[]) {
    let upti = this.state.UPTI;
    upti.List = list;
    if (!list.length)
      upti.Trace = {};
    this.setState({ UPTI: upti });
    this.changeUPTI.current?.discoverCompleted();
  }

  handleUPTITraceChange(newTrace: any) {
    let upti = this.state.UPTI;
    if (newTrace.Trace.length === 0) upti.Trace[newTrace.SerialNumber] = [];
    else {
      if (!upti.Trace[newTrace.SerialNumber])
        upti.Trace[newTrace.SerialNumber] = [];
      upti.Trace[newTrace.SerialNumber].push(newTrace.Trace);
      if (upti.Trace[newTrace.SerialNumber].length > 200)
        upti.Trace[newTrace.SerialNumber] = upti.Trace[newTrace.SerialNumber].slice(-200);
    }
    this.setState({ UPTI: upti });
  }

  handleUPTITraceInit(trace: any) {
    let upti = this.state.UPTI;
    upti.Trace = trace;
    this.setState({ UPTI: upti });
  }

  handleGroupsChange(list: any) {
    this.setState({ GroupList: list });
    if (this.changeGroups.current)
      this.changeGroups.current.updateState(list, this.state.NodeList);
  }

  handleOTAChange(list: any) {
    this.setState({ OTAImageList: list });
    if (this.changeOTA.current)
      this.changeOTA.current.updateImageList([...list]);
  }

  getClusterProps(clusterType: string) {
    return {
      SocketServer: this.state.SocketServer,
      IsConnected: this.state.IsConnected,
      ClusterType: (ClusterTypes as any)[clusterType],
      ClusterTypeAttrs: ClusterTypeAttrs[clusterType],
      NodeList: this.state.NodeList,
      GroupList: this.state.GroupList,
      ClusterViewOverrides: (ClusterViewOverrides as any)[clusterType]
    }
  }

  getLocalStorage = () => {
    let storage: any;
    try {
      storage = JSON.parse(localStorage.uic);
    } catch (error) {
      storage = {};
      localStorage.uic = JSON.stringify(storage);
    }
    return storage;
  }

  setLocalStorage = (name: string, value: any) => {
    let storage = JSON.parse(localStorage.uic);
    storage[name] = value;
    localStorage.uic = JSON.stringify(storage);
  }

  toggleSideBar = () => {
    this.setState({ IsSideBarCollapsed: !this.state.IsSideBarCollapsed })
  }

  render() {
    let baseProps = {
      SocketServer: this.state.SocketServer,
      IsConnected: this.state.IsConnected,
      Storage: {
        Get: this.getLocalStorage,
        Set: this.setLocalStorage
      } as LocalStorage
    }

    return (
      <>
        <Header ref={this.changeHeader} {...baseProps} handleIsConnectedChange={this.handleIsConnectedChange} />
        <BrowserRouter>
          <div className={`split-container ${this.state.IsSideBarCollapsed ? "side-bar-collapsed" : ""}`}>
            <div className="split1">
              <Navbar ToggleSideBar={() => this.toggleSideBar()} IsSideBarCollapsed={this.state.IsSideBarCollapsed} />
            </div>
            <div className="split2">
              <span className="icon side-bar-collapse" onClick={this.toggleSideBar} >
                <IoIcons.IoIosArrowBack />
              </span>
              <div className="col-sm-12 no-padding-l">
                <Switch>
                  <Route path='/nodes' exact render={() => <Nodes ref={this.changeNodes} {...baseProps} NodeList={this.state.NodeList} />} />
                  <Route path='/groups' exact render={() => <Groups ref={this.changeGroups}  {...baseProps} NodeList={this.state.NodeList} GroupList={this.state.GroupList} />} />
                  <Route path='/smartstart' exact render={() => <SmartStart ref={this.changeSmartStart} {...baseProps} SmartStartList={this.state.SmartStartList} />} />
                  <Route path='/upti' exact render={() => <UPTI ref={this.changeUPTI}  {...baseProps} UPTI={this.state.UPTI} />} />
                  <Route path='/upti/:serial' render={(pr) => <UPTITrace ref={this.changeUPTITrace}
                    IsConnected={this.state.IsConnected || false} UPTI={this.state.UPTI} SerialNumber={pr.match.params.serial} SocketServer={this.state.SocketServer} />} />
                  <Route path='/rftelemetry' exact render={() => <RFTelemetryList ref={this.changeTelemetry}  {...baseProps} ClusterTypeAttrs={ClusterTypeAttrs.RFTelemetry} NodeList={this.state.NodeList} />} />
                  <Route path='/rftelemetry/:unid/:dst' exact render={(pr) => <RFTelemetry IsConnected={this.state.IsConnected || false} NodeList={this.state.NodeList} Unid={pr.match.params.unid} DestinationUNID={pr.match.params.dst} SocketServer={this.state.SocketServer} />} />
                  <Redirect from="/rftelemetry/:unid/" exact to="/rftelemetry/" />
                  <Route path='/locators' exact render={() => <Locators {...baseProps} NodeList={this.state.NodeList} />} />
                  <Route path='/ota' exact render={() => <OTA ref={this.changeOTA}  {...baseProps} NodeList={this.state.NodeList} />} />
                  {Object.keys(ClusterTypes).map((type, index) =>
                    <Route key={index} path={NavbarItems.find(i => i.name === type)?.path} exact render={() =>
                      <BaseClusters key={index} ref={this.changeClusters} {...this.getClusterProps(type)} />} />
                  )}
                  <Redirect from="/" to="/nodes" />
                </Switch>
              </div>
            </div>
          </div>
        </BrowserRouter>
        <ToastContainer
          position="bottom-right"
          autoClose={3000}
          hideProgressBar={false}
          newestOnTop={false}
          closeOnClick
          rtl={false}
          pauseOnFocusLoss
          draggable
          pauseOnHover />
      </>
    );
  }

  initWebSocket() {
    let protocol = window.location.protocol === "https:" ? "wss" : "ws";
    let port = window.location.protocol === "https:" ? "1343" : "1337";
    let connection = new WebSocket(`${protocol}://${window.location.hostname}:${port}`);
    connection.onopen = function () {
      console.log('Connection established');
    };
    connection.addEventListener("error", (error) => {
      console.log(`Some problem with your connection or the server is down: ${JSON.stringify(error)}`);
      this.toggleConnectState(false);
      if (window.location.protocol === "https:") {
        if (this.attemptsCount++ >= 3) {
          let url = `http://${window.location.hostname}:3080`;
          console.log("WSS does not support. Redirecting to " + url);
          window.location.replace(url);
        }
      }
    });
    connection.addEventListener("close", (event) => {
      console.log(`Connection closed`);
      this.toggleConnectState(false);
      setTimeout(() => this.initWebSocket(), 2000);
    });
    connection.onmessage = this.onMessage;
    this.setState({ SocketServer: connection });
  }

  toggleConnectState(isConnected: boolean) {
    this.setState({ IsConnected: isConnected });
    if (!isConnected)
      this.resetState();
    this.changeHeader?.current.toggleCollapse(isConnected);
  }

  onMessage(message: any) {
    let mes: any = {};
    try {
      mes = JSON.parse(message.data);
    } catch (e) {
      console.log('Invalid JSON: ', message.data);
      return;
    }
    switch (mes.type) {
      case "connect":
        this.handleIsConnectedChange(mes.data);
        if (!mes.data)
          this.resetState();
        break;
      case "certificates":
        this.changeHeader.current.changeConnect.current.updateAttr("CAName", mes.data?.CA);
        this.changeHeader.current.changeConnect.current.updateAttr("ClientKeyName", mes.data?.ClientKey);
        this.changeHeader.current.changeConnect.current.updateAttr("ClientCertificateName", mes.data?.ClientCertificate);
        break;
      case "error":
        toast(mes.data, { type: "error" });
        break;
      case "state":
        this.changeNodes.current && this.changeNodes.current.updateNodeState(mes.data);
        break;
      case "init-state":
        this.changeHeader.current?.changeConnect.current.updateAttr("Port", mes.data.Port);
        this.changeHeader.current?.changeConnect.current.updateAttr("Host", mes.data.Host);
        this.handleIsConnectedChange(mes.data.IsConnected);
        this.handleSmartStartChange(mes.data.SmartStart);
        this.handleGroupsChange(mes.data.Groups);
        this.handleNodesChange(mes.data.Nodes);
        this.handleOTAChange(mes.data.OTA);
        this.handleUPTIChange(mes.data.UPTI.List);
        this.handleUPTITraceInit(mes.data.UPTI.Trace);
        break;
      case "smart-start-list":
        this.handleSmartStartChange(mes.data);
        break;
      case "nodes-list":
        this.handleNodesChange(mes.data);
        break;
      case "groups":
        this.handleGroupsChange(mes.data);
        break;
      case "ota":
        this.handleOTAChange(mes.data);
        break;
      case "protocol-controller-state":
        this.changeNodes.current && this.changeNodes.current.handleProtocolControllerState(mes.data);
        break;
      case "upti-trace":
        this.handleUPTITraceChange(mes.data);
        break;
      case "upti-list":
        this.handleUPTIChange(mes.data);
        break;
    }
  }
}

export default App;
