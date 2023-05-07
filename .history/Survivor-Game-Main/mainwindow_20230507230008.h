#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QStackedWidget>

#include "MainInterface.h"
#include "SelectHeroes.h"

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void paintGameEvent(QPaintEvent *event); // ������Ϸ��ͼ�¼�
    QStackedWidget *stackedLayout;

public slots:
    void changeWidget(int Index); // �л����ڲۺ���

private:
    Ui::MainWindow *ui;

    MainInterface *main_interface;                  // ������
    SelectHeroesInterface *select_heroes_interface; // ѡ��Ӣ�۽���
};
#endif // MAINWINDOW_H
