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
    void set_Heroes_loc(int, int); // 角色移动函数
    void drawHero();               // 绘制角色函数
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
    void drawMonster();   // 绘制怪物函数
};
