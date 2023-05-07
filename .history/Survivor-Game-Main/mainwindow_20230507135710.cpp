#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("勇者大冒险");                                        // 设置标题
    this->setFixedSize(1000, 800);                                             // 设置窗口大小
    startButton = new QPushButton("开始游戏", this);                           // 开始按钮初始化
    exitButton = new QPushButton("退出游戏", this);                            // 退出按钮初始化
    savebutton = new QPushButton("保存游戏", this);                            // 保存按钮初始化
    loadbutton = new QPushButton("加载存档", this);                            // 加载存档按钮初始化
    backbutton = new QPushButton("返回主界面", this);                          // 返回按钮初始化
    backbutton->hide();                                                        // 隐藏返回按钮
    startButton->setGeometry(430, 450, 150, 80);                               // 设置开始按钮位置
    savebutton->setGeometry(430, 520, 150, 80);                                // 设置保存按钮位置
    loadbutton->setGeometry(430, 590, 150, 80);                                // 设置加载存档按钮位置
    exitButton->setGeometry(430, 660, 150, 80);                                // 设置退出按钮位置
    backbutton->setGeometry(0, 760, 90, 30);                                   // 设置返回按钮位置
    connect(startButton, &QPushButton::clicked, this, &MainWindow::startGame); // 开始按钮连接
    // connect(savebutton, &QPushButton::clicked, this, &MainWindow::save_date);  // 保存按钮连接
    // connect(loadbutton, &QPushButton::clicked, this, &MainWindow::load_date);  // 加载存档按钮连接
    connect(exitButton, &QPushButton::clicked, this, &QWidget::close); // 退出按钮连接
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::startGame()
{
    initOther();
    startButton->hide();
    exitButton->hide();
    savebutton->hide();
    loadbutton->hide();
    backbutton->show();
    paintEvent(nullptr, 0);
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter pen(this);
    pen.drawPixmap(0, 0, 1000, 800, QPixmap("../src/main_back_ground.png")); // 绘制背景
    update();
}

void MainWindow::paintEvent(QPaintEvent *event, int type)
{
    QPainter pen(this);
    switch (type)
    {
    case 0: // 开始地图
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                if (game_map[i][j] == 0)
                {
                    QPainter pen(this);
                    pen.drawPixmap(i * 100, j * 80, 100, 80, QPixmap("../src/Sprite/brick.png")); // 绘制背景
                }
                else if (game_map[i][j] == 1)
                {
                    QPainter pen(this);
                    pen.drawPixmap(i * 100, j * 80, 100, 80, QPixmap("../src/Sprite/barrier.png")); // 绘制背景
                }
            }
        }
        break;

    default:
        break;
    }
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
    MonstersNum = 3;
    MonstersLoc = {{0, 0}, {0, 0}, {0, 0}};
}
