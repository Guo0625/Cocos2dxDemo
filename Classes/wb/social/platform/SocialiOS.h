
#ifndef __Social_IOS_H__
#define __Social_IOS_H__

#include <string>
#include "../interface/SocialBase.h"
#define VIGAME_BEGIN                     namespace vigame {
#define VIGAME_END                       }

VIGAME_BEGIN

class SocialiOS:public SocialBase
{
public:
	SocialiOS();
	~SocialiOS();
    void init() override;
    void Login(int type) override;
    void GetUserInfo(int type) override;
    bool IsSupportSocialAgent(int socialType) override;
};

VIGAME_END

#endif //__Social_IOS_H__