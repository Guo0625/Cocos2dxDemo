/**
 * Created by Zack on 2018/11/14.
 */

var wb = window.wb || {};

wb.Ad = wb.SysCore.extend(wb.JAd, {});

wb.ADSourceItem = wb.SysCore.extend(wb.JADCache, {});

wb.ADManager = wb.SysCore.extend(wb.JADManager, {});

wb.ADManager.openAdO = function (str, int) {
    if (!wb.ADManager.isAdEnable(str)) return false;
    if (wb.ADManager.isAdReady(str) && wb.SysPlatform.isNative()) this.parent.openAdO(str, int);
};

wb.ADManager.openAd = function (str) {
    if (!wb.ADManager.isAdEnable(str)) return false;
    if (wb.ADManager.isAdReady(str) && wb.SysPlatform.isNative()) this.parent.openAd(str);
};

wb.ADManager.openAdC = function (str, func) {
    if (!wb.ADManager.isAdEnable(str)) return false;
    if (wb.SysPlatform.isNative()) {
        if (wb.ADManager.isAdReady(str)) this.parent.openAdC(str, func);
    }
    else if (func) func(null, 0);
};

wb.ADManager.openAdOC = function (str, int, func) {
    if (!wb.ADManager.isAdEnable(str)) return false;
    if (wb.SysPlatform.isNative()) {
        if (wb.ADManager.isAdReady(str)) this.parent.openAdOC(str, int, func);
    }
    else if (func) func(null, 0);
};

wb.ADManager.getVideoLimitOpenNum = function () {
    if (wb.SysPlatform.isNative()) return this.parent.getVideoLimitOpenNum();
    return 10;
};
wb.ADManager.isAdReady = function (position, type) {
    if (!wb.ADManager.isAdEnable(position)) return false;
    if (wb.SysPlatform.isNative()) return this.parent.isAdReady(position);
    else if (wb.SysPlatform.isWX())  return false;
    return true;
};

wb.ADManager.isAdEnable = function (position) {
    for (var i = 0; i < wb.vigameNs.adVideoPosition.length; i++) {
        if (wb.vigameNs.adVideoPosition[i] == position) return true;
    }
    return wb.Helper.getADEnabled();
};