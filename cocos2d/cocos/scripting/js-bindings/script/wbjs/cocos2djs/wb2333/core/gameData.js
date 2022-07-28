/**
 * Created by Zack on 2018/12/18.
 */

var wb = window.wb || {};
wb.data23PushData = {};

wb.data23PushData.adlist = null;
wb.data23PushData.init = function () {
    //   wb.Http.httpRequest("http://zp.vimedia.cn:8998/productPush?value=cGlkPTExMjIzMw==", {}, function (data) {

    var url = "http://zp.vimedia.cn:8998/productPush?value=" + wb.Tools.base64.encode("pid=" + wb.getPrjid());
    wb.Http.httpRequest(url, {}, function (data) {
        var data = wb.XmlHelper.parse(data);
        wb.data23PushData.adlist = data.root.adlist.ad;
        wb.log("wb.data23PushData.init");
        wb.log(wb.data23PushData.adlist);
    }, true);
};