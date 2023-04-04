#include "ScoreTable.h"
#include "ui_mainwindow.h"
#include <string>
ScoreTable::ScoreTable(QWidget *parent,vector<Match*> lastRoundScores):
    QMainWindow(parent),
    ui(new Ui::MainUi),
    Scores(lastRoundScores)
{
    ui->setupUi(this);
    QPixmap bkgnd("/home/user/Pictures/background.png");
        bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
        QPalette palette;
        palette.setBrush(QPalette::Background, bkgnd);
        this->setPalette(palette);
    QPushButton *numButtons[2];

        // Cycle through locating the buttons
        for(int i = 0; i < 1; ++i){
//            QString butName = "Button" + QString::number(i);

//            // Get the buttons by name and add to array
//            numButtons[i] = ScoreTable::findChild<QPushButton *>(butName);

//            // When the button is released call num_pressed()
//            connect(numButtons[i], SIGNAL(released()), this,
//                    SLOT(NumPressed()));
            QString butName = "Button" + QString::number(i);

            numButtons[i] = ScoreTable::findChild<QPushButton *>(butName);
//            QTableWidget* table = ScoreTable::findChild<QTableWidget *>("Table");
//                    table->setRowCount(3);
            connect(numButtons[i], SIGNAL(released()), this,
                    SLOT(printScores()));
        }

}
ScoreTable::~ScoreTable(){
    delete ui;
}
void ScoreTable::NumPressed(){
//       QPushButton *button = (QPushButton *)sender();
//       QString butVal = button->text();
//       QString displayVal = ui->Display->text();
//       if((displayVal.toDouble() == 0) || (displayVal.toDouble() == 0.0)){
////           ui->Display->setText(butVal);
//       } else {
//           QString newVal = displayVal + butVal;
//           double dblNewVal = newVal.toDouble();
//           ui->Display->setText(QString::number(dblNewVal, 'g', 16));

//       }
}
void ScoreTable::printScores(){
//       ui->AttackingTeam1->setText(QString::fromStdString(this->Scores[0]->getAttackingTeam()));
//       ui->DeffendingTeam1->setText(QString::fromStdString(this->Scores[0]->getDeffendingTeam()));
//       ui->Score1->setText(QString::fromStdString(std::to_string(this->Scores[0]->getAttackingTeamGoals())+
//               ":"+std::to_string(this->Scores[0]->getDeffendingTeamGoals())));
       ui->tableWidget->setFixedHeight(this->Scores.size()*40+26);
       ui->tableWidget->setRowCount(this->Scores.size());
       ui->tableWidget->setColumnWidth(0,160);
       ui->tableWidget->setColumnWidth(2,160);
       ui->tableWidget->setColumnWidth(1,60);


       int i = 0;
       for(Match* match : this->Scores){
           ui->tableWidget->setRowHeight(i,40);
           QTableWidgetItem* item1= new QTableWidgetItem(QString::fromStdString(match->getAttackingTeam()));
           item1->setTextAlignment(Qt::AlignCenter);
           QTableWidgetItem* item2= new QTableWidgetItem(QString::fromStdString(std::to_string(match->getAttackingTeamGoals())+
                                  ":"+std::to_string(match->getDeffendingTeamGoals())));
           item2->setTextAlignment(Qt::AlignCenter);
           QTableWidgetItem* item3= new QTableWidgetItem(QString::fromStdString(match->getDeffendingTeam()));
           item3->setTextAlignment(Qt::AlignCenter);
           ui->tableWidget->setItem(i,0,item1);
           ui->tableWidget->setItem(i,1,item2);
           ui->tableWidget->setItem(i,2,item3);
           i++;

       }
}

