#ifndef __AD_MANAGER_H__
#define __AD_MANAGER_H__

#include <string>
#include <map>
#include <queue>
#include <functional>
#include "interface/ADBase.h"

VIGAME_BEGIN

class ADManager
{
public:
	ADManager();
	~ADManager();
	static ADManager* getInstance();
    // Open the general AD
    // Note: you shold close backgroud music when plaque or video open success.
    // the callback of ad result bool：true-open success false-open fail  (note:If the video play complete,flag will be true.)
    // the callback of ad result string: { "adName", "result", "ecpm", "sid", "agentName", "openType", "tradeId" }; split by '#'
	void OpenAd(std::string adName, std::function<void(bool, std::string)> func = nullptr);
    // Open the native AD
    // adName the name of AD position
    // width：width on the screen, in pixels 
    // height：height on the screen, in pixels 
    // x：X in the upper left corner，in pixels 
    // y：Y in the upper left corner，in pixels 
    // the callback same to the OpenAd function
    void OpenYsAd(std::string adName, int width, int height, int x, int y, std::function<void(bool, std::string)> func = nullptr);
    // Close AD
    void CloseAd(std::string adName);
    // IS AD Ready
    bool IsAdReady(std::string adName);
    // Is AD be opened in level
    bool IsAdBeOpenInLevel(std::string adName, int level);
    // Get AD position param
    std::string GetAdPositionParam(std::string adName, std::string param);
    // Is AD type exist
    bool IsAdTypeExist(std::string adType);
    // Get video limit open number
    int GetVideoLimitOpenNum();
    void VideoCallBack(std::string params);
private:
    ADBase* mInterface;
    std::vector<std::string> Split(std::string s, std::string delimiter);
    void AddCallBackFun(std::string positionName, std::function<void(bool, std::string)> func =nullptr);
    std::map<std::string, std::queue<std::function<void(bool, std::string)>>> callbacks;
};

VIGAME_END

#endif //__AD_MANAGER_H__