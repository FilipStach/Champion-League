#include "UpdateLineupWindow.h"
#include "ui_UpdateLineupWindow.h"
#include <algorithm>
#include <iostream>
UpdateLineupWindow::UpdateLineupWindow(QWidget *parent, MyClub& myClub) :
    QDialog(parent),
    ui(new Ui::UpdateLineupWindow)
{

    ui->setupUi(this);
    this->update = false;
    this->myClub = &myClub;
    unordered_map<int,Footballer*> squad = this->myClub->getSquad();
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
    unordered_map<int,Footballer*> lineup = this->myClub->getLineup();
    i = 0;
    ui->lineupTable->setColumnWidth(0,100);
    ui->lineupTable->setColumnWidth(1,120);
    ui->lineupTable->setColumnWidth(2,120);
    ui->lineupTable->setColumnWidth(3,80);
    ui->lineupTable->setColumnWidth(4,40);
    it = lineup.begin();
    items.clear();
    while (it != lineup.end()) {
        items.push_back(it->second);
           it++;
       }
    ui->lineupTable->setRowCount(lineup.size());
    ui->lineupTable->setFixedHeight(lineup.size()*40+26);
    ui->lineupTable->setFixedWidth(477);
    for(Footballer* player : items){
        ui->lineupTable->setRowHeight(i,40);
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
        ui->lineupTable->setItem(i,0,item1);
        ui->lineupTable->setItem(i,1,item2);
        ui->lineupTable->setItem(i,2,item3);
        ui->lineupTable->setItem(i,3,item4);
        ui->lineupTable->setItem(i,4,item5);
        i++;
    }


}

UpdateLineupWindow::~UpdateLineupWindow()
{
    for(int row = 0;row<ui->squadTable->rowCount();row++){
        delete ui->squadTable->item(row,0);
        delete ui->squadTable->item(row,1);
        delete ui->squadTable->item(row,2);
        delete ui->squadTable->item(row,3);
        delete ui->squadTable->item(row,4);
    }
    for(int row = 0;row<ui->lineupTable->rowCount();row++){
        delete ui->lineupTable->item(row,0);
        delete ui->lineupTable->item(row,1);
        delete ui->lineupTable->item(row,2);
        delete ui->lineupTable->item(row,3);
        delete ui->lineupTable->item(row,4);
    }
    delete ui->lineupTable;
    delete ui->squadTable;
    delete ui;
}

void UpdateLineupWindow::on_pushButton_clicked()
{
    this->update = true;
    this->ids.clear();
}


void UpdateLineupWindow::on_squadTable_cellClicked(int row, int column)
{
    int id = ui->squadTable->item(row,4)->text().toInt();
    if(this->update && std::find(ids.begin(), ids.end(), id) == ids.end()&&
            this->ids.size()<4){
        this->ids.push_back(id);
        cout<<"Player picked"<<endl;
    }
    else{
        cout<<"First press updateKey"<<endl;
    }
}
vector<int> UpdateLineupWindow::getIds() const{
    return this->ids;
}
