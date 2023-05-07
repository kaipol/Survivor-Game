#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    startButton = new QPushButton("开始游戏", this);                           // 开始按钮初始化
    exitButton = new QPushButton("退出游戏", this);                            // 退出按钮初始化
    savebutton = new QPushButton("保存游戏", this);                            // 保存按钮初始化
    loadbutton = new QPushButton("加载存档", this);                            // 加载存档按钮初始化
    startButton->setGeometry(450, 450, 150, 80);                               // 设置开始按钮位置
    savebutton->setGeometry(450, 520, 150, 80);                                // 设置保存按钮位置
    loadbutton->setGeometry(450, 590, 150, 80);                                // 设置加载存档按钮位置
    exitButton->setGeometry(450, 660, 150, 80);                                // 设置退出按钮位置
    connect(startButton, &QPushButton::clicked, this, &MainWindow::startGame); // 开始按钮连接
    connect(savebutton, &QPushButton::clicked, this, &MainWindow::save_date);  // 保存按钮连接
    connect(loadbutton, &QPushButton::clicked, this, &MainWindow::load_date);  // 加载存档按钮连接
    connect(exitButton, &QPushButton::clicked, this, &QWidget::close);         // 退出按钮连接
    this->grabKeyboard();                                                      // 设置接收键盘事件
    this->setWindowTitle("勇者大冒险");                                        // 设置标题
    this->setFixedSize(1000, 800);                                             // 设置窗口大小
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::startGame()
{
    initOther();
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter pen(this);
}

void MainWindow::initOther()
{
    game_map = {
        {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 1, 0, 0, 1, 0},
        {0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 0, 1, 0},
        {0, 0, 0, 1, 0, 0, 0, 0, 1, 0},
    };
}