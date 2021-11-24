#ifndef __Core_MANAGER_H__
#define __Core_MANAGER_H__

#include <string>
#include <map>
#include <queue>
#include <functional>
#include "interface/CoreBase.h"

VIGAME_BEGIN


enum CDKeyState
{
    UnUse = -1, // -1 异常，未使用
    UnExist = 0, // 0兑换码不存在
    Success = 1, // 1成功
    Repeat = 2, // 2不能重复使用
    ParamError = 3, // 3参数错误
    NetError = 4, // 4网络错误
};

class CoreManager
{
public:
	CoreManager();
	~CoreManager();
	static CoreManager* getInstance();
	void UseCDKey(std::string dhm, std::function<void(CDKeyState, std::string, std::string)> func);
    bool CDKeyIsSupport();
    void OpenActivityPage();
    void OpenActivityNotice();
    void OpenRank();
    void OpenUserAgreement();
    void OpenPrivacyPolicy();
    void OpenUserAgreementByWeb();
    void OpenUserAgreementNoCompany();
    void OpenFeedback();
    void OpenMarketPlus(std::string url, std::string param);
    void SumbitRankData(std::string userId, int level, int score, int usedCoins, int leftCoins);
    void SetGameName(std::string gameName);

    std::string GetAppName();
    std::string GetChannel();
    std::string GetPrjid();
    std::string GetAppid();
    std::string GetLsn();
    std::string GetUuid();
    std::string GetImsi();
    std::string GetImei();
    std::string GetOaid();
    std::string GetAndroidId();
    std::string GetAppkey();
    int GetNetState();
    std::string GetSignature();
    std::string GetPackageName();
    std::string GetVerName();
    //返回值：true-非审核状态 false-审核中
    bool GetAuditSwitch();
    /// <summary>
    /// 获取动能id
    /// </summary>
    /// <returns>动能id</returns>
    std::string GetDnid();

    std::string GetCustomSwitch(std::string key);
    bool GetIsHarmonyOs();
    void OpenUrl(std::string url);
    void OpenInnerUrl(std::string url);
    void OpenDialogWeb(std::string url, std::string title);
    void OpenActivityWeb(std::string url, std::string title);
    // void NotifyNotification(int id, std::string body, long fireDate, int unitInterval, Dictionary<std::string, std::string> userinfo);
    // void CancleNotification(int id);
    // void CancleNotificationAll();
    // bool Fastmark();
    // void JumpComment();
    void CloseAccount();
    void InitGameConfig(int version);
    std::string GetConfigValue(std::string key);
    // // 移动积分兑换 获取积分数据
    // void GetIntegralData();
    // // 移动积分兑换 上报接口
    // void ReportIntegral(std::string json);
    // // 移动积分兑换 打开h5界面
    // void OpenIntegralActivity();
    // 更新敏感词配置
    void WordFilterUpdate();
    // 处理敏感词
    std::string WordFilter(std::string sentence);
    // 设置当前scene的名称
    void SetSceneName(std::string name);
    // 积分模块是否打开s
    bool IsRedeemEnable();
    // // 积分v2获取订单列表
    // void GetOrderData(std::string outOrderId);
    // // 积分v2获取商品列表
    // void GetProductData();
    // // 积分v2获取未发货订单列表
    // void GetLostOrderData();
    // // 积分v2更新订单列表状态
    // void UpdateOrderState(std::string orderList);
    // // 积分v2打开h5页
    // void OpenNewIntegralActivity(std::string actJson);
    // // 问卷调查 打开h5页
    // void OpenQuestionH5(std::string winId);
    // // 问卷调查 请求弹窗配置
    // void GetQuestionWinConfig();
    // // 问卷调查 获取资源更新状态
    // int GetQuestionResState();
    // // 问卷调查 获取问卷调查资源
    // void GetVerForNet();
    // // 产品-问卷调查 打开h5页
    // void OpenSurveyH5(std::string winId);
    // // 产品-问卷调查 请求弹窗配置
    // void GetSurveyWinConfig();
    // // 产品-问卷调查 获取资源更新状态
    // int GetSurveyResState();
    // // 产品-问卷调查 获取问卷调查资源
    // void GetSurveyVerForNet();
    // 获取投放渠道
    std::string GetBuyChannel();
    // 获取投放账户
    std::string GetBuyUserId();
    // // 积分v3获取订单列表
    // void GetOrderDataV3(std::string outOrderId);
    // // 积分v3获取商品列表
    // void GetProductDataV3();
    // // 积分v3获取未发货订单列表
    // void GetLostOrderDataV3();
    // // 积分v3更新订单列表状态
    // void UpdateOrderStateV3(std::string orderList);
    // // 积分v3打开h5页
    // void OpenNewIntegralActivityV3(std::string actJson);

    // 获取Assets下文件内容
    std::string GetAssetsFileData(std::string fileName);

    /// <summary>
    /// 获取apk更新弹窗信息
    /// </summary>
    /// <returns></returns>
    std::string GetUpdateInfo();

    /// <summary>
    /// 根据key获取ConfigVigame.xml中的值
    /// </summary>
    /// <param name="key">关键字</param>
    /// <returns></returns>
    std::string GetConfigVigameValue(std::string key);

    // /// <summary>
    // /// 设置unity当前节点信息
    // /// </summary>
    // /// <param name="nodeInfo"></param>
    // void SetNodeInfo(std::string nodeInfo);

    // /// <summary>
    // /// 获取签名验证MD5
    // /// </summary>
    // /// <returns></returns>
    // std::string GetSignMd5();

    /// <summary>
    /// 获取opengl版本
    /// </summary>
    /// <returns></returns>
    std::string GetOpenGLVersion();

    /// <summary>
    /// 打开deepLink
    /// </summary>
    /// <param name="openUrl">deepLink链接</param>
    /// <returns>0失败；1成功</returns>
    int OpenDeepLink(std::string openUrl);

    /// <summary>
    /// 打开支付宝DeepLink链接
    /// </summary>
    /// <returns>0失败；1成功</returns>
    int OpenZfbDp();

    /**
     * @brief 获取 开机时间.
     * 
     * @return long 
     */
    unsigned long GetElapsedRealtime();

    /**
     * @brief 兑换码回调
     * 
     * @param params 
     */
    void CDKeyCallBack(std::string params);
private:
    CoreBase* mInterface;
    std::function<void(CDKeyState, std::string, std::string)> cdKeyCallFun;
};

VIGAME_END

#endif //__Core_MANAGER_H__