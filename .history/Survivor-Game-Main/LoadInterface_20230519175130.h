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
#include <QTimer>
#include "Characters.h"

class LoadInterface : public QWidget
{
    Q_OBJECT
private:
    QLabel *load_info_label;  // 加载存档信息标签
    QLabel *load_info_label2; // 加载存档信息标签
    QLabel *load_info_label3; // 加载存档信息标签
    QLabel *fail_open_data;   // 打开失败标签
    QTimer *timer;
    QPushButton *save_button;  // 保存存档按钮
    QPushButton *save_button2; // 保存存档按钮
    QPushButton *save_button3; // 保存存档按钮
    QPushButton *load_button;  // 加载存档按钮
    QPushButton *load_button2; // 加载存档按钮
    QPushButton *load_button3; // 加载存档按钮
    Heroes *hero_mir;          // 英雄镜像

public:
    LoadInterface(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event); // 绘制事件
    void save_data(int choice);
    void load_data(int choice);

public slots:
    void get_save_date(Heroes *); // 获取存档信息

signals:
    void is_selected();                // 开始游戏信号
    void data_select_signal(Heroes *); // 读取存档信号
};
#endif // LOADINTERFACE_H