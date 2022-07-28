/**
 * Created by Zack on 2018/1/9.
 */
var wb = window.wb || {};
wb.isWeb = false;

// 推送
wb.pushUrl = "https://api.vzhifu.net/wxIconPush";

wb.PAY_SUCCED_STR = "购买成功!";

// 购买去广告礼包后，保留的广告位
wb.adVideoPosition = ["level_fail_mfzs", "skin", "double_fail_mfzs", "home_mfzs", "mfdj"];

wb.adPosition = ["home", "banner", "level_fail", "pause", "game_awaken"];

wb.pushRes = {
    wxPushBg: "res/wxRes/pushBg.png",     // 推送的底图
    pushFrame: "res/wxRes/pushFrame.png",  // 推送的框
    pushPlbg: "res/wxRes/pushPlbg.png",
    pushX: "res/wxRes/pushX.png"
};


wb.XYXConfigTest = {
    iconUrlList: [
        "http://a.vigame.cn/push_img/e48c6a0d54bbb2bf599bfafb87fc27f3.png",
        "http://a.vigame.cn/apk/baec6461b0d69dde1b861aefbe375d8a.png",
        "http://a.vigame.cn/apk/73cc953b4f6dc09a1953e01e424534ff.jpg",
        "http://a.vigame.cn/push_img/78bda131b9eeced384a1b326625e3163.png",
        "http://a.vigame.cn/apk/baec6461b0d69dde1b861aefbe375d8a.png",
        "http://a.vigame.cn/apk/73cc953b4f6dc09a1953e01e424534ff.jpg",
    ],
    imgUrlList: [
        "http://a.vigame.cn/mmlxx/25d5eb2f1d3c5cfad4bf4d1f72d5c5c0.jpg",
        "http://a.vigame.cn/mmlxx/25d5eb2f1d3c5cfad4bf4d1f72d5c5c0.jpg",
        "http://a.vigame.cn/mmlxx/25d5eb2f1d3c5cfad4bf4d1f72d5c5c0.jpg",
        "http://a.vigame.cn/mmlxx/25d5eb2f1d3c5cfad4bf4d1f72d5c5c0.jpg",
        "http://a.vigame.cn/mmlxx/25d5eb2f1d3c5cfad4bf4d1f72d5c5c0.jpg",
        "http://a.vigame.cn/mmlxx/25d5eb2f1d3c5cfad4bf4d1f72d5c5c0.jpg"
    ],
    linkUrlList: [
        "http://a.vigame.cn/apk/test1.apk",
        "http://a.vigame.cn/apk/test2.apk",
        "http://a.vigame.cn/apk/test3.apk",
        "http://a.vigame.cn/apk/test1.apk",
        "http://a.vigame.cn/apk/test2.apk",
        "http://a.vigame.cn/apk/test3.apk"
    ],
    openUrlList: [
        "",
        "",
        "",
        "",
        "",
        ""
    ],
    paramList: [
        "",
        "",
        "",
        "",
        "",
        ""
    ]
};

wb.res = {

    scsz_png: "studio/atlasNum/scsz.png",
    zssz_png: "studio/atlasNum/zssz.png",

    cjlb_png: "studio/cjlb/cjlb.png",
    czlb_png: "studio/czlb/czlb.png",
    shop_png: "studio/shop/shop.png",
    xslb_png: "studio/xslb/xslb.png",
    thlb_png: "studio/thlb/thlb.png",

    cjlb_plist: "studio/cjlb/cjlb.plist",
    czlb_plist: "studio/czlb/czlb.plist",
    shop_plist: "studio/shop/shop.plist",
    xslb_plist: "studio/xslb/xslb.plist",
    thlb_plist: "studio/thlb/thlb.plist",

    shopLayer_json: "studio/ShopLayer.json",
    czlbLayer_json: "studio/CzlbLayer.json",
    xslbLayer_json: "studio/XslbLayer.json",
    noAdLayer_json: "studio/NoADLayer.json",
    thlbLayer_json: "studio/ThlbLayer.json",

    djgx_png: "spine/djgx.png",
    djgx_atlas: "spine/djgx.atlas",
    djgx_json: "spine/djgx.json",
    diamond_icon_png: "spine/diamond_icon.png",
    num_dj_zs_fs_sj_png: "spine/num_dj_zs_fs_sj.png",

    gift_cfg_csv: "config/GiftConfig.csv",
    task_cfg_csv: "config/Tasks.csv",
    push_cfg_csv: "config/PushConfig.csv",
    share_cfg_csv: "config/ShareConfig.csv",
    online_cfg_csv: "config/OnlineConfig.csv",

    gift_buy_png: "gift/buy.png",
    gift_close_png: "gift/close.png",
    gift_get_png: "gift/get.png",
    gift_gou_png: "gift/gou.png",
    gift_ok_png: "gift/ok.png",
    gift_qb_png: "gift/qb.png"

}

wb.frameworkResPath = "frameworks/cocos2d-html5/wbjs/vigame/res/";
if (wb.isNative()) wb.frameworkResPath = "script/wbjs/vigame/res/";
else if (wb.isWeb) wb.frameworkResPath = "res/";
wb.g_resources = [];

for (var i in wb.res) {
    wb.res[i] = wb.frameworkResPath + wb.res[i];
    wb.g_resources.push(wb.res[i]);
}

//// 商店
//wb.shopData = {
//    items: [
//        {
//            id: 1,
//            price: "￥28.00",
//            diamond: 350
//        },
//        {
//            id: 2,
//            price: "￥12.00",
//            diamond: 150
//        },
//        {
//            id: 3,
//            price: "￥6.00",
//            diamond: 60
//        }
//    ],
//    diamondEndP: {x: 34, y: 1084},   // 钻石飞向的坐标
//    jsonPath: wb.res.shopLayer_json  // 界面的路径
//};
//
//// 超值礼包
//wb.czlbData = {
//    id: 4,                       // 支付id
//    diamond: 400,                // 获得的钻石数量
//    price: 28,                   // 价格
//    diamondStr: "/400",          // 钻石描述
//    priceStr: "￥28.00",         // 价格描述
//    txt_zs: "txt_zs",            // 钻石label
//    txt_price: "txt_price",      // 价格label
//    btn_buy: "btn_buy",          // 购买按钮
//    btn_close: "btn_close",      // 关闭按钮
//    diamondEndP: {x: 34, y: 1084},  // 钻石飞向的坐标
//    jsonPath: wb.res.czlbLayer_json // 界面的路径
//};
//
//// 限时礼包
//wb.xslbData = {
//    id: 5,                      // 支付id
//    diamond: 35,                // 获得的钻石数量
//    price: 6,                   // 价格
//    diamondStr: "/35",          // 钻石描述
//    priceStr: "￥6.00",         // 价格描述
//    txt_zs: "txt_zs",            // 钻石label
//    txt_price: "txt_price",      // 价格label
//    btn_buy: "btn_buy",          // 购买按钮
//    btn_close: "btn_close",      // 关闭按钮
//    diamondEndP: {x: 34, y: 1084},  // 钻石飞向的坐标
//    jsonPath: wb.res.xslbLayer_json // 界面的路径
//};
//
//// 去广告礼包
//wb.noAdData = {
//    id: -200,                   // 支付id
//    diamond: 100,               // 获得的钻石数量
//    price: 6,                   // 价格
//    diamondStr: "100钻石",      // 钻石描述
//    priceStr: "￥6.00",         // 价格描述
//    txt_zs: "txt_zs",            // 钻石label
//    txt_price: "txt_price",      // 价格label
//    btn_buy: "btn_buy",          // 购买按钮
//    btn_close: "btn_close",      // 关闭按钮
//    diamondEndP: {x: 34, y: 1084},  // 钻石飞向的坐标
//    jsonPath: wb.res.noAdLayer_json // 界面的路径
//};
//
//// 特惠礼包
//wb.thlbData = {
//    id: -1,                   // 支付id
//    diamond: 20,               // 获得的钻石数量
//    price: 6,                   // 价格
//    diamondStr: "20",      // 钻石描述
//    priceStr: "￥6.00",         // 价格描述
//    txt_zs: "numText",            // 钻石label
//    txt_price: "txt_price",      // 价格label
//    btn_buy: "btn_buy",          // 购买按钮
//    btn_close: "btn_close",      // 关闭按钮
//    diamondEndP: {x: 34, y: 1084}, // 钻石飞向的坐标
//    jsonPath: wb.res.thlbLayer_json // 界面的路径
//};

