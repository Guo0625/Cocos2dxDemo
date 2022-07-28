/**
 * Created by Administrator on 2018/11/16.
 */
var wb = window.wb || {};

// 互推按钮数据来自 bottomList
wb.PushAdMoBtn = wb.PushAdBtn.extend({
    ctor: function (dataIndex, pushData, nSize, loopTime) {
        this._super(dataIndex, pushData, nSize, loopTime);
        this.setContentSize(this.nSize);
    },
    createBtnSp: function (texture2d) {
        if (this.hideSp) return;

        this.setContentSize(this.nSize);
        var sp = new cc.Sprite(texture2d);
        this.addChild(sp, 1);
        var spSize = sp.getContentSize();

        var scaleX = this.nSize.width / spSize.width;
        var scaleY = this.nSize.height / spSize.height;
        sp.setScaleX(scaleX);
        sp.setScaleY(scaleY);

        sp.setPosition(wb.getNodeCenterP(this));

    }
});


wb.createMoreGameBtn = function (size, hideSp) {
    if (!wb.wxData.pushData) return null;

    var loopTime = -1;
    var size = size ? size : cc.size(90, 90);
    var pushData = wb.wxData.pushData.moregameList;
    if (pushData.length <= 0) return null;
    var dataIndex = wb.randNum(0, pushData.length - 1);

    var moregameBtn = new wb.PushAdMoBtn(dataIndex, pushData, size, loopTime);
    moregameBtn.hideSp = hideSp;
    return moregameBtn;
};

wb.openMoreGame = function () {
    if (!wb.wxData.pushData) return null;

    var pushData = wb.wxData.pushData.moregameList;
    if (pushData.length <= 0) return null;

    var dataIndex = wb.randNum(0, pushData.length - 1);
    var data = pushData[dataIndex];

    if (data.open != "miniprogram")return;

    wb.wx.navigateToMiniProgram({
        appId: data.pushAppID,
        path: data.openPath,
        extraData: {
            vigame_from: "miniprogram"
        },
        success: function (res) {
        }
    });
};