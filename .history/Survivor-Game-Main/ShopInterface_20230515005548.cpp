#include "ShopInterface.h"

ShopInterface::ShopInterface(QWidget *parent) : QWidget(parent)
{
    timer = new QTimer(this);                                    // 创建定时器
    success_label = new QLabel(this);                            // 创建标签
    fail_label = new QLabel(this);                               // 创建标签
    success_label->setText("购买成功");                          // 设置标签文本
    success_label->setGeometry(400, 400, 100, 100);              // 设置标签位置
    success_label->setStyleSheet("font:bold 25px; color:green"); // 设置标签样式
    fail_label->setText("金币不足");                             // 设置标签文本
    fail_label->setGeometry(400, 400, 100, 100);                 // 设置标签位置
    fail_label->setStyleSheet("font:bold 25px; color:red");      // 设置标签样式

    buy_button1 = new QPushButton(this); // 创建按钮
    buy_button2 = new QPushButton(this); // 创建按钮
    buy_button3 = new QPushButton(this); // 创建按钮
    connect(buy_button1, &QPushButton::clicked, this, [=]()
            { buy_event(1); }); // 按钮信号连接
    connect(buy_button2, &QPushButton::clicked, this, [=]()
            { buy_event(2); }); // 按钮信号连接
    connect(buy_button3, &QPushButton::clicked, this, [=]()
            { buy_event(3); }); // 按钮信号连接
    connect(buy_button4, &QPushButton::clicked, this, [=]()
            { buy_event(4); }); // 按钮信号连接
    connect(buy_button5, &QPushButton::clicked, this, [=]()
            { buy_event(5); }); // 按钮信号连接
    connect(timer, &QTimer::timeout, this, [=]()
            { success_label->hide(); }); // 定时器信号连接
    connect(timer, &QTimer::timeout, this, [=]()
            { fail_label->hide(); }); // 定时器信号连接
}
void ShopInterface::get_coin(int coin)
{
    this->coin = coin;
    coin_label->setText("剩余金币" + QString::number(coin));
}

void ShopInterface::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load("../src/shop.jp");
    painter.drawPixmap(0, 0, 1000, 800, pix);
}

void ShopInterface::buy_event(int type)
{

    switch (type)
    {
    case 1:
        if (coin < prop1->get_coin())
        {
            fail_label->show();
            break;
        }
        else
        {
            success_label->show();
            coin -= prop1->get_coin();
            coin_label->setText("剩余金币" + QString::number(coin));
            emit prop_type(1);
        }
        break;
    case 2:
        if (coin < prop2->get_coin())
        {
            fail_label->show();
            break;
        }
        else
        {
            success_label->show();
            coin -= prop2->get_coin();
            coin_label->setText("剩余金币" + QString::number(coin));
            emit prop_type(2);
        }
        break;
    case 3:
        if (coin < prop3->get_coin())
        {
            fail_label->show();
            break;
        }
        else
        {
            success_label->show();
            coin -= prop3->get_coin();
            coin_label->setText("剩余金币" + QString::number(coin));
            emit prop_type(3);
        }
        break;
    case 4:
        if (coin < prop4->get_coin())
        {
            fail_label->show();
            break;
        }
        else
        {
            success_label->show();
            coin -= prop4->get_coin();
            coin_label->setText("剩余金币" + QString::number(coin));
            emit prop_type(4);
        }
        break;
    case 5:
        if (coin < prop5->get_coin())
        {
            fail_label->show();
            break;
        }
        else
        {
            success_label->show();
            coin -= prop5->get_coin();
            coin_label->setText("剩余金币" + QString::number(coin));
            emit prop_type(5);
        }
        break;
    default:
        break;
    }

    timer->start(1000); // 启动定时器
}
