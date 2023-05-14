#include "Prop.h"
Prop::Prop(int type)
{
    switch (type)
    {
    case 0:
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