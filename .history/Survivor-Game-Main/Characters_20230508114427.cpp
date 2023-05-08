#include "Characters.h"

Heroes::Heroes(QString name)
{
    HeroesLoc[0] = 0, HeroesLoc[1] = 0;
    if (name == "AL-1S")
    {
        blood = 20;
        attack = 5;
        defense = 5;
    }
    else if (name == "NOA")
    {
        blood = 13;
        attack = 7;
        defense = 3;
    }
}

void Heroes::set_Heroes_loc(int x, int y)
{
    HeroesLoc[0] = x;
    HeroesLoc[1] = y;
}

Monsters::Monsters(QString name)
{
    MonstersLoc = {{0, 0}, {0, 0}, {0, 0}};
    if (name == "robot")
    {
        blood = 5;
        attack = 2;
        defense = 0;
    }
    else if (name == "")
    {
    }
}
