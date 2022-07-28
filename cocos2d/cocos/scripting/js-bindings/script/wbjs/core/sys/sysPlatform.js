/**
 * Created by Zack on 2018/11/14.
 */

var wb = window.wb || {};
wb.SysPlatform = wb.SysPlatform || {};

wb.SysPlatform.LANGUAGE_ENGLISH = "en";
wb.SysPlatform.LANGUAGE_CHINESE = "zh";
wb.SysPlatform.LANGUAGE_FRENCH = "fr";
wb.SysPlatform.LANGUAGE_ITALIAN = "it";
wb.SysPlatform.LANGUAGE_GERMAN = "de";
wb.SysPlatform.LANGUAGE_SPANISH = "es";
wb.SysPlatform.LANGUAGE_DUTCH = "du";
wb.SysPlatform.LANGUAGE_RUSSIAN = "ru";
wb.SysPlatform.LANGUAGE_KOREAN = "ko";
wb.SysPlatform.LANGUAGE_JAPANESE = "ja";
wb.SysPlatform.LANGUAGE_HUNGARIAN = "hu";
wb.SysPlatform.LANGUAGE_PORTUGUESE = "pt";
wb.SysPlatform.LANGUAGE_ARABIC = "ar";
wb.SysPlatform.LANGUAGE_NORWEGIAN = "no";
wb.SysPlatform.LANGUAGE_POLISH = "pl";
wb.SysPlatform.LANGUAGE_UNKNOWN = "unkonwn";
wb.SysPlatform.OS_IOS = "iOS";
wb.SysPlatform.OS_ANDROID = "Android";
wb.SysPlatform.OS_WINDOWS = "Windows";
wb.SysPlatform.OS_MARMALADE = "Marmalade";
wb.SysPlatform.OS_LINUX = "Linux";
wb.SysPlatform.OS_BADA = "Bada";
wb.SysPlatform.OS_BLACKBERRY = "Blackberry";
wb.SysPlatform.OS_OSX = "OS X";
wb.SysPlatform.OS_WP8 = "WP8";
wb.SysPlatform.OS_WINRT = "WINRT";
wb.SysPlatform.OS_UNKNOWN = "Unknown";
wb.SysPlatform.UNKNOWN = -1;
wb.SysPlatform.WIN32 = 0;
wb.SysPlatform.LINUX = 1;
wb.SysPlatform.MACOS = 2;
wb.SysPlatform.ANDROID = 3;
wb.SysPlatform.IPHONE = 4;
wb.SysPlatform.IPAD = 5;
wb.SysPlatform.BLACKBERRY = 6;
wb.SysPlatform.NACL = 7;
wb.SysPlatform.EMSCRIPTEN = 8;
wb.SysPlatform.TIZEN = 9;
wb.SysPlatform.WINRT = 10;
wb.SysPlatform.WP8 = 11;
wb.SysPlatform.MOBILE_BROWSER = 100;
wb.SysPlatform.DESKTOP_BROWSER = 101;
wb.SysPlatform.BROWSER_TYPE_WECHAT = "wechat";
wb.SysPlatform.BROWSER_TYPE_ANDROID = "androidbrowser";
wb.SysPlatform.BROWSER_TYPE_IE = "ie";
wb.SysPlatform.BROWSER_TYPE_QQ_APP = "qq"; // QQ App
wb.SysPlatform.BROWSER_TYPE_QQ = "qqbrowser";
wb.SysPlatform.BROWSER_TYPE_MOBILE_QQ = "mqqbrowser";
wb.SysPlatform.BROWSER_TYPE_UC = "ucbrowser";
wb.SysPlatform.BROWSER_TYPE_360 = "360browser";
wb.SysPlatform.BROWSER_TYPE_BAIDU_APP = "baiduboxapp";
wb.SysPlatform.BROWSER_TYPE_BAIDU = "baidubrowser";
wb.SysPlatform.BROWSER_TYPE_MAXTHON = "maxthon";
wb.SysPlatform.BROWSER_TYPE_OPERA = "opera";
wb.SysPlatform.BROWSER_TYPE_OUPENG = "oupeng";
wb.SysPlatform.BROWSER_TYPE_MIUI = "miuibrowser";
wb.SysPlatform.BROWSER_TYPE_FIREFOX = "firefox";
wb.SysPlatform.BROWSER_TYPE_SAFARI = "safari";
wb.SysPlatform.BROWSER_TYPE_CHROME = "chrome";
wb.SysPlatform.BROWSER_TYPE_LIEBAO = "liebao";
wb.SysPlatform.BROWSER_TYPE_QZONE = "qzone";
wb.SysPlatform.BROWSER_TYPE_SOUGOU = "sogou";
wb.SysPlatform.BROWSER_TYPE_UNKNOWN = "unknown";

wb.SysPlatform.RENDER_TYPE_CANVAS = 1;
wb.SysPlatform.RENDER_TYPE_WEBGL = 1;
wb.SysPlatform.RENDER_TYPE_OPENGL = 2;

wb.SysPlatform.init = function () {
    if (wb.SysPlatform.isNative()) return;

    var win = window, nav = win.navigator, doc = document, docEle = doc.documentElement;
    var sysPlatform = wb.SysPlatform;
    var ua = nav.userAgent.toLowerCase();

    var currLanguage = nav.language;
    currLanguage = currLanguage ? currLanguage : nav.browserLanguage;
    currLanguage = currLanguage ? currLanguage.split("-")[0] : sysPlatform.LANGUAGE_ENGLISH;

    // Get the os of system
    var isAndroid = false, iOS = false, osVersion = '', osMainVersion = 0;
    var uaResult = /android (\d+(?:\.\d+)+)/i.exec(ua) || /android (\d+(?:\.\d+)+)/i.exec(nav.platform);
    if (uaResult) {
        isAndroid = true;
        osVersion = uaResult[1] || '';
        osMainVersion = parseInt(osVersion) || 0;
    }
    uaResult = /(iPad|iPhone|iPod).*OS ((\d+_?){2,3})/i.exec(ua);
    if (uaResult) {
        iOS = true;
        osVersion = uaResult[2] || '';
        osMainVersion = parseInt(osVersion) || 0;
    }
    else if (/(iPhone|iPad|iPod)/.exec(nav.platform)) {
        iOS = true;
        osVersion = '';
        osMainVersion = 0;
    }

    var osName = sysPlatform.OS_UNKNOWN;
    if (nav.appVersion.indexOf("Win") !== -1) osName = sysPlatform.OS_WINDOWS;
    else if (iOS) osName = sysPlatform.OS_IOS;
    else if (nav.appVersion.indexOf("Mac") !== -1) osName = sysPlatform.OS_OSX;
    else if (nav.appVersion.indexOf("X11") !== -1 && nav.appVersion.indexOf("Linux") === -1) osName = sysPlatform.OS_UNIX;
    else if (isAndroid) osName = sysPlatform.OS_ANDROID;
    else if (nav.appVersion.indexOf("Linux") !== -1) osName = sysPlatform.OS_LINUX;


    /* Determine the browser type */
    var typeReg1 = /micromessenger|mqqbrowser|sogou|qzone|liebao|ucbrowser|360 aphone|360browser|baiduboxapp|baidubrowser|maxthon|mxbrowser|trident|miuibrowser/i;
    var typeReg2 = /qqbrowser|qq|chrome|safari|firefox|opr|oupeng|opera/i;
    var browserTypes = typeReg1.exec(ua);
    if (!browserTypes) browserTypes = typeReg2.exec(ua);
    var browserType = browserTypes ? browserTypes[0] : sysPlatform.BROWSER_TYPE_UNKNOWN;
    if (browserType === 'micromessenger')
        browserType = sysPlatform.BROWSER_TYPE_WECHAT;
    else if (browserType === "safari" && isAndroid)
        browserType = sysPlatform.BROWSER_TYPE_ANDROID;
    else if (browserType === "trident")
        browserType = sysPlatform.BROWSER_TYPE_IE;
    else if (browserType === "360 aphone")
        browserType = sysPlatform.BROWSER_TYPE_360;
    else if (browserType === "mxbrowser")
        browserType = sysPlatform.BROWSER_TYPE_MAXTHON;
    else if (browserType === "opr")
        browserType = sysPlatform.BROWSER_TYPE_OPERA;

    /* Determine the browser version number */
    var versionReg1 = /(mqqbrowser|micromessenger|sogou|qzone|liebao|maxthon|mxbrowser|baidu)(mobile)?(browser)?\/?([\d.]+)/i;
    var versionReg2 = /(msie |rv:|firefox|chrome|ucbrowser|qq|oupeng|opera|opr|safari|miui)(mobile)?(browser)?\/?([\d.]+)/i;
    var tmp = ua.match(versionReg1);
    if (!tmp) tmp = ua.match(versionReg2);

    var w = window.innerWidth || document.documentElement.clientWidth;
    var h = window.innerHeight || document.documentElement.clientHeight;
    var ratio = window.devicePixelRatio || 1;

    sysPlatform.windowPixelResolution = {
        width: ratio * w,
        height: ratio * h
    };

    // recommended use interface ,is error in native platform
    sysPlatform.nativeFlag = false;
    sysPlatform.mobileFlag = window.wx ? true : /mobile|android|iphone|ipad/.test(ua);
    sysPlatform.platform = sysPlatform.mobileFlag ? sysPlatform.MOBILE_BROWSER : sysPlatform.DESKTOP_BROWSER;
    sysPlatform.language = currLanguage;
    sysPlatform.os = osName;
    sysPlatform.osVersion = osVersion;
    sysPlatform.osMainVersion = osMainVersion;
    sysPlatform.browserType = browserType;
    sysPlatform.browserVersion = tmp ? tmp[4] : "";
    sysPlatform.renderType = sysPlatform.RENDER_TYPE_WEBGL;
    sysPlatform.CONCURRENCY_HTTP_REQUEST_COUNT = sysPlatform.mobileFlag ? 20 : 0;

    var spf = sysPlatform;
    var logStr = "is mobile:" + spf.mobileFlag + " platform: " + spf.platform + " language:" + spf.language +
        " os:" + spf.os + " osVersion:" + spf.osVersion + " osMainVersion:" + spf.osMainVersion +
        " browserType:" + spf.browserType + " browserVersion:" + spf.browserVersion;
    spf.log(logStr);
};

wb.SysPlatform.log = function (str) {
    console.log(str);
};
wb.log = wb.SysPlatform.log;

wb.SysPlatform.os = function () {
    return wb.SysPlatform.os;
};

wb.SysPlatform.isMobileBrowser = function () {
    return wb.SysPlatform.platform == wb.SysPlatform.MOBILE_BROWSER;
};

wb.SysPlatform.isDesktopBrowser = function () {
    return wb.SysPlatform.platform == wb.SysPlatform.DESKTOP_BROWSER;
};

wb.SysPlatform.isBrowser = function () {
    return wb.SysPlatform.isDesktopBrowser() || wb.SysPlatform.isMobileBrowser();
};

wb.SysPlatform.isNative = function () {
    if (wb.SysPlatform.isWX()) return false;
    return !window.document;
};

wb.SysPlatform.isMobile = function () {
    return wb.SysPlatform.mobileFlag;
};

wb.SysPlatform.isWX = function () {
    return window.wx ? true : false;
};

// maybe overwrite
wb.SysPlatform.getWinSize = function () {
    return wb.SysPlatform.windowPixelResolution;
};

// overwrite
wb.SysPlatform.getFrameSize = function () {
    return {
        width: 640,
        height: 1136
    };
};

wb.SysPlatform.init();
