/**
 * Created by Zack on 2018/11/15.
 */

var wb = window.wb || {};

wb.modulesMap = {
    wbcore: [
        "wbjs/core/sys/sysCore.js",
        "wbjs/core/sys/sysPlatform.js",
        "wbjs/core/sys/sysValue.js",
        "wbjs/core/data/data.js",
        "wbjs/core/data/plistHelper.js",
        "wbjs/core/data/xmlHelper.js",
        "wbjs/core/event/eventManger.js",
        "wbjs/core/tools/tools.js",
        "wbjs/core/audio/audio.js",
        "wbjs/core/net/http.js",
        "wbjs/core/vigame/interface/jsb_jsbAd_auto_api.js",
        "wbjs/core/vigame/interface/jsb_jsbCore_auto_api.js",
        "wbjs/core/vigame/interface/jsb_jsbFramework_auto_api.js",
        "wbjs/core/vigame/interface/jsb_jsbGameHelper_auto_api.js",
        "wbjs/core/vigame/interface/jsb_jsbPay_auto_api.js",
        "wbjs/core/vigame/interface/jsb_jsbPush_auto_api.js",
        "wbjs/core/vigame/interface/jsb_jsbShare_auto_api.js",
        "wbjs/core/vigame/interface/jsb_jsbTj_auto_api.js"
    ],
    wbjsb: [
        "wbcore",
        "wbjs/core/vigame/jsb/adConfig.js",
        "wbjs/core/vigame/jsb/vigameAd.js",
        "wbjs/core/vigame/jsb/vigameCore.js",
        "wbjs/core/vigame/jsb/vigameFramework.js",
        "wbjs/core/vigame/jsb/vigameGameHelper.js",
        "wbjs/core/vigame/jsb/vigamePay.js",
        "wbjs/core/vigame/jsb/vigamePush.js",
        "wbjs/core/vigame/jsb/vigameShare.js",
        "wbjs/core/vigame/jsb/vigameTj.js"
    ],
    wbwx: [
        "wbcore",
        "wbjs/core/vigame/wx/vigameApi/vigameAd.js",
        "wbjs/core/vigame/wx/vigameApi/vigameTj.js",
        "wbjs/core/vigame/wx/core/wxConfig.js",
        "wbjs/core/vigame/wx/core/wxData.js",
        "wbjs/core/vigame/wx/core/wxInterface.js",
        "wbjs/core/vigame/wx/core/wxSys.js",
        "wbjs/core/vigame/wx/core/wxTool.js"
    ],
    wbcc: [
        "wbcore",
        "wbjsb",
        "wbjs/cocos2djs/cc/core/gameTool.js",
        "wbjs/cocos2djs/cc/core/gameConfig.js",
        "wbjs/cocos2djs/cc/core/gameData.js",
        "wbjs/cocos2djs/cc/core/gameSys.js",
        "wbjs/cocos2djs/cc/core/gameEvent.js",
        "wbjs/cocos2djs/cc/core/gameInterface.js",
        "wbjs/cocos2djs/cc/ui/baseLayer.js",
        "wbjs/cocos2djs/cc/ui/appInfoLayer.js",
        "wbjs/cocos2djs/cc/ui/menuItemAD.js",
        "wbjs/cocos2djs/cc/ui/menuItemADLayer.js",
        "wbjs/cocos2djs/cc/ui/toast.js",
        "wbjs/cocos2djs/cc/ui/pushAdBtn.js",
        "wbjs/cocos2djs/cc/ui/pushAdBtBtn.js",
        "wbjs/cocos2djs/cc/ui/pushAdLayer.js"
    ],
    wbccwx: [
        "wbcore",
        "wbcc",
        "wbwx",
        "wbjs/cocos2djs/wx/core/core.js",
        "wbjs/cocos2djs/wx/overwrite/wxData.js",
        "wbjs/cocos2djs/wx/overwrite/wxTool.js",
        "wbjs/cocos2djs/wx/overwrite/audio.js",
        "wbjs/cocos2djs/wx/ui/pushAdBtn.js",
        "wbjs/cocos2djs/wx/ui/pushAdRaBtn.js",
        "wbjs/cocos2djs/wx/ui/pushAdBaBtn.js",
        "wbjs/cocos2djs/wx/ui/pushAdBtBtn.js",
        "wbjs/cocos2djs/wx/ui/pushAdPlBtn.js",
        "wbjs/cocos2djs/wx/ui/pushAdMoBtn.js",
        "wbjs/cocos2djs/wx/ui/pushAdLayer.js",
        "wbjs/cocos2djs/wx/ui/userInfoLayer.js"
    ],
    wbcc2333: [
        "wbcore",
        "wbjsb",
        "wbjs/cocos2djs/wb2333/plugin.js",
        "wbjs/cocos2djs/wb2333/ui/loaderScene.js"
    ]

};
