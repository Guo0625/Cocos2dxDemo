
#ifndef __Social_BASE_H__
#define __Social_BASE_H__

#include "../../utils/macros.h"

VIGAME_BEGIN

class SocialBase
{
public:
    virtual void init() = 0;
    virtual void Login(int type) = 0;
    virtual void GetUserInfo(int type) = 0;
    // virtual void Share(Dictionary<string, string> attributes) = 0;
    virtual bool IsSupportSocialAgent(int socialType) = 0;
};

VIGAME_END

#endif //__Social_BASE_H__