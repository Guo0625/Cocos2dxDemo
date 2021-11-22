#include "CorePc.h"
#include "cocos2d.h"

VIGAME_BEGIN

CorePc::CorePc()
{
}

CorePc::~CorePc()
{
}

void CorePc::init()
{
}


void CorePc::UseCDKey(std::string dhm) {}
bool CorePc::CDKeyIsSupport() { return false; }
void CorePc::OpenActivityPage() {}
void CorePc::OpenActivityNotice() {}
void CorePc::OpenRank() {}
void CorePc::OpenUserAgreement() {}
void CorePc::OpenPrivacyPolicy() {}
void CorePc::OpenUserAgreementByWeb() {}
void CorePc::OpenUserAgreementNoCompany() {}
void CorePc::OpenFeedback() {}
void CorePc::OpenMarketPlus(std::string url, std::string param) {}
void CorePc::SumbitRankData(std::string userId, int level, int score, int usedCoins, int leftCoins) {}
void CorePc::SetGameName(std::string gameName) {}

std::string CorePc::GetAppName() { return ""; }
std::string CorePc::GetChannel() { return ""; }
std::string CorePc::GetPrjid() { return ""; }
std::string CorePc::GetAppid() { return ""; }
std::string CorePc::GetLsn() { return ""; }
std::string CorePc::GetUuid() { return ""; }
std::string CorePc::GetImsi() { return ""; }
std::string CorePc::GetImei() { return ""; }
std::string CorePc::GetOaid() { return ""; }
std::string CorePc::GetAndroidId() { return ""; }
std::string CorePc::GetAppkey() { return ""; }
int CorePc::GetNetState() { return 0; }

std::string CorePc::GetSignature() { return ""; }

std::string CorePc::GetPackageName() { return ""; }

std::string CorePc::GetVerName() { return ""; }
//返回值：true-非审核状态 false-审核中
bool CorePc::GetAuditSwitch() { return false; }

std::string CorePc::GetCustomSwitch(std::string key) { return ""; }
bool CorePc::GetIsHarmonyOs() { return false; }
void CorePc::OpenUrl(std::string url) {}
void CorePc::OpenInnerUrl(std::string url) {}
void CorePc::OpenDialogWeb(std::string url, std::string title) {}
void CorePc::OpenActivityWeb(std::string url, std::string title) {}
// void CorePc::NotifyNotification(int id, std::string body, long fireDate, int unitInterval, Dictionary<std::string, std::string> userinfo) {}
// void CorePc::CancleNotification(int id) {}
// void CorePc::CancleNotificationAll() {}
// bool CorePc::Fastmark() { return false; }
// void CorePc::JumpComment() {}
void CorePc::CloseAccount() {}
void CorePc::InitGameConfig(int version) {}
std::string CorePc::GetConfigValue(std::string key) { return ""; }
// // 移动积分兑换 获取积分数据
// void CorePc::GetIntegralData() {}
// // 移动积分兑换 上报接口
// void CorePc::ReportIntegral(std::string json) {}
// // 移动积分兑换 打开h5界面
// void CorePc::OpenIntegralActivity() {}
// 更新敏感词配置
void CorePc::WordFilterUpdate() {}
// 处理敏感词
std::string CorePc::WordFilter(std::string sentence) { return ""; }
// 设置当前scene的名称
void CorePc::SetSceneName(std::string name) {}
// 积分模块是否打开s
bool CorePc::IsRedeemEnable() { return false; }
// // 积分v2获取订单列表
// void CorePc::GetOrderData(std::string outOrderId) {}
// // 积分v2获取商品列表
// void CorePc::GetProductData() {}
// // 积分v2获取未发货订单列表
// void CorePc::GetLostOrderData() {}
// // 积分v2更新订单列表状态
// void CorePc::UpdateOrderState(std::string orderList) {}
// // 积分v2打开h5页
// void CorePc::OpenNewIntegralActivity(std::string actJson) {}
// // 问卷调查 打开h5页
// void CorePc::OpenQuestionH5(std::string winId) {}
// // 问卷调查 请求弹窗配置
// void CorePc::GetQuestionWinConfig() {}
// // 问卷调查 获取资源更新状态
// int CorePc::GetQuestionResState() { return 0; }
// // 问卷调查 获取问卷调查资源
// void CorePc::GetVerForNet() {}
// // 产品-问卷调查 打开h5页
// void CorePc::OpenSurveyH5(std::string winId) {}
// // 产品-问卷调查 请求弹窗配置
// void CorePc::GetSurveyWinConfig() {}
// // 产品-问卷调查 获取资源更新状态
// int CorePc::GetSurveyResState() { return 0; }
// // 产品-问卷调查 获取问卷调查资源
// void CorePc::GetSurveyVerForNet() {}
// 获取投放渠道
std::string CorePc::GetBuyChannel() { return ""; }
// 获取投放账户
std::string CorePc::GetBuyUserId() { return ""; }
// // 积分v3获取订单列表
// void CorePc::GetOrderDataV3(std::string outOrderId) {}
// // 积分v3获取商品列表
// void CorePc::GetProductDataV3() {}
// // 积分v3获取未发货订单列表
// void CorePc::GetLostOrderDataV3() {}
// // 积分v3更新订单列表状态
// void CorePc::UpdateOrderStateV3(std::string orderList) {}
// // 积分v3打开h5页
// void CorePc::OpenNewIntegralActivityV3(std::string actJson) {}

// 获取Assets下文件内容
std::string CorePc::GetAssetsFileData(std::string fileName) { return ""; }

/// <summary>
/// 获取apk更新弹窗信息
/// </summary>
/// <returns></returns>
std::string CorePc::GetUpdateInfo() { return ""; }

/// <summary>
/// 根据key获取ConfigVigame.xml中的值
/// </summary>
/// <param name="key">关键字</param>
/// <returns></returns>
std::string CorePc::GetConfigVigameValue(std::string key) { return ""; }

// /// <summary>
// /// 设置unity当前节点信息
// /// </summary>
// /// <param name="nodeInfo"></param>
// void CorePc::SetNodeInfo(std::string nodeInfo) {}

// /// <summary>
// /// 获取签名验证MD5
// /// </summary>
// /// <returns></returns>
// std::string CorePc::GetSignMd5() { return ""; }

/// <summary>
/// 获取opengl版本
/// </summary>
/// <returns></returns>
std::string CorePc::GetOpenGLVersion() { return ""; }

/// <summary>
/// 打开deepLink
/// </summary>
/// <param name="openUrl">deepLink链接</param>
/// <returns>0失败；1成功</returns>
int CorePc::OpenDeepLink(std::string openUrl) { return 0; }

/// <summary>
/// 打开支付宝DeepLink链接
/// </summary>
/// <returns>0失败；1成功</returns>
int CorePc::OpenZfbDp() { return 0; }

/// <summary>
/// 获取动能id
/// </summary>
/// <returns>动能id</returns>
std::string CorePc::GetDnid() { return ""; }

unsigned long CorePc::GetElapsedRealtime() { return 0; }

VIGAME_END