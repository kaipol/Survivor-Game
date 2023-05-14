#include "LevelUpSelectInterface.h"

LevelUpSelectInterface::LevelUpSelectInterface(QWidget *parent) : QWidget(parent)
{
}

void LevelUpSelectInterface::paintEvent(QPaintEvent *event)
{
    QPainter pen(this);
    pen.drawPixmap(0, 0, 1000, 800, QPixmap("../src/Sprite/LevelUp.png"));
}