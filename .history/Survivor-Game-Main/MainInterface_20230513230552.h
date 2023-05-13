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

class MainInterface : public QWidget
{
    Q_OBJECT
private:
    QWidget *select_heroes_interface; // 选择英雄界面
    QPushButton *startButton;         // 开始按钮
    QPushButton *exitButton;          // 退出按钮
    QPushButton *loadbutton;          // 加载存档按钮
    QPushButton *continuebutton;      // 继续游戏按钮
    QLabel *game_name_label;          // 游戏名字标签

signals:
    void changeWidgetsignal(int Index); // 切换窗口信号
public:
    MainInterface(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    void startGame();
    // void save_date();
    // void load_date();
};