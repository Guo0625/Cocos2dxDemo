/**
 * Created by zack on 2018/7/30.
 */

var wb = window.wb || {};
wb.wx = wb.wx || {};

wb.wxData = wb.wxData || {};

// 推送数据
wb.wxData.pushData = null;
// 分享数据
wb.wxData.shareData = null;
// 用户id
wb.wxData.openid = "";
// 用户信息
wb.wxData.userInfo = null;
// 统计唯一标示
wb.wxData.userLsn = "";
// 用户unionId
wb.wxData.unionId = "";
// 应对广告审核机制
wb.wxData.vigameAdFlag = false;

wb.wxData.init = function () {
    //wb.wxData.initUserLsn();
    //wb.wxData.initPushData();
    //wb.wxData.initLoginData();
    //wb.wxData.initVigameAdFlag();
};

wb.wxData.initVigameAdFlag = function () {
    // if (!wb.SysPlatform.isWX()) return;
    // var option = wb.wx.getLaunchOptionsSync();
    // var query = option.query;
    // if (!query) return;
    // wb.log("initVigameAdFlag");
    // wb.log(query.vigame_ad_flag);
    // if (query.vigame_ad_flag == "true") wb.wxData.vigameAdFlag = true;

    var gameConfig = wb.wxData.pushData.gameConfig;
    if (gameConfig && gameConfig.vigame_ad_flag == "true") {
        wb.wxData.vigameAdFlag = true;
    }
};

wb.wxData.initUserLsn = function () {
    wb.wxData.userLsn = wb.wxTool.getUserLsn();
};

// 初始分享图数据
wb.wxData.initShareData = function (callFunc) {
    if (wb.wxConfig.wbAppID.length <= 0) return;

    wb.Http.httpRequest(wb.wxConfig.wxShareUrl, "appid=" + wb.wxConfig.wbAppID, function (data) {
        wb.wxData.shareData = data;
        if (callFunc) callFunc(data);
        wb.EventManager.dispatchCustomEvent("wxShareData");
    }, false);

};

// 初始推送数据
wb.wxData.initPushData = function (callFunc) {
    if (wb.wxConfig.wbAppID.length <= 0) return;

    var platform = "win";
    var systemInfo = wb.wx.getSystemInfoSync();
    if (systemInfo) platform = systemInfo.platform;
    wb.log("platform:" + platform);

    wb.Http.httpRequest(wb.wxConfig.wxPushUrl, "appid=" + wb.wxConfig.wbAppID + "&platform=" + platform + "&channel=wechat", function (data) {
        wb.wxData.pushData = data;
        wb.wxData.initVigameAdFlag();
        if (callFunc) callFunc(data);
        wb.EventManager.dispatchCustomEvent("wxPushData");
    }, false);
};

// 初始登陆数据
wb.wxData.initLoginData = function (callFunc) {
    wb.log("wb.wxData.initLoginData");
    var openid = wb.Data.getItem("wxOpenid", "");
    if (openid.length > 0) {
        wb.wxData.openid = openid;
        if (callFunc) callFunc(openid);
        wb.log("wxOpenid=" + openid);
        wb.wx.startPost();
        return;
    }

    wb.wx.login({
        success: function (res) {
            var requestData = "js_code=" + res.code + "&pid=" + wb.wxConfig.pid;
            wb.log("wb.wxData.initLoginData3 " + requestData);
            wb.Http.httpRequest(wb.wxConfig.wxLoginUrl, requestData, function (data) {
                wb.log("wb.wxData.initLoginData4");
                // var sessionKey = data.session_key;
                wb.wxData.openid = data.openid;
                wb.log("wxOpenid=" + wb.wxData.openid);
                wb.Data.setItem("wxOpenid", "" + wb.wxData.openid);
                if (callFunc) callFunc(wb.wxData.openid);
                wb.wx.startPost();
            }, false);
        },
        fail: function () {
            wb.log("login fail");
            if (callFunc) callFunc(null);
            wb.wx.startPost();
        }
    });
};

// 用户信息
wb.wxData.initUserInfo = function (callFunc) {
    wb.wx.getUserInfo({
            success: function (res) {
                wb.log("wb.wx.getUserInfo");
                wb.log(res.userInfo);
                wb.wxData.userInfo = res.userInfo;
                if (callFunc)callFunc(res.userInfo);
            },
            fail: function () {
                wb.log("getUserInfo fail");
                if (callFunc) callFunc(null);
            }
        }
    )
};

// 加载附加资源
wb.wxData.loadExtraData = function () {
    wb.Loader.load(wb.wxRes,
        function (result, count, loadedCount) {
        }, function () {
        });
};
