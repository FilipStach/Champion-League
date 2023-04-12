#pragma once

#include "Match.h"
#include <QDialog>

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

