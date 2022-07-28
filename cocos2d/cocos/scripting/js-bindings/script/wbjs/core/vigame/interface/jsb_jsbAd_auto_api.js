/**
 * @module jsbAd
 */
var wb = wb || {};

/**
 * @class JAd
 */
wb.JAd = {

/**
 * @method init
 */
init : function (
)
{
},

};

/**
 * @class JADCache
 */
wb.JADCache = {

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
 * @method getStatus
 * @return {int}
 */
getStatus : function (
)
{
    return 0;
},

/**
 * @method getIsUsed
 * @return {int}
 */
getIsUsed : function (
)
{
    return 0;
},

/**
 * @method getEcpm
 * @return {int}
 */
getEcpm : function (
)
{
    return 0;
},

/**
 * @method getId
 * @return {int}
 */
getId : function (
)
{
    return 0;
},

/**
 * @method create
 * @return {wb.JADCache}
 */
create : function (
)
{
    return wb.JADCache;
},

};

/**
 * @class JADManager
 */
wb.JADManager = {

/**
 * @method removeAdPositionListener
 * @param {String} arg0
 */
removeAdPositionListener : function (
str 
)
{
},

/**
 * @method setCustomVideoLimitNum
 * @param {int} arg0
 */
setCustomVideoLimitNum : function (
int 
)
{
},

/**
 * @method getBannerType
 * @return {int}
 */
getBannerType : function (
)
{
    return 0;
},

/**
 * @method removeAdReadyChangedCallback
 * @param {String} arg0
 */
removeAdReadyChangedCallback : function (
str 
)
{
},

/**
 * @method setAdStatusChangedCallback
 * @param {function} arg0
 */
setAdStatusChangedCallback : function (
func 
)
{
},

/**
 * @method setAwakenCallback
 * @param {function} arg0
 */
setAwakenCallback : function (
func 
)
{
},

/**
 * @method addAdPositionListener
 * @param {String} arg0
 * @param {function} arg1
 */
addAdPositionListener : function (
str, 
func 
)
{
},

/**
 * @method setBannerAlignment
 * @param {int} arg0
 * @param {int} arg1
 */
setBannerAlignment : function (
int, 
int 
)
{
},

/**
 * @method addAdReadyChangedCallback
 * @param {String} arg0
 * @param {function} arg1
 */
addAdReadyChangedCallback : function (
str, 
func 
)
{
},

/**
 * @method closeAd
 * @param {String} arg0
 */
closeAd : function (
str 
)
{
},

/**
 * @method getAdPositionParam
 * @param {String} arg0
 * @param {String} arg1
 * @return {String}
 */
getAdPositionParam : function (
str, 
str 
)
{
    return ;
},

/**
 * @method isAdTypeExist
 * @param {String} arg0
 * @return {bool}
 */
isAdTypeExist : function (
str 
)
{
    return false;
},

/**
 * @method init
 */
init : function (
)
{
},

/**
 * @method getVideoLimitOpenNum
 * @return {int}
 */
getVideoLimitOpenNum : function (
)
{
    return 0;
},

/**
 * @method isAdOpen
 * @param {String} arg0
 * @return {bool}
 */
isAdOpen : function (
str 
)
{
    return false;
},

/**
 * @method isAdBeOpenInLevel
 * @param {String} arg0
 * @param {int} arg1
 * @return {bool}
 */
isAdBeOpenInLevel : function (
str, 
int 
)
{
    return false;
},

/**
 * @method openAdO
 * @param {String} arg0
 * @param {int} arg1
 */
openAdO : function (
str, 
int 
)
{
},

/**
 * @method openAd
* @param {String|String} str
* @param {int} int
* @param {int} int
* @param {int} int
* @param {int} int
*/
openAd : function(
str,
int,
int,
int,
int 
)
{
},

/**
 * @method setAddGameCoinCallback
 * @param {function} arg0
 */
setAddGameCoinCallback : function (
func 
)
{
},

/**
 * @method isAdReady
* @param {String|String} str
* @param {String} str
* @return {bool|bool}
*/
isAdReady : function(
str,
str 
)
{
    return false;
},

/**
 * @method openAdC
 * @param {String} arg0
 * @param {function} arg1
 */
openAdC : function (
str, 
func 
)
{
},

/**
 * @method openAdOC
 * @param {String} arg0
 * @param {int} arg1
 * @param {function} arg2
 */
openAdOC : function (
str, 
int, 
func 
)
{
},

/**
 * @method getScreenSize
 * @return {size_object}
 */
getScreenSize : function (
)
{
    return cc.Size;
},

/**
 * @method setBannerType
 * @param {int} arg0
 */
setBannerType : function (
int 
)
{
},

};
