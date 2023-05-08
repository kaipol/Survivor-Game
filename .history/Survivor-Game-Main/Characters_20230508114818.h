#ifndef CHARACTERS_H
#define CHARACTERS_H
#endif // CHARACTERS_H
#pragma once
#include <Qstring>

class Heroes
{
private:
    QString name;
    int blood;
    int attack;
    int defense;

public:
    Heroes(QString name);
};

class Monsters
{
    QString name;
    int blood;
    int attack;
    int defense;

public:
    Monsters(QString);
    void Monsters_move(); // 怪物移动函数
};
