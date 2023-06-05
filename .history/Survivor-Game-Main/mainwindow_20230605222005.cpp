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

    stackedLayout = new QStackedWidget(this);                     // 创建堆栈窗口 用于切换窗口
    main_interface = new MainInterface(this);                     // 创建主界面
    load_interface = new LoadInterface(this);                     // 创建加载界面
    shop_interface = new ShopInterface(this);                     // 创建商店界面
    select_heroes_interface = new SelectHeroesInterface(this);    // 创建选择英雄界面
    fight_interface = new FightInterface(this);                   // 创建战斗界面
    level_up_select_interface = new LevelUpSelectInterface(this); // 创建升级选择界面
    game_end_interface = new GameEndInterface(this);              // 创建游戏结束界面

    this->setCentralWidget(stackedLayout);
    main_interface->setFixedSize(1000, 800);             // 设置窗口大小
    shop_interface->setFixedSize(1000, 800);             // 设置窗口大小
    load_interface->setFixedSize(1000, 800);             // 设置窗口大小
    select_heroes_interface->setFixedSize(1000, 800);    // 设置窗口大小
    fight_interface->setFixedSize(1000, 800);            // 设置窗口大小
    level_up_select_interface->setFixedSize(1000, 800);  // 设置窗口大小
    game_end_interface->setFixedSize(1000, 800);         // 设置窗口大小
    stackedLayout->addWidget(main_interface);            // 添加窗口0
    stackedLayout->addWidget(select_heroes_interface);   // 添加窗口1
    stackedLayout->addWidget(fight_interface);           // 添加窗口2
    stackedLayout->addWidget(game_end_interface);        // 添加窗口3
    stackedLayout->addWidget(shop_interface);            // 添加窗口4
    stackedLayout->addWidget(load_interface);            // 添加窗口5
    stackedLayout->addWidget(level_up_select_interface); // 添加窗口6

    stackedLayout->setCurrentWidget(main_interface); // 设置当前窗口

    connect(main_interface, &MainInterface::changeWidgetsignal, this, &MainWindow::changeWidget);                  // 切换窗口信号连接
    connect(select_heroes_interface, &SelectHeroesInterface::changeWidgetsignal, this, &MainWindow::changeWidget); // 切换窗口信号连接
    connect(fight_interface, &FightInterface::changeWidgetsignal, this, &MainWindow::changeWidget);                // 切换窗口信号连接
    connect(game_end_interface, &GameEndInterface::changeWidgetsignal, this, &MainWindow::changeWidget);           // 切换窗口信号连接
    connect(shop_interface, &ShopInterface::changeWidgetsignal, this, &MainWindow::changeWidget);                  // 切换窗口信号连接
    connect(load_interface, &LoadInterface::changeWidgetsignal, this, &MainWindow::changeWidget);                  // 切换窗口信号连接

    connect(select_heroes_interface, &SelectHeroesInterface::selectHerosignal, fight_interface, &FightInterface::Heroes_init); // 选择英雄信号连接
    connect(select_heroes_interface, &SelectHeroesInterface::selectMapsignal, fight_interface, &FightInterface::get_map_type); // 选择地图信号连接

    connect(shop_interface, &ShopInterface::prop_type, fight_interface, &FightInterface::get_prop_type);            // 道具类型信号连接
    connect(main_interface, &MainInterface::continue_game_signal, fight_interface, &FightInterface::continue_game); // 继续游戏信号连接

    connect(level_up_select_interface, &LevelUpSelectInterface::change_type, fight_interface, &FightInterface::get_level_up_change); // 升级选择信号连接

    connect(load_interface, &LoadInterface::data_select_signal, fight_interface, &FightInterface::get_data); // 读取存档信号连接
    connect(load_interface, &LoadInterface::is_selected, main_interface, &MainInterface::is_started);        // 读取存档信号连接
    connect(main_interface, &MainInterface::is_main, load_interface, &LoadInterface::is_main);               // 读取存档信号连接
    connect(fight_interface, &FightInterface::is_fight, load_interface, &LoadInterface::is_fight);           // 是否为战斗界面信号连接

    connect(game_end_interface, &GameEndInterface::play_again_signal, this, &MainWindow::play_again);                                     // 再来一局信号连接
    connect(game_end_interface, &GameEndInterface::restart_game_signal, select_heroes_interface, &SelectHeroesInterface::restart_select); // 再来一局信号连接
    connect(game_end_interface, &GameEndInterface::changeWidgetsignal, this, &MainWindow::changeWidget);                                  // 切换窗口信号连接
    connect(game_end_interface, &GameEndInterface::changeWidgetsignal, this, &MainWindow::restart_game);                                  // 切换窗口信号连接
    connect(fight_interface, &FightInterface::game_end_type_signal, game_end_interface, &GameEndInterface::get_end_type);                 // 游戏结束类型信号连接
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeWidget(int Index)
{
    stackedLayout->setCurrentIndex(Index);
}

void MainWindow::play_again()
{
    main_interface->again_game();
}

void MainWindow::restart_game()
{
    stackedLayout->removeWidget(fight_interface);
    fight_interface->deleteLater();
    fight_interface = new FightInterface(this);
    fight_interface->setFixedSize(1000, 800); // 设置窗口大小

    connect(fight_interface, &FightInterface::changeWidgetsignal, this, &MainWindow::changeWidget);                            // 切换窗口信号连接
    connect(select_heroes_interface, &SelectHeroesInterface::selectHerosignal, fight_interface, &FightInterface::Heroes_init); // 选择英雄信号连接
    connect(fight_interface, &FightInterface::game_end_type_signal, game_end_interface, &GameEndInterface::get_end_type);      // 游戏结束类型信号连接

    stackedLayout->insertWidget(2, fight_interface);
    stackedLayout->setCurrentIndex(0);
    main_interface->again_game();
}
