#include "Characters.h"

//! Heroes
Heroes::Heroes(QString name1)
{
    name = name1;
    if (name1 == "AL-1S")
    {
        blood = blood_max = 20;
        bullet_attack = 5;
        speed = 10;
        pic = new QPixmap("../src/Sprite/MCH_PL001_001.png");
        bullets_pic = new QPixmap("../src/Sprite/AL-1S-bullet.png");
    }
    else if (name1 == "NOA")
    {
        blood = blood_max = 13;
        bullet_attack = 7;
        speed = 15;
        pic = new QPixmap("../src/Sprite/MCH_PL006_001.png");
        bullets_pic = new QPixmap("../src/Sprite/NOA-bullet.png");
    }
    exp = 0;
    level = 1;
    revival_times = 0;
    direction = 1;
    coin = 0;
    hp_label = new QLabel("血量: " + QString::number(blood));
    base_kill_coin = 0;
    base_kill_exp = 0;
}
Heroes::Heroes(const Heroes &hero_mir)
{
    name = hero_mir.name;
    hp_label = hero_mir.hp_label;
    blood = hero_mir.blood;
    blood_max = hero_mir.blood_max;
    bullet_attack = hero_mir.bullet_attack;
    exp = hero_mir.exp;
    level = hero_mir.level;
    speed = hero_mir.speed;
    coin = hero_mir.coin;
    direction = hero_mir.direction;
    base_kill_coin = hero_mir.base_kill_coin;
    base_kill_exp = hero_mir.base_kill_exp;
    revival_times = hero_mir.revival_times;
    pic = hero_mir.pic;
    bullets_pic = hero_mir.bullets_pic;
}
Heroes *Heroes::operator=(const Heroes &hero_mir)
{
    name = hero_mir.name;
    hp_label = hero_mir.hp_label;
    blood = hero_mir.blood;
    blood_max = hero_mir.blood_max;
    bullet_attack = hero_mir.bullet_attack;
    exp = hero_mir.exp;
    level = hero_mir.level;
    speed = hero_mir.speed;
    coin = hero_mir.coin;
    direction = hero_mir.direction;
    base_kill_coin = hero_mir.base_kill_coin;
    base_kill_exp = hero_mir.base_kill_exp;
    revival_times = hero_mir.revival_times;
    pic = hero_mir.pic;
    bullets_pic = hero_mir.bullets_pic;
    return this;
}
QPixmap *Heroes::get_pic()
{
    return pic;
}
QPixmap *Heroes::get_bullets_pic()
{
    return bullets_pic;
}
QString Heroes::get_name()
{
    return name;
}
int Heroes::get_blood()
{
    return blood;
}
int Heroes::get_bullet_attack()
{
    return bullet_attack;
}
int Heroes::get_hero_exp()
{
    return exp;
}
int Heroes::get_hero_level()
{
    return level;
}
int Heroes::get_speed()
{
    return speed;
}

void Heroes::set_bullet_attack(int attack)
{
    bullet_attack = attack;
}
void Heroes::set_hero_exp(int exp)
{
    this->exp = exp;
}
void Heroes::set_hero_level(int level)
{
    this->level = level;
}
void Heroes::set_speed(int speed)
{
    speed = speed;
}
void Heroes::set_hero_revival_times(int times)
{
    revival_times = times;
}
void Heroes::set_base_kill_exp(int exp)
{
    base_kill_exp = exp;
}
void Heroes::set_base_killed_coin(int coin)
{
    base_kill_coin = coin;
}
void Heroes::set_hero_loc(int x, int y)
{
    loc[0] = x;
    loc[1] = y;
}
void Heroes::set_direction(int direction)
{
    this->direction = direction;
}
void Heroes::set_hero_coin(int coin)
{
    this->coin = coin;
}
void Heroes::set_blood(int blood)
{
    this->blood = blood;
}
void Heroes::set_blood_max(int blood_max)
{
    this->blood_max = blood_max;
}
void Heroes::set_loc(int x, int y)
{
    loc[0] = x;
    loc[1] = y;
}
int Heroes::get_hero_revival_times()
{
    return revival_times;
}
int Heroes::get_base_kill_exp()
{
    return base_kill_exp;
}
int Heroes::get_base_killed_coin()
{
    return base_kill_coin;
}
int Heroes::get_direction()
{
    return direction;
}
int Heroes::get_blood_max()
{
    return blood_max;
}
int Heroes::get_hero_coin()
{
    return coin;
}
QPair<int, int> Heroes::get_loc()
{
    return QPair<int, int>(loc[0], loc[1]);
}
QLabel *Heroes::get_hp_label()
{
    return hp_label;
}

//! Monsters
Monsters::Monsters(QString name)
{
    if (name == "robot")
    {
        blood = 7;
        close_attack = 1;
        bullet_attack = 0;
        speed = 10;
        killed_exp = 1;
        killed_coin = 1;
        blood_max = 7;
        pic = new QPixmap("../src/Sprite/BCH_001.png");
        pic_size.first = 25;
        pic_size.second = 20;
    }
    else if (name == "yuka")
    {
        blood = 15;
        close_attack = 3;
        bullet_attack = 3;
        speed = 5;
        killed_exp = 5;
        killed_coin = 5;
        blood_max = 15;
        pic = new QPixmap("../src/Sprite/BCH_003.png");
        bullets_pic = new QPixmap("../src/Sprite/yuka_bullet.png");
        pic_size.first = 40;
        pic_size.second = 40;
    }
    direction = 0;
    hp_label = new QLabel("血量: " + QString::number(blood));
}
QString Monsters::get_name()
{
    return name;
}

QPixmap *Monsters::get_pic()
{
    return pic;
}
QPixmap *Monsters::get_bullets_pic()
{
    return bullets_pic;
}
int Monsters::get_blood()
{
    return blood;
}
int Monsters::get_blood_max()
{
    return blood_max;
}
int Monsters::get_monster_close_attack()
{
    return close_attack;
}
int Monsters::get_bullet_attack()
{
    return bullet_attack;
}
int Monsters::get_speed()
{
    return speed;
}
int Monsters::get_direction()
{
    return direction;
}
int Monsters::get_monster_kill_exp()
{
    return killed_exp;
}
int Monsters::get_monster_killed_coin()
{
    return killed_coin;
}
void Monsters::set_loc(int x, int y)
{
    loc[0] = x;
    loc[1] = y;
}
void Monsters::set_blood(int blood)
{
    this->blood = blood;
}
void Monsters::set_blood_max(int blood_max)
{
    this->blood_max = blood_max;
}
void Monsters::set_direction(int direction)
{
    this->direction = direction;
}
void Monsters::set_speed(int speed)
{
    this->speed = speed;
}
void Monsters::set_monster_killed_coin(int coin)
{
    killed_coin = coin;
}
void Monsters::set_bullet_attack(int attack)
{
    bullet_attack = attack;
}
QPair<int, int> Monsters::get_loc()
{
    return QPair<int, int>(loc[0], loc[1]);
}
QLabel *Monsters::get_hp_label()
{
    return hp_label;
}
QPair<int, int> Monsters::get_pic_size()
{
    return pic_size;
}
