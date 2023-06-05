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
    time_label->setGeometry(0, 0, 200, 30);                           // 时间显示位置
    time_label->setStyleSheet("font: bold 15px");                     // 设置字体
    coin_label = new QLabel("金币数:" + QString::number(coin), this); // 金币显示
    coin_label->setGeometry(0, 30, 200, 30);                          // 金币显示位置
    coin_label->setStyleSheet("font: bold 17px");                     // 设置字体

    connect(timer, &QTimer::timeout, this, &FightInterface::time_control);              // 战斗定时器连接
    connect(move_timer, &QTimer::timeout, this, &FightInterface::Monsters_move);        // 战斗定时器连接
                                                                                        // connect(bullet_generate_timer, &QTimer::timeout, this, &FightInterface::bullet_generate); // 子弹定时器连接
    connect(bullet_move_timer, &QTimer::timeout, this, &FightInterface::bullet_move);   // 战斗定时器连接
    connect(monster_timer, &QTimer::timeout, this, &FightInterface::Monsters_generate); // 战斗定时器连接
    connect(timer, &QTimer::timeout, this, &FightInterface::check_hero_attack);         // 战斗定时器连接

    backbutton = new QPushButton("返回主界面", this);                                // 返回按钮初始化
    backbutton->setGeometry(900, 0, 90, 30);                                         // 设置返回按钮位置
    savebutton = new QPushButton("保存游戏", this);                                  // 保存按钮初始化
    savebutton->setGeometry(810, 0, 90, 30);                                         // 设置保存按钮位置
    connect(savebutton, &QPushButton::clicked, this, &FightInterface::save_data);    // 保存按钮连接
    connect(backbutton, &QPushButton::clicked, this, &FightInterface::back_to_main); // 返回按钮连接
}

void FightInterface::get_map_type(int type)
{
    game_map_widget = new GameMap(type); // 游戏地图初始化
    game_map = game_map_widget->getMap();
    create_obstacle_rects(); // 障碍物初始化
    // 怪物生成
    for (int i = 0; i < 5; i++)
    {
        Monsters *monster = new Monsters("robot");
        Monsters_all.insert(i, monster); // 怪物初始化
        while (1)
        {
            int y = rand() % 16, x = rand() % 20; // 怪物位置随机生成
            if (game_map[y][x] == 0)
            {
                Monsters_all[i]->set_loc(x * 50 + 10, y * 50 + 10);
                break;
            }
        }
        Monsters_all[i]->get_hp_label()->setParent(this);                                                                                    // 设置父对象
        Monsters_all[i]->get_hp_label()->setGeometry(Monsters_all[i]->get_loc().first - 5, Monsters_all[i]->get_loc().second - 10, 100, 10); // 血量显示位置
        Monsters_all[i]->get_hp_label()->setStyleSheet("font: bold 15px");                                                                   // 设置字体
    }

    timer->start(1000);                 // 战斗定时器开始
    move_timer->start(100);             // 移动定时器开始
    bullet_generate_timer->start(1500); // 子弹生成定时器开始
    bullet_move_timer->start(100);      // 子弹移动定时器开始
    monster_timer->start(3000);         // 怪物定时器开始
}

void FightInterface::Heroes_init(QString name) // 英雄和怪物初始化
{

    if (name == "AL-1S")
    {
        hero = new Heroes("AL-1S");
    }
    else if (name == "NOA")
    {
        hero = new Heroes("NOA");
    }
    hero_loc[0] = 0, hero_loc[1] = 0;                                                                    // 英雄位置初始化
    hero_hp_label = hero->get_hp_label();                                                                // 血量显示
    hero_hp_label->setParent(this);                                                                      // 设置父对象
    hero_hp_label->setGeometry(hero_loc[0], hero_loc[1] - 10, 100, 10);                                  // 血量显示位置
    hero_hp_label->setStyleSheet("font: bold 15px;color:red");                                           // 设置字体
    hero_direction = 1;                                                                                  // 英雄方向初始化
    hero_bullets_pic = hero->get_bullets_pic();                                                          // 英雄子弹图片初始化
    hero_level_label = new QLabel("英雄等级:" + QString::number(hero->get_hero_level()), this);          // 英雄等级显示
    hero_level_label->setGeometry(0, 60, 200, 30);                                                       // 英雄等级显示位置
    hero_level_label->setStyleSheet("font: bold 17px");                                                  // 设置字体
    hero_revive_label = new QLabel("复活次数:" + QString::number(hero->get_hero_revival_times()), this); // 英雄复活次数显示
    hero_revive_label->setGeometry(0, 90, 200, 30);                                                      // 英雄复活次数显示位置
    hero_revive_label->setStyleSheet("font: bold 17px");                                                 // 设置字体
}

void FightInterface::get_data(Heroes hero)
{
    hero = hero;
}

void FightInterface::create_obstacle_rects()
{
    for (int i = 0; i < game_map.size(); i++)
    {
        for (int j = 0; j < game_map[i].size(); j++)
        {
            if (game_map[i][j] == 1)
            {
                QRect obstacle_rect(j * 50, i * 50, 50, 50);
                obstacle_rects.push_back(obstacle_rect); // 将障碍物的QRect存储在列表中
            }
        }
    }
}

void FightInterface::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_W)
    {
        QRect hero_rect(hero_loc[0], hero_loc[1] - hero->get_speed(), 40, 40);
        bool hero_colliding = is_colliding(hero_rect); // 检查英雄对象是否与任何一个障碍物相交
        if (hero_loc[1] > 0 && !hero_colliding)
        {
            hero_loc[1] -= hero->get_speed();
            hero_direction = 0;
        }
    }
    if (event->key() == Qt::Key_S)
    {
        QRect hero_rect(hero_loc[0], hero_loc[1] + hero->get_speed(), 40, 40);
        bool hero_colliding = is_colliding(hero_rect); // 检查英雄对象是否与任何一个障碍物相交
        if (hero_loc[1] + 30 < 800 && !hero_colliding)
        {
            hero_loc[1] += hero->get_speed();
            hero_direction = 1;
        }
    }
    if (event->key() == Qt::Key_A)
    {
        QRect hero_rect(hero_loc[0] - hero->get_speed(), hero_loc[1], 40, 40);
        bool hero_colliding = is_colliding(hero_rect); // 检查英雄对象是否与任何一个障碍物相交
        if (hero_loc[0] > 0 && !hero_colliding)
        {
            hero_loc[0] -= hero->get_speed();
            hero_direction = 2;
        }
    }
    if (event->key() == Qt::Key_D)
    {
        QRect hero_rect(hero_loc[0] + hero->get_speed(), hero_loc[1], 40, 40);
        bool hero_colliding = is_colliding(hero_rect); // 检查英雄对象是否与任何一个障碍物相交
        if (hero_loc[0] + 30 < 1000 && !hero_colliding)
        {
            hero_loc[0] += hero->get_speed();
            hero_direction = 3;
        }
    }
    hero_hp_label->setGeometry(hero_loc[0], hero_loc[1] - 10, 70, 10); // 血量显示位置
    update();
}

bool FightInterface::is_colliding(QRect rect)
{
    for (int i = 0, j = obstacle_rects.size() - 1; i <= j; i++, j--)
    {
        if (rect.intersects(obstacle_rects[i]) || rect.intersects(obstacle_rects[j]))
        {
            return true;
        }
    }
    return false;
}

void FightInterface::Monsters_move()
{
    for (int i = 0; i < Monsters_all.size(); i++)
    {
        std::pair<int, int> loc = Monsters_all[i]->get_loc();
        QPair<int, int> pic_size = Monsters_all[i]->get_pic_size();
        int direction = rand() % 4; // 随机方向移动
        int speed = Monsters_all[i]->get_speed();

        if (rand() % 2 == 0) // 随机方向移动
        {
            if (direction == 0) // 上
            {
                QRect next_rect(loc.first, loc.second - speed, pic_size.first, pic_size.second); // 创建下一个位置的QRect
                if (next_rect.top() >= 0 && !is_colliding(next_rect))                            // 检测碰撞
                {
                    Monsters_all[i]->set_loc(loc.first, loc.second - speed);
                    Monsters_all[i]->set_direction(0);
                }
            }
            else if (direction == 1) // 下
            {
                QRect next_rect(loc.first, loc.second + speed, pic_size.first, pic_size.second); // 创建下一个位置的QRect
                if (next_rect.bottom() <= 800 && !is_colliding(next_rect))                       // 检测碰撞
                {
                    Monsters_all[i]->set_loc(loc.first, loc.second + speed);
                    Monsters_all[i]->set_direction(1);
                }
            }
            else if (direction == 2) // 左
            {
                QRect next_rect(loc.first - speed, loc.second, pic_size.first, pic_size.second); // 创建下一个位置的QRect
                if (next_rect.left() >= 0 && !is_colliding(next_rect))                           // 检测碰撞
                {
                    Monsters_all[i]->set_loc(loc.first - speed, loc.second);
                    Monsters_all[i]->set_direction(2);
                }
            }
            else if (direction == 3) // 右
            {
                QRect next_rect(loc.first + speed, loc.second, pic_size.first, pic_size.second); // 创建下一个位置的QRect
                if (next_rect.right() <= 1000 && !is_colliding(next_rect))                       // 检测碰撞
                {
                    Monsters_all[i]->set_loc(loc.first + speed, loc.second);
                    Monsters_all[i]->set_direction(3);
                }
            }
        }
        else // 向英雄位置移动
        {
            int dx = hero_loc[0] - loc.first;
            int dy = hero_loc[1] - loc.second;
            if (dx > 0) // 英雄在右侧
            {
                QRect next_rect(loc.first + speed, loc.second, pic_size.first, pic_size.second); // 创建下一个位置的QRect
                if (next_rect.right() <= 1000 && !is_colliding(next_rect))                       // 检测碰撞
                {
                    Monsters_all[i]->set_loc(loc.first + speed, loc.second);
                    Monsters_all[i]->set_direction(3); // 向右移动
                }
            }
            else if (dx < 0) // 英雄在左侧
            {
                QRect next_rect(loc.first - speed, loc.second, pic_size.first, pic_size.second); // 创建下一个位置的QRect
                if (next_rect.left() >= 0 && !is_colliding(next_rect))                           // 检测碰撞
                {
                    Monsters_all[i]->set_loc(loc.first - speed, loc.second);
                    Monsters_all[i]->set_direction(2); // 向左移动
                }
            }
            else if (dy > 0) // 英雄在下方
            {
                QRect next_rect(loc.first, loc.second + speed, pic_size.first, pic_size.second); // 创建下一个位置的QRect
                if (next_rect.bottom() <= 800 && !is_colliding(next_rect))                       // 检测碰撞
                {
                    Monsters_all[i]->set_loc(loc.first, loc.second + speed);
                    Monsters_all[i]->set_direction(1); // 向下移动
                }
            }
            else if (dy < 0) // 英雄在上方
            {
                QRect next_rect(loc.first, loc.second - speed, pic_size.first, pic_size.second); // 创建下一个位置的QRect
                if (next_rect.top() >= 0 && !is_colliding(next_rect))                            // 检测碰撞
                {
                    Monsters_all[i]->set_loc(loc.first, loc.second - speed);
                    Monsters_all[i]->set_direction(0); // 向上移动
                }
            }
        }
        Monsters_all[i]->get_hp_label()->setGeometry(loc.first, loc.second - 10, 70, 10); // 血量显示位置
    }
    update();
}

void FightInterface::Monsters_generate()
{
    int type = rand() % 100;
    Monsters *monster;
    if (type <= 80)
    {
        monster = new Monsters("robot");
    }
    else
    {
        monster = new Monsters("yuka");
        QVector<QVector<int>> v1;
        Yuka_loc.push_back(qMakePair(Monsters_all.size() - 1, v1));
    }
    Monsters_all.push_back(monster);
    while (1)
    {
        int y = rand() % 16, x = rand() % 20; // 怪物位置随机生成
        if (game_map[y][x] == 0)
        {
            Monsters_all[Monsters_all.size() - 1]->set_loc(x * 50 + 10, y * 50 + 10);
            break;
        }
    }
    Monsters_all[Monsters_all.size() - 1]->get_hp_label()->setParent(this);                                                                                                                               // 设置父对象
    Monsters_all[Monsters_all.size() - 1]->get_hp_label()->setGeometry(Monsters_all[Monsters_all.size() - 1]->get_loc().first - 5, Monsters_all[Monsters_all.size() - 1]->get_loc().second - 10, 70, 10); // 血量显示位置
    Monsters_all[Monsters_all.size() - 1]->get_hp_label()->setText("血量:" + QString::number(Monsters_all[Monsters_all.size() - 1]->get_blood()));                                                        // 设置血量
    Monsters_all[Monsters_all.size() - 1]->get_hp_label()->setStyleSheet("font: bold 15px");                                                                                                              // 设置字体
    Monsters_all[Monsters_all.size() - 1]->get_hp_label()->show();                                                                                                                                        // 显示血量
    update();
}

void FightInterface::monsters_hit(int i, int j)
{
    Monsters_all[j]->set_blood(Monsters_all[j]->get_blood() - hero->get_bullet_attack());
    if (Monsters_all[j]->get_blood() <= 0)
    {
        coin += Monsters_all[j]->get_monster_killed_coin();
        coin_label->setText("金币数:" + QString::number(coin));
        hero->set_hero_exp(hero->get_hero_exp() + Monsters_all[j]->get_monster_kill_exp());
        hero_level_up();
        while (1)
        {
            int y = rand() % 16, x = rand() % 20; // 怪物位置随机生成
            if (game_map[y][x] == 0)
            {
                Monsters_all[j]->set_loc(x * 50 + 10, y * 50 + 10);
                break;
            }
        }
        Monsters_all[j]->get_hp_label()->setText("血量:" + QString::number(Monsters_all[j]->get_blood_max())); // 血量显示
    }
    else if (Monsters_all[j]->get_blood() > 0)
    {
        Monsters_all[j]->get_hp_label()->setText("血量:" + QString::number(Monsters_all[j]->get_blood())); // 血量显示
    }
    Monsters_all[j]->get_hp_label()->setGeometry(Monsters_all[j]->get_loc().first - 5, Monsters_all[j]->get_loc().second - 10, 70, 10); // 血量显示位置
    Monsters_all[j]->get_hp_label()->show();                                                                                            // 显示血量
}

void FightInterface::bullet_generate()
{
    switch (hero_direction)
    {
    case 0:
        hero_bullets_loc.push_back({hero_loc[0] + 15, hero_loc[1] + 20 - 5, hero_direction});
        break;
    case 1:
        hero_bullets_loc.push_back({hero_loc[0] + 15, hero_loc[1] + 20 + 5, hero_direction});
        break;
    case 2:
        hero_bullets_loc.push_back({hero_loc[0] + 15 - 5, hero_loc[1] + 20, hero_direction});
        break;
    case 3:
        hero_bullets_loc.push_back({hero_loc[0] + 15 + 5, hero_loc[1] + 20, hero_direction});
        break;

    default:
        break;
    }
    for (int i = 0; i < Yuka_loc.size(); i++)
    {
        int x = Monsters_all[Yuka_loc[i].first]->get_loc().first;
        int y = Monsters_all[Yuka_loc[i].first]->get_loc().second;
        int direction = Monsters_all[Yuka_loc[i].first]->get_direction();
        switch (direction)
        {
        case 0:
            Yuka_loc[i].second.push_back({x + 15, y + 20 - 5, direction});
            break;
        case 1:
            Yuka_loc[i].second.push_back({x + 15, y + 20 + 5, direction});
            break;
        case 2:
            Yuka_loc[i].second.push_back({x + 15 - 5, y + 20, direction});
            break;
        case 3:
            Yuka_loc[i].second.push_back({x + 15 + 5, y + 20, direction});
            break;
        default:
            break;
        }
    }
    paint_bullet();
}

void FightInterface::bullet_move()
{
    // 英雄子弹移动
    for (int i = 0; i < hero_bullets_loc.size(); i++)
    {
        QRect next_rect(hero_bullets_loc[i][0], hero_bullets_loc[i][1], 15, 15);
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
        else if (is_colliding(next_rect))
        {
            hero_bullets_loc.remove(i);
            i--;
        }
        else
        {
            for (int j = 0, k = Monsters_all.size() - 1; j <= k; j++, k--)
            {
                QRect next_rect2(Monsters_all[j]->get_loc().first, Monsters_all[j]->get_loc().second, Monsters_all[j]->get_pic_size().first, Monsters_all[j]->get_pic_size().second);
                QRect next_rect3(Monsters_all[k]->get_loc().first, Monsters_all[k]->get_loc().second, Monsters_all[k]->get_pic_size().first, Monsters_all[k]->get_pic_size().second);
                if (next_rect.intersects(next_rect2))
                {
                    monsters_hit(i, j);
                    hero_bullets_loc.remove(i);
                    i--;
                }
                if (next_rect.intersects(next_rect3))
                {
                    monsters_hit(i, k);
                    hero_bullets_loc.remove(i);
                    i--;
                }
            }
        }
    }

    // 怪物子弹移动
    QRect hero_rect(hero_loc[0], hero_loc[1], 40, 40);
    for (int i = 0; i < Yuka_loc.size(); i++)
    {
        for (int j = 0; j < Yuka_loc[i].second.size(); j++)
        {
            QRect next_rect(Yuka_loc[i].second[j][0], Yuka_loc[i].second[j][1], 20, 20);
            switch (Yuka_loc[i].second[j][2])
            {
            case 0: // 上
                Yuka_loc[i].second[j][1] -= 30;
                break;
            case 1: // 下
                Yuka_loc[i].second[j][1] += 30;
                break;
            case 2: // 左
                Yuka_loc[i].second[j][0] -= 30;
                break;
            case 3: // 右
                Yuka_loc[i].second[j][0] += 30;
                break;
            }
            if (Yuka_loc[i].second[j][0] < 0 || Yuka_loc[i].second[j][0] > 1000 || Yuka_loc[i].second[j][1] < 0 || Yuka_loc[i].second[j][1] > 800)
            {
                Yuka_loc[i].second.remove(j);
                j--;
            }
            else if (is_colliding(next_rect))
            {
                Yuka_loc[i].second.remove(j);
                j--;
            }
            else if (hero_rect.intersects(next_rect))
            {
                int revival_time = hero->get_hero_revival_times();
                hero->set_blood(hero->get_blood() - Monsters_all[i]->get_bullet_attack());
                if (hero->get_blood() <= 0 && revival_time == 0)
                {
                    game_fail();
                }
                else if (hero->get_blood() <= 0 && revival_time > 0)
                {
                    revival_time--;
                    hero_loc[0] = 0;
                    hero_loc[1] = 0;
                    hero->set_blood(hero->get_blood_max());
                    update();
                }
                hero_hp_label->setText("血量: " + QString::number(hero->get_blood()));
                Yuka_loc[i].second.remove(j);
                j--;
            }
        }
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
    for (int i = 0; i < Yuka_loc.size(); i++)
    {
        for (int j = 0; j < Yuka_loc[i].second.size(); j++)
        {
            pen.drawPixmap(Yuka_loc[i].second[j][0], Yuka_loc[i].second[j][1], 20, 20, *Monsters_all[Yuka_loc[i].first]->get_bullets_pic()); // 绘制子弹
        }
    }
}

void FightInterface::check_hero_attack()
{
    int revival_time = hero->get_hero_revival_times();
    int hero_hp = hero->get_blood();
    QRect hero_rect(hero_loc[0], hero_loc[1], 80, 80);
    for (int i = 0; i < Monsters_all.size(); i++)
    {
        QRect monster_rect((Monsters_all[i]->get_loc()).first, (Monsters_all[i]->get_loc()).second, 25, 20);
        if (hero_rect.intersects(monster_rect))
        {
            hero->set_blood(hero_hp - Monsters_all[i]->get_monster_close_attack());
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
                hero_hp = hero->get_blood_max();
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
    for (int i = 0; i < game_map.size(); i++)
    {
        for (int j = 0; j < game_map[i].size(); j++)
        {
            if (game_map[i][j] == 0)
            {
                pen.drawPixmap(j * 50, i * 50, 50, 50, QPixmap("../src/Sprite/brick.png")); // 绘制背景
            }
            else if (game_map[i][j] == 1)
            {
                pen.drawPixmap(j * 50, i * 50, 50, 50, QPixmap("../src/Sprite/barrier.png")); // 绘制背景
            }
        }
    }
    pen.drawPixmap(hero_loc[0], hero_loc[1], 40, 40, *hero->get_pic()); // 绘制英雄
    for (int i = 0; i < Monsters_all.size(); i++)
    {
        pen.drawPixmap(Monsters_all[i]->get_loc().first, Monsters_all[i]->get_loc().second, Monsters_all[i]->get_pic_size().first, Monsters_all[i]->get_pic_size().second, *Monsters_all[i]->get_pic()); // 绘制怪物
    }
    paint_bullet();
}

void FightInterface::time_stop()
{
    timer->stop();
    bullet_move_timer->stop();
    monster_timer->stop();
    bullet_generate_timer->stop();
    move_timer->stop();
}

void FightInterface::back_to_main() // 返回主界面
{
    this->hide();
    time_stop();
    emit changeWidgetsignal(0);
}

void FightInterface::hero_level_up()
{
    int exp = hero->get_hero_exp();
    int level = hero->get_hero_level();
    if ((exp == 10 && level == 1) || (exp == 20 && level == 2) || (exp == 30 && level == 3) || (exp == 40 && level == 4))
    {
        hero->set_hero_exp(0), hero->set_hero_level(level);
        level++;
        time_stop();
        emit changeWidgetsignal(6);
    }
    hero_level_label->setText("英雄等级: " + QString::number(level));
}

void FightInterface::get_level_up_change(int type)
{
    switch (type)
    {
    case 0:
        hero->set_blood(hero->get_blood() + 3);
        break;
    case 1:
        hero->set_bullet_attack(hero->get_bullet_attack() + 1);
        break;
    case 2:
        hero->set_speed(hero->get_speed() + 5);
        break;
    case 3:
        hero->set_base_killed_coin(hero->get_base_killed_coin() + 1);
        break;
    case 4:
        hero->set_hero_exp(hero->get_hero_exp() + 3);
        break;
    case 5:
        bullet_generate_timer->setInterval(bullet_generate_timer->interval() - 100);
        break;
    default:
        break;
    }
    time_stop();
}

void FightInterface::get_prop_type(int type)
{
    switch (type)
    {
    case 0:
        hero->set_bullet_attack(hero->get_bullet_attack() + 3);
        break;
    case 1:
        hero->set_speed(hero->get_speed() + 5);
        break;
    case 2:
        hero->set_hero_revival_times(hero->get_hero_revival_times() + 1);
        break;
    case 3:
        hero->set_base_killed_coin(hero->get_base_killed_coin() + 1);
        break;
    case 4:
        hero->set_blood(hero->get_blood() + 3);
        break;
    default:
        break;
    }
}

void FightInterface::save_data()
{
    time_stop();
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
        this->hide();
        game_end();
        emit game_end_type_signal(0);
        emit changeWidgetsignal(3);
        time_stop();
    }
}

void FightInterface::continue_game()
{
    timer->start();
    bullet_generate_timer->start();
    bullet_move_timer->start();
    move_timer->start();
    monster_timer->start();
}

void FightInterface::game_end()
{
    Monsters_all.clear();
    Yuka_loc.clear();
    hero_loc[0] = 0, hero_loc[1] = 0;
    hero_bullets_loc.clear();
    hero->set_hero_coin(hero->get_hero_coin() + coin); // 金币数更新
    coin = 0;
    coin_label->setText("金币数: " + QString::number(hero->get_hero_coin()));
}

void FightInterface::game_fail() // 游戏失败
{
    time_stop();
    this->hide();
    game_end();
    emit game_end_type_signal(1);
    emit changeWidgetsignal(3);
}
