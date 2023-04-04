#pragma once

#include "Match.h"
#include "qmainwindow.h"
#include <QMainWindow>
namespace Ui{
class MainUi;
}
class ScoreTable : public QMainWindow
{
    Q_OBJECT
public:
    ScoreTable(QWidget *parent,vector<Match*> lastRoundScores);
    ~ScoreTable();

private:
    Ui::MainUi *ui;
    vector<Match*> Scores;
private slots:
    void NumPressed();
    void printScores();
};
