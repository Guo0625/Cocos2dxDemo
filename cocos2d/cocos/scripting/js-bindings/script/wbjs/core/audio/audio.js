/**
 * Created by Zack on 2018/11/14.
 */

var wb = window.wb || {};
/**
 * Audio support in the browser
 *
 * MULTI_CHANNEL        : Multiple audio while playing - If it doesn't, you can only play background music
 * WEB_AUDIO            : Support for WebAudio - Support W3C WebAudio standards, all of the audio can be played
 * AUTOPLAY             : Supports auto-play audio - if Don‘t support it, On a touch detecting background music canvas, and then replay
 * REPLAY_AFTER_TOUCH   : The first music will fail, must be replay after touchstart
 * USE_EMPTIED_EVENT    : Whether to use the emptied event to replace load callback
 * DELAY_CREATE_CTX     : delay created the context object - only webAudio
 * NEED_MANUAL_LOOP     : loop attribute failure, need to perform loop manually
 *
 * May be modifications for a few browser version
 */
(function () {

    var DEBUG = false;

    var sys = wb.SysPlatform;
    var version = sys.browserVersion;

    // check if browser supports Web Audio
    // check Web Audio's context
    var supportWebAudio = !!(window.AudioContext || window.webkitAudioContext || window.mozAudioContext);

    var support = {ONLY_ONE: false, WEB_AUDIO: supportWebAudio, DELAY_CREATE_CTX: false, ONE_SOURCE: false};

    if (sys.browserType === sys.BROWSER_TYPE_FIREFOX) {
        support.DELAY_CREATE_CTX = true;
        support.USE_LOADER_EVENT = 'canplay';
    }

    if (sys.os === sys.OS_IOS) {
        support.USE_LOADER_EVENT = 'loadedmetadata';
    }

    if (sys.os === sys.OS_ANDROID) {
        if (sys.browserType === sys.BROWSER_TYPE_UC) {
            support.ONE_SOURCE = true;
        }
    }

    window.__audioSupport = support;

    if (DEBUG) {
        setTimeout(function () {
            wb.log("browse type: " + sys.browserType);
            wb.log("browse version: " + version);
            wb.log("MULTI_CHANNEL: " + window.__audioSupport.MULTI_CHANNEL);
            wb.log("WEB_AUDIO: " + window.__audioSupport.WEB_AUDIO);
            wb.log("AUTOPLAY: " + window.__audioSupport.AUTOPLAY);
        }, 0);
    }

})();


// Encapsulate DOM and webAudio
wb.Audio = wb.Class.extend({
    interruptPlay: false,
    src: null,
    _element: null,
    _AUDIO_TYPE: "AUDIO",

    ctor: function (url) {
        this.src = url;
    },

    setBuffer: function (buffer) {
        this._AUDIO_TYPE = "WEBAUDIO";
        this._element = new wb.Audio.WebAudio(buffer);
    },

    setElement: function (element) {
        this._AUDIO_TYPE = "AUDIO";
        this._element = element;

        // Prevent partial browser from playing after the end does not reset the paused tag
        // Will cause the player to judge the status of the error
        element.addEventListener('ended', function () {
            if (!element.loop) {
                element.paused = true;
            }
        });
    },

    play: function (offset, loop) {
        if (!this._element) {
            this.interruptPlay = false;
            return;
        }
        this._element.loop = loop;
        this._element.play();
        if (this._AUDIO_TYPE === 'AUDIO' && this._element.paused) {
            if (!window.wx) {
                this.stop();
                wb.Audio.touchPlayList.push({loop: loop, offset: offset, audio: this._element});
            }
        }

        if (wb.Audio.bindTouch === false) {
            wb.Audio.bindTouch = true;
            // Listen to the touchstart body event and play the audio when necessary.

        }
    },

    getPlaying: function () {
        if (!this._element) return true;
        return !this._element.paused;
    },

    stop: function () {
        if (!this._element) {
            this.interruptPlay = true;
            return;
        }
        this._element.pause();
        try {
            this._element.currentTime = 0;
        } catch (err) {
        }
    },

    pause: function () {
        if (!this._element) {
            this.interruptPlay = true;
            return;
        }
        this._element.pause();
    },

    resume: function () {
        if (!this._element) {
            this.interruptPlay = false;
            return;
        }
        this._element.play();
    },

    setVolume: function (volume) {
        if (!this._element) return;
        this._element.volume = volume;
    },

    getVolume: function () {
        if (!this._element) return;
        return this._element.volume;
    },

    cloneNode: function () {
        var audio = new wb.Audio(this.src);
        if (this._AUDIO_TYPE === "AUDIO") {
            var elem = document.createElement("audio");
            if (window.wx) {
                elem.src = this.src;
            } else {
                var sources = elem.getElementsByTagName('source');
                for (var i = 0; i < sources.length; i++) {
                    elem.appendChild(sources[i]);
                }
            }
            audio.setElement(elem);
        } else {
            audio.setBuffer(this._element.buffer);
        }
        return audio;
    }
});

wb.Audio.touchPlayList = [
    //{ offset: 0, audio: audio }
];

wb.Audio.bindTouch = false;
wb.Audio.touchStart = function () {
    var list = wb.Audio.touchPlayList;
    var item = null;
    while (item = list.pop()) {
        item.audio.loop = !!item.loop;
        item.audio.play(item.offset);
    }
};

wb.Audio.WebAudio = function (buffer) {
    this.buffer = buffer;
    this.context = wb.Audio._context;

    var volume = this.context['createGain']();
    volume['gain'].value = 1;
    volume['connect'](this.context['destination']);
    this._volume = volume;

    this._loop = false;

    // The time stamp on the audio time axis when the recording begins to play.
    this._startTime = -1;
    // Record the currently playing Source
    this._currentSource = null;
    // Record the time has been played
    this.playedLength = 0;

    this._currextTimer = null;
};

wb.Audio.WebAudio.prototype = {
    constructor: wb.Audio.WebAudio,

    get paused() {
        // If the current audio is a loop, then paused is false
        if (this._currentSource && this._currentSource.loop)
            return false;

        // StartTime does not have value, as the default -1, it does not begin to play
        if (this._startTime === -1)
            return true;

        // currentTime - startTime > durationTime
        return this.context.currentTime - this._startTime > this.buffer.duration;
    },
    set paused(bool) {
    },

    get loop() {
        return this._loop;
    },
    set loop(bool) {
        return this._loop = bool;
    },

    get volume() {
        return this._volume['gain'].value;
    },
    set volume(num) {
        return this._volume['gain'].value = num;
    },

    get currentTime() {
        return this.playedLength;
    },
    set currentTime(num) {
        return this.playedLength = num;
    },

    play: function (offset) {

        // If repeat play, you need to stop before an audio
        if (this._currentSource && !this.paused) {
            this._currentSource.stop(0);
            this.playedLength = 0;
        }

        var audio = this.context["createBufferSource"]();
        audio.buffer = this.buffer;
        audio["connect"](this._volume);
        audio.loop = this._loop;

        this._startTime = this.context.currentTime;
        offset = offset || this.playedLength;

        var duration = this.buffer.duration;
        if (!this._loop) {
            if (audio.start)
                audio.start(0, offset, duration - offset);
            else if (audio["notoGrainOn"])
                audio["noteGrainOn"](0, offset, duration - offset);
            else
                audio["noteOn"](0, offset, duration - offset);
        } else {
            if (audio.start)
                audio.start(0);
            else if (audio["notoGrainOn"])
                audio["noteGrainOn"](0);
            else
                audio["noteOn"](0);
        }

        this._currentSource = audio;

        // If the current audio context time stamp is 0
        // There may be a need to touch events before you can actually start playing audio
        // So here to add a timer to determine whether the real start playing audio, if not, then the incoming touchPlay queue
        if (this.context.currentTime === 0) {
            var self = this;
            clearTimeout(this._currextTimer);
            this._currextTimer = setTimeout(function () {
                if (self.context.currentTime === 0) {
                    wb.Audio.touchPlayList.push({
                        offset: offset,
                        audio: self
                    });
                }
            }, 10);
        }
    },
    pause: function () {
        // Record the time the current has been played
        this.playedLength = this.context.currentTime - this._startTime;
        //If the duration of playedLendth exceeds the audio, you should take the remainder
        this.playedLength %= this.buffer.duration;
        var audio = this._currentSource;
        this._currentSource = null;
        this._startTime = -1;
        if (audio)
            audio.stop(0);
    }
};

(function (polyfill) {



    var SWA = polyfill.WEB_AUDIO, SWB = polyfill.ONLY_ONE;

    var support = [];

    (function () {
        if (wb.SysPlatform.isNative()) return;
        var audio = document.createElement("audio");
        if (audio.canPlayType) {
            var ogg = audio.canPlayType('audio/ogg; codecs="vorbis"');
            if (ogg && ogg !== "") support.push(".ogg");
            var mp3 = audio.canPlayType("audio/mpeg");
            if (mp3 && mp3 !== "") support.push(".mp3");
            var wav = audio.canPlayType('audio/wav; codecs="1"');
            if (wav && wav !== "") support.push(".wav");
            var mp4 = audio.canPlayType("audio/mp4");
            if (mp4 && mp4 !== "") support.push(".mp4");
            var m4a = audio.canPlayType("audio/x-m4a");
            if (m4a && m4a !== "") support.push(".m4a");
        }
    })();
    try {
        if (SWA) {
            var context = new (window.AudioContext || window.webkitAudioContext || window.mozAudioContext)();
            wb.Audio._context = context;
            // check context integrity
            if (
                !context["createBufferSource"] || !context["createGain"] || !context["destination"] || !context["decodeAudioData"]
            ) {
                throw 'context is incomplete';
            }
            if (polyfill.DELAY_CREATE_CTX)
                setTimeout(function () {
                    context = new (window.AudioContext || window.webkitAudioContext || window.mozAudioContext)();
                    wb.Audio._context = context;
                }, 0);
        }
    } catch (error) {
        SWA = false;
        wb.log("browser don't support web audio");
    }

    var loader = {

        cache: {},

        useWebAudio: true,

        loadBuffer: function (url, cb) {
            if (!SWA) return; // WebAudio Buffer

            var request = wb.Http.getXMLHttpRequest();
            request.open("GET", url, true);
            request.responseType = "arraybuffer";

            // Our asynchronous callback
            request.onload = function () {
                if (request._timeoutId >= 0) {
                    clearTimeout(request._timeoutId);
                }
                context["decodeAudioData"](request.response, function (buffer) {
                    //success
                    cb(null, buffer);
                    //audio.setBuffer(buffer);
                }, function () {
                    //error
                    cb('decode error - ' + url);
                });
            };

            request.onerror = function () {
                cb('request error - ' + url);
            };
            if (request.ontimeout === undefined) {
                request._timeoutId = setTimeout(function () {
                    request.ontimeout();
                }, request.timeout);
            }
            request.ontimeout = function () {
                cb('request timeout - ' + url);
            };

            request.send();
        },

        load: function (realUrl, url, res, cb) {

            if (support.length === 0) return cb("can not support audio!");

            var audio = wb.Loader.getRes(url);
            if (audio) return cb(null, audio);

            if (wb.Loader.audioPath) realUrl = wb.Path.join(wb.Loader.audioPath, realUrl);

            var extname = wb.Path.extname(realUrl);

            var typeList = [extname];
            for (var i = 0; i < support.length; i++) {
                if (extname !== support[i]) {
                    typeList.push(support[i]);
                }
            }

            audio = new wb.Audio(realUrl);
            wb.Loader.cache[url] = audio;
            this.loadAudioFromExtList(realUrl, typeList, audio, cb);
            return audio;
        },

        loadAudioFromExtList: function (realUrl, typeList, audio, cb) {
            if (window.REMOTE_SERVER_ROOT === undefined)
                window.REMOTE_SERVER_ROOT = '';
            realUrl = window.REMOTE_SERVER_ROOT + realUrl;
            if (typeList.length === 0) {
                var ERRSTR = "can not found the resource of audio! Last match url is : ";
                ERRSTR += realUrl.replace(/\.(.*)?$/, "(");
                support.forEach(function (ext) {
                    ERRSTR += ext + "|";
                });
                ERRSTR = ERRSTR.replace(/\|$/, ")");
                return cb({status: 520, errorMessage: ERRSTR}, null);
            }

            if (SWA && this.useWebAudio) {
                this.loadBuffer(realUrl, function (error, buffer) {
                    if (error)
                        wb.log(error);

                    if (buffer)
                        audio.setBuffer(buffer);

                    cb(null, audio);
                });
                return;
            }

            var num = polyfill.ONE_SOURCE ? 1 : typeList.length;

            // 加载统一使用dom
            var dom = document.createElement('audio');

            if (window.wx) {
                dom.src = wb.Path.changeExtname(realUrl, typeList[0]);
            } else {
                for (var i = 0; i < num; i++) {
                    var source = document.createElement('source');
                    source.src = wb.Path.changeExtname(realUrl, typeList[i]);
                    dom.appendChild(source);
                }
            }

            audio.setElement(dom);
            var timer = setTimeout(function () {
                if (dom.readyState === 0) {
                    console.log("loadAudioFromExtList timeout 8000");
                    failure();
                } else {
                    success();
                }
            }, 8000);

            var success = function () {
                dom.removeEventListener("canplaythrough", success, false);
                dom.removeEventListener("error", failure, false);
                dom.removeEventListener("emptied", success, false);
                if (polyfill.USE_LOADER_EVENT)
                    dom.removeEventListener(polyfill.USE_LOADER_EVENT, success, false);
                clearTimeout(timer);
                cb(null, audio);
            };
            var failure = function () {
                wb.log('load audio failure - ' + realUrl);
                success();
            };
            dom.addEventListener("canplaythrough", success, false);
            dom.addEventListener("error", failure, false);
            if (polyfill.USE_LOADER_EVENT)
                dom.addEventListener(polyfill.USE_LOADER_EVENT, success, false);
        }
    };
    wb.Loader.register(["mp3", "ogg", "wav", "mp4", "m4a"], loader);

    /**
     * wb.audioEngine is the singleton object, it provide simple audio APIs.
     * @namespace
     */
    wb.audioEngine = {
        _currMusic: null,
        _musicVolume: 1,

        features: polyfill,

        /**
         * Indicates whether any background music can be played or not.
         * @returns {boolean} <i>true</i> if the background music is playing, otherwise <i>false</i>
         */
        willPlayMusic: function () {
            return false;
        },

        /**
         * Play music.
         * @param {String} url The path of the music file without filename extension.
         * @param {Boolean} loop Whether the music loop or not.
         * @example
         * //example
         * wb.audioEngine.playMusic(path, false);
         */
        playMusic: function (url, loop) {
            if (wb.SysPlatform.isNative()) return;
            var bgMusic = this._currMusic;
            if (bgMusic && bgMusic.getPlaying()) {
                bgMusic.stop();
            }
            var musicVolume = this._musicVolume;
            var audio = wb.Loader.getRes(url);
            if (!audio) {
                wb.Loader.load(url, function () {
                    if (!audio.getPlaying() && !audio.interruptPlay) {
                        audio.setVolume(musicVolume);
                        audio.play(0, loop || false);
                    }
                });
                audio = wb.Loader.getRes(url);
            }
            audio.setVolume(musicVolume);
            audio.play(0, loop || false);

            this._currMusic = audio;
        },

        /**
         * Stop playing music.
         * @param {Boolean} [releaseData] If release the music data or not.As default value is false.
         * @example
         * //example
         * wb.audioEngine.stopMusic();
         */
        stopMusic: function (releaseData) {
            if (wb.SysPlatform.isNative()) return;
            var audio = this._currMusic;
            if (audio) {
                var list = wb.Audio.touchPlayList;
                for (var i = list.length - 1; i >= 0; --i) {
                    if (this[i] && this[i].audio === audio._element)
                        list.splice(i, 1);
                }

                audio.stop();
                this._currMusic = null;
                if (releaseData)
                    wb.Loader.release(audio.src);
            }
        },

        /**
         * Pause playing music.
         * @example
         * //example
         * wb.audioEngine.pauseMusic();
         */
        pauseMusic: function () {
            if (wb.SysPlatform.isNative()) return;
            var audio = this._currMusic;
            if (audio)
                audio.pause();
        },

        /**
         * Resume playing music.
         * @example
         * //example
         * wb.audioEngine.resumeMusic();
         */
        resumeMusic: function () {
            if (wb.SysPlatform.isNative()) return;
            var audio = this._currMusic;
            if (audio)
                audio.resume();
        },

        //T-Add Begin
        preLoadEffect: function (url) {
            if (wb.SysPlatform.isNative()) return;
            var audio = wb.Loader.getRes(url);

            if (audio && SWA && audio._AUDIO_TYPE === 'AUDIO') {
                wb.Loader.release(url);
                audio = null;
            }

            var effectList = this._audioPool[url];
            if (!effectList) {
                effectList = this._audioPool[url] = [];
            }

            if (audio) {
                if (SWA && audio._AUDIO_TYPE === 'AUDIO') {
                    loader.loadBuffer(url, function (error, buffer) {
                        audio.setBuffer(buffer);
                        audio.setVolume(wb.audioEngine._effectVolume);
                    });
                } else {
                    audio = audio.cloneNode();
                    audio.setVolume(this._effectVolume);
                    effectList.push(audio);
                    return;
                }

            }

            wb.Loader.load(url, function (audio) {
                audio = wb.Loader.getRes(url);
                audio = audio.cloneNode();
                audio.setVolume(wb.audioEngine._effectVolume);
                effectList.push(audio);
            });
        },
        //T-Add End

        /**
         * Rewind playing music.
         * @example
         * //example
         * wb.audioEngine.rewindMusic();
         */
        rewindMusic: function () {
            if (wb.SysPlatform.isNative()) return;
            var audio = this._currMusic;
            if (audio) {
                audio.stop();
                audio.play();
            }
        },

        /**
         * The volume of the music max value is 1.0,the min value is 0.0 .
         * @return {Number}
         * @example
         * //example
         * var volume = wb.audioEngine.getMusicVolume();
         */
        getMusicVolume: function () {
            if (wb.SysPlatform.isNative()) return 0;
            return this._musicVolume;
        },

        /**
         * Set the volume of music.
         * @param {Number} volume Volume must be in 0.0~1.0 .
         * @example
         * //example
         * wb.audioEngine.setMusicVolume(0.5);
         */
        setMusicVolume: function (volume) {
            if (wb.SysPlatform.isNative()) return;
            volume = volume - 0;
            if (isNaN(volume)) volume = 1;
            if (volume > 1) volume = 1;
            if (volume < 0) volume = 0;

            this._musicVolume = volume;
            var audio = this._currMusic;
            if (audio) {
                audio.setVolume(volume);
            }
        },

        /**
         * Whether the music is playing.
         * @return {Boolean} If is playing return true,or return false.
         * @example
         * //example
         *  if (wb.audioEngine.isMusicPlaying()) {
         *      wb.log("music is playing");
         *  }
         *  else {
         *      wb.log("music is not playing");
         *  }
         */
        isMusicPlaying: function () {
            if (wb.SysPlatform.isNative()) return false;
            var audio = this._currMusic;
            if (audio) {
                return audio.getPlaying();
            } else {
                return false;
            }
        },

        _audioPool: {},
        _maxAudioInstance: 10,
        _effectVolume: 1,
        /**
         * Play sound effect.
         * @param {String} url The path of the sound effect with filename extension.
         * @param {Boolean} loop Whether to loop the effect playing, default value is false
         * @return {Number|null} the audio id
         * @example
         * //example
         * var soundId = wb.audioEngine.playEffect(path);
         */
        playEffect: function (url, loop) {
            if (wb.SysPlatform.isNative()) return;
            if (window.wx) {
                var audio = wb.Loader.getRes(url);
                if (!audio) {
                    wb.Loader.load(url, function () {
                        audio.setVolume(wb.audioEngine._effectVolume);
                        audio.play(0, loop || false);
                    });
                    audio = wb.Loader.getRes(url);
                }
                audio.setVolume(wb.audioEngine._effectVolume);
                audio.play(0, loop || false);
                return
            }

            if (SWB && this._currMusic && this._currMusic.getPlaying()) {
                wb.log('Browser is only allowed to play one audio');
                return null;
            }

            var effectList = this._audioPool[url];
            if (!effectList) {
                effectList = this._audioPool[url] = [];
            }

            for (var i = 0; i < effectList.length; i++) {
                if (!effectList[i].getPlaying()) {
                    break;
                }
            }

            if (!SWA && i > this._maxAudioInstance) {
                var first = effectList.shift();
                first.stop();
                effectList.push(first);
                i = effectList.length - 1;
                // wb.log("Error: %s greater than %d", url, this._maxAudioInstance);
            }

            var audio;
            if (effectList[i]) {
                audio = effectList[i];
                audio.setVolume(this._effectVolume);
                audio.play(0, loop || false);
                return audio;
            }

            audio = wb.Loader.getRes(url);

            if (audio && SWA && audio._AUDIO_TYPE === 'AUDIO') {
                wb.Loader.release(url);
                audio = null;
            }

            if (audio) {

                if (SWA && audio._AUDIO_TYPE === 'AUDIO') {
                    loader.loadBuffer(url, function (error, buffer) {
                        audio.setBuffer(buffer);
                        audio.setVolume(wb.audioEngine._effectVolume);
                        if (!audio.getPlaying())
                            audio.play(0, loop || false);
                    });
                } else {
                    audio = audio.cloneNode();
                    audio.setVolume(this._effectVolume);
                    audio.play(0, loop || false);
                    effectList.push(audio);
                    return audio;
                }

            }

            var cache = loader.useWebAudio;
            loader.useWebAudio = true;
            wb.Loader.load(url, function (audio) {
                audio = wb.Loader.getRes(url);
                audio = audio.cloneNode();
                audio.setVolume(wb.audioEngine._effectVolume);
                audio.play(0, loop || false);
                effectList.push(audio);
            });
            loader.useWebAudio = cache;

            return audio;
        },

        /**
         * Set the volume of sound effects.
         * @param {Number} volume Volume must be in 0.0~1.0 .
         * @example
         * //example
         * wb.audioEngine.setEffectsVolume(0.5);
         */
        setEffectsVolume: function (volume) {
            if (wb.SysPlatform.isNative()) return;
            volume = volume - 0;
            if (isNaN(volume)) volume = 1;
            if (volume > 1) volume = 1;
            if (volume < 0) volume = 0;

            this._effectVolume = volume;
            var audioPool = this._audioPool;
            for (var p in audioPool) {
                var audioList = audioPool[p];
                if (Array.isArray(audioList))
                    for (var i = 0; i < audioList.length; i++) {
                        audioList[i].setVolume(volume);
                    }
            }
        },

        /**
         * The volume of the effects max value is 1.0,the min value is 0.0 .
         * @return {Number}
         * @example
         * //example
         * var effectVolume = wb.audioEngine.getEffectsVolume();
         */
        getEffectsVolume: function () {
            return this._effectVolume;
        },

        /**
         * Pause playing sound effect.
         * @param {Number} audio The return value of function playEffect.
         * @example
         * //example
         * wb.audioEngine.pauseEffect(audioID);
         */
        pauseEffect: function (audio) {
            if (wb.SysPlatform.isNative()) return;
            if (audio) {
                audio.pause();
            }
        },

        /**
         * Pause all playing sound effect.
         * @example
         * //example
         * wb.audioEngine.pauseAllEffects();
         */
        pauseAllEffects: function () {
            if (wb.SysPlatform.isNative()) return;
            var ap = this._audioPool;
            for (var p in ap) {
                var list = ap[p];
                for (var i = 0; i < ap[p].length; i++) {
                    if (list[i].getPlaying()) {
                        list[i].pause();
                    }
                }
            }
        },

        /**
         * Resume playing sound effect.
         * @param {Number} audio The return value of function playEffect.
         * @audioID
         * //example
         * wb.audioEngine.resumeEffect(audioID);
         */
        resumeEffect: function (audio) {
            if (wb.SysPlatform.isNative()) return;
            if (audio)
                audio.resume();
        },

        /**
         * Resume all playing sound effect
         * @example
         * //example
         * wb.audioEngine.resumeAllEffects();
         */
        resumeAllEffects: function () {
            if (wb.SysPlatform.isNative()) return;
            var ap = this._audioPool;
            for (var p in ap) {
                var list = ap[p];
                for (var i = 0; i < ap[p].length; i++) {
                    list[i].resume();
                }
            }
        },

        /**
         * Stop playing sound effect.
         * @param {Number} audio The return value of function playEffect.
         * @example
         * //example
         * wb.audioEngine.stopEffect(audioID);
         */
        stopEffect: function (audio) {
            if (wb.SysPlatform.isNative()) return;
            if (audio) {
                audio.stop();
            }
        },

        /**
         * Stop all playing sound effects.
         * @example
         * //example
         * wb.audioEngine.stopAllEffects();
         */
        stopAllEffects: function () {
            if (wb.SysPlatform.isNative()) return;
            var ap = this._audioPool;
            for (var p in ap) {
                var list = ap[p];
                for (var i = 0; i < list.length; i++) {
                    list[i].stop();
                }
                list.length = 0;
            }
            ap.length = 0;
        },

        /**
         * Unload the preloaded effect from internal buffer
         * @param {String} url
         * @example
         * //example
         * wb.audioEngine.unloadEffect(EFFECT_FILE);
         */
        unloadEffect: function (url) {
            if (wb.SysPlatform.isNative()) return;
            if (!url) {
                return;
            }

            wb.Loader.release(url);
            var pool = this._audioPool[url];
            if (pool) {
                for (var i = 0; i < pool.length; i++) {
                    pool[i].stop();
                }
                pool.length = 0;
            }
            delete this._audioPool[url];
        },

        /**
         * End music and effects.
         */
        end: function () {
            if (wb.SysPlatform.isNative()) return;
            this.stopMusic();
            this.stopAllEffects();
        },

        _pauseCache: [],
        _pausePlaying: function () {
            var bgMusic = this._currMusic;
            if (bgMusic && bgMusic.getPlaying()) {
                bgMusic.pause();
                this._pauseCache.push(bgMusic);
            }
            var ap = this._audioPool;
            for (var p in ap) {
                var list = ap[p];
                for (var i = 0; i < ap[p].length; i++) {
                    if (list[i].getPlaying()) {
                        list[i].pause();
                        this._pauseCache.push(list[i]);
                    }
                }
            }
        },

        _resumePlaying: function () {
            var list = this._pauseCache;
            for (var i = 0; i < list.length; i++) {
                list[i].resume();
            }
            list.length = 0;
        }
    };

})(window.__audioSupport);

wb.AudioEngine = wb.audioEngine;