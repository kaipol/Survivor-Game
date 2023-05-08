#include "FightInterface.h"

FightInterface::FightInterface(QWidget *parent) : QWidget(parent)
{
    backbutton = new QPushButton("返回主界面", this);                                // 返回按钮初始化
    backbutton->setGeometry(900, 0, 90, 30);                                         // 设置返回按钮位置
    connect(backbutton, &QPushButton::clicked, this, &FightInterface::back_to_main); // 返回按钮连接
}

void FightInterface::back_to_main()
{
    this->hide();
    emit changeWidgetsignal(0);
}

void FightInterface::paintEvent(QPaintEvent *event)
{
    QPainter pen(this);
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (game_map[i][j] == 0)
            {
                pen.drawPixmap(i * 100, 100 + j * 70, 100, 70, QPixmap("../src/Sprite/brick.png")); // 绘制背景
            }
            else if (game_map[i][j] == 1)
            {
                pen.drawPixmap(i * 100, 100 + j * 70, 100, 70, QPixmap("../src/Sprite/barrier.png")); // 绘制背景
            }
        }
    }
}

void FightInterface::Heroes_and_Monsters_init(QString name)
{
    if (name == "AL-1S")
    {
        Heroes *hero = new Heroes("AL-1S");
    }
    else if (name == "NOA")
    {
        Heroes *hero = new Heroes("NOA");
    }
    MonstersNum = 3;
    for (int i = 0; i < MonstersNum; i++)
    {
        Monsters *monster = new Monsters("robot");
        Monsters_all.insert(i, *monster);
    }
}