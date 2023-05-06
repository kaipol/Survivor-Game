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

public:
    Heroes(QString name);
};

class Monsters
{
    QString name;
    int blood;
    int attack;
    int defense;
    int type;

public:
    Monsters();
};