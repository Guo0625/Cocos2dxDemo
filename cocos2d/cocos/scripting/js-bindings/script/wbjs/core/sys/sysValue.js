/**
 * Created by Zack on 2018/11/14.
 */

var wb = window.wb || {};
wb.SysValue = wb.SysValue || {};

wb.SysValue.isInteger = function (obj) {
    return typeof obj === "number" && obj % 1 === 0
};

wb.SysValue.isFloat = function (obj) {
    return typeof obj === "number" && obj % 1 != 0
};

wb.SysValue.isBoolean = function (obj) {
    return typeof obj === "boolean";
};

wb.SysValue.isString = function (obj) {
    return typeof obj === "string";
};

wb.SysValue.isArray = function (obj) {
    if (obj instanceof Array) return true;
    return false;
};

wb.SysValue.isObject = function (obj) {
    if (wb.SysValue.isArray(obj)) return false;
    return typeof obj === "object";
};

wb.SysValue.uniqueObj = function (objOrigin, objNew) {
    for (var k in objOrigin) {
        if (objOrigin.hasOwnProperty(k)) {
            if (objNew[k] == undefined) {
                objNew[k] = objOrigin[k];
            }
        }
    }
    return objNew;
};

wb.SysValue.uniqueArray = function (array) {
    var result = [];
    for (var i = 0; i < array.length; i++) {
        if (result.indexOf(array[i]) == -1) result.push(array[i]);
    }
    return result;
};

wb.SysValue.concatArray = function (array) {
    var arr, i;
    for (i = 1; i < arguments.length; i++) {
        arr = arguments[i];
        Array.prototype.push.apply(array, arr);
    }
};

wb.SysValue.spliceArray = function (array, index, num) {
    var i, len;
    for (i = index + num, len = array.length; i < len; i++) {
        array[i - num] = array[i];
    }
    array.length = len - num;
};

wb.SysValue.copyArray = function (array) {
    var arrTemp = [];
    for (var i = 0; i < array.length; i++) {
        arrTemp.push(array[i])
    }
    return arrTemp
};

wb.SysValue.isInArray = function (array, item) {
    for (var i = 0; i < array.length; i++) {
        if (array[i] == item) return true;
    }
    return false
};

wb.SysValue.getRandomInArray = function (array) {
    if (array == null) return null;
    var i = wb.SysValue.randNum(0, array.length - 1);
    return array[i];
};

wb.SysValue.shuffleArray = function (array, len) {
    if (len === undefined || len <= 0 || len > array.length) len = array.length;
    for (var i = len - 1; i >= 0; i--) {
        var j = 0 | (cc.rand() % (i + 1));
        var v = array[i];
        array[i] = array[j];
        array[j] = v;
    }
};

wb.SysValue.getLastInArray = function (array) {
    if (!array || array.length <= 0) return null;
    return array[array.length - 1];
};

wb.SysValue.getFirstInArray = function (array) {
    if (!array || array.length <= 0) return null;
    return array[0];
};

wb.SysValue.getItemInArrayByFunc = function (array, func) {
    if (!array || !func) return null;
    for (var i = 0; i < array.length; i++) {
        if (func(array[i])) return array[i];
    }
    return null;
};

wb.SysValue.removeItemInArray = function (array, item) {
    var index = array.indexOf(item);
    if (index <= -1) return false;
    array.splice(index, 1);
    return true;
};


wb.SysValue.randNum = function (min, max) {
    return Math.floor(Math.random() * (max - min + 1) + min);
};

wb.SysValue.randBool = function () {
    if (wb.SysValue.randNum(1, 10) <= 5) return true;
    return false;
};

wb.SysValue.boolToStr = function (flag) {
    if (flag) return "true";
    return "false"
};

wb.SysValue.strToBool = function (str) {
    if ("true" == str || str === true) return true;
    return false;
};

wb.SysValue.subStr = function (str, n) {
    var r = /[^\x00-\xff]/g;
    if (str.replace(r, "mm").length <= n) {
        return str;
    }
    var m = Math.floor(n / 2);
    for (var i = m; i < str.length; i++) {
        if (str.substr(0, i).replace(r, "mm").length >= n) {
            return str.substr(0, i) + "...";
        }
    }
    return str;
};

wb.SysValue.getStrLen = function (str) {
    return str.replace(/[\u0391-\uFFE5]/g, "aa").length;
};

wb.SysValue.angleNormal = function (angle) {
    var newAngle = angle - parseInt(angle / 360) * 360;
    if (newAngle < 0) newAngle = newAngle + 360;
    return newAngle;
};

wb.SysValue.stringify = function (dataObject) {
    return JSON.stringify(dataObject)
};

wb.SysValue.parse = function (jsonstr) {
    return JSON.parse(jsonstr);
};

wb.SysValue.subScore = function (n) {
    var num = parseFloat(n);
    if (num > 1000) {
        num = num / 1000;
        return "" + num.toFixed(1) + "k";
    } else if (num > 10000) {
        num = num / 10000;
        return "" + num.toFixed(1) + "w";
    }
    return "" + n;
};

wb.SysValue.each = function (obj, iterator, context) {
    if (!obj)  return;
    if (obj instanceof Array) {
        for (var i = 0, li = obj.length; i < li; i++) {
            if (iterator.call(context, obj[i], i) === false) return;
        }
    } else {
        for (var key in obj) {
            if (iterator.call(context, obj[key], key) === false)  return;
        }
    }
};