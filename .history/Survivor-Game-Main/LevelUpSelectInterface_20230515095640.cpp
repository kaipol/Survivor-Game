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
    label1->setGeometry(200, 100, 100, 50);            // 设置标签位置和大小
    label2 = new QLabel("攻击+1", this);               // 创建标签
    label2->setGeometry(200, 200, 100, 50);            // 设置标签位置和大小
    label3 = new QLabel("速度+5", this);               // 创建标签
    label3->setGeometry(200, 300, 100, 50);            // 设置标签位置和大小
    label4 = new QLabel("击杀怪物获取金币数+1", this); // 创建标签
    label4->setGeometry(200, 400, 100, 50);            // 设置标签位置和大小

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

    emit changeWidgetsignal(2);
}

void LevelUpSelectInterface::prop_generate()
{
    int type = rand() % 40;
    if (type < 10)
    {
        label1->hide();
        label2->show();
        label3->show();
        label4->show();
    }
    else if (type < 20)
    {
        label1->show();
        label2->hide();
        label3->show();
        label4->show();
    }
    else if (type < 30)
    {
        label1->show();
        label2->show();
        label3->hide();
        label4->show();
    }
    else
    {
        label1->show();
        label2->show();
        label3->show();
        label4->hide();
    }
}
