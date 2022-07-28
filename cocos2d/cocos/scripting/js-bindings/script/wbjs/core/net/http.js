/**
 * Created by Administrator on 2018/11/15.
 */

var wb = window.wb || {};

wb.Http = {
    getXMLHttpRequest: function () {
        var xhr = window.XMLHttpRequest ? new window.XMLHttpRequest() : new ActiveXObject("MSXML2.XMLHTTP");
        xhr.timeout = 10000;
        if (xhr.ontimeout === undefined) {
            xhr._timeoutId = -1;
        }
        return xhr;
    },
    httpRequest: function (url, data, func) {
        var xhr = wb.Http.getXMLHttpRequest();
        if (!xhr.onreadystatechange) {
            xhr.onreadystatechange = function () {
                if (xhr.readyState == 4 && (xhr.status >= 200 && xhr.status <= 207)) {
                    wb.log("response:\n" + xhr.responseText);
                    var data = null;
                    if (xhr.responseText.length > 0) data = wb.SysValue.parse(xhr.responseText);
                    if (!data) return;
                    if (data) wb.log(data);
                    if (data && data.result_status == 1) {
                    }
                    if (func) func(data);
                }
            };
        }
        xhr.open("POST", url);
        xhr.setRequestHeader('content-type', 'application/x-www-form-urlencoded');
        xhr.send(data);
    }
};
