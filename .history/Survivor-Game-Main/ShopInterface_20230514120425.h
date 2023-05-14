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
    void buy_label(int); // 购买标签信号
    void get_coin(int);  // 获取金币

signals:
    void changeWidgetsignal(int Index); // 切换窗口信号
    void buy_status_signal(int status); // 购买状态信号

private:
    QLabel *success_label; // 购买成功标签
    QLabel *fail_label;    // 购买失败标签
    QLabel *coin_label;    // 金币标签

    Prop *prop1; // 道具
    Prop *prop2; // 道具
    Prop *prop3; // 道具

    int coin;                 // 金币
    QPushButton *buy_button1; // 购买按钮
    QPushButton *buy_button2; // 购买按钮
    QPushButton *buy_button3; // 购买按钮
    QTimer *timer;            // 定时器
};
#endif // _SHOPINTERFACE_H_