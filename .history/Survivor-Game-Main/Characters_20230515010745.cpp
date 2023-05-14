#include "Characters.h"

//! Heroes
Heroes::Heroes(QString name)
{
    if (name == "AL-1S")
    {
        blood = blood_max = 20;
        bullet_attack = 5;
        speed = 10;
        hero_pic = new QPixmap("../src/Sprite/MCH_PL001_001.png");
        hero_bullets = new QPixmap("../src/Sprite/AL-1S-bullet.png");
    }
    else if (name == "NOA")
    {
        blood = blood_max = 13;
        bullet_attack = 7;
        speed = 15;
        hero_pic = new QPixmap("../src/Sprite/MCH_PL006_001.png");
        hero_bullets = new QPixmap("../src/Sprite/bullet-NOA.png");
    }
    exp = 0;
    level = 1;
    revival_times = 0;
    direction = 1;
    hero_hp_label = new QLabel("血量: " + QString::number(blood));
}
QPixmap *Heroes::get_hero_pic()
{
    return hero_pic;
}
QPixmap *Heroes::get_hero_bullets()
{
    return hero_bullets;
}
int Heroes::get_hero_blood()
{
    return blood;
}
int Heroes::get_hero_attack()
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
int Heroes::get_hero_speed()
{
    return speed;
}
void Heroes::set_hero_blood(int blood)
{
    this->blood = blood;
}
void Heroes::set_hero_attack(int attack)
{
    this->bullet_attack = attack;
}
void Heroes::set_hero_exp(int exp)
{
    this->exp = exp;
}
void Heroes::set_hero_level(int level)
{
    this->level = level;
}
void Heroes::set_hero_speed(int speed)
{
    this->speed = speed;
}
void Heroes::set_hero_revival_times(int times)
{
    revival_times = times;
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
void Heroes::set_hero_direction(int direction)
{
    this->direction = direction;
}
int Heroes::get_hero_revival_times()
{
    return revival_times;
}
int Heroes::get_base_killed_coin()
{
    return base_kill_coin;
}
int Heroes::get_hero_direction()
{
    return direction;
}
int Heroes::get_hero_blood_max()
{
    return blood_max;
}
QPair<int, int> Heroes::get_hero_loc()
{
    return QPair<int, int>(loc[0], loc[1]);
}
QLabel *Heroes::get_hero_hp_label()
{
    return hero_hp_label;
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
        monster_pic = new QPixmap("../src/Sprite/BCH_001.png");
    }
    else if (name == "yuka")
    {
        blood = 15;
        close_attack = 3;
        bullet_attack = 3;
        speed = 5;
        killed_exp = 5;
        killed_coin = 5;
        monster_pic = new QPixmap("../src/Sprite/BCH_003.png");
    }
    direction = 0;
    monster_hp_label = new QLabel("血量: " + QString::number(blood));
}
QString Monsters::get_monster_name()
{
    return name;
}

QPixmap *Monsters::get_monster_pic()
{
    return monster_pic;
}
QPixmap *Monsters::get_monster_bullets()
{
    return monster_bullets;
}
int Monsters::get_monster_blood()
{
    return blood;
}
int Monsters::get_monster_close_attack()
{
    return close_attack;
}
int Monsters::get_monster_bullet_attack()
{
    return bullet_attack;
}
int Monsters::get_monster_speed()
{
    return speed;
}
int Monsters::get_monster_direction()
{
    return direction;
}
int Monsters::get_monster_exp()
{
    return killed_exp;
}
int Monsters::get_monster_killed_coin()
{
    return killed_coin;
}
void Monsters::set_monster_loc(int x, int y)
{
    loc[0] = x;
    loc[1] = y;
}
void Monsters::set_monster_blood(int blood)
{
    this->blood = blood;
}
void Monsters::set_monster_direction(int direction)
{
    this->direction = direction;
}
void Monsters::set_monster_speed(int speed)
{
    this->speed = speed;
}
void Monsters::set_monster_killed_coin(int coin)
{
    killed_coin = coin;
}

QPair<int, int> Monsters::get_monster_loc()
{
    return QPair<int, int>(loc[0], loc[1]);
}
QLabel *Monsters::get_monster_hp_label()
{
    return monster_hp_label;
}