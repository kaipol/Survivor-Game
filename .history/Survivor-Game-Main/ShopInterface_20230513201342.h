#ifndef _SHOPINTERFACE_H_
#define _SHOPINTERFACE_H_
#endif // _SHOPINTERFACE_H_
#pragma once

#include <QPainter>
#include <QLabel>

class ShopInterface : public QWidget
{
    Q_OBJECT
public:
    ShopInterface(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event); // 绘制事件

public slots:
    void back_to_main();

signals:
    void changeWidgetsignal(int Index); // 切换窗口信号
};