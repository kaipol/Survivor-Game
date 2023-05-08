#ifndef FightInterface_H
#define FightInterface_H
#endif // FightInterface_H
#pragma once

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
    void Heroes_and_Monsters_init(QString name);

signals:
    void changeWidgetsignal(int Index); // 切换窗口信号
    // void save_date_signal();            // 保存游戏信号

private:
    int MonstersNum;                         // 怪物数量
    QMap<int, Monsters> Monsters_all;        // 怪物
    QMap<int, QPair<int, int>> Monsters_loc; // 怪物位置
    QMap<int, QPixmap *> Monsters_pic;       // 怪物图片
    QMap<int, QPixmap *> Monsters_bullets;   // 怪物子弹
    QMap<int, QLabel *> Monsters_hp;
    QMap<int, QPair<int, int>> Monsters_hp_loc; // 怪物血量位置

    Heroes *hero;          // 英雄
    int hero_loc[2];       // 英雄位置
    QPixmap *hero_pic;     // 英雄图片
    QPixmap *hero_bullets; // 英雄子弹
    QLabel *hero_hp;       // 英雄血量

    QTimer *timer; // 战斗定时器

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
