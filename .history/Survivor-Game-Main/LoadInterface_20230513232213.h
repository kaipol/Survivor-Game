#ifndef LOADINTERFACE_H
#define LOADINTERFACE_H
#endif // LOADINTERFACE_H
#pragma once

#include <QWidget>
#include <QByteArray>
#include <QFile>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QLabel>

class LoadInterface : public QWidget
{
    Q_OBJECT
private:
    QLabel *load_label;

public:
};