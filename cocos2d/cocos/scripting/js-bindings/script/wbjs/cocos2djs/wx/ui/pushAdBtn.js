/**
 * Created by zack on 2018/7/30.
 */
var wb = window.wb || {};

wb.PushAdBtn = ccui.Widget.extend({
    data: null,
    pushData: null,
    nSize: null,
    dataIndex: null,
    loopTime: null,
    placement: "",
    ctor: function (dataIndex, pushData, nSize, loopTime) {
        this._super();
        if (!this.check(pushData)) return true;

        this.initData(dataIndex, pushData, nSize);
        this.initUI();
        this.initLoop(loopTime);

    },
    onEnter: function () {
        this._super();
        this.showPost();
    },
    onExit: function () {
        this._super();
    },
    check: function (pushData) {
        if (!pushData || pushData.length <= 0) {
            this.setVisible(false);
            return false;
        }
        return true;
    },
    initLoop: function (loopTime) {
        if (!loopTime || loopTime <= 0) return;
        this.schedule(function () {
            if (wb.wxData.vigameAdFlag) return;

            this.loopNext();
        }.bind(this), loopTime);
    },
    initData: function (dataIndex, pushData, nSize) {
        this.data = pushData[dataIndex];
        if (!this.data) return;
        this.nSize = nSize;
        this.dataIndex = dataIndex;
        this.pushData = pushData;
        this.pushType = "";
        this.setData(this.data);

        this.addClickEventListener(this.onClick);
        this.setTouchEnabled(true);
    },
    setDataByIndex: function (index) {
        this.setData(this.pushData[index]);
    },
    setData: function (data) {
        if (!data) return;
        this.data = data;

        wb.wxTool.loadImg(this.data.icon, function (texture2d) {
            this.createBtnSp(texture2d);
        }.bind(this));
    },
    createBtnSp: function (texture2d) {

        var bgSpSize = cc.size(101, 101);
        var isFirst = false;
        if (!this.clippingNode) {
            isFirst = true;
            var stencil = new cc.Sprite(wb.wxRes.pushFrame);
            stencil.setContentSize(this.nSize);
            stencil.setScaleX(this.nSize.width / bgSpSize.width);
            stencil.setScaleY(this.nSize.height / bgSpSize.height);
            stencil.setAnchorPoint(cc.p(0, 0));

            var clippingNode = new cc.ClippingNode();
            clippingNode.setInverted(false);
            //clippingNode.setAlphaThreshold(0);
            this.addChild(clippingNode, 1);
            clippingNode.setStencil(stencil);
            this.clippingNode = clippingNode;

            this.bgSp = new cc.Sprite(wb.wxRes.pushFrame);
            this.bgSp.setAnchorPoint(cc.p(0.5, 0.5));
            this.addChild(this.bgSp, 0);
        }

        var sp = new cc.Sprite(texture2d);
        //this.addChild(sp, 1);
        this.clippingNode.addChild(sp);

        this.setContentSize(sp.getContentSize());
        sp.setPosition(wb.getNodeCenterP(this));
        this.bgSp.setPosition(wb.getNodeCenterP(this));

        var spSize = sp.getContentSize();
        this.setContentSize(this.nSize);
        var nodeCP = wb.getNodeCenterP(this);
        // sp.setPosition(wb.getNodeCenterP(this));
        var scaleX = this.nSize.width / spSize.width;
        var scaleY = this.nSize.height / spSize.height;
        sp.setScaleX(scaleX);
        sp.setScaleY(scaleY);

        this.bgSp.setPosition(wb.getNodeCenterP(this));
        this.bgSp.setScaleX(this.nSize.width / bgSpSize.width + 0.05);
        this.bgSp.setScaleY(this.nSize.height / bgSpSize.height + 0.05);

        // 第一次则直接显示
        if (isFirst) {
            sp.setPosition(nodeCP);
            this.btnSp = sp;
        } else {
            sp.setPosition(cc.p(nodeCP.x + this.nSize.width, nodeCP.y));
            var seq = cc.sequence(cc.moveTo(0.4, nodeCP), cc.callFunc(function () {
                if (this.btnSp) this.btnSp.removeFromParent();
                this.btnSp = sp;
            }.bind(this)));
            sp.runAction(seq);
        }
    },
    initUI: function () {
    },
    onClick: function () {
        cc.log("onClick~~~~~");
        var openType = this.data.open;
        // var tjKey = "ad_" + openType;

        if (!wb.wx.checkSupportMiniprogram()) openType = "image";

        if (openType == "image") {
            wb.wx.previewImage({
                urls: [this.data.pushImage]
            })
        } else if (openType == "url") {

        } else if (openType == "miniprogram") {
            var tjKey = "ad_" + openType;
            var selfData = this.data;
            wb.wx.navigateToMiniProgram({
                appId: selfData.pushAppID,
                path: selfData.openPath,
                extraData: {
                    vigame_from: "miniprogram"
                },
                success: function (res) {
                }
            });
        }
        var tjData = {
            label: this.data.id,
            pushappid: this.data.pushAppID
        };
        wb.DataTJManager.event2(this.pushType, tjData, this.placement);
        if (this.clickFunc) this.clickFunc(this);
        if (this.isLoop) this.loopNext();
    },
    // 监听回调
    setClickFunc: function (func) {
        this.clickFunc = func;
    },
    // 设置点击后为下一个
    setIsLoop: function (flag) {
        this.isLoop = flag;
    },
    // 循环
    loopNext: function () {
        this.dataIndex++;
        if (this.dataIndex >= this.pushData.length) this.dataIndex = 0;
        this.data = this.pushData[this.dataIndex];
        this.setData(this.data);

        this.showPost();
    },
    // 统计参数
    setPlacement: function (placement) {
        this.placement = placement;
    },
    // 展示数上报
    showPost: function () {
        var tjData = {
            label: this.data.id,
            pushappid: this.data.pushAppID,
            placement: this.placement
        };
        //wb.DataTJManager.event2(this.pushType, tjData, this.placement);
        wb.DataTJManager.reportData("pushShow", this.pushType, tjData);
    }
});

// 根据下标创建
wb.createPushAdBtnByIndex = function (index, data, size, loopTime) {
    if (!wb.wxData.pushData) return null;
    if (!data) return null;
    var dataIndex = index ? index : 0;
    var pushData = data;    // 数据来源
    var loopTime = loopTime ? loopTime : 10;  // 循环时间
    var size = size ? size : cc.size(90, 90);
    var pushAdBtn = new wb.PushAdBtn(dataIndex, pushData, size, loopTime);
    return pushAdBtn;
};



