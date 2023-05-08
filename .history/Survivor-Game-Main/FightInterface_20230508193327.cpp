#include "FightInterface.h"

FightInterface::FightInterface(QWidget *parent) : QWidget(parent)
{
    backbutton = new QPushButton("返回主界面", this);                                // 返回按钮初始化
    backbutton->setGeometry(900, 0, 90, 30);                                         // 设置返回按钮位置
    connect(backbutton, &QPushButton::clicked, this, &FightInterface::back_to_main); // 返回按钮连接
    savebutton = new QPushButton("保存游戏", this);                                  // 保存按钮初始化
    savebutton->setGeometry(810, 0, 90, 30);                                         // 设置保存按钮位置
    // connect(savebutton, &QPushButton::clicked, this, &FightInterface::back_to_main); // 保存按钮连接
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
                pen.drawPixmap(i * 100, j * 80, 100, 80, QPixmap("../src/Sprite/brick.png")); // 绘制背景
            }
            else if (game_map[i][j] == 1)
            {
                pen.drawPixmap(i * 100, j * 80, 100, 80, QPixmap("../src/Sprite/barrier.png")); // 绘制背景
            }
        }
    }
    pen.drawPixmap(hero_loc[0] * 100, hero_loc[1] * 80, 100, 80, *hero_pic); // 绘制英雄
}

void FightInterface::paintMonsters() // 绘制怪物
{
    QPainter pen(this);
    for (int i = 0; i < MonstersNum; i++)
    {

        pen.drawPixmap(Monsters_loc[i].first, Monsters_loc[i].second, 100, 80, *Monsters_pic[i]); // 绘制怪物
    }
}

void FightInterface::Heroes_and_Monsters_init(QString name)
{
    if (name == "AL-1S")
    {
        hero = new Heroes("AL-1S");
    }
    else if (name == "NOA")
    {
        hero = new Heroes("NOA");
    }
    hero_loc[0] = 0, hero_loc[1] = 0;                                // 英雄位置初始化
    hero_hp_loc[0] = hero_loc[0], hero_hp_loc[1] = hero_loc[1] - 10; // 英雄血量位置初始化
    hero_pic = hero->get_hero_pic();                                 // 英雄图片初始化
    hero_bullets = hero->get_hero_bullets();                         // 英雄子弹初始化

    MonstersNum = 3;
    for (int i = 0; i < MonstersNum; i++)
    {
        Monsters *monster = new Monsters("robot");
        Monsters_all.insert(i, *monster); // 怪物初始化
        while (1)
        {
            int x = rand() % 10, y = rand() % 10; // 怪物位置随机生成
            if (game_map[x][y] == 0 && x * 100 != hero_loc[0] && y * 80 != hero_loc[1])
            {
                Monsters_loc.insert(i, QPair<int, int>(x * 100, y * 80));
                break;
            }
        }                                                                                               // 怪物位置初始化
        Monsters_hp_loc.insert(i, QPair<int, int>(Monsters_loc[i].first, Monsters_loc[i].second - 10)); // 怪物血量位置初始化
        Monsters_pic.insert(i, monster->get_monster_pic());                                             // 怪物图片初始化
        Monsters_bullets.insert(i, monster->get_monster_bullets());                                     // 怪物子弹初始化
    }
}
