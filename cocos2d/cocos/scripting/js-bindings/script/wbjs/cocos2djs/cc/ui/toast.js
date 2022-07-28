/**
 * Created by Zack on 2018/4/10.
 */
var wb = window.wb || {};

wb.Toast = {
    makeText: function (text, posYStart, posYEnd, runTime, deleyTime) {
        if (!posYStart) posYStart = 0;
        if (!posYEnd) posYEnd = 60;
        if (!runTime) runTime = 0.1;
        if (!deleyTime) deleyTime = 2;

        var winSize = wb.getWinSize();
        var bg = new cc.LayerColor(cc.color(0, 0, 0, 180));

        var label = new cc.LabelTTF(text, "Arial", 30);
        bg.addChild(label, 1);

        var labelSize = label.getContentSize();
        bg.setContentSize(cc.size(labelSize.width + 25, labelSize.height + 15));
        bg.setPosition(cc.p(winSize.width / 2 - bg.getContentSize().width / 2, posYEnd - bg.getContentSize().height));
        label.setPosition(cc.p(bg.getContentSize().width / 2, bg.getContentSize().height / 2));

        bg.runAction(cc.sequence(
            cc.moveBy(runTime, cc.p(0, posYEnd)),
            cc.delayTime(deleyTime),
            cc.fadeOut(0.2),
            cc.removeSelf()));

        wb.addNodeToScene(bg);
    }
};