/**
 * Created by Zack on 2018/1/9.
 */
var wb = window.wb || {};

wb.GCUserDefault = wb.SysCore.extend(wb.JGCUserDefault, {});
wb.GCUserDefault.setIntegerForKey = function (key, value) {
    if (wb.SysPlatform.isNative()) this.parent.setIntegerForKey(key, parseInt(value));
    else wb.Data.setItem(key, parseInt(value));
};

wb.GCUserDefault.setDoubleForKey = function (key, value) {
    if (wb.SysPlatform.isNative()) this.parent.setDoubleForKey(key, parseFloat(value));
    else wb.Data.setItem(key, parseFloat(value));
};
wb.GCUserDefault.setStringForKey = function (key, value) {
    if (wb.SysPlatform.isNative()) this.parent.setStringForKey(key, String(value));
    else wb.Data.setItem(key, String(value));
};

wb.GCUserDefault.setBoolForKey = function (key, value) {
    if (wb.SysPlatform.isNative()) this.parent.setBoolForKey(key, Boolean(value));
    else wb.Data.setItem(key, wb.boolToStr(Boolean(value)));
};


wb.GCUserDefault.getBoolForKey = function (key, value) {
    if (value == undefined || value == null)  value = false;
    if (wb.SysPlatform.isNative()) return this.parent.getBoolForKey(key, value);
    return wb.SysValue.strToBool(wb.Data.getItem(key, value));
};

wb.GCUserDefault.getStringForKey = function (key, value) {
    if (value == undefined || value == null)  value = "";
    if (wb.SysPlatform.isNative()) return this.parent.getStringForKey(key, value);
    return wb.Data.getItem(key, value);
};

wb.GCUserDefault.getIntegerForKey = function (key, value) {
    if (value == undefined || value == null)  value = -1;
    if (wb.SysPlatform.isNative()) return this.parent.getIntegerForKey(key, value);
    return parseInt(wb.Data.getItem(key, value));
};
wb.GCUserDefault.getDoubleForKey = function (key, value) {
    if (value == undefined || value == null)  value = -1;
    if (wb.SysPlatform.isNative()) return this.parent.getDoubleForKey(key, value);
    return parseFloat(wb.Data.getItem(key, value));
};

wb.GCUserDefault.setItem = function (key, value) {
    if (wb.SysValue.isInteger(value)) wb.GCUserDefault.setIntegerForKey(key, value);
    else if (wb.SysValue.isFloat(value)) wb.GCUserDefault.setDoubleForKey(key, value);
    else if (wb.SysValue.isString(value)) wb.GCUserDefault.setStringForKey(key, value);
    else if (wb.SysValue.isBoolean(value)) wb.GCUserDefault.setBoolForKey(key, value);
    else wb.log("setItem error!");
};

wb.GCUserDefault.getItem = function (key, value) {
    if (value == undefined || value == null)  value = "";
    if (wb.SysPlatform.isNative()) return this.parent.getStringForKey(key, value);
    return wb.Data.getItem(key, value);
};



