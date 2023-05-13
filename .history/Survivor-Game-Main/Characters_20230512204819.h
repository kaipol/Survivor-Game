#ifndef CHARACTERS_H
#define CHARACTERS_H
#endif // CHARACTERS_H
#pragma once
#include <Qstring>
#include <QPixmap>
#include <QPair>

class bullet
{
protected:
    int attack; // 子弹攻击力

public:
    bullet(int attack) : attack(attack) {}
};

class Heroes
{
    QString name;
    int blood;
    int attack;

protected:
    QPixmap *hero_pic;     // 英雄图片
    QPixmap *hero_bullets; // 子弹图片

public:
    Heroes(QString name);
    QPixmap *get_hero_pic();     // 获取英雄图片
    QPixmap *get_hero_bullets(); // 获取子弹图片
    int get_hero_blood();        // 获取英雄血量
};

class Monsters
{
    QString name;
    int blood;
    int attack;

protected:
    QPixmap *monster_pic;     // 怪物图片
    QPixmap *monster_bullets; // 子弹图片

public slots:
    void set_monster_loc(int x, int y); // 设置怪物位置

public:
    Monsters(QString);
    QPixmap *get_monster_pic();     // 获取怪物图片
    QPixmap *get_monster_bullets(); // 获取子弹图片
    int get_monster_blood();        // 获取怪物血量
};
