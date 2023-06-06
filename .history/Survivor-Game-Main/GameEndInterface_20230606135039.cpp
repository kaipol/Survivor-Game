#include "GameEndInterface.h"

GameEndInterface::GameEndInterface(QWidget *parent) : QWidget(parent)
{
    game_over_label = new QLabel(this);                   // 游戏结束标签
    again_button = new QPushButton("再来一局", this);     // 再来一局按钮
    restart_button = new QPushButton("重新开始", this);   // 重新开始按钮
    game_over_button = new QPushButton("退出游戏", this); // 退出游戏按钮
    again_button->hide();
    restart_button->hide();
    again_button->setGeometry(430, 400, 150, 100);
    restart_button->setGeometry(430, 500, 150, 100);
    game_over_button->setGeometry(430, 600, 150, 100);
    connect(again_button, &QPushButton::clicked, this, &GameEndInterface::play_again);
    connect(restart_button, &QPushButton::clicked, this, &GameEndInterface::restart_game);
    connect(game_over_button, &QPushButton::clicked, this, &qApp->quit);
}

void GameEndInterface::get_end_type(int type1)
{
    this->type = type1;
    restart_button->show();
    if (type == 0)
    {
        game_over_label->setText("游戏胜利");
        game_over_label->setStyleSheet("font: bold 65px");
        again_button->show();
    }
    else
    {
        again_button->hide();
        game_over_label->setText("游戏失败");
        game_over_label->setStyleSheet("color: red;font: bold 65px");
    }
    game_over_label->setGeometry(350, 100, 500, 100);

    update();
}

void GameEndInterface::play_again()
{
    this->hide();
    emit changeWidgetsignal(0);
    emit play_again_signal();
}

void GameEndInterface::restart_game()
{
    this->hide();
    emit changeWidgetsignal(0);
    emit restart_game_signal();
}

void GameEndInterface::paintEvent(QPaintEvent *event)
{
    if (type == 0) // 胜利
    {
        QPainter pen(this);
        pen.drawPixmap(0, 0, 1000, 800, QPixmap("../src/Sprite/game_win.png"));
    }
    else // 失败
    {
        QPainter pen(this);
        pen.drawPixmap(0, 0, 1000, 800, QPixmap("../src/Sprite/game_end.png"));
    }
}