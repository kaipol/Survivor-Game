
#include <Qpushbutton>
#include <Qmediaplayer>
#include <QPainter>
class SelectHeroesInterface : public QWidget
{
    Q_OBJECT
public slots:
    void back_to_main();

public:
    SelectHeroesInterface();
    void inter_select_interface();
    // void paintEvent(QPaintEvent *event);

private:
    QPushButton *backbutton; // 返回按钮
    QMediaPlayer *bgm_select;
};