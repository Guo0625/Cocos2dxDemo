/**
 * Created by Zack on 2018/4/10.
 */
var wb = window.wb || {};

wb.AppInfoLayer = cc.Layer.extend({
    fingerNum: 0,
    isShow: false,
    infoLayer: null,
    ctor: function () {
        this._super();
        this.initData();
        this.initUI();
        return true;
    },
    initData: function () {
        var listener = cc.eventManager.addListener({
            event: cc.EventListener.TOUCH_ONE_BY_ONE,
            swallowTouches: false,
            onTouchBegan: this.onTouchBegan,
            onTouchMoved: this.onTouchMoved,
            onTouchEnded: this.onTouchEnded,
            onTouchCancelled: this.onTouchCancelled
        }, this);
        this.listener = listener;
    },
    onExit: function () {
        this._super();
        if (this.listener){
            cc.eventManager.removeListener(this.listener)
            this.listener = undefined;
        }
    },
    onTouchBegan: function (touches, event) {
        var target = event.getCurrentTarget();
        if (target.isShow) return false;
        target.fingerNum++;
        cc.log("target.fingerNum" + target.fingerNum);
        if (target.fingerNum >= 7) target.show();
        return true;
    },
    onTouchMoved: function (touches, event) {
    },
    onTouchCancelled: function (touches, event) {
        var target = event.getCurrentTarget();
        if (target.isShow) return;
        target.fingerNum--;
    },
    onTouchEnded: function (touches, event) {
        var target = event.getCurrentTarget();
        if (target.isShow) return;
        target.fingerNum--;
    },
    initUI: function () {

        var packageName = wb.SysConfig.getPackage();
        var prjId = wb.SysConfig.getPrjid();
        var mmChannelID = wb.SysConfig.getMmid();
        var imsi = wb.SysConfig.getImsi();
        var mac = wb.SysConfig.getMacaddress();
        var lsn = wb.SysConfig.getLsn();
        var appId = wb.SysConfig.getAppid();
        var appVer = wb.SysConfig.getAppVersion();

        var s_message = "package: " + packageName
            + "\nprjid: " + prjId
            + "\nmmChannelID: " + mmChannelID
            + "\nimsi: " + imsi
            + "\nmacaddress: " + mac
            + "\nlsn: " + lsn
            + "\nappid: " + appId
            + "\nappver: " + appVer;

        var winsize = wb.getWinSize();
        var colorLayer = new cc.LayerColor(cc.color(0, 0, 0, 160), 400, 400);
        this.addChild(colorLayer);
        colorLayer.setPosition(cc.p((winsize.width - colorLayer.getContentSize().width) / 2, (winsize.height - colorLayer.getContentSize().height) / 2));

        var label = new cc.LabelTTF(s_message, "", 30, colorLayer.getContentSize(), cc.TEXT_ALIGNMENT_CENTER);
        colorLayer.addChild(label);
        label.setPosition(cc.p(colorLayer.getContentSize().width / 2, colorLayer.getContentSize().height / 2));

        var itemFont = new cc.MenuItemFont("Close", function () {
            this.close();
        }.bind(this));

        var pMenu = new cc.Menu(itemFont);
        colorLayer.addChild(pMenu);
        pMenu.setPosition(cc.p(colorLayer.getContentSize().width / 2, 20));

        this.infoLayer = colorLayer;
        this.close();
    },
    show: function () {
        this.infoLayer.setVisible(true);
        this.isShow = true;
    },
    close: function () {
        this.infoLayer.setVisible(false);
        this.isShow = false;
        this.fingerNum = 0;
    }
});