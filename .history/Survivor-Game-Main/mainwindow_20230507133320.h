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
    void keyPressEvent(QKeyEvent *event);          // 键盘事件
    void paintEvent(QPaintEvent *event, int type); // 绘制游戏地图事件
    void initOther();                              // 初始化游戏地图函数
    // void updateMap(int type, int preValue = 0); // 刷新游戏地图函数

public slots:
    void startGame();
    // void save_date();
    // void load_date();
private:
    Ui::MainWindow *ui;
    QPushButton *startButton;             // 开始按钮
    QPushButton *exitButton;              // 退出按钮
    QPushButton *savebutton;              // 保存按钮
    QPushButton *loadbutton;              // 加载存档按钮
    QVector<QVector<int>> game_map;       // 游戏地图
    int HeroesLoc[2] = {0};               // 角色位置
    int MonstersNum;                      // 怪物数量
    QVector<QPair<int, int>> MonstersLoc; // 怪物位置

    QMediaPlayer *bgm_main; // 播放背景音乐
};
#endif // MAINWINDOW_H
