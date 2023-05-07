#include "SelectHeroes.h"

void SelectHeroesInterface::inter_select_interface()
{
    this->setFixedSize(1000, 800);                                                          // 设置窗口大小
    backbutton = new QPushButton("返回主界面", this);                                       // 返回按钮初始化
    backbutton->setGeometry(900, 0, 90, 30);                                                // 设置返回按钮位置
    connect(backbutton, &QPushButton::clicked, this, &SelectHeroesInterface::back_to_main); // 返回按钮连接
}

void SelectHeroesInterface::back_to_main()
{
    emit back_to_main();
    this->close();
}