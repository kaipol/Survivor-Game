#include "LevelUpSelectInterface.h"

LevelUpSelectInterface::LevelUpSelectInterface(QWidget *parent) : QWidget(parent)
{
    select_one = new QPushButton("选它", this);   // 创建按钮
    select_one->setGeometry(100, 100, 100, 50);   // 设置按钮位置和大小
    select_two = new QPushButton("选它", this);   // 创建按钮
    select_two->setGeometry(100, 200, 100, 50);   // 设置按钮位置和大小
    select_three = new QPushButton("选它", this); // 创建按钮
    select_three->setGeometry(100, 300, 100, 50); // 设置按钮位置和大小

    label1 = new QLabel("血量+3", this);               // 创建标签
    label2 = new QLabel("攻击+1", this);               // 创建标签
    label3 = new QLabel("速度+5", this);               // 创建标签
    label4 = new QLabel("击杀怪物获取金币数+1", this); // 创建标签

    connect(select_one, &QPushButton::clicked, this, &LevelUpSelectInterface::back_to_fight);   // 按钮信号连接
    connect(select_two, &QPushButton::clicked, this, &LevelUpSelectInterface::back_to_fight);   // 按钮信号连接
    connect(select_three, &QPushButton::clicked, this, &LevelUpSelectInterface::back_to_fight); // 按钮信号连接
}

void LevelUpSelectInterface::paintEvent(QPaintEvent *event)
{
    QPainter pen(this);
    pen.drawPixmap(0, 0, 1000, 800, QPixmap("../src/Sprite/LevelUp.png"));
}
void LevelUpSelectInterface::back_to_fight()
{
    if (sender() == select_one)
    {
    }
    else if (sender() == select_two)
    {
    }
    else if (sender() == select_three)
    {
    }
    emit changeWidgetsignal(2);
}

void LevelUpSelectInterface::prop_generate()
{
    int type = rand() % 40;
    if (type < 10)
    {
        label1->hide();
        label2->show();
        label2->setGeometry(100, 100, 100, 50);
        loc[1] = 1;
        label3->show();
        label3->setGeometry(100, 200, 100, 50);
        loc[2] = 2;
        label4->show();
        label4->setGeometry(100, 300, 100, 50);
        loc[3] = 3;
    }
    else if (type < 20)
    {
        label1->show();
        label1->setGeometry(100, 100, 100, 50);
        loc[0] = 1;
        label2->hide();
        label3->show();
        label3->setGeometry(100, 200, 100, 50);
        loc[2] = 2;
        label4->show();
        label4->setGeometry(100, 300, 100, 50);
        loc[3] = 3;
    }
    else if (type < 30)
    {
        label1->show();
        label1->setGeometry(100, 100, 100, 50);

        label2->show();
        label2->setGeometry(100, 200, 100, 50);
        label3->hide();
        label4->show();
        label4->setGeometry(100, 300, 100, 50);
    }
    else
    {
        label1->show();
        label1->setGeometry(100, 100, 100, 50);
        label2->show();
        label2->setGeometry(100, 200, 100, 50);
        label3->show();
        label3->setGeometry(100, 300, 100, 50);
        label4->hide();
    }
}
