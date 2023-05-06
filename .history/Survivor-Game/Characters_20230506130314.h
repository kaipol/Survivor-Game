#include <QWidget>
#include <Qstring>

class AL_1S : public QWidget
{
    Q_OBJECT
private:
    QString name;
    int blood;
    int attack;
    int defense;

public:
    AL_1S();
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