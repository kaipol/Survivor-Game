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
void Heroes::set_hero_loc(int x, int y) // 设置英雄位置
{
    HeroesLoc[0] = x, HeroesLoc[1] = y;
}

QPair<int, int> Heroes::get_hero_loc() // 获取英雄位置
{
    return QPair<int, int>(HeroesLoc[0], HeroesLoc[1]);
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

void Monsters::set_monster_loc(int x, int y) // 设置怪物位置
{
    Monsters_Loc[0] = x, Monsters_Loc[1] = y;
}

QPair<int, int> Monsters::get_monster_loc() // 获取怪物位置
{
    return QPair<int, int>(Monsters_Loc[0], Monsters_Loc[1]);
}
