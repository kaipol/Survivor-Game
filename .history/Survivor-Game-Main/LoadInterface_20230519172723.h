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
#include "Characters.h"

class LoadInterface : public QWidget
{
    Q_OBJECT
private:
    QLabel *load_info_label;   // 加载存档信息标签
    QLabel *load_info_label2;  // 加载存档信息标签
    QLabel *load_info_label3;  // 加载存档信息标签
    QPushButton *save_button;  // 保存存档按钮
    QPushButton *save_button2; // 保存存档按钮
    QPushButton *save_button3; // 保存存档按钮
    QPushButton *load_button;  // 加载存档按钮
    QPushButton *load_button2; // 加载存档按钮
    QPushButton *load_button3; // 加载存档按钮
    Heroes *hero_mir;          // 加载英雄镜像

public:
    LoadInterface(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event); // 绘制事件

public slots:
    void get_save_date(Heroes *);

signals:
    void data_select_signal(Heroes *);
};
#endif // LOADINTERFACE_H