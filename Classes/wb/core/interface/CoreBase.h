
#ifndef __CORE_BASE_H__
#define __CORE_BASE_H__

#include <string>

#define VIGAME_BEGIN \
    namespace vigame \
    {
#define VIGAME_END }

VIGAME_BEGIN

class CoreBase
{
public:
    virtual void init() = 0;
    virtual void UseCDKey(std::string dhm) = 0;
    virtual bool CDKeyIsSupport() = 0;
    virtual void OpenActivityPage() = 0;
    virtual void OpenActivityNotice() = 0;
    virtual void OpenRank() = 0;
    virtual void OpenUserAgreement() = 0;
    virtual void OpenPrivacyPolicy() = 0;
    virtual void OpenUserAgreementByWeb() = 0;
    virtual void OpenUserAgreementNoCompany() = 0;
    virtual void OpenFeedback() = 0;
    virtual void OpenMarketPlus(std::string url, std::string param) = 0;
    virtual void SumbitRankData(std::string userId, int level, int score, int usedCoins, int leftCoins) = 0;
    virtual void SetGameName(std::string gameName) = 0;

    virtual std::string GetAppName() = 0;
    virtual std::string GetChannel() = 0;
    virtual std::string GetPrjid() = 0;
    virtual std::string GetAppid() = 0;
    virtual std::string GetLsn() = 0;
    virtual std::string GetUuid() = 0;
    virtual std::string GetImsi() = 0;
    virtual std::string GetImei() = 0;
    virtual std::string GetOaid() = 0;
    virtual std::string GetAndroidId() = 0;
    virtual std::string GetAppkey() = 0;
    virtual int GetNetState() = 0;

    virtual std::string GetSignature() = 0;

    virtual std::string GetPackageName() = 0;

    virtual std::string GetVerName() = 0;
    //返回值：true-非审核状态 false-审核中
    virtual bool GetAuditSwitch() = 0;

    virtual std::string GetCustomSwitch(std::string key) = 0;
    virtual bool GetIsHarmonyOs() = 0;
    virtual void OpenUrl(std::string url) = 0;
    virtual void OpenInnerUrl(std::string url) = 0;
    virtual void OpenDialogWeb(std::string url, std::string title) = 0;
    virtual void OpenActivityWeb(std::string url, std::string title) = 0;
    // virtual void NotifyNotification(int id, std::string body, long fireDate, int unitInterval, Dictionary<std::string, std::string> userinfo) = 0;
    // virtual void CancleNotification(int id) = 0;
    // virtual void CancleNotificationAll() = 0;
    // virtual bool Fastmark() = 0;
    // virtual void JumpComment() = 0;
    virtual void CloseAccount() = 0;
    virtual void InitGameConfig(int version) = 0;
    virtual std::string GetConfigValue(std::string key) = 0;
    // // 移动积分兑换 获取积分数据
    // virtual void GetIntegralData() = 0;
    // // 移动积分兑换 上报接口
    // virtual void ReportIntegral(std::string json) = 0;
    // // 移动积分兑换 打开h5界面
    // virtual void OpenIntegralActivity() = 0;
    // 更新敏感词配置
    virtual void WordFilterUpdate() = 0;
    // 处理敏感词
    virtual std::string WordFilter(std::string sentence) = 0;
    // 设置当前scene的名称
    virtual void SetSceneName(std::string name) = 0;
    // 积分模块是否打开s
    virtual bool IsRedeemEnable() = 0;
    // // 积分v2获取订单列表
    // virtual void GetOrderData(std::string outOrderId) = 0;
    // // 积分v2获取商品列表
    // virtual void GetProductData() = 0;
    // // 积分v2获取未发货订单列表
    // virtual void GetLostOrderData() = 0;
    // // 积分v2更新订单列表状态
    // virtual void UpdateOrderState(std::string orderList) = 0;
    // // 积分v2打开h5页
    // virtual void OpenNewIntegralActivity(std::string actJson) = 0;
    // // 问卷调查 打开h5页
    // virtual void OpenQuestionH5(std::string winId) = 0;
    // // 问卷调查 请求弹窗配置
    // virtual void GetQuestionWinConfig() = 0;
    // // 问卷调查 获取资源更新状态
    // virtual int GetQuestionResState() = 0;
    // // 问卷调查 获取问卷调查资源
    // virtual void GetVerForNet() = 0;
    // // 产品-问卷调查 打开h5页
    // virtual void OpenSurveyH5(std::string winId) = 0;
    // // 产品-问卷调查 请求弹窗配置
    // virtual void GetSurveyWinConfig() = 0;
    // // 产品-问卷调查 获取资源更新状态
    // virtual int GetSurveyResState() = 0;
    // // 产品-问卷调查 获取问卷调查资源
    // virtual void GetSurveyVerForNet() = 0;
    // 获取投放渠道
    virtual std::string GetBuyChannel() = 0;
    // 获取投放账户
    virtual std::string GetBuyUserId() = 0;
    // // 积分v3获取订单列表
    // virtual void GetOrderDataV3(std::string outOrderId) = 0;
    // // 积分v3获取商品列表
    // virtual void GetProductDataV3() = 0;
    // // 积分v3获取未发货订单列表
    // virtual void GetLostOrderDataV3() = 0;
    // // 积分v3更新订单列表状态
    // virtual void UpdateOrderStateV3(std::string orderList) = 0;
    // // 积分v3打开h5页
    // virtual void OpenNewIntegralActivityV3(std::string actJson) = 0;

    // 获取Assets下文件内容
    virtual std::string GetAssetsFileData(std::string fileName) = 0;

    /// <summary>
    /// 获取apk更新弹窗信息
    /// </summary>
    /// <returns></returns>
    virtual std::string GetUpdateInfo() = 0;

    /// <summary>
    /// 根据key获取ConfigVigame.xml中的值
    /// </summary>
    /// <param name="key">关键字</param>
    /// <returns></returns>
    virtual std::string GetConfigVigameValue(std::string key) = 0;

    // /// <summary>
    // /// 设置unity当前节点信息
    // /// </summary>
    // /// <param name="nodeInfo"></param>
    // virtual void SetNodeInfo(std::string nodeInfo) = 0;

    // /// <summary>
    // /// 获取签名验证MD5
    // /// </summary>
    // /// <returns></returns>
    // virtual std::string GetSignMd5() = 0;

    /// <summary>
    /// 获取opengl版本
    /// </summary>
    /// <returns></returns>
    virtual std::string GetOpenGLVersion() = 0;

    /// <summary>
    /// 打开deepLink
    /// </summary>
    /// <param name="openUrl">deepLink链接</param>
    /// <returns>0失败；1成功</returns>
    virtual int OpenDeepLink(std::string openUrl) = 0;

    /// <summary>
    /// 打开支付宝DeepLink链接
    /// </summary>
    /// <returns>0失败；1成功</returns>
    virtual int OpenZfbDp() = 0;

    /// <summary>
    /// 获取动能id
    /// </summary>
    /// <returns>动能id</returns>
    virtual std::string GetDnid() = 0;

    virtual unsigned long GetElapsedRealtime() = 0;
};

VIGAME_END
#endif //__CORE_BASE_H__