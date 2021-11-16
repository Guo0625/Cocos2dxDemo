#ifndef __HOME_SCENE_H__
#define __HOME_SCENE_H__

#include "cocos2d.h"

class Home : public cocos2d::Layer
{
public:
    // implement the "static create()" method manually
    CREATE_FUNC(Home);
    virtual bool init();
    void adButtonCallBack(Ref* pSender);
    void buttonCallBack(Ref* pSender);
    void payButtonCallBack(Ref* pSender);
    void tjButtonCallBack(Ref* pSender);
};

#endif // __HOME_SCENE_H__
