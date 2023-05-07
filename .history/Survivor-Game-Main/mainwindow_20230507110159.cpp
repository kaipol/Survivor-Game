#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->grabKeyboard();               // 设置接收键盘事件
    this->setWindowTitle("勇者大冒险"); // 设置标题
    initMap();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void startGame()
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