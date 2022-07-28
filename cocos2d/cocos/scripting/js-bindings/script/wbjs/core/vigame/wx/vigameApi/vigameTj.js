/**
 * Created by Zack on 2018/1/9.
 */
var wb = window.wb || {};
wb.DataTJManager = wb.SysCore.extend(wb.JDataTJManager, {});

wb.DataTJManager.eventType = {
    startLevel: {type: "level", eventID: "begin", tag: "levelid"},
    finishLevel: {type: "level", eventID: "complete", tag: "levelid"},
    failLevel: {type: "level", eventID: "fail", tag: "levelid"},
    setUserData: {type: "acount", eventID: "update"},
    onShare: {type: "custom", eventID: "share_click"},
    onShareEnter: {type: "custom", eventID: "share_enter"}
};

wb.DataTJManager.onEvent = function (key, label) {
    var type = "custom";
    var eventID = key;
    var data = {};
    if (typeof label == "string") {
        data = {
            label: label
        }
    } else if (typeof label == "object") {
        data = label;
    }
    this.reportData(type, eventID, data);
};

wb.DataTJManager.reportData = function (type, eventID, data, pid) {
    wb.log("onEvent:type=" + type + ",eventID=" + eventID);
    var tData = {
        type: type,
        eventid: eventID,
        wxappid: wb.wxConfig.wbAppID,
        openid: wb.wxData.openid,
        pid: pid,
        data: data,
        lsn: wb.wxData.userLsn,
        unionid: wb.wxData.unionId
    };
    var base64value = wb.Base64.encode(JSON.stringify(tData));

    var url = wb.wxConfig.wxTjUrl + wb.wxConfig.wbAppID + "?value=" + base64value;
    wb.log("reportData url : " + url);
    wb.Http.httpRequest(url, data, function () {
    });
};

// 小游戏统计
wb.DataTJManager.event2 = function (key, value, placement) {
    if (!wb.wx.isWxEnable() || !wb.wxData.openid) return;

    var eventType = wb.DataTJManager.eventType[key];
    if (eventType) {
        var data = value;
        var tag = eventType.tag;
        if (tag) {
            data = {};
            data[tag] = value;
        }
        data.placement = placement;
        wb.DataTJManager.reportData(eventType.type, eventType.eventID, data);
    } else if (typeof(value) == 'object') {
        value.placement = placement;
        wb.DataTJManager.reportData("custom", key, value);
    } else {
        var data = {};
        data.label = value;
        if (placement) data.placement = placement;
        wb.DataTJManager.reportData("custom", key, data);
    }
};