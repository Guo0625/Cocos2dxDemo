/**
 * Created by Zack on 2018/1/9.
 */
var wb = window.wb || {};

wb.Helper = wb.SysCore.extend(wb.GameHelper, {});

wb.Helper.setMusic = function (boolEnable) {
    wb.GCUserDefault.setItem("music", boolEnable);
    wb.GCUserDefault.save();
};

wb.Helper.setEffect = function (boolEnable) {
    wb.GCUserDefault.setItem("sound", boolEnable);
    wb.GCUserDefault.save();
};

/**
 * @method getMusic
 * @return {bool}
 */
wb.Helper.getMusic = function () {
    return wb.GCUserDefault.getBoolForKey("music", true);
};

/**
 * @method getEffect
 * @return {bool}
 */
wb.Helper.getEffect = function () {
    return wb.GCUserDefault.getBoolForKey("sound", true);
};

/**
 * @method addCoin
 * @param {int} arg0
 */
wb.Helper.addCoin = function (adds) {
    var coins = wb.getCoin();
    wb.GCUserDefault.setIntegerForKey("coins", coins + adds);
    wb.GCUserDefault.save();
};

/**
 * @method getCoin
 * @return {int}
 */
wb.Helper.getCoin = function () {
    return wb.GCUserDefault.getIntegerForKey("coins", 0);
};

/**
 * @method subCoin
 * @param {int} arg0
 */
wb.Helper.subCoin = function (subs) {
    var coins = wb.Helper.getCoin();
    coins = Math.max(coins - subs, 0);
    wb.GCUserDefault.setIntegerForKey("coins", coins);
    wb.GCUserDefault.save();
};

wb.Helper.setADEnabled = function (enabled) {
    wb.GCUserDefault.setBoolForKey("ADEnabled", enabled);
    wb.GCUserDefault.save();

};

wb.Helper.getADEnabled = function () {
    return wb.GCUserDefault.getBoolForKey("ADEnabled", true);
};

