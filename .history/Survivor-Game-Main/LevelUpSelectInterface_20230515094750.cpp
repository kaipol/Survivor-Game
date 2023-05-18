#include "LevelUpSelectInterface.h"

LevelUpSelectInterface::LevelUpSelectInterface(QWidget *parent) : QWidget(parent)
{
    select_one = new QPushButton("选它", this);                                               // 创建按钮
    select_one->setGeometry(100, 100, 100, 50);                                               // 设置按钮位置和大小
    select_two = new QPushButton("选它", this);                                               // 创建按钮
    select_two->setGeometry(100, 200, 100, 50);                                               // 设置按钮位置和大小
    select_three = new QPushButton("选它", this);                                             // 创建按钮
    select_three->setGeometry(100, 300, 100, 50);                                             // 设置按钮位置和大小
    connect(select_one, &QPushButton::clicked, this, &LevelUpSelectInterface::back_to_fight); // 按钮信号连接
    connect(select_one, &QPushButton::clicked, this, [=]()
            { change_type(1); });                                                               // 按钮信号连接
    connect(select_two, &QPushButton::clicked, this, &LevelUpSelectInterface::back_to_fight);   // 按钮信号连接
    connect(select_three, &QPushButton::clicked, this, &LevelUpSelectInterface::back_to_fight); // 按钮信号连接
}

void LevelUpSelectInterface::paintEvent(QPaintEvent *event)
{
    QPainter pen(this);
    pen.drawPixmap(0, 0, 1000, 800, QPixmap("../src/Sprite/LevelUp.png"));
}
