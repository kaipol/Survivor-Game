#include "LevelUpSelectInterface.h"

LevelUpSelectInterface::LevelUpSelectInterface(QWidget *parent) : QWidget(parent)
{
    select_one = new QPushButton("选它", this);    // 创建按钮
    select_one->setGeometry(100, 500, 200, 100);   // 设置按钮位置和大小
    select_two = new QPushButton("选它", this);    // 创建按钮
    select_two->setGeometry(450, 500, 200, 100);   // 设置按钮位置和大小
    select_three = new QPushButton("选它", this);  // 创建按钮
    select_three->setGeometry(800, 500, 200, 100); // 设置按钮位置和大小

    label1 = new QLabel("当前血量+3", this);           // 创建标签
    label1->setStyleSheet("font:bold 30px;");          // 设置标签字体
    label2 = new QLabel("攻击+1", this);               // 创建标签
    label2->setStyleSheet("font:bold 30px;");          // 设置标签字体
    label3 = new QLabel("速度+5", this);               // 创建标签
    label3->setStyleSheet("font:bold 30px;");          // 设置标签字体
    label4 = new QLabel("击杀怪物获取金币数+1", this); // 创建标签
    label4->setStyleSheet("font:bold 30px;");          // 设置标签字体
    label5 = new QLabel("击杀怪物获取经验数+1", this); // 创建标签
    label5->setStyleSheet("font:bold 30px;");          // 设置标签字体
    label6 = new QLabel("子弹生成速度加快", this);     // 创建标签
    label6->setStyleSheet("font:bold 30px;");          // 设置标签字体
    label1->hide();                                    // 隐藏标签
    label2->hide();                                    // 隐藏标签
    label3->hide();                                    // 隐藏标签
    label4->hide();                                    // 隐藏标签
    label5->hide();                                    // 隐藏标签
    label6->hide();                                    // 隐藏标签
    label1_flag = false;                               // 标签:血量+3是否显示
    label2_flag = false;                               // 标签:攻击+1是否显示
    label3_flag = false;                               // 标签:速度+5是否显示
    label4_flag = false;                               // 标签:击杀怪物获取金币数+1是否显示
    label5_flag = false;                               // 标签:击杀怪物获取经验数+1是否显示
    label6_flag = false;                               // 标签:子弹生成速度加快是否显示

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
        if (type < 10 && !label1_flag)
        {
            label1->show();
            label1_flag = true;
            loc[i] = 1;
        }
        else if (type < 20)
        {
            label2->show();
            label2_flag = true;
            loc[i] = 2;
        }
        else if (type < 30)
        {
            label3->show();
            label3_flag = true;
            loc[i] = 3;
        }
        else if (type < 40)
        {
            label4->show();
            label4_flag = true;
            loc[i] = 4;
        }
        else if (type < 50)
        {
            label5->show();
            label5_flag = true;
            loc[i] = 5;
        }
        else if (type < 60)
        {
            label6->show();
            label6_flag = true;
            loc[i] = 6;
        }
    }
}
