#ifndef CHARACTERS_H
#define CHARACTERS_H
#pragma once
#include <Qstring>
#include <QPixmap>
#include <QPair>
#include <QLabel>

class Heroes
{
    QString name;
    QLabel *hero_hp_label;
    int blood;
    int exp;
    int level;
    int speed;
    int revival_times;
    int direction; // 英雄方向: 0上 1下 2左 3右
    int loc[2] = {0, 0};

protected:
    QPixmap *hero_pic;     // 英雄图片
    QPixmap *hero_bullets; // 子弹图片

public:
    Heroes(QString name);
};
class AL_1S : public Heroes
{

    static int blood_max;
    static int bullet_attack;
    static int speed;

public:
    virtual QPixmap *get_hero_pic();          // 获取英雄图片
    virtual QPixmap *get_hero_bullets();      // 获取子弹图片
    virtual void set_hero_blood(int);         // 设置英雄血量
    virtual void set_hero_attack(int);        // 设置英雄攻击力
    virtual void set_hero_exp(int);           // 设置英雄经验值
    virtual void set_hero_level(int);         // 设置英雄等级
    virtual void set_hero_speed(int);         // 设置英雄速度
    virtual void set_hero_revival_times(int); // 设置英雄复活次数
    virtual void set_hero_loc(int, int);      // 设置英雄位置
    virtual void set_hero_direction(int);     // 设置英雄方向
    virtual int get_hero_blood();             // 获取英雄血量
    virtual int get_hero_blood_max();         // 获取英雄最大血量
    virtual int get_hero_attack();            // 获取英雄攻击力
    virtual int get_hero_exp();               // 获取英雄经验值
    virtual int get_hero_level();             // 获取英雄等级
    virtual int get_hero_speed();             // 获取英雄速度
    virtual int get_hero_revival_times();     // 获取英雄复活时间
    virtual int get_hero_direction();         // 获取英雄方向
    virtual QPair<int, int> get_hero_loc();   // 获取英雄位置
    virtual QLabel *get_hero_hp_label();      // 获取英雄血量标签
};

class Monsters
{
    QString name;
    QLabel *monster_hp_label;
    int blood;
    int close_attack;
    int bullet_attack;
    int speed;
    int direction; // 怪物方向: 0上 1下 2左 3右
    int killed_exp;
    static int killed_coin;
    int loc[2] = {0, 0};
    QPair<int, int> pic_size;

protected:
    QPixmap *monster_pic;     // 怪物图片
    QPixmap *monster_bullets; // 子弹图片

public:
    Monsters(QString);
    QPixmap *get_monster_pic();        // 获取怪物图片
    QPixmap *get_monster_bullets();    // 获取子弹图片
    QString get_monster_name();        // 获取怪物名字
    void set_monster_loc(int, int);    // 设置怪物位置
    void set_monster_blood(int);       // 设置怪物血量
    void set_monster_direction(int);   // 设置怪物方向
    void set_monster_speed(int);       // 设置怪物速度
    void set_monster_killed_coin(int); // 设置怪物被杀死后掉落金币
    int get_monster_blood();           // 获取怪物血量
    int get_monster_close_attack();    // 获取怪物近战攻击力
    int get_monster_bullet_attack();   // 获取怪物远程攻击力
    int get_monster_speed();           // 获取怪物速度
    int get_monster_direction();       // 获取怪物方向
    int get_monster_exp();             // 获取怪物经验值
    int get_monster_killed_coin();     // 获取怪物被杀死后掉落金币
    QPair<int, int> get_monster_loc(); // 获取怪物位置
    QLabel *get_monster_hp_label();    // 获取怪物血量标签
};

#endif // CHARACTERS_H
