#pragma once
#include <QDialog>

#include "ClubsContainer.h"
#include "Match.h"
#include "qdialog.h"
/**
@class TournamentCreationWindow
@brief Klasa TournamentCreationWindow reprezentuje interfejs graficzny służący do tworzenia nowych rozgrywek Ligi Mistrzów.
Klasa zawiera metody umożliwiające wyświetlanie i edycję informacji o klubach biorących udział w rozgrywkach.
*/
namespace Ui {
class TournamentCreationWindow;
}

class TournamentCreationWindow : public QDialog
{
    Q_OBJECT

public:
    TournamentCreationWindow(QWidget *parent,ClubsContainer& clubsContainer);
    ~TournamentCreationWindow();
    vector<int> getIds();
private:
    Ui::TournamentCreationWindow *ui;
    vector<Match*> Scores;
    vector<int> ids;
    ClubsContainer* clubs;
    int size;
private slots:
    void on_ExitButton_clicked();
    void on_AddButton_clicked();
    void on_SubmitButton_clicked();
};
