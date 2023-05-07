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
    void keyPressEvent(QKeyEvent *event); // �����¼�

    void paintEvent(QPaintEvent *event);     // �����������¼�
    void paintGameEvent(QPaintEvent *event); // ������Ϸ��ͼ�¼�

    void initMap(); // ��ʼ����Ϸ��ͼ����
    // void updateMap(int type, int preValue = 0); // ˢ����Ϸ��ͼ����

public slots:
    void startGame(); // ��ʼ��Ϸ����
    // void save_date();
    // void load_date();
    // void back_to_main();

private:
    Ui::MainWindow *ui;

    QWidget *main_interface; // ������
    QWidget *select_heroes_interface;

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
