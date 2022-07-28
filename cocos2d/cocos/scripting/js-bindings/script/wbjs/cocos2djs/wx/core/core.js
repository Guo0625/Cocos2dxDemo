/**
 * Created by Zack on 2019/2/13.
 */

(function () {
    if (!wb.SysPlatform.isWX()) return;
    cc.ContainerStrategy.prototype._setupContainer = function (view, w, h) {
        var locCanvas = cc.game.canvas, locContainer = cc.game.container;
        if (!window.wx && cc.sys.os === cc.sys.OS_ANDROID) {
            document.body.style.width = (view._isRotated ? h : w) + 'px';
            document.body.style.height = (view._isRotated ? w : h) + 'px';
        }
        // Setup style
        locContainer.style.width = locCanvas.style.width = w + 'px';
        locContainer.style.height = locCanvas.style.height = h + 'px';    // Setup pixel ratio for retina display
        var devicePixelRatio = view._devicePixelRatio = 1;
        if (view.isRetinaEnabled()) {
            devicePixelRatio = view._devicePixelRatio = window.devicePixelRatio || 1;
        }    // Setup canvas
        locCanvas.width = w * devicePixelRatio;
        locCanvas.height = h * devicePixelRatio;
    };
})();

