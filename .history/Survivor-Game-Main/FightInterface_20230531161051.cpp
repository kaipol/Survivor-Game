#include "FightInterface.h"

FightInterface::FightInterface(QWidget *parent) : QWidget(parent)
{

    timer = new QTimer(this);                 // 战斗定时器
    move_timer = new QTimer(this);            // 移动定时器
    bullet_move_timer = new QTimer(this);     // 子弹移动定时器
    bullet_generate_timer = new QTimer(this); // 子弹生成定时器
    monster_timer = new QTimer(this);         // 怪物定时器
    remain_min = 0, remain_sec = 20;          // 剩余时间初始化
    time_label = new QLabel("剩余时间: " + QString::number(remain_min) + ":" + QString::number(remain_sec), this);
    time_label->setGeometry(0, 0, 200, 30);                                                                  // 时间显示位置
    time_label->setStyleSheet("font: bold 15px");                                                            // 设置字体
    coin_label = new QLabel("金币数:" + QString::number(coin), this);                                        // 金币显示
    coin_label->setGeometry(0, 30, 200, 30);                                                                 // 金币显示位置
    coin_label->setStyleSheet("font: bold 17px");                                                            // 设置字体
    hero_level_label = new QLabel("英雄等级:" + QString::number(hero->get_hero_level()), this);              // 英雄等级显示
    hero_level_label->setGeometry(0, 60, 200, 30);                                                           // 英雄等级显示位置
    hero_level_label->setStyleSheet("font: bold 17px");                                                      // 设置字体
    hero_revive_label = new QLabel("英雄复活次数:" + QString::number(hero->get_hero_revival_times()), this); // 英雄复活次数显示
    hero_revive_label->setGeometry(0, 90, 200, 30);                                                          // 英雄复活次数显示位置
    hero_revive_label->setStyleSheet("font: bold 17px");                                                     // 设置字体

    connect(timer, &QTimer::timeout, this, &FightInterface::time_control);                    // 战斗定时器连接
    connect(move_timer, &QTimer::timeout, this, &FightInterface::Monsters_move);              // 战斗定时器连接
    connect(bullet_generate_timer, &QTimer::timeout, this, &FightInterface::bullet_generate); // 子弹定时器连接
    connect(bullet_move_timer, &QTimer::timeout, this, &FightInterface::bullet_move);         // 战斗定时器连接
    connect(monster_timer, &QTimer::timeout, this, &FightInterface::Monsters_generate);       // 战斗定时器连接
    connect(timer, &QTimer::timeout, this, &FightInterface::check_hero_attack);               // 战斗定时器连接

    backbutton = new QPushButton("返回主界面", this);                                // 返回按钮初始化
    backbutton->setGeometry(900, 0, 90, 30);                                         // 设置返回按钮位置
    savebutton = new QPushButton("保存游戏", this);                                  // 保存按钮初始化
    savebutton->setGeometry(810, 0, 90, 30);                                         // 设置保存按钮位置
    connect(savebutton, &QPushButton::clicked, this, &FightInterface::save_data);    // 保存按钮连接
    connect(backbutton, &QPushButton::clicked, this, &FightInterface::back_to_main); // 返回按钮连接

    game_map = {
        {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0},
        {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0},
        {0, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0},
        {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
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
    hero_hp_label->setStyleSheet("font: bold 15px;color:red");               // 设置字体
    hero_direction = 1;                                                      // 英雄方向初始化
    hero_bullets_pic = hero->get_hero_bullets();                             // 英雄子弹图片初始化

    for (int i = 0; i < 5; i++)
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

    timer->start(1000);                // 战斗定时器开始
    move_timer->start(100);            // 移动定时器开始
    bullet_generate_timer->start(800); // 子弹生成定时器开始
    bullet_move_timer->start(300);     // 子弹移动定时器开始
    monster_timer->start(3000);        // 怪物定时器开始
}

void FightInterface::get_data(Heroes hero)
{
    hero = hero;
}

void FightInterface::keyPressEvent(QKeyEvent *event) // 键盘事件
// TODO:人物移动
{
    if (event->key() == Qt::Key_W)
    {
        if (hero_loc[1] - (hero->get_hero_speed()) > 0 && game_map[(hero_loc[0] + 93) / 100][(hero_loc[1] - (hero->get_hero_speed())) / 80] == 0 && game_map[(hero_loc[0]) / 100][(hero_loc[1] - (hero->get_hero_speed())) / 80] == 0)
        {
            hero_loc[1] -= hero->get_hero_speed();
            hero_direction = 0;
        }
    }
    if (event->key() == Qt::Key_S)
    {
        if (hero_loc[1] + 80 + (hero->get_hero_speed()) < 800 && game_map[(hero_loc[0] + 93) / 100][((hero_loc[1] + 60) + hero->get_hero_speed()) / 80] == 0 && game_map[(hero_loc[0]) / 100][((hero_loc[1] + 60) + (hero->get_hero_speed())) / 80] == 0)
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
        if (hero_loc[0] + 100 + (hero->get_hero_speed()) < 1000 && game_map[(hero_loc[0] + 100 + (hero->get_hero_speed())) / 100][hero_loc[1] / 80] == 0)
        {
            hero_loc[0] += hero->get_hero_speed();
            hero_direction = 3;
        }
    }
    update();
}

void FightInterface::Monsters_move() // 怪物移动函数
{
    int move_type = rand() % 10;
    for (int i = 0; i < Monsters_all.size(); i++)
    {
        QPair<int, int> loc = Monsters_all[i]->get_monster_loc(); // 获取怪物位置
        int speed = Monsters_all[i]->get_monster_speed();         // 获取怪物速度
        if (move_type > 7)                                        // 随机移动
        {
            int x = rand() % 4; // 随机生成移动方向
            switch (x)
            {
            case 0: // 上
                if (loc.second - speed > 0 && game_map[loc.first / 100][(loc.second - speed) / 80] == 0)
                {
                    Monsters_all[i]->set_monster_loc(loc.first, loc.second - speed);
                    Monsters_all[i]->set_monster_direction(0); // 设置怪物方向
                }
                break;
            case 1: // 下
                if (loc.second + speed < 800 && game_map[loc.first / 100][(loc.second + speed) / 80] == 0)
                {
                    Monsters_all[i]->set_monster_loc(loc.first, loc.second + speed);
                    Monsters_all[i]->set_monster_direction(1); // 设置怪物方向
                }
                break;
            case 2: // 左
                if (loc.first - speed > 0 && game_map[(loc.first - speed) / 100][loc.second / 80] == 0)
                {
                    Monsters_all[i]->set_monster_loc(loc.first - speed, loc.second);
                    Monsters_all[i]->set_monster_direction(2); // 设置怪物方向
                }
                break;
            case 3: // 右
                if (loc.first + speed < 1000 && game_map[(loc.first + speed) / 100][loc.second / 80] == 0)
                {
                    Monsters_all[i]->set_monster_loc(loc.first + speed, loc.second);
                    Monsters_all[i]->set_monster_direction(3); // 设置怪物方向
                }
                break;
            }
        }
        else // 向玩家移动
        {
            if (loc.first > hero_loc[0] && game_map[(loc.first - speed) / 100][loc.second / 80] == 0)
            {
                Monsters_all[i]->set_monster_loc(loc.first - speed, loc.second);
                Monsters_all[i]->set_monster_direction(2); // 设置怪物方向
            }
            else if (loc.first < hero_loc[0] && game_map[(loc.first + speed) / 100][loc.second / 80] == 0)
            {
                Monsters_all[i]->set_monster_loc(loc.first + speed, loc.second);
                Monsters_all[i]->set_monster_direction(3); // 设置怪物方向
            }
            else if (loc.second > hero_loc[1] && game_map[loc.first / 100][(loc.second - speed) / 80] == 0)
            {
                Monsters_all[i]->set_monster_loc(loc.first, loc.second - speed);
                Monsters_all[i]->set_monster_direction(0); // 设置怪物方向
            }
            else if (loc.second < hero_loc[1] && game_map[loc.first / 100][(loc.second + speed) / 80] == 0)
            {
                Monsters_all[i]->set_monster_loc(loc.first, loc.second + speed);
                Monsters_all[i]->set_monster_direction(1); // 设置怪物方向
            }
        }
        Monsters_all[i]->get_monster_hp_label()->setGeometry(loc.first + 10, loc.second - 10, 100, 10); // 血量显示位置
    }

    update();
}

void FightInterface::Monsters_generate()
{
    int type = rand() % 100;
    Monsters *monster;
    if (type <= 90)
    {
        monster = new Monsters("robot");
    }
    else
    {
        monster = new Monsters("yuka");
    }
    Monsters_all.insert(Monsters_all.size(), monster); // 怪物初始化
    while (1)
    {
        int x = rand() % 10, y = rand() % 10; // 怪物位置随机生成
        if (game_map[x][y] == 0 && x * 100 != hero_loc[0] && y * 80 != hero_loc[1])
        {
            int type = rand() % 2; // 怪物位置随机生成
            if (type == 0)
                Monsters_all[Monsters_all.size() - 1]->set_monster_loc(x * 100, y * 80);
            else
                Monsters_all[Monsters_all.size() - 1]->set_monster_loc(x * 100 + 50, y * 80 + 40);
            break;
        }
    }
    Monsters_all[Monsters_all.size() - 1]->get_monster_hp_label()->setParent(this);                                                                                                                                                 // 设置父对象
    Monsters_all[Monsters_all.size() - 1]->get_monster_hp_label()->setGeometry(Monsters_all[Monsters_all.size() - 1]->get_monster_loc().first + 10, Monsters_all[Monsters_all.size() - 1]->get_monster_loc().second - 10, 100, 10); // 血量显示位置
    Monsters_all[Monsters_all.size() - 1]->get_monster_hp_label()->setStyleSheet("font: bold 15px");                                                                                                                                // 设置字体
    Monsters_all[Monsters_all.size() - 1]->get_monster_hp_label()->show();                                                                                                                                                          // 显示血量
}

void FightInterface::bullet_generate()
{
    switch (hero_direction)
    {
    case 0:
        hero_bullets_loc.push_back({hero_loc[0] + 50, hero_loc[1] + 40 - 5, hero_direction});
        break;
    case 1:
        hero_bullets_loc.push_back({hero_loc[0] + 50, hero_loc[1] + 40 + 5, hero_direction});
        break;
    case 2:
        hero_bullets_loc.push_back({hero_loc[0] + 50 - 5, hero_loc[1] + 40, hero_direction});
        break;
    case 3:
        hero_bullets_loc.push_back({hero_loc[0] + 50 + 5, hero_loc[1] + 40, hero_direction});
        break;

    default:
        break;
    }
    paint_bullet();
}

void FightInterface::bullet_move()
{
    // 英雄子弹移动
    for (int i = 0; i < hero_bullets_loc.size(); i++)
    {
        switch (hero_bullets_loc[i][2])
        {
        case 0: // 上
            hero_bullets_loc[i][1] -= 30;
            break;
        case 1: // 下
            hero_bullets_loc[i][1] += 30;
            break;
        case 2: // 左
            hero_bullets_loc[i][0] -= 30;
            break;
        case 3: // 右
            hero_bullets_loc[i][0] += 30;
            break;
        }
        if (hero_bullets_loc[i][0] < 0 || hero_bullets_loc[i][0] > 1000 || hero_bullets_loc[i][1] < 0 || hero_bullets_loc[i][1] > 800)
        {
            hero_bullets_loc.remove(i);
            i--;
        }
        else if (game_map[hero_bullets_loc[i][0] / 100][hero_bullets_loc[i][1] / 80] == 1)
        {
            hero_bullets_loc.remove(i);
            i--;
        }
        // else
        // {
        //     for (int j = 0; j < Monsters_all.size(); j++)
        //     {
        //         QPair<int, int> loc = Monsters_all[j]->get_monster_loc(); // 获取怪物位置
        //         if (loc[0] == Monsters_all[j]->get_monster_loc()[0] && loc[1] == Monsters_all[j]->get_monster_loc()[1])
        //         {
        //             Monsters_all[j]->set_monster_blood(Monsters_all[j]->get_monster_blood() - hero->get_hero_attack());
        //             if (Monsters_all[j]->get_monster_blood() <= 0)
        //             {
        //                 Monsters_all.remove(j);
        //                 j--;
        //             }
        //             hero_bullets_loc.remove(i);
        //             i--;
        //             break;
        //         }
        //     }
        // }
    }
    update();
}

inline void FightInterface::paint_bullet() // 绘制子弹
{
    QPainter pen(this);
    for (int i = 0; i < hero_bullets_loc.size(); i++)
    {
        pen.drawPixmap(hero_bullets_loc[i][0], hero_bullets_loc[i][1], 20, 20, *hero_bullets_pic); // 绘制子弹
    }
}

void FightInterface::check_hero_attack()
{
    int revival_time = hero->get_hero_revival_times();
    int hero_hp = hero->get_hero_blood();
    QRect hero_rect(hero_loc[0], hero_loc[1], 80, 80);
    for (int i = 0; i < Monsters_all.size(); i++)
    {
        QRect monster_rect((Monsters_all[i]->get_monster_loc()).first, (Monsters_all[i]->get_monster_loc()).second, 50, 40);
        if (hero_rect.intersects(monster_rect))
        {
            hero->set_hero_blood(hero_hp - Monsters_all[i]->get_monster_close_attack());
            hero_hp_label->setText("血量: " + QString::number(hero_hp));
            if (hero_hp <= 0 && revival_time == 0)
            {
                game_fail();
            }
            else if (hero_hp <= 0 && revival_time > 0)
            {
                revival_time--;
                hero_loc[0] = 0;
                hero_loc[1] = 0;
                hero_hp = hero->get_hero_blood_max();
                hero_hp_label->setText("血量: " + QString::number(hero_hp));
                update();
            }
        }
    }
    hero->set_hero_revival_times(revival_time);
    hero_revive_label->setText("复活次数: " + QString::number(revival_time));
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
                pen.drawPixmap(j * 100, i * 80, 100, 80, QPixmap("../src/Sprite/brick.png")); // 绘制背景
            }
            else if (game_map[i][j] == 1)
            {
                pen.drawPixmap(j * 100, i * 80, 100, 80, QPixmap("../src/Sprite/barrier.png")); // 绘制背景
            }
        }
    }
    pen.drawPixmap(hero_loc[0], hero_loc[1], 80, 80, *hero->get_hero_pic()); // 绘制英雄
    for (int i = 0; i < Monsters_all.size(); i++)
    {
        pen.drawPixmap(Monsters_all[i]->get_monster_loc().first, Monsters_all[i]->get_monster_loc().second, 50, 40, *Monsters_all[i]->get_monster_pic()); // 绘制怪物
    }
    paint_bullet();
}

void FightInterface::back_to_main() // 返回主界面
{
    this->hide();
    timer->stop();
    bullet_move_timer->stop();
    monster_timer->stop();
    emit changeWidgetsignal(0);
}

void FightInterface::hero_level_up()
{
    int exp = hero->get_hero_exp(), level = hero->get_hero_level();
    if (exp == 10 && level == 1 || exp == 20 && level == 2 && exp == 30 && level == 3)
    {
        exp == 0;
        level++;
        timer->stop();
        bullet_move_timer->stop();
        monster_timer->stop();
        emit changeWidgetsignal(6);
    }
    hero->set_hero_exp(0), hero->set_hero_level(level);
    hero_level_label->setText("英雄等级: " + QString::number(level));
}

void FightInterface::get_level_up_change(int type)
{
    switch (type)
    {
    case 0:
        hero->set_hero_blood(hero->get_hero_blood_max() + 3);
        break;
    case 1:
        hero->set_hero_attack(hero->get_hero_attack() + 1);
        break;
    case 2:
        hero->set_hero_speed(hero->get_hero_speed() + 5);
        break;
    case 3:
        hero->set_hero_revival_times(hero->get_hero_revival_times() + 1);
        break;

    default:
        break;
    }
    timer->start();
    bullet_move_timer->start();
    monster_timer->start();
}

void FightInterface::get_prop_type(int type)
{
    switch (type)
    {
    case 0:
        hero->set_hero_attack(hero->get_hero_attack() + 3);
        break;
    case 1:
        hero->set_hero_speed(hero->get_hero_speed() + 5);
        break;
    case 2:
        hero->set_hero_revival_times(hero->get_hero_revival_times() + 1);
        break;
    case 3:
        hero->set_base_killed_coin(hero->get_base_killed_coin() + 1);
        break;
    case 4:
        hero->set_hero_blood(hero->get_hero_blood() + 3);
        break;
    default:
        break;
    }
}

void FightInterface::save_data()
{
    timer->stop();
    bullet_move_timer->stop();
    monster_timer->stop();
    emit save_data_signal(*hero);
    emit changeWidgetsignal(5);
    emit is_fight();
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
        hero->set_hero_coin(hero->get_hero_coin() + coin); // 金币数更新
        this->hide();
        emit game_end_type_signal(0);
        emit changeWidgetsignal(3);
        timer->stop();
        bullet_move_timer->stop();
        monster_timer->stop();
    }
}

void FightInterface::continue_game()
{
    timer->start();
    bullet_move_timer->start();
    monster_timer->start();
}

void FightInterface::game_fail() // 游戏失败
{
    timer->stop();                                     // 计时器暂停
    bullet_move_timer->stop();                         // 子弹计时器暂停
    monster_timer->stop();                             // 怪物计时器暂停
    hero->set_hero_coin(hero->get_hero_coin() + coin); // 金币数更新
    this->hide();
    emit game_end_type_signal(1);
    emit changeWidgetsignal(3);
}
