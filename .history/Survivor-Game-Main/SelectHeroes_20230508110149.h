#ifndef SELECTHEROES_H
#define SELECTHEROES_H
#endif // SELECTHEROES_H
#pragma once
#include <Qpushbutton>
#include <Qmediaplayer>
#include <QPainter>

class SelectHeroesInterface : public QWidget
{
    Q_OBJECT
public slots:
    void back_to_main();
    // void hero1_to_fight();
    // void hero2_to_fight();

signals:
    void changeWidgetsignal(int Index); // 切换窗口信号

public:
    SelectHeroesInterface(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);

private:
    QPushButton *backbutton; // 返回按钮
    QPushButton *hero1;      // 英雄1
    QPushButton *hero2;      // 英雄2
    QMediaPlayer *bgm_select;
};