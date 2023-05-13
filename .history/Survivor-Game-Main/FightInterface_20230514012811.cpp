#include "FightInterface.h"

FightInterface::FightInterface(QWidget *parent) : QWidget(parent)
{

    timer = new QTimer(this);        // 战斗定时器
    remain_min = 0, remain_sec = 20; // 剩余时间初始化
    time_label = new QLabel("剩余时间: " + QString::number(remain_min) + ":" + QString::number(remain_sec), this);
    time_label->setGeometry(0, 0, 200, 30);                           // 时间显示位置
    time_label->setStyleSheet("font: bold 15px");                     // 设置字体
    coin_label = new QLabel("金币数:" + QString::number(coin), this); // 金币显示
    coin_label->setGeometry(0, 30, 200, 30);                          // 金币显示位置
    coin_label->setStyleSheet("font: bold 15px");                     // 设置字体

    connect(timer, &QTimer::timeout, this, &FightInterface::time_control);  // 战斗定时器连接
    connect(timer, &QTimer::timeout, this, &FightInterface::Monsters_move); // 战斗定时器连接
    // connect(timer, &QTimer::timeout, this, &FightInterface::bullet_generate);
    connect(timer, &QTimer::timeout, this, &FightInterface::bullet_move);       // 战斗定时器连接
    connect(timer, &QTimer::timeout, this, &FightInterface::Monsters_generate); // 战斗定时器连接

    backbutton = new QPushButton("返回主界面", this); // 返回按钮初始化
    backbutton->setGeometry(900, 0, 90, 30);          // 设置返回按钮位置
    shopbutton = new QPushButton("进入商店", this);   // 商店按钮初始化
    savebutton = new QPushButton("保存游戏", this);   // 保存按钮初始化
    savebutton->setGeometry(810, 0, 90, 30);          // 设置保存按钮位置
    // connect(savebutton, &QPushButton::clicked, this, &FightInterface::back_to_main); // 保存按钮连接
    connect(backbutton, &QPushButton::clicked, this, &FightInterface::back_to_main); // 返回按钮连接

    connect(this, &FightInterface::hero_hp_equal_0_signal, this, &FightInterface::game_fail); // 英雄血量为0信号连接

    game_map = {
        {0, 1, 0, 0, 0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
        {0, 1, 0, 0, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
        {0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 0, 1, 0},
        {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
    };
}

void FightInterface::Heroes_and_Monsters_init(QString name) // 英雄和怪物初始化
{

    if (name == "AL-1S")
    {
        hero = new Heroes("AL-1S");
    }
    else if (name == "NOA")
    {
        hero = new Heroes("NOA");
    }
    hero_loc[0] = 0, hero_loc[1] = 0;                                        // 英雄位置初始化
    hero_hp_label = hero->get_hero_hp_label();                               // 血量显示
    hero_hp_label->setParent(this);                                          // 设置父对象
    hero_hp_label->setGeometry(hero_loc[0] + 20, hero_loc[1] - 10, 100, 10); // 血量显示位置
    hero_hp_label->setStyleSheet("font: bold 15px");                         // 设置字体
    hero_direction = 1;                                                      // 英雄方向初始化
    hero_bullets_attack = hero->get_hero_attack();                           // 英雄子弹攻击力初始化
    hero_bullets_pic = hero->get_hero_bullets();                             // 英雄子弹图片初始化

    for (int i = 0; i < 3; i++)
    {
        Monsters *monster = new Monsters("robot");
        Monsters_all.insert(i, monster); // 怪物初始化
        while (1)
        {
            int x = rand() % 10, y = rand() % 10; // 怪物位置随机生成
            if (game_map[x][y] == 0 && x * 100 != hero_loc[0] && y * 80 != hero_loc[1])
            {
                int type = rand() % 2; // 怪物位置随机生成
                if (type == 0)
                    Monsters_all[i]->set_monster_loc(x * 100, y * 80);
                else
                    Monsters_all[i]->set_monster_loc(x * 100 + 50, y * 80 + 40);
                break;
            }
        }
        Monsters_all[i]->get_monster_hp_label()->setParent(this);                                                                                                     // 设置父对象
        Monsters_all[i]->get_monster_hp_label()->setGeometry(Monsters_all[i]->get_monster_loc().first + 20, Monsters_all[i]->get_monster_loc().second - 10, 100, 10); // 血量显示位置
        Monsters_all[i]->get_monster_hp_label()->setStyleSheet("font: bold 15px");                                                                                    // 设置字体
    }

    timer->start(1000); // 战斗定时器开始
}

void FightInterface::keyPressEvent(QKeyEvent *event) // 键盘事件
{
    if (event->key() == Qt::Key_W)
    {
        if (hero_loc[1] - (hero->get_hero_speed()) > 0 && game_map[hero_loc[0] / 100][(hero_loc[1] - (hero->get_hero_speed())) / 80] == 0)
        {
            hero_loc[1] -= hero->get_hero_speed();
            hero_direction = 0;
        }
    }
    if (event->key() == Qt::Key_S)
    {
        if (hero_loc[1] + (hero->get_hero_speed()) < 800 && game_map[hero_loc[0] / 100][(hero_loc[1] + (hero->get_hero_speed())) / 80] == 0)
        {
            hero_loc[1] += hero->get_hero_speed();
            hero_direction = 1;
        }
    }
    if (event->key() == Qt::Key_A)
    {
        if (hero_loc[0] - (hero->get_hero_speed()) > 0 && game_map[(hero_loc[0] - (hero->get_hero_speed())) / 100][hero_loc[1] / 80] == 0)
        {
            hero_loc[0] -= hero->get_hero_speed();
            hero_direction = 2;
        }
    }
    if (event->key() == Qt::Key_D)
    {
        if (hero_loc[0] + (hero->get_hero_speed()) < 1000 && game_map[(hero_loc[0] + (hero->get_hero_speed())) / 100][hero_loc[1] / 80] == 0)
        {
            hero_loc[0] += hero->get_hero_speed();
            hero_direction = 3;
        }
    }
    update();
}

void FightInterface::Monsters_move() // 怪物移动函数
{
    for (int i = 0; i < Monsters_all.size(); i++)
    {
        int x = rand() % 4;          // 随机生成移动方向
        bool loc_equal = false;      // 位置相等判断
        bool loc_equal_hero = false; // 人物位置相等判断
        switch (x)
        {
        case 0:
            if (Monsters_loc[i].second - (Monsters_all[i]->get_monster_speed()) > 0 && game_map[Monsters_loc[i].first / 100][(Monsters_loc[i].second - (Monsters_all[i]->get_monster_speed())) / 80] == 0)
            {
                Monsters_loc[i].second -= Monsters_all[i]->get_monster_speed();
                Monsters_all[i]->set_monster_direction(0);
            }
            break;
        case 1:
            if (Monsters_loc[i].second + (Monsters_all[i]->get_monster_speed()) < 800 && game_map[Monsters_loc[i].first / 100][(Monsters_loc[i].second + (Monsters_all[i]->get_monster_speed())) / 80] == 0)
            {
                Monsters_loc[i].second += Monsters_all[i]->get_monster_speed();
                Monsters_direction[i] = 1;
            }
            break;
        case 2:
            if (Monsters_loc[i].first - (Monsters_all[i]->get_monster_speed()) > 0 && game_map[(Monsters_loc[i].first - (Monsters_all[i]->get_monster_speed())) / 100][Monsters_loc[i].second / 80] == 0)
            {
                Monsters_loc[i].first -= Monsters_all[i]->get_monster_speed();
                Monsters_direction[i] = 2;
            }
            break;
        case 3:
            if (Monsters_loc[i].first + (Monsters_all[i]->get_monster_speed()) < 1000 && game_map[(Monsters_loc[i].first + (Monsters_all[i]->get_monster_speed())) / 100][Monsters_loc[i].second / 80] == 0)
            {
                Monsters_loc[i].first += Monsters_all[i]->get_monster_speed();
                Monsters_direction[i] = 3;
            }
            break;
        }
    }
    update();
}

void FightInterface::bullet_move()
{
}

void FightInterface::paintEvent(QPaintEvent *event) // 绘制事件
{

    QPainter pen(this); // 创建画笔
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
    pen.drawPixmap(hero_loc[0], hero_loc[1], 100, 80, *hero->get_hero_pic()); // 绘制英雄
    for (int i = 0; i < Monsters_all.size(); i++)
    {
        pen.drawPixmap(Monsters_loc[i].first + 20, Monsters_loc[i].second + 20, 50, 40, *Monsters_all[i]->get_monster_pic()); // 绘制怪物
    }
}

inline void FightInterface::paint_bullet() // 绘制子弹
{
    QPainter pen(this);
    for (int i = 0; i < hero_bullets_loc.size(); i++)
    {
        pen.drawPixmap(hero_bullets_loc[i].first, hero_bullets_loc[i].second, 20, 20, *hero_bullets_pic); // 绘制子弹
    }
}

void FightInterface::back_to_main() // 返回主界面
{
    this->hide();
    timer->stop();
    emit changeWidgetsignal(0);
}

void FightInterface::time_control()
{
    if (remain_sec == 0)
    {
        remain_min--;
        remain_sec = 59;
    }
    else
    {
        remain_sec--;
    }
    time_label->setText("剩余时间: " + QString::number(remain_min) + ":" + QString::number(remain_sec));
    if (remain_min == 0 && remain_sec == 0)
    {
        this->hide();
        emit game_end_type_signal(0);
        emit changeWidgetsignal(3);
    }
}

void FightInterface::game_fail() // 游戏失败
{
    this->hide();
    timer->stop(); // 计时器暂停
    emit game_end_type_signal(1);
    emit changeWidgetsignal(3);
}
