/**
 * Created by Zack on 2018/11/16.
 */

var wb = window.wb || {};


// 互推按钮数据来自 bottomList
wb.PushAdPlBtn = wb.PushAdBtn.extend({
    ctor: function (dataIndex, pushData, nSize, loopTime) {
        this._super(dataIndex, pushData, nSize, loopTime);
        this.pushType = "plaque";
        return true;
    },
    initPlUI: function () {

        if (this.bkSp9) this.bkSp9.removeFromParent();
        if (this.closeBtn) this.closeBtn.removeFromParent();

        var bkSp9 = new cc.Scale9Sprite(wb.wxRes.pushPlbg, cc.rect(0, 0, 100, 100), cc.rect(25, 25, 25, 25));
        this.addChild(bkSp9);
        this.bkSp9 = bkSp9;

        var closeBtn = new ccui.Button(wb.wxRes.pushX, wb.wxRes.pushX, wb.wxRes.pushX);
        this.addChild(closeBtn, 2);
        closeBtn.setScale(1.1);
        this.closeBtn = closeBtn;

        this.closeBtn.addClickEventListener(function () {
            if (this.shadeLayer) this.shadeLayer.removeFromParent();
            else this.removeFromParent();
        }.bind(this));

        this.setVisible(false);
    },
    createBtnSp: function (texture2d) {

        var sp = new cc.Sprite(texture2d);
        this.addChild(sp, 1);

        var norSize = cc.size(508, 408);
        var nSize = sp.getContentSize();

        var scale = norSize.width / nSize.width;
        nSize.height = scale * nSize.height;
        nSize.width = norSize.width;

        this.setContentSize(nSize);
        sp.setPosition(cc.p(nSize.width / 2, nSize.height / 2));
        sp.setScale(scale);

        this.initPlUI();

        var offsetWH = 25;
        var bkSize = cc.size(nSize.width + offsetWH, nSize.height + offsetWH);
        this.bkSp9.setContentSize(bkSize);
        this.bkSp9.setPosition(cc.p(bkSize.width / 2 - offsetWH / 2, bkSize.height / 2 - offsetWH / 2));

        this.closeBtn.setPosition(cc.p(bkSize.width - 50, bkSize.height - 50));
        this.setVisible(true);
        if (this.shadeLayer) this.shadeLayer.setVisible(true);
    }
});

// 互推plaque数据来自 plaqueList
wb.createPushPlaque = function (index) {
    if (!wb.wxData.pushData) return null;

    var pushData = wb.wxData.pushData.plaqueList;
    var size = cc.size(508, 408);
    var dataIndex = index ? index : wb.randNum(0, pushData.length - 1);
    var loopTime = -1;

    if (pushData.length <= 0) return null;
    // 根据概率判断是否显示
    var extra = parseInt(pushData[dataIndex].extra);
    if (wb.randNum(0, 100) > extra) return null;

    var winSize = wb.getWinSize();
    var plaque = new wb.PushAdPlBtn(dataIndex, pushData, size, loopTime);
    plaque.setPosition(cc.p(winSize.width / 2, winSize.height / 2));
    return plaque;
};
wb.createPushPlaqueWs = function (opacity, index) {
    var pushData = wb.wxData.pushData.plaqueList;
    if (pushData.length <= 0) return null;

    var opacity = opacity ? opacity : 150;
    var shadeLayer = new wb.ShadeLayer(opacity);
    var plaque = wb.createPushPlaque(index);
    if (plaque) {
        shadeLayer.addChild(plaque);
        plaque.shadeLayer = shadeLayer;
        wb.popUI(plaque, 0.2);
    } else {
        return null;
    }
    return shadeLayer;
};