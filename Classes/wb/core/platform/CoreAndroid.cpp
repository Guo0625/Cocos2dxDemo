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
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, ANDROIDBRIDGE_CLASS, "useCDKey", "(Ljava/lang/String;)V");
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
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, ANDROIDBRIDGE_CLASS, "CDKeyIsSupport", "()Z");
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
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, ANDROIDBRIDGE_CLASS, "openActivityPage", "()V");
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
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, ANDROIDBRIDGE_CLASS, "openActivityNotice", "()V");
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
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, ANDROIDBRIDGE_CLASS, "openRank", "()V");
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
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, ANDROIDBRIDGE_CLASS, "openUserAgreement", "()V");
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
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, ANDROIDBRIDGE_CLASS, "openPrivacyPolicy", "()V");
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
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, ANDROIDBRIDGE_CLASS, "openUserAgreementByWeb", "()V");
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
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, ANDROIDBRIDGE_CLASS, "openUserAgreementNoCompany", "()V");
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
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, ANDROIDBRIDGE_CLASS, "openFeedback", "()V");
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
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, ANDROIDBRIDGE_CLASS, "openMarketPlus", "(Ljava/lang/String;Ljava/lang/String;)V");
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
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, ANDROIDBRIDGE_CLASS, "sumbitRankData", "(Ljava/lang/String;IIII)V");
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
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, ANDROIDBRIDGE_CLASS, "setGameName", "(Ljava/lang/String;)V");
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
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, ANDROIDBRIDGE_CLASS, "getAppName", "()Ljava/lang/String;");
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
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, ANDROIDBRIDGE_CLASS, "getChannel", "()Ljava/lang/String;");
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
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, ANDROIDBRIDGE_CLASS, "getPrjid", "()Ljava/lang/String;");
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
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, ANDROIDBRIDGE_CLASS, "getAppid", "()Ljava/lang/String;");
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
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, ANDROIDBRIDGE_CLASS, "getLsn", "()Ljava/lang/String;");
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
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, ANDROIDBRIDGE_CLASS, "getUuid", "()Ljava/lang/String;");
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
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, ANDROIDBRIDGE_CLASS, "getImsi", "()Ljava/lang/String;");
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
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, ANDROIDBRIDGE_CLASS, "getImei", "()Ljava/lang/String;");
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
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, ANDROIDBRIDGE_CLASS, "getOaid", "()Ljava/lang/String;");
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
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, ANDROIDBRIDGE_CLASS, "getAndroidId", "()Ljava/lang/String;");
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
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, ANDROIDBRIDGE_CLASS, "getAppKey", "()Ljava/lang/String;");
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
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, ANDROIDBRIDGE_CLASS, "getNetState", "()I");
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
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, ANDROIDBRIDGE_CLASS, "getSignature", "()Ljava/lang/String;");
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
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, ANDROIDBRIDGE_CLASS, "getPkgName", "()Ljava/lang/String;");
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
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, ANDROIDBRIDGE_CLASS, "getVerName", "()Ljava/lang/String;");
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

//????????????true-??????????????? false-?????????
bool CoreAndroid::GetAuditSwitch() 
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo methodInfo;
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, ANDROIDBRIDGE_CLASS, "getAuditSwitch", "()Z");
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
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, ANDROIDBRIDGE_CLASS, "getCustomSwitch", "(Ljava/lang/String;)Ljava/lang/String;");
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
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, ANDROIDBRIDGE_CLASS, "getIsHarmonyOs", "()Z");
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
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, ANDROIDBRIDGE_CLASS, "openUrl", "(Ljava/lang/String;)V");
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
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, ANDROIDBRIDGE_CLASS, "openInnerUrl", "(Ljava/lang/String;IIII)V");
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
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, ANDROIDBRIDGE_CLASS, "openDialogWeb", "(Ljava/lang/String;Ljava/lang/String;)V");
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
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, ANDROIDBRIDGE_CLASS, "openActivityWeb", "(Ljava/lang/String;Ljava/lang/String;)V");
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
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, ANDROIDBRIDGE_CLASS, "closeAccount", "()V");
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
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, ANDROIDBRIDGE_CLASS, "initGameConfig", "(I)V");
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
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, ANDROIDBRIDGE_CLASS, "getConfigValue", "(Ljava/lang/String;)Ljava/lang/String;");
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

// // ?????????????????? ??????????????????
// void CoreAndroid::GetIntegralData() {}
// // ?????????????????? ????????????
// void CoreAndroid::ReportIntegral(std::string json) {}
// // ?????????????????? ??????h5??????
// void CoreAndroid::OpenIntegralActivity() {}

// ?????????????????????
void CoreAndroid::WordFilterUpdate() 
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo methodInfo;
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, ANDROIDBRIDGE_CLASS, "wordFilterUpdate", "()V");
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

// ???????????????
std::string CoreAndroid::WordFilter(std::string sentence) 
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo methodInfo;
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, ANDROIDBRIDGE_CLASS, "wordFilter", "(Ljava/lang/String;)Ljava/lang/String;");
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

// ????????????scene?????????
void CoreAndroid::SetSceneName(std::string name) 
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo methodInfo;
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, ANDROIDBRIDGE_CLASS, "openActivityWeb", "(Ljava/lang/String;)V");
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

// ????????????????????????s
bool CoreAndroid::IsRedeemEnable() 
{ 
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo methodInfo;
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, ANDROIDBRIDGE_CLASS, "redeemEnable", "()Z");
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

// // ??????v2??????????????????
// void CoreAndroid::GetOrderData(std::string outOrderId) {}
// // ??????v2??????????????????
// void CoreAndroid::GetProductData() {}
// // ??????v2???????????????????????????
// void CoreAndroid::GetLostOrderData() {}
// // ??????v2????????????????????????
// void CoreAndroid::UpdateOrderState(std::string orderList) {}
// // ??????v2??????h5???
// void CoreAndroid::OpenNewIntegralActivity(std::string actJson) {}
// // ???????????? ??????h5???
// void CoreAndroid::OpenQuestionH5(std::string winId) {}
// // ???????????? ??????????????????
// void CoreAndroid::GetQuestionWinConfig() {}
// // ???????????? ????????????????????????
// int CoreAndroid::GetQuestionResState() { return 0; }
// // ???????????? ????????????????????????
// void CoreAndroid::GetVerForNet() {}
// // ??????-???????????? ??????h5???
// void CoreAndroid::OpenSurveyH5(std::string winId) {}
// // ??????-???????????? ??????????????????
// void CoreAndroid::GetSurveyWinConfig() {}
// // ??????-???????????? ????????????????????????
// int CoreAndroid::GetSurveyResState() { return 0; }
// // ??????-???????????? ????????????????????????
// void CoreAndroid::GetSurveyVerForNet() {}

// ??????????????????
std::string CoreAndroid::GetBuyChannel() 
{ 
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo methodInfo;
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, ANDROIDBRIDGE_CLASS, "getBuyChannel", "()Ljava/lang/String;");
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

// ??????????????????
std::string CoreAndroid::GetBuyUserId() 
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo methodInfo;
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, ANDROIDBRIDGE_CLASS, "getBuyUserId", "()Ljava/lang/String;");
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

// // ??????v3??????????????????
// void CoreAndroid::GetOrderDataV3(std::string outOrderId) {}
// // ??????v3??????????????????
// void CoreAndroid::GetProductDataV3() {}
// // ??????v3???????????????????????????
// void CoreAndroid::GetLostOrderDataV3() {}
// // ??????v3????????????????????????
// void CoreAndroid::UpdateOrderStateV3(std::string orderList) {}
// // ??????v3??????h5???
// void CoreAndroid::OpenNewIntegralActivityV3(std::string actJson) {}

// ??????Assets???????????????
std::string CoreAndroid::GetAssetsFileData(std::string fileName) 
{ 
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo methodInfo;
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, ANDROIDBRIDGE_CLASS, "getAssetsFileData", "(Ljava/lang/String;)Ljava/lang/String;");
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
/// ??????apk??????????????????
/// </summary>
/// <returns></returns>
std::string CoreAndroid::GetUpdateInfo() 
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo methodInfo;
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, ANDROIDBRIDGE_CLASS, "getUpdateInfo", "()Ljava/lang/String;");
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
/// ??????key??????ConfigVigame.xml?????????
/// </summary>
/// <param name="key">?????????</param>
/// <returns></returns>
std::string CoreAndroid::GetConfigVigameValue(std::string key) 
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo methodInfo;
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, ANDROIDBRIDGE_CLASS, "getConfigVigameValue", "(Ljava/lang/String;)Ljava/lang/String;");
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
// /// ??????unity??????????????????
// /// </summary>
// /// <param name="nodeInfo"></param>
// void CoreAndroid::SetNodeInfo(std::string nodeInfo) {}

// /// <summary>
// /// ??????????????????MD5
// /// </summary>
// /// <returns></returns>
// std::string CoreAndroid::GetSignMd5() { return ""; }

/// <summary>
/// ??????opengl??????
/// </summary>
/// <returns></returns>
std::string CoreAndroid::GetOpenGLVersion() 
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo methodInfo;
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, ANDROIDBRIDGE_CLASS, "getOpenGLVersion", "()Ljava/lang/String;");
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
/// ??????deepLink
/// </summary>
/// <param name="openUrl">deepLink??????</param>
/// <returns>0?????????1??????</returns>
int CoreAndroid::OpenDeepLink(std::string openUrl) 
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo methodInfo;
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, ANDROIDBRIDGE_CLASS, "openDeepLink", "(Ljava/lang/String;)I");
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
/// ???????????????DeepLink??????
/// </summary>
/// <returns>0?????????1??????</returns>
int CoreAndroid::OpenZfbDp() 
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo methodInfo;
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, ANDROIDBRIDGE_CLASS, "openZfbDp", "()I");
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
/// ????????????id
/// </summary>
/// <returns>??????id</returns>
std::string CoreAndroid::GetDnid()
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo methodInfo;
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, ANDROIDBRIDGE_CLASS, "getDnid", "()Ljava/lang/String;");
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
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, ANDROIDBRIDGE_CLASS, "getElapsedRealtime", "()J");
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