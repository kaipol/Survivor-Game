#include "MainInterface.h"

MainInterface::MainInterface(QWidget *parent) : QWidget(parent)
{
    startButton = new QPushButton("开始游戏", this);                              // 开始按钮初始化
    exitButton = new QPushButton("退出游戏", this);                               // 退出按钮初始化
    loadbutton = new QPushButton("加载存档", this);                               // 加载存档按钮初始化
    startButton->setGeometry(430, 450, 150, 80);                                  // 设置开始按钮位置
    loadbutton->setGeometry(430, 550, 150, 80);                                   // 设置加载存档按钮位置
    exitButton->setGeometry(430, 650, 150, 80);                                   // 设置退出按钮位置
    connect(startButton, &QPushButton::clicked, this, &MainInterface::startGame); // 开始按钮连接
    // connect(loadbutton, &QPushButton::clicked, this, &MainInterface::load_date);  // 加载存档按钮连接
    connect(exitButton, &QPushButton::clicked, this, &qApp->quit); // 退出按钮连接
}

void MainInterface::paintEvent(QPaintEvent *event)
{
    QPainter pen(this);
    pen.drawPixmap(0, 0, 1000, 850, QPixmap("../src/main_back_ground.png")); // 绘制背景
}

void MainInterface::startGame()
{
    this->hide();
    emit changeWidgetsignal(1);
}
