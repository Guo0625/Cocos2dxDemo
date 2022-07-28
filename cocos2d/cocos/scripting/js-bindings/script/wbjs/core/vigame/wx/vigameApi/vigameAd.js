/**
 * Created by Zack on 2018/1/9.
 */

var wb = window.wb || {};
wb.ADManager = wb.SysCore.extend(wb.JADManager, {});

wb.ADManager.bannerSingle = null;
wb.ADManager.videoSingle = null;

wb.ADManager.isVideoEnable = false;
wb.ADManager.videoAdCallFunc = null;  // 视频回调
wb.ADManager.videoADS = ["video", "level_fail_mfzs", "skin", "home_mfzs", "double_fail_mfzs"];

wb.ADManager.init = function () {
    wb.ADManager.createVideo();
};

// is enable must be overwrite
wb.ADManager.addPushBannerToScene = function () {
    return null;
};

wb.ADManager.isBannerAD = function (str) {
    if (wb.SysValue.isObject(wb.wxConfig.bannerADid)) {
        if (wb.wxConfig.bannerADid[str]) return true;
        // else return false;
    }
    if (str == "banner") return true;
    return false;
};

wb.ADManager.isVideoAD = function (str) {
    var videos = wb.ADManager.videoADS;
    for (var i = 0; i < videos.length; i++) {
        if (str == videos[i]) return true;
    }
    return false;
};

wb.ADManager.hideBanner = function () {
    if (!wb.ADManager.bannerSingle) return;
    wb.ADManager.bannerSingle.hide();
};

wb.ADManager.showBanner = function () {
    if (!wb.ADManager.bannerSingle) return;
    wb.ADManager.bannerSingle.show();
};

wb.ADManager.createBannerAD = function (str, func) {
    if (wb.wxConfig.bannerADid.length <= 0) return;
    wb.ADManager.closeAd("banner");
    var bannerADid = 0;
    if (wb.SysValue.isObject(wb.wxConfig.bannerADid)) {
        bannerADid = wb.wxConfig.bannerADid[str];
    }
    else {
        bannerADid = wb.wxConfig.bannerADid;
    }
    var size = wb.wxTool.getScreenSize();
    if (!size) {
        if (func) func("size is null", 1);
        return;
    }

    var bannerAd = wb.wx.createBannerAd({
        adUnitId: bannerADid,
        style: {
            left: 0,
            top: size.height - 120,
            width: size.width,
            height: 120
        }
    });
    if (bannerAd) {
        wb.ADManager.bannerSingle = bannerAd;
        bannerAd.onResize(function (res) {
            wb.log(res);
            if (wb.ADManager.bannerSingle.style) wb.ADManager.bannerSingle.style.top = size.height - res.height - wb.wxTool.upOffsetH();
        }.bind(this));
        //加载失败通知
        bannerAd.onError(function (err) {
            wb.log('banner load error');
            wb.log(err);
            if (func) func(err, 1);
            //wb.ADManager.bannerSingle.offResize(function () {
            //});
            //wb.ADManager.bannerSingle.offLoad(function () {
            //});
            //wb.ADManager.bannerSingle.offError(function () {
            //});
            wb.ADManager.closeAd("banner");

            // wx banner is opend error，so open the psuhBanner, must be overwrite
             if (!wb.wxData.vigameAdFlag) wb.ADManager.bannerSingle = wb.addPushBannerToScene();
        });
        bannerAd.onLoad(function () {
            wb.log('banner load succed');
            if (func) func(null, 0);
        });
        bannerAd.show();
    }
};
wb.ADManager.createVideo = function () {
    if (wb.ADManager.videoSingle) return;
    if (wb.wxConfig.videoADid.length <= 0) return;
    wb.log("wb.ADManager.createVideo~");
    var videoAd = wb.wx.createRewardedVideoAd({
        adUnitId: wb.wxConfig.videoADid
    });
    wb.ADManager.videoSingle = videoAd;
    if (videoAd) {
        videoAd.onLoad(function () {
            wb.log("videoAd.onLoad");
            wb.ADManager.isVideoEnable = true;
        });

        videoAd.onError(function () {
            wb.log("videoAd.onError");
            wb.ADManager.isVideoEnable = false;
            wb.ADManager.videoSingle.load();
        });

        // wb.ADManager.videoAdCallFunc = null;
        videoAd.onClose(function (res) {
            wb.ADManager.showBanner();
            wb.audioEngine.resumeMusic();

            if (!wb.ADManager.videoAdCallFunc) return;
            if (!res) wb.ADManager.videoAdCallFunc({isEnded: true}, 0);
            else {
                var result = -1;
                if (res.isEnded) result = 0;
                wb.ADManager.videoAdCallFunc(res, result);
            }
        });

    }
};

wb.ADManager.closeAd = function (str) {
    if (wb.ADManager.isBannerAD(str)) {
        if (wb.ADManager.bannerSingle) {
            wb.ADManager.bannerSingle.hide();
            wb.ADManager.bannerSingle.destroy();
            wb.ADManager.bannerSingle = null;
        }
    } else if (wb.ADManager.isVideoAD(str)) {
    }
};


wb.ADManager.openAd = function (str) {
    if (!wb.ADManager.isAdReady(str)) return false;

    if (wb.ADManager.isBannerAD(str)) {
        wb.ADManager.createBannerAD(str);
    } else if (wb.ADManager.isVideoAD(str)) {
        wb.audioEngine.pauseMusic();
        wb.ADManager.createVideo();
        wb.ADManager.hideBanner();
        wb.ADManager.videoAdCallFunc = null;
        wb.ADManager.videoSingle.show();
    }
};

wb.ADManager.openAdC = function (str, func) {
    if (!wb.ADManager.isAdReady(str)) {
        if (func) func("not ready", 1);
        return false;
    }

    if (wb.ADManager.isBannerAD(str)) {
        wb.ADManager.createBannerAD(str, func);
    } else if (wb.ADManager.isVideoAD(str)) {
        wb.audioEngine.pauseMusic();
        wb.ADManager.createVideo();
        wb.ADManager.hideBanner();
        wb.ADManager.videoAdCallFunc = func;
        wb.ADManager.videoSingle.show();
    }

};


wb.ADManager.isAdReady = function (position, type) {
    if (wb.ADManager.isBannerAD(position)) {
        return true;
    } else if (wb.ADManager.isVideoAD(position)) {
        return wb.ADManager.isVideoEnable;
    }
    return true;
};

wb.ADManager.isAdEnable = function (position) {
    return true;
};