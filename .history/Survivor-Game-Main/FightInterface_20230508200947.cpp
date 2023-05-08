#include "FightInterface.h"

FightInterface::FightInterface(QWidget *parent) : QWidget(parent)
{
    backbutton = new QPushButton("返回主界面", this);                                // 返回按钮初始化
    backbutton->setGeometry(900, 0, 90, 30);                                         // 设置返回按钮位置
    connect(backbutton, &QPushButton::clicked, this, &FightInterface::back_to_main); // 返回按钮连接
    savebutton = new QPushButton("保存游戏", this);                                  // 保存按钮初始化
    savebutton->setGeometry(810, 0, 90, 30);                                         // 设置保存按钮位置
    // connect(savebutton, &QPushButton::clicked, this, &FightInterface::back_to_main); // 保存按钮连接

    connect(timer, &QTimer::timeout, this, &FightInterface::game_over); // 时间到信号连接
    connect(this, &FightInterface::hero_hp_equal_0_signal, this, &FightInterface::game_fail);
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
    pen.drawPixmap(hero_loc[0], hero_loc[1], 100, 80, *hero_pic); // 绘制英雄
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
    hero_loc[0] = 0, hero_loc[1] = 0;                                         // 英雄位置初始化
    hero_blood = hero->get_hero_blood();                                      // 英雄血量初始化
    hero_hp_label = new QLabel("血量: " + QString::number(hero_blood), this); // 血量显示
    hero_hp_loc[0] = hero_loc[0], hero_hp_loc[1] = hero_loc[1] - 10;          // 英雄血量位置初始化
    hero_pic = hero->get_hero_pic();                                          // 英雄图片初始化
    hero_bullets = hero->get_hero_bullets();                                  // 英雄子弹初始化

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
        Monsters_blood.insert(i, monster->get_monster_blood());                                         // 怪物血量初始化
        Monsters_hp_label.insert(i, new QLabel("血量: " + QString::number(Monsters_blood[i]), this));   // 怪物血量显示
        Monsters_hp_loc.insert(i, QPair<int, int>(Monsters_loc[i].first, Monsters_loc[i].second - 10)); // 怪物血量位置初始化
        Monsters_pic.insert(i, monster->get_monster_pic());                                             // 怪物图片初始化
        Monsters_bullets.insert(i, monster->get_monster_bullets());                                     // 怪物子弹初始化
    }
}

void FightInterface::game_over()
{
    game_end(0);
}
void FightInterface::game_fail()
{
    game_end(1);
}
void FightInterface::game_end(int type)
{
    QWidget *game_over_widget = new QWidget(this);
    this->hide();

    game_over_widget->show();
    game_over_widget->setFixedSize(300, 200);
    if (type == 0)
        game_over_widget->setWindowTitle("游戏胜利");
    else if (type == 1)
        game_over_widget->setWindowTitle("游戏失败");

    QPushButton *game_over_button = new QPushButton("退出游戏", game_over_widget);
    connect(game_over_button, &QPushButton::clicked, this, &qApp->quit);
    game_over_button->setGeometry(100, 100, 100, 50);

    QPushButton *game_over_button2 = new QPushButton("再来一局", game_over_widget);
    connect(game_over_button2, &QPushButton::clicked, this, &FightInterface::play_again);
    game_over_button2->setGeometry(100, 150, 100, 50);

    QLabel *game_over_label;
    if (type == 0)
        game_over_label = new QLabel("恭喜你,游戏胜利!", game_over_widget);
    else if (type == 1)
        game_over_label = new QLabel("很遗憾,游戏失败!", game_over_widget);
    game_over_label->setGeometry(100, 50, 100, 50);
}

void FightInterface::play_again()
{
    this->hide();
    emit changeWidgetsignal(1);
}
