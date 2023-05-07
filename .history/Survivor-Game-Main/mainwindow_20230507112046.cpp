#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    startButton = new QPushButton(this);         // 开始按钮
    exitButton = new QPushButton(this);          // 退出按钮
    savebutton = new QPushButton(this);          // 保存按钮
    loadbutton = new QPushButton(this);          // 加载存档按钮
    startButton->setText("开始游戏");            // 设置开始按钮文字
    exitButton->setText("退出游戏");             // 设置退出按钮文字
    savebutton->setText("保存游戏");             // 设置保存按钮文字
    loadbutton->setText("加载存档");             // 设置加载存档按钮文字
    startButton->setGeometry(400, 400, 100, 50); // 设置开始按钮位置
    exitButton->setGeometry(400, 450, 100, 50);  // 设置退出按钮位置
    savebutton->setGeometry(400, 500, 100, 50);  // 设置保存按钮位置
    loadbutton->setGeometry(400, 550, 100, 50);  // 设置加载存档按钮位置
    this->grabKeyboard();                        // 设置接收键盘事件
    this->setWindowTitle("勇者大冒险");          // 设置标题
    this->setFixedSize(1000, 800);               // 设置窗口大小
    initMap();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::startGame()
{
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter pen(this);
}

void MainWindow::initMap()
{
    QVector<QVector<int>> game_map = {
        {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},

    };
}