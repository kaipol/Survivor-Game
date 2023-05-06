#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QLabel>
#include <QMediaPlayer>

QT_BEGIN_NAMESPACE
namespace Ui
{
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public slots:
    void startGame();

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void keyPressEvent(QKeyEvent *event); // 键盘事件
    void paintEvent(QPaintEvent *event);
    void initMap();                             // 初始化游戏地图函数
    void updateMap(int type, int preValue = 0); // 刷新游戏地图函数

private:
    Ui::MainWindow *ui;
    // 记录是否重新开始
    bool isStart = true;
    QMediaPlayer *bgm;       // 播放背景音乐
    QMediaPlaylist *bgmlist; // 背景音乐列表，用于循环播放
    QLabel *nameLabel;       // 角色名字
};
#endif // MAINWINDOW_H
