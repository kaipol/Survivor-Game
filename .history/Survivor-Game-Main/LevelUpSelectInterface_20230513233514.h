
#ifndef LevelUpSelectInterface_H
#define LevelUpSelectInterface_H
#endif // LevelUpSelectInterface_H
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
};