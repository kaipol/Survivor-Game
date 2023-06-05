#include <QVector>

class GameMap
{
    QVector<QVector<int>> map;

public:
    GameMap();
    QVector<QVector<int>> getMap();
};