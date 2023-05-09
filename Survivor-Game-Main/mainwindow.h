#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QStackedWidget>

#include "MainInterface.h"
#include "SelectHeroes.h"
#include "FightInterface.h"
#include "GameEndInterface.h"

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
    QStackedWidget *stackedLayout;

public slots:
    void changeWidget(int Index); // 切换窗口槽函数
    void play_again();            // 再来一局槽函数
    // void save_date();       // 保存游戏槽函数
    // void load_date();       // 加载游戏槽函数

private:
    Ui::MainWindow *ui;

    MainInterface *main_interface;                  // 主界面
    SelectHeroesInterface *select_heroes_interface; // 选择英雄界面
    FightInterface *fight_interface;                // 战斗界面
    GameEndInterface *game_end_interface;           // 游戏结束界面
};
#endif // MAINWINDOW_H
