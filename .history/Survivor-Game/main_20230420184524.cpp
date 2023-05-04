#include "mainwindow.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>

void read_date()
{
    FILE *fp;
    fp = freopen("./date/date.txt", "r", stdin);
    if (!fp)
    {
    }
    else
    {
        qDebug() << "Error: Can't open file \"./date/date.txt\".";
        exit(-1);
    }
    fclose(fp);
}
void save_date()
{
    FILE *fp;
    fp = freopen("./date/date.txt", "w", stdout);
    if (!fp)
    {
    }
    else
    {
        qDebug() << "Error: Can't open file \"./date/date.txt\".";
        exit(-1);
    }
    fclose(fp);
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
