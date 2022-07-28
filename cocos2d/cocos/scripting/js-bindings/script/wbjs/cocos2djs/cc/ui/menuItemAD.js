/**
 * Created by Zack on 2018/1/10.
 */
var wb = window.wb || {};

wb.MenuItemAD = cc.MenuItemSprite.extend({
    _index: null,
    _img: null,
    _open: null,
    _link: null,
    _icon: null,
    _param: null,
    ctor: function (index) {
        this._super();
        this._index = index;
        this.initData();
        this.initUI();
        if (wb.isNative()) this.initWithCallback(this.onClickMenu);
        else this.initWithCallback(this.onClickMenu, this);
        return true;
    },
    initData: function () {
        this.setConfigIndex(this._index);
    },
    initUI: function () {
    },
    setConfigIndex: function (index) {
        var length = wb.XYXManager.getListLength();
        if (index >= length) return;
        this._index = index;
        this.flushData();
        wb.XYXManager.exposure(wb.menuItemADLayer.xyxConfig.getAdShowUrl(), this._icon);
    },
    flushData: function () {
        var config = wb.XYXManager.getConfig();
        this._img = config.getImageList()[this._index];
        this._open = config.getOpenList()[this._index];
        this._link = config.getLinkUrlList()[this._index];
        this._icon = config.getIconList()[this._index];
        this._param = config.getParamList()[this._index];
        this.loadIcon();
    },
    loadIcon: function () {
        this.initMenuADWithTexture(wb.menuItemADLayer.iconImageMap[this._icon]);
    },
    initMenuADWithTexture: function (texture) {
        var sp = new cc.Sprite(texture);
        this.setNormalImage(sp);
        this.setContentSize(sp.getContentSize());
    },
    setItemSize: function (size) {
        wb.scaleToSize(this, size);
    },
    onClickMenu: function () {
        if ("image" == this._open) {
        } else if ("url" == this._open) {
            wb.Browser.openInnerWeb(this._link);
        } else if ("miniProgram" == this._open) {
            wb.Helper.openMiniProgram(this._link, this._param);
        }
        wb.XYXManager.exposure(wb.menuItemADLayer.xyxConfig.getAdClickUrl(), this._icon);
        wb.menuItemADLayer.nextItem(this, this._index);
    }
});

wb.createMenuItemAD = function (index) {
    return new wb.MenuItemAD(index);
};