/**
 * Created by Zack on 2018/4/16.
 */
var wb = window.wb || {};

wb.EVENT_COIN_CHANGE = "coin_change";

// overwrite
wb.EventManager = {
    dispatchCustomEvent: function (eventStr, data) {
        var event = new cc.EventCustom(eventStr);
        if (data) event.setUserData(data);
        cc.eventManager.dispatchEvent(event);
    },
    addCustomEventListener: function (eventStr, func, tager) {
        var listener = cc.EventListener.create({
            event: cc.EventListener.CUSTOM,
            eventName: eventStr,
            callback: func
        });

        cc.eventManager.addListener(listener, 1);

        if (tager && tager.pushCustomEventListener) tager.pushCustomEventListener(listener);
        return listener;
    },
    removeListener: function (listener) {
        if (!listener) return;
        cc.eventManager.removeListener(listener);
    }
};
