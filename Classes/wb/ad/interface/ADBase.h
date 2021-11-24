
#ifndef __AD_BASE_H__
#define __AD_BASE_H__

#include "../../utils/macros.h"

VIGAME_BEGIN

class ADBase
{
public:
    virtual void init()=0;
	virtual void OpenAd(std::string adName) = 0;
    virtual void OpenYsAd(std::string adName, int width, int height, int x, int y) = 0;
    virtual void CloseAd(std::string adName) = 0;
    virtual bool IsAdReady(std::string adName) = 0;
    virtual bool IsAdBeOpenInLevel(std::string adName, int level) = 0;
    virtual std::string GetAdPositionParam(std::string adName, std::string param) = 0;
    virtual bool IsAdTypeExist(std::string adType) = 0;
    virtual int GetVideoLimitOpenNum() = 0;
};

VIGAME_END
#endif //__AD_BASE_H__