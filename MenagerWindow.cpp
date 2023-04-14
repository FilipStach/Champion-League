#include "MenagerWindow.h"
#include "ChampionsLeague.h"
#include "TrainingWindow.h"
#include "UpdateLineupWindow.h"
#include "ui_MenagerWindow.h"
#include <string>
#include "MenagerWindow.h"
#include <QFile>
#include "ResultWindow.h"
/**
@class MenagerWindow
@brief Konstruktor klasy MenagerWindow
Konstruktor klasy MenagerWindow tworzy interfejs graficzny aplikacji menadżera drużyny piłkarskiej.
@param parent wskaźnik na obiekt QWidget rodzica
@param tournament obiekt klasy ChampionsLeague
@param myClub obiekt klasy MyClub
*/
MenagerWindow::MenagerWindow(QWidget *parent,ChampionsLeague& tournament, MyClub& myClub):
    QMainWindow(parent),
    ui(new Ui::MenagerWindow)
{
    this->myClub = &myClub;
    this->tournament = &tournament;
    unordered_map<int,Footballer*> squad = this->myClub->getSquad();
    ui->setupUi(this);
    this->recovery = false;
    this->isActive = true;

    QTextOption center(Qt::AlignCenter);
    ui->trainingsBrowser->document()->setDefaultTextOption(center);
    ui->commandBox->document()->setDefaultTextOption(center);
    ui->trainingsBrowser->setText((QString::fromStdString(to_string(this->myClub->getTrainings()))));
    ui->commandBox->setText(QString::fromStdString(""));
    QTextCharFormat format;
    format.setFontPointSize(12);

    ui->commandBox->selectAll();
    ui->commandBox->mergeCurrentCharFormat(format);
    vector<Footballer*> items;
    int i = 0;
    ui->squadTable->setColumnWidth(0,100);
    ui->squadTable->setColumnWidth(1,120);
    ui->squadTable->setColumnWidth(2,120);
    ui->squadTable->setColumnWidth(3,80);
    ui->squadTable->setColumnWidth(4,40);
    unordered_map<int, Footballer*>::iterator it
            = squad.begin();
    while (it != squad.end()) {
        items.push_back(it->second);
           it++;
       }
    ui->squadTable->setRowCount(squad.size());
    ui->squadTable->setFixedHeight(squad.size()*40+26);
    ui->squadTable->setFixedWidth(477);
    for(Footballer* player : items){
        ui->squadTable->setRowHeight(i,40);
        QTableWidgetItem* item1= new QTableWidgetItem(QString::fromStdString(player->getPosition()));
        item1->setTextAlignment(Qt::AlignCenter);
        QTableWidgetItem* item2= new QTableWidgetItem(QString::fromStdString(player->getName()));
        item2->setTextAlignment(Qt::AlignCenter);
        QTableWidgetItem* item3= new QTableWidgetItem(QString::fromStdString(player->getSurrname()));
        item3->setTextAlignment(Qt::AlignCenter);
        QTableWidgetItem* item4= new QTableWidgetItem(QString::fromStdString(to_string(player->getStamina())));
        item4->setTextAlignment(Qt::AlignCenter);
        QTableWidgetItem* item5= new QTableWidgetItem(QString::fromStdString(to_string(player->getId())));
        item5->setTextAlignment(Qt::AlignCenter);
        ui->squadTable->setItem(i,0,item1);
        ui->squadTable->setItem(i,1,item2);
        ui->squadTable->setItem(i,2,item3);
        ui->squadTable->setItem(i,3,item4);
        ui->squadTable->setItem(i,4,item5);
        i++;

    }
}
/**
@brief Destruktor klasy MenagerWindow
*/
MenagerWindow::~MenagerWindow(){

    for(int row = 0;row<ui->squadTable->rowCount();row++){
        delete ui->squadTable->item(row,0);
        delete ui->squadTable->item(row,1);
        delete ui->squadTable->item(row,2);
        delete ui->squadTable->item(row,3);
        delete ui->squadTable->item(row,4);
    }

    delete ui->squadTable;
    delete ui;
}



/**
@brief slot wywoływany po kliknięciu przycisku ExitButton, który kończy działanie aplikacji
*/
void MenagerWindow::on_ExitButton_clicked()
{
    QApplication::quit();
}


/**
@brief slot wywoływany po kliknięciu przycisku RecoveryButton, który uruchamia regenerację
*/
void MenagerWindow::on_RecoveryButton_clicked()
{
    if(this->isActive&& this->myClub->getTrainings()>0){
        ui->commandBox->setText(QString::fromStdString("Pick player for recovery"));
        this->recovery = true;
    }
    else if(this->myClub->getTrainings()==0){
        ui->commandBox->setText(QString::fromStdString("No trainings left"));
    }
    else{
        ui->commandBox->setText(QString::fromStdString("Tournament ended"));
    }
}

/**
@brief slot wywoływany po kliknięciu elementu w tablicy Zawodników.
Wprowadza obsługę treningu "recovery" jeżeli taki został aktywowany.
*/
void MenagerWindow::on_squadTable_cellClicked(int row, int column)
{
    if(this->recovery){
        int id = ui->squadTable->item(row,4)->text().toInt();
        this->myClub->recovery(id);
        this->recovery=false;
        this->updateStamina();
        ui->trainingsBrowser->setText((QString::fromStdString(to_string(this->myClub->getTrainings()))));
        ui->commandBox->setText(QString::fromStdString("Training carried out"));

    }

}

/**
@brief slot wywoływany po kliknięciu przycisku NextRoundButton.
Uruchamia czynności związane z rozegraniem kolejnej rundy turnieju.
*/
void MenagerWindow::on_NextRoundButton_clicked()
{
    ui->commandBox->setText(QString::fromStdString(""));
    if(this->isActive){
        QWidget *parent = 0;
        this->tournament->playNextRound();
        this->updateStamina();
        ResultWindow resultWindow(parent, this->tournament->getlastRoundScores());
        resultWindow.setModal(true);
        resultWindow.show();
        resultWindow.exec();
        if(!this->tournament->getIsActive()){
            ui->commandBox->setText(QString::fromStdString("Your team lost"));
            this->isActive = false;
        }
        else if(this->tournament->getClubsSize()==1 && this->tournament->getIsActive()){
            ui->commandBox->setText(QString::fromStdString("Your team won tournament"));

            this->isActive = false;
        }

    }
    else{
        ui->commandBox->setText(QString::fromStdString("Tournament ended"));

    }

}

/**
@brief metoda wywoływany mająca za zadanie odświeżyć kolumnę
wytrzymałości w tablicy składu.
*/
void MenagerWindow::updateStamina(){
    unordered_map<int,Footballer*> squad = this->myClub->getSquad();
        vector<Footballer*> items;
        int i = 0;
        unordered_map<int, Footballer*>::iterator it
                = squad.begin();
        while (it != squad.end()) {
            items.push_back(it->second);
               it++;
           }
        for(Footballer* player : items){
            ui->squadTable->item(i,3)->setText(QString::fromStdString(to_string(player->getStamina())));
            i++;
        }
}

/**
@brief slot wywoływany po kliknięciu przycisku PickLineupButton.
Tworzy i uruchamia okno wyboru składu.
*/
void MenagerWindow::on_PickLineupButton_clicked()
{
    ui->commandBox->setText(QString::fromStdString(""));
    if(this->isActive){
        QWidget *parent = 0;
        UpdateLineupWindow updateLineupWindow(parent, *this->myClub);
        updateLineupWindow.setModal(true);
        updateLineupWindow.show();
        updateLineupWindow.exec();
        if(updateLineupWindow.getIds().size()>0){
            this->myClub->pickLineUp(updateLineupWindow.getIds());
            ui->commandBox->setText(QString::fromStdString("Lineup updated"));
        }


    }
    else{

        ui->commandBox->setText(QString::fromStdString("Tournament ended"));
    }
}

/**
@brief slot wywoływany po kliknięciu przycisku SkillTrainingButton.
Tworzy i uruchamia okno treningu umiejętności.
*/
void MenagerWindow::on_SkillTrainingButton_clicked()
{
    ui->commandBox->setText(QString::fromStdString(""));
    if(this->isActive && this->myClub->getTrainings()>0){
        QWidget *parent = 0;
        TrainingWindow trainingWindow(parent, *this->myClub);
        trainingWindow.setModal(true);
        trainingWindow.show();
        trainingWindow.exec();
        this->updateStamina();
        ui->trainingsBrowser->setText((QString::fromStdString(to_string(this->myClub->getTrainings()))));
        ui->commandBox->setText(QString::fromStdString("Training ended"));
    }
    else if(this->myClub->getTrainings()==0){
        ui->commandBox->setText(QString::fromStdString("No trainings left"));
    }
    else{
        ui->commandBox->setText(QString::fromStdString("Tournament ended"));
    }
}

