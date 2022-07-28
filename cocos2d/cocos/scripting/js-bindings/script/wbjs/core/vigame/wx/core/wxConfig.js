/**
 * Created by zack on 2018/4/20.
 */

var wb = window.wb || {};
wb.wx = wb.wx || {};

wb.wxConfig = {};

// 推送
wb.wxConfig.wxPushUrl = "https://api.vzhifu.net/wxIconPush";
// 分享图
wb.wxConfig.wxShareUrl = "https://api.vzhifu.net/wxSharePush";
// 登陆
wb.wxConfig.wxLoginUrl = "https://api.vzhifu.net/wxCodeToken";
// 统计
wb.wxConfig.wxTjUrl = "https://tj.vzhifu.net/";
// unionid
wb.wxConfig.wxUnionidUrl = 'https://api.vzhifu.net/wxDeCrypt';

wb.wxConfig.pid = "";
wb.wxConfig.prjid = "";
wb.wxConfig.wbAppID = "";

wb.wxConfig.videoADid = "";   // 视频广告id
wb.wxConfig.bannerADid = "";  // banner广告id
wb.wxConfig.bannerADW = 300;  // banner广告宽

wb.wxRes = {
    wxPushBg: "res/wxRes/pushBg.png",     // 推送的底图
    pushFrame: "res/wxRes/pushFrame.png",  // 推送的框
    pushPlbg: "res/wxRes/pushPlbg.png",
    pushX: "res/wxRes/pushX.png"
};
