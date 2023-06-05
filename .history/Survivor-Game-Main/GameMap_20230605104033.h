#ifndef GAMEMAP_H
#define GAMEMAP_H

#include <QVector>

class GameMap
{
    QVector<QVector<int>> map;

public:
    GameMap(int type);
    QVector<QVector<int>> getMap();
};
#endif // GAMEMAP_H