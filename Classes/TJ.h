#ifndef __TJ_SCENE_H__
#define __TJ_SCENE_H__

#include "cocos2d.h"

class TJ : public cocos2d::Layer
{
public:
    // implement the "static create()" method manually
    CREATE_FUNC(TJ);
    virtual bool init();
    void backBtnCallBack(Ref* pSender);
    void btn1CallBack(Ref* pSender);
    void btn2CallBack(Ref* pSender);
    void btn3CallBack(Ref* pSender);
    void btn4CallBack(Ref* pSender);
    void btn5CallBack(Ref* pSender);
    void btn6CallBack(Ref* pSender);
    void btn7CallBack(Ref* pSender);
    void btn8CallBack(Ref* pSender);
    void btn9CallBack(Ref* pSender);
};
#endif // __TJ_SCENE_H__