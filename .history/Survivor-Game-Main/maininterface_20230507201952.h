#include <QVector>
#include <QLabel>
#include <QMediaPlayer>
#include <QPainter>
#include <QKeyEvent>
#include <QImage>
#include <QPushButton>
#include <QPair>
#include <Qtimer>

class MainInterface : public QWidget
{
    Q_OBJECT
private:
    QPushButton *startButton; // 开始按钮
    QPushButton *exitButton;  // 退出按钮
    QPushButton *savebutton;  // 保存按钮
    QPushButton *loadbutton;  // 加载存档按钮
public:
    MainInterface(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void initMap();
    void updateMap(int type, int preValue = 0);
    void startGame();
    void save_date();
    void load_date();
};