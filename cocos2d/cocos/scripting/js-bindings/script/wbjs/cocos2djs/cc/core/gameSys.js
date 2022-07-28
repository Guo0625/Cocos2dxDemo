/**
 * Created by Zack on 2018/1/9.
 */

var wb = window.wb || {};
wb.initRes = function () {
    // cc.spriteFrameCache.addSpriteFrames(wb.res.cjlb_plist,wb.res.cjlb_png);
    // cc.spriteFrameCache.addSpriteFrames(wb.res.czlb_plist,wb.res.czlb_png);
    // cc.spriteFrameCache.addSpriteFrames(wb.res.shop_plist,wb.res.shop_png);
    // cc.spriteFrameCache.addSpriteFrames(wb.res.xslb_plist,wb.res.xslb_png);

    //cc.loader.load(wb.g_resources,
    //    function (result, count, loadedCount) {
    //    }, function () {
    //    });
};


wb.originDesignResolutionSize = {width: 640, height: 1136};
wb.initEngineCallBack = function () {
    cc.log("wb.initEngineCallBack");
    if (wb.isWX()) return;

    if (!wb.isNative()) {
        // 请求互推数据
        wb.Http.httpRequest(wb.pushUrl, "appid=" + 20065 + "&platform=web&channel=wb", function (data) {
            cc.log(data);
            wb.pushData = data;
        }, false);

        // 加载附加资源
        wb.Loader.load(wb.pushRes,
            function (result, count, loadedCount) {
            }, function () {
            });
    }

    wb.initRes();

    if (!wb.isNative() && !cc.view._setDesignResolutionSizeTemp) {
        cc.view._setDesignResolutionSizeTemp = cc.view.setDesignResolutionSize;
        cc.view.setDesignResolutionSize = function (width, height, resolutionPolicy) {
            wb.originDesignResolutionSize = cc.size(width, height);
            cc.view._setDesignResolutionSizeTemp(width, height, resolutionPolicy);
        }
    }

    if (cc.view && !cc.view._setDesignResolutionSizeTemp) {
        cc.view._setDesignResolutionSizeTemp = cc.view.setDesignResolutionSize;
        cc.view.setDesignResolutionSize = function (width, height, resolutionPolicy) {
            wb.originDesignResolutionSize = cc.size(width, height);
            cc.view._setDesignResolutionSizeTemp(width, height, resolutionPolicy);
        }
    }

    var ccs = ccs || {};
    if (!ccs._loadTemp && ccs.load) {
        ccs._loadTemp = ccs.load;
        ccs._loadTemp.validate = ccs.load.validate;
        ccs.load = function (file, path) {
            cc.log("ccs._loadTemp  " + file);
            var objectTemp = ccs._loadTemp(file, path);
            var rootNode = objectTemp.node;
            var rootNodeSize = rootNode.getContentSize();
            if (wb.originDesignResolutionSize.width == rootNodeSize.width && wb.originDesignResolutionSize.height == rootNodeSize.height) {
                var size = cc.director.getWinSize();
                rootNode.setContentSize(size);
                ccui.helper.doLayout(rootNode);
            }
            return objectTemp;
        };
        ccs.load.validate = ccs._loadTemp.validate;
    }

};
wb.currentSceneStr = null;
wb.appendSceneStr = function (str) {
    if (!wb.isNative()) return str;
    wb.currentSceneStr = wb.Helper.getCurrentSceneStr();
    if (wb.currentSceneStr.length > 0) return wb.currentSceneStr + "/" + str;
    return str;
};

//////////////////////////////////////////////////////////////

//if (!ccui.TextAtlas.prototype._setStringTemp) {
//    ccui.TextAtlas.prototype._setStringTemp = ccui.TextAtlas.prototype.setString;
//    ccui.TextAtlas.prototype.setString = function (str) {
//        var size = this.getVirtualRendererSize();
//        var dw = size.width / this.getString().replace(/[\u0391-\uFFE5]/g, "aa").length;
//        this._setStringTemp(str);
//        this.setContentSize(cc.size(dw * str.toString().replace(/[\u0391-\uFFE5]/g, "aa").length, size.height));
//        //this.setTextHorizontalAlignment(cc.TEXT_ALIGNMENT_CENTER);
//    }
//}
//
//if (!ccui.Text.prototype._setStringTemp) {
//    ccui.Text.prototype._setStringTemp = ccui.Text.prototype.setString;
//    ccui.Text.prototype.setString = function (str) {
//        this._setStringTemp(str);
//        var fontSize = this.getFontSize();
//        this.setContentSize(cc.size(fontSize * str.toString().replace(/[\u0391-\uFFE5]/g, "aa").length, fontSize));
//        //this.setTextHorizontalAlignment(this.getTextHorizontalAlignment());
//    }
//}



