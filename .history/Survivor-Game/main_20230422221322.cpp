#include "mainwindow.h"

#include <QApplication>
#include <QByteArray>
#include <QFile>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QLocale>
#include <QTranslator>

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
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages)
    {
        const QString baseName = "Survivor-Game_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName))
        {
            a.installTranslator(&translator);
            break;
        }
    }
    MainWindow w;
    w.show();
    return a.exec();
}
