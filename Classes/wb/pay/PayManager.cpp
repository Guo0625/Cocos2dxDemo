#include "cocos2d.h"
#include "PayManager.h"
#include "../utils/Utils.h"
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#include "platform/PayAndroid.h"
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
#include "platform/PayiOS.h"
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
#include "platform/PayPc.h"
#endif

VIGAME_BEGIN

PayManager *PayManager::getInstance()
{
	static std::unique_ptr<PayManager> s_instance;
	static std::once_flag s_instance_created;
	std::call_once(s_instance_created, [=]
				   { s_instance = std::make_unique<PayManager>(); });
	return s_instance.get();
}

PayManager::PayManager()
{
	func = nullptr;

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	mInterface = new vigame::PayAndroid();
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	mInterface = new vigame::PayiOS();
#else
	mInterface = new vigame::PayPc();
#endif
	mInterface->init();
}

PayManager::~PayManager()
{
}

void PayManager::OrderPay(int payId, std::function<void(PayStatus, int, std::string)> func) 
{
	this->func = func;
	mInterface->OrderPay(payId);
}

void PayManager::OrderPay(int payId, int price, std::function<void(PayStatus, int, std::string)> func) 
{
	this->func = func;
	mInterface->OrderPay(payId, price);
}

void PayManager::OrderPay(int payId, std::string userData, std::function<void(PayStatus, int, std::string)> func) 
{
	this->func = func;
	mInterface->OrderPay(payId, userData);
}

void PayManager::OrderPay(int payId, int price, std::string userData, std::function<void(PayStatus, int, std::string)> func) 
{
	this->func = func;
	mInterface->OrderPay(payId, price, userData);
}

void PayManager::OrderPay(int payId, int price, int type, std::string userData, std::function<void(PayStatus, int, std::string)> func) 
{
	this->func = func;
	mInterface->OrderPay(payId, price, type, userData);
}

int PayManager::GetGiftCtrlFlagUse(int giftId) 
{ 
	return 	mInterface->GetGiftCtrlFlagUse(giftId);
}

bool PayManager::IsSupportExit() 
{ 
	return mInterface->IsSupportExit();
}

void PayManager::OpenExitGame() 
{
	mInterface->OpenExitGame();
}

bool PayManager::IsMoreGameBtn() 
{ 
	return mInterface->IsMoreGameBtn();
}

void PayManager::OpenMoreGame() 
{
	mInterface->OpenMoreGame();
}

bool PayManager::IsPayReady() 
{ 
	return mInterface->IsPayReady();
}

std::string PayManager::GetDefaultFeeInfo() 
{ 
	return mInterface->GetDefaultFeeInfo();
}

int PayManager::GetDefaultPayType() 
{ 
	return mInterface->GetDefaultPayType();
}

bool PayManager::IsBillingPointExist(std::string bp) 
{ 
	return mInterface->IsBillingPointExist(bp);
}

int PayManager::GetButtonType(int id) 
{ 
	return mInterface->GetButtonType(id);
}

int PayManager::GetMarketType() 
{ 
	return mInterface->GetMarketType();
}

void PayManager::OrderPayWithType(int payId, int price, int payType, std::string userData, std::function<void(PayStatus, int, std::string)> func) 
{
	this->func = func;
	mInterface->OrderPayWithType(payId, price, payType, userData);
}

void PayManager::OpenMarket(std::string packageName) 
{
	mInterface->OpenMarket(packageName);
}

void PayManager::OpenAppraise() 
{
	mInterface->OpenAppraise();
}

std::vector<std::string> PayManager::Split(std::string str, std::string pattern)
{
    std::vector<std::string> res;
    if(str == "")
        return res;
    //在字符串末尾也加入分隔符，方便截取最后一段
    std::string strs = str + pattern;
    size_t pos = strs.find(pattern);

    while(pos != strs.npos)
    {
        std::string temp = strs.substr(0, pos);
        res.push_back(temp);
        //去掉已分割的字符串,在剩下的字符串中进行分割
        strs = strs.substr(pos+1, strs.size());
        pos = strs.find(pattern);
    }

    return res;
}

void PayManager::PayCheckCallBack(std::string params)
{
	cocos2d::log("PayManager params = %s", params.c_str());
	if (this->func == nullptr)
	{
		return;
	}
	std::vector<std::string> tokens = vigame::Utils::getInstance()->Split(params, "#");
	int payId = atoi(tokens[0].c_str());
	std::string resultStr = tokens[1];
	std::string userData = tokens[2];
	PayStatus status = PayStatus::PayFail;
	if (resultStr == "Paysuccess")
	{
		status = PayStatus::PaySuccess;
	}
	else if (resultStr == "Payfail")
	{
		status = PayStatus::PayFail;
	}
	else if (resultStr == "Paycancel")
	{
		status = PayStatus::PayCancel;
	}
	this->func(status, payId, userData);
	this->func = nullptr;
	this->ClearPayList(payId);
}

/**
 * @brief 获取补单列表
 * 
 * @return std::string 
 */
std::vector<std::string> PayManager::GetPayList()
{
	std::string ret = mInterface->GetPayList();
	std::vector<std::string> tokens = vigame::Utils::getInstance()->Split(ret, "#");
	return tokens;
}

/**
 * @brief 根据id删除补单
 * 
 * @param payId 
 */
void PayManager::ClearPayList(int payId)
{
	mInterface->ClearPayList(payId);
}

/**
 * @brief 上报用户游戏信息
 * 
 * @param roldId 
 * @param roleName 
 * @param roleLevel 
 * @param realmId 
 * @param realmName 
 * @param chapter 
 * @param combatValue 
 * @param pointValue 
 * @param ext 
 */
void PayManager::ReportUserGameInfo(std::string roldId, std::string roleName, int roleLevel, std::string realmId, std::string realmName, std::string chapter, int combatValue, int pointValue, std::string ext)
{
	this->mInterface->ReportUserGameInfo(roldId, roleName, roleLevel, realmId, realmName, chapter, combatValue, pointValue, ext);
}

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
extern "C"
{
	JNIEXPORT void Java_com_vimedia_cocos2dxbridge_Cocos2dxWbActivity_PayCheckCallBack(JNIEnv *env, jobject thiz, jstring jparams)
	{
		std::string params = cocos2d::JniHelper::jstring2string(jparams);
		vigame::PayManager::getInstance()->PayCheckCallBack(params);
	}
}

#endif

VIGAME_END