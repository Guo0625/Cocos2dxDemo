/**
 * @module jsbShare
 */
var wb = wb || {};

/**
 * @class JShare
 */
wb.JShare = {

/**
 * @method init
 */
init : function (
)
{
},

};

/**
 * @class JShareInfo
 */
wb.JShareInfo = {

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
 * @method setParams
 * @param {map_object} arg0
 */
setParams : function (
map 
)
{
},

/**
 * @method getParams
 * @return {map_object}
 */
getParams : function (
)
{
    return map_object;
},

/**
 * @method create
 * @return {wb.JShareInfo}
 */
create : function (
)
{
    return wb.JShareInfo;
},

};

/**
 * @class JWXShareData
 */
wb.JWXShareData = {

/**
 * @method getResultCode
 * @return {String}
 */
getResultCode : function (
)
{
    return ;
},

/**
 * @method getUrl
 * @return {String}
 */
getUrl : function (
)
{
    return ;
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
 * @method getTitle
 * @return {String}
 */
getTitle : function (
)
{
    return ;
},

/**
 * @method getContent
 * @return {String}
 */
getContent : function (
)
{
    return ;
},

/**
 * @method getResultMsg
 * @return {String}
 */
getResultMsg : function (
)
{
    return ;
},

/**
 * @method create
 * @return {wb.JWXShareData}
 */
create : function (
)
{
    return wb.JWXShareData;
},

};

/**
 * @class JShareManager
 */
wb.JShareManager = {

/**
 * @method invite
 * @param {wb.JShareInfo} arg0
 * @param {function} arg1
 */
invite : function (
jshareinfo, 
func 
)
{
},

/**
 * @method share
 * @param {wb.JShareInfo} arg0
 * @param {function} arg1
 */
share : function (
jshareinfo, 
func 
)
{
},

/**
 * @method getWXShare
 * @param {int} arg0
 * @param {int} arg1
 * @return {wb.JWXShareData}
 */
getWXShare : function (
int, 
int 
)
{
    return wb.JWXShareData;
},

/**
 * @method init
 */
init : function (
)
{
},

/**
 * @method inviteEnable
 * @param {wb.JShareInfo} arg0
 * @return {bool}
 */
inviteEnable : function (
jshareinfo 
)
{
    return false;
},

/**
 * @method isShareAvailable
 * @param {wb.JShareInfo} arg0
 * @return {bool}
 */
isShareAvailable : function (
jshareinfo 
)
{
    return false;
},

};
