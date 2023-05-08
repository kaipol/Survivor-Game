#ifndef SELECTHEROES_H
#define SELECTHEROES_H
#endif // SELECTHEROES_H
#pragma once
#include <Qpushbutton>
#include <Qmediaplayer>
#include <QPainter>
#include <QLabel>

class SelectHeroesInterface : public QWidget
{
    Q_OBJECT
public slots:
    void back_to_main();
    // void hero1_to_fight();
    // void hero2_to_fight();

signals:
    void changeWidgetsignal(int Index); // 切换窗口信号
    void changeHero1signal();           // 切换英雄1信号
    void changeHero2signal(int Index);  // 切换英雄2信号

public:
    SelectHeroesInterface(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);

private:
    QPushButton *backbutton;   // 返回按钮
    QPushButton *select_hero1; // 英雄1
    QLabel *hero1_name;        // 英雄1名字
    QLabel *hero1_hp;          // 英雄1血量
    QLabel *hero1_atk;         // 英雄1攻击力
    QLabel *hero1_def;         // 英雄1防御力

    QPushButton *select_hero2; // 英雄2
    QLabel *hero2_name;        // 英雄2名字
    QLabel *hero2_hp;          // 英雄2血量
    QLabel *hero2_atk;         // 英雄2攻击力
    QLabel *hero2_def;         // 英雄2防御力
    QMediaPlayer *bgm_select;
};