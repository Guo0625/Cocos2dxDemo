/**
 * @module jsbPay
 */
var wb = wb || {};

/**
 * @class JPay
 */
wb.JPay = {

/**
 * @method init
 */
init : function (
)
{
},

};

/**
 * @class JPayParams
 */
wb.JPayParams = {

/**
 * @method getGiftCoinNum
 * @return {int}
 */
getGiftCoinNum : function (
)
{
    return 0;
},

/**
 * @method getUserdata
 * @return {String}
 */
getUserdata : function (
)
{
    return ;
},

/**
 * @method getReason
 * @return {String}
 */
getReason : function (
)
{
    return ;
},

/**
 * @method getReasonCode
 * @return {String}
 */
getReasonCode : function (
)
{
    return ;
},

/**
 * @method getPayTimes
 * @return {int}
 */
getPayTimes : function (
)
{
    return 0;
},

/**
 * @method getGiftCoinPercent
 * @return {float}
 */
getGiftCoinPercent : function (
)
{
    return 0;
},

/**
 * @method getDiscount
 * @return {float}
 */
getDiscount : function (
)
{
    return 0;
},

/**
 * @method init
 * @return {bool}
 */
init : function (
)
{
    return false;
},

/**
 * @method getPayResult
 * @return {int}
 */
getPayResult : function (
)
{
    return 0;
},

/**
 * @method getTradeId
 * @return {String}
 */
getTradeId : function (
)
{
    return ;
},

/**
 * @method getPayPrice
 * @return {int}
 */
getPayPrice : function (
)
{
    return 0;
},

/**
 * @method getPayDesc
 * @return {String}
 */
getPayDesc : function (
)
{
    return ;
},

/**
 * @method getPayType
 * @return {int}
 */
getPayType : function (
)
{
    return 0;
},

/**
 * @method getPayId
 * @return {int}
 */
getPayId : function (
)
{
    return 0;
},

/**
 * @method getPayCode
 * @return {String}
 */
getPayCode : function (
)
{
    return ;
},

/**
 * @method create
 * @return {wb.JPayParams}
 */
create : function (
)
{
    return wb.JPayParams;
},

};

/**
 * @class JFeeItem
 */
wb.JFeeItem = {

/**
 * @method getCode
 * @return {String}
 */
getCode : function (
)
{
    return ;
},

/**
 * @method getDesc
 * @return {String}
 */
getDesc : function (
)
{
    return ;
},

/**
 * @method getGiftCoinPercent
 * @return {float}
 */
getGiftCoinPercent : function (
)
{
    return 0;
},

/**
 * @method getID
 * @return {int}
 */
getID : function (
)
{
    return 0;
},

/**
 * @method init
 * @return {bool}
 */
init : function (
)
{
    return false;
},

/**
 * @method getPrice
 * @return {int}
 */
getPrice : function (
)
{
    return 0;
},

/**
 * @method create
 * @return {wb.JFeeItem}
 */
create : function (
)
{
    return wb.JFeeItem;
},

};

/**
 * @class JFeeInfo
 */
wb.JFeeInfo = {

/**
 * @method getFeeItemByCode
 * @param {String} arg0
 * @return {wb.JFeeItem}
 */
getFeeItemByCode : function (
str 
)
{
    return wb.JFeeItem;
},

/**
 * @method getValueForKey
 * @param {char} arg0
 * @return {char}
 */
getValueForKey : function (
char 
)
{
    return 0;
},

/**
 * @method getFeePriceByID
 * @param {int} arg0
 * @return {int}
 */
getFeePriceByID : function (
int 
)
{
    return 0;
},

/**
 * @method getFeeItem
* @param {int|int} int
* @param {int} int
* @return {wb.JFeeItem|wb.JFeeItem}
*/
getFeeItem : function(
int,
int 
)
{
    return wb.JFeeItem;
},

/**
 * @method getValues
 * @return {map_object}
 */
getValues : function (
)
{
    return map_object;
},

/**
 * @method init
 * @return {bool}
 */
init : function (
)
{
    return false;
},

/**
 * @method getFeeItems
 * @return {Array}
 */
getFeeItems : function (
)
{
    return new Array();
},

/**
 * @method create
 * @return {wb.JFeeInfo}
 */
create : function (
)
{
    return wb.JFeeInfo;
},

};

/**
 * @class JPayManager
 */
wb.JPayManager = {

/**
 * @method openExitGame
 */
openExitGame : function (
)
{
},

/**
 * @method addOnPayFinishCallback
 * @param {function} arg0
 * @return {int}
 */
addOnPayFinishCallback : function (
func 
)
{
    return 0;
},

/**
 * @method getDefaultFeeInfo
 * @return {wb.JFeeInfo}
 */
getDefaultFeeInfo : function (
)
{
    return wb.JFeeInfo;
},

/**
 * @method getDefaultPayTypes
 * @return {Array}
 */
getDefaultPayTypes : function (
)
{
    return new Array();
},

/**
 * @method removeOnPayFinishCallback
 * @param {int} arg0
 */
removeOnPayFinishCallback : function (
int 
)
{
},

/**
 * @method orderPay4
 * @param {int} arg0
 * @param {int} arg1
 * @param {int} arg2
 * @param {String} arg3
 */
orderPay4 : function (
int, 
int, 
int, 
str 
)
{
},

/**
 * @method orderPay3
 * @param {int} arg0
 * @param {int} arg1
 * @param {String} arg2
 */
orderPay3 : function (
int, 
int, 
str 
)
{
},

/**
 * @method openMoreGame
 */
openMoreGame : function (
)
{
},

/**
 * @method orderPayByType
 * @param {int} arg0
 * @param {int} arg1
 */
orderPayByType : function (
int, 
int 
)
{
},

/**
 * @method isMoreGame
 * @return {bool}
 */
isMoreGame : function (
)
{
    return false;
},

/**
 * @method orderPay2
 * @param {int} arg0
 * @param {int} arg1
 */
orderPay2 : function (
int, 
int 
)
{
},

/**
 * @method init
 */
init : function (
)
{
},

/**
 * @method getFeeInfo
 * @param {int} arg0
 * @return {wb.JFeeInfo}
 */
getFeeInfo : function (
int 
)
{
    return wb.JFeeInfo;
},

/**
 * @method setPayFeeInfoChangedCallback
 * @param {function} arg0
 */
setPayFeeInfoChangedCallback : function (
func 
)
{
},

/**
 * @method setOnPayFinishCallback
 * @param {function} arg0
 */
setOnPayFinishCallback : function (
func 
)
{
},

/**
 * @method getGiftCtrlFlagUse
 * @param {int} arg0
 * @return {int}
 */
getGiftCtrlFlagUse : function (
int 
)
{
    return 0;
},

/**
 * @method getPayOperator
 * @return {int}
 */
getPayOperator : function (
)
{
    return 0;
},

/**
 * @method getGiftCtrlFlag
 * @param {int} arg0
 * @return {int}
 */
getGiftCtrlFlag : function (
int 
)
{
    return 0;
},

/**
 * @method isCtrlGiftEnable
 * @return {bool}
 */
isCtrlGiftEnable : function (
)
{
    return false;
},

/**
 * @method orderPay
 * @param {int} arg0
 */
orderPay : function (
int 
)
{
},

/**
 * @method getMarketType
 * @return {int}
 */
getMarketType : function (
)
{
    return 0;
},

/**
 * @method isExitGame
 * @return {bool}
 */
isExitGame : function (
)
{
    return false;
},

/**
 * @method getDefaultPayType
 * @return {int}
 */
getDefaultPayType : function (
)
{
    return 0;
},

/**
 * @method setOnGameExit
 * @param {function} arg0
 */
setOnGameExit : function (
func 
)
{
},

/**
 * @method getButtonType
 * @param {int} arg0
 * @return {int}
 */
getButtonType : function (
int 
)
{
    return 0;
},

};
