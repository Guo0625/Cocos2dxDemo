#include "CoreAndroid.h"
#include "cocos2d.h"

VIGAME_BEGIN

CoreAndroid::CoreAndroid()
{
}

CoreAndroid::~CoreAndroid()
{
}

void CoreAndroid::init()
{
}

void CoreAndroid::UseCDKey(std::string dhm) 
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo methodInfo;
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, "com/vimedia/game/AndroidBridge", "useCDKey", "(Ljava/lang/String;)V");
	if (isExist)
	{
		jstring str = methodInfo.env->NewStringUTF(dhm.c_str());							//create jstring
		methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, str); //call Java method
		methodInfo.env->DeleteLocalRef(str);
		methodInfo.env->ExceptionClear();
	}
	else
	{
		cocos2d::log("Core jni get useCDKey function error");
	}
#endif
}

bool CoreAndroid::CDKeyIsSupport() 
{ 
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo methodInfo;
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, "com/vimedia/game/AndroidBridge", "CDKeyIsSupport", "()Z");
	if (isExist)
	{
		bool ret = methodInfo.env->CallStaticBooleanMethod(methodInfo.classID, methodInfo.methodID); //call Java method
		methodInfo.env->ExceptionClear();
		return ret;
	}
	else
	{
		cocos2d::log("Core jni get CDKeyIsSupport function error");
		return false;
	}
#endif
}

void CoreAndroid::OpenActivityPage() 
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo methodInfo;
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, "com/vimedia/game/AndroidBridge", "openActivityPage", "()V");
	if (isExist)
	{
		methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID); //call Java method
		methodInfo.env->ExceptionClear();
	}
	else
	{
		cocos2d::log("Core jni get openActivityPage function error");
	}
#endif
}

void CoreAndroid::OpenActivityNotice() 
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo methodInfo;
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, "com/vimedia/game/AndroidBridge", "openActivityNotice", "()V");
	if (isExist)
	{
		methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID); //call Java method
		methodInfo.env->ExceptionClear();
	}
	else
	{
		cocos2d::log("Core jni get openActivityNotice function error");
	}
#endif
}

void CoreAndroid::OpenRank() 
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo methodInfo;
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, "com/vimedia/game/AndroidBridge", "openRank", "()V");
	if (isExist)
	{
		methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID); //call Java method
		methodInfo.env->ExceptionClear();
	}
	else
	{
		cocos2d::log("Core jni get openRank function error");
	}
#endif
}

void CoreAndroid::OpenUserAgreement() 
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo methodInfo;
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, "com/vimedia/game/AndroidBridge", "openUserAgreement", "()V");
	if (isExist)
	{
		methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID); //call Java method
		methodInfo.env->ExceptionClear();
	}
	else
	{
		cocos2d::log("Core jni get openUserAgreement function error");
	}
#endif
}

void CoreAndroid::OpenPrivacyPolicy() 
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo methodInfo;
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, "com/vimedia/game/AndroidBridge", "openPrivacyPolicy", "()V");
	if (isExist)
	{
		methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID); //call Java method
		methodInfo.env->ExceptionClear();
	}
	else
	{
		cocos2d::log("Core jni get openPrivacyPolicy function error");
	}
#endif
}

void CoreAndroid::OpenUserAgreementByWeb() 
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo methodInfo;
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, "com/vimedia/game/AndroidBridge", "openUserAgreementByWeb", "()V");
	if (isExist)
	{
		methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID); //call Java method
		methodInfo.env->ExceptionClear();
	}
	else
	{
		cocos2d::log("Core jni get openUserAgreementByWeb function error");
	}
#endif
}

void CoreAndroid::OpenUserAgreementNoCompany() 
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo methodInfo;
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, "com/vimedia/game/AndroidBridge", "openUserAgreementNoCompany", "()V");
	if (isExist)
	{
		methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID); //call Java method
		methodInfo.env->ExceptionClear();
	}
	else
	{
		cocos2d::log("Core jni get openUserAgreementNoCompany function error");
	}
#endif	
}

void CoreAndroid::OpenFeedback() 
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo methodInfo;
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, "com/vimedia/game/AndroidBridge", "openFeedback", "()V");
	if (isExist)
	{
		methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID); //call Java method
		methodInfo.env->ExceptionClear();
	}
	else
	{
		cocos2d::log("Core jni get openFeedback function error");
	}
#endif	
}

void CoreAndroid::OpenMarketPlus(std::string url, std::string param) 
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo methodInfo;
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, "com/vimedia/game/AndroidBridge", "openMarketPlus", "(Ljava/lang/String;Ljava/lang/String;)V");
	if (isExist)
	{
		jstring str1 = methodInfo.env->NewStringUTF(url.c_str());
		jstring str2 = methodInfo.env->NewStringUTF(param.c_str());
		methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, str1, str2); //call Java method
		methodInfo.env->DeleteLocalRef(str1);
		methodInfo.env->DeleteLocalRef(str2);
		methodInfo.env->ExceptionClear();
	}
	else
	{
		cocos2d::log("Core jni get openMarketPlus function error");
	}
#endif		
}

void CoreAndroid::SumbitRankData(std::string userId, int level, int score, int usedCoins, int leftCoins) 
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo methodInfo;
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, "com/vimedia/game/AndroidBridge", "sumbitRankData", "(Ljava/lang/String;IIII)V");
	if (isExist)
	{
		jstring str = methodInfo.env->NewStringUTF(userId.c_str());
		methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, str, level, score, usedCoins, leftCoins); //call Java method
		methodInfo.env->DeleteLocalRef(str);
		methodInfo.env->ExceptionClear();
	}
	else
	{
		cocos2d::log("Core jni get sumbitRankData function error");
	}
#endif
}

void CoreAndroid::SetGameName(std::string gameName) 
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo methodInfo;
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, "com/vimedia/game/AndroidBridge", "setGameName", "(Ljava/lang/String;)V");
	if (isExist)
	{
		jstring str = methodInfo.env->NewStringUTF(gameName.c_str());
		methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, str); //call Java method
		methodInfo.env->DeleteLocalRef(str);
		methodInfo.env->ExceptionClear();
	}
	else
	{
		cocos2d::log("Core jni get setGameName function error");
	}
#endif
}

std::string CoreAndroid::GetAppName() 
{ 
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo methodInfo;
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, "com/vimedia/game/AndroidBridge", "getAppName", "()Ljava/lang/String;");
	if (isExist)
	{
		std::string ret = cocos2d::JniHelper::jstring2string((jstring)(methodInfo.env->CallStaticObjectMethod(methodInfo.classID, methodInfo.methodID))); //call Java method
		methodInfo.env->ExceptionClear();
		return ret;
	}
	else
	{
		cocos2d::log("Core jni get getAppName function error");
		return "";
	}
#endif
}

std::string CoreAndroid::GetChannel() 
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo methodInfo;
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, "com/vimedia/game/AndroidBridge", "getChannel", "()Ljava/lang/String;");
	if (isExist)
	{
		std::string ret = cocos2d::JniHelper::jstring2string((jstring)(methodInfo.env->CallStaticObjectMethod(methodInfo.classID, methodInfo.methodID))); //call Java method
		methodInfo.env->ExceptionClear();
		return ret;
	}
	else
	{
		cocos2d::log("Core jni get getChannel function error");
		return "";
	}
#endif
}

std::string CoreAndroid::GetPrjid() 
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo methodInfo;
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, "com/vimedia/game/AndroidBridge", "getPrjid", "()Ljava/lang/String;");
	if (isExist)
	{
		std::string ret = cocos2d::JniHelper::jstring2string((jstring)(methodInfo.env->CallStaticObjectMethod(methodInfo.classID, methodInfo.methodID))); //call Java method
		methodInfo.env->ExceptionClear();
		return ret;
	}
	else
	{
		cocos2d::log("Core jni get getPrjid function error");
		return "";
	}
#endif
}

std::string CoreAndroid::GetAppid() 
{ 
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo methodInfo;
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, "com/vimedia/game/AndroidBridge", "getAppid", "()Ljava/lang/String;");
	if (isExist)
	{
		std::string ret = cocos2d::JniHelper::jstring2string((jstring)(methodInfo.env->CallStaticObjectMethod(methodInfo.classID, methodInfo.methodID))); //call Java method
		methodInfo.env->ExceptionClear();
		return ret;
	}
	else
	{
		cocos2d::log("Core jni get getAppid function error");
		return "";
	}
#endif
}

std::string CoreAndroid::GetLsn() 
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo methodInfo;
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, "com/vimedia/game/AndroidBridge", "getLsn", "()Ljava/lang/String;");
	if (isExist)
	{
		std::string ret = cocos2d::JniHelper::jstring2string((jstring)(methodInfo.env->CallStaticObjectMethod(methodInfo.classID, methodInfo.methodID))); //call Java method
		methodInfo.env->ExceptionClear();
		return ret;
	}
	else
	{
		cocos2d::log("Core jni get getLsn function error");
		return "";
	}
#endif
}

std::string CoreAndroid::GetUuid() 
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo methodInfo;
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, "com/vimedia/game/AndroidBridge", "getUuid", "()Ljava/lang/String;");
	if (isExist)
	{
		std::string ret = cocos2d::JniHelper::jstring2string((jstring)(methodInfo.env->CallStaticObjectMethod(methodInfo.classID, methodInfo.methodID))); //call Java method
		methodInfo.env->ExceptionClear();
		return ret;
	}
	else
	{
		cocos2d::log("Core jni get getUuid function error");
		return "";
	}
#endif
}

std::string CoreAndroid::GetImsi() 
{ 
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo methodInfo;
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, "com/vimedia/game/AndroidBridge", "getImsi", "()Ljava/lang/String;");
	if (isExist)
	{
		std::string ret = cocos2d::JniHelper::jstring2string((jstring)(methodInfo.env->CallStaticObjectMethod(methodInfo.classID, methodInfo.methodID))); //call Java method
		methodInfo.env->ExceptionClear();
		return ret;
	}
	else
	{
		cocos2d::log("Core jni get getImsi function error");
		return "";
	}
#endif
}

std::string CoreAndroid::GetImei() 
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo methodInfo;
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, "com/vimedia/game/AndroidBridge", "getImei", "()Ljava/lang/String;");
	if (isExist)
	{
		std::string ret = cocos2d::JniHelper::jstring2string((jstring)(methodInfo.env->CallStaticObjectMethod(methodInfo.classID, methodInfo.methodID))); //call Java method
		methodInfo.env->ExceptionClear();
		return ret;
	}
	else
	{
		cocos2d::log("Core jni get getImei function error");
		return "";
	}
#endif	
}

std::string CoreAndroid::GetOaid() 
{ 
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo methodInfo;
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, "com/vimedia/game/AndroidBridge", "getOaid", "()Ljava/lang/String;");
	if (isExist)
	{
		std::string ret = cocos2d::JniHelper::jstring2string((jstring)(methodInfo.env->CallStaticObjectMethod(methodInfo.classID, methodInfo.methodID))); //call Java method
		methodInfo.env->ExceptionClear();
		return ret;
	}
	else
	{
		cocos2d::log("Core jni get getOaid function error");
		return "";
	}
#endif
}

std::string CoreAndroid::GetAndroidId() 
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo methodInfo;
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, "com/vimedia/game/AndroidBridge", "getAndroidId", "()Ljava/lang/String;");
	if (isExist)
	{
		std::string ret = cocos2d::JniHelper::jstring2string((jstring)(methodInfo.env->CallStaticObjectMethod(methodInfo.classID, methodInfo.methodID))); //call Java method
		methodInfo.env->ExceptionClear();
		return ret;
	}
	else
	{
		cocos2d::log("Core jni get getAndroidId function error");
		return "";
	}
#endif
}

std::string CoreAndroid::GetAppkey() 
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo methodInfo;
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, "com/vimedia/game/AndroidBridge", "getAppKey", "()Ljava/lang/String;");
	if (isExist)
	{
		std::string ret = cocos2d::JniHelper::jstring2string((jstring)(methodInfo.env->CallStaticObjectMethod(methodInfo.classID, methodInfo.methodID))); //call Java method
		methodInfo.env->ExceptionClear();
		return ret;
	}
	else
	{
		cocos2d::log("Core jni get getAppKey function error");
		return "";
	}
#endif
}

int CoreAndroid::GetNetState() 
{ 
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo methodInfo;
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, "com/vimedia/game/AndroidBridge", "getNetState", "()I");
	if (isExist)
	{
		jint ret = methodInfo.env->CallStaticIntMethod(methodInfo.classID, methodInfo.methodID); //call Java method
		methodInfo.env->ExceptionClear();
		return ret;
	}
	else
	{
		cocos2d::log("Core jni get getNetState function error");
		return 0;
	}
#endif
}

std::string CoreAndroid::GetSignature() 
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo methodInfo;
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, "com/vimedia/game/AndroidBridge", "getSignature", "()Ljava/lang/String;");
	if (isExist)
	{
		std::string str = cocos2d::JniHelper::jstring2string((jstring)methodInfo.env->CallStaticObjectMethod(methodInfo.classID, methodInfo.methodID)); //call Java method
		methodInfo.env->ExceptionClear();
		return str;
	}
	else
	{
		cocos2d::log("Core jni get getSignature function error");
		return "";
	}
#endif
}

std::string CoreAndroid::GetPackageName() 
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo methodInfo;
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, "com/vimedia/game/AndroidBridge", "getPkgName", "()Ljava/lang/String;");
	if (isExist)
	{
		std::string str = cocos2d::JniHelper::jstring2string((jstring)methodInfo.env->CallStaticObjectMethod(methodInfo.classID, methodInfo.methodID)); //call Java method
		methodInfo.env->ExceptionClear();
		return str;
	}
	else
	{
		cocos2d::log("Core jni get getPkgName function error");
		return "";
	}
#endif
}

std::string CoreAndroid::GetVerName() 
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo methodInfo;
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, "com/vimedia/game/AndroidBridge", "getVerName", "()Ljava/lang/String;");
	if (isExist)
	{
		std::string str = cocos2d::JniHelper::jstring2string((jstring)methodInfo.env->CallStaticObjectMethod(methodInfo.classID, methodInfo.methodID)); //call Java method
		methodInfo.env->ExceptionClear();
		return str;
	}
	else
	{
		cocos2d::log("Core jni get getVerName function error");
		return "";
	}
#endif
}

//返回值：true-非审核状态 false-审核中
bool CoreAndroid::GetAuditSwitch() 
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo methodInfo;
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, "com/vimedia/game/AndroidBridge", "getAuditSwitch", "()Z");
	if (isExist)
	{
		bool ret = methodInfo.env->CallStaticBooleanMethod(methodInfo.classID, methodInfo.methodID); //call Java method
		methodInfo.env->ExceptionClear();
		return ret;
	}
	else
	{
		cocos2d::log("Core jni get getAuditSwitch function error");
		return false;
	}
#endif
}

std::string CoreAndroid::GetCustomSwitch(std::string key) 
{ 
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo methodInfo;
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, "com/vimedia/game/AndroidBridge", "getCustomSwitch", "(Ljava/lang/String;)Ljava/lang/String;");
	if (isExist)
	{
		jstring str = methodInfo.env->NewStringUTF(key.c_str());
		std::string ret = cocos2d::JniHelper::jstring2string((jstring)methodInfo.env->CallStaticObjectMethod(methodInfo.classID, methodInfo.methodID, str)); //call Java method
		methodInfo.env->DeleteLocalRef(str);
		methodInfo.env->ExceptionClear();
		return ret;
	}
	else
	{
		cocos2d::log("Core jni get getCustomSwitch function error");
		return "";
	}
#endif
}

bool CoreAndroid::GetIsHarmonyOs() 
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo methodInfo;
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, "com/vimedia/game/AndroidBridge", "getIsHarmonyOs", "()Z");
	if (isExist)
	{
		bool ret = methodInfo.env->CallStaticBooleanMethod(methodInfo.classID, methodInfo.methodID); //call Java method
		methodInfo.env->ExceptionClear();
		return ret;
	}
	else
	{
		cocos2d::log("Core jni get getIsHarmonyOs function error");
		return false;
	}
#endif
}

void CoreAndroid::OpenUrl(std::string url) 
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo methodInfo;
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, "com/vimedia/game/AndroidBridge", "openUrl", "(Ljava/lang/String;)V");
	if (isExist)
	{
		jstring str = methodInfo.env->NewStringUTF(url.c_str());
		methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, str); //call Java method
		methodInfo.env->DeleteLocalRef(str);
		methodInfo.env->ExceptionClear();
	}
	else
	{
		cocos2d::log("Core jni get openUrl function error");
	}
#endif
}

void CoreAndroid::OpenInnerUrl(std::string url) 
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo methodInfo;
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, "com/vimedia/game/AndroidBridge", "openInnerUrl", "(Ljava/lang/String;IIII)V");
	if (isExist)
	{
		jstring str = methodInfo.env->NewStringUTF(url.c_str());
		methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, str); //call Java method
		methodInfo.env->DeleteLocalRef(str);
		methodInfo.env->ExceptionClear();
	}
	else
	{
		cocos2d::log("Core jni get openInnerUrl function error");
	}
#endif
}

void CoreAndroid::OpenDialogWeb(std::string url, std::string title)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo methodInfo;
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, "com/vimedia/game/AndroidBridge", "openDialogWeb", "(Ljava/lang/String;Ljava/lang/String;)V");
	if (isExist)
	{
		jstring str1 = methodInfo.env->NewStringUTF(url.c_str());
		jstring str2 = methodInfo.env->NewStringUTF(title.c_str());
		methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, str1, str2); //call Java method
		methodInfo.env->DeleteLocalRef(str1);
		methodInfo.env->DeleteLocalRef(str2);
		methodInfo.env->ExceptionClear();
	}
	else
	{
		cocos2d::log("Core jni get openDialogWeb function error");
	}
#endif
}

void CoreAndroid::OpenActivityWeb(std::string url, std::string title) 
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo methodInfo;
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, "com/vimedia/game/AndroidBridge", "openActivityWeb", "(Ljava/lang/String;Ljava/lang/String;)V");
	if (isExist)
	{
		jstring str1 = methodInfo.env->NewStringUTF(url.c_str());
		jstring str2 = methodInfo.env->NewStringUTF(title.c_str());
		methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, str1, str2); //call Java method
		methodInfo.env->DeleteLocalRef(str1);
		methodInfo.env->DeleteLocalRef(str2);
		methodInfo.env->ExceptionClear();
	}
	else
	{
		cocos2d::log("Core jni get openActivityWeb function error");
	}
#endif
}

// void CoreAndroid::NotifyNotification(int id, std::string body, long fireDate, int unitInterval, Dictionary<std::string, std::string> userinfo) {}
// void CoreAndroid::CancleNotification(int id) {}
// void CoreAndroid::CancleNotificationAll() {}
// bool CoreAndroid::Fastmark() { return false; }
// void CoreAndroid::JumpComment() {}

void CoreAndroid::CloseAccount() 
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo methodInfo;
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, "com/vimedia/game/AndroidBridge", "closeAccount", "()V");
	if (isExist)
	{
		methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID); //call Java method
		methodInfo.env->ExceptionClear();
	}
	else
	{
		cocos2d::log("Core jni get closeAccount function error");
	}
#endif
}

void CoreAndroid::InitGameConfig(int version) 
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo methodInfo;
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, "com/vimedia/game/AndroidBridge", "initGameConfig", "(I)V");
	if (isExist)
	{
		methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, version); //call Java method
		methodInfo.env->ExceptionClear();
	}
	else
	{
		cocos2d::log("Core jni get initGameConfig function error");
	}
#endif
}

std::string CoreAndroid::GetConfigValue(std::string key) 
{ 
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo methodInfo;
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, "com/vimedia/game/AndroidBridge", "getConfigValue", "(Ljava/lang/String;)Ljava/lang/String;");
	if (isExist)
	{
		jstring str = methodInfo.env->NewStringUTF(key.c_str());
		std::string ret = cocos2d::JniHelper::jstring2string((jstring)methodInfo.env->CallStaticObjectMethod(methodInfo.classID, methodInfo.methodID, str)); //call Java method
		methodInfo.env->DeleteLocalRef(str);
		methodInfo.env->ExceptionClear();
		return ret;
	}
	else
	{
		cocos2d::log("Core jni get getConfigValue function error");
		return "";
	}
#endif
}

// // 移动积分兑换 获取积分数据
// void CoreAndroid::GetIntegralData() {}
// // 移动积分兑换 上报接口
// void CoreAndroid::ReportIntegral(std::string json) {}
// // 移动积分兑换 打开h5界面
// void CoreAndroid::OpenIntegralActivity() {}

// 更新敏感词配置
void CoreAndroid::WordFilterUpdate() 
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo methodInfo;
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, "com/vimedia/game/AndroidBridge", "wordFilterUpdate", "()V");
	if (isExist)
	{
		methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID); //call Java method
		methodInfo.env->ExceptionClear();
	}
	else
	{
		cocos2d::log("Core jni get wordFilterUpdate function error");
	}
#endif
}

// 处理敏感词
std::string CoreAndroid::WordFilter(std::string sentence) 
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo methodInfo;
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, "com/vimedia/game/AndroidBridge", "wordFilter", "(Ljava/lang/String;)Ljava/lang/String;");
	if (isExist)
	{
		jstring str = methodInfo.env->NewStringUTF(sentence.c_str());
		std::string ret = cocos2d::JniHelper::jstring2string((jstring)methodInfo.env->CallStaticObjectMethod(methodInfo.classID, methodInfo.methodID, str)); //call Java method
		methodInfo.env->DeleteLocalRef(str);
		methodInfo.env->ExceptionClear();
		return ret;
	}
	else
	{
		cocos2d::log("Core jni get wordFilter function error");
		return "";
	}
#endif
}

// 设置当前scene的名称
void CoreAndroid::SetSceneName(std::string name) 
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo methodInfo;
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, "com/vimedia/game/AndroidBridge", "openActivityWeb", "(Ljava/lang/String;)V");
	if (isExist)
	{
		jstring str1 = methodInfo.env->NewStringUTF(name.c_str());
		methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, str1); //call Java method
		methodInfo.env->DeleteLocalRef(str1);
		methodInfo.env->ExceptionClear();
	}
	else
	{
		cocos2d::log("Core jni get openActivityWeb function error");
	}
#endif
}

// 积分模块是否打开s
bool CoreAndroid::IsRedeemEnable() 
{ 
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo methodInfo;
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, "com/vimedia/game/AndroidBridge", "redeemEnable", "()Z");
	if (isExist)
	{
		bool ret = methodInfo.env->CallStaticBooleanMethod(methodInfo.classID, methodInfo.methodID); //call Java method
		methodInfo.env->ExceptionClear();
		return ret;
	}
	else
	{
		cocos2d::log("Core jni get redeemEnable function error");
		return false;
	}
#endif
}

// // 积分v2获取订单列表
// void CoreAndroid::GetOrderData(std::string outOrderId) {}
// // 积分v2获取商品列表
// void CoreAndroid::GetProductData() {}
// // 积分v2获取未发货订单列表
// void CoreAndroid::GetLostOrderData() {}
// // 积分v2更新订单列表状态
// void CoreAndroid::UpdateOrderState(std::string orderList) {}
// // 积分v2打开h5页
// void CoreAndroid::OpenNewIntegralActivity(std::string actJson) {}
// // 问卷调查 打开h5页
// void CoreAndroid::OpenQuestionH5(std::string winId) {}
// // 问卷调查 请求弹窗配置
// void CoreAndroid::GetQuestionWinConfig() {}
// // 问卷调查 获取资源更新状态
// int CoreAndroid::GetQuestionResState() { return 0; }
// // 问卷调查 获取问卷调查资源
// void CoreAndroid::GetVerForNet() {}
// // 产品-问卷调查 打开h5页
// void CoreAndroid::OpenSurveyH5(std::string winId) {}
// // 产品-问卷调查 请求弹窗配置
// void CoreAndroid::GetSurveyWinConfig() {}
// // 产品-问卷调查 获取资源更新状态
// int CoreAndroid::GetSurveyResState() { return 0; }
// // 产品-问卷调查 获取问卷调查资源
// void CoreAndroid::GetSurveyVerForNet() {}

// 获取投放渠道
std::string CoreAndroid::GetBuyChannel() 
{ 
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo methodInfo;
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, "com/vimedia/game/AndroidBridge", "getBuyChannel", "()Ljava/lang/String;");
	if (isExist)
	{
		std::string ret = cocos2d::JniHelper::jstring2string((jstring)methodInfo.env->CallStaticObjectMethod(methodInfo.classID, methodInfo.methodID)); //call Java method
		methodInfo.env->ExceptionClear();
		return ret;
	}
	else
	{
		cocos2d::log("Core jni get getBuyChannel function error");
		return "";
	}
#endif
}

// 获取投放账户
std::string CoreAndroid::GetBuyUserId() 
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo methodInfo;
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, "com/vimedia/game/AndroidBridge", "getBuyUserId", "()Ljava/lang/String;");
	if (isExist)
	{
		std::string ret = cocos2d::JniHelper::jstring2string((jstring)methodInfo.env->CallStaticObjectMethod(methodInfo.classID, methodInfo.methodID)); //call Java method
		methodInfo.env->ExceptionClear();
		return ret;
	}
	else
	{
		cocos2d::log("Core jni get getBuyUserId function error");
		return "";
	}
#endif
}

// // 积分v3获取订单列表
// void CoreAndroid::GetOrderDataV3(std::string outOrderId) {}
// // 积分v3获取商品列表
// void CoreAndroid::GetProductDataV3() {}
// // 积分v3获取未发货订单列表
// void CoreAndroid::GetLostOrderDataV3() {}
// // 积分v3更新订单列表状态
// void CoreAndroid::UpdateOrderStateV3(std::string orderList) {}
// // 积分v3打开h5页
// void CoreAndroid::OpenNewIntegralActivityV3(std::string actJson) {}

// 获取Assets下文件内容
std::string CoreAndroid::GetAssetsFileData(std::string fileName) 
{ 
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo methodInfo;
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, "com/vimedia/game/AndroidBridge", "getAssetsFileData", "(Ljava/lang/String;)Ljava/lang/String;");
	if (isExist)
	{
		jstring str = methodInfo.env->NewStringUTF(fileName.c_str());
		std::string ret = cocos2d::JniHelper::jstring2string((jstring)methodInfo.env->CallStaticObjectMethod(methodInfo.classID, methodInfo.methodID, str)); //call Java method
		methodInfo.env->DeleteLocalRef(str);
		methodInfo.env->ExceptionClear();
		return ret;
	}
	else
	{
		cocos2d::log("Core jni get getAssetsFileData function error");
		return "";
	}
#endif
}

/// <summary>
/// 获取apk更新弹窗信息
/// </summary>
/// <returns></returns>
std::string CoreAndroid::GetUpdateInfo() 
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo methodInfo;
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, "com/vimedia/game/AndroidBridge", "getUpdateInfo", "()Ljava/lang/String;");
	if (isExist)
	{
		std::string ret = cocos2d::JniHelper::jstring2string((jstring)methodInfo.env->CallStaticObjectMethod(methodInfo.classID, methodInfo.methodID)); //call Java method
		methodInfo.env->ExceptionClear();
		return ret;
	}
	else
	{
		cocos2d::log("Core jni get getUpdateInfo function error");
		return "";
	}
#endif
}

/// <summary>
/// 根据key获取ConfigVigame.xml中的值
/// </summary>
/// <param name="key">关键字</param>
/// <returns></returns>
std::string CoreAndroid::GetConfigVigameValue(std::string key) 
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo methodInfo;
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, "com/vimedia/game/AndroidBridge", "getConfigVigameValue", "(Ljava/lang/String;)Ljava/lang/String;");
	if (isExist)
	{
		jstring str = methodInfo.env->NewStringUTF(key.c_str());
		std::string ret = cocos2d::JniHelper::jstring2string((jstring)methodInfo.env->CallStaticObjectMethod(methodInfo.classID, methodInfo.methodID, str)); //call Java method
		methodInfo.env->DeleteLocalRef(str);
		methodInfo.env->ExceptionClear();
		return ret;
	}
	else
	{
		cocos2d::log("Core jni get getConfigVigameValue function error");
		return "";
	}
#endif
}

// /// <summary>
// /// 设置unity当前节点信息
// /// </summary>
// /// <param name="nodeInfo"></param>
// void CoreAndroid::SetNodeInfo(std::string nodeInfo) {}

// /// <summary>
// /// 获取签名验证MD5
// /// </summary>
// /// <returns></returns>
// std::string CoreAndroid::GetSignMd5() { return ""; }

/// <summary>
/// 获取opengl版本
/// </summary>
/// <returns></returns>
std::string CoreAndroid::GetOpenGLVersion() 
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo methodInfo;
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, "com/vimedia/game/AndroidBridge", "getOpenGLVersion", "()Ljava/lang/String;");
	if (isExist)
	{
		std::string ret = cocos2d::JniHelper::jstring2string((jstring)methodInfo.env->CallStaticObjectMethod(methodInfo.classID, methodInfo.methodID)); //call Java method
		methodInfo.env->ExceptionClear();
		return ret;
	}
	else
	{
		cocos2d::log("Core jni get getOpenGLVersion function error");
		return "";
	}
#endif
}

/// <summary>
/// 打开deepLink
/// </summary>
/// <param name="openUrl">deepLink链接</param>
/// <returns>0失败；1成功</returns>
int CoreAndroid::OpenDeepLink(std::string openUrl) 
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo methodInfo;
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, "com/vimedia/game/AndroidBridge", "openDeepLink", "(Ljava/lang/String;)I");
	if (isExist)
	{
		jstring str = methodInfo.env->NewStringUTF(openUrl.c_str());
		jint ret = methodInfo.env->CallStaticIntMethod(methodInfo.classID, methodInfo.methodID); //call Java method
		methodInfo.env->DeleteLocalRef(str);
		methodInfo.env->ExceptionClear();
		return ret;
	}
	else
	{
		cocos2d::log("Core jni get openDeepLink function error");
		return 0;
	}
#endif
}

/// <summary>
/// 打开支付宝DeepLink链接
/// </summary>
/// <returns>0失败；1成功</returns>
int CoreAndroid::OpenZfbDp() 
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo methodInfo;
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, "com/vimedia/game/AndroidBridge", "openZfbDp", "()I");
	if (isExist)
	{
		jint ret = methodInfo.env->CallStaticIntMethod(methodInfo.classID, methodInfo.methodID); //call Java method
		methodInfo.env->ExceptionClear();
		return ret;
	}
	else
	{
		cocos2d::log("Core jni get openZfbDp function error");
		return 0;
	}
#endif
}

/// <summary>
/// 获取动能id
/// </summary>
/// <returns>动能id</returns>
std::string CoreAndroid::GetDnid()
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo methodInfo;
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, "com/vimedia/game/AndroidBridge", "getDnid", "()Ljava/lang/String;");
	if (isExist)
	{
		std::string ret = cocos2d::JniHelper::jstring2string((jstring)methodInfo.env->CallStaticObjectMethod(methodInfo.classID, methodInfo.methodID)); //call Java method
		methodInfo.env->ExceptionClear();
		return ret;
	}
	else
	{
		cocos2d::log("Core jni get getDnid function error");
		return "";
	}
#endif
}

unsigned long CoreAndroid::GetElapsedRealtime()
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo methodInfo;
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, "com/vimedia/game/AndroidBridge", "getElapsedRealtime", "()J");
	if (isExist)
	{
		unsigned long ret = methodInfo.env->CallStaticLongMethod(methodInfo.classID, methodInfo.methodID); //call Java method
		methodInfo.env->ExceptionClear();
		return ret;
	}
	else
	{
		cocos2d::log("Core jni get getElapsedRealtime function error");
		return 0;
	}
#endif
}

VIGAME_END