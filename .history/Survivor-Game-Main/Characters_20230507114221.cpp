#include "./Characters.h"
Heroes::Heroes(QString name)
{
    if (name == "AL-1S")
    {
        blood = 10;
        attack = 5;
        defense = 5;
    }
    else if (name == "")
    {
    }
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