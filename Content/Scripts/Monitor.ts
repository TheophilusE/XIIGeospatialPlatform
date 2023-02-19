import xii = require("TypeScript/xii");

export class MsgSwitchMonitor extends xii.Message {
  XII_DECLARE_MESSAGE_TYPE;

  renderTarget: string;
  screenMaterial: string;
}

export class Monitor extends xii.TypescriptComponent {
  /* BEGIN AUTO-GENERATED: VARIABLES */
    /* END AUTO-GENERATED: VARIABLES */

  constructor() {
    super();
  }

  static RegisterMessageHandlers() {
    xii.TypescriptComponent.RegisterMessageHandler(
      MsgSwitchMonitor,
      "OnMsgSwitchMonitor"
    );
  }

  OnMsgSwitchMonitor(msg: MsgSwitchMonitor): void {
    let owner = this.GetOwner();
    let display = owner.FindChildByName("Display");
    let mat = new xii.MsgSetMeshMaterial();

    mat.MaterialSlot = 0;
    mat.Material = msg.screenMaterial;

    display.SendMessage(mat);

    let activator = display.TryGetComponentOfBaseType(
      xii.RenderTargetActivatorComponent
    );

    activator.RenderTarget = msg.renderTarget;
  }
}
