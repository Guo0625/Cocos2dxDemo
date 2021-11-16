#include "cocos2d.h"
#include "ADManager.h"
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#include "platform/ADAndroid.h"
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
#include "platform/ADiOS.h"
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
#include "platform/ADPc.h"
#endif

VIGAME_BEGIN
ADManager *ADManager::getInstance()
{
	static std::unique_ptr<ADManager> s_instance;
	static std::once_flag s_instance_created;
	std::call_once(s_instance_created, [=]
				   { s_instance = std::make_unique<ADManager>(); });
	return s_instance.get();
}

ADManager::ADManager()
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	mInterface = new vigame::ADAndroid();
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	mInterface = new vigame::ADiOS();
#else
	mInterface = new vigame::ADPc();
#endif
	mInterface->init();
}

ADManager::~ADManager()
{

}

void ADManager::OpenAd(std::string adName, std::function<void(bool, std::string)> func)
{
	AddCallBackFun(adName, func);
	mInterface->OpenAd(adName);
}

void ADManager::OpenYsAd(std::string adName, int width, int height, int x, int y, std::function<void(bool, std::string)> func)
{
	AddCallBackFun(adName, func);
	mInterface->OpenYsAd(adName, width, height, x, y);
}

void ADManager::CloseAd(std::string adName)
{
	mInterface->CloseAd(adName);
}

bool ADManager::IsAdReady(std::string adName)
{
	return mInterface->IsAdReady(adName);
}

bool ADManager::IsAdBeOpenInLevel(std::string adName, int level)
{
	return mInterface->IsAdBeOpenInLevel(adName, level);
}

std::string ADManager::GetAdPositionParam(std::string adName, std::string param)
{
	return mInterface->GetAdPositionParam(adName, param);
}

bool ADManager::IsAdTypeExist(std::string adType)
{
	return mInterface->IsAdTypeExist(adType);
}

int ADManager::GetVideoLimitOpenNum()
{
	return mInterface->GetVideoLimitOpenNum();
}

void ADManager::AddCallBackFun(std::string positionName, std::function<void(bool, std::string)> func)
{
	if (func == nullptr)
	{
		return;
	}
	this->callbacks[positionName].push(func);
}

std::vector<std::string> ADManager::Split(std::string str, std::string pattern)
{
    std::vector<std::string> res;
    if(str == "") return res;
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

void ADManager::VideoCallBack(std::string params)
{
	cocos2d::log("VideoCallBack params = %s", params.c_str());
	// "positionName", "result", "ecpm", "sid", "agentName", "openType", "tradeId"
	std::vector<std::string> tokens = this->Split(params, "#");
	if (callbacks.size() == 0) return;
	if (callbacks.find(tokens[0]) == callbacks.end()) return;
	if (callbacks[tokens[0]].size() == 0) return;
	std::function<void(bool, std::string)> func = callbacks[tokens[0]].front();
	if (tokens[1] == "true")
	{
		func(true, params);
	} else {
		func(false, params);
	}
	callbacks[tokens[0]].pop();
}

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
extern "C"
{
	JNIEXPORT void Java_com_vimedia_cocos2dxbridge_Cocos2dxWbActivity_VideoCallBack(JNIEnv *env, jobject thiz, jstring jparams)
	{
		std::string params = cocos2d::JniHelper::jstring2string(jparams);
		vigame::ADManager::getInstance()->VideoCallBack(params);
	}
}

#endif

VIGAME_END