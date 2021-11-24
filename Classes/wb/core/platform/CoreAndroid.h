
#ifndef __CORE_ADDROID_H__
#define __CORE_ADDROID_H__

#include "../interface/CoreBase.h"

VIGAME_BEGIN

class CoreAndroid:public CoreBase
{
public:
	CoreAndroid();
	~CoreAndroid();
    void init() override;
	void UseCDKey(std::string dhm) override;
    bool CDKeyIsSupport() override;
    void OpenActivityPage() override;
    void OpenActivityNotice() override;
    void OpenRank() override;
    void OpenUserAgreement() override;
    void OpenPrivacyPolicy() override;
    void OpenUserAgreementByWeb() override;
    void OpenUserAgreementNoCompany() override;
    void OpenFeedback() override;
    void OpenMarketPlus(std::string url, std::string param) override;
    void SumbitRankData(std::string userId, int level, int score, int usedCoins, int leftCoins) override;
    void SetGameName(std::string gameName) override;

    std::string GetAppName() override;
    std::string GetChannel() override;
    std::string GetPrjid() override;
    std::string GetAppid() override;
    std::string GetLsn() override;
    std::string GetUuid() override;
    std::string GetImsi() override;
    std::string GetImei() override;
    std::string GetOaid() override;
    std::string GetAndroidId() override;
    std::string GetAppkey() override;
    int GetNetState() override;

    std::string GetSignature() override;

    std::string GetPackageName() override;

    std::string GetVerName() override;
    //返回值：true-非审核状态 false-审核中
    bool GetAuditSwitch() override;

    std::string GetCustomSwitch(std::string key) override;
    bool GetIsHarmonyOs() override;
    void OpenUrl(std::string url) override;
    void OpenInnerUrl(std::string url) override;
    void OpenDialogWeb(std::string url, std::string title) override;
    void OpenActivityWeb(std::string url, std::string title) override;
    // void NotifyNotification(int id, std::string body, long fireDate, int unitInterval, Dictionary<std::string, std::string> userinfo) override;
    // void CancleNotification(int id) override;
    // void CancleNotificationAll() override;
    // bool Fastmark() override;
    // void JumpComment() override;
    void CloseAccount() override;
    void InitGameConfig(int version) override;
    std::string GetConfigValue(std::string key) override;
    // // 移动积分兑换 获取积分数据
    // void GetIntegralData() override;
    // // 移动积分兑换 上报接口
    // void ReportIntegral(std::string json) override;
    // // 移动积分兑换 打开h5界面
    // void OpenIntegralActivity() override;
    // 更新敏感词配置
    void WordFilterUpdate() override;
    // 处理敏感词
    std::string WordFilter(std::string sentence) override;
    // 设置当前scene的名称
    void SetSceneName(std::string name) override;
    // 积分模块是否打开s
    bool IsRedeemEnable() override;
    // // 积分v2获取订单列表
    // void GetOrderData(std::string outOrderId) override;
    // // 积分v2获取商品列表
    // void GetProductData() override;
    // // 积分v2获取未发货订单列表
    // void GetLostOrderData() override;
    // // 积分v2更新订单列表状态
    // void UpdateOrderState(std::string orderList) override;
    // // 积分v2打开h5页
    // void OpenNewIntegralActivity(std::string actJson) override;
    // // 问卷调查 打开h5页
    // void OpenQuestionH5(std::string winId) override;
    // // 问卷调查 请求弹窗配置
    // void GetQuestionWinConfig() override;
    // // 问卷调查 获取资源更新状态
    // int GetQuestionResState() override;
    // // 问卷调查 获取问卷调查资源
    // void GetVerForNet() override;
    // // 产品-问卷调查 打开h5页
    // void OpenSurveyH5(std::string winId) override;
    // // 产品-问卷调查 请求弹窗配置
    // void GetSurveyWinConfig() override;
    // // 产品-问卷调查 获取资源更新状态
    // int GetSurveyResState() override;
    // // 产品-问卷调查 获取问卷调查资源
    // void GetSurveyVerForNet() override;
    // 获取投放渠道
    std::string GetBuyChannel() override;
    // 获取投放账户
    std::string GetBuyUserId() override;
    // // 积分v3获取订单列表
    // void GetOrderDataV3(std::string outOrderId) override;
    // // 积分v3获取商品列表
    // void GetProductDataV3() override;
    // // 积分v3获取未发货订单列表
    // void GetLostOrderDataV3() override;
    // // 积分v3更新订单列表状态
    // void UpdateOrderStateV3(std::string orderList) override;
    // // 积分v3打开h5页
    // void OpenNewIntegralActivityV3(std::string actJson) override;

    // 获取Assets下文件内容
    std::string GetAssetsFileData(std::string fileName) override;

    /// <summary>
    /// 获取apk更新弹窗信息
    /// </summary>
    /// <returns></returns>
    std::string GetUpdateInfo() override;

    /// <summary>
    /// 根据key获取ConfigVigame.xml中的值
    /// </summary>
    /// <param name="key">关键字</param>
    /// <returns></returns>
    std::string GetConfigVigameValue(std::string key) override;

    // /// <summary>
    // /// 设置unity当前节点信息
    // /// </summary>
    // /// <param name="nodeInfo"></param>
    // void SetNodeInfo(std::string nodeInfo) override;

    // /// <summary>
    // /// 获取签名验证MD5
    // /// </summary>
    // /// <returns></returns>
    // std::string GetSignMd5() override;

    /// <summary>
    /// 获取opengl版本
    /// </summary>
    /// <returns></returns>
    std::string GetOpenGLVersion() override;

    /// <summary>
    /// 打开deepLink
    /// </summary>
    /// <param name="openUrl">deepLink链接</param>
    /// <returns>0失败；1成功</returns>
    int OpenDeepLink(std::string openUrl) override;

    /// <summary>
    /// 打开支付宝DeepLink链接
    /// </summary>
    /// <returns>0失败；1成功</returns>
    int OpenZfbDp() override;

    /// <summary>
    /// 获取动能id
    /// </summary>
    /// <returns>动能id</returns>
    std::string GetDnid() override;

    unsigned long GetElapsedRealtime() override;
};

VIGAME_END

#endif //__CORE_ADDROID_H__