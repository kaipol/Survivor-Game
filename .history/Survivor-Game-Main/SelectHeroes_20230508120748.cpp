#include "SelectHeroes.h"

SelectHeroesInterface::SelectHeroesInterface(QWidget *parent) : QWidget(parent)
{

    backbutton = new QPushButton("返回主界面", this);                                       // 返回按钮初始化
    backbutton->setGeometry(900, 0, 90, 30);                                                // 设置返回按钮位置
    connect(backbutton, &QPushButton::clicked, this, &SelectHeroesInterface::back_to_main); // 返回按钮连接
    select_hero1 = new QPushButton("选择AL-1S", this);
    select_hero1->setGeometry(210, 500, 100, 30);
    connect(select_hero1, &QPushButton::clicked, this, &SelectHeroesInterface::hero1_to_fight); // 选择按钮连接
    select_hero2 = new QPushButton("选择NOA", this);
    select_hero2->setGeometry(690, 500, 100, 30);
    connect(select_hero2, &QPushButton::clicked, this, &SelectHeroesInterface::hero2_to_fight); // 选择按钮连接
}

void SelectHeroesInterface::back_to_main()
{
    this->hide();
    emit changeWidgetsignal(0);
}

void SelectHeroesInterface::paintEvent(QPaintEvent *event)
{
    QPainter pen(this);
    pen.drawPixmap(-125, -100, 1250, 1000, QPixmap("../src/Sprite/BBG_002.png"));   // 绘制背景
    pen.drawPixmap(70, 200, 400, 300, QPixmap("../src/Sprite/MCH_PL001_001.png"));  // 绘制背景
    pen.drawPixmap(530, 200, 400, 300, QPixmap("../src/Sprite/MCH_PL006_001.png")); // 绘制背景
}

void SelectHeroesInterface::hero1_to_fight()
{
    this->hide();
    emit changeHerosignal("AL-1S");
    emit changeWidgetsignal(2);
}

void SelectHeroesInterface::hero2_to_fight()
{
    this->hide();
    emit changeHerosignal("NOA");
    emit changeWidgetsignal(2);
}