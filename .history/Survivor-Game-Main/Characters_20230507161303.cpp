#include "./Characters.h"
Heroes::Heroes(QString name)
{
    HeroesLoc[0] = 0, HeroesLoc[1] = 0;
    if (name == "AL-1S")
    {
        blood = 10;
        attack = 5;
        defense = 5;
    }
    else if (name == "NOA")
    {
        blood = 7;
    }
}

void set_Heroes_loc(int x, int y)
{
    HeroesLoc[0] = x;
    HeroesLoc[1] = y;
}

Monsters::Monsters(QString name)
{
    if (name == "robot")
    {
        blood = 3;
        attack = 1;
        defense = 0;
    }
    else if (name == "")
    {
    }
}