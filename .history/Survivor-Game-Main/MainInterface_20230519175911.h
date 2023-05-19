#ifndef MAININTERFACE_H
#define MAININTERFACE_H
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
    QPushButton *startButton;       // 开始按钮
    QPushButton *exitButton;        // 退出按钮
    QPushButton *load_button;       // 加载存档按钮
    QPushButton *continue_button;   // 继续游戏按钮
    QPushButton *enter_shop_button; // 进入商店按钮
    QLabel *game_name_label;        // 游戏名字标签

signals:
    void changeWidgetsignal(int Index); // 切换窗口信号
    // void load_date_signal();            // 加载存档信号

public:
    MainInterface(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event); // 绘制事件
    void startGame();                    // 开始游戏
    void enter_shop();                   // 进入商店
    void load_data();                    // 加载存档

public slots:
    void is_started(); // 加载存档
};
#endif // MAININTERFACE_H