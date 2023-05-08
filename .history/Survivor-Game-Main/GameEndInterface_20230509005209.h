#ifndef OTHERINTERFACE_H
#define OTHERINTERFACE_H
#endif // OTHERINTERFACE_H
#pragma once

#include <QApplication>
#include <QPushButton>
#include <QPainter>
#include <QLabel>

class GameEndInterface : public QWidget
{
    Q_OBJECT
private:
    int type;                      // 0胜利 1失败
    QLabel *game_over_label;       // 游戏结束标签
    QPushButton *again_button;     // 再来一局按钮
    QPushButton *game_over_button; // 退出游戏按钮

public slots:
    void get_end_type(int type); // 获取游戏结束类型
    void play_again();           // 再来一局

signals:
    void changeWidgetsignal(int Index); // 切换窗口信号

public:
    GameEndInterface(QWidget *parent = nullptr);
    // void paintEvent(QPaintEvent *event);
};