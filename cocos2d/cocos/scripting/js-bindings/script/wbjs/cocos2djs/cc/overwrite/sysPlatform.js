/**
 * Created by Zack on 2018/11/16.
 */

var wb = window.wb || {};

// overwrite interface

wb.SysPlatform.log = function (str) {
    cc.log(str);
};
wb.log = wb.SysPlatform.log;

wb.SysPlatform.os = function () {
    return cc.sys.os;
};

wb.SysPlatform.isMobileBrowser = function () {
    return cc.sys.platform == cc.sys.MOBILE_BROWSER;
};

wb.SysPlatform.isDesktopBrowser = function () {
    return cc.sys.platform == cc.sys.DESKTOP_BROWSER;
};

wb.SysPlatform.isBrowser = function () {
    return wb.SysPlatform.isDesktopBrowser() || wb.SysPlatform.isMobileBrowser();
};

wb.SysPlatform.isNative = function () {
    return cc.sys.isNative;
};

wb.SysPlatform.isMobile = function () {
    return cc.sys.isMobile;
};


wb.SysPlatform.getWinSize = function () {
    return cc.director.getWinSize();
};

wb.SysPlatform.getFrameSize = function () {
    return cc.view.getFrameSize();
};