#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QLabel>
#include <QMediaPlayer>
#include <QPainter>
#include <QKeyEvent>
#include <QImage>
#include <QPushButton>
#include <QPair>
#include <Qtimer>

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    friend class SelectHeroesInterface;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void paintEvent(QPaintEvent *event);     // �����������¼�
    void paintGameEvent(QPaintEvent *event); // ������Ϸ��ͼ�¼�

private:
    Ui::MainWindow *ui;

    QWidget *main_interface; // ������

    QVector<QVector<int>> game_map = {
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
    };                      // ��Ϸ��ͼ
    QMediaPlayer *bgm_main; // ���ű�������
};
#endif // MAINWINDOW_H