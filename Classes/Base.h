#ifndef __Base_SCENE_H__
#define __Base_SCENE_H__

#include "cocos2d.h"

class Base : public cocos2d::Layer
{
public:
    // implement the "static create()" method manually
    CREATE_FUNC(Base);
    virtual bool init();
    void backBtnCallBack(Ref* pSender);
    void btn1CallBack(Ref* pSender);
    void btn2CallBack(Ref* pSender);
    void btn3CallBack(Ref* pSender);
    void btn4CallBack(Ref* pSender);
};
#endif // __Base_SCENE_H__