#pragma once

#include "ClubsContainer.h"
#include "Match.h"
#include "MyClub.h"
#include "qmainwindow.h"
#include <QMainWindow>
/**
@class MenagerWindow
@brief Klasa MenagerWindow reprezentuje interfejs graficzny aplikacji menedżera drużyny w rozgrywkach Ligi Mistrzów.
Klasa zawiera metody i sloty, które umożliwiają użytkownikowi zarządzanie swoją drużyną, jej składem i szkoleniem umiejętności.
*/
namespace Ui{
class MenagerWindow;
}
class MenagerWindow : public QMainWindow
{
    Q_OBJECT
public:
    MenagerWindow(QWidget *parent,ChampionsLeague& tournament, MyClub& myClub);
    ~MenagerWindow();
private:
    Ui::MenagerWindow *ui;
    vector<Match*> Scores;
    ClubsContainer* clubs;
    bool recovery;
    MyClub* myClub;
    ChampionsLeague* tournament;
    bool isActive;
private slots:
    void on_ExitButton_clicked();
    void on_RecoveryButton_clicked();
    void on_squadTable_cellClicked(int row, int column);
    void on_NextRoundButton_clicked();
    void updateStamina();
    void on_PickLineupButton_clicked();
    void on_SkillTrainingButton_clicked();
};
