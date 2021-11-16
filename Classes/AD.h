#ifndef __AD_SCENE_H__
#define __AD_SCENE_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h" 

class AD : public cocos2d::Layer
{
public:
	AD();
	~AD();
    // implement the "static create()" method manually
    CREATE_FUNC(AD);
    virtual bool init();
    void backBtnCallBack(Ref* pSender);
    void splashBtnCallBack(Ref* pSender);
    void bannerBtnCallBack(Ref* pSender);
    void cbannerBtnCallBack(Ref* pSender);
    void pauseBtnCallBack(Ref* pSender);
    void exit_gameBtnCallBack(Ref* pSender);
    void home_mfzsBtnCallBack(Ref* pSender);
    void level_win_mfzsBtnCallBack(Ref* pSender);
    void updateAdStaus(float dt);

private:
	int status;
	Ref* splashBtn;
    Ref* bannerBtn;
    Ref* pauseBtn;
    Ref* exit_gameBtn;
    Ref* home_mfzsBtn;
    Ref* level_win_mfzsBtn;
};

#endif // __AD_SCENE_H__
