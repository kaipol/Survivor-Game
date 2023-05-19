#include "LoadInterface.h"

LoadInterface::LoadInterface(QWidget *parent) : QWidget(parent)
{
    save_button = new QPushButton("保存存档1", this);  // 保存存档按钮初始化
    save_button2 = new QPushButton("保存存档2", this); // 保存存档按钮初始化
    save_button3 = new QPushButton("保存存档3", this); // 保存存档按钮初始化
    load_button = new QPushButton("加载存档1", this);  // 加载存档按钮初始化
    load_button2 = new QPushButton("加载存档2", this); // 加载存档按钮初始化
    load_button3 = new QPushButton("加载存档3", this); // 加载存档按钮初始化
    back_button = new QPushButton("返回主窗口", this); // 返回按钮初始化
    connect(save_button, &QPushButton::clicked, this, [=]()
            { save_data(0); });
    connect(save_button2, &QPushButton::clicked, this, [=]()
            { save_data(1); });
    connect(save_button3, &QPushButton::clicked, this, [=]()
            { save_data(2); });
    connect(load_button, &QPushButton::clicked, this, [=]()
            { load_data(0); });
    connect(load_button2, &QPushButton::clicked, this, [=]()
            { load_data(1); });
    connect(load_button3, &QPushButton::clicked, this, [=]()
            { load_data(2); });
    connect(back_button, &QPushButton::clicked, this, [=]()
            { emit changeWidgetsignal(0); });
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

    switch (choice)
    {
    case 0:
        break;
    case 1:
        break;
    case 2:
        break;
    default:
        break;
    }
    QFile file("../src/data/data1.json");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
    }
    QJsonObject root;
    root.insert("关卡数", QJsonValue(1)); // TODO:其他特性
    root.insert("血量", QJsonValue(1));
    root.insert("攻击力", QJsonValue(1));
    root.insert("速度", QJsonValue(0));
    file.write(QJsonDocument(root).toJson());
    file.close();
}
void LoadInterface::load_data(int choice)
{
    switch (choice)
    {
    case 0:
        break;
    case 1:
        break;
    case 2:
        break;
    default:
        break;
    }
    QFile file("../src/data/data1.json");
    file.open(QIODevice::ReadOnly);
    QByteArray data = file.readAll();
    file.close();

    QJsonParseError json_error;
}