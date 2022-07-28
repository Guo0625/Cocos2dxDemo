/**
 * Created by zack on 2018/7/30.
 */
var wb = window.wb || {};

// 互推按钮数据来自 bannerList
wb.PushAdBaBtn = wb.PushAdBtn.extend({
    ctor: function (dataIndex, pushData, nSize, loopTime) {
        this._super(dataIndex, pushData, nSize, loopTime);
        this.pushType = "banner";
    },
    createBtnSp: function (texture2d) {
        this.setContentSize(this.nSize);

        var sp = new cc.Sprite(texture2d);
        this.addChild(sp, 1);

        var spSize = sp.getContentSize();
        var scaleX = this.nSize.width / spSize.width;
        var scaleY = this.nSize.height / spSize.height;
        sp.setScaleX(scaleX);
        sp.setScaleY(scaleY);
        sp.setPosition(cc.p(this.nSize.width / 2, this.nSize.height / 2));

    },
    loopNext: function () {
        this.dataIndex = wb.randNum(0, this.pushData.length - 1);
        this.data = this.pushData[this.dataIndex];
        this.setData(this.data);
    },
    hide: function () {
        this.setVisible(false);
    },
    destroy: function () {
        this.removeFromParent();
    },
    show: function () {
        this.setVisible(true);
    }
});


// 互推banner数据来自 bannerList
wb.createPushBanner = function (index, data, size, loopTime) {
    if (!wb.wxData.pushData) return null;
    var dataIndex = index ? index : 0;
    var pushData = data ? data : wb.wxData.pushData.bannerList;
    var size = size ? size : cc.size(cc.winSize.width, 200);
    var loopTime = loopTime ? loopTime : 10;

    if (pushData.length <= 0) return null;

    if (pushData.open == "banner") {
        wb.ADManager.openAd("banner");
        return null;
    }

    var banner = new wb.PushAdBaBtn(dataIndex, pushData, size, loopTime);
    banner.setPosition(cc.p(size.width / 2, size.height / 2));
    banner.setIsLoop(true);
    return banner;
};

wb.addPushBannerToScene = function () {
    var banner = wb.createPushBanner();
    if (banner) {
        wb.ADManager.closeAd("banner");
        cc.director.getRunningScene().addChild(banner, 9999999);
    }
    return banner;
};