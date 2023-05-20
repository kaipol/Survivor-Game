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
#include "Characters.h"
#include "Prop.h"

class FightInterface : public QWidget
{
    Q_OBJECT
public:
    FightInterface(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event); // 绘制事件
    void paint_bullet();                 // 绘制子弹
    void hero_level_up();                // 英雄升级

public slots:
    void keyPressEvent(QKeyEvent *event); // 键盘按下事件
    void back_to_main();                  // 返回主界面
    void time_control();                  // 时间控制
    void game_fail();                     // 游戏失败
    void save_data();                     // 保存游戏

    void Heroes_and_Monsters_init(QString name); // 英雄和怪物初始化
    void Monsters_move();                        // 怪物移动函数
    void Monsters_generate();                    // 怪物生成函数
    void bullet_generate();                      // 子弹生成槽函数
    void bullet_move();                          // 子弹移动槽函数
    void check_hero_attack();                    // 检查攻击进行槽函数
    void get_level_up_change(int);               // 获取升级选择信号
    void get_prop_type(int);                     // 获取道具类型信号
    void get_data(Heroes *);                     // 获取存档信号
    void continue_game();                        // 继续游戏

signals:
    void changeWidgetsignal(int Index);  // 切换窗口信号
    void hero_hp_equal_0_signal();       // 英雄血量为0信号
    void enter_shop_signal(int coin);    // 进入商店信号
    void game_end_type_signal(int type); // 游戏结束类型信号
    void save_data_signal(Heroes *);     // 保存游戏信号
    void is_fight();

private:
    QMap<int, Monsters *> Monsters_all;              // 怪物
    QMap<int, QPair<int, int>> Monsters_bullets_loc; // 怪物子弹位置

    Heroes *hero;          // 英雄
    int hero_loc[2];       // 英雄位置
    QLabel *hero_hp_label; // 英雄血量标签
    int hero_direction;    // 英雄方向: 0上 1下 2左 3右

    QVector<QPair<int, int>> hero_bullets_loc; // 英雄子弹位置
    QPixmap *hero_bullets_pic;                 // 英雄子弹图片

    int coin = 0;       // 局内金币
    QLabel *coin_label; // 金币标签

    Prop *prop1; // 道具1:回复3HP
    Prop *prop2; // 道具2:速度+5
    Prop *prop3; // 道具3:怪物速度-3

    QTimer *timer;      // 战斗定时器
    int remain_min;     // 剩余分钟
    int remain_sec;     // 剩余秒数
    QLabel *time_label; // 时间显示

    QVector<QVector<int>>
        game_map;            // 游戏地图
    QPushButton *backbutton; // 返回按钮
    QPushButton *savebutton; // 保存按钮
};

#endif // FightInterface_H