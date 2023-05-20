#include "MainInterface.h"

MainInterface::MainInterface(QWidget *parent) : QWidget(parent)
{
    startButton = new QPushButton("开始游戏", this);       // 开始按钮初始化
    exitButton = new QPushButton("退出游戏", this);        // 退出按钮初始化
    load_button = new QPushButton("加载存档", this);       // 加载存档按钮初始化
    enter_shop_button = new QPushButton("进入商店", this); // 进入商店按钮初始化
    continue_button = new QPushButton("继续游戏", this);   // 继续游戏按钮初始化

    startButton->setGeometry(430, 350, 150, 80);       // 设置开始按钮位置
    continue_button->setGeometry(430, 430, 150, 80);   // 设置继续游戏按钮位置
    continue_button->hide();                           // 隐藏继续游戏按钮
    load_button->setGeometry(430, 450, 150, 80);       // 设置加载存档按钮位置
    enter_shop_button->setGeometry(430, 550, 150, 80); // 设置进入商店按钮位置
    exitButton->setGeometry(430, 650, 150, 80);        // 设置退出按钮位置

    connect(startButton, &QPushButton::clicked, this, &MainInterface::startGame);         // 开始按钮连接
    connect(enter_shop_button, &QPushButton::clicked, this, &MainInterface::enter_shop);  // 进入商店按钮连接
    connect(load_button, &QPushButton::clicked, this, &MainInterface::load_data);         // 加载存档按钮连接
    connect(continue_button, &QPushButton::clicked, this, &MainInterface::continue_game); // 继续游戏按钮连接
    connect(exitButton, &QPushButton::clicked, this, &qApp->quit);                        // 退出按钮连接

    game_name_label = new QLabel("勇者大冒险", this);                          // 游戏名字标签初始化
    game_name_label->setGeometry(300, 100, 500, 100);                          // 设置游戏名字标签位置
    game_name_label->setStyleSheet("font: bold 85px");                         // 设置游戏名字标签字体
    game_name_label->setFont(QFont("../src/Font/LiberationSans.ttf", 85, 50)); // 设置游戏名字标签字体
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
    is_started();
}

void MainInterface::is_started()
{
    continue_button->show();
    load_button->setGeometry(430, 510, 150, 80);
    enter_shop_button->setGeometry(430, 590, 150, 80);
    exitButton->setGeometry(430, 670, 150, 80);
}

void MainInterface::restart_game()
{
    continue_button->hide();                           // 隐藏继续游戏按钮
    load_button->setGeometry(430, 450, 150, 80);       // 设置加载存档按钮位置
    enter_shop_button->setGeometry(430, 550, 150, 80); // 设置进入商店按钮位置
    exitButton->setGeometry(430, 650, 150, 80);        // 设置退出按钮位置
}

void MainInterface::load_data()
{
    this->hide();
    emit changeWidgetsignal(5);
    emit is_main();
}

void MainInterface::enter_shop()
{
    this->hide();
    emit changeWidgetsignal(4);
}

void MainInterface::continue_game()
{
    this->hide();
    emit changeWidgetsignal(2);
    emit continue_game_signal();
}
