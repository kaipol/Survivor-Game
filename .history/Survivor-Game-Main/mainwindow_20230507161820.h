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

QT_BEGIN_NAMESPACE
namespace Ui
{
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void keyPressEvent(QKeyEvent *event);    // �����¼�
    void paintEvent(QPaintEvent *event);     // �����������¼�
    void paintGameEvent(QPaintEvent *event); // ������Ϸ��ͼ�¼�
    void initMap();                          // ��ʼ����Ϸ��ͼ����
    // void updateMap(int type, int preValue = 0); // ˢ����Ϸ��ͼ����

public slots:
    void startGame();
    // void save_date();
    // void load_date();
    void back_to_main();

private:
    Ui::MainWindow *ui;
    QPushButton *startButton;       // ��ʼ��ť
    QPushButton *exitButton;        // �˳���ť
    QPushButton *savebutton;        // ���水ť
    QPushButton *loadbutton;        // ���ش浵��ť
    QPushButton *backbutton;        // ���ذ�ť
    bool is_start = false;          // ��Ϸ�Ƿ�ʼ
    QVector<QVector<int>> game_map; // ��Ϸ��ͼ
    QMediaPlayer *bgm_main;         // ���ű�������
};
#endif // MAINWINDOW_H
