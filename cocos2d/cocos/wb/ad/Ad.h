
#ifndef __AD_H__
#define __AD_H__

#include <string>

#define VIGAME_BEGIN                     namespace vigame {
#define VIGAME_END                       }

VIGAME_BEGIN

class ADManager
{
public:
	ADManager();
	~ADManager();
	static ADManager* getInstance();
	void OpenAd(std::string adName);
    void OpenYsAd(std::string adName, int width, int height, int x, int y);
    void CloseAd(std::string adName);
    bool IsAdReady(std::string adName);
    bool IsAdBeOpenInLevel(std::string adName, int level);
    std::string GetAdPositionParam(std::string adName, std::string param);
    bool IsAdTypeExist(std::string adType);
    int GetVideoLimitOpenNum();
};

VIGAME_END
#endif //__AD_H__