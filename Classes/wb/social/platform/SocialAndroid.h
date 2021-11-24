
#ifndef __Social_ADDROID_H__
#define __Social_ADDROID_H__

#include "../interface/SocialBase.h"

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