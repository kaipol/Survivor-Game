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
    QLabel *load_info_label_name;    // 加载存档信息标签
    QLabel *load_info_label_hp;      // 加载存档信息标签
    QLabel *load_info_label_atk;     // 加载存档信息标签
    QLabel *load_info_label_spd;     // 加载存档信息标签
    QLabel *load_info_label_coin;    // 加载存档信息标签
    QLabel *load_info_label_level;   // 加载存档信息标签
    QLabel *load_info_label_revival; // 加载存档信息标签
    bool is_null = true;             // 是否为空存档

    QLabel *load_info_label_name2;    // 加载存档信息标签
    QLabel *load_info_label_hp2;      // 加载存档信息标签
    QLabel *load_info_label_atk2;     // 加载存档信息标签
    QLabel *load_info_label_spd2;     // 加载存档信息标签
    QLabel *load_info_label_coin2;    // 加载存档信息标签
    QLabel *load_info_label_level2;   // 加载存档信息标签
    QLabel *load_info_label_revival2; // 加载存档信息标签
    bool is_null2 = true;             // 是否为空存档

    QLabel *load_info_label_name3;    // 加载存档信息标签
    QLabel *load_info_label_hp3;      // 加载存档信息标签
    QLabel *load_info_label_atk3;     // 加载存档信息标签
    QLabel *load_info_label_spd3;     // 加载存档信息标签
    QLabel *load_info_label_coin3;    // 加载存档信息标签
    QLabel *load_info_label_level3;   // 加载存档信息标签
    QLabel *load_info_label_revival3; // 加载存档信息标签
    bool is_null3 = true;             // 是否为空存档

    QPushButton *save_button;  // 保存存档按钮
    QPushButton *save_button2; // 保存存档按钮
    QPushButton *save_button3; // 保存存档按钮
    QPushButton *load_button;  // 加载存档按钮
    QPushButton *load_button2; // 加载存档按钮
    QPushButton *load_button3; // 加载存档按钮
    QPushButton *back_button;  // 返回按钮
    Heroes *hero_mir;          // 英雄镜像
    Heroes *hero_mir2;         // 英雄镜像
    Heroes *hero_mir3;         // 英雄镜像

public:
    LoadInterface(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event); // 绘制事件
    void save_data(int choice);          // 保存存档
    void load_data(int choice);          // 加载存档
    void load_hero_info();               // 加载英雄信息
    void update_info();                  // 更新信息

public slots:
    void get_save_date(Heroes); // 获取存档信息
    void is_main();             // 是否为主界面
    void is_fight();

signals:
    void is_selected();                 // 已经读取存档信号
    void data_select_signal(Heroes);    // 读取存档信号
    void changeWidgetsignal(int Index); // 切换窗口信号
};
#endif // LOADINTERFACE_H