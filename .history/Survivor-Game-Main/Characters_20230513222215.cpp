#include "Characters.h"

Heroes::Heroes(QString name)
{
    if (name == "AL-1S")
    {
        blood = 20;
        bullet_attack = 5;
        hero_pic = new QPixmap("../src/Sprite/MCH_PL001_001.png");
        hero_bullets = new QPixmap("../src/Sprite/AL-1S-bullet.png");
    }
    else if (name == "NOA")
    {
        blood = 13;
        bullet_attack = 7;
        hero_pic = new QPixmap("../src/Sprite/MCH_PL006_001.png");
        hero_bullets = new QPixmap("../src/Sprite/bullet-NOA.png");
    }
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

Monsters::Monsters(QString name)
{
    if (name == "robot")
    {
        blood = 5;
        close_attack = 1;
        bullet_attack = 0;
        monster_pic = new QPixmap("../src/Sprite/BCH_001.png");
    }
    else if (name == "yuka")
    {
        blood = 15;
        close_attack = 3;
        bullet_attack = 3;

        monster_pic = new QPixmap("../src/Sprite/BCH_003.png");
    }
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
