#pragma once

#include "qmainwindow.h"
#include <QMainWindow>
namespace Ui{
class MainUi;
}
class ScoreTable : public QMainWindow
{
    Q_OBJECT
public:
   explicit ScoreTable(QWidget *parent = 0);
    ~ScoreTable();

private:
    Ui::MainUi *ui;
private slots:
    void NumPressed();
};
