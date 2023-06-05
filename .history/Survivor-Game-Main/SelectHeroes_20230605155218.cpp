#include "SelectHeroes.h"

SelectHeroesInterface::SelectHeroesInterface(QWidget *parent) : QWidget(parent)
{

    select_hero1 = new QPushButton("选择AL-1S", this);
    select_hero1->setGeometry(210, 500, 100, 30);
    connect(select_hero1, &QPushButton::clicked, this, [=]()
            { hero_to_fight(1); });                // 选择按钮连接
    hero1_hp = new QLabel("血量: 20", this);       // 血量显示
    hero1_hp->setGeometry(210, 550, 200, 60);      // 血量显示位置
    hero1_hp->setStyleSheet("font: bold 25px");    // 设置字体
    hero1_atk = new QLabel("攻击力: 5", this);     // 攻击力显示
    hero1_atk->setGeometry(210, 600, 200, 60);     // 攻击力显示位置
    hero1_atk->setStyleSheet("font: bold 25px");   // 设置字体
    hero1_speed = new QLabel("速度: 10", this);    // 速度显示
    hero1_speed->setGeometry(210, 650, 200, 60);   // 速度显示位置
    hero1_speed->setStyleSheet("font: bold 25px"); // 设置字体

    select_hero2 = new QPushButton("选择NOA", this);
    select_hero2->setGeometry(690, 500, 100, 30);
    connect(select_hero2, &QPushButton::clicked, this, [=]()
            { hero_to_fight(2); });                // 选择按钮连接
    hero2_hp = new QLabel("血量: 13", this);       // 血量显示
    hero2_hp->setGeometry(690, 550, 200, 60);      // 血量显示位置
    hero2_hp->setStyleSheet("font: bold 25px");    // 设置字体
    hero2_atk = new QLabel("攻击力: 7", this);     // 攻击力显示
    hero2_atk->setGeometry(690, 600, 200, 60);     // 攻击力显示位置
    hero2_atk->setStyleSheet("font: bold 25px");   // 设置字体
    hero2_speed = new QLabel("速度: 7", this);     // 速度显示
    hero2_speed->setGeometry(690, 650, 200, 60);   // 速度显示位置
    hero2_speed->setStyleSheet("font: bold 25px"); // 设置字体

    map_label = new QLabel("选择地图类型", this);          // 地图选择
    map_label->setGeometry(330, 100, 400, 100);            // 地图选择位置
    map_label->hide();                                     // 隐藏地图选择
    map_label->setStyleSheet("font: bold 85px;color:red"); // 设置字体
    select_map1 = new QPushButton("选择地图1", this);      // 选择地图1
    select_map1->setGeometry(430, 200, 200, 100);          // 选择地图1位置
    connect(select_map1, &QPushButton::clicked, this, [=]()
            { select_map(1); });                      // 选择按钮连接
    select_map2 = new QPushButton("选择地图2", this); // 选择地图2
    select_map2->setGeometry(430, 400, 200, 100);     // 选择地图2位置
    connect(select_map2, &QPushButton::clicked, this, [=]()
            { select_map(2); });                      // 选择按钮连接
    select_map3 = new QPushButton("选择地图3", this); // 选择地图3
    select_map3->setGeometry(430, 600, 200, 100);     // 选择地图3位置
    connect(select_map3, &QPushButton::clicked, this, [=]()
            { select_map(3); }); // 选择按钮连接
    select_map1->hide();
    select_map2->hide();
    select_map3->hide();
}

void SelectHeroesInterface::paintEvent(QPaintEvent *event)
{
    QPainter pen(this);
    (pen).drawPixmap(-125, -100, 1250, 1000, QPixmap("../src/Sprite/BBG_002.png")); // 绘制背景
    if (!select_hero1->isHidden())
    {
        (pen).drawPixmap(130, 150, 300, 350, QPixmap("../src/Sprite/MCH_PL001_001.png")); // 绘制人物
        (pen).drawPixmap(600, 150, 300, 350, QPixmap("../src/Sprite/MCH_PL006_001.png")); // 绘制人物
    }
}

void SelectHeroesInterface::hero_to_fight(int type)
{
    switch (type)
    {
    case 1:
        emit selectHerosignal("AL-1S");
        break;
    case 2:
        emit selectHerosignal("NOA");
        break;
    default:
        break;
    }
    select_hero1->hide();
    select_hero2->hide();
    hero1_hp->hide();
    hero1_atk->hide();
    hero1_speed->hide();
    hero2_hp->hide();
    hero2_atk->hide();
    hero2_speed->hide();
    map_label->show();
    select_map1->show();
    select_map2->show();
    select_map3->show();
    update();
}

void SelectHeroesInterface::select_map(int type)
{
    switch (type)
    {
    case 1:
        emit selectMapsignal(1);
        break;
    case 2:
        emit selectMapsignal(2);
        break;
    case 3:
        emit selectMapsignal(3);
        break;
    default:
        break;
    }
    this->hide();
    emit changeWidgetsignal(3);
}
