#include "Characters.h"

Heroes::Heroes(QString name)
{
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

Monsters::Monsters(QString name)
{
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
