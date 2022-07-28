/**
 * Created by Zack on 2018/1/11.
 */
var wb = window.wb || {};

wb.MenuItemADLayer = cc.Layer.extend({
    itemNum: null,
    itemSize: null,
    iconImageMap: null,
    btnItemList: null,
    loadIconIndex: null,
    iconDataIndexList: null,
    xyxConfig: null,
    listener: null,
    ctor: function (data) {
        this._super();
        wb.menuItemADLayer = this;
        this.initListener();
        this.initData();
        this.initUI(data);
        return true;
    },
    onExit: function () {
        this._super();
        if (this.listener) cc.eventManager.removeListener(this.listener);
    },
    initData: function () {
        this.iconImageMap = {};
        this.btnItemList = [];
        this.loadIconIndex = 0;
        this.itemNum = Math.min(4, wb.XYXManager.getListLength());
        this.itemSize = cc.size(100, 100);
        this.iconDataIndexList = [];
        this.xyxConfig = wb.XYXManager.getConfig();
        cc.log("this.itemNum " + this.itemNum);
        this.loadIcon();
    },
    initUI: function (data) {
        if (data && data.offsetP) this.setPosition(cc.p(data.offsetP.x, data.offsetP.y));
    },
    initListener: function () {
        var listener = cc.EventListener.create({
            event: cc.EventListener.CUSTOM,
            eventName: "show_showItemAd",
            callback: function () {
                this.showItemAd();
            }.bind(this)
        });
        this.listener = listener;
        cc.eventManager.addListener(listener, 1);
    },
    loadIcon: function () {
        if (this.itemNum <= 0) return;
        var configIconList = this.xyxConfig.getIconList();
        this.configIconList = wb.uniqueArray(configIconList);
        cc.loader.loadImg(this.configIconList[this.loadIconIndex], {isCrossOrigin: true}, this.loadCb);
    },
    loadCb: function (err, img) {
        if (err) return;
        var self = wb.menuItemADLayer;
        cc.log("self.loadIconIndex " + self.loadIconIndex);
        self.iconImageMap[self.configIconList[self.loadIconIndex]] = img;
        self.loadIconIndex++;
        if (self.loadIconIndex >= self.configIconList.length) {
            // self.showItemAd();
            cc.eventManager.dispatchEvent(new cc.EventCustom("show_showItemAd"));
            return;
        }
        cc.loader.loadImg(self.configIconList[self.loadIconIndex], {isCrossOrigin: true}, self.loadCb);
    },
    showItemAd: function () {
        var itemList = [];
        var index_start = 0;
        var index_end = this.itemNum;
        if (wb.XYXManager.getListLength() > 4) {
            var temp = Math.ceil(wb.XYXManager.getListLength() / 4.0);
            var te = Math.floor(Math.random() * temp + 1);
            if (te * 4 > wb.XYXManager.getListLength()) {
                index_end = wb.XYXManager.getListLength();
                index_start = index_end - 4;
            }
            else {
                index_start = (te - 1) * 4;
                index_end = te * 4;
            }
        }
        for (var i = index_start; i < index_end; i++) {
            var item = new wb.MenuItemAD(i);
            item.setItemSize(this.itemSize);
            itemList.push(item);
            this.iconDataIndexList[i] = true;
        }
        var dx = (wb.getWinSize().width - this.itemNum * this.itemSize.width) / (this.itemNum + 1);
        if (dx < 0) dx = 0;
        var menu = new cc.Menu(itemList);
        menu.alignItemsHorizontallyWithPadding(dx);
        menu.setPositionY(100);
        this.addChild(menu);
    },
    nextItem: function (item, index) {
        var length = wb.XYXManager.getListLength();
        if (this.itemNum >= length) return;
        var i = index;
        do {
            if (!this.iconDataIndexList[i] && i != index) {
                item.setConfigIndex(i);
                item.setItemSize(this.itemSize);
                this.iconDataIndexList[i] = true;
                this.iconDataIndexList[index] = false;
                break;
            }
            i = i + 1;
            if (i >= length) i = 0;
        } while (true);
    },
    show: function () {
        this.removeAllChildren();
        this.showItemAd();
    }
});
var MenuItemADLayer = wb.MenuItemADLayer;

wb.createMenuItemADLayer = function () {
    return new wb.MenuItemADLayer();
};