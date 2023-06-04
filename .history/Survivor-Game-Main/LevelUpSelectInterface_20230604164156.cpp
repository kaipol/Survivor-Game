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
        for (int i = 0; i < 4; i++)
        {
            if (loc[i] == 1)
            {
                emit change_type(i);
                break;
            }
        }
    }
    else if (sender() == select_two)
    {
        for (int i = 0; i < 4; i++)
        {
            if (loc[i] == 2)
            {
                emit change_type(i);
                break;
            }
        }
    }
    else if (sender() == select_three)
    {
        for (int i = 0; i < 4; i++)
        {
            if (loc[i] == 3)
            {
                emit change_type(i);
                break;
            }
        }
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
            loc[0] = 1;
            label2->show();
            label2->setGeometry(100, 200, 100, 50);
            loc[1] = 2;
            label3->hide();
            label4->show();
            label4->setGeometry(100, 300, 100, 50);
            loc[3] = 3;
        }
        else if (type < 40)
        {
            label1->show();
            label1->setGeometry(100, 100, 100, 50);
            loc[0] = 1;
            label2->show();
            label2->setGeometry(100, 200, 100, 50);
            loc[1] = 2;
            label3->show();
            label3->setGeometry(100, 300, 100, 50);
            loc[2] = 3;
            label4->hide();
        }
        else if (type < 50)
        {
            label1->hide();
            label2->hide();
            label3->hide();
            label4->show();
            label4->setGeometry(100, 100, 100, 50);
            loc[3] = 1;
        }
        else
        {
            label1->hide();
            label2->hide();
            label3->hide();
            label4->hide();
        }
    }
}
