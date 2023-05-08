#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QStackedWidget>

#include "MainInterface.h"
#include "SelectHeroes.h"
#include "FightInterface.h"

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
    void paintGameEvent(QPaintEvent *event); // 绘制游戏地图事件
    QStackedWidget *stackedLayout;

public slots:
    void changeWidget(int Index); // 切换窗口槽函数

private:
    Ui::MainWindow *ui;

    MainInterface *main_interface;                  // 主界面
    SelectHeroesInterface *select_heroes_interface; // 选择英雄界面
    FightInterface *fight_interface;                // 战斗界面
};
#endif // MAINWINDOW_H
