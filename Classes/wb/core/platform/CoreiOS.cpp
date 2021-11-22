#include "CoreiOS.h"
#include "cocos2d.h"

VIGAME_BEGIN

CoreiOS::CoreiOS()
{
    
}

CoreiOS::~CoreiOS()
{
}

void CoreiOS::init()
{
}

void CoreiOS::UseCDKey(std::string dhm) {}
bool CoreiOS::CDKeyIsSupport() { return false; }
void CoreiOS::OpenActivityPage() {}
void CoreiOS::OpenActivityNotice() {}
void CoreiOS::OpenRank() {}
void CoreiOS::OpenUserAgreement() {}
void CoreiOS::OpenPrivacyPolicy() {}
void CoreiOS::OpenUserAgreementByWeb() {}
void CoreiOS::OpenUserAgreementNoCompany() {}
void CoreiOS::OpenFeedback() {}
void CoreiOS::OpenMarketPlus(std::string url, std::string param) {}
void CoreiOS::SumbitRankData(std::string userId, int level, int score, int usedCoins, int leftCoins) {}
void CoreiOS::SetGameName(std::string gameName) {}

std::string CoreiOS::GetAppName() { return ""; }
std::string CoreiOS::GetChannel() { return ""; }
std::string CoreiOS::GetPrjid() { return ""; }
std::string CoreiOS::GetAppid() { return ""; }
std::string CoreiOS::GetLsn() { return ""; }
std::string CoreiOS::GetUuid() { return ""; }
std::string CoreiOS::GetImsi() { return ""; }
std::string CoreiOS::GetImei() { return ""; }
std::string CoreiOS::GetOaid() { return ""; }
std::string CoreiOS::GetAndroidId() { return ""; }
std::string CoreiOS::GetAppkey() { return ""; }
int CoreiOS::GetNetState() { return 0; }

std::string CoreiOS::GetSignature() { return ""; }

std::string CoreiOS::GetPackageName() { return ""; }

std::string CoreiOS::GetVerName() { return ""; }
//返回值：true-非审核状态 false-审核中
bool CoreiOS::GetAuditSwitch() { return false; }

std::string CoreiOS::GetCustomSwitch(std::string key) { return ""; }
bool CoreiOS::GetIsHarmonyOs() { return false; }
void CoreiOS::OpenUrl(std::string url) {}
void CoreiOS::OpenInnerUrl(std::string url) {}
void CoreiOS::OpenDialogWeb(std::string url, std::string title) {}
void CoreiOS::OpenActivityWeb(std::string url, std::string title) {}
// void CoreiOS::NotifyNotification(int id, std::string body, long fireDate, int unitInterval, Dictionary<std::string, std::string> userinfo) {}
// void CoreiOS::CancleNotification(int id) {}
// void CoreiOS::CancleNotificationAll() {}
// bool CoreiOS::Fastmark() { return false; }
// void CoreiOS::JumpComment() {}
void CoreiOS::CloseAccount() {}
void CoreiOS::InitGameConfig(int version) {}
std::string CoreiOS::GetConfigValue(std::string key) { return ""; }
// // 移动积分兑换 获取积分数据
// void CoreiOS::GetIntegralData() {}
// // 移动积分兑换 上报接口
// void CoreiOS::ReportIntegral(std::string json) {}
// // 移动积分兑换 打开h5界面
// void CoreiOS::OpenIntegralActivity() {}
// 更新敏感词配置
void CoreiOS::WordFilterUpdate() {}
// 处理敏感词
std::string CoreiOS::WordFilter(std::string sentence) { return ""; }
// 设置当前scene的名称
void CoreiOS::SetSceneName(std::string name) {}
// 积分模块是否打开s
bool CoreiOS::IsRedeemEnable() { return false; }
// // 积分v2获取订单列表
// void CoreiOS::GetOrderData(std::string outOrderId) {}
// // 积分v2获取商品列表
// void CoreiOS::GetProductData() {}
// // 积分v2获取未发货订单列表
// void CoreiOS::GetLostOrderData() {}
// // 积分v2更新订单列表状态
// void CoreiOS::UpdateOrderState(std::string orderList) {}
// // 积分v2打开h5页
// void CoreiOS::OpenNewIntegralActivity(std::string actJson) {}
// // 问卷调查 打开h5页
// void CoreiOS::OpenQuestionH5(std::string winId) {}
// // 问卷调查 请求弹窗配置
// void CoreiOS::GetQuestionWinConfig() {}
// // 问卷调查 获取资源更新状态
// int CoreiOS::GetQuestionResState() { return 0; }
// // 问卷调查 获取问卷调查资源
// void CoreiOS::GetVerForNet() {}
// // 产品-问卷调查 打开h5页
// void CoreiOS::OpenSurveyH5(std::string winId) {}
// // 产品-问卷调查 请求弹窗配置
// void CoreiOS::GetSurveyWinConfig() {}
// // 产品-问卷调查 获取资源更新状态
// int CoreiOS::GetSurveyResState() { return 0; }
// // 产品-问卷调查 获取问卷调查资源
// void CoreiOS::GetSurveyVerForNet() {}
// 获取投放渠道
std::string CoreiOS::GetBuyChannel() { return ""; }
// 获取投放账户
std::string CoreiOS::GetBuyUserId() { return ""; }
// // 积分v3获取订单列表
// void CoreiOS::GetOrderDataV3(std::string outOrderId) {}
// // 积分v3获取商品列表
// void CoreiOS::GetProductDataV3() {}
// // 积分v3获取未发货订单列表
// void CoreiOS::GetLostOrderDataV3() {}
// // 积分v3更新订单列表状态
// void CoreiOS::UpdateOrderStateV3(std::string orderList) {}
// // 积分v3打开h5页
// void CoreiOS::OpenNewIntegralActivityV3(std::string actJson) {}

// 获取Assets下文件内容
std::string CoreiOS::GetAssetsFileData(std::string fileName) { return ""; }

/// <summary>
/// 获取apk更新弹窗信息
/// </summary>
/// <returns></returns>
std::string CoreiOS::GetUpdateInfo() { return ""; }

/// <summary>
/// 根据key获取ConfigVigame.xml中的值
/// </summary>
/// <param name="key">关键字</param>
/// <returns></returns>
std::string CoreiOS::GetConfigVigameValue(std::string key) { return ""; }

// /// <summary>
// /// 设置unity当前节点信息
// /// </summary>
// /// <param name="nodeInfo"></param>
// void CoreiOS::SetNodeInfo(std::string nodeInfo) {}

// /// <summary>
// /// 获取签名验证MD5
// /// </summary>
// /// <returns></returns>
// std::string CoreiOS::GetSignMd5() { return ""; }

/// <summary>
/// 获取opengl版本
/// </summary>
/// <returns></returns>
std::string CoreiOS::GetOpenGLVersion() { return ""; }

/// <summary>
/// 打开deepLink
/// </summary>
/// <param name="openUrl">deepLink链接</param>
/// <returns>0失败；1成功</returns>
int CoreiOS::OpenDeepLink(std::string openUrl) { return 0; }

/// <summary>
/// 打开支付宝DeepLink链接
/// </summary>
/// <returns>0失败；1成功</returns>
int CoreiOS::OpenZfbDp() { return 0; }

/// <summary>
/// 获取动能id
/// </summary>
/// <returns>动能id</returns>
std::string CoreiOS::GetDnid() { return ""; }

unsigned long CoreiOS::GetElapsedRealtime() { return 0; }

VIGAME_END