#include "TrainingWindow.h"
#include "ui_TrainingWindow.h"
#include <iostream>

TrainingWindow::TrainingWindow(QWidget *parent, MyClub& myClub) :
    QDialog(parent),
    ui(new Ui::TrainingWindow)
{
    this->myClub = &myClub;
    ui->setupUi(this);
    QTextCursor cursor = ui->trainingsBrowser->textCursor();
    QTextOption center(Qt::AlignCenter);
    ui->trainingsBrowser->document()->setDefaultTextOption(center);
    ui->trainingsBrowser->setText((QString::fromStdString(to_string(this->myClub->getTrainings()))));
    ui->squadTable->setColumnWidth(0,100);
    ui->squadTable->setColumnWidth(1,120);
    ui->squadTable->setColumnWidth(2,120);
    ui->squadTable->setColumnWidth(3,80);
    ui->squadTable->setColumnWidth(4,40);
    this->defaultTable();
}
TrainingWindow::~TrainingWindow()
{
    this->deleteTableItems();
    delete ui->squadTable;
    delete ui;
}
void TrainingWindow::deleteTableItems(){
    for(int row = 0;row<ui->squadTable->rowCount();row++){
        delete ui->squadTable->item(row,0);
        delete ui->squadTable->item(row,1);
        delete ui->squadTable->item(row,2);
        delete ui->squadTable->item(row,3);
        delete ui->squadTable->item(row,4);
    }
}
void TrainingWindow::defaultTable(){
    this->deleteTableItems();
    unordered_map<int,Footballer*> squad = this->myClub->getSquad();
    vector<Footballer*> items;
    int i = 0;
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
void TrainingWindow::updateTable(Abilities training){
    unordered_map<int,Footballer*> squad = this->myClub->getSquad();
    vector<Footballer*> items;
    int i = 0;
    this->deleteTableItems();
    if(training == REFLEX){
        unordered_map<int, Footballer*>::iterator it
                = squad.begin();
        while (it != squad.end()) {
            if(it->second->getPosition()=="GOALKEEPER"){
                items.push_back(it->second);
            }
               it++;
           }
    }
    else if(training == TACKLES){
        unordered_map<int, Footballer*>::iterator it
                = squad.begin();
        while (it != squad.end()) {
            if(it->second->getPosition()=="GOALKEEPER" ||
                    it->second->getPosition()=="DEFENDER"||
                    it->second->getPosition()=="MIDFIELDER"){
                items.push_back(it->second);
            }
               it++;
           }
    }
    else if(training == HEADERS){
        unordered_map<int, Footballer*>::iterator it
                = squad.begin();
        while (it != squad.end()) {
            if(it->second->getPosition()=="STRIKER" ||
                    it->second->getPosition()=="DEFENDER"){
                items.push_back(it->second);
            }
               it++;
           }
    }
    else if(training == PASSES){
        unordered_map<int, Footballer*>::iterator it
                = squad.begin();
        while (it != squad.end()) {
            if(it->second->getPosition()=="STRIKER" ||
                    it->second->getPosition()=="MIDFIELDER"){
                items.push_back(it->second);
            }
               it++;
           }
    }
    else if(training == SHOOTING){
        unordered_map<int, Footballer*>::iterator it
                = squad.begin();
        while (it != squad.end()) {
            if(it->second->getPosition()=="STRIKER"||
                    it->second->getPosition()=="MIDFIELDER"){
                items.push_back(it->second);
            }
               it++;
           }
    }
    else{
        cout<<"Wrong training name"<<endl;
    }
    ui->squadTable->setRowCount(items.size());
    ui->squadTable->setFixedHeight(items.size()*40+26);
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

void TrainingWindow::on_tackleButton_clicked()
{
    this->headersTraining = false;
    this->passesTraining = false;
    this->shootingTraining = false;
    this->reflexTraining = false;
    this->tackleTraining=true;
    this->updateTable(TACKLES);
}


void TrainingWindow::on_headersButton_clicked()
{
    this->tackleTraining  = false;
    this->passesTraining = false;
    this->shootingTraining = false;
    this->reflexTraining = false;
    this->headersTraining = true;
    this->updateTable(HEADERS);
}


void TrainingWindow::on_passesButton_clicked()
{
    this->headersTraining = false;
    this->tackleTraining  = false;
    this->shootingTraining = false;
    this->reflexTraining = false;
    this->passesTraining = true;
    this->updateTable(PASSES);
}


void TrainingWindow::on_shootingButton_clicked()
{
    this->headersTraining = false;
    this->tackleTraining  = false;
    this->passesTraining = false;
    this->reflexTraining = false;
    this->shootingTraining = true;
    this->updateTable(SHOOTING);
}


void TrainingWindow::on_reflexButton_clicked()
{
    this->headersTraining = false;
    this->tackleTraining  = false;
    this->passesTraining = false;
    this->shootingTraining = false;
    this->reflexTraining = true;
    this->updateTable(REFLEX);
}


void TrainingWindow::on_squadTable_cellClicked(int row, int column)
{
    if(this->myClub->getTrainings()>0){
        Abilities ability;
        int id = ui->squadTable->item(row,4)->text().toInt();
        if(this->headersTraining){
            ability = HEADERS;
        }
        else if(this->tackleTraining){
            ability = TACKLES;
        }
        else if(this->passesTraining){
            ability = PASSES;
        }
        else if(this->shootingTraining){
            ability = SHOOTING;
        }
        else if(this->reflexTraining){
            ability = REFLEX;
        }
        this->myClub->training(id,ability);
        this->headersTraining = false;
        this->tackleTraining  = false;
        this->passesTraining = false;
        this->shootingTraining = false;
        this->reflexTraining = false;
        ui->trainingsBrowser->setText((QString::fromStdString(to_string(this->myClub->getTrainings()))));
    }
    else{
        cout<<"You dont have enough trainings left"<<endl;
    }
}

