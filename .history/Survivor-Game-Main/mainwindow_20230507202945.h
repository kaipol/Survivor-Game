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
    void keyPressEvent(QKeyEvent *event); // 键盘事件

    void paintEvent(QPaintEvent *event);     // 绘制主窗口事件
    void paintGameEvent(QPaintEvent *event); // 绘制游戏地图事件

    void initMap(); // 初始化游戏地图函数
    // void updateMap(int type, int preValue = 0); // 刷新游戏地图函数

public slots:
    void startGame(); // 开始游戏函数
    // void save_date();
    // void load_date();
    // void back_to_main();

private:
    Ui::MainWindow *ui;

    QWidget *main_interface; // 主界面
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
    };                      // 游戏地图
    QMediaPlayer *bgm_main; // 播放背景音乐
};
#endif // MAINWINDOW_H
