#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("勇者大冒险");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
}

void MainWindow::paintEvent(QPaintEvent *event)
{
}

void MainWindow::initMap()
{
    QVector<QVector<int>> game_map;
}