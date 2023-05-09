#include "GameEndInterface.h"

GameEndInterface::GameEndInterface(QWidget *parent) : QWidget(parent)
{
    game_over_label = new QLabel(this);                   // 游戏结束标签
    again_button = new QPushButton("再来一局", this);     // 再来一局按钮
    game_over_button = new QPushButton("退出游戏", this); // 退出游戏按钮
    again_button->setGeometry(400, 350, 150, 100);
    game_over_button->setGeometry(400, 450, 150, 100);
    connect(again_button, &QPushButton::clicked, this, &GameEndInterface::play_again);
    connect(game_over_button, &QPushButton::clicked, this, &qApp->quit);
}

void GameEndInterface::get_end_type(int type)
{
    this->type = type;
    if (type == 0)
    {
        game_over_label->setText("游戏胜利");
    }
    else
    {
        game_over_label->setText("游戏失败");
    }
    game_over_label->setGeometry(400, 100, 500, 100);
    game_over_label->setStyleSheet("font: bold 65px");
    again_button->show();
    game_over_button->show();
    update();
}

void GameEndInterface::play_again()
{
    this->hide();
    emit changeWidgetsignal(0);
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