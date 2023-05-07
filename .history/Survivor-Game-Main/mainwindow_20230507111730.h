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
    void startGame();
    void keyPressEvent(QKeyEvent *event); // 键盘事件
    void paintEvent(QPaintEvent *event);
    void initMap();                             // 初始化游戏地图函数
    void updateMap(int type, int preValue = 0); // 刷新游戏地图函数

private:
    Ui::MainWindow *ui;
    QPushButton *startButton; // 开始按钮
    QPushButton *exitButton;  // 退出按钮
    QPushButton *savebutton;  // 保存按钮
    QPushButton *loadbutton;  // 加载存档按钮
    int HeroesLoc[1][1];      // 角色位置
    QLabel *nameLabel;        // 角色名字

    QMediaPlayer *bgm_main; // 播放背景音乐
};
#endif // MAINWINDOW_H
