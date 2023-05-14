#ifndef _PROP_H_
#define _PROP_H_
#pragma once

#include <QPixmap>
#include <QString>

class Prop
{
    QPixmap *prop_pic; // 道具图片
    int prop_coin;     // 道具价格
    QString prop_name; // 道具名称
    QString prop_info; // 道具信息

public:
    Prop(int type);
    QPixmap *get_pic(); // 获取道具图片
    int get_coin();     // 获取道具价格
    QString get_name(); // 获取道具名称
    QString get_info(); // 获取道具信息
};
#endif // _PROP_H_