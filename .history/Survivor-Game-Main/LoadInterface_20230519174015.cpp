#include "LoadInterface.h"

LoadInterface::LoadInterface(QWidget *parent) : QWidget(parent)
{
    hero_mir = new Heroes;
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