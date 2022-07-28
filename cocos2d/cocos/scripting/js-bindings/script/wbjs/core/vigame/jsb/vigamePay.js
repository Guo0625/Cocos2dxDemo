/**
 * Created by Zack on 2018/1/9.
 */
var wb = window.wb || {};

wb.PAY_RESULT_OTHER = -4;      //其它
wb.PAY_RESULT_PAYCODERROR = -3;//计费点错误
wb.PAY_RESULT_UNINIT = -2;     //支付尚未初始化
wb.PAY_RESULT_ERROR = -1;      //支付错误
wb.PAY_RESULT_SUCCESS = 0;     //支付成功
wb.PAY_RESULT_FAIL = 1;        //支付失败
wb.PAY_RESULT_CANCEL = 2;      //支付取消

wb.Pay = wb.SysCore.extend(wb.JPay, {});
wb.PayParams = wb.SysCore.extend(wb.JPayParams, {});
wb.FeeItem = wb.SysCore.extend(wb.JFeeItem, {});
wb.FeeInfo = wb.SysCore.extend(wb.JFeeInfo, {});

wb.PayManager = wb.SysCore.extend(wb.JPayManager, {});

wb.PayManager.payCallFuncV = [];

wb.PayManager.payCallFunc = function (payParams) {
    for (var i = 0; i < wb.PayManager.payCallFuncV.length; i++) {
        var func = wb.PayManager.payCallFuncV[i];
        if (func) func(payParams);
    }
};

wb.PayManager.addOnPayFinishCallback = function (func) {
    if (wb.SysPlatform.isNative()) return this.parent.addOnPayFinishCallback(func);

    wb.PayManager.payCallFuncV.push(func);
    return wb.PayManager.payCallFuncV.length - 1;
};

wb.PayManager.removeOnPayFinishCallback = function (id) {
    if (wb.SysPlatform.isNative()) return this.parent.removeOnPayFinishCallback(id);
    wb.PayManager.payCallFuncV[id] = null;
};

wb.PayManager.orderPay = function (id) {
    if (wb.SysPlatform.isNative()) return this.parent.orderPay(id);

    var payParams = {};
    payParams.getPayId = function () {
        return id;
    };
    payParams.getPayResult = function () {
        return wb.PAY_RESULT_SUCCESS;
    };
    this.payCallFunc(payParams);
};

wb.PayManager.orderPay2 = function (id, price) {
    if (wb.SysPlatform.isNative()) return this.parent.orderPay2(id, price);

    var payParams = {};
    payParams.getPayId = function () {
        return id;
    };
    payParams.getPayResult = function () {
        return wb.PAY_RESULT_SUCCESS;
    };
    payParams.getPayPrice = function () {
        return price;
    };
    this.payCallFunc(payParams);
};

wb.PayParams = wb.SysCore.extend(wb.JPayParams, {});
wb.FeeItem = wb.SysCore.extend(wb.JFeeItem, {});
wb.FeeInfo = wb.SysCore.extend(wb.JFeeInfo, {});

