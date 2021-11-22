
#ifndef __Social_ADDROID_H__
#define __Social_ADDROID_H__

#include <string>
#include "../interface/SocialBase.h"
#define VIGAME_BEGIN                     namespace vigame {
#define VIGAME_END                       }

VIGAME_BEGIN

class SocialAndroid:public SocialBase
{
public:
	SocialAndroid();
	~SocialAndroid();
    void init() override;
    void Login(int type) override;
    void GetUserInfo(int type) override;
    bool IsSupportSocialAgent(int socialType) override;
};

VIGAME_END

#endif //__Social_ADDROID_H__