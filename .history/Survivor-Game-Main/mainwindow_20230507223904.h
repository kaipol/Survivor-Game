#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QLabel>
#include <QMediaPlayer>
#include <QPainter>
#include <QKeyEvent>
#include <QPushButton>
#include <QPair>
#include <QStackedWidget>

#include "SelectHeroes.h"
#include "MainInterface.h"

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

    QWidget *main_interface;          // ������
    QWidget *select_heroes_interface; // ѡ��Ӣ�۽���

    QVector<QVector<int>>
        game_map = {
            {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
            {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
            {0, 0, 1, 0, 0, 0, 0, 1, 0, 0},
            {0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
            {0, 0, 0, 0, 0, 1, 0, 0, 1, 0},
            {0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 1, 0, 0, 1, 0},
            {0, 0, 0, 1, 0, 0, 0, 0, 1, 0},
        };                  // ��Ϸ��ͼ
    QMediaPlayer *bgm_main; // ���ű�������
};
#endif // MAINWINDOW_H
