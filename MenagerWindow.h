#pragma once

#include "ClubsContainer.h"
#include "Match.h"
#include "MyClub.h"
#include "qmainwindow.h"
#include <QMainWindow>
namespace Ui{
class MenagerWindow;
}
class MenagerWindow : public QMainWindow
{
    Q_OBJECT
public:
    MenagerWindow(QWidget *parent,vector<Match*> lastRoundScores);
    MenagerWindow(QWidget *parent,ChampionsLeague& tournament, MyClub& myClub);
    ~MenagerWindow();
private:
    Ui::MenagerWindow *ui;
    vector<Match*> Scores;
    ClubsContainer* clubs;
    bool recovery;
    MyClub* myClub;
    ChampionsLeague* tournament;
private slots:
    void printScores();
    void on_ExitButton_clicked();
    void on_RecoveryButton_clicked();
    void on_playersTable_cellClicked(int row, int column);
};
