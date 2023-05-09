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
    fight_interface = new FightInterface(this);                // 创建战斗界面
    game_end_interface = new GameEndInterface(this);           // 创建游戏结束界面

    this->setCentralWidget(stackedLayout);
    main_interface->setFixedSize(1000, 800);           // 设置窗口大小
    select_heroes_interface->setFixedSize(1000, 800);  // 设置窗口大小
    fight_interface->setFixedSize(1000, 800);          // 设置窗口大小
    game_end_interface->setFixedSize(1000, 800);       // 设置窗口大小
    stackedLayout->addWidget(main_interface);          // 添加窗口
    stackedLayout->addWidget(select_heroes_interface); // 添加窗口
    stackedLayout->addWidget(fight_interface);         // 添加窗口
    stackedLayout->addWidget(game_end_interface);      // 添加窗口

    stackedLayout->setCurrentWidget(main_interface); // 设置当前窗口

    connect(main_interface, &MainInterface::changeWidgetsignal, this, &MainWindow::changeWidget);                  // 切换窗口信号连接
    connect(select_heroes_interface, &SelectHeroesInterface::changeWidgetsignal, this, &MainWindow::changeWidget); // 切换窗口信号连接
    connect(fight_interface, &FightInterface::changeWidgetsignal, this, &MainWindow::changeWidget);                // 切换窗口信号连接
    connect(game_end_interface, &GameEndInterface::changeWidgetsignal, this, &MainWindow::changeWidget);           // 切换窗口信号连接
    connect(game_end_interface, &GameEndInterface::play_again_signal,this,&MainWindow::play_again; // 再来一局信号连接

    connect(select_heroes_interface, &SelectHeroesInterface::selectHerosignal, fight_interface, &FightInterface::Heroes_and_Monsters_init); // 选择英雄信号连接
    connect(fight_interface, &FightInterface::game_end_type_signal, game_end_interface, &GameEndInterface::get_end_type);                   // 游戏结束类型信号连接
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
}
