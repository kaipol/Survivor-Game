#include "Prop.h"
Prop::Prop(int type)
{
    switch (type)
    {
    case 0:
        prop_coin = 20;
        prop_name = "攻击药水";
        prop_info = "攻击力+3";
        break;
    case 1:
        prop_coin = 25;
        prop_name = "速度药水";
        prop_info = "速度+5";
        break;
    case 2:
        prop_coin = 100;
        prop_name = "复活药水";
        prop_info = "复活次数+1";
        break;
    case 3:
        prop_coin = 20;
        prop_name = "金币宝藏";
        prop_info = "击杀怪物获取金币数+1";
        break;
    case 4:
        prop_coin = 25;
        prop_name = "血量药水";
        prop_info = "血量+3";
        break;
    default:
        break;
    }
}

QPixmap *Prop::get_pic()
{
    return prop_pic;
}

int Prop::get_coin()
{
    return prop_coin;
}

QString Prop::get_name()
{
    return prop_name;
}

QString Prop::get_info()
{
    return prop_info;
}