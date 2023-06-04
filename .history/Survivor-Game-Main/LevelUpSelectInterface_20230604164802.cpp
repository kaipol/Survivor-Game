#include "LevelUpSelectInterface.h"

LevelUpSelectInterface::LevelUpSelectInterface(QWidget *parent) : QWidget(parent)
{
    select_one = new QPushButton("选它", this);   // 创建按钮
    select_one->setGeometry(100, 100, 100, 50);   // 设置按钮位置和大小
    select_two = new QPushButton("选它", this);   // 创建按钮
    select_two->setGeometry(100, 200, 100, 50);   // 设置按钮位置和大小
    select_three = new QPushButton("选它", this); // 创建按钮
    select_three->setGeometry(100, 300, 100, 50); // 设置按钮位置和大小

    label1 = new QLabel("当前血量+3", this);           // 创建标签
    label2 = new QLabel("攻击+1", this);               // 创建标签
    label3 = new QLabel("速度+5", this);               // 创建标签
    label4 = new QLabel("击杀怪物获取金币数+1", this); // 创建标签
    label5 = new QLabel("击杀怪物获取经验数+1", this); // 创建标签
    label6 = new QLabel("子弹生成速度加快", this);     // 创建标签
    label1->hide();                                    // 隐藏标签
    label2->hide();                                    // 隐藏标签
    label3->hide();                                    // 隐藏标签
    label4->hide();                                    // 隐藏标签
    label5->hide();                                    // 隐藏标签
    label6->hide();                                    // 隐藏标签

    connect(select_one, &QPushButton::clicked, this, &LevelUpSelectInterface::back_to_fight);   // 按钮信号连接
    connect(select_two, &QPushButton::clicked, this, &LevelUpSelectInterface::back_to_fight);   // 按钮信号连接
    connect(select_three, &QPushButton::clicked, this, &LevelUpSelectInterface::back_to_fight); // 按钮信号连接
    prop_generate();                                                                            // 道具生成
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
        emit change_type(loc[0]);
    }
    else if (sender() == select_two)
    {
        emit change_type(loc[1]);
    }
    else if (sender() == select_three)
    {
        emit change_type(loc[2]);
    }
    emit changeWidgetsignal(2);
}

void LevelUpSelectInterface::prop_generate()
{
    for (int i = 0; i < 3; i++)
    {
        int type = rand() % 60;
        if (type < 10)
        {
        }
        else if (type < 20)
        {
        }
        else if (type < 30)
        {
        }
        else if (type < 40)
        {
        }
        else if (type < 50)
        {
        }
        else if (type < 60)
        {
        }
    }
}
