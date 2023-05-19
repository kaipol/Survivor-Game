#include "LoadInterface.h"

LoadInterface::LoadInterface(QWidget *parent) : QWidget(parent)
{
    save_button = new QPushButton("保存存档1", this);  // 保存存档按钮初始化
    save_button->setGeometry(430, 350, 150, 80);       // 设置保存存档按钮位置
    save_button2 = new QPushButton("保存存档2", this); // 保存存档按钮初始化
    save_button2->setGeometry(530, 350, 150, 80);      // 设置保存存档按钮位置
    save_button3 = new QPushButton("保存存档3", this); // 保存存档按钮初始化
    save_button3->setGeometry(630, 350, 150, 80);      // 设置保存存档按钮位置
    load_button = new QPushButton("加载存档1", this);  // 加载存档按钮初始化
    load_button->setGeometry(430, 550, 150, 80);       // 设置加载存档按钮位置
    load_button2 = new QPushButton("加载存档2", this); // 加载存档按钮初始化
    load_button2->setGeometry(530, 550, 150, 80);      // 设置加载存档按钮位置
    load_button3 = new QPushButton("加载存档3", this); // 加载存档按钮初始化
    load_button3->setGeometry(630, 550, 150, 80);      // 设置加载存档按钮位置
    back_button = new QPushButton("返回主窗口", this); // 返回按钮初始化
    back_button->setGeometry(900, 0, 100, 50);         // 设置按钮位置和大小

    connect(save_button, &QPushButton::clicked, this, [=]()
            { save_data(0); }); // 保存存档按钮连接
    connect(save_button2, &QPushButton::clicked, this, [=]()
            { save_data(1); }); // 保存存档按钮连接
    connect(save_button3, &QPushButton::clicked, this, [=]()
            { save_data(2); }); // 保存存档按钮连接
    connect(load_button, &QPushButton::clicked, this, [=]()
            { load_data(0); }); // 加载存档按钮连接
    connect(load_button2, &QPushButton::clicked, this, [=]()
            { load_data(1); }); // 加载存档按钮连接
    connect(load_button3, &QPushButton::clicked, this, [=]()
            { load_data(2); }); // 加载存档按钮连接
    connect(back_button, &QPushButton::clicked, this, [=]()
            { emit changeWidgetsignal(0); }); // 返回按钮连接
}

void LoadInterface::paintEvent(QPaintEvent *event)
{
    QPainter pen(this);
    pen.drawPixmap(0, 0, 1000, 850, QPixmap("../src/Sprite/Load_background.png")); // 绘制背景
}
void LoadInterface::get_save_date(Heroes *hero)
{
    hero_mir = hero;
}

void LoadInterface::save_data(int choice)
{
    QFile file;
    switch (choice)
    {
    case 0:
        file.setFileName("../src/data/data1.json");
        break;
    case 1:
        file.setFileName("../src/data/data2.json");
        break;
    case 2:
        file.setFileName("../src/data/data3.json");
        break;
    default:
        break;
    }
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
    }
    QJsonObject root; // TODO:其他特性
    root.insert("当前血量", QJsonValue(hero_mir->get_hero_blood()));
    root.insert("最大血量", QJsonValue(hero_mir->get_hero_blood_max()));
    root.insert("当前速度", QJsonValue(hero_mir->get_hero_speed()));
    root.insert("当前金币数", QJsonValue(hero_mir->get_hero_coin()));
    root.insert("当前等级", QJsonValue(hero_mir->get_hero_level()));
    file.write(QJsonDocument(root).toJson());
    file.close();
}
void LoadInterface::load_data(int choice)
{
    QFile file;
    switch (choice)
    {
    case 0:
        file.setFileName("../src/data/data1.json");
        break;
    case 1:
        file.setFileName("../src/data/data2.json");
        break;
    case 2:
        file.setFileName("../src/data/data3.json");
        break;
    default:
        break;
    }
    file.open(QIODevice::ReadOnly);
    QByteArray data = file.readAll();
    file.close();

    QJsonParseError json_error;
}