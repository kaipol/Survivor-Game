#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include "SelectHeroes.h"
#include "MainInterface.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("勇者大冒险");                  // 设置标题
    this->setFixedSize(1000, 800);                       // 设置窗口大小
    this->setWindowIcon(QIcon("../src/windowicon.ico")); // 设置图标

    stackedLayout = new QStackedLayout;
    main_interface = new MainInterface(this);
    select_heroes_interface = new SelectHeroesInterface(this);

    this->setCentralWidget(main_interface);
    main_interface->setGeometry(0, 0, 1000, 800);
    stackedLayout->addWidget(main_interface);
    stackedLayout->addWidget(select_heroes_interface);
    stackedLayout->setCurrentWidget(main_interface);
    stackedLayout->setCurrentWidget(select_heroes_interface);
}

MainWindow::~MainWindow()
{
    delete ui;
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
