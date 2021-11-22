#include "cocos2d.h"
#include "CoreManager.h"
#include "../utils/Utils.h"
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#include "platform/CoreAndroid.h"
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
#include "platform/CoreiOS.h"
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
#include "platform/CorePc.h"
#endif

VIGAME_BEGIN

CoreManager *CoreManager::getInstance()
{
	static std::unique_ptr<CoreManager> s_instance;
	static std::once_flag s_instance_created;
	std::call_once(s_instance_created, [=]
				   { s_instance = std::make_unique<CoreManager>();});
	return s_instance.get();
}

CoreManager::CoreManager()
{
	this->cdKeyCallFun = nullptr;
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	mInterface = new vigame::CoreAndroid();
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	mInterface = new vigame::CoreiOS();
#else
	mInterface = new vigame::CorePc();
#endif
	mInterface->init();
}

CoreManager::~CoreManager()
{
}

void CoreManager::UseCDKey(std::string dhm, std::function<void(CDKeyState, std::string, std::string)> func) 
{
	this->cdKeyCallFun = func;
	mInterface->UseCDKey(dhm);
}

bool CoreManager::CDKeyIsSupport() 
{
	return mInterface->CDKeyIsSupport();
}

void CoreManager::OpenActivityPage() 
{
	mInterface->OpenActivityPage();
}

void CoreManager::OpenActivityNotice() 
{
	mInterface->OpenActivityNotice();
}

void CoreManager::OpenRank() 
{
	mInterface->OpenRank();
}

void CoreManager::OpenUserAgreement() 
{
	mInterface->OpenUserAgreement();
}

void CoreManager::OpenPrivacyPolicy() 
{
	mInterface->OpenPrivacyPolicy();
}

void CoreManager::OpenUserAgreementByWeb() 
{
	mInterface->OpenUserAgreementByWeb();
}

void CoreManager::OpenUserAgreementNoCompany() 
{
	mInterface->OpenUserAgreementNoCompany();
}

void CoreManager::OpenFeedback() 
{
	mInterface->OpenFeedback();
}

void CoreManager::OpenMarketPlus(std::string url, std::string param) 
{
	mInterface->OpenMarketPlus(url, param);
}

void CoreManager::SumbitRankData(std::string userId, int level, int score, int usedCoins, int leftCoins) 
{
	mInterface->SumbitRankData(userId, level, score, usedCoins, leftCoins);
}

void CoreManager::SetGameName(std::string gameName) 
{
	mInterface->SetGameName(gameName);
}


std::string CoreManager::GetAppName() 
{
	return mInterface->GetAppName();
}

std::string CoreManager::GetChannel() 
{
	return mInterface->GetChannel();
}

std::string CoreManager::GetPrjid() 
{
	return mInterface->GetPrjid();
}

std::string CoreManager::GetAppid() 
{
	return mInterface->GetAppid();
}

std::string CoreManager::GetLsn() 
{
	return mInterface->GetLsn();
}

std::string CoreManager::GetUuid() 
{
	return mInterface->GetUuid();
}

std::string CoreManager::GetImsi() 
{
	return mInterface->GetImsi();
}

std::string CoreManager::GetImei() 
{
	return mInterface->GetImei();
}

std::string CoreManager::GetOaid() 
{
	return mInterface->GetOaid();
}

std::string CoreManager::GetAndroidId() 
{
	return mInterface->GetAndroidId();
}

std::string CoreManager::GetAppkey() 
{
	return mInterface->GetAppkey();
}

int CoreManager::GetNetState() 
{
	return mInterface->GetNetState();
}


std::string CoreManager::GetSignature() 
{
	return mInterface->GetSignature();
}


std::string CoreManager::GetPackageName() 
{
	return mInterface->GetPackageName();
}


std::string CoreManager::GetVerName() 
{
	return mInterface->GetVerName();
}

//返回值：true-非审核状态 false-审核中
bool CoreManager::GetAuditSwitch() 
{
	return mInterface->GetAuditSwitch();
}


std::string CoreManager::GetCustomSwitch(std::string key) 
{
	return mInterface->GetCustomSwitch(key);
}

bool CoreManager::GetIsHarmonyOs() 
{
	return mInterface->GetIsHarmonyOs();
}

void CoreManager::OpenUrl(std::string url) 
{
	mInterface->OpenUrl(url);
}

void CoreManager::OpenInnerUrl(std::string url) 
{
	mInterface->OpenInnerUrl(url);
}

void CoreManager::OpenDialogWeb(std::string url, std::string title) 
{
	mInterface->OpenDialogWeb(url, title);
}

void CoreManager::OpenActivityWeb(std::string url, std::string title) 
{
	mInterface->OpenActivityWeb(url, title);
}

// void CoreManager::NotifyNotification(int id, std::string body, long fireDate, int unitInterval, Dictionary<std::string, std::string> userinfo) {}
// void CoreManager::CancleNotification(int id) {}
// void CoreManager::CancleNotificationAll() {}
// bool CoreManager::Fastmark() {}
// void CoreManager::JumpComment() {}

void CoreManager::CloseAccount() 
{
	mInterface->CloseAccount();
}

void CoreManager::InitGameConfig(int version) 
{
	mInterface->InitGameConfig(version);
}

std::string CoreManager::GetConfigValue(std::string key) 
{
	return mInterface->GetConfigValue(key);
}

// 移动积分兑换 获取积分数据
// void CoreManager::GetIntegralData() {}
// 移动积分兑换 上报接口
// void CoreManager::ReportIntegral(std::string json) {}
// 移动积分兑换 打开h5界面
// void CoreManager::OpenIntegralActivity() {}
// 更新敏感词配置
void CoreManager::WordFilterUpdate() 
{
	mInterface->WordFilterUpdate();
}

// 处理敏感词
std::string CoreManager::WordFilter(std::string sentence) 
{
	return mInterface->WordFilter(sentence);
}

// 设置当前scene的名称
void CoreManager::SetSceneName(std::string name) 
{
	mInterface->SetSceneName(name);
}

// 积分模块是否打开s
bool CoreManager::IsRedeemEnable() 
{
	return mInterface->IsRedeemEnable();
}

// 积分v2获取订单列表
// void CoreManager::GetOrderData(std::string outOrderId) {}
// 积分v2获取商品列表
// void CoreManager::GetProductData() {}
// 积分v2获取未发货订单列表
// void CoreManager::GetLostOrderData() {}
// 积分v2更新订单列表状态
// void CoreManager::UpdateOrderState(std::string orderList) {}
// 积分v2打开h5页
// void CoreManager::OpenNewIntegralActivity(std::string actJson) {}
// 问卷调查 打开h5页
// void CoreManager::OpenQuestionH5(std::string winId) {}
// 问卷调查 请求弹窗配置
// void CoreManager::GetQuestionWinConfig() {}
// 问卷调查 获取资源更新状态
// int CoreManager::GetQuestionResState() {}
// 问卷调查 获取问卷调查资源
// void CoreManager::GetVerForNet() {}
// 产品-问卷调查 打开h5页
// void CoreManager::OpenSurveyH5(std::string winId) {}
// 产品-问卷调查 请求弹窗配置
// void CoreManager::GetSurveyWinConfig() {}
// 产品-问卷调查 获取资源更新状态
// int CoreManager::GetSurveyResState() {}
// 产品-问卷调查 获取问卷调查资源
// void CoreManager::GetSurveyVerForNet() {}

// 获取投放渠道
std::string CoreManager::GetBuyChannel() 
{
	return mInterface->GetBuyChannel();
}

// 获取投放账户
std::string CoreManager::GetBuyUserId() 
{
	return mInterface->GetBuyUserId();
}

// 积分v3获取订单列表
// void CoreManager::GetOrderDataV3(std::string outOrderId) {}
// 积分v3获取商品列表
// void CoreManager::GetProductDataV3() {}
// 积分v3获取未发货订单列表
// void CoreManager::GetLostOrderDataV3() {}
// 积分v3更新订单列表状态
// void CoreManager::UpdateOrderStateV3(std::string orderList) {}
// 积分v3打开h5页
// void CoreManager::OpenNewIntegralActivityV3(std::string actJson) {}


// 获取Assets下文件内容
std::string CoreManager::GetAssetsFileData(std::string fileName) 
{
	return mInterface->GetAssetsFileData(fileName);
}


/// <summary>
/// 获取apk更新弹窗信息
/// </summary>
/// <returns></returns>
std::string CoreManager::GetUpdateInfo() 
{
	return mInterface->GetUpdateInfo();
}


/// <summary>
/// 根据key获取ConfigVigame.xml中的值
/// </summary>
/// <param name="key">关键字</param>
/// <returns></returns>
std::string CoreManager::GetConfigVigameValue(std::string key) 
{
	return mInterface->GetConfigVigameValue(key);
}


// /// <summary>
// /// 设置unity当前节点信息
// /// </summary>
// /// <param name="nodeInfo"></param>
// void CoreManager::SetNodeInfo(std::string nodeInfo) {}


// /// <summary>
// /// 获取签名验证MD5
// /// </summary>
// /// <returns></returns>
// std::string CoreManager::GetSignMd5() {}


/// <summary>
/// 获取opengl版本
/// </summary>
/// <returns></returns>
std::string CoreManager::GetOpenGLVersion() 
{
	return mInterface->GetOpenGLVersion();
}


/// <summary>
/// 打开deepLink
/// </summary>
/// <param name="openUrl">deepLink链接</param>
/// <returns>0失败；1成功</returns>
int CoreManager::OpenDeepLink(std::string openUrl) 
{
	return mInterface->OpenDeepLink(openUrl);
}


/// <summary>
/// 打开支付宝DeepLink链接
/// </summary>
/// <returns>0失败；1成功</returns>
int CoreManager::OpenZfbDp() 
{
	return mInterface->OpenZfbDp();
}

/// <summary>
/// 获取动能id
/// </summary>
/// <returns>动能id</returns>
std::string CoreManager::GetDnid() 
{
	return mInterface->GetDnid();
}

/**
 * @brief 获取 开机时间.
 * 
 * @return long 
 */
unsigned long CoreManager::GetElapsedRealtime()
{
	return mInterface->GetElapsedRealtime();
}

/**
 * @brief 兑换码回调
 * 
 * @param status 
 * @param price 
 * @param msg 
 */
void CoreManager::CDKeyCallBack(std::string params)
{
	cocos2d::log("CoreManager CDKeyCallBack params = %s", params.c_str());
	if (this->cdKeyCallFun == nullptr) return;
	std::vector<std::string> tokens = vigame::Utils::getInstance()->Split(params, "#");
	std::string price = tokens[0];
	int status = atoi(tokens[1].c_str());
	std::string msg = tokens[2];
	this->cdKeyCallFun(CDKeyState(status), price, msg);
	this->cdKeyCallFun = nullptr;
}

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
extern "C"
{
	JNIEXPORT void Java_com_vimedia_cocos2dxbridge_Cocos2dxWbActivity_CDKeyCallBack(JNIEnv *env, jobject thiz, jstring jparams)
	{
		std::string params = cocos2d::JniHelper::jstring2string(jparams);
		vigame::CoreManager::getInstance()->CDKeyCallBack(params);
	}
}

#endif

VIGAME_END