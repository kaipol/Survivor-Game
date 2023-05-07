#include "Characters.h"
#include <Qpushbutton>
#include <Qmediaplayer>
class SelectHeroesInterface : public QWidget
{
    Q_OBJECT
public slots:
    void back_to_main();

public:
    void inter_select_interface();

private:
    QPushButton *backbutton; // 返回按钮
    QMediaPlayer *bgm_select;
};