/**
 * Created by zack on 2018/10/31.
 */
var wb = window.wb || {};
wb.UserInfoLayer = cc.Layer.extend({
    shadeLayer: null,
    callFunc: null,
    data: null,
    ctor: function (func, data) {
        this._super();
        this.initData(func, data);
        this.initUI();
    },
    initData: function (func, data) {
        this.callFunc = func;
        this.data = data ? data : {};
    },
    initUI: function () {
        if (!wb.isWX()) return;
        var winSize = cc.director.getWinSize();
        this.shadeLayer = new ccui.Layout();
        this.shadeLayer.setContentSize(winSize);
        this.shadeLayer.setBackGroundColor(cc.color.BLACK);
        this.shadeLayer.setBackGroundColorType(ccui.Layout.BG_COLOR_SOLID);
        this.shadeLayer.setBackGroundColorOpacity(180);
        this.shadeLayer.setTouchEnabled(true);
        this.addChild(this.shadeLayer);

        this.showGetUserBtn();
    },
    showGetUserBtn: function () {
        if (!wb.isWX()) return;
        var winW = wb.wx.getSystemInfoSync().windowWidth;
        var winH = wb.wx.getSystemInfoSync().windowHeight;
        var btnW = this.data.btnW ? this.data.btnW : 200;
        var btnH = this.data.btnH ? this.data.btnH : 50;
        var backgroundColor = this.data.btnBackgroundColor ? this.data.btnBackgroundColor : '#feb938';
        var color = this.data.fontColor ? this.data.fontColor : '#000000';
        var fontSize = this.data.fontSize ? this.data.fontSize : 20;
        var btnText = this.data.btnText ? this.data.btnText : '获取用户信息';

        var wxStartButton = wb.wx.createUserInfoButton({
            type: 'text',
            text: btnText,
            style: {
                left: winW / 2 - btnW / 2,
                top: winH / 2 - btnH / 2,
                width: btnW,
                height: btnH,
                lineHeight: btnH,
                backgroundColor: backgroundColor,
                color: color,
                textAlign: 'center',
                fontSize: fontSize,
                borderRadius: btnH / 2
            }
        });

        wxStartButton.onTap(function (res) {
            if (!res.rawData)  return;
            cc.log("wxStartButton.onTap~~~~~~~~~");
            cc.log(res);
            wb.setItem("wxUserInfos", res.rawData);
            var userInfos = JSON.parse(res.rawData);
            cc.log(userInfos);
            this.callLogin(res);
            wxStartButton.hide();
            if (this.callFunc) this.callFunc(userInfos);
            this.removeFromParent();
        }.bind(this));
        wxStartButton.show();
    },
    callLogin: function (resUser) {
        wb.wx.login({
            success: function (res) {
                var requestData = "js_code=" + res.code + "&pid=" + wb.wxConfig.pid;
                cc.log("callLogin " + requestData);
                wb.Http.httpRequest(wb.wxConfig.wxLoginUrl, requestData, function (data) {
                    cc.log("wb.wxData.initLoginData4");
                    var sessionKey = data.session_key;
                    wb.wxData.openid = data.openid;
                    cc.log("wxOpenid=" + wb.wxData.openid);
                    cc.log("sessionKey " + sessionKey);
                    wb.setItem("wxOpenid", "" + wb.wxData.openid);
                    this.initUnionid(resUser, sessionKey);
                }.bind(this), false);
            }.bind(this),
            fail: function () {
                cc.log("login fail");
                // if (callFunc) callFunc(null);
            }.bind(this)
        });
    },
    // 获取unionid
    initUnionid: function (resUser, sessionKey) {

        var strData = {
            iv: resUser.iv,
            encryptedData: resUser.encryptedData,
            sessionKey: sessionKey
        };
        wb.wx.request({
            url: wb.wxConfig.wxUnionidUrl,
            method: 'POST',
            data: strData,
            header: {
                'content-type': 'application/x-www-form-urlencoded'
            },
            success: function (res) {
                cc.log("====wxDeCrypt===");
                cc.log(res.data.unionId);
                if (res.data.unionId) {
                    wb.wxData.unionId = res.data.unionId;
                    wb.setItem("wxUnionId", "" + res.data.unionId);
                }
            }
        })
    }
});

wb.createUserInfoLayer = function (callFunc, data) {
    var wxUserInfos = wb.getItem("wxUserInfos", "");
    wb.wxData.unionId = wb.getItem("wxUnionId", "");
    if (wxUserInfos.length > 0) {
        if (callFunc) callFunc(wb.parse(wxUserInfos));
        return;
    }
    return new wb.UserInfoLayer(callFunc, data);
};