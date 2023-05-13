#include "Prop.h"
Prop::Prop(QString name, QString info, int coin, QPixmap *pic)
{
    prop_name = name;
    prop_info = info;
    prop_coin = coin;
    prop_pic = pic;
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