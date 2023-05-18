
#ifndef LevelUpSelectInterface_H
#define LevelUpSelectInterface_H
#pragma once

#include <QApplication>
#include <QPushButton>
#include <QLabel>
#include <QPainter>

class LevelUpSelectInterface : public QWidget
{
    Q_OBJECT
public:
    LevelUpSelectInterface(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event); // 绘制事件
    void prop_generate();                // 道具生成

private:
    QPushButton *select_one;   // 选择第一项
    QPushButton *select_two;   // 选择第二项
    QPushButton *select_three; // 选择第三项
    QLabel *label1;            // 标签:血量+3
    QLabel *label2;            // 标签:攻击+1
    QLabel *label3;            // 标签:速度+5
    QLabel *label4;            // 标签:击杀怪物获取金币数+1
    int loc[4];

public slots:
    void back_to_fight();

signals:
    void change_type(int);
    void changeWidgetsignal(int);
};
#endif // LevelUpSelectInterface_H