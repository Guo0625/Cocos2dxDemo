/**
 * Created by zack on 2018/7/30.
 */
var wb = window.wb || {};

wb.PushAdLayer = cc.Layer.extend({
    data: null,
    enableIndex: [], // 可用下标
    bindLayer: null,
    placement: "",
    adBtnList: null,
    ctor: function (pData, layer, size, btnIndexList) {
        this._super();
        wb.PushAdLayerSingle = this;
        if (!this.check(layer)) return true;
        this.initData(pData, layer);
        this.initUI(pData, layer, size, btnIndexList);
    },
    check: function (layer) {
        var bottomList = wb.wxData.pushData.bottomList;
        if (!bottomList || bottomList.length <= 0) {
            this.setVisible(false);
            layer.setVisible(false);
            return false;
        }
        return true;
    },
    initData: function (pData, layer) {
        this.enableIndex = [];
        this.adBtnList = [];
        this.bindLayer = layer;
    },
    initUI: function (pData, layer, size, btnIndexList) {
        var bottomList = wb.wxData.pushData.bottomList;

        for (var i = 0; i < btnIndexList.length; i++) {
           // var adBtn = wb.createPushAdBtnByIndex(btnIndexList[i], bottomList, size, -1);
            var adBtn = wb.createBtBtn(btnIndexList[i], bottomList, size, -1);
            adBtn.setPosition(pData[i]);
            layer.addChild(adBtn, 1);
            adBtn.setClickFunc(this.clickFun);
            adBtn.dataIndex = btnIndexList[i];
            adBtn.setPlacement(this.placement);
            this.adBtnList.push(adBtn);
            adBtn.pushType = "bottom";
        }
        var bIndex = btnIndexList[btnIndexList.length - 1] + 1;
        var len = bottomList.length - btnIndexList.length;
        for (var i = 0; i < len; i++) {
            if (bIndex >= bottomList.length) bIndex = 0;
            this.enableIndex.push(bIndex);
            bIndex++;
        }
    },
    clickFun: function (btn) {
        var self = wb.PushAdLayerSingle;
        if (self.enableIndex.length <= 0) return;
        cc.log("PushAdLayer clickFun");
        var index = self.enableIndex.shift();
        btn.setDataByIndex(index);
        self.enableIndex.push(btn.dataIndex);
        btn.dataIndex = index;
    },
    // 统计参数
    setPlacement: function (placement) {
        this.placement = placement;
        for (var i = 0; i < this.adBtnList.length; i++) {
            this.adBtnList[i].setPlacement(placement);
        }
    }
});

// 根据坐标创建
wb.createPushAdLayerByData = function (pList, layer, size, btnIndexList) {
    return new wb.PushAdLayer(pList, layer, size, btnIndexList);
};

// 四个 btn 开始下标
wb.pushAdLayerBIndex = 0;

// 自带底图的互推
wb.createPushAdLayer = function (placement, btnIndexList, num, btnDw) {
    if (!wb.wxData.pushData) return null;
    if (wb.wxData.vigameAdFlag) return null;

    var dw = btnDw ? btnDw : 20;  // 间隔
    var num = num ? num : 4;      // 数量
    var btnIndexList = btnIndexList;  // 创建时的数据的下标
    var placement = placement ? placement : "";

    var bottomList = wb.wxData.pushData.bottomList;
    if (bottomList.length <= 0) return null;

    // 取最小值
    num = num > bottomList.length ? bottomList.length : num;
    if (num > 4) num = 4;
    // 重计算间隔
    if (!btnDw) dw = 80 / num;

    if (!btnIndexList) {
        btnIndexList = [];
        var dataIndex = wb.pushAdLayerBIndex;
        for (var i = 0; i < num; i++) {
            if (dataIndex >= bottomList.length) dataIndex = 0;
            btnIndexList.push(dataIndex);
            dataIndex++;
        }
        wb.pushAdLayerBIndex = dataIndex;
    }

    var btnSize = cc.size(90, 90);
    var bg = new cc.Sprite(wb.wxRes.wxPushBg);
    var bgSize = cc.size(455, 155);

    var bgCenterP = cc.p(bgSize.width / 2, bgSize.height / 2 + 20);
    var beganP = cc.p(bgCenterP.x - (num * btnSize.width + (num - 1) * dw) / 2 + btnSize.width / 2, bgCenterP.y - 15);
    var pList = [];
    for (var i = 0; i < num; i++) {
        var p = cc.p(beganP.x + i * (dw + btnSize.width), beganP.y);
        pList.push(p);
    }

    for (var i = 0; i < pList.length; i++) {
        var frameSp = new cc.Sprite(wb.wxRes.pushFrame);
        frameSp.setPosition(pList[i]);
        bg.addChild(frameSp);
    }

    var pushAdlayer = wb.createPushAdLayerByData(pList, bg, btnSize, btnIndexList);
    pushAdlayer.setPlacement(placement);
    return bg;
};
