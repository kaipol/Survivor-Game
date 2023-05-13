#include "LoadInterface.h"

using namespace std;
void save_date()
{
    QFile file("./date/date.json");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << ("打开存档失败!");
    }
    QJsonObject root;
    root.insert("关卡数", QJsonValue(1)); // TODO:其他特性
    root.insert("血量", QJsonValue(1));
    root.insert("攻击力", QJsonValue(1));
    file.write(QJsonDocument(root).toJson());
    file.close();
}
void read_date()
{
    QFile file("./date/date.json");
    file.open(QIODevice::ReadOnly);
    QByteArray data = file.readAll();
    file.close();

    QJsonParseError json_error;
}