#ifndef CHARACTERS_H
#define CHARACTERS_H
#endif // CHARACTERS_H
#pragma once
#include <Qstring>
#include <QPixmap>
#include "FightInterface.h"

class Heroes
{
protected:
    QString name;
    int blood;
    int attack;
    int defense;
    int HeroesLoc[2] = {0}; // 英雄位置

protected:
    QPixmap *hero_pic;     // 英雄图片
    QPixmap *hero_bullets; // 子弹

public:
    friend class FightInterface;
    Heroes(QString name);
};

class Monsters
{
protected:
    QString name;
    int blood;
    int attack;
    int defense;
    int Monsters_Loc[2];

protected:
    QPixmap *monster_pic;     // 怪物图片
    QPixmap *monster_bullets; // 子弹

public:
    friend class FightInterface;
    Monsters(QString);
};
