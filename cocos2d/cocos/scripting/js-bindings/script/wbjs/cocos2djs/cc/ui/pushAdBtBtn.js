/**
 * Created by zack on 2018/7/30.
 */
var wb = window.wb || {};

// 互推按钮数据来自 bottomList
wb.PushAdBtBtn = wb.PushAdBtn.extend({
    ctor: function (dataIndex, pushData, nSize, loopTime) {
        this._super(dataIndex, pushData, nSize, loopTime);
        this.addNameLabel();
    },
    addNameLabel: function () {
        var nameLabel = new cc.LabelTTF("", "", 20);
        this.addChild(nameLabel);
        nameLabel.x = this.nSize.width / 2;
        nameLabel.y = - 20;
        this.nameLabel = nameLabel;

        this.flushNameLabel();
    },
    flushNameLabel: function () {
        this.nameLabel.setString(wb.subStr(this.data.gameName,8));
    }
});


wb.createBtBtn = function (dataIndex, pushData, nSize, loopTime) {
    return new wb.PushAdBtBtn(dataIndex, pushData, nSize, loopTime);
};