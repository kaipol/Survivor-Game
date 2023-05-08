#ifndef CHARACTERS_H
#define CHARACTERS_H
#endif // CHARACTERS_H
#pragma once
#include <Qstring>
#include <QPixmap>

class Heroes
{
    QString name;
    int blood;
    int attack;
    int HeroesLoc[2] = {0}; // 英雄位置

protected:
    QPixmap *hero_pic;     // 英雄图片
    QPixmap *hero_bullets; // 子弹

public slots:
    void set_hero_loc(int x, int y);

public:
    Heroes(QString name);
};

class Monsters
{
    QString name;
    int blood;
    int attack;
    int Monsters_Loc[2];

protected:
    QPixmap *monster_pic;     // 怪物图片
    QPixmap *monster_bullets; // 子弹

public slots:
    void set_monster_loc(int x, int y); // 设置怪物位置

public:
    Monsters(QString);
};
