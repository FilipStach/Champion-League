#include "TransferDialog.h"
#include <algorithm>
#include "ui_TransferDialog.h"

TransferDialog::TransferDialog(QWidget *parent,PlayersContainer& playersContainer, CoachesContainer& coachesContainer,int budget) :
    QDialog(parent),
    ui(new Ui::TransferDialog)

{
    this->coachId=1;
    this->coaches=&coachesContainer;
    this->players=&playersContainer;
    ui->setupUi(this);
    ui->playersTable->hide();
    ui->label_2->hide();
    QTextCursor cursor = ui->budgetBrowser->textCursor();
    QTextOption center(Qt::AlignCenter);
    ui->budgetBrowser->document()->setDefaultTextOption(center);
    ui->budgetBrowser->setText(QString::fromStdString(to_string(budget)));
    this->budget = budget;
//    ui->textBrowser->setTextAlignment(Qt::AlignCenter);
    if(this->coaches->getElements().size()*40+26>400){
        ui->coachesTable->setFixedHeight(400);
    }
    else{
        ui->coachesTable->setFixedHeight(this->coaches->getElements().size()*40+26);
    }
    ui->coachesTable->setRowCount(this->coaches->getElements().size());
    ui->coachesTable->setColumnWidth(0,160);
    ui->coachesTable->setColumnWidth(1,160);
    ui->coachesTable->setColumnWidth(2,100);


    int i = 0;
    unordered_map<int,Coach*> coachesMap = coaches->getElements();
    unordered_map<int, Coach*>::iterator it
            = coachesMap.begin();
    vector<Coach*> items;
    while (it != coachesMap.end()) {
        items.push_back(it->second);
           it++;
       }
    for(Coach* coach : items){
        ui->coachesTable->setRowHeight(i,40);
        QTableWidgetItem* item1= new QTableWidgetItem(QString::fromStdString(coach->getName()));
        item1->setTextAlignment(Qt::AlignCenter);
        QTableWidgetItem* item2= new QTableWidgetItem(QString::fromStdString(coach->getTactics()));
        item2->setTextAlignment(Qt::AlignCenter);
        QTableWidgetItem* item3= new QTableWidgetItem(QString::fromStdString(to_string(coach->getValue())));
        item3->setTextAlignment(Qt::AlignCenter);
        ui->coachesTable->setItem(i,0,item1);
        ui->coachesTable->setItem(i,1,item2);
        ui->coachesTable->setItem(i,2,item3);
        i++;

    }
    connect(ui->coachesTable, &QTableWidget::itemClicked, this, &TransferDialog::onTableItemClicked);
    connect(ui->playersTable, &QTableWidget::itemClicked, this, &TransferDialog::onPlayersTableItemClicked);

}

TransferDialog::~TransferDialog()
{
    for(int row = 0;row<ui->coachesTable->rowCount();row++){
        delete ui->coachesTable->item(row,0);
        delete ui->coachesTable->item(row,1);
        delete ui->coachesTable->item(row,2);
    }
    delete ui->coachesTable;
    if(coachId!=1){
        for(int row = 0;row<ui->playersTable->rowCount();row++){
            delete ui->playersTable->item(row,0);
            delete ui->playersTable->item(row,1);
            delete ui->playersTable->item(row,2);
            delete ui->playersTable->item(row,3);
        }
        delete ui->playersTable;
    }
    delete ui;
}
void TransferDialog::onTableItemClicked(){
    int row =ui->coachesTable->currentItem()->row();
    ui->coachesTable->item(row,0)->setBackground(Qt::blue);
    ui->coachesTable->item(row,1)->setBackground(Qt::blue);
    ui->coachesTable->item(row,2)->setBackground(Qt::blue);
}
void TransferDialog::onPlayersTableItemClicked(){
    int row =ui->playersTable->currentItem()->row();
    ui->playersTable->item(row,0)->setBackground(Qt::blue);
    ui->playersTable->item(row,1)->setBackground(Qt::blue);
    ui->playersTable->item(row,2)->setBackground(Qt::blue);
    ui->playersTable->item(row,3)->setBackground(Qt::blue);
}
void TransferDialog::on_buyButton_clicked()
{
   if(coachId == 1){
       int row = ui->coachesTable->currentItem()->row();
       this->budget -= ui->coachesTable->item(row,2)->text().toInt();
       ui->budgetBrowser->setText(QString::fromStdString(to_string(budget)));
       ui->coachesTable->item(row,0)->setBackground(Qt::red);
       ui->coachesTable->item(row,1)->setBackground(Qt::red);
       ui->coachesTable->item(row,2)->setBackground(Qt::red);
       this->coachId = this->coaches->returnId((ui->coachesTable->item(row,0)->text().toStdString()));
   }
//   else if(coachId != 1 && ui->playersTable.){
//       cout<<"You have alread bought coach, go to players transfer now"<<endl;
//   }
      else{
            if(ui->playersTable->isHidden()==true){
               cout<<"You have alread bought coach, go to players transfer now"<<endl;
            }
            else{
                int row = ui->playersTable->currentItem()->row();
                int id = this->players->returnId((ui->playersTable->item(row,1)->text().toStdString()),
                                                 ui->playersTable->item(row,2)->text().toStdString());
                if(std::find(this->ids.begin(),this->ids.end(), id )== this->ids.end() &&
                        this->budget>=ui->playersTable->item(row,3)->text().toInt()){
                    this->budget -= ui->playersTable->item(row,3)->text().toInt();
                    ui->budgetBrowser->setText(QString::fromStdString(to_string(budget)));
                    ui->playersTable->item(row,0)->setBackground(Qt::red);
                    ui->playersTable->item(row,1)->setBackground(Qt::red);
                    ui->playersTable->item(row,2)->setBackground(Qt::red);
                    ui->playersTable->item(row,3)->setBackground(Qt::red);
                    this->ids.push_back(id);
                    if(this->players->getMinPrice()>this->budget&& this->ids.size()!=6){
                        cout<<"You dont have enough money for other players,"
                              " academy youths will be added"<<endl;
                        QApplication::quit();
                    }
                    else if(this->ids.size()==6){
                        cout<<"You have enough players"<<endl;
                        QApplication::quit();
                    }
                }
                else if(std::find(this->ids.begin(),this->ids.end(), id )!= this->ids.end()){
                    cout << "You have already bought this player"<<endl;
                }
                else{
                    cout<< "You dont have money for this player"<<endl;
                }
            }
      }
}


void TransferDialog::on_ExitButton_clicked()
{
    if(coachId!= 1){
        QApplication::quit();
    }
    else{
        cout<<"Pick coach first"<<endl;
    }
}


void TransferDialog::on_TransferButton_clicked()
{
    if(coachId!=1){
        ui->playersTable->show();
        ui->label_2->show();
        ui->coachesTable->hide();
        ui->TransferButton->hide();
        ui->label_3->hide();
        ui->playersTable->setColumnWidth(2,160);
        ui->playersTable->setColumnWidth(1,160);
        ui->playersTable->setColumnWidth(0,100);
        ui->playersTable->setColumnWidth(3,60);
        int i = 0;
        string position;
        unordered_map<int,Footballer*> playersMap = players->getElements();
        ui->playersTable->setRowCount(this->players->getElements().size());
        unordered_map<int, Footballer*>::iterator it
                = playersMap.begin();
        vector<Footballer*> items;
        while (it != playersMap.end()) {
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
            QTableWidgetItem* item4= new QTableWidgetItem(QString::fromStdString(to_string(player->getValue())));
            item4->setTextAlignment(Qt::AlignCenter);
            ui->playersTable->setItem(i,0,item1);
            ui->playersTable->setItem(i,1,item2);
            ui->playersTable->setItem(i,2,item3);
            ui->playersTable->setItem(i,3,item4);
            i++;

        }

    }
    else{
        cout<<"Buy coach first"<<endl;
    }
}
int TransferDialog::getCoachId(){
    return this->coachId;
}
vector<int> TransferDialog::getIds() const{
    return this->ids;
}

