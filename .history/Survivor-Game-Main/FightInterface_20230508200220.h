#ifndef FightInterface_H
#define FightInterface_H
#endif // FightInterface_H
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

class FightInterface : public QWidget
{
    Q_OBJECT
public:
    FightInterface(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    // void keyPressEvent(QKeyEvent *event);

    // void Heroes_move(int x, int y); // 英雄移动函数
    // void Monsters_move();           // 怪物移动函数
    void paintMonsters(); // 绘制怪物

public slots:
    void back_to_main();
    void Heroes_and_Monsters_init(QString name); // 英雄和怪物初始化
    void game_over(int);                         // 游戏结束
    void play_again();                           // 重新开始

signals:
    void changeWidgetsignal(int Index); // 切换窗口信号
    // void save_date_signal();            // 保存游戏信号

private:
    int MonstersNum;                            // 怪物数量
    QMap<int, Monsters> Monsters_all;           // 怪物
    QMap<int, QPair<int, int>> Monsters_loc;    // 怪物位置
    QMap<int, QPixmap *> Monsters_pic;          // 怪物图片
    QMap<int, QPixmap *> Monsters_bullets;      // 怪物子弹
    QMap<int, int> Monsters_blood;              // 怪物血量
    QMap<int, QLabel *> Monsters_hp_label;      // 怪物血量
    QMap<int, QPair<int, int>> Monsters_hp_loc; // 怪物血量位置

    Heroes *hero;          // 英雄
    int hero_loc[2];       // 英雄位置
    QPixmap *hero_pic;     // 英雄图片
    QPixmap *hero_bullets; // 英雄子弹
    int hero_blood;        // 英雄血量
    QLabel *hero_hp_label; // 英雄血量
    int hero_hp_loc[2];    // 英雄血量位置

    QTimer *timer;      // 战斗定时器
    QLabel *time_label; // 时间显示

    QVector<QVector<int>>
        game_map = {
            {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
            {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
            {0, 0, 1, 0, 0, 0, 0, 1, 0, 0},
            {0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
            {0, 0, 0, 0, 0, 1, 0, 0, 1, 0},
            {0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 1, 0, 0, 1, 0},
            {0, 0, 0, 1, 0, 0, 0, 0, 1, 0},
        };                   // 游戏地图
    QPushButton *backbutton; // 返回按钮
    QPushButton *savebutton; // 保存按钮
};
