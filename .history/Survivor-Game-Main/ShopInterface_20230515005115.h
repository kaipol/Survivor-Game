#ifndef _SHOPINTERFACE_H_
#define _SHOPINTERFACE_H_
#pragma once

#include <QPainter>
#include <QLabel>
#include <QTimer>
#include <QPushButton>
#include "Prop.h"

class ShopInterface : public QWidget
{
    Q_OBJECT
public:
    ShopInterface(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event); // 绘制事件

public slots:
    void buy_event(int); // 购买事件
    void get_coin(int);  // 获取金币

signals:
    void changeWidgetsignal(int Index); // 切换窗口信号
    void prop_type(int);                // 道具类型信号

private:
    QLabel *success_label; // 购买成功标签
    QLabel *fail_label;    // 购买失败标签
    QLabel *coin_label;    // 金币标签
    int label_type_showed = 0;

    Prop *prop1;         // 道具1:攻击+3
    QLabel *prop1_label; // 道具标签
    Prop *prop2;         // 道具2：速度+5
    QLabel *prop2_label; // 道具标签
    Prop *prop3;         // 道具3：复活次数+1
    QLabel *prop3_label; // 道具标签
    Prop *prop4;         // 道具4：金币获取系数+1
    QLabel *prop4_label; // 道具标签
    Prop *prop5;         // 道具5：血量+3
    QLabel *prop5_label; // 道具标签

    int coin;                 // 金币
    QPushButton *buy_button1; // 购买按钮
    QPushButton *buy_button2; // 购买按钮
    QPushButton *buy_button3; // 购买按钮
    QPushButton *buy_button4; // 购买按钮
    QPushButton *buy_button5; // 购买按钮
    QTimer *timer;            // 定时器
};
#endif // _SHOPINTERFACE_H_