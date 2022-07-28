/**
 * Created by cc on 2018/4/20.
 */

var wb = window.wb || {};

wb.HTTPRE = "httpre";

wb.wxTool = wb.wxTool || {};

wb.wxTool.getScreenSize = function () {
    var systemInfo = wb.wx.getSystemInfoSync();
    if (!systemInfo) return null;
    return {
        width: systemInfo.screenWidth,
        height: systemInfo.screenHeight
    };
};

wb.wxTool.upOffsetH = function () {
    if (this.isIphoneX()) return 25;
    return 0;
};

wb.wxTool.isIphoneX = function () {
    var systemInfo = wb.wx.getSystemInfoSync();
    console.log(systemInfo);
    if (systemInfo && systemInfo.model.toLowerCase().indexOf("iphone x") != -1) {
       return true;
    }
    return false;
};

// 微信分享
wb.wxTool.fxMessage = function (callFun) {
    wb.log("fxMessage1");
    if (!wb.wxData.shareData) return;
    var shareList = wb.wxData.shareData.shareList;
    if (!shareList) return;
    var sData = null;
    for (var i = 0; i < shareList.length; i++) {
        wb.log("shareData[i].placement " + shareList[i].placement);
        if (shareList[i].placement == type) {
            sData = shareList[i];
            break;
        }
    }
    if (!sData) return;
    var callF = function () {
    };
    if (callFun) callF = callFun;
    var data = {
        title: sData.title,
        imageUrl: sData.imageUrl,
        success: callF
    };
    wb.wx.shareAppMessage(data);
};

wb.wxTool.getUserLsn = function () {
    var user_lsn = wb.Data.getItem("user_lsn", "");
    if (user_lsn) return user_lsn;

    if (wb.SysPlatform.isWX()) {
        var res = wb.wx.getSystemInfoSync();
        var strMd = "" + res.brand + res.model + res.system + res.platform + (Math.random() * 1000000);
        var dt = new Date();
        strMd += dt.getMilliseconds();
        user_lsn = wb.Tools.md5(strMd);
        wb.log(strMd);
    } else {
        var strMd = "" + (Math.random() * 10000000);
        var dt = new Date();
        strMd += dt.getMilliseconds();
        user_lsn = wb.Tools.md5(strMd);
        wb.log(strMd);
    }
    wb.log("user_lsn: " + user_lsn);
    wb.Data.setItem('user_lsn', user_lsn);
    return user_lsn;
};





