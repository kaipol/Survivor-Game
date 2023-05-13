#include "Characters.h"

//! Heroes
Heroes::Heroes(QString name)
{
    if (name == "AL-1S")
    {
        blood = 20;
        bullet_attack = 5;
        speed = 10;
        hero_pic = new QPixmap("../src/Sprite/MCH_PL001_001.png");
        hero_bullets = new QPixmap("../src/Sprite/AL-1S-bullet.png");
    }
    else if (name == "NOA")
    {
        blood = 13;
        bullet_attack = 7;
        speed = 15;
        hero_pic = new QPixmap("../src/Sprite/MCH_PL006_001.png");
        hero_bullets = new QPixmap("../src/Sprite/bullet-NOA.png");
    }
    exp = 0;
    level = 1;
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
void Heroes::set_hero_loc(int x, int y)
{
    loc[0] = x;
    loc[1] = y;
}
int Heroes::get_hero_revival_times()
{
    return revival_times;
}

//! Monsters
Monsters::Monsters(QString name)
{
    if (name == "robot")
    {
        blood = 5;
        close_attack = 1;
        bullet_attack = 0;
        speed = 10;
        killed_exp = 1;
        monster_pic = new QPixmap("../src/Sprite/BCH_001.png");
    }
    else if (name == "yuka")
    {
        blood = 15;
        close_attack = 3;
        bullet_attack = 3;
        speed = 5;
        killed_exp = 4;
        monster_pic = new QPixmap("../src/Sprite/BCH_003.png");
    }
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
void Monsters::set_monster_loc(int x, int y)
{
    loc[0] = x;
    loc[1] = y;
}