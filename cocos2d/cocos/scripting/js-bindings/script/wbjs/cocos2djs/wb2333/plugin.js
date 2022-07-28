var wb = wb || {};

wb.log("plugin~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
var plusReady = function () {
    wb.log("plusready~~~~~~~~~~~~~~");
    var _BARCODE = 'ADManager';
    var bridge = window.plus.bridge;
    var ADManager =
    {
        openAdC: function (AdId, successCallback, errorCallback) {
            ADManager.printLog("openAdC ~~~~~~~~~~~~~~~~~~~~~~~~~~~ ");
            var success = typeof successCallback !== 'function' ? null : function (args) {
                ADManager.printLog("openAdC successCallback ");
                successCallback(args, parseInt(args));
            };

            var fail = typeof errorCallback !== 'function' ? null : function (code) {
                ADManager.printLog("openAdC errorCallback ");
                if (errorCallback) {
                    errorCallback(code, 1);
                }
            };
            var callbackID = bridge.callbackId(success, fail);

            return bridge.exec(_BARCODE, "openAdC", [callbackID, AdId]);
        },
        openAd: function (AdId) {
            return bridge.exec(_BARCODE, "openAd", [AdId]);
        },
        closeAd: function (AdId) {
            return bridge.exec(_BARCODE, "closeAd", [AdId]);
        },
        printLog: function (LogInfo) {
            return bridge.execSync(_BARCODE, "printLog", [LogInfo]);
        },
        isAdReady: function (AdId, type) {
            var result = bridge.execSync(_BARCODE, "isAdReady", [AdId, type]);
            if (result == "")   return false;
            return true;
        },
        getAdPositionParam: function (AdId, key) {
            return bridge.execSync(_BARCODE, "getAdPositionParam", [AdId, key]);
        },
        getVideoLimitOpenNum: function () {
            return Number(bridge.execSync(_BARCODE, "getVideoLimitOpenNum", []));
        },
        isAdBeOpenInLevel: function (AdId, lv) {
            var result = bridge.execSync(_BARCODE, "isAdBeOpenInLevel", [AdId, lv]);
            if (result == "") return false;
            return true;
        },
        setItem: function (key, value) {
            return bridge.execSync(_BARCODE, "setItem", [key, value]);

        },
        getItem: function (key) {
            return bridge.execSync(_BARCODE, "getItem", [key]);
        }
    };

    wb.ADManager.openAd = ADManager.openAd;
    wb.ADManager.closeAd = ADManager.closeAd;
    wb.ADManager.printLog = ADManager.printLog;
    wb.ADManager.isAdReady = ADManager.isAdReady;
    wb.ADManager.getAdPositionParam = ADManager.getAdPositionParam;
    wb.ADManager.getVideoLimitOpenNum = ADManager.getVideoLimitOpenNum;
    wb.ADManager.isAdBeOpenInLevel = ADManager.isAdBeOpenInLevel;

    wb.ADManager.openAdC = function (str, func) {
        cc.audioEngine.pauseMusic();
        var callFun = function (a, result) {
            if (func) func(a, result);
            cc.audioEngine.resumeMusic();
        };
        ADManager.openAdC(str, callFun);
    };
    wb.setItem = function (k, v) {
        ADManager.setItem("" + k, "" + v);
    };
    wb.getItem = function (k, v) {
        var tag = ADManager.getItem("" + k, "" + v);
        if (tag == undefined || tag == "undefined" || tag == null || tag === "" || tag == "nil") return v;
        return tag;
    }
};

if (window.plus) {
    plusReady();
} else {
    document.addEventListener("plusready", plusReady, true);
}
