#ifndef FightInterface_H
#define FightInterface_H
#pragma once

#include <QApplication>
#include <QVector>
#include <QPushButton>
#include <QPainter>
#include <QKeyEvent>
#include <QTimer>
#include <QMap>
#include <QLabel>
#include <Qmediaplayer>
#include "Characters.h"
#include "Prop.h"
#include "GameMap.h"

class FightInterface : public QWidget
{
    Q_OBJECT
public:
    FightInterface(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event); // 绘制事件
    void paint_bullet();                 // 绘制子弹
    void hero_level_up();                // 英雄升级
    void time_start();                   // 时间开始
    void time_stop();                    // 时间停止
    bool is_colliding(QRect rect1);      // 碰撞检测
    void create_obstacle_rects();        // 创建障碍物矩形
    void monsters_hit(int i, int j);     // 重新生成怪物
    void game_end();                     // 游戏结束
    void drop_prop();

public slots:
    void keyPressEvent(QKeyEvent *event); // 键盘按下事件
    void back_to_main();                  // 返回主界面
    void time_control();                  // 时间控制
    void game_fail();                     // 游戏失败
    void save_data();                     // 保存游戏

    void Heroes_init(QString name); // 英雄初始化
    void Monsters_move();           // 怪物移动函数
    void Monsters_generate();       // 怪物生成函数
    void bullet_generate();         // 子弹生成槽函数
    void bullet_move();             // 子弹移动槽函数
    void check_hero_attack();       // 检查攻击进行槽函数
    void get_level_up_change(int);  // 获取升级选择信号
    void get_prop_type(int);        // 获取道具类型信号
    void get_coin(int);             // 获取金币信号
    void get_data(Heroes);          // 获取存档信号
    void continue_game();           // 继续游戏
    void get_map_type(int);         // 获取地图类型信号

signals:
    void changeWidgetsignal(int Index);  // 切换窗口信号
    void game_end_type_signal(int type); // 游戏结束类型信号
    void save_data_signal(Heroes);       // 保存游戏信号
    void is_fight();                     // 是否为战斗界面
    void now_coin(int);                  // 当前金币数
    void hero_level_up_signal();         // 英雄升级信号

private:
    QVector<Monsters *> Monsters_all;                    // 怪物
    QVector<QPair<int, QVector<QVector<int>>>> Yuka_loc; // yuka位置

    Heroes *hero;              // 英雄
    int hero_loc[2];           // 英雄位置
    QLabel *hero_hp_label;     // 英雄血量标签
    QLabel *hero_level_label;  // 英雄等级标签
    QLabel *hero_revive_label; // 英雄复活次数标签
    int hero_direction;        // 英雄方向: 0上 1下 2左 3右

    QVector<QVector<int>> hero_bullets_loc; // 英雄子弹位置
    QPixmap *hero_bullets_pic;              // 英雄子弹图片

    int coin = 0;       // 局内金币
    int base_kill_coin; // 基础击杀金币
    int base_kill_exp;
    QLabel *coin_label; // 金币标签

    Prop *prop1; // 道具1:回复3HP
    Prop *prop2; // 道具2:速度+5
    Prop *prop3; // 道具3:怪物速度-3

    QTimer *timer;                 // 战斗定时器
    QTimer *move_timer;            // 移动定时器
    QTimer *bullet_generate_timer; // 子弹生成定时器
    QTimer *bullet_move_timer;     // 子弹移动定时器
    QTimer *monster_timer;         // 怪物生成定时器
    int remain_min;                // 剩余分钟
    int remain_sec;                // 剩余秒数
    QLabel *time_label;            // 时间显示

    GameMap *game_map_widget; // 游戏地图
    QVector<QVector<int>>
        game_map;                     // 游戏地图
    QVector<QVector<int>> drop_props; // 掉落道具
    QVector<QRect> obstacle_rects;    // 障碍物矩形
    QPushButton *savebutton;          // 保存按钮
    QPushButton *backbutton;          // 返回按钮
    QMediaPlayer *bgm;                // 背景音乐
};

#endif // FightInterface_H