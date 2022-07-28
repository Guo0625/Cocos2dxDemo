/**
 * Created by Zack on 2018/4/16.
 */
var wb = window.wb || {};

wb.ShadeLayer = cc.LayerColor.extend({
    touchListener: null,
    ctor: function (color, width, height) {
        this._super(color, width, height);

        var listener = cc.EventListener.create({
            event: cc.EventListener.TOUCH_ONE_BY_ONE,
            swallowTouches: true,
            onTouchBegan: function (touch, event) {
                return true;
            }
        });
        cc.eventManager.addListener(listener, this);
        this.touchListener = listener;
        return true;
    },
    onExit: function () {
        this._super();
        cc.eventManager.removeListener(this.touchListener);
    }
});

wb.BaseLayer = cc.Layer.extend({
    rootNode: null,
    object: null,
    shadeLayer: null,
    _keyBoardListener: null,
    _customListeners: null,
    ctor: function (res, path) {
        this._super();
        this.initBaseData();
        this.initBaseUI(res, path);
        // this.addKeyBoard();
        return true;
    },
    onEnter: function () {
        this._super();
    },
    onExit: function () {
        this._super();
        for (var i = 0; i < this._customListeners.length; i++) {
            wb.EventManager.removeListener(this._customListeners[i]);
        }
        if (this._keyBoardListener) cc.eventManager.removeListener(this._keyBoardListener);
    },
    initBaseData: function () {
        this._customListeners = [];
    },
    initBaseUI: function (res, path) {
        //this.shadeLayer = new wb.ShadeLayer(cc.color(0, 0, 0, 125));
        //this.addChild(this.shadeLayer);

        if (!res) return;

        this.object = ccs.load(res, path);
        this.rootNode = this.object.node;
        this.addChild(this.rootNode);
    },
    popUI: function (name, time) {
        var uiPanel = wb.FW(this.rootNode, name);
        wb.popUI(uiPanel, time);
    },
    showShadeLayer: function (flag) {
        if (!this.shadeLayer) return;
        this.shadeLayer.setVisible(flag);
    },
    setKeyBoardFunc: function (func) {
        this._keyboardFunc = func;
    },
    addKeyBoard: function () {
        this._keyBoardListener = cc.EventListener.create({
            event: cc.EventListener.KEYBOARD,
            swallowTouches: true,
            onKeyReleased: function (key, event) {
                event.stopPropagation();
                if (!(key == cc.KEY.back || key == cc.KEY.escape)) return;
                if (this._keyboardFunc) this._keyboardFunc();
                else this.removeFromParent();
            }.bind(this)
        });
        cc.eventManager.addListener(this._keyBoardListener, this);
    },
    closeLayer: function () {
        this.removeFromParent();
    },
    pushCustomEventListener: function (listener) {
        this._customListeners.push(listener);
    },
    fwByRootNode: function (name, func, data) {
        return wb.FW(this.rootNode, name, func, data);
    }
});