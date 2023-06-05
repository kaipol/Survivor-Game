#ifndef SELECTHEROES_H
#define SELECTHEROES_H
#pragma once
#include <Qpushbutton>
#include <Qmediaplayer>
#include <QPainter>
#include <QLabel>

class SelectHeroesInterface : public QWidget
{
    Q_OBJECT
public slots:
    void hero_to_fight(int type); // 英雄进入战斗界面
    void again_select();          // 重新开始

signals:
    void changeWidgetsignal(int Index);  // 切换窗口信号
    void selectHerosignal(QString name); // 切换英雄信号
    void selectMapsignal(int type);      // 切换地图信号

public:
    SelectHeroesInterface(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    void select_map(int type);

private:
    QPushButton *select_hero1; // 英雄1
    QLabel *hero1_hp;          // 英雄1血量
    QLabel *hero1_atk;         // 英雄1攻击力
    QLabel *hero1_speed;       // 英雄1速度

    QPushButton *select_hero2; // 英雄2
    QLabel *hero2_hp;          // 英雄2血量
    QLabel *hero2_atk;         // 英雄2攻击力
    QLabel *hero2_speed;       // 英雄2速度

    QLabel *map_label;        // 地图选择
    QPushButton *select_map1; // 选择地图1
    QPushButton *select_map2; // 选择地图2
    QPushButton *select_map3; // 选择地图3
    bool again;               // 是否重新开始

    QMediaPlayer *bgm_select;
};
#endif // SELECTHEROES_H