#include "MainInterface.h"
#include "SelectHeroes.h"

MainInterface::MainInterface(QWidget *parent)
{
    startButton = new QPushButton("开始游戏", this);                              // 开始按钮初始化
    exitButton = new QPushButton("退出游戏", this);                               // 退出按钮初始化
    savebutton = new QPushButton("保存游戏", this);                               // 保存按钮初始化
    loadbutton = new QPushButton("加载存档", this);                               // 加载存档按钮初始化
    startButton->setGeometry(430, 450, 150, 80);                                  // 设置开始按钮位置
    savebutton->setGeometry(430, 520, 150, 80);                                   // 设置保存按钮位置
    loadbutton->setGeometry(430, 590, 150, 80);                                   // 设置加载存档按钮位置
    exitButton->setGeometry(430, 660, 150, 80);                                   // 设置退出按钮位置
    connect(startButton, &QPushButton::clicked, this, &MainInterface::startGame); // 开始按钮连接
    // connect(savebutton, &QPushButton::clicked, this, &MainInterface::save_date);  // 保存按钮连接
    // connect(loadbutton, &QPushButton::clicked, this, &MainInterface::load_date);  // 加载存档按钮连接
    connect(exitButton, &QPushButton::clicked, this, &QWidget::close); // 退出按钮连接
}

void MainInterface::paintEvent(QPaintEvent *event)
{
    QPainter pen(this);
    pen.drawPixmap(0, 0, 1000, 800, QPixmap("../src/main_back_ground.png")); // 绘制背景
}

void MainInterface::startGame()
{
    this->hide();
    select_heroes_interface = new SelectHeroesInterface(this);
    select_heroes_interface->show();
}