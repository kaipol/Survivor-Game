#ifndef LOADINTERFACE_H
#define LOADINTERFACE_H
#pragma once

#include <QWidget>
#include <QByteArray>
#include <QFile>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QLabel>
#include <QPushButton>
#include <QPainter>

class LoadInterface : public QWidget
{
    Q_OBJECT
private:
    QLabel *load_label;  // 加载存档标签
    QLabel *load_label2; // 加载存档标签
    QLabel *load_label3; // 加载存档标签
    QPushButton *save_button;
    QPushButton *save_button2;
    QPushButton *load_button;  // 加载存档按钮
    QPushButton *load_button2; // 加载存档按钮
    QPushButton *load_button3; // 加载存档按钮
public:
    LoadInterface(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event); // 绘制事件
};
#endif // LOADINTERFACE_H