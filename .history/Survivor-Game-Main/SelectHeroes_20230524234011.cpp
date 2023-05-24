#include "SelectHeroes.h"

SelectHeroesInterface::SelectHeroesInterface(QWidget *parent) : QWidget(parent)
{

    select_hero1 = new QPushButton("选择AL-1S", this);
    select_hero1->setGeometry(210, 500, 100, 30);
    connect(select_hero1, &QPushButton::clicked, this, &SelectHeroesInterface::hero1_to_fight); // 选择按钮连接
    hero1_hp = new QLabel("血量: 20", this);                                                    // 血量显示
    hero1_hp->setGeometry(210, 550, 200, 60);                                                   // 血量显示位置
    hero1_hp->setStyleSheet("font: bold 25px");                                                 // 设置字体
    hero1_atk = new QLabel("攻击力: 5", this);                                                  // 攻击力显示
    hero1_atk->setGeometry(210, 600, 200, 60);                                                  // 攻击力显示位置
    hero1_atk->setStyleSheet("font: bold 25px");                                                // 设置字体
    hero1_speed = new QLabel("速度: 10", this);                                                 // 速度显示
    hero1_speed->setGeometry(210, 650, 200, 60);                                                // 速度显示位置
    hero1_speed->setStyleSheet("font: bold 25px");                                              // 设置字体

    select_hero2 = new QPushButton("选择NOA", this);
    select_hero2->setGeometry(690, 500, 100, 30);
    connect(select_hero2, &QPushButton::clicked, this, &SelectHeroesInterface::hero2_to_fight); // 选择按钮连接
    hero2_hp = new QLabel("血量: 13", this);                                                    // 血量显示
    hero2_hp->setGeometry(690, 550, 200, 60);                                                   // 血量显示位置
    hero2_hp->setStyleSheet("font: bold 25px");                                                 // 设置字体
    hero2_atk = new QLabel("攻击力: 7", this);                                                  // 攻击力显示
    hero2_atk->setGeometry(690, 600, 200, 60);                                                  // 攻击力显示位置
    hero2_atk->setStyleSheet("font: bold 25px");                                                // 设置字体
    hero2_speed = new QLabel("速度: 7", this);                                                  // 速度显示
    hero2_speed->setGeometry(690, 650, 200, 60);                                                // 速度显示位置
    hero2_speed->setStyleSheet("font: bold 25px");                                              // 设置字体
}

void SelectHeroesInterface::paintEvent(QPaintEvent *event)
{
    QPainter pen(this);
    pen.drawPixmap(-125, -100, 1250, 1000, QPixmap("../src/Sprite/BBG_002.png"));   // 绘制背景
    pen.drawPixmap(70, 200, 300, 400, QPixmap("../src/Sprite/MCH_PL001_001.png"));  // 绘制背景
    pen.drawPixmap(530, 200, 300, 400, QPixmap("../src/Sprite/MCH_PL006_001.png")); // 绘制背景
}

void SelectHeroesInterface::hero1_to_fight()
{
    this->hide();
    emit selectHerosignal("AL-1S");
    emit changeWidgetsignal(2);
}

void SelectHeroesInterface::hero2_to_fight()
{
    this->hide();
    emit selectHerosignal("NOA");
    emit changeWidgetsignal(2);
}