#ifndef MAININTERFACE_H
#define MAININTERFACE_H
#endif // MAININTERFACE_H
#pragma once
#include <QVector>
#include <QApplication>
#include <QMediaPlayer>
#include <QPainter>
#include <QLabel>
#include <QPushButton>
#include "ShopInterface.h"

class MainInterface : public QWidget
{
    Q_OBJECT
private:
    bool is_load = false;           // 是否加载存档
    QPushButton *startButton;       // 开始按钮
    QPushButton *exitButton;        // 退出按钮
    QPushButton *load_button;       // 加载存档按钮
    QPushButton *continue_button;   // 继续游戏按钮
    QPushButton *enter_shop_button; // 进入商店按钮
    QLabel *game_name_label;        // 游戏名字标签

signals:
    void changeWidgetsignal(int Index); // 切换窗口信号

public:
    MainInterface(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    void startGame();
    // void load_date();
};