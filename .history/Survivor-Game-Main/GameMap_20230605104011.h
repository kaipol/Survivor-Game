#include <QVector>

class GameMap
{
    QVector<QVector<int>> map;

public:
    GameMap(int type);
    QVector<QVector<int>> getMap();
};