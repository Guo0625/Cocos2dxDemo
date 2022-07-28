/**
 * Created by Administrator on 2018/11/14.
 */

var wb = wb || {};
window.wb = wb; 

wb.jsRootPath = "frameworks/cocos2d-html5/";

wb.each = function (obj, iterator, context) {
    if (!obj)  return;
    if (obj instanceof Array) {
        for (var i = 0, li = obj.length; i < li; i++) {
            if (iterator.call(context, obj[i], i) === false) return;
        }
    } else {
        for (var key in obj) {
            if (iterator.call(context, obj[key], key) === false)  return;
        }
    }
};
wb.JsListOfModule = {
    _jsAddedCache: [],
    getJsListOfModule: function (moduleMap, moduleName, dir) {
        if (this._jsAddedCache[moduleName]) return null;
        dir = dir || "";
        var jsList = [];
        var tempList = moduleMap[moduleName];
        if (!tempList) throw new Error("can not find module [" + moduleName + "]");
        var ccPath = wb.Path;
        for (var i = 0, li = tempList.length; i < li; i++) {
            var item = tempList[i];
            if (this._jsAddedCache[item]) continue;
            var extname = ccPath.extname(item);
            if (!extname) {
                var arr = this.getJsListOfModule(moduleMap, item, dir);
                if (arr) jsList = jsList.concat(arr);
            } else if (extname.toLowerCase() === ".js") jsList.push(ccPath.join(dir, item));
            this._jsAddedCache[item] = 1;
        }
        return jsList;
    }
};
wb.Async = {
    series: function (tasks, cb, target) {
        var asyncPool = new wb.AsyncPool(tasks, 1, function (func, index, cb1) {
            func.call(target, cb1);
        }, cb, target);
        asyncPool.flow();
        return asyncPool;
    },

    parallel: function (tasks, cb, target) {
        var asyncPool = new wb.AsyncPool(tasks, 0, function (func, index, cb1) {
            func.call(target, cb1);
        }, cb, target);
        asyncPool.flow();
        return asyncPool;
    },

    waterfall: function (tasks, cb, target) {
        var args = [];
        var lastResults = [null];//the array to store the last results
        var asyncPool = new wb.AsyncPool(tasks, 1,
            function (func, index, cb1) {
                args.push(function (err) {
                    args = Array.prototype.slice.call(arguments, 1);
                    if (tasks.length - 1 === index) lastResults = lastResults.concat(args);//while the last task
                    cb1.apply(null, arguments);
                });
                func.apply(target, args);
            }, function (err) {
                if (!cb)
                    return;
                if (err)
                    return cb.call(target, err);
                cb.apply(target, lastResults);
            });
        asyncPool.flow();
        return asyncPool;
    },

    map: function (tasks, iterator, callback, target) {
        var locIterator = iterator;
        if (typeof(iterator) === "object") {
            callback = iterator.cb;
            target = iterator.iteratorTarget;
            locIterator = iterator.iterator;
        }
        var asyncPool = new wb.AsyncPool(tasks, 0, locIterator, callback, target);
        asyncPool.flow();
        return asyncPool;
    },


    mapLimit: function (tasks, limit, iterator, cb, target) {
        var asyncPool = new wb.AsyncPool(tasks, limit, iterator, cb, target);
        asyncPool.flow();
        return asyncPool;
    }
};
wb.AsyncPool = function (srcObj, limit, iterator, onEnd, target) {
    var self = this;
    self._finished = false;
    self._srcObj = srcObj;
    self._limit = limit;
    self._pool = [];
    self._iterator = iterator;
    self._iteratorTarget = target;
    self._onEnd = onEnd;
    self._onEndTarget = target;
    self._results = srcObj instanceof Array ? [] : {};
    self._errors = srcObj instanceof Array ? [] : {};

    wb.each(srcObj, function (value, index) {
        self._pool.push({index: index, value: value});
    });


    self.size = self._pool.length;
    self.finishedSize = 0;
    self._workingSize = 0;

    self._limit = self._limit || self.size;

    self.onIterator = function (iterator, target) {
        self._iterator = iterator;
        self._iteratorTarget = target;
    };

    self.onEnd = function (endCb, endCbTarget) {
        self._onEnd = endCb;
        self._onEndTarget = endCbTarget;
    };

    self._handleItem = function () {
        var self = this;
        if (self._pool.length === 0 || self._workingSize >= self._limit)
            return;                                                         //return directly if the array's length = 0 or the working size great equal limit number

        var item = self._pool.shift();
        var value = item.value, index = item.index;
        self._workingSize++;
        self._iterator.call(self._iteratorTarget, value, index,
            function (err, result) {
                if (self._finished) {
                    return;
                }

                if (err) {
                    self._errors[this.index] = err;
                }
                else {
                    self._results[this.index] = result;
                }

                self.finishedSize++;
                self._workingSize--;
                if (self.finishedSize === self.size) {
                    var errors = self._errors.length === 0 ? null : self._errors;
                    self.onEnd(errors, self._results);
                    return;
                }
                self._handleItem();
            }.bind(item),
            self);
    };

    self.flow = function () {
        var self = this;
        if (self._pool.length === 0) {
            if (self._onEnd)
                self._onEnd.call(self._onEndTarget, null, []);
            return;
        }
        for (var i = 0; i < self._limit; i++)
            self._handleItem();
    };

    self.onEnd = function (errors, results) {
        self._finished = true;
        if (self._onEnd) {
            var selector = self._onEnd;
            var target = self._onEndTarget;
            self._onEnd = null;
            self._onEndTarget = null;
            selector.call(target, errors, results);
        }
    };
};
wb.ImagePool = {
    _pool: new Array(10),
    _MAX: 10,
    _smallImg: "data:image/gif;base64,R0lGODlhAQABAAAAACwAAAAAAQABAAA=",

    count: 0,
    get: function () {
        if (this.count > 0) {
            this.count--;
            var result = this._pool[this.count];
            this._pool[this.count] = null;
            return result;
        }
        else {
            return new Image();
        }
    },
    put: function (img) {
        if (window.wx) {
            return
        }
        var pool = this._pool;
        if (img instanceof window.HTMLImageElement && this.count < this._MAX) {
            img.src = this._smallImg;
            pool[this.count] = img;
            this.count++;
        }
    }
};
wb.Path = {
    normalizeRE: /[^\.\/]+\/\.\.\//,

    /**
     * Join strings to be a path.
     * @example
     wb.Path.join("a", "b.png");//-->"a/b.png"
     wb.Path.join("a", "b", "c.png");//-->"a/b/c.png"
     wb.Path.join("a", "b");//-->"a/b"
     wb.Path.join("a", "b", "/");//-->"a/b/"
     wb.Path.join("a", "b/", "/");//-->"a/b/"
     * @returns {string}
     */
    join: function () {
        var l = arguments.length;
        var result = "";
        for (var i = 0; i < l; i++) {
            result = (result + (result === "" ? "" : "/") + arguments[i]).replace(/(\/|\\\\)$/, "");
        }
        return result;
    },

    /**
     * Get the ext name of a path.
     * @example
     wb.Path.extname("a/b.png");//-->".png"
     wb.Path.extname("a/b.png?a=1&b=2");//-->".png"
     wb.Path.extname("a/b");//-->null
     wb.Path.extname("a/b?a=1&b=2");//-->null
     * @param {string} pathStr
     * @returns {*}
     */
    extname: function (pathStr) {
        var temp = /(\.[^\.\/\?\\]*)(\?.*)?$/.exec(pathStr);
        return temp ? temp[1] : null;
    },

    /**
     * Get the main name of a file name
     * @param {string} fileName
     * @returns {string}
     */
    mainFileName: function (fileName) {
        if (fileName) {
            var idx = fileName.lastIndexOf(".");
            if (idx !== -1)
                return fileName.substring(0, idx);
        }
        return fileName;
    },

    /**
     * Get the file name of a file path.
     * @example
     wb.Path.basename("a/b.png");//-->"b.png"
     wb.Path.basename("a/b.png?a=1&b=2");//-->"b.png"
     wb.Path.basename("a/b.png", ".png");//-->"b"
     wb.Path.basename("a/b.png?a=1&b=2", ".png");//-->"b"
     wb.Path.basename("a/b.png", ".txt");//-->"b.png"
     * @param {string} pathStr
     * @param {string} [extname]
     * @returns {*}
     */
    basename: function (pathStr, extname) {
        var index = pathStr.indexOf("?");
        if (index > 0) pathStr = pathStr.substring(0, index);
        var reg = /(\/|\\\\)([^(\/|\\\\)]+)$/g;
        var result = reg.exec(pathStr.replace(/(\/|\\\\)$/, ""));
        if (!result) return null;
        var baseName = result[2];
        if (extname && pathStr.substring(pathStr.length - extname.length).toLowerCase() === extname.toLowerCase())
            return baseName.substring(0, baseName.length - extname.length);
        return baseName;
    },

    /**
     * Get dirname of a file path.
     * @example
     * unix
     wb.Path.driname("a/b/c.png");//-->"a/b"
     wb.Path.driname("a/b/c.png?a=1&b=2");//-->"a/b"
     wb.Path.dirname("a/b/");//-->"a/b"
     wb.Path.dirname("c.png");//-->""
     * windows
     wb.Path.driname("a\\b\\c.png");//-->"a\b"
     wb.Path.driname("a\\b\\c.png?a=1&b=2");//-->"a\b"
     * @param {string} pathStr
     * @returns {*}
     */
    dirname: function (pathStr) {
        return pathStr.replace(/((.*)(\/|\\|\\\\))?(.*?\..*$)?/, '$2');
    },

    /**
     * Change extname of a file path.
     * @example
     wb.Path.changeExtname("a/b.png", ".plist");//-->"a/b.plist"
     wb.Path.changeExtname("a/b.png?a=1&b=2", ".plist");//-->"a/b.plist?a=1&b=2"
     * @param {string} pathStr
     * @param {string} [extname]
     * @returns {string}
     */
    changeExtname: function (pathStr, extname) {
        extname = extname || "";
        var index = pathStr.indexOf("?");
        var tempStr = "";
        if (index > 0) {
            tempStr = pathStr.substring(index);
            pathStr = pathStr.substring(0, index);
        }
        index = pathStr.lastIndexOf(".");
        if (index < 0) return pathStr + extname + tempStr;
        return pathStr.substring(0, index) + extname + tempStr;
    },
    /**
     * Change file name of a file path.
     * @example
     wb.Path.changeBasename("a/b/c.plist", "b.plist");//-->"a/b/b.plist"
     wb.Path.changeBasename("a/b/c.plist?a=1&b=2", "b.plist");//-->"a/b/b.plist?a=1&b=2"
     wb.Path.changeBasename("a/b/c.plist", ".png");//-->"a/b/c.png"
     wb.Path.changeBasename("a/b/c.plist", "b");//-->"a/b/b"
     wb.Path.changeBasename("a/b/c.plist", "b", true);//-->"a/b/b.plist"
     * @param {String} pathStr
     * @param {String} basename
     * @param {Boolean} [isSameExt]
     * @returns {string}
     */
    changeBasename: function (pathStr, basename, isSameExt) {
        if (basename.indexOf(".") === 0) return this.changeExtname(pathStr, basename);
        var index = pathStr.indexOf("?");
        var tempStr = "";
        var ext = isSameExt ? this.extname(pathStr) : "";
        if (index > 0) {
            tempStr = pathStr.substring(index);
            pathStr = pathStr.substring(0, index);
        }
        index = pathStr.lastIndexOf("/");
        index = index <= 0 ? 0 : index + 1;
        return pathStr.substring(0, index) + basename + ext + tempStr;
    },
    //todo make public after verification
    _normalize: function (url) {
        var oldUrl = url = String(url);

        //removing all ../
        do {
            oldUrl = url;
            url = url.replace(this.normalizeRE, "");
        } while (oldUrl.length !== url.length);
        return url;
    }
};
wb.Loader = (function () {
    var _jsCache = {}, //cache for js
        _register = {}, //register of loaders
        _langPathCache = {}, //cache for lang path
        _aliases = {}, //aliases for res url
        _queue = {}, // Callback queue for resources already loading
        _urlRegExp = new RegExp("^(?:https?|ftp)://\\S*$", "i");

    return {
        resPath: "",
        audioPath: "",
        cache: {},

        //@MODE_BEGIN DEV
        _getArgs4Js: function (args) {
            var a0 = args[0], a1 = args[1], a2 = args[2], results = ["", null, null];

            if (args.length === 1) {
                results[1] = a0 instanceof Array ? a0 : [a0];
            } else if (args.length === 2) {
                if (typeof a1 === "function") {
                    results[1] = a0 instanceof Array ? a0 : [a0];
                    results[2] = a1;
                } else {
                    results[0] = a0 || "";
                    results[1] = a1 instanceof Array ? a1 : [a1];
                }
            } else if (args.length === 3) {
                results[0] = a0 || "";
                results[1] = a1 instanceof Array ? a1 : [a1];
                results[2] = a2;
            } else throw new Error("arguments error to load js!");
            return results;
        },

        isLoading: function (url) {
            return (_queue[url] !== undefined);
        },


        loadJs: function (baseDir, jsList, cb) {
            var self = this,
                args = self._getArgs4Js(arguments);

            var preDir = args[0], list = args[1], callback = args[2];
            if (navigator.userAgent.indexOf("Trident/5") > -1) {
                self._loadJs4Dependency(preDir, list, 0, callback);
            } else {
                wb.Async.map(list, function (item, index, cb1) {
                    var jsPath = wb.Path.join(preDir, item);
                    if (_jsCache[jsPath]) return cb1(null);
                    self._createScript(jsPath, false, cb1);
                }, callback);
            }
        },

        _createScript: function (jsPath, isAsync, cb) {
            var d = document, self = this, s = document.createElement('script');
            s.async = isAsync;
            _jsCache[jsPath] = true;
            s.src = jsPath;
            s.addEventListener('load', function () {
                console.log("js load is ok " + s.src);
                cb();
                s.parentNode.removeChild(s);
                this.removeEventListener('load', arguments.callee, false);

            }, false);
            s.addEventListener('error', function () {
                console.log("js load error " + s.src);
                cb(s.src);
                s.parentNode.removeChild(s);
            }, false);
            d.body.appendChild(s);
        },

        _Utf8ArrayToStr: function (array) {
            var out, i, len, c;
            var char2, char3;

            out = "";
            len = array.length;
            i = 0;
            while (i < len) {
                c = array[i++];
                switch (c >> 4) {
                    case 0:
                    case 1:
                    case 2:
                    case 3:
                    case 4:
                    case 5:
                    case 6:
                    case 7:
                        // 0xxxxxxx
                        out += String.fromCharCode(c);
                        break;
                    case 12:
                    case 13:
                        // 110x xxxx   10xx xxxx
                        char2 = array[i++];
                        out += String.fromCharCode(((c & 0x1F) << 6) | (char2 & 0x3F));
                        break;
                    case 14:
                        // 1110 xxxx  10xx xxxx  10xx xxxx
                        char2 = array[i++];
                        char3 = array[i++];
                        out += String.fromCharCode(((c & 0x0F) << 12) |
                            ((char2 & 0x3F) << 6) |
                            ((char3 & 0x3F) << 0));
                        break;
                }
            }

            return out;
        },

        loadTxt: function (url, cb) {
            var _self = this;
            url = wb.Loader.getUrl('', url);

            if (!wb._isNodeJs) {
                var xhr = wb.Http.getXMLHttpRequest();
                var errInfo = "load " + url + " failed!";
                xhr.open("GET", url, true);
                if (/msie/i.test(navigator.userAgent) && !/opera/i.test(navigator.userAgent)) {
                    // IE-specific logic here
                    xhr.setRequestHeader("Accept-Charset", "utf-8");
                    xhr.onreadystatechange = function () {
                        if (xhr.readyState === 4)
                            xhr.status === 200 ? cb(null, xhr.responseText) : cb({
                                status: xhr.status,
                                errorMessage: errInfo
                            }, null);
                    };
                }
                else {
                    if (xhr.overrideMimeType) xhr.overrideMimeType("text\/plain; charset=utf-8");
                    xhr.onload = function () {
                        if (xhr._timeoutId >= 0) {
                            clearTimeout(xhr._timeoutId);
                        }
                        if (xhr.readyState === 4) {
                            xhr.status === 200 ? cb(null, xhr.responseText) : cb({
                                status: xhr.status,
                                errorMessage: errInfo
                            }, null);
                        }
                    };
                    xhr.onerror = function () {
                        cb({
                            status: xhr.status,
                            errorMessage: errInfo
                        }, null);
                    };
                    if (xhr.ontimeout === undefined) {
                        xhr._timeoutId = setTimeout(function () {
                            xhr.ontimeout();
                        }, xhr.timeout);
                    }
                    xhr.ontimeout = function () {
                        cb({
                            status: xhr.status,
                            errorMessage: "Request timeout: " + errInfo
                        }, null);
                    };
                }
                xhr.send(null);
            }
            else {
                var fs = require("fs");
                fs.readFile(url, function (err, data) {
                    err ? cb(err) : cb(null, data.toString());
                });
            }
        },

        loadJson: function (url, cb) {
            url = wb.Loader.getUrl('', url);
            this.loadTxt(url, function (err, txt) {
                if (err) {
                    cb(err);
                }
                else {
                    try {
                        var result = JSON.parse(txt);
                    }
                    catch (e) {
                        throw new Error("parse json [" + url + "] failed : " + e);
                        return;
                    }
                    cb(null, result);
                }
            });
        },

        _checkIsImageURL: function (url) {
            var ext = /(\.png)|(\.jpg)|(\.bmp)|(\.jpeg)|(\.gif)/.exec(url);
            return (ext != null);
        },

        loadImg: function (url, option, callback, img) {
            url = wb.Loader.getUrl('', url);
            var opt = {
                isCrossOrigin: true
            };
            if (callback !== undefined)
                opt.isCrossOrigin = option.isCrossOrigin === undefined ? opt.isCrossOrigin : option.isCrossOrigin;
            else if (option !== undefined)
                callback = option;

            var texture = this.getRes(url);
            if (texture) {
                callback && callback(null, texture);
                return null;
            }

            var timestamp = url + new Date().getTime() + Math.floor(Math.random() * 100);
            var queue = _queue[timestamp];
            if (queue) {
                queue.callbacks.push(callback);
                return queue.img;
            }

            img = img || wb.ImagePool.get();
            if (opt.isCrossOrigin && location.origin !== "file://")
                img.crossOrigin = "Anonymous";
            else
                img.crossOrigin = null;

            var loadCallback = function () {
                this.removeEventListener('load', loadCallback, false);
                this.removeEventListener('error', errorCallback, false);

                var queue = _queue[timestamp];
                if (queue) {
                    var callbacks = queue.callbacks;
                    for (var i = 0; i < callbacks.length; ++i) {
                        var cb = callbacks[i];
                        if (cb) {
                            cb(null, img);
                        }
                    }
                    queue.img = null;
                    delete _queue[timestamp];
                }

                if (window.ENABLE_IMAEG_POOL && wb.SysPlatform.renderType === wb.SysPlatform.RENDER_TYPE_WEBGL) {
                    wb.ImagePool.put(img);
                }
            };

            var self = this;
            var errorCallback = function () {
                this.removeEventListener('load', loadCallback, false);
                this.removeEventListener('error', errorCallback, false);

                if (window.location.protocol !== 'https:' && img.crossOrigin && img.crossOrigin.toLowerCase() === "anonymous") {
                    opt.isCrossOrigin = false;
                    self.release(url);
                    wb.Loader.loadImg(url, opt, callback, img);
                } else {
                    var queue = _queue[timestamp];
                    if (queue) {
                        var callbacks = queue.callbacks;
                        for (var i = 0; i < callbacks.length; ++i) {
                            var cb = callbacks[i];
                            if (cb) {
                                cb("load image failed");
                            }
                        }
                        queue.img = null;
                        delete _queue[timestamp];
                    }

                    if (wb.SysPlatform.renderType === wb.SysPlatform.RENDER_TYPE_WEBGL) {
                        wb.ImagePool.put(img);
                    }
                }
            };

            _queue[timestamp] = {
                img: img,
                callbacks: callback ? [callback] : []
            };

            img.addEventListener("load", loadCallback);
            img.addEventListener("error", errorCallback);
            img.src = url;
            return img;
        },

        _loadResIterator: function (item, index, cb) {
            var self = this, url = null;
            var type = item.type;
            if (type) {
                type = "." + type.toLowerCase();
                url = item.src ? item.src : item.name + type;
            } else {
                url = item;
                type = wb.Path.extname(url);
            }

            var obj = self.getRes(url);
            if (obj)
                return cb(null, obj);
            var loader = null;
            if (type) {
                loader = _register[type.toLowerCase()];
            }
            if (!loader) {
                wb.log("loader for [" + type + "] not exists!");
                return cb();
            }
            var realUrl = url;
            if (!_urlRegExp.test(url) && !window.wx) {
                var basePath = loader.getBasePath ? loader.getBasePath() : self.resPath;
                realUrl = self.getUrl(basePath, url);
            }

            loader.load(realUrl, url, item, function (err, data) {
                if (err) {
                    wb.log(err);
                    self.cache[url] = null;
                    delete self.cache[url];
                    cb({
                        status: 520,
                        errorMessage: err
                    }, null);
                }
                else {
                    self.cache[url] = data;
                    cb(null, data);
                }
            });
        },
        _noCacheRex: /\?/,

        getUrl: function (basePath, url) {
            if (window.wx) {
                window.pre = window.pre || '';
                if (url.slice(0, 4) != 'http' && url.slice(0, 2) != '//') {
                    return window.REMOTE_SERVER_ROOT + url;
                }
                else {
                    return url
                }
            }

            var self = this, path = wb.Path;
            if (basePath !== undefined && url === undefined) {
                url = basePath;
                var type = path.extname(url);
                type = type ? type.toLowerCase() : "";
                var loader = _register[type];
                if (!loader)
                    basePath = self.resPath;
                else
                    basePath = loader.getBasePath ? loader.getBasePath() : self.resPath;
            }
            url = wb.Path.join(basePath || "", url);
            if (url.match(/[\/(\\\\)]lang[\/(\\\\)]/i)) {
                if (_langPathCache[url])
                    return _langPathCache[url];
                var extname = path.extname(url) || "";
                url = _langPathCache[url] = url.substring(0, url.length - extname.length) + "_" + wb.SysPlatform.language + extname;
            }
            return url;
        },

        load: function (resources, option, loadCallback) {
            var self = this;
            var len = arguments.length;
            if (len === 0)
                throw new Error("arguments error!");

            if (len === 3) {
                if (typeof option === "function") {
                    if (typeof loadCallback === "function")
                        option = {
                            trigger: option,
                            cb: loadCallback
                        };
                    else
                        option = {
                            cb: option,
                            cbTarget: loadCallback
                        };
                }
            }
            else if (len === 2) {
                if (typeof option === "function")
                    option = {cb: option};
            }
            else if (len === 1) {
                option = {};
            }

            if (!(resources instanceof Array)) {
                resources = [resources];
            }

            var asyncPool = new wb.AsyncPool(
                resources, wb.SysPlatform.CONCURRENCY_HTTP_REQUEST_COUNT,
                function (value, index, AsyncPoolCallback, aPool) {
                    self._loadResIterator(value, index, function (err) {
                        var arr = Array.prototype.slice.call(arguments, 1);
                        if (option.trigger)
                            option.trigger.call(option.triggerTarget, arr[0], aPool.size, aPool.finishedSize);   //call trigger
                        AsyncPoolCallback(err, arr[0]);
                    });
                },
                option.cb, option.cbTarget);
            asyncPool.flow();
            return asyncPool;
        },

        register: function (extNames, loader) {
            if (!extNames || !loader) return;
            var self = this;
            if (typeof extNames === "string")
                return _register[extNames.trim().toLowerCase()] = loader;
            for (var i = 0, li = extNames.length; i < li; i++) {
                _register["." + extNames[i].trim().toLowerCase()] = loader;
            }
        },


        getRes: function (url) {
            return this.cache[url];
        },

        release: function (url) {
            var cache = this.cache;
            var queue = _queue[url];
            if (queue) {
                queue.img = null;
                delete _queue[url];
            }
            delete cache[url];
            delete cache[_aliases[url]];
            delete _aliases[url];
        },

        releaseAll: function () {
            var locCache = this.cache;
            for (var key in locCache)
                delete locCache[key];
            for (var key in _aliases)
                delete _aliases[key];
        }
    };
})();


wb._loadModule = function (modules, callFun) {
    var jsList = [];
    for (var i = 0, li = modules.length; i < li; i++) {
        var arr = wb.JsListOfModule.getJsListOfModule(wb.modulesMap, modules[i], wb.jsRootPath);
        if (arr) jsList = jsList.concat(arr);
    }
    wb.Loader.loadJs("", jsList, function () {
        if (callFun) callFun();
    }.bind(this));
};

wb.isDLModules = true;
// if not need dynamic loading script, don't call init function ,
// it will be error on wx platform .
wb.init = function (modules, jsRootPath, callFun) {
    wb.jsRootPath = jsRootPath;
    // init module
    if (wb.isDLModules) {
        wb.Loader.loadJs(wb.jsRootPath, ["wbjs/module.js"], function () {
            wb._loadModule(modules, callFun);
        });
    } else {
        if (callFun) callFun();
    }
};

//wb.init([wb.moduleType], wb.jsRootPath, function () {
//
//});

