/**
 * Created by Zack on 2019/1/8.
 */


var wb = window.wb || {};
wb.PlistHelper = wb.PlistHelper || {};

wb.SAXParser = wb.Class.extend({
    _parser: null,
    _isSupportDOMParser: null,

    ctor: function () {
        if (window.DOMParser) {
            this._isSupportDOMParser = true;
            this._parser = new DOMParser();
        } else {
            this._isSupportDOMParser = false;
        }
    },

    parse: function (xmlTxt) {
        return this._parseXML(xmlTxt);
    },

    _parseXML: function (textxml) {
        // get a reference to the requested corresponding xml file
        var xmlDoc;
        if (this._isSupportDOMParser) {
            xmlDoc = this._parser.parseFromString(textxml, "text/xml");
        } else {
            // Internet Explorer (untested!)
            xmlDoc = new ActiveXObject("Microsoft.XMLDOM");
            xmlDoc.async = "false";
            xmlDoc.loadXML(textxml);
        }
        return xmlDoc;
    }
});


wb.PlistParser = wb.SAXParser.extend({

    parse: function (xmlTxt) {
        var xmlDoc = this._parseXML(xmlTxt);
        var plist = xmlDoc.documentElement;
        if (plist.tagName !== 'plist') {
            wb.log("Not a plist file!");
            return {};
        }

        // Get first real node
        var node = null;
        for (var i = 0, len = plist.childNodes.length; i < len; i++) {
            node = plist.childNodes[i];
            if (node.nodeType === 1)
                break;
        }
        xmlDoc = null;
        return this._parseNode(node);
    },

    _parseNode: function (node) {
        var data = null, tagName = node.tagName;
        if (tagName === "dict") {
            data = this._parseDict(node);
        } else if (tagName === "array") {
            data = this._parseArray(node);
        } else if (tagName === "string") {
            if (node.childNodes.length === 1)
                data = node.firstChild.nodeValue;
            else {
                //handle Firefox's 4KB nodeValue limit
                data = "";
                for (var i = 0; i < node.childNodes.length; i++)
                    data += node.childNodes[i].nodeValue;
            }
        } else if (tagName === "false") {
            data = false;
        } else if (tagName === "true") {
            data = true;
        } else if (tagName === "real") {
            data = parseFloat(node.firstChild.nodeValue);
        } else if (tagName === "integer") {
            data = parseInt(node.firstChild.nodeValue, 10);
        }
        return data;
    },

    _parseArray: function (node) {
        var data = [];
        for (var i = 0, len = node.childNodes.length; i < len; i++) {
            var child = node.childNodes[i];
            if (child.nodeType !== 1)
                continue;
            data.push(this._parseNode(child));
        }
        return data;
    },

    _parseDict: function (node) {
        var data = {};
        var key = null;
        for (var i = 0, len = node.childNodes.length; i < len; i++) {
            var child = node.childNodes[i];
            if (child.nodeType !== 1) continue;

            // Grab the key, next noe should be the value
            if (child.tagName === 'key')
                key = child.firstChild.nodeValue;
            else
            // Parse the value node
                data[key] = this._parseNode(child);
        }
        return data;
    }
});

wb.saxParser = new wb.SAXParser();
wb.plistParser = new wb.PlistParser();

wb.PlistHelper.plistDictCache = {};
wb.PlistHelper.CCNS_REG1 = /^\s*\{\s*([\-]?\d+[.]?\d*)\s*,\s*([\-]?\d+[.]?\d*)\s*\}\s*$/;
wb.PlistHelper.CCNS_REG2 = /^\s*\{\s*\{\s*([\-]?\d+[.]?\d*)\s*,\s*([\-]?\d+[.]?\d*)\s*\}\s*,\s*\{\s*([\-]?\d+[.]?\d*)\s*,\s*([\-]?\d+[.]?\d*)\s*\}\s*\}\s*$/;

wb.PlistHelper.rectFromString = function (content) {
    var result = wb.PlistHelper.CCNS_REG2.exec(content);
    if (!result) return wb.SysValue.rect(0, 0, 0, 0);
    return wb.SysValue.rect(parseFloat(result[1]), parseFloat(result[2]), parseFloat(result[3]), parseFloat(result[4]));
};

wb.PlistHelper.pointFromString = function (content) {
    var result = wb.PlistHelper.CCNS_REG1.exec(content);
    if (!result) return wb.SysValue.p(0, 0);
    return wb.SysValue.p(parseFloat(result[1]), parseFloat(result[2]));
};
wb.PlistHelper.sizeFromString = function (content) {
    var result = wb.PlistHelper.CCNS_REG1.exec(content);
    if (!result) return wb.SysValue.size(0, 0);
    return wb.SysValue.size(parseFloat(result[1]), parseFloat(result[2]));
};

wb.PlistHelper.parseFrameConfig = function (dict) {
    var tempFrames = dict["frames"], tempMeta = dict["metadata"] || dict["meta"];
    var frames = {}, meta = {};
    var format = 0;
    if (tempMeta) {//init meta
        var tmpFormat = tempMeta["format"];
        format = (tmpFormat.length <= 1) ? parseInt(tmpFormat) : tmpFormat;
        meta.image = tempMeta["textureFileName"] || tempMeta["textureFileName"] || tempMeta["image"];
    }
    for (var key in tempFrames) {
        var frameDict = tempFrames[key];
        if (!frameDict) continue;
        var tempFrame = {};

        if (format == 0) {
            tempFrame.rect = wb.SysValue.rect(frameDict["x"], frameDict["y"], frameDict["width"], frameDict["height"]);
            tempFrame.rotated = false;
            tempFrame.offset = wb.SysValue.p(frameDict["offsetX"], frameDict["offsetY"]);
            var ow = frameDict["originalWidth"];
            var oh = frameDict["originalHeight"];
            // check ow/oh
            // if (!ow || !oh) {
            // }

            // Math.abs ow/oh
            ow = Math.abs(ow);
            oh = Math.abs(oh);
            tempFrame.size = wb.SysValue.size(ow, oh);
        } else if (format == 1 || format == 2) {
            tempFrame.rect = wb.PlistHelper.rectFromString(frameDict["frame"]);
            tempFrame.rotated = frameDict["rotated"] || false;
            tempFrame.offset = wb.PlistHelper.pointFromString(frameDict["offset"]);
            tempFrame.size = wb.PlistHelper.sizeFromString(frameDict["sourceSize"]);
        } else if (format == 3) {
            // get values
            var spriteSize = wb.PlistHelper.sizeFromString(frameDict["spriteSize"]);
            var textureRect = wb.PlistHelper.rectFromString(frameDict["textureRect"]);
            if (spriteSize) {
                textureRect = wb.SysValue.rect(textureRect.x, textureRect.y, spriteSize.width, spriteSize.height);
            }
            tempFrame.rect = textureRect;
            tempFrame.rotated = frameDict["textureRotated"] || false; // == "true";
            tempFrame.offset = wb.PlistHelper.pointFromString(frameDict["spriteOffset"]);
            tempFrame.size = wb.PlistHelper.sizeFromString(frameDict["spriteSourceSize"]);
            tempFrame.aliases = frameDict["aliases"];
        } else {
            var tmpFrame = frameDict["frame"], tmpSourceSize = frameDict["sourceSize"];
            key = frameDict["filename"] || key;
            tempFrame.rect = wb.SysValue.rect(tmpFrame["x"], tmpFrame["y"], tmpFrame["w"], tmpFrame["h"]);
            tempFrame.rotated = frameDict["rotated"] || false;
            tempFrame.offset = wb.SysValue.p(0, 0);
            tempFrame.size = wb.SysValue.size(tmpSourceSize["w"], tmpSourceSize["h"]);
        }
        frames[key] = tempFrame;
    }
    return {inited: true, frames: frames, meta: meta};
};

wb.PlistHelper.parsePlist = function (url, callFun) {
    var tempData = wb.PlistHelper.plistDictCache[url];
    if (tempData && tempData.inited) {
        if (callFun) callFun(tempData);
        return;
    }

    wb.Loader.loadTxt(url, function (err, responseText) {
        wb.log("parsePlist~~~~~~~~");
        if (err) {
            wb.log(err);
            if (callFun) callFun(null);
        }
        wb.log(responseText);
        var dict = wb.plistParser.parse(responseText);
        wb.Loader.release(url);//release it in loader

        var data = wb.PlistHelper.parseFrameConfig(dict);
        // wb.log(data);
        wb.PlistHelper.plistDictCache[url] = data;
        if (callFun) callFun(data);
    }.bind(this));

};