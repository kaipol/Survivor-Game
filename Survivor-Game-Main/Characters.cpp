#include "Characters.h"

Heroes::Heroes(QString name)
{
    if (name == "AL-1S")
    {
        blood = 20;
        attack = 5;
        hero_pic = new QPixmap("../src/Sprite/MCH_PL001_001.png");
        hero_bullets = new QPixmap("../src/Sprite\/AL-1S-bullet.png");
    }
    else if (name == "NOA")
    {
        blood = 13;
        attack = 7;
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

Monsters::Monsters(QString name)
{
    if (name == "robot")
    {
        blood = 5;
        attack = 2;
        monster_pic = new QPixmap("../src/Sprite/BCH_001.png");
        monster_bullets = new QPixmap("../src/Sprite/Monster_bullet.png");
    }
    else if (name == "")
    {
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
