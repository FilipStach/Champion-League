#include "MenagerWindow.h"
#include "ui_MenagerWindow.h"
#include <string>
#include "MenagerWindow.h"
#include <QFile>
MenagerWindow::MenagerWindow(QWidget *parent,vector<Match*> lastRoundScores):
    QMainWindow(parent),
    ui(new Ui::MenagerWindow),
    Scores(lastRoundScores)
{
    ui->setupUi(this);
    QPushButton *numButtons[2];
    int i =0;
    QString butName = "Button" + QString::number(i);
    numButtons[i] = MenagerWindow::findChild<QPushButton *>(butName);
    connect(numButtons[i], SIGNAL(released()), this,
            SLOT(printScores()));
}
MenagerWindow::MenagerWindow(QWidget *parent,ChampionsLeague& tournament, MyClub& myClub):
    QMainWindow(parent),
    ui(new Ui::MenagerWindow),
    myClub(&myClub),
    tournament(&tournament)
{
    ui->setupUi(this);
    this->recovery = false;
    unordered_map<int, Footballer*>::iterator it
            = myClub.getSquad().begin();
    vector<Footballer*> items;
    int i = 0;
    ui->playersTable->setColumnWidth(0,100);
    ui->playersTable->setColumnWidth(1,120);
    ui->playersTable->setColumnWidth(2,120);
    ui->playersTable->setColumnWidth(3,20);
    ui->playersTable->setColumnWidth(4,20);
    while (it != myClub.getSquad().end()) {
        cout<<it->second->getName()<<endl;
        items.push_back(it->second);
           it++;
       }
    for(Footballer* player : items){
        ui->playersTable->setRowHeight(i,40);
        QTableWidgetItem* item1= new QTableWidgetItem(QString::fromStdString(player->getPosition()));
        item1->setTextAlignment(Qt::AlignCenter);
        QTableWidgetItem* item2= new QTableWidgetItem(QString::fromStdString(player->getName()));
        item2->setTextAlignment(Qt::AlignCenter);
        QTableWidgetItem* item3= new QTableWidgetItem(QString::fromStdString(player->getSurrname()));
        item3->setTextAlignment(Qt::AlignCenter);
        QTableWidgetItem* item4= new QTableWidgetItem(QString::fromStdString(to_string(player->getStamina())));
        item4->setTextAlignment(Qt::AlignCenter);
        QTableWidgetItem* item5= new QTableWidgetItem(QString::fromStdString(to_string(player->getId())));
        item4->setTextAlignment(Qt::AlignCenter);
        ui->playersTable->setItem(i,0,item1);
        ui->playersTable->setItem(i,1,item2);
        ui->playersTable->setItem(i,2,item3);
        ui->playersTable->setItem(i,3,item4);
        ui->playersTable->setItem(i,4,item4);
        i++;

    }
//    connect(ui->playersTable, &QTableWidget::itemClicked, this, &MenagerWindow::on_playersTableItem_clicked);
}

MenagerWindow::~MenagerWindow(){
    for(int row = 0;row<ui->tableWidget->rowCount();row++){
        delete ui->tableWidget->item(row,0);
        delete ui->tableWidget->item(row,1);
        delete ui->tableWidget->item(row,2);
    }


    delete ui->tableWidget;
    delete ui;
}

void MenagerWindow::printScores(){
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
//           item3->setForeground(QBrush(QColor(255, 0, 0, 127)));
//           item1->setForeground(QBrush(QColor(0, 0, 255, 127)));
           item3->setTextAlignment(Qt::AlignCenter);
           ui->tableWidget->setItem(i,0,item1);
           ui->tableWidget->setItem(i,1,item2);
           ui->tableWidget->setItem(i,2,item3);
           i++;

       }
}


void MenagerWindow::on_ExitButton_clicked()
{
    QApplication::quit();
}



void MenagerWindow::on_RecoveryButton_clicked()
{
    cout<<"Pick player for recovery"<<endl;
    this->recovery = true;
}


void MenagerWindow::on_playersTable_cellClicked(int row, int column)
{
    if(this->recovery){
        int id = ui->playersTable->item(row,4)->text().toInt();
        this->myClub->recovery(id);
    }
    else{
        cout<<"Recovery is unactive"<<endl;
    }
}

