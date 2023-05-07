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
    void keyPressEvent(QKeyEvent *event); // 键盘事件

    void paintEvent(QPaintEvent *event);     // 绘制主窗口事件
    void paintGameEvent(QPaintEvent *event); // 绘制游戏地图事件

    void initMap(); // 初始化游戏地图函数
    // void updateMap(int type, int preValue = 0); // 刷新游戏地图函数
    QStackedWidget *stackedWidget; // 设置堆栈窗口

public slots:
    void startGame(); // 开始游戏函数
    // void save_date();
    // void load_date();
    void back_to_main();

private:
    Ui::MainWindow *ui;
    QPushButton *startButton;        // 开始按钮
    QPushButton *exitButton;         // 退出按钮
    QPushButton *savebutton;         // 保存按钮
    QPushButton *loadbutton;         // 加载存档按钮
    QPushButton *back_to_mainbutton; // 返回主界面按钮

    QWidget *select_heroes_interface;

    int game_process = 0;           // 游戏进程
    QTimer *timer;                  // 定时器
    QVector<QVector<int>> game_map; // 游戏地图
    QMediaPlayer *bgm_main;         // 播放背景音乐
};
#endif // MAINWINDOW_H
