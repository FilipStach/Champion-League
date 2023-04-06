#pragma once

#include "ClubsContainer.h"
#include "Match.h"
#include "qmainwindow.h"
#include <QMainWindow>
namespace Ui{
class ResultWindow;
}
class ResultWindow : public QMainWindow
{
    Q_OBJECT
public:
    ResultWindow(QWidget *parent,vector<Match*> lastRoundScores);
    ResultWindow(QWidget *parent,ClubsContainer& clubsContainer);
    ~ResultWindow();
    vector<int> getIds();
private:
    Ui::ResultWindow *ui;
    vector<Match*> Scores;
    vector<int> ids;
    ClubsContainer* clubs;
    int size;
private slots:
    void NumPressed();
    void printScores();
    void on_ExitButton_clicked();
    void on_NextWind_clicked();
    void on_AddButton_clicked();
    void on_TransferButton_clicked();
    void on_SubmitButton_clicked();
};
