#include "ShopInterface.h"

ShopInterface::ShopInterface(QWidget *parent) : QWidget(parent)
{
}

void ShopInterface::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load("../src/shop.jpg");
    painter.drawPixmap(0, 0, 1000, 800, pix);
}