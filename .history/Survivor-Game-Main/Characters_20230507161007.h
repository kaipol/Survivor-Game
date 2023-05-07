#include <QWidget>
#include <Qstring>

class Heroes : public QWidget
{
    Q_OBJECT
private:
    QString name;
    int blood;
    int attack;
    int defense;
    int HeroesLoc[2] = {0};

public:
    Heroes(QString name);
    void Heroes_move(); // 角色移动函数
};

class Monsters
{
    QString name;
    int blood;
    int attack;
    int defense;
    int MonstersNum;
    QVector<QPair<int, int>> MonstersLoc;

public:
    Monsters(QString);
    void Monsters_move(); // 怪物移动函数
};