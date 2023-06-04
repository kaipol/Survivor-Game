#include "ShopInterface.h"

ShopInterface::ShopInterface(QWidget *parent) : QWidget(parent)
{
    timer = new QTimer(this);                          // 创建定时器
    prop1 = new Prop(1);                               // 创建道具
    prop2 = new Prop(2);                               // 创建道具
    prop3 = new Prop(3);                               // 创建道具
    prop4 = new Prop(4);                               // 创建道具
    prop5 = new Prop(5);                               // 创建道具
    prop1_label = new QLabel(prop1->get_name(), this); // 创建标签

    prop2_label = new QLabel(prop2->get_name(), this); // 创建标签
    prop3_label = new QLabel(prop3->get_name(), this); // 创建标签
    prop4_label = new QLabel(prop4->get_name(), this); // 创建标签
    prop5_label = new QLabel(prop5->get_name(), this); // 创建标签
    prop1_info = new QLabel(prop1->get_info(), this);  // 创建标签
    prop2_info = new QLabel(prop2->get_info(), this);  // 创建标签
    prop3_info = new QLabel(prop3->get_info(), this);  // 创建标签
    prop4_info = new QLabel(prop4->get_info(), this);  // 创建标签
    prop5_info = new QLabel(prop5->get_info(), this);  // 创建标签

    success_label = new QLabel("购买成功", this);                // 创建标签
    fail_label = new QLabel("金币不足", this);                   // 创建标签
    success_label->setGeometry(350, 0, 300, 100);                // 设置标签位置
    success_label->setStyleSheet("font:bold 45px; color:green"); // 设置标签样式
    fail_label->setGeometry(350, 0, 300, 100);                   // 设置标签位置
    fail_label->setStyleSheet("font:bold 45px; color:red");      // 设置标签样式
    success_label->hide();                                       // 隐藏标签
    fail_label->hide();                                          // 隐藏标签

    buy_button1 = new QPushButton("购买", this);       // 创建按钮
    buy_button2 = new QPushButton("购买", this);       // 创建按钮
    buy_button3 = new QPushButton("购买", this);       // 创建按钮
    buy_button4 = new QPushButton("购买", this);       // 创建按钮
    buy_button5 = new QPushButton("购买", this);       // 创建按钮
    back_button = new QPushButton("返回主界面", this); // 创建按钮
    buy_button1->setGeometry(430, 350, 100, 50);       // 设置按钮位置和大小
    buy_button2->setGeometry(630, 350, 100, 50);       // 设置按钮位置和大小
    buy_button3->setGeometry(830, 350, 100, 50);       // 设置按钮位置和大小
    buy_button4->setGeometry(530, 650, 100, 50);       // 设置按钮位置和大小
    buy_button5->setGeometry(730, 650, 100, 50);       // 设置按钮位置和大小

    back_button->setGeometry(900, 0, 100, 50); // 设置按钮位置和大小

    connect(buy_button1, &QPushButton::clicked, this, [=]()
            { buy_event(1); }); // 按钮信号连接
    connect(buy_button2, &QPushButton::clicked, this, [=]()
            { buy_event(2); }); // 按钮信号连接
    connect(buy_button3, &QPushButton::clicked, this, [=]()
            { buy_event(3); }); // 按钮信号连接
    connect(buy_button4, &QPushButton::clicked, this, [=]()
            { buy_event(4); }); // 按钮信号连接
    connect(buy_button5, &QPushButton::clicked, this, [=]()
            { buy_event(5); });                                                      // 按钮信号连接
    connect(back_button, &QPushButton::clicked, this, &ShopInterface::back_to_main); // 按钮信号连接

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
    pix.load("../src/Sprite/ShopInterface.png");
    painter.drawPixmap(0, 0, 1000, 800, QPixmap("../src/Sprite/MAP_002_2.png"));
    painter.drawPixmap(0, 130, 1000, 600, pix);
    painter.drawPixmap(400, 200, 150, 150, QPixmap("../src/Sprite/attack_potion.png"));
    painter.drawPixmap(600, 200, 150, 150, QPixmap("../src/Sprite/speed_potion.png"));
    painter.drawPixmap(800, 200, 150, 150, QPixmap("../src/Sprite/revival_potion.png"));
    painter.drawPixmap(500, 500, 150, 150, QPixmap("../src/Sprite/coin_potion.png"));
    painter.drawPixmap(700, 500, 150, 150, QPixmap("../src/Sprite/hp_potion.png"));
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

void ShopInterface::back_to_main()
{
    emit changeWidgetsignal(0);
}
