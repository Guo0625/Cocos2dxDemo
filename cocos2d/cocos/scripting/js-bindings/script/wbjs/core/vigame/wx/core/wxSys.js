/**
 * Created by zack on 2018/4/20.
 */

var wb = window.wb || {};
wb.wx = wb.wx || {};

wb.wx.init = function (data) {

    wb.wxConfig.pid = data.pid;
    wb.wxConfig.prjid = data.prjid;
    wb.wxConfig.wbAppID = data.wbAppID;

    wb.wxConfig.bannerADid = data.bannerADid;
    wb.wxConfig.videoADid = data.videoADid;

    wb.wxData.initUserLsn();
    wb.wxData.loadExtraData();
    wb.ADManager.init();
    // wb.wxData.initVigameAdFlag();
};

// 
wb.wx.startPost = function () {
    if (!wb.wx.isWxEnable()) return;
    var option = wb.wx.getLaunchOptionsSync();
    var scene = option.scene;
    var query = option.query;
    var pid = "";
    var channel = "";
    if (query && query.pid) {
        pid = query.pid;
    }
    if (query && query.channel) {
        channel = query.channel;
    }
    var type = "custom";
    var eventID = "start";
    var data = {label: channel};
    wb.DataTJManager.reportData(type, eventID, data, pid);
};

// 
wb.wx.loginPost = function () {
    if (!wb.wx.isWxEnable()) return;
    var option = wb.wx.getLaunchOptionsSync();
    var scene = option.scene;
    var query = option.query;
    var pid = "";
    var channel = "";
    if (query && query.pid) {
        pid = query.pid;
    }
    if (query && query.channel) {
        channel = query.channel;
    }
    var type = "custom";
    var eventID = "login";
    var data = {label: channel};
    wb.DataTJManager.reportData(type, eventID, data, pid);
};

