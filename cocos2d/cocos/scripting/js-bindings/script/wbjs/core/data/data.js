/**
 * Created by Zack on 2018/11/14.
 */

var wb = window.wb || {};
wb.Data = wb.Data || {};

wb.Data.init = function () {
    if (wb.SysPlatform.isNative()) return;
    wb.log("wb.Data.init~~~");
    wb.Data.localStorage = window.localStorage;
};

wb.Data.getItem = function (key, value) {
    var tag = wb.Data.localStorage.getItem(key);
    if (tag == undefined || tag == "undefined" || tag == null || tag === "") return value;
    return tag;
};

wb.Data.setItem = function (key, value) {
    wb.Data.localStorage.setItem(key, value);
};

wb.Data.init();
