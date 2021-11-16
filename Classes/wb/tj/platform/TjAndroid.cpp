#include "TjAndroid.h"
#include "cocos2d.h"

VIGAME_BEGIN

TjAndroid::TjAndroid()
{
}

TjAndroid::~TjAndroid()
{
}

void TjAndroid::init()
{
}

void TjAndroid::TJCustomEvent(std::string eventId)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo methodInfo;
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, "com/vimedia/game/AndroidBridge", "TJCustomEvent", "(Ljava/lang/String;)V");
	if (isExist)
	{
		jstring str = methodInfo.env->NewStringUTF(eventId.c_str());						//create jstring
		methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, str); //call Java method
		methodInfo.env->DeleteLocalRef(str);
		methodInfo.env->ExceptionClear();
	}
	else
	{
		cocos2d::log("Tj jni get TJCustomEvent function error");
	}
#endif
}

void TjAndroid::TJCustomEvent(std::string eventId, std::string attributes)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo methodInfo;
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, "com/vimedia/game/AndroidBridge", "TJCustomEvent", "(Ljava/lang/String;Ljava/lang/String;)V");
	if (isExist)
	{
		jstring str1 = methodInfo.env->NewStringUTF(eventId.c_str());							   //create jstring
		jstring str2 = methodInfo.env->NewStringUTF(attributes.c_str());						   //create jstring
		methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, str1, str2); //call Java method
		methodInfo.env->DeleteLocalRef(str1);
		methodInfo.env->DeleteLocalRef(str2);
		methodInfo.env->ExceptionClear();
	}
	else
	{
		cocos2d::log("Tj jni get TJCustomEvent function error");
	}
#endif
}

void TjAndroid::TJCustomEvent(std::string eventId, std::unordered_map<std::string, std::string> attributes)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo methodInfo;
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, "com/vimedia/game/AndroidBridge", "TJCustomEvent", "(Ljava/lang/String;Ljava/util/HashMap;)V");
	if (isExist)
	{
		jstring str = methodInfo.env->NewStringUTF(eventId.c_str()); //create jstring
		jobject jobject_attributes = nullptr;
		jclass jclass_hashmap = methodInfo.env->FindClass("java/util/HashMap");
		if (jclass_hashmap)
		{
			jmethodID jmethodID_hashmap_init = methodInfo.env->GetMethodID(jclass_hashmap, "<init>", "()V");
			jmethodID jmethodID_hashmap_put = methodInfo.env->GetMethodID(jclass_hashmap, "put", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;");
			if (jmethodID_hashmap_put && jmethodID_hashmap_init && jmethodID_hashmap_put)
			{
				jobject_attributes = methodInfo.env->NewObject(jclass_hashmap, jmethodID_hashmap_init, "");
				std::for_each(attributes.begin(), attributes.end(), [&](auto values)
				{
					std::string key = values.first;
					std::string value = values.second;
					jstring jstring_key = methodInfo.env->NewStringUTF(key.c_str());
					jstring jstring_value = methodInfo.env->NewStringUTF(value.c_str());
					methodInfo.env->CallObjectMethod(jobject_attributes, jmethodID_hashmap_put, jstring_key, jstring_value);
					methodInfo.env->DeleteLocalRef(jstring_key);
					methodInfo.env->DeleteLocalRef(jstring_value);
				});
			}
		}
		methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, str, jobject_attributes); //call Java method
		methodInfo.env->DeleteLocalRef(str);
		methodInfo.env->DeleteLocalRef(jobject_attributes);
		methodInfo.env->ExceptionClear();
	}
	else
	{
		cocos2d::log("Tj jni get TJCustomEvent function error");
	}
#endif
}

void TjAndroid::TJEventValue(std::string eventId, std::string attributes, int duration)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo methodInfo;
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, "com/vimedia/game/AndroidBridge", "TJEventValue", "(Ljava/lang/String;Ljava/lang/String;I)V");
	if (isExist)
	{
		jstring str1 = methodInfo.env->NewStringUTF(eventId.c_str());										 //create jstring
		jstring str2 = methodInfo.env->NewStringUTF(attributes.c_str());									 //create jstring
		methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, str1, str2, duration); //call Java method
		methodInfo.env->DeleteLocalRef(str1);
		methodInfo.env->DeleteLocalRef(str2);
		methodInfo.env->ExceptionClear();
	}
	else
	{
		cocos2d::log("Tj jni get TJCustomEvent function error");
	}
#endif
}

void TjAndroid::TJEventValue(std::string eventId, std::unordered_map<std::string, std::string> attributes, int duration)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo methodInfo;
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, "com/vimedia/game/AndroidBridge", "TJEventValue", "(Ljava/lang/String;Ljava/util/HashMap;I)V");
	if (isExist)
	{
		jstring str = methodInfo.env->NewStringUTF(eventId.c_str()); //create jstring
		jobject jobject_attributes = nullptr;
		jclass jclass_hashmap = methodInfo.env->FindClass("java/util/HashMap");
		if (jclass_hashmap)
		{
			jmethodID jmethodID_hashmap_init = methodInfo.env->GetMethodID(jclass_hashmap, "<init>", "()V");
			jmethodID jmethodID_hashmap_put = methodInfo.env->GetMethodID(jclass_hashmap, "put", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;");
			if (jmethodID_hashmap_put && jmethodID_hashmap_init && jmethodID_hashmap_put)
			{
				jobject_attributes = methodInfo.env->NewObject(jclass_hashmap, jmethodID_hashmap_init, "");
				std::for_each(attributes.begin(), attributes.end(), [&](auto values)
				{
					std::string key = values.first;
					std::string value = values.second;
					jstring jstring_key = methodInfo.env->NewStringUTF(key.c_str());
					jstring jstring_value = methodInfo.env->NewStringUTF(value.c_str());
					methodInfo.env->CallObjectMethod(jobject_attributes, jmethodID_hashmap_put, jstring_key, jstring_value);
					methodInfo.env->DeleteLocalRef(jstring_key);
					methodInfo.env->DeleteLocalRef(jstring_value);
				});
			}
		}
		methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, str, jobject_attributes, duration); //call Java method
		methodInfo.env->DeleteLocalRef(str);
		methodInfo.env->DeleteLocalRef(jobject_attributes);
		methodInfo.env->ExceptionClear();
	}
	else
	{
		cocos2d::log("Tj jni get TJEventValue function error");
	}
#endif
}

void TjAndroid::StartLevel(std::string level)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo methodInfo;
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, "com/vimedia/game/AndroidBridge", "startLevel", "(Ljava/lang/String;)V");
	if (isExist)
	{
		jstring str = methodInfo.env->NewStringUTF(level.c_str());							//create jstring
		methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, str); //call Java method
		methodInfo.env->DeleteLocalRef(str);
		methodInfo.env->ExceptionClear();
	}
	else
	{
		cocos2d::log("Tj jni get StartLevel function error");
	}
#endif
}

void TjAndroid::FinishLevel(std::string level, std::string score)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo methodInfo;
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, "com/vimedia/game/AndroidBridge", "finishLevel", "(Ljava/lang/String;Ljava/lang/String;)V");
	if (isExist)
	{
		jstring str1 = methodInfo.env->NewStringUTF(level.c_str());								   //create jstring
		jstring str2 = methodInfo.env->NewStringUTF(score.c_str());								   //create jstring
		methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, str1, str2); //call Java method
		methodInfo.env->DeleteLocalRef(str1);
		methodInfo.env->DeleteLocalRef(str2);
		methodInfo.env->ExceptionClear();
	}
	else
	{
		cocos2d::log("Tj jni get FinishLevel function error");
	}
#endif
}

void TjAndroid::FailLevel(std::string level, std::string score)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo methodInfo;
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, "com/vimedia/game/AndroidBridge", "failLevel", "(Ljava/lang/String;Ljava/lang/String;)V");
	if (isExist)
	{
		jstring str1 = methodInfo.env->NewStringUTF(level.c_str());								   //create jstring
		jstring str2 = methodInfo.env->NewStringUTF(score.c_str());								   //create jstring
		methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, str1, str2); //call Java method
		methodInfo.env->DeleteLocalRef(str1);
		methodInfo.env->DeleteLocalRef(str2);
		methodInfo.env->ExceptionClear();
	}
	else
	{
		cocos2d::log("Tj jni get FailLevel function error");
	}
#endif
}

void TjAndroid::TJPay(double money, double coin, int source)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo methodInfo;
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, "com/vimedia/game/AndroidBridge", "TJPay", "(DDI)V");
	if (isExist)
	{
		methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, money, coin, source); //call Java method
		methodInfo.env->ExceptionClear();
	}
	else
	{
		cocos2d::log("Tj jni get TJPay function error");
	}
#endif
}

void TjAndroid::TJPayAndBuy(double money, std::string item, int number, double price, int source)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo methodInfo;
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, "com/vimedia/game/AndroidBridge", "TJPayAndBuy", "(DLjava/lang/String;IDI)V");
	if (isExist)
	{
		jstring str = methodInfo.env->NewStringUTF(item.c_str());
		methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, money, str, number, price, source); //call Java method
		methodInfo.env->DeleteLocalRef(str);
		methodInfo.env->ExceptionClear();
	}
	else
	{
		cocos2d::log("Tj jni get TJPayAndBuy function error");
	}
#endif
}

void TjAndroid::onPageStart(std::string sid)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo methodInfo;
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, "com/vimedia/game/AndroidBridge", "onPageStart", "(Ljava/lang/String;)V");
	if (isExist)
	{
		jstring str = methodInfo.env->NewStringUTF(sid.c_str());							//create jstring
		methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, str); //call Java method
		methodInfo.env->DeleteLocalRef(str);
		methodInfo.env->ExceptionClear();
	}
	else
	{
		cocos2d::log("Tj jni get onPageStart function error");
	}
#endif
}

void TjAndroid::onPageEnd(std::string sid)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo methodInfo;
	bool isExist = cocos2d::JniHelper::getStaticMethodInfo(methodInfo, "com/vimedia/game/AndroidBridge", "onPageEnd", "(Ljava/lang/String;)V");
	if (isExist)
	{
		jstring str = methodInfo.env->NewStringUTF(sid.c_str());							//create jstring
		methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, str); //call Java method
		methodInfo.env->DeleteLocalRef(str);
		methodInfo.env->ExceptionClear();
	}
	else
	{
		cocos2d::log("Tj jni get onPageEnd function error");
	}
#endif
}

VIGAME_END