#include "FightInterface.h"

FightInterface::FightInterface(QWidget *parent) : QWidget(parent)
{
    timer = new QTimer(this);       // 战斗定时器
    timer->start(1000);             // 战斗定时器开始
    remain_min = 1, remain_sec = 0; // 剩余时间初始化
    time_label = new QLabel("剩余时间: " + QString::number(remain_min) + ":" + QString::number(remain_sec), this);
    time_label->setGeometry(0, 0, 200, 30);                                 // 时间显示位置
    time_label->setStyleSheet("font: bold 15px");                           // 设置字体
    connect(timer, &QTimer::timeout, this, &FightInterface::time_control);  // 战斗定时器连接
    connect(timer, &QTimer::timeout, this, &FightInterface::Monsters_move); // 战斗定时器连接

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
    if (event->key() == Qt::Key_W)
    {
        if (hero_loc[1] > 0 && game_map[hero_loc[0] / 100][hero_loc[1] / 80 - 1] == 0)
        {
            hero_loc[1] -= 80;
            hero_hp_loc[1] -= 80;
        }
    }
    if (event->key() == Qt::Key_S)
    {
        if (hero_loc[1] < 720 && game_map[hero_loc[0] / 100][hero_loc[1] / 80 + 1] == 0)
        {
            hero_loc[1] += 80;
            hero_hp_loc[1] += 80;
        }
    }
    if (event->key() == Qt::Key_A)
    {
        if (hero_loc[0] > 0 && game_map[hero_loc[0] / 100 - 1][hero_loc[1] / 80] == 0)
        {
            hero_loc[0] -= 100;
            hero_hp_loc[0] -= 100;
        }
    }
    if (event->key() == Qt::Key_D)
    {
        if (hero_loc[0] < 900 && game_map[hero_loc[0] / 100 + 1][hero_loc[1] / 80] == 0)
        {
            hero_loc[0] += 100;
            hero_hp_loc[0] += 100;
        }
    }
    update();
}

void FightInterface::Monsters_move() // 怪物移动函数
{
    for (int i = 0; i < MonstersNum; i++)
    {
        int x = rand() % 4; // 随机生成移动方向
        switch (x)
        {
        case 0: // 向上移动
            if (Monsters_loc[i].second > 0 && game_map[Monsters_loc[i].first / 100][Monsters_loc[i].second / 80 - 1] == 0)
            {
                Monsters_loc[i].second -= 80;
                Monsters_hp_loc[i].second -= 80;
            }
            break;
        case 1: // 向下移动
            if (Monsters_loc[i].second < 720 && game_map[Monsters_loc[i].first / 100][Monsters_loc[i].second / 80 + 1] == 0)
            {
                Monsters_loc[i].second += 80;
                Monsters_hp_loc[i].second += 80;
            }
            break;
        case 2: // 向左移动
            if (Monsters_loc[i].first > 0 && game_map[Monsters_loc[i].first / 100 - 1][Monsters_loc[i].second / 80] == 0)
            {
                Monsters_loc[i].first -= 100;
                Monsters_hp_loc[i].first -= 100;
            }
            break;
        case 3: // 向右移动
            if (Monsters_loc[i].first < 900 && game_map[Monsters_loc[i].first / 100 + 1][Monsters_loc[i].second / 80] == 0)
            {
                Monsters_loc[i].first += 100;
                Monsters_hp_loc[i].first += 100;
            }
            break;

        default:
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
        pen.drawPixmap(Monsters_loc[i].first, Monsters_loc[i].second, 100, 80, *Monsters_pic[i]); // 绘制怪物
    }
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
    hero_loc[0] = 0, hero_loc[1] = 0;                                         // 英雄位置初始化
    hero_blood = hero->get_hero_blood();                                      // 英雄血量初始化
    hero_hp_label = new QLabel("血量: " + QString::number(hero_blood), this); // 血量显示
    hero_hp_loc[0] = hero_loc[0], hero_hp_loc[1] = hero_loc[1] - 10;          // 英雄血量位置初始化
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
        }                                                                                               // 怪物位置初始化
        Monsters_blood.insert(i, monster->get_monster_blood());                                         // 怪物血量初始化
        Monsters_hp_label.insert(i, new QLabel("血量: " + QString::number(Monsters_blood[i]), this));   // 怪物血量显示
        Monsters_hp_loc.insert(i, QPair<int, int>(Monsters_loc[i].first, Monsters_loc[i].second - 10)); // 怪物血量位置初始化
        Monsters_pic.insert(i, monster->get_monster_pic());                                             // 怪物图片初始化
        Monsters_direction.insert(i, 1);                                                                // 怪物方向初始化
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
        emit game_end_type_signal(0);
        this->hide();
    }
}

void FightInterface::game_fail() // 游戏失败
{
    emit game_end_type_signal(1);
    this->hide();
}
