/**
 * Created by Zack on 2018/1/9.
 */
var wb = window.wb || {};

wb.Core = wb.SysCore.extend(wb.JCore, {});
wb.SysConfig = wb.SysCore.extend(wb.JSysConfig, {});

wb.SysConfig.getAppid = function () {
    if (wb.SysPlatform.isNative()) return this.parent.getAppid();
    return "10000";
};

wb.SysConfig.getPrjid = function () {
    if (wb.SysPlatform.isNative()) return this.parent.getPrjid();
    return "112233";
};

wb.SysConfig.getLsn = function () {
    if (wb.SysPlatform.isNative()) return this.parent.getLsn();
    return "152252525";
};

wb.SysConfig.getChannel = function () {
    if (wb.SysPlatform.isNative()) return this.parent.getChannel();
    return "wb";
};

wb.SysConfig.getImei = function () {
    if (wb.SysPlatform.isNative()) return this.parent.getImei();
    return "111111111";
};

wb.SysConfig.getImsi = function () {
    if (wb.SysPlatform.isNative()) return this.parent.getImsi();
    return "222222222";
};

wb.CoreManager = wb.SysCore.extend(wb.JCoreManager, {});
wb.CoreManager = wb.SysCore.extend(wb.JCoreManager, {});

wb.Browser = wb.SysCore.extend(wb.JBrowser, {});
wb.Browser.openInnerWeb = function (str) {
    if (wb.SysPlatform.isNative()) return this.parent.openInnerWeb(str);
    window.open(str);
};

wb.DhmData = wb.SysCore.extend(wb.JDhmData, {});
wb.ExchangeData = wb.SysCore.extend(wb.JExchangeData, {});
wb.CDKEY = wb.SysCore.extend(wb.JCDKEY, {});
wb.Exchange = wb.SysCore.extend(wb.JExchange, {});
wb.Community = wb.SysCore.extend(wb.JCommunity, {});
wb.FileUtils = wb.SysCore.extend(wb.JFileUtils, {});
wb.ZPFileUtils = wb.SysCore.extend(wb.JZPFileUtils, {});
wb.FileUtils = wb.SysCore.extend(wb.JFileUtils, {});
wb.response = wb.SysCore.extend(wb.Jresponse, {});
wb.HttpFetch = wb.SysCore.extend(wb.JHttpFetch, {});
wb.MMChnl = wb.SysCore.extend(wb.JMMChnl, {});
wb.MMChnlLocal = wb.SysCore.extend(wb.JMMChnlLocal, {});
wb.MMChnlNet = wb.SysCore.extend(wb.JMMChnlNet, {});
wb.MMChnlManager = wb.SysCore.extend(wb.JMMChnlManager, {});
wb.Notice = wb.SysCore.extend(wb.JNotice, {});
wb.MMChnlLocal = wb.SysCore.extend(wb.JMMChnlLocal, {});
wb.Notification = wb.SysCore.extend(wb.JNotification, {});
wb.Rank = wb.SysCore.extend(wb.JRank, {});
wb.Signature = wb.SysCore.extend(wb.JSignature, {});
wb.UserAgreement = wb.SysCore.extend(wb.JUserAgreement, {});
wb.XYXConfig = wb.SysCore.extend(wb.JXYXConfig, {});

wb.XYXManager = wb.SysCore.extend(wb.JXYXManager, {});
wb.XYXManager.getConfig = function () {
    if (wb.SysPlatform.isNative()) return this.parent.getConfig();
    var config = {};
    config.getOpenList = function () {
        return wb.vigameNs.XYXConfigTest.openUrlList;
    };
    config.getImageList = function () {
        return wb.vigameNs.XYXConfigTest.imgUrlList;
    };
    config.getLinkUrlList = function () {
        return wb.vigameNs.XYXConfigTest.linkUrlList;
    };
    config.getIconList = function () {
        return wb.vigameNs.XYXConfigTest.iconUrlList;
    };
    config.getParamList = function () {
        return wb.vigameNs.XYXConfigTest.paramList;
    };
    config.getAdShowUrl = function () {
        return "";
    };
    config.getAdClickUrl = function () {
        return "";
    };
    return config;
};

wb.XYXManager.getListLength = function () {
    if (wb.SysPlatform.isNative()) return this.parent.getConfig().getIconList().length;
    return wb.vigameNs.XYXConfigTest.iconUrlList.length;
};

wb.Cash = wb.extend(wb.JCash, {});
wb.GameParam = wb.extend(wb.JGameParam, {});
wb.NetCash = wb.extend(wb.JNetCash, {});
wb.HbGroup = wb.extend(wb.JHbGroup, {});
wb.Invite = wb.extend(wb.JInvite, {});