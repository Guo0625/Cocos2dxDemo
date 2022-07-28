/**
 * Created by Zack on 2018/11/14.
 */

var wb = window.wb || {};
wb.SysCore = wb.SysCore || {};

wb.SysCore.extend = function (parent, child) {
    if (!parent) return child;
    for (var k in parent) {
        if (parent.hasOwnProperty(k)) {
            if (child[k] == undefined) {
                child[k] = parent[k];
            }
        }
    }
    child.parent = parent;
    return child;
};
wb.extend = wb.SysCore.extend;

wb.SysCore.defineGetterSetter = function (proto, prop, getter, setter, getterName, setterName) {
    if (proto.__defineGetter__) {
        getter && proto.__defineGetter__(prop, getter);
        setter && proto.__defineSetter__(prop, setter);
    } else if (Object.defineProperty) {
        var desc = {enumerable: false, configurable: true};
        getter && (desc.get = getter);
        setter && (desc.set = setter);
        Object.defineProperty(proto, prop, desc);
    } else {
        throw new Error("browser does not support getters");
    }

    if (!getterName && !setterName) {
        // Lookup getter/setter function
        var hasGetter = (getter != null), hasSetter = (setter != undefined), props = Object.getOwnPropertyNames(proto);
        for (var i = 0; i < props.length; i++) {
            var name = props[i];

            if ((proto.__lookupGetter__ ? proto.__lookupGetter__(name)
                    : Object.getOwnPropertyDescriptor(proto, name))
                || typeof proto[name] !== "function")
                continue;

            var func = proto[name];
            if (hasGetter && func === getter) {
                getterName = name;
                if (!hasSetter || setterName) break;
            }
            if (hasSetter && func === setter) {
                setterName = name;
                if (!hasGetter || getterName) break;
            }
        }
    }

    // Found getter/setter
    var ctor = proto.constructor;
    if (getterName) {
        if (!ctor.__getters__) {
            ctor.__getters__ = {};
        }
        ctor.__getters__[getterName] = prop;
    }
    if (setterName) {
        if (!ctor.__setters__) {
            ctor.__setters__ = {};
        }
        ctor.__setters__[setterName] = prop;
    }
};

wb.SysCore.ClassManager = {
    id: (0 | (Math.random() * 998)),
    instanceId: (0 | (Math.random() * 998)),
    getNewID: function () {
        return this.id++;
    },
    getNewInstanceId: function () {
        return this.instanceId++;
    }
};


(function () {
    var fnTest = /\b_super\b/;

    wb.Class = function () {
    };

    wb.Class.extend = function (props) {
        var _super = this.prototype;
        var prototype = Object.create(_super);

        var desc = {writable: true, enumerable: false, configurable: true};
        // The dummy Class constructor
        var Class;

        Class = function (arg0, arg1, arg2, arg3, arg4) {
            this.__instanceId = wb.SysCore.ClassManager.getNewInstanceId();
            if (this.ctor) {
                switch (arguments.length) {
                    case 0:
                        this.ctor();
                        break;
                    case 1:
                        this.ctor(arg0);
                        break;
                    case 2:
                        this.ctor(arg0, arg1);
                        break;
                    case 3:
                        this.ctor(arg0, arg1, arg2);
                        break;
                    case 4:
                        this.ctor(arg0, arg1, arg2, arg3);
                        break;
                    case 5:
                        this.ctor(arg0, arg1, arg2, arg3, arg4);
                        break;
                    default:
                        this.ctor.apply(this, arguments);
                }
            }
        };

        desc.value = wb.SysCore.ClassManager.getNewID();
        Object.defineProperty(prototype, '__pid', desc);
        Class.prototype = prototype;


        desc.value = Class;
        Object.defineProperty(prototype, 'constructor', desc);

        // Copy getter/setter
        this.__getters__ && (Class.__getters__ = wb.clone(this.__getters__));
        this.__setters__ && (Class.__setters__ = wb.clone(this.__setters__));

        for (var idx = 0, li = arguments.length; idx < li; ++idx) {
            var prop = arguments[idx];
            for (var name in prop) {
                var isFunc = (typeof prop[name] === "function");
                var override = (typeof _super[name] === "function");
                var hasSuperCall = fnTest.test(prop[name]);

                if (isFunc && override && hasSuperCall) {
                    desc.value = (function (name, fn) {
                        return function () {
                            var tmp = this._super;

                            // Add a new ._super() method that is the same method
                            // but on the super-Class
                            this._super = _super[name];

                            // The method only need to be bound temporarily, so we
                            // remove it when we're done executing
                            var ret = fn.apply(this, arguments);
                            this._super = tmp;

                            return ret;
                        };
                    })(name, prop[name]);
                    Object.defineProperty(prototype, name, desc);
                } else if (isFunc) {
                    desc.value = prop[name];
                    Object.defineProperty(prototype, name, desc);
                } else {
                    prototype[name] = prop[name];
                }

                if (isFunc) {
                    // Override registered getter/setter
                    var getter, setter, propertyName;
                    if (this.__getters__ && this.__getters__[name]) {
                        propertyName = this.__getters__[name];
                        for (var i in this.__setters__) {
                            if (this.__setters__[i] === propertyName) {
                                setter = i;
                                break;
                            }
                        }
                        wb.SysCore.defineGetterSetter(prototype, propertyName, prop[name], prop[setter] ? prop[setter] : prototype[setter], name, setter);
                    }
                    if (this.__setters__ && this.__setters__[name]) {
                        propertyName = this.__setters__[name];
                        for (var i in this.__getters__) {
                            if (this.__getters__[i] === propertyName) {
                                getter = i;
                                break;
                            }
                        }
                        wb.SysCore.defineGetterSetter(prototype, propertyName, prop[getter] ? prop[getter] : prototype[getter], prop[name], getter, name);
                    }
                }
            }
        }

        Class.extend = wb.Class.extend;
        Class.implement = function (prop) {
            for (var name in prop) {
                prototype[name] = prop[name];
            }
        };
        return Class;
    };
})();

