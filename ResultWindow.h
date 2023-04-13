#pragma once

#include "Match.h"
#include <QDialog>
/**
@class ResultWindow
@brief Klasa ResultWindow reprezentuje interfejs graficzny wyświetlający wyniki ostatniej rundy rozgrywek Ligi Mistrzów.
Klasa zawiera metody umożliwiające wyświetlanie wyników oraz ich formatowanie.
*/
namespace Ui {
class ResultWindow;
}

class ResultWindow : public QDialog
{
    Q_OBJECT

public:
    ResultWindow(QWidget *parent,vector<Match*> lastRoundScores);
    ~ResultWindow();

private:
    Ui::ResultWindow *ui;
    vector<Match*> Scores;
};

