#include "LoadInterface.h"

LoadInterface::LoadInterface(QWidget *parent) : QWidget(parent)
{
    save_button = new QPushButton("保存存档1", this);  // 保存存档按钮初始化
    save_button->setGeometry(85, 600, 150, 80);        // 设置保存存档按钮位置
    save_button2 = new QPushButton("保存存档2", this); // 保存存档按钮初始化
    save_button2->setGeometry(430, 600, 150, 80);      // 设置保存存档按钮位置
    save_button3 = new QPushButton("保存存档3", this); // 保存存档按钮初始化
    save_button3->setGeometry(770, 600, 150, 80);      // 设置保存存档按钮位置
    load_button = new QPushButton("加载存档1", this);  // 加载存档按钮初始化
    load_button->setGeometry(85, 650, 150, 80);        // 设置加载存档按钮位置
    load_button2 = new QPushButton("加载存档2", this); // 加载存档按钮初始化
    load_button2->setGeometry(430, 650, 150, 80);      // 设置加载存档按钮位置
    load_button3 = new QPushButton("加载存档3", this); // 加载存档按钮初始化
    load_button3->setGeometry(770, 650, 150, 80);      // 设置加载存档按钮位置
    back_button = new QPushButton("返回主窗口", this); // 返回按钮初始化
    back_button->setGeometry(900, 0, 100, 50);         // 设置按钮位置和大小

    connect(save_button, &QPushButton::clicked, this, [=]()
            { save_data(0); }); // 保存存档按钮连接
    connect(save_button2, &QPushButton::clicked, this, [=]()
            { save_data(1); }); // 保存存档按钮连接
    connect(save_button3, &QPushButton::clicked, this, [=]()
            { save_data(2); }); // 保存存档按钮连接
    connect(load_button, &QPushButton::clicked, this, [=]()
            { load_data(0); }); // 加载存档按钮连接
    connect(load_button2, &QPushButton::clicked, this, [=]()
            { load_data(1); }); // 加载存档按钮连接
    connect(load_button3, &QPushButton::clicked, this, [=]()
            { load_data(2); }); // 加载存档按钮连接
    connect(back_button, &QPushButton::clicked, this, [=]()
            { emit changeWidgetsignal(0); }); // 返回按钮连接
    load_hero_info();
    update_info();
}

void LoadInterface::paintEvent(QPaintEvent *event)
{
    QPainter pen(this);
    pen.drawPixmap(0, 0, 1000, 850, QPixmap("../src/Sprite/Load_background.png")); // 绘制背景
}
void LoadInterface::get_save_date(Heroes hero)
{
    hero_mir = new Heroes(hero);
}

void LoadInterface::update_info()
{
    // 存档1
    if (!is_null)
    {
        load_info_label_name = new QLabel("角色名：" + hero_mir->get_name(), this); // 加载存档信息标签初始化
        load_info_label_name->setGeometry(90, 230, 300, 50);                        // 设置加载存档信息标签位置
        load_info_label_name->setStyleSheet("font:bold 20px;");
        load_info_label_name->show();
        load_info_label_hp = new QLabel("当前血量：" + QString::number(hero_mir->get_blood()), this);
        load_info_label_hp->setGeometry(90, 280, 300, 50);
        load_info_label_hp->setStyleSheet("font:bold 20px;");
        load_info_label_hp->show();
        load_info_label_atk = new QLabel("攻击力：" + QString::number(hero_mir->get_bullet_attack()), this);
        load_info_label_atk->setGeometry(90, 330, 300, 50);
        load_info_label_atk->setStyleSheet("font:bold 20px;");
        load_info_label_atk->show();
        load_info_label_spd = new QLabel("当前速度：" + QString::number(hero_mir->get_speed()), this);
        load_info_label_spd->setGeometry(90, 380, 300, 50);
        load_info_label_spd->setStyleSheet("font:bold 20px;");
        load_info_label_spd->show();
        load_info_label_coin = new QLabel("当前金币数：" + QString::number(hero_mir->get_hero_coin()), this);
        load_info_label_coin->setGeometry(90, 430, 300, 50);
        load_info_label_coin->setStyleSheet("font:bold 20px;");
        load_info_label_coin->show();
        load_info_label_level = new QLabel("当前等级：" + QString::number(hero_mir->get_hero_level()), this);
        load_info_label_level->setGeometry(90, 480, 300, 50);
        load_info_label_level->setStyleSheet("font:bold 20px;");
        load_info_label_level->show();
        load_info_label_revival = new QLabel("当前复活次数：" + QString::number(hero_mir->get_hero_revival_times()), this);
        load_info_label_revival->setGeometry(90, 530, 300, 50);
        load_info_label_revival->setStyleSheet("font:bold 20px;");
        load_info_label_revival->show();
    }

    // 存档2
    if (!is_null2)
    {
        load_info_label_name2 = new QLabel("角色名：" + hero_mir2->get_name(), this); // 加载存档信息标签初始化
        load_info_label_name2->setGeometry(400, 230, 300, 50);                        // 设置加载存档信息标签位置
        load_info_label_name2->setStyleSheet("font:bold 20px;");
        load_info_label_name2->show();
        load_info_label_hp2 = new QLabel("当前血量：" + QString::number(hero_mir2->get_blood()), this);
        load_info_label_hp2->setGeometry(400, 280, 300, 50);
        load_info_label_hp2->setStyleSheet("font:bold 20px;");
        load_info_label_hp2->show();
        load_info_label_atk2 = new QLabel("攻击力：" + QString::number(hero_mir2->get_bullet_attack()), this);
        load_info_label_atk2->setGeometry(400, 330, 300, 50);
        load_info_label_atk2->setStyleSheet("font:bold 20px;");
        load_info_label_atk2->show();
        load_info_label_spd2 = new QLabel("当前速度：" + QString::number(hero_mir2->get_speed()), this);
        load_info_label_spd2->setGeometry(400, 380, 300, 50);
        load_info_label_spd2->setStyleSheet("font:bold 20px;");
        load_info_label_spd2->show();
        load_info_label_coin2 = new QLabel("当前金币数：" + QString::number(hero_mir2->get_hero_coin()), this);
        load_info_label_coin2->setGeometry(400, 430, 300, 50);
        load_info_label_coin2->setStyleSheet("font:bold 20px;");
        load_info_label_coin2->show();
        load_info_label_level2 = new QLabel("当前等级：" + QString::number(hero_mir2->get_hero_level()), this);
        load_info_label_level2->setGeometry(400, 480, 300, 50);
        load_info_label_level2->setStyleSheet("font:bold 20px;");
        load_info_label_level2->show();
        load_info_label_revival2 = new QLabel("当前复活次数：" + QString::number(hero_mir2->get_hero_revival_times()), this);
        load_info_label_revival2->setGeometry(400, 530, 300, 50);
        load_info_label_revival2->setStyleSheet("font:bold 20px;");
        load_info_label_revival2->show();
    }

    // 存档3
    if (!is_null3)
    {
        load_info_label_name3 = new QLabel("角色名：" + hero_mir3->get_name(), this); // 加载存档信息标签初始化
        load_info_label_name3->setGeometry(730, 230, 300, 50);                        // 设置加载存档信息标签位置
        load_info_label_name3->setStyleSheet("font:bold 20px;");
        load_info_label_name3->show();
        load_info_label_hp3 = new QLabel("当前血量：" + QString::number(hero_mir3->get_blood()), this);
        load_info_label_hp3->setGeometry(730, 280, 300, 50);
        load_info_label_hp3->setStyleSheet("font:bold 20px;");
        load_info_label_hp3->show();
        load_info_label_atk3 = new QLabel("攻击力：" + QString::number(hero_mir3->get_bullet_attack()), this);
        load_info_label_atk3->setGeometry(730, 330, 300, 50);
        load_info_label_atk3->setStyleSheet("font:bold 20px;");
        load_info_label_atk3->show();
        load_info_label_spd3 = new QLabel("当前速度：" + QString::number(hero_mir3->get_speed()), this);
        load_info_label_spd3->setGeometry(730, 380, 300, 50);
        load_info_label_spd3->setStyleSheet("font:bold 20px;");
        load_info_label_spd3->show();
        load_info_label_coin3 = new QLabel("当前金币数：" + QString::number(hero_mir3->get_hero_coin()), this);
        load_info_label_coin3->setGeometry(730, 430, 300, 50);
        load_info_label_coin3->setStyleSheet("font:bold 20px;");
        load_info_label_coin3->show();
        load_info_label_level3 = new QLabel("当前等级：" + QString::number(hero_mir3->get_hero_level()), this);
        load_info_label_level3->setGeometry(730, 480, 300, 50);
        load_info_label_level3->setStyleSheet("font:bold 20px;");
        load_info_label_level3->show();
        load_info_label_revival3 = new QLabel("当前复活次数：" + QString::number(hero_mir3->get_hero_revival_times()), this);
        load_info_label_revival3->setGeometry(730, 530, 300, 50);
        load_info_label_revival3->setStyleSheet("font:bold 20px;");
        load_info_label_revival3->show();
    }
}

void LoadInterface::is_main()
{
    save_button->hide();
    save_button2->hide();
    save_button3->hide();
    load_button->show();
    load_button2->show();
    load_button3->show();
}

void LoadInterface::is_fight()
{
    save_button->show();
    save_button2->show();
    save_button3->show();
    load_button->hide();
    load_button2->hide();
    load_button3->hide();
}

void LoadInterface::save_data(int choice)
{
    QFile file;
    switch (choice)
    {
    case 0:
        file.setFileName("../src/data/data1.json");
        file.open(QIODevice::WriteOnly | QIODevice::Truncate);
        is_null = false;
        break;
    case 1:
        file.setFileName("../src/data/data2.json");
        file.open(QIODevice::WriteOnly | QIODevice::Truncate);
        is_null2 = false;
        break;
    case 2:
        file.setFileName("../src/data/data3.json");
        file.open(QIODevice::WriteOnly | QIODevice::Truncate);
        is_null3 = false;
        break;
    default:
        break;
    }
    QJsonObject root;
    root.insert("角色名", QJsonValue(hero_mir->get_name()));
    root.insert("当前血量", QJsonValue(hero_mir->get_blood()));
    root.insert("攻击力", QJsonValue(hero_mir->get_bullet_attack()));
    root.insert("当前速度", QJsonValue(hero_mir->get_speed()));
    root.insert("当前金币数", QJsonValue(hero_mir->get_hero_coin()));
    root.insert("当前经验", QJsonValue(hero_mir->get_hero_exp()));
    root.insert("当前等级", QJsonValue(hero_mir->get_hero_level()));
    root.insert("当前复活次数", QJsonValue(hero_mir->get_hero_revival_times()));
    root.insert("基本击杀金币", QJsonValue(hero_mir->get_base_killed_coin()));
    file.write(QJsonDocument(root).toJson());
    file.close();
    load_hero_info();
    update_info();
}
void LoadInterface::load_data(int choice)
{
    QFile file;
    switch (choice)
    {
    case 0:
        if (!is_null)
        {
            emit data_select_signal(*hero_mir);
            emit is_selected();
        }
        break;
    case 1:
        if (!is_null2)
        {
            emit data_select_signal(*hero_mir2);
            emit is_selected();
        }
        break;
    case 2:
        if (!is_null3)
        {
            emit data_select_signal(*hero_mir3);
            emit is_selected();
        }
        break;
    default:
        break;
    }
}

void LoadInterface::load_hero_info()
{
    // 存档1
    QFile file;
    file.setFileName("../src/data/data1.json");
    file.open(QIODevice::ReadOnly);

    QByteArray data = file.readAll();
    file.close();
    QJsonDocument json_doc(QJsonDocument::fromJson(data));
    QJsonObject root = json_doc.object();

    hero_mir = new Heroes(root.value("角色名").toString());
    hero_mir->set_blood(root.value("当前血量").toInt());
    hero_mir->set_bullet_attack(root.value("攻击力").toInt());
    hero_mir->set_speed(root.value("当前速度").toInt());
    hero_mir->set_hero_coin(root.value("当前金币数").toInt());
    hero_mir->set_hero_exp(root.value("当前经验").toInt());
    hero_mir->set_hero_level(root.value("当前等级").toInt());
    hero_mir->set_hero_revival_times(root.value("当前复活次数").toInt());
    hero_mir->set_base_killed_coin(root.value("基本击杀金币").toInt());

    // 存档2
    QFile file2;
    file2.setFileName("../src/data/data2.json");
    file2.open(QIODevice::ReadOnly);
    QByteArray data2 = file2.readAll();
    file2.close();
    QJsonDocument json_doc2(QJsonDocument::fromJson(data2));
    QJsonObject root2 = json_doc2.object();

    hero_mir2 = new Heroes(root2.value("角色名").toString());
    hero_mir2->set_blood(root2.value("当前血量").toInt());
    hero_mir2->set_bullet_attack(root2.value("攻击力").toInt());
    hero_mir2->set_speed(root2.value("当前速度").toInt());
    hero_mir2->set_hero_coin(root2.value("当前金币数").toInt());
    hero_mir2->set_hero_exp(root2.value("当前经验").toInt());
    hero_mir2->set_hero_level(root2.value("当前等级").toInt());
    hero_mir2->set_hero_revival_times(root2.value("当前复活次数").toInt());
    hero_mir2->set_base_killed_coin(root2.value("基本击杀金币").toInt());

    // 存档3
    QFile file3;
    file3.setFileName("../src/data/data3.json");
    file3.open(QIODevice::ReadOnly);
    QByteArray data3 = file3.readAll();
    file3.close();
    QJsonDocument json_doc3(QJsonDocument::fromJson(data3));
    QJsonObject root3 = json_doc3.object();

    hero_mir3 = new Heroes(root3.value("角色名").toString());
    hero_mir3->set_blood(root3.value("当前血量").toInt());
    hero_mir3->set_bullet_attack(root3.value("攻击力").toInt());
    hero_mir3->set_speed(root3.value("当前速度").toInt());
    hero_mir3->set_hero_coin(root3.value("当前金币数").toInt());
    hero_mir3->set_hero_exp(root3.value("当前经验").toInt());
    hero_mir3->set_hero_level(root3.value("当前等级").toInt());
    hero_mir3->set_hero_revival_times(root3.value("当前复活次数").toInt());
    hero_mir3->set_base_killed_coin(root3.value("基本击杀金币").toInt());
}
