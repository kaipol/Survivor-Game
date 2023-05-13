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
    int exp;
    int level;
    int speed;
    int revival_times;

protected:
    QPixmap *hero_pic;     // 英雄图片
    QPixmap *hero_bullets; // 子弹图片

public:
    Heroes(QString name);
    QPixmap *get_hero_pic();      // 获取英雄图片
    QPixmap *get_hero_bullets();  // 获取子弹图片
    void set_hero_blood(int);     // 设置英雄血量
    void set_hero_attack(int);    // 设置英雄攻击力
    void set_hero_exp(int);       // 设置英雄经验值
    void set_hero_level(int);     // 设置英雄等级
    void set_hero_speed(int);     // 设置英雄速度
    int get_hero_blood();         // 获取英雄血量
    int get_hero_attack();        // 获取英雄攻击力
    int get_hero_exp();           // 获取英雄经验值
    int get_hero_level();         // 获取英雄等级
    int get_hero_speed();         // 获取英雄速度
    int get_hero_revival_times(); // 获取英雄复活时间
};

class Monsters
{
    QString name;
    int blood;
    int close_attack;
    int bullet_attack;
    int speed;
    int direction;
    int exp;

protected:
    QPixmap *monster_pic;     // 怪物图片
    QPixmap *monster_bullets; // 子弹图片

public:
    Monsters(QString);
    QPixmap *get_monster_pic();      // 获取怪物图片
    QPixmap *get_monster_bullets();  // 获取子弹图片
    int get_monster_blood();         // 获取怪物血量
    int get_monster_close_attack();  // 获取怪物近战攻击力
    int get_monster_bullet_attack(); // 获取怪物远程攻击力
    int get_monster_speed();         // 获取怪物速度
    int get_monster_direction();     // 获取怪物方向
    int get_monster_exp();           // 获取怪物经验值
};
