#ifndef _PROP_H_
#define _PROP_H_
#endif // _PROP_H_
#pragma once

#include <QPixmap>
#include <QString>
class Prop
{
    QPixmap *prop_pic; // 道具图片
    int prop_coin;     // 道具价格
    QString prop_name; // 道具名称

public:
    Prop();
};