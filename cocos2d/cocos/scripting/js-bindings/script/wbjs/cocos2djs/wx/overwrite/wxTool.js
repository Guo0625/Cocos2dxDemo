/**
 * Created by Administrator on 2018/11/15.
 */

var wb = window.wb || {};
wb.wxTool = wb.wxTool || {};

wb.wxTool.loadImg = function (url, func) {
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