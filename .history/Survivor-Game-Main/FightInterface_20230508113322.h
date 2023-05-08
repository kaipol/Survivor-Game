#ifndef FightInterface_H
#define FightInterface_H
#endif // FightInterface_H
#pragma once

#include <QVector>
#include <QPushButton>
#include <QPainter>
#include <QKeyEvent>
#include <QTimer>
#include "Characters.h"

class FightInterface : public QWidget
{
    Q_OBJECT
public:
    FightInterface(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    // void keyPressEvent(QKeyEvent *event);

public slots:
    void back_to_main();
    void Heroes_and_Monsters_init(QString name);

signals:
    void changeWidgetsignal(int Index); // 切换窗口信号

private:
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
};