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
#include <QStackedWidget>

#include "SelectHeroes.h"

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
    void keyPressEvent(QKeyEvent *event); // �����¼�

    void paintEvent(QPaintEvent *event);     // �����������¼�
    void paintGameEvent(QPaintEvent *event); // ������Ϸ��ͼ�¼�

    void initMap(); // ��ʼ����Ϸ��ͼ����
    // void updateMap(int type, int preValue = 0); // ˢ����Ϸ��ͼ����
    QStackedWidget *stackedWidget; // ���ö�ջ����

public slots:
    void startGame(); // ��ʼ��Ϸ����
    // void save_date();
    // void load_date();
    // void back_to_main();

private:
    Ui::MainWindow *ui;
    QPushButton *startButton;        // ��ʼ��ť
    QPushButton *exitButton;         // �˳���ť
    QPushButton *savebutton;         // ���水ť
    QPushButton *loadbutton;         // ���ش浵��ť
    QPushButton *back_to_mainbutton; // ���������水ť

    SelectHeroesInterface *select_heroes_interface;

    int game_process = 0;           // ��Ϸ����
    QTimer *timer;                  // ��ʱ��
    QVector<QVector<int>> game_map; // ��Ϸ��ͼ
    QMediaPlayer *bgm_main;         // ���ű�������
};
#endif // MAINWINDOW_H
