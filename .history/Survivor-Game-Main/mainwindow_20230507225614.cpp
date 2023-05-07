#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("勇者大冒险");                  // 设置标题
    this->setFixedSize(1000, 800);                       // 设置窗口大小
    this->setWindowIcon(QIcon("../src/windowicon.ico")); // 设置图标
    this->setStatusBar(nullptr);

    stackedLayout = new QStackedWidget(this);                  // 创建堆栈窗口 用于切换窗口
    main_interface = new MainInterface(this);                  // 创建主界面
    select_heroes_interface = new SelectHeroesInterface(this); // 创建选择英雄界面

    this->setCentralWidget(stackedLayout);
    main_interface->setFixedSize(1000, 900);           // 设置窗口大小
    select_heroes_interface->setFixedSize(1000, 900);  // 设置窗口大小
    stackedLayout->addWidget(main_interface);          // 添加窗口
    stackedLayout->addWidget(select_heroes_interface); // 添加窗口

    stackedLayout->setCurrentWidget(main_interface); // 设置当前窗口

    connect(main_interface, &MainInterface::changeWidgetsignal, this, &MainWindow::changeWidget);                  // 切换窗口信号连接
    connect(select_heroes_interface, &SelectHeroesInterface::changeWidgetsignal, this, &MainWindow::changeWidget); // 切换窗口信号连接
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeWidget(int Index)
{
    stackedLayout->setCurrentIndex(Index);
}

void MainWindow::paintGameEvent(QPaintEvent *event)
{
    QPainter pen(this);
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (game_map[i][j] == 0)
            {
                pen.drawPixmap(i * 100, 100 + j * 70, 100, 70, QPixmap("../src/Sprite/brick.png")); // 绘制背景
            }
            else if (game_map[i][j] == 1)
            {
                pen.drawPixmap(i * 100, 100 + j * 70, 100, 70, QPixmap("../src/Sprite/barrier.png")); // 绘制背景
            }
        }
    }
}
