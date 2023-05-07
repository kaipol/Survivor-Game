#ifndef SELECTHEROES_H
#define SELECTHEROES_H
#endif // SELECTHEROES_H
#pragma once
#include <Qpushbutton>
#include <Qmediaplayer>
#include <QPainter>

class SelectHeroesInterface : public QWidget
{
    Q_OBJECT
public slots:
    void back_to_main();
signals:
    void changeWidgetsignal(int Index);

public:
    SelectHeroesInterface(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);

private:
    QPushButton *backbutton; // 返回按钮
    QMediaPlayer *bgm_select;
};