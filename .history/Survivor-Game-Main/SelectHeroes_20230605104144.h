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
    void hero1_to_fight();
    void hero2_to_fight();

signals:
    void changeWidgetsignal(int Index);  // 切换窗口信号
    void selectHerosignal(QString name); // 切换英雄信号

public:
    SelectHeroesInterface(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);

private:
    QPushButton *select_hero1; // 英雄1
    QLabel *hero1_hp;          // 英雄1血量
    QLabel *hero1_atk;         // 英雄1攻击力
    QLabel *hero1_speed;       // 英雄1速度

    QPushButton *select_hero2; // 英雄2
    QLabel *hero2_hp;          // 英雄2血量
    QLabel *hero2_atk;         // 英雄2攻击力
    QLabel *hero2_speed;       // 英雄2速度
    QMediaPlayer *bgm_select;
    QPushButton *select_map; // 选择地图
};
#endif // SELECTHEROES_H