
#ifndef __AD_ADDROID_H__
#define __AD_ADDROID_H__

#include "../interface/ADBase.h"

VIGAME_BEGIN

class ADAndroid:public ADBase
{
public:
	ADAndroid();
	~ADAndroid();
    void init() override;
	void OpenAd(std::string adName) override;
    void OpenYsAd(std::string adName, int width, int height, int x, int y) override;
    void CloseAd(std::string adName) override;
    bool IsAdReady(std::string adName) override;
    bool IsAdBeOpenInLevel(std::string adName, int level) override;
    std::string GetAdPositionParam(std::string adName, std::string param) override;
    bool IsAdTypeExist(std::string adType) override;
    int GetVideoLimitOpenNum() override;
};

VIGAME_END
#endif //__AD_ADDROID_H__