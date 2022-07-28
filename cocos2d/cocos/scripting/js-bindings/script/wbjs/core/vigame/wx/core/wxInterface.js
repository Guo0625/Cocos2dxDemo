/**
 * Created by cc on 2018/4/20.
 */

var wb = window.wb || {};
wb.wx = wb.wx || {};

wb.wxIFS = wb.extend(window.wx, {});

wb.wx.isWxEnable = function () {
    if (window.wx) return true;
    return false;
};

wb.wx.isWxFun = function (funStr) {
    if (wb.wxIFS[funStr]) return true;
    return false;
};

wb.wx.callFunc = function (funStr, data) {
    if (!wb.wx.isWxFun(funStr)) return null;
    return wb.wxIFS[funStr](data);
};

wb.wx.checkSupportMiniprogram = function () {
    if (!wb.wx.isWxEnable()) return false;
    if (wb.wx.isSupportMiniprogram) return true;

    var systemInfo = wb.wx.getSystemInfoSync();
    if (systemInfo && systemInfo.SDKVersion) {
        if (systemInfo.SDKVersion >= "2.2.0") {
            wb.wx.isSupportMiniprogram = true;
            return true;
        }
    }
    return false;
};

///////////////////////////////////////  微信小游戏常用接口

wb.wx.createInnerAudioContext = function () {
    return wb.wx.callFunc("createInnerAudioContext");
};

wb.wx.navigateToMiniProgram = function (data) {
    return wb.wx.callFunc("navigateToMiniProgram", data);
};

wb.wx.getSystemInfoSync = function () {
    return wb.wx.callFunc("getSystemInfoSync");
};


wb.wx.getSystemInfo = function (data) {
    return wb.wx.callFunc("getSystemInfo", data);
};

wb.wx.onHide = function (data) {
    return wb.wx.callFunc("onHide", data);
};

wb.wx.onShow = function (data) {
    return wb.wx.callFunc("onShow", data);
};

wb.wx.createUserInfoButton = function (data) {
    return wb.wx.callFunc("createUserInfoButton", data);
};

wb.wx.login = function (data) {
    return wb.wx.callFunc("login", data);
};

wb.wx.request = function (data) {
    return wb.wx.callFunc("request", data);
};

wb.wx.getUserInfo = function (data) {
    return wb.wx.callFunc("getUserInfo", data);
};

wb.wx.setUserCloudStorage = function (data) {
    return wb.wx.callFunc("setUserCloudStorage", data);
};

wb.wx.removeUserCloudStorage = function (data) {
    return wb.wx.callFunc("removeUserCloudStorage", data);
};

wb.wx.getLaunchOptionsSync = function (data) {
    return wb.wx.callFunc("getLaunchOptionsSync", data);
};

wb.wx.getLaunchOptionsSync = function (data) {
    return wb.wx.callFunc("getLaunchOptionsSync", data);
};

wb.wx.showShareMenu = function (data) {
    return wb.wx.callFunc("showShareMenu", data);
};

wb.wx.shareAppMessage = function (data) {
    return wb.wx.callFunc("shareAppMessage", data);
};

wb.wx.onShareAppMessage = function (data) {
    return wb.wx.callFunc("onShareAppMessage", data);
};

wb.wx.getOpenDataContext = function () {
    return wb.wx.callFunc("getOpenDataContext");
};

wb.wx.getOpenDataCanvas = function () {
    var context = wb.wx.getOpenDataContext();
    if (!context) return null;
    return context.canvas;
};

wb.wx.getSharedCanvas = function () {
    return wb.wx.callFunc("getSharedCanvas");
};

wb.wx.postMessage = function (data) {
    var openDataContext = wb.wx.getOpenDataContext();
    if (openDataContext) openDataContext.postMessage(data);
};

wb.wx.previewImage = function (data) {
    return wb.wx.callFunc("previewImage", data);
};

wb.wx.createBannerAd = function (data) {
    return wb.wx.callFunc("createBannerAd", data);
};

wb.wx.createRewardedVideoAd = function (data) {
    return wb.wx.callFunc("createRewardedVideoAd", data);
};






