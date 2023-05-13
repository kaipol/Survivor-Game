#include "ShopInterface.h"

ShopInterface::ShopInterface(QWidget *parent) : QWidget(parent)
{
    timer = new QTimer(this);                                          // 创建定时器
    connect(timer, &QTimer::timeout, this, &ShopInterface::buy_label); // 定时器信号连接
    success_label = new QLabel(this);                                  // 创建标签
    fail_label = new QLabel(this);                                     // 创建标签

    buy_button1 = new QPushButton(this); // 创建按钮
    buy_button2 = new QPushButton(this); // 创建按钮
    buy_button3 = new QPushButton(this); // 创建按钮
    connect(buy_button1, &QPushButton::clicked, this, [=]()
            { buy_event(1); }); // 按钮信号连接
}

void ShopInterface::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load("../src/shop.jpg");
    painter.drawPixmap(0, 0, 1000, 800, pix);
}

void ShopInterface::buy_event(int type)
{
    switch (type)
    {
    case 1:

        emit buy_status_signal(1);
        break;
    case 2:
        emit buy_status_signal(2);
        break;
    case 3:
        emit buy_status_signal(3);
        break;
    default:
        break;
    }
    timer->start(1000);
}

void ShopInterface::buy_label(int type)
{
}