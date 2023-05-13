#ifndef CHARACTERS_H
#define CHARACTERS_H
#endif // CHARACTERS_H
#pragma once
#include <Qstring>
#include <QPixmap>
#include <QPair>

class Heroes
{
    QString name;
    int blood;
    int bullet_attack;
    int defense;
    int exp;
    int level;
    int speed;

protected:
    QPixmap *hero_pic;     // 英雄图片
    QPixmap *hero_bullets; // 子弹图片

public:
    Heroes(QString name);
    QPixmap *get_hero_pic();     // 获取英雄图片
    QPixmap *get_hero_bullets(); // 获取子弹图片
    int get_hero_blood();        // 获取英雄血量
    int get_hero_attack();       // 获取英雄攻击力
    int get_hero_defense();      // 获取英雄防御力
    int get_hero_exp();          // 获取英雄经验值
    int get_hero_level();        // 获取英雄等级
    int get_hero_speed();        // 获取英雄速度
};

class Monsters
{
    QString name;
    int blood;
    int close_attack;
    int bullet_attack;
    int defense;
    int speed;

protected:
    QPixmap *monster_pic;     // 怪物图片
    QPixmap *monster_bullets; // 子弹图片

public:
    Monsters(QString);
    QPixmap *get_monster_pic();     // 获取怪物图片
    QPixmap *get_monster_bullets(); // 获取子弹图片
    int get_monster_blood();        // 获取怪物血量
    int get_monster_close_attack(); // 获取怪物攻击力
    int get_monster_defense();      // 获取怪物防御力
    int get_monster_speed();        // 获取怪物速度
};
