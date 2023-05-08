#ifndef OTHERINTERFACE_H
#define OTHERINTERFACE_H
#endif // OTHERINTERFACE_H
#pragma once

#include <QPushButton>
#include <QPainter>
#include <QLabel>

class GameEndInterface : public QWidget
{
    Q_OBJECT
private:
    int type;                      // 0胜利 1失败
    QLabel *game_over_label;       // 游戏结束标签
    QPushButton *game_over_button; // 退出游戏按钮
    QPushButton *again_button;     // 再来一局按钮
public:
    // GameEndInterface(int type, QWidget *parent = nullptr);
    // void paintEvent(QPaintEvent *event);
};