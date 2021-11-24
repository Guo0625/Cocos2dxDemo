#ifndef __Social_MANAGER_H__
#define __Social_MANAGER_H__

#include <string>
#include <map>
#include <queue>
#include <functional>
#include "interface/SocialBase.h"

VIGAME_BEGIN

// 登录类型
enum LoginType
{
    TYPE_NULL = 0,
    TYPE_WX = 1,
    TYPE_QQ = 2,
    TYPE_FACEBOOK = 3,
    TYPE_MSDK = 4,
    TYPE_AliGame = 5,
    TYPE_Downjoy = 6,
    TYPE_Vivo = 7,
    TYPE_AliPay = 8,
    TYPE_Common = 9
};

class SocialManager
{
public:
	SocialManager();
	~SocialManager();
	static SocialManager* getInstance();

    /**
     * @brief Login
     * 
     * @param type 
     * @param func 
     */
    void Login(LoginType type, std::function<void(bool)> func);

    /**
     * @brief Get the User Info
     * 
     * @param type 
     * @param func 
     */
    void GetUserInfo(LoginType type, std::function<void(bool, std::string)> func);

    /**
     * @brief Login CallBack
     * 
     * @param result 
     */
    void LoginCallBack(std::string result);

    /**
     * @brief Get the User Info CallBack
     * 
     * @param result 
     */
    void GetUserInfoCallBack(std::string result);
    
    /**
     * @brief 是否支持指定社交代理
     * 
     * @param socialType 
     * @return true 
     * @return false 
     */
    bool IsSupportSocialAgent(LoginType socialType);
private:
    SocialBase* mInterface;
    std::function<void(bool)> loginCallFun;
    std::function<void(bool, std::string)> userInfoCallFun;
};

VIGAME_END

#endif //__Social_MANAGER_H__