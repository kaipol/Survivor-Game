#include "FightInterface.h"

FightInterface::FightInterface(QWidget *parent) : QWidget(parent)
{

    timer = new QTimer(this);        // 战斗定时器
    remain_min = 0, remain_sec = 20; // 剩余时间初始化
    time_label = new QLabel("剩余时间: " + QString::number(remain_min) + ":" + QString::number(remain_sec), this);
    time_label->setGeometry(0, 0, 200, 30);                                 // 时间显示位置
    time_label->setStyleSheet("font: bold 15px");                           // 设置字体
    connect(timer, &QTimer::timeout, this, &FightInterface::time_control);  // 战斗定时器连接
    connect(timer, &QTimer::timeout, this, &FightInterface::Monsters_move); // 战斗定时器连接
    connect(timer, &QTimer::timeout, this, &FightInterface::bullet_move);   // 战斗定时器连接

    backbutton = new QPushButton("返回主界面", this); // 返回按钮初始化
    backbutton->setGeometry(900, 0, 90, 30);          // 设置返回按钮位置
    savebutton = new QPushButton("保存游戏", this);   // 保存按钮初始化
    savebutton->setGeometry(810, 0, 90, 30);          // 设置保存按钮位置
    // connect(savebutton, &QPushButton::clicked, this, &FightInterface::back_to_main); // 保存按钮连接
    connect(backbutton, &QPushButton::clicked, this, &FightInterface::back_to_main); // 返回按钮连接

    connect(this, &FightInterface::hero_hp_equal_0_signal, this, &FightInterface::game_fail);
    this->grabKeyboard(); // 获取键盘
}

void FightInterface::keyPressEvent(QKeyEvent *event) // 键盘事件
{
    bool loc_equal_monster = false; // 英雄位置是否与怪物位置重合
    if (event->key() == Qt::Key_W)
    {
        if (hero_loc[1] > 0 && game_map[hero_loc[0] / 100][hero_loc[1] / 80 - 1] == 0)
        {
            hero_loc[1] -= 80;
            hero_direction = 0;
        }
    }
    if (event->key() == Qt::Key_S)
    {
        if (hero_loc[1] < 720 && game_map[hero_loc[0] / 100][hero_loc[1] / 80 + 1] == 0)
        {
            hero_loc[1] += 80;
            hero_direction = 1;
        }
    }
    if (event->key() == Qt::Key_A)
    {
        if (hero_loc[0] > 0 && game_map[hero_loc[0] / 100 - 1][hero_loc[1] / 80] == 0)
        {
            hero_loc[0] -= 100;
            hero_direction = 2;
        }
    }
    if (event->key() == Qt::Key_D)
    {
        if (hero_loc[0] < 900 && game_map[hero_loc[0] / 100 + 1][hero_loc[1] / 80] == 0)
        {
            hero_loc[0] += 100;
            hero_direction = 3;
        }
    }
    for (int i = 0; i < MonstersNum; i++) // 判断英雄位置是否与怪物位置重合
    {
        if (hero_loc[0] == Monsters_loc[i].first && hero_loc[1] == Monsters_loc[i].second)
        {
            hero_blood -= Monsters_blood[i]; // 英雄血量减少
            if (hero_blood <= 0)
            {
                emit hero_hp_equal_0_signal();
            }
            hero_hp_label->setText("血量: " + QString::number(hero_blood)); // 显示英雄血量
            do
            {
                int x = rand() % 10, y = rand() % 10; // 重新随机生成怪物位置
                Monsters_loc[i].first = x * 100, Monsters_loc[i].second = y * 80;
            } while (Monsters_loc[i].first == hero_loc[0] && Monsters_loc[i].second == hero_loc[1]);             // 重新随机生成怪物位置
            Monsters_hp_label[i]->setGeometry(Monsters_loc[i].first + 20, Monsters_loc[i].second + 10, 100, 10); // 怪物血量显示位置
            break;
        }
    }
    hero_hp_label->setGeometry(hero_loc[0] + 20, hero_loc[1] - 10, 100, 10); // 英雄血量显示位置
    update();
}

void FightInterface::Monsters_move() // 怪物移动函数
{
    for (int i = 0; i < MonstersNum; i++)
    {
        int x = rand() % 4;          // 随机生成移动方向
        bool loc_equal = false;      // 位置相等判断
        bool loc_equal_hero = false; // 人物位置相等判断
        switch (x)
        {
        case 0: // 向上移动
            if (Monsters_loc[i].second > 0 && game_map[Monsters_loc[i].first / 100][Monsters_loc[i].second / 80 - 1] == 0)
            {
                for (int j = 0; j < MonstersNum; j++)
                {
                    if (i != j && Monsters_loc[i].first == Monsters_loc[j].first && Monsters_loc[i].second - 80 == Monsters_loc[j].second)
                    {
                        loc_equal = true; // 位置相等
                        break;
                    }
                    if (Monsters_loc[i].first == hero_loc[0] && Monsters_loc[i].second - 80 == hero_loc[1])
                    {
                        loc_equal_hero = true; // 人物位置相等
                        break;
                    }
                }
                if (loc_equal == false)
                {
                    Monsters_loc[i].second -= 80;
                    Monsters_direction[i] = 0;
                }
            }
            break;
        case 1: // 向下移动
            if (Monsters_loc[i].second < 720 && game_map[Monsters_loc[i].first / 100][Monsters_loc[i].second / 80 + 1] == 0)
            {
                for (int j = 0; j < MonstersNum; j++)
                {
                    if (i != j && Monsters_loc[i].first == Monsters_loc[j].first && Monsters_loc[i].second + 80 == Monsters_loc[j].second)
                    {
                        loc_equal = true; // 位置相等
                        break;
                    }
                    if (Monsters_loc[i].first == hero_loc[0] && Monsters_loc[i].second + 80 == hero_loc[1])
                    {
                        loc_equal_hero = true; // 人物位置相等
                        break;
                    }
                }
                if (loc_equal == false)
                {
                    Monsters_loc[i].second += 80;
                    Monsters_direction[i] = 1;
                }
            }
            break;
        case 2: // 向左移动
            if (Monsters_loc[i].first > 0 && game_map[Monsters_loc[i].first / 100 - 1][Monsters_loc[i].second / 80] == 0)
            {
                for (int j = 0; j < MonstersNum; j++)
                {
                    if (i != j && Monsters_loc[i].first - 100 == Monsters_loc[j].first && Monsters_loc[i].second == Monsters_loc[j].second)
                    {
                        loc_equal = true; // 位置相等
                        break;
                    }
                }
                if (loc_equal == false)
                {
                    Monsters_loc[i].first -= 100;
                    Monsters_direction[i] = 2;
                }
            }
            break;
        case 3: // 向右移动
            if (Monsters_loc[i].first < 900 && game_map[Monsters_loc[i].first / 100 + 1][Monsters_loc[i].second / 80] == 0)
            {
                for (int j = 0; j < MonstersNum; j++)
                {
                    if (i != j && Monsters_loc[i].first + 100 == Monsters_loc[j].first && Monsters_loc[i].second == Monsters_loc[j].second)
                    {
                        loc_equal = true; // 位置相等
                        break;
                    }
                    if (Monsters_loc[i].first + 100 == hero_loc[0] && Monsters_loc[i].second == hero_loc[1])
                    {
                        loc_equal_hero = true; // 人物位置相等
                        break;
                    }
                }
                if (loc_equal == false)
                {
                    Monsters_loc[i].first += 100;
                    Monsters_direction[i] = 3;
                }
            }
            break;

        default:
            break;
        }
        if (loc_equal_hero == true)
        {
            hero_blood -= Monsters_blood[i];
            hero_hp_label->setText("血量: " + QString::number(hero_blood));
            if (hero_blood <= 0)
            {
                emit hero_hp_equal_0_signal();
            }
            do
            {
                int x = rand() % 10, y = rand() % 10; // 重新随机生成怪物位置
                Monsters_loc[i].first = x * 100, Monsters_loc[i].second = y * 80;
            } while (Monsters_loc[i].first == hero_loc[0] && Monsters_loc[i].second == hero_loc[1]); // 重新随机生成怪物位置
        }
        Monsters_hp_label[i]->setGeometry(Monsters_loc[i].first + 20, Monsters_loc[i].second + 10, 100, 10); // 怪物血量显示位置
    }
    update();
}

void FightInterface::bullet_move()
{
    // 人物子弹移动
    switch (hero_direction)
    {
        {
        case 0: // 向上移动

            break;

        default:
            break;
        }
    }
}

void FightInterface::Heroes_and_Monsters_init(QString name) // 英雄和怪物初始化
{

    timer->start(1000); // 战斗定时器开始

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
    hero_hp_label->setGeometry(hero_loc[0] + 20, hero_loc[1] - 10, 100, 10);  // 血量显示位置
    hero_hp_label->setStyleSheet("font: bold 15px");                          // 设置字体
    hero_pic = hero->get_hero_pic();                                          // 英雄图片初始化
    hero_direction = 1;                                                       // 英雄方向初始化

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
        }                                                                                                    // 怪物位置初始化
        Monsters_blood.insert(i, monster->get_monster_blood());                                              // 怪物血量初始化
        Monsters_hp_label.insert(i, new QLabel("血量: " + QString::number(Monsters_blood[i]), this));        // 怪物血量显示
        Monsters_hp_label[i]->setGeometry(Monsters_loc[i].first + 20, Monsters_loc[i].second + 10, 100, 10); // 怪物血量显示位置
        Monsters_hp_label[i]->setStyleSheet("font: bold 15px");                                              // 设置字体
        Monsters_pic.insert(i, monster->get_monster_pic());                                                  // 怪物图片初始化
        Monsters_direction.insert(i, 1);                                                                     // 怪物方向初始化
    }
}

void FightInterface::paintEvent(QPaintEvent *event) // 绘制事件
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
    for (int i = 0; i < MonstersNum; i++)
    {
        pen.drawPixmap(Monsters_loc[i].first + 20, Monsters_loc[i].second + 20, 50, 40, *Monsters_pic[i]); // 绘制怪物
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
    emit game_end_type_signal(1);
    emit changeWidgetsignal(3);
}
