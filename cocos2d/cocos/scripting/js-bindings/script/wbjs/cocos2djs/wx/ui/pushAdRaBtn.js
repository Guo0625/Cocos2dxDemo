/**
 * Created by zack on 2018/7/30.
 */
var wb = window.wb || {};

// 互推按钮数据来自 iconList
wb.PushAdRaBtn = wb.PushAdBtn.extend({
    ctor: function (dataIndex, pushData, nSize, loopTime) {
        this._super(dataIndex, pushData, nSize, loopTime);
        this.pushType = "icon";
    },

    onExit: function () {
        this._super();
        this.isLoop = false;
        wb.pushAdBtnDataList.push(this.dataIndex);
    },
    setData: function (data) {
        if (!data) return;
        this.data = data;

        wb.wxTool.loadImg(this.data.icon, function (texture2d) {
            if (this.data.plist && this.data.plist.length > 0) {
                //cc.loader.loadTxt(this.data.plist, function (err, txt) {
                //    this.createBtnSp(texture2d);
                //}.bind(this));

                cc.loader.load([this.data.plist], function (result, count, loadedCount) {
                }, function () {
                    this.createBtnSp(texture2d);
                }.bind(this));
            } else {
                this.createBtnSp(texture2d);
            }
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

        var sp = null;
        var spSize = null;
        if (this.data.plist && this.data.plist.length > 0) {

            // 创建动画
            var animation = cc.animationCache.getAnimation(this.data.plist);
            if (!animation) {
                var cache = cc.spriteFrameCache;
                cache.addSpriteFrames(this.data.plist, texture2d);
                var frameNames = cache._frameConfigCache[this.data.plist].frames;
                animation = new cc.Animation();

                for (var frameName in frameNames) {
                    var frame = cc.spriteFrameCache.getSpriteFrame(frameName);
                    animation.addSpriteFrame(frame);
                }
                animation.setDelayPerUnit(0.15);
                animation.setRestoreOriginalFrame(true);

                // 放入缓存
                cc.animationCache.addAnimation(animation, this.data.plist);
            }

            var firstFrame = animation.getFrames()[0].getSpriteFrame();
            sp = new cc.Sprite(firstFrame);
            spSize = cc.size(firstFrame.getRect().width, firstFrame.getRect().height);
            sp.runAction(cc.animate(animation).repeatForever());


        } else {
            sp = new cc.Sprite(texture2d);
            spSize = sp.getContentSize();
        }

        //this.addChild(sp, 1);
        this.clippingNode.addChild(sp);

        this.setContentSize(sp.getContentSize());
        sp.setPosition(wb.getNodeCenterP(this));
        this.bgSp.setPosition(wb.getNodeCenterP(this));

        //var spSize = cc.size(128,128);//sp.getContentSize();
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
    // 循环
    loopNext: function () {
        if (!this.isLoop) return;
        if (!this) return;

        var newIndex = wb.pushAdBtnDataRand(this.dataIndex);
        if (newIndex == undefined || this.dataIndex == newIndex) return;
        this.dataIndex = newIndex;
        this.data = this.pushData[this.dataIndex];
        this.setData(this.data);
    }
});

// 随机取数据
wb.pushAdBtnDataList = null;
wb.pushAdBtnDataRand = function (oldDataIndex) {
    if (wb.pushAdBtnDataList.length <= 0) return oldDataIndex;
    var index = wb.randNum(0, wb.pushAdBtnDataList.length - 1);
    var dataIndex = wb.pushAdBtnDataList[index];
    wb.spliceArray(wb.pushAdBtnDataList, index, 1);
    if (oldDataIndex != undefined) wb.pushAdBtnDataList.push(oldDataIndex);
    return dataIndex;
};

// 默认互推按钮数据来自 iconList
wb.createPushAdBtn = function (index, data, size, loopTime) {
    if (!wb.wxData.pushData) return null;

    var pushData = data ? data : wb.wxData.pushData.iconList;
    var loopTime = loopTime ? loopTime : 10;  // 循环时间
    var size = size ? size : cc.size(90, 90);

    if (pushData.length <= 0) return null;

    if (!wb.pushAdBtnDataList) {
        wb.pushAdBtnDataList = [];
        for (var i = 0; i < pushData.length; i++) {
            wb.pushAdBtnDataList.push(i);
        }
    }
    // 获取随机下标
    var dataIndex = wb.pushAdBtnDataRand(null);
    if (dataIndex == null) return null;

    var pushAdBtn = new wb.PushAdRaBtn(dataIndex, pushData, size, loopTime);
    pushAdBtn.setIsLoop(true);
    return pushAdBtn;
};

