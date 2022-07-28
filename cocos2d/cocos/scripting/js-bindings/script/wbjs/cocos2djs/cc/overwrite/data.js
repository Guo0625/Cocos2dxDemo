/**
 * Created by Zack on 2018/11/16.
 */

var wb = window.wb || {};
// overwrite interface

wb.Data.getItem = function (key, value) {
    var tag = cc.sys.localStorage.getItem(key);
    if (tag == undefined || tag == "undefined" || tag == null || tag === "") return value;
    return tag;
};

wb.Data.setItem = function (key, value) {
    cc.sys.localStorage.setItem(key, value);
};