#include "ResultWindow.h"
#include "ui_ResultWindow.h"

ResultWindow::ResultWindow(QWidget *parent,vector<Match*> lastRoundScores) :
    QDialog(parent),
    ui(new Ui::ResultWindow),
    Scores(lastRoundScores)
{
    ui->setupUi(this);
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
//           item3->setForeground(QBrush(QColor(255, 0, 0, 127)));
//           item1->setForeground(QBrush(QColor(0, 0, 255, 127)));
        item3->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->setItem(i,0,item1);
        ui->tableWidget->setItem(i,1,item2);
        ui->tableWidget->setItem(i,2,item3);
        i++;

    }
}

ResultWindow::~ResultWindow()
{
    for(int row = 0;row<ui->tableWidget->rowCount();row++){
        delete ui->tableWidget->item(row,0);
        delete ui->tableWidget->item(row,1);
        delete ui->tableWidget->item(row,2);
    }
    delete ui->tableWidget;
    delete ui;
}

