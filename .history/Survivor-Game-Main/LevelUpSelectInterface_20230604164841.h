
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
    bool label1_flag;          // 标签:血量+3是否显示
    QLabel *label2;            // 标签:攻击+1
    bool label2_flag;          // 标签:攻击+1是否显示
    QLabel *label3;            // 标签:速度+5
    bool label3_flag;          // 标签:速度+5是否显示
    QLabel *label4;            // 标签:击杀怪物获取金币数+1
    bool label4_flag;          // 标签:击杀怪物获取金币数+1是否显示
    QLabel *label5;            // 标签:击杀怪物获取经验数+1
    bool label5_flag;          // 标签:击杀怪物获取经验数+1是否显示
    QLabel *label6;            // 标签:子弹生成速度加快
    bool label6_flag;          // 标签:子弹生成速度加快是否显示
    int loc[3];                // 道具位置

public slots:
    void back_to_fight();

signals:
    void change_type(int);
    void changeWidgetsignal(int);
};
#endif // LevelUpSelectInterface_H