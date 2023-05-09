#include "GameEndInterface.h"

GameEndInterface::GameEndInterface(QWidget *parent) : QWidget(parent)
{
    game_over_label = new QLabel(this);                   // 游戏结束标签
    again_button = new QPushButton("再来一局", this);     // 再来一局按钮
    game_over_button = new QPushButton("退出游戏", this); // 退出游戏按钮
    again_button->setGeometry(200, 200, 100, 50);
    game_over_button->setGeometry(200, 300, 100, 50);
    connect(again_button, &QPushButton::clicked, this, &GameEndInterface::play_again);
    connect(game_over_button, &QPushButton::clicked, this, &qApp->quit);
}

void GameEndInterface::get_end_type(int type)
{
    this->type = type;
    if (type == 0)
    {
        game_over_label->setText("胜利");
    }
    else
    {
        game_over_label->setText("失败");
    }
}

void GameEndInterface::play_again()
{
    this->hide();
    emit changeWidgetsignal(0);
}