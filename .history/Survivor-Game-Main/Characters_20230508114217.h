#ifndef CHARACTERS_H
#define CHARACTERS_H
#endif // CHARACTERS_H
#pragma once
#include <QWidget>
#include <Qstring>

class Heroes
{
private:
    QString name;
    int blood;
    int attack;
    int defense;
    int HeroesLoc[2] = {0};

public:
    Heroes(QString name);
    void set_Heroes_loc(int, int); // 角色移动函数
};

class Monsters
{
    QString name;
    int blood;
    int attack;
    int defense;
    int MonstersNum;
    QVector<QPair<int, int>> MonstersLoc;

public:
    Monsters(QString);
    void Monsters_move(); // 怪物移动函数
};
