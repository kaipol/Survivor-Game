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

signals:
    void changeWidgetsignal(int Index); // 切换窗口信号

private:
    QLabel *success_label;   // 购买成功标签
    QLabel *fail_label;      // 购买失败标签
    QPushButton *buy_button; // 购买按钮
};