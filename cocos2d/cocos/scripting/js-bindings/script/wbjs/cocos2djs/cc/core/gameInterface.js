/**
 * Created by Zack on 2018/4/18.
 */

var wb = window.wb || {};

wb.showMenuItemADLayer = function (offsetX, offsetY, layerName, zOrder, data) {
    offsetX = offsetX ? offsetX : 0;
    offsetY = offsetY ? offsetY : 0;
    layerName = layerName ? layerName : "";
    zOrder = zOrder ? zOrder : 0;

    if (wb.wx) {
        data = data ? data : {};
        var menuADLayer = wb.createPushAdLayer(data.placement, data.btnIndexList, data.num, data.btnDw);
        if (!menuADLayer) return null;

        if (offsetY == 0) offsetY = 100;
        if (offsetX == 0) offsetX = cc.director.getWinSize().width / 2;

        if (layerName == "") {
            wb.addNodeToScene(menuADLayer, zOrder);
        } else {
            var scene = cc.director.getRunningScene();
            var layer = scene.getChildByName(layerName);
            if (!layer) return;
            layer.addChild(menuADLayer, zOrder);
        }
        menuADLayer.setPosition(cc.p(offsetX, offsetY));
        return menuADLayer;
    } else if (wb.SysPlatform.isNative()) {
        wb.Helper.createMenuADLayer(offsetX, offsetY, layerName, zOrder);
        return null;
    } else {
        //var menuADLayer = new wb.MenuItemADLayer(null);
        //if (layerName == "") {
        //    wb.addNodeToScene(menuADLayer, zOrder);
        //} else {
        //    var scene = cc.director.getRunningScene();
        //    var layer = scene.getChildByName(layerName);
        //    if (!layer) return;
        //    layer.addChild(menuADLayer, zOrder);
        //}
        //menuADLayer.setPosition(cc.p(offsetX, offsetY));

        var menuADLayer = wb.createPushAdLayer();
        if (!menuADLayer) return null;
        if (offsetY == 0) offsetY = 100;
        if (offsetX == 0) offsetX = cc.director.getWinSize().width / 2;

        if (layerName == "") {
            wb.addNodeToScene(menuADLayer, zOrder);
        } else {
            var scene = cc.director.getRunningScene();
            var layer = scene.getChildByName(layerName);
            if (!layer) return;
            layer.addChild(menuADLayer, zOrder);
        }
        menuADLayer.setPosition(cc.p(offsetX, offsetY));
        return menuADLayer;
    }
};

wb.showToast = function (str) {
    wb.Toast.makeText(str);
};
wb.showAppInfoLayer = function () {
    var layer = new wb.AppInfoLayer();
    layer.show();
    wb.addNodeToScene(layer);
};

//wb.showCzlbLayer = function (data) {
//    wb.addNodeToScene(new wb.CzlbLayer(data));
//};
//
//wb.showXslbLayer = function (data) {
//    wb.addNodeToScene(new wb.XslbLayer(data));
//};
//
//wb.showNoAdLayer = function (data) {
//    wb.addNodeToScene(new wb.NoAdLayer(data));
//};
//
//wb.showRewardLayer = function (data) {
//    wb.addNodeToScene(new wb.RewardLayer(data));
//};
//
//wb.showShopLayer = function (data) {
//    wb.addNodeToScene(new wb.ShopLayer(data));
//};