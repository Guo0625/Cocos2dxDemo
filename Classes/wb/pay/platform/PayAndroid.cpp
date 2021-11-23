#include "PayAndroid.h"
#include "cocos2d.h"

VIGAME_BEGIN

PayAndroid::PayAndroid() 
{

}

PayAndroid::~PayAndroid() 
{

}

void PayAndroid::init() 
{

}

void PayAndroid::OrderPay(int payId) 
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo methodInfo;
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, ANDROIDBRIDGE_CLASS, "orderPay", "(I)V");
	if (isExist)
	{
		methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, payId); //call Java method
		methodInfo.env->ExceptionClear();
	}
	else
	{
		cocos2d::log("Pay jni get OrderPay function error");
	}
#endif
}

void PayAndroid::OrderPay(int payId, int price) 
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo methodInfo;
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, ANDROIDBRIDGE_CLASS, "orderPay", "(II)V");
	if (isExist)
	{
		methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, payId, price); //call Java method
		methodInfo.env->ExceptionClear();
	}
	else
	{
		cocos2d::log("Pay jni get OrderPay function error");
	}
#endif
}

void PayAndroid::OrderPay(int payId, std::string userData) 
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo methodInfo;
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, ANDROIDBRIDGE_CLASS, "orderPay", "(ILjava/lang/String;)V");
	if (isExist)
	{
		jstring str = methodInfo.env->NewStringUTF(userData.c_str());						//create jstring
		methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, payId, str); //call Java method
		methodInfo.env->DeleteLocalRef(str);
		methodInfo.env->ExceptionClear();
	}
	else
	{
		cocos2d::log("Pay jni get orderPay function error");
	}
#endif
}

void PayAndroid::OrderPay(int payId, int price, std::string userData) 
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo methodInfo;
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, ANDROIDBRIDGE_CLASS, "orderPay", "(IILjava/lang/String;)V");
	if (isExist)
	{
		jstring str = methodInfo.env->NewStringUTF(userData.c_str());						//create jstring
		methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, payId, price, str); //call Java method
		methodInfo.env->DeleteLocalRef(str);
		methodInfo.env->ExceptionClear();
	}
	else
	{
		cocos2d::log("Pay jni get orderPay function error");
	}
#endif
}

void PayAndroid::OrderPay(int payId, int price, int type, std::string userData) 
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo methodInfo;
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, ANDROIDBRIDGE_CLASS, "orderPay", "(IIILjava/lang/String;)V");
	if (isExist)
	{
		jstring str = methodInfo.env->NewStringUTF(userData.c_str());						//create jstring
		methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, payId, price, type, str); //call Java method
		methodInfo.env->DeleteLocalRef(str);
		methodInfo.env->ExceptionClear();
	}
	else
	{
		cocos2d::log("Pay jni get orderPay function error");
	}
#endif
}

int PayAndroid::GetGiftCtrlFlagUse(int giftId) 
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo methodInfo;
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, ANDROIDBRIDGE_CLASS, "getGiftCtrlFlagUse", "(I)I");
	if (isExist)
	{
		int ret = methodInfo.env->CallStaticIntMethod(methodInfo.classID, methodInfo.methodID, giftId); //call Java method
		methodInfo.env->ExceptionClear();
		return ret;
	}
	else
	{
		cocos2d::log("Pay jni get GetGiftCtrlFlagUse function error");
		return -1;
	}
#endif
}

bool PayAndroid::IsSupportExit() 
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo methodInfo;
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, ANDROIDBRIDGE_CLASS, "isSupportExit", "()Z");
	if (isExist)
	{
		bool ret = methodInfo.env->CallStaticBooleanMethod(methodInfo.classID, methodInfo.methodID); //call Java method
		methodInfo.env->ExceptionClear();
		return ret;
	}
	else
	{
		cocos2d::log("Pay jni get IsSupportExit function error");
		return false;
	}
#endif
}

void PayAndroid::OpenExitGame() 
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo methodInfo;
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, ANDROIDBRIDGE_CLASS, "openExitGame", "()V");
	if (isExist)
	{
		methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID); //call Java method
		methodInfo.env->ExceptionClear();
	}
	else
	{
		cocos2d::log("Pay jni get openExitGame function error");
	}
#endif
}

bool PayAndroid::IsMoreGameBtn() 
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo methodInfo;
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, ANDROIDBRIDGE_CLASS, "isMoreGameBtn", "()Z");
	if (isExist)
	{
		bool ret = methodInfo.env->CallStaticBooleanMethod(methodInfo.classID, methodInfo.methodID); //call Java method
		methodInfo.env->ExceptionClear();
		return ret;
	}
	else
	{
		cocos2d::log("Pay jni get isMoreGameBtn function error");
		return false;
	}
#endif
}

void PayAndroid::OpenMoreGame() 
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo methodInfo;
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, ANDROIDBRIDGE_CLASS, "openMoreGame", "()V");
	if (isExist)
	{
		methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID); //call Java method
		methodInfo.env->ExceptionClear();
	}
	else
	{
		cocos2d::log("Pay jni get openMoreGame function error");
	}
#endif
}

bool PayAndroid::IsPayReady() 
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo methodInfo;
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, ANDROIDBRIDGE_CLASS, "isPayReady", "()Z");
	if (isExist)
	{
		bool ret = methodInfo.env->CallStaticBooleanMethod(methodInfo.classID, methodInfo.methodID); //call Java method
		methodInfo.env->ExceptionClear();
		return ret;
	}
	else
	{
		cocos2d::log("Pay jni get isPayReady function error");
		return false;
	}
#endif
}

std::string PayAndroid::GetDefaultFeeInfo() 
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo methodInfo;
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, ANDROIDBRIDGE_CLASS, "getDefaultFeeInfo", "()Ljava/lang/String;");
	if (isExist)
	{
		std::string str = cocos2d::JniHelper::jstring2string((jstring)methodInfo.env->CallStaticObjectMethod(methodInfo.classID, methodInfo.methodID)); //call Java method
		methodInfo.env->ExceptionClear();
		return str;
	}
	else
	{
		cocos2d::log("Pay jni get getDefaultFeeInfo function error");
		return "";
	}
#endif
}

int PayAndroid::GetDefaultPayType() 
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo methodInfo;
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, ANDROIDBRIDGE_CLASS, "getDefaultPayType", "()I");
	if (isExist)
	{
		int ret = methodInfo.env->CallStaticIntMethod(methodInfo.classID, methodInfo.methodID); //call Java method
		methodInfo.env->ExceptionClear();
		return ret;
	}
	else
	{
		cocos2d::log("Pay jni get getDefaultPayType function error");
		return -1;
	}
#endif
}

bool PayAndroid::IsBillingPointExist(std::string bp) 
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo methodInfo;
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, ANDROIDBRIDGE_CLASS, "isBillingPointExist", "(Ljava/lang/String;)Z");
	if (isExist)
	{
		jstring str = methodInfo.env->NewStringUTF(bp.c_str());						//create jstring
		bool ret = methodInfo.env->CallStaticBooleanMethod(methodInfo.classID, methodInfo.methodID, str); //call Java method
		methodInfo.env->DeleteLocalRef(str);
		methodInfo.env->ExceptionClear();
		return ret;
	}
	else
	{
		cocos2d::log("Pay jni get IsBillingPointExist function error");
		return false;
	}
#endif
}

int PayAndroid::GetButtonType(int id) 
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo methodInfo;
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, ANDROIDBRIDGE_CLASS, "getButtonType", "(I)I");
	if (isExist)
	{
		int ret = methodInfo.env->CallStaticIntMethod(methodInfo.classID, methodInfo.methodID, id); //call Java method
		methodInfo.env->ExceptionClear();
		return ret;
	}
	else
	{
		cocos2d::log("Pay jni get getButtonType function error");
		return -1;
	}
#endif
}

int PayAndroid::GetMarketType() 
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo methodInfo;
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, ANDROIDBRIDGE_CLASS, "getMarketType", "()I");
	if (isExist)
	{
		int ret =  methodInfo.env->CallStaticIntMethod(methodInfo.classID, methodInfo.methodID); //call Java method
		methodInfo.env->ExceptionClear();
		return ret;
	}
	else
	{
		cocos2d::log("Pay jni get getMarketType function error");
		return -1;
	}
#endif
}

void PayAndroid::OrderPayWithType(int payId, int price, int payType,std::string userData) 
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo methodInfo;
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, ANDROIDBRIDGE_CLASS, "orderPayWithType", "(IIILjava/lang/String;)V");
	if (isExist)
	{
		jstring str = methodInfo.env->NewStringUTF(userData.c_str());						//create jstring
		methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, payId, price, payType, str); //call Java method
		methodInfo.env->DeleteLocalRef(str);
		methodInfo.env->ExceptionClear();
	}
	else
	{
		cocos2d::log("Pay jni get orderPayWithType function error");
	}
#endif
}

void PayAndroid::OpenMarket(std::string packageName) 
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo methodInfo;
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, ANDROIDBRIDGE_CLASS, "openMarket", "(Ljava/lang/String;)V");
	if (isExist)
	{
		jstring str = methodInfo.env->NewStringUTF(packageName.c_str());						//create jstring
		methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, str); //call Java method
		methodInfo.env->DeleteLocalRef(str);
		methodInfo.env->ExceptionClear();
	}
	else
	{
		cocos2d::log("Pay jni get openMarket function error");
	}
#endif
}

void PayAndroid::OpenAppraise() 
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo methodInfo;
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, ANDROIDBRIDGE_CLASS, "openAppraise", "()V");
	if (isExist)
	{
		methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID); //call Java method
		methodInfo.env->ExceptionClear();
	}
	else
	{
		cocos2d::log("Pay jni get openAppraise function error");
	}
#endif
}

std::string PayAndroid::GetPayList() 
{ 
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo methodInfo;
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, "com/vimedia/cocos2dxbridge/Cocos2dxWbActivity", "GetPayList", "()[I");
	if (isExist)
	{
		std::string str = cocos2d::JniHelper::jstring2string((jstring)methodInfo.env->CallStaticObjectMethod(methodInfo.classID, methodInfo.methodID)); //call Java method
		methodInfo.env->ExceptionClear();
		return str;
	}
	else
	{
		cocos2d::log("Pay jni get GetPayList function error");
		return nullptr;
	}
#endif
}

void PayAndroid::ClearPayList(int payId) 
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo methodInfo;
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, "com/vimedia/cocos2dxbridge/Cocos2dxWbActivity", "ClearPayList", "(I)V");
	if (isExist)
	{
		methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, payId); //call Java method
		methodInfo.env->ExceptionClear();
	}
	else
	{
		cocos2d::log("Pay jni get ClearPayList function error");
	}
#endif
}

void PayAndroid::ReportUserGameInfo(std::string roldId, std::string roleName, int roleLevel, std::string realmId, std::string realmName, std::string chapter, int combatValue, int pointValue, std::string ext)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo methodInfo;
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, ANDROIDBRIDGE_CLASS, "reportUserGameInfo", "(Ljava/lang/String;Ljava/lang/String;ILjava/lang/String;Ljava/lang/String;Ljava/lang/String;IILjava/lang/String;)V");
	if (isExist)
	{
		jstring str1 = methodInfo.env->NewStringUTF(roldId.c_str());						//create jstring
		jstring str2 = methodInfo.env->NewStringUTF(roleName.c_str());						//create jstring
		jstring str3 = methodInfo.env->NewStringUTF(realmId.c_str());						//create jstring
		jstring str4 = methodInfo.env->NewStringUTF(realmName.c_str());						//create jstring
		jstring str5 = methodInfo.env->NewStringUTF(chapter.c_str());						//create jstring
		jstring str6 = methodInfo.env->NewStringUTF(ext.c_str());						//create jstring
		methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, str1, str2, roleLevel, str3, str4, str5, combatValue, pointValue, str6); //call Java method
		methodInfo.env->DeleteLocalRef(str1);
		methodInfo.env->DeleteLocalRef(str2);
		methodInfo.env->DeleteLocalRef(str3);
		methodInfo.env->DeleteLocalRef(str4);
		methodInfo.env->DeleteLocalRef(str5);
		methodInfo.env->DeleteLocalRef(str6);
		methodInfo.env->ExceptionClear();
	}
	else
	{
		cocos2d::log("Pay jni get reportUserGameInfo function error");
	}
#endif
}

VIGAME_END