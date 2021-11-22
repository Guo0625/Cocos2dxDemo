#ifndef __Social_SCENE_H__
#define __Social_SCENE_H__

#include "cocos2d.h"

class Social : public cocos2d::Layer
{
public:
    // implement the "static create()" method manually
    CREATE_FUNC(Social);
    virtual bool init();
    void backBtnCallBack(Ref* pSender);
    void btn1CallBack(Ref* pSender);
    void btn2CallBack(Ref* pSender);
    void btn3CallBack(Ref* pSender);
    void btn4CallBack(Ref* pSender);
};
#endif // __Social_SCENE_H__