#include "ShopInterface.h"

ShopInterface::ShopInterface(QWidget *parent) : QWidget(parent)
{
    timer = new QTimer(this);                                          // 创建定时器
    connect(timer, &QTimer::timeout, this, &ShopInterface::buy_label); // 定时器信号连接
    success_label = new QLabel(this);                                  // 创建标签
    fail_label = new QLabel(this);                                     // 创建标签

    buy_button1 = new QPushButton(this); // 创建按钮
}

void ShopInterface::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load("../src/shop.jpg");
    painter.drawPixmap(0, 0, 1000, 800, pix);
}

void ShopInterface::buy_label()
{

    success_label->hide();
    fail_label->hide();
}