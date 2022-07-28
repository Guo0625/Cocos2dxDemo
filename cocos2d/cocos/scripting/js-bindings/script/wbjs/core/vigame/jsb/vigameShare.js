/**
 * Created by Zack on 2018/1/9.
 */
var wb = window.wb || {};

wb.Share = wb.SysCore.extend(wb.JShare, {});

wb.ShareInfo = wb.SysCore.extend(wb.JShareInfo, {});
wb.ShareInfo._params = {
    "shareTo": "1",
    "platform": "1",
    "shareTo": "0"
};
wb.ShareInfo.platForm = function (value) {
    wb.ShareInfo._params["platform"] = value;
    wb.ShareInfo.setParams(wb.ShareInfo._params);
};
wb.ShareInfo.title = function (value) {
    wb.ShareInfo._params["title"] = value;
    wb.ShareInfo.setParams(wb.ShareInfo._params);
};
wb.ShareInfo.site = function (value) {
    wb.ShareInfo._params["site"] = value;
    wb.ShareInfo.setParams(wb.ShareInfo._params);
};
wb.ShareInfo.siteUrl = function (value) {
    wb.ShareInfo._params["siteUrl"] = value;
    wb.ShareInfo.setParams(wb.ShareInfo._params);
};
wb.ShareInfo.text = function (value) {
    wb.ShareInfo._params["text"] = value;
    wb.ShareInfo.setParams(wb.ShareInfo._params);
};
wb.ShareInfo.imagePath = function (value) {
    wb.ShareInfo._params["imagePath"] = value;
    wb.ShareInfo.setParams(wb.ShareInfo._params);
};
wb.ShareInfo.imageUrl = function (value) {
    wb.ShareInfo._params["imageUrl"] = value;
    wb.ShareInfo.setParams(wb.ShareInfo._params);
};
wb.ShareInfo.thumbImage = function (value) {
    wb.ShareInfo._params["thumbImage"] = value;
    wb.ShareInfo.setParams(wb.ShareInfo._params);
};
wb.ShareInfo.url = function (value) {
    wb.ShareInfo._params["url"] = value;
    wb.ShareInfo.setParams(wb.ShareInfo._params);
};
wb.ShareInfo.shareTo = function (value) {
    wb.ShareInfo._params["shareTo"] = value;
    wb.ShareInfo.setParams(wb.ShareInfo._params);
};
wb.ShareInfo.action = function (value) {
    wb.ShareInfo._params["action"] = value;
    wb.ShareInfo.setParams(wb.ShareInfo._params);
};
wb.ShareInfo.messageExt = function (value) {
    wb.ShareInfo._params["messageExt"] = value;
    wb.ShareInfo.setParams(wb.ShareInfo._params);
};
wb.ShareInfo.shareType = function (value) {
    wb.ShareInfo._params["shareType"] = value;
    wb.ShareInfo.setParams(wb.ShareInfo._params);
};
wb.ShareInfo.tagName = function (value) {
    wb.ShareInfo._params["tagName"] = value;
    wb.ShareInfo.setParams(wb.ShareInfo._params);
};


wb.ShareManager = wb.SysCore.extend(wb.JShareManager, {});