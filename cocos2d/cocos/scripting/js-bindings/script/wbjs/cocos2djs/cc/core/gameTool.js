/**
 * Created by Zack on 2018/11/15.
 */

var wb = window.wb || {};

wb.os = function () {
    return cc.sys.os;
};

wb.isNative = function () {
    if (wb.isWX()) return false;
    return cc.sys.isNative;
};
wb.isWX = function () {
    return window.wx ? true : false;
};
wb.isMobile = function () {
    return cc.sys.isMobile;
};

wb.isMobileBrowser = function () {
    return cc.sys.platform == cc.sys.MOBILE_BROWSER;
};

wb.isDesktopBrowser = function () {
    return cc.sys.platform == cc.sys.DESKTOP_BROWSER;
};

wb.isBrowser = function () {
    return wb.isDesktopBrowser() || wb.isMobileBrowser();
};

wb.browserType = function () {
    return cc.sys.browserType;
};

wb.isInteger = function (obj) {
    return wb.SysValue.isInteger(obj);
};

wb.isFloat = function (obj) {
    return wb.SysValue.isFloat(obj);
};

wb.isBoolean = function (obj) {
    return wb.SysValue.isBoolean(obj);
};

wb.isString = function (obj) {
    return wb.SysValue.isString(obj);
};

wb.isArray = function (obj) {
    return wb.SysValue.isArray(obj);
};

wb.isObject = function (obj) {
    return wb.SysValue.isObject(obj);
};

///////////////////////////////////////////////////

wb.uniqueObj = function (objOrigin, objNew) {
    return wb.SysValue.uniqueObj(objOrigin, objNew);
};

wb.uniqueArray = function (array) {
    return wb.SysValue.uniqueArray(array);
};

wb.concatArray = function (array) {
    wb.SysValue.concatArray(array);
};

wb.spliceArray = function (array, index, num) {
    wb.SysValue.spliceArray(array, index, num);
};

wb.copyArray = function (array) {
    return wb.SysValue.copyArray(array);
};

wb.isInArray = function (array, item) {
    return wb.SysValue.isInArray(array, item);
};

wb.getRandomInArray = function (array) {
    return wb.SysValue.getRandomInArray(array);
};

wb.shuffleArray = function (array, len) {
    wb.SysValue.shuffleArray(array, len);
};

wb.getLastInArray = function (array) {
    return wb.SysValue.getLastInArray(array);
};

wb.getFirstInArray = function (array) {
    return wb.SysValue.getFirstInArray(array);
};

wb.getItemInArrayByFunc = function (array, func) {
    return wb.SysValue.getItemInArrayByFunc(array, func);
};

wb.removeItemInArray = function (array, item) {
    return wb.SysValue.removeItemInArray(array, item);
};

////////////////////////////////////////////////

wb.randNum = function (min, max) {
    return wb.SysValue.randNum(min, max);
};

wb.randBool = function () {
    return wb.SysValue.randBool();
};
////////////////////////////////////////////////

wb.boolToStr = function (flag) {
    return wb.SysValue.boolToStr(flag);
};

wb.strToBool = function (str) {
    return wb.SysValue.strToBool(str);
};

wb.subScore = function (n) {
    return wb.SysValue.subScore(n);
};

wb.stringify = function (dataObject) {
    return wb.SysValue.stringify(dataObject);
};

wb.parse = function (jsonStr) {
    return wb.SysValue.parse(jsonStr);
};

wb.angleNormal = function (angle) {
    return wb.SysValue.angleNormal(angle);
};

wb.base64 = wb.Tools.base64;

wb.subStr = function (str, n) {
    return wb.SysValue.subStr(str, n);
};

wb.getStrLen = function (str) {
    return wb.SysValue.getStrLen(str);
};

////////////////////////////////////////////////

wb.getWinSize = function () {
    return cc.director.getWinSize();
};


wb.getItem = function (key, value) {
    var tag = cc.sys.localStorage.getItem(key);
    if (tag == undefined || tag == "undefined" || tag == null || tag === "") return value;
    return tag;
};
// overwrite
wb.Data.setItem = wb.getItem;


wb.setItem = function (key, value) {
    cc.sys.localStorage.setItem(key, value);
};
// overwrite
wb.Data.setItem = wb.setItem;

//////////////////////////////////////////////////

wb.FW = function (rootNode, name, func, data) {
    if (func) return wb.FWC(rootNode, name, func, data);
    return ccui.helper.seekWidgetByName(rootNode, name);
};

wb.FWC = function (rootNode, name, func, data) {
    var node = wb.FW(rootNode, name);
    if (!node) return null;
    if (node instanceof ccui.Button) node.setPressedActionEnabled(true);
    node.addClickEventListener(func);
    node.data = data;
    return node;
};

//////////////////////////////////////////////////
wb.closeAllAd = function () {
    for (var i = 0; i < wb.adPosition.length; i++) {
        wb.ADManager.closeAd(wb.adPosition[i]);
    }
};

wb.popAction = function (time) {
    if (!time) time = 0;
    return cc.sequence(cc.delayTime(time), cc.scaleTo(0.2, 1.1), cc.scaleTo(0.2, 1.0));
};

wb.popUI = function (node, time) {
    if (!node) return false;
    node.setScale(0);
    node.runAction(wb.popAction(time));
};

wb.btnClickAction = function () {
    return cc.sequence(cc.scaleTo(0.05, 1.1), cc.scaleTo(0.05, 1.0));
};

wb.scaleToSize = function (node, size) {
    var nodeSize = node.getContentSize();
    node.setScaleX(size.width / nodeSize.width);
    node.setScaleY(size.height / nodeSize.height);
};

wb.getCenterP = function () {
    var size = cc.director.getWinSize();
    return cc.p(size.width / 2, size.height / 2);
};

wb.getNodeSubP = function (node1, node2) {
    if (!node1 || !node2) return null;
    return cc.p(node1.getPositionX() - node2.getPositionX(), node1.getPositionY() - node2.getPositionY());
};

wb.getNodeCenterP = function (node) {
    if (!node) return null;
    var size = node.getContentSize();
    return cc.p(size.width / 2, size.height / 2);
};
///////////////////////////////////////////////////////
wb.getCoin = function () {
    return wb.getCoinDefault(0);
};

wb.getCoinDefault = function (val) {
    return parseInt(wb.GCUserDefault.getItem("coins", val));
};

wb.setCoin = function (val) {
    wb.GCUserDefault.setItem("coins", val);
    wb.GCUserDefault.save();
};

wb.addCoin = function (val) {
    var c_coin = wb.getCoin();
    if (c_coin <= 0 && val < 0)
        return false;
    wb.setCoin(c_coin + val > 0 ? (c_coin + val) : 0);
    wb.GCUserDefault.save();
    return true;
};

wb.getMusicEnable = function () {
    return parseInt(wb.GCUserDefault.getItem("music", 1));
};

wb.setMusicEnable = function (val) {
    wb.GCUserDefault.setItem("music", val ? 1 : 0);
    wb.GCUserDefault.save();
};

wb.getSoundEnable = function () {
    return parseInt(wb.GCUserDefault.getItem("sound", 1));
};

wb.setSoundEnable = function (val) {
    wb.GCUserDefault.setItem("sound", val ? 1 : 0);
    wb.GCUserDefault.save();
};

wb.getADEnabled = function () {
    return wb.GCUserDefault.getBoolForKey("ADEnabled", true);
};

wb.setADEnabled = function (enabled) {
    wb.GCUserDefault.setBoolForKey("ADEnabled", enabled);
    wb.GCUserDefault.save();
};

wb.playEffect = function (char, bool) {
    if (wb.getSoundEnable()) cc.audioEngine.playEffect((char), bool);
};

wb.playMusic = function (char, bool) {
    cc.audioEngine.stopMusic();
    if (wb.getMusicEnable()) cc.audioEngine.playMusic((char), bool);
};

/////////////////////////////////////////////////////////////

wb.addNodeToScene = function (node, zorder) {
    if (!node) return;
    if (!zorder) zorder = 999999;
    cc.director.getRunningScene().addChild(node, zorder);
};

wb.loadImg = function (url, func) {
    cc.loader.loadImg(url, {isCrossOrigin: true}, function (err, img) {
        if (err) return cc.log(err);
        cc.log("img " + img);
        var texture2d = cc.loader.getRes(url);
        if (!texture2d) {
            texture2d = new cc.Texture2D();
            texture2d.initWithElement(img);
            texture2d.handleLoadedTexture();
        }
        if (func) func(texture2d);
    });
};

