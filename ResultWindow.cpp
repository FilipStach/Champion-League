#include "ResultWindow.h"
#include "ui_ResultWindow.h"
#include <string>
#include "MenagerWindow.h"
ResultWindow::ResultWindow(QWidget *parent,vector<Match*> lastRoundScores):
    QMainWindow(parent),
    ui(new Ui::ResultWindow),
    Scores(lastRoundScores)
{
    ui->setupUi(this);
    QPushButton *numButtons[2];
    int i =0;
    QString butName = "Button" + QString::number(i);
    numButtons[i] = ResultWindow::findChild<QPushButton *>(butName);
    connect(numButtons[i], SIGNAL(released()), this,
            SLOT(printScores()));


}
ResultWindow::ResultWindow(QWidget *parent,ClubsContainer& clubsContainer):
    QMainWindow(parent),
    ui(new Ui::ResultWindow)
{
    ui->setupUi(this);
    this->size = 0;
    this->clubs=&clubsContainer;
    unordered_map<int,Club*> clubsMap = clubsContainer.getClubs();
    unordered_map<int, Club*>::iterator it
            = clubsMap.begin();
    vector<QListWidgetItem*> items;
    while (it != clubsMap.end()) {
        items.push_back(new QListWidgetItem(QString::fromStdString(it->second->getName())));
        cout<<it->second->getName()<<endl;
//        QListWidgetItem* item1 = new QListWidgetItem(QString::fromStdString(it->second->getName()));
//        ui->listWidget->addItem(item1);
           it++;
       }
    for(QListWidgetItem* item: items){
      item->setTextAlignment(Qt::AlignCenter);
      item->setBackground(QColor(	0,	0,	153));
      ui->listWidget->addItem(item);
    }
}
ResultWindow::~ResultWindow(){
    for(int row = 0;row<ui->tableWidget->rowCount();row++){
        delete ui->tableWidget->item(row,0);
        delete ui->tableWidget->item(row,1);
        delete ui->tableWidget->item(row,2);
    }
    delete ui->tableWidget;
    delete ui;
}
void ResultWindow::NumPressed(){
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
vector<int> ResultWindow::getIds(){
    return this->ids;
}
void ResultWindow::printScores(){
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


void ResultWindow::on_ExitButton_clicked()
{
    QApplication::quit();
}
void ResultWindow::on_NextWind_clicked()
{
    MenagerWindow menagerWindow;
    menagerWindow.setModal(true);
    menagerWindow.exec();
}
void ResultWindow::on_AddButton_clicked()
{
    if(this->size!=0 && this->ids.size()<this->size){
        bool contains = false;
        QListWidgetItem* item = ui->listWidget->currentItem();
        item->setBackground(QColor(255, 0, 0));
        int itemId = this->clubs->returnID(item->text().toStdString());
        for(int id : ids){
            if(itemId==id){
                contains = true;
                cout<<"Clubs already picked";
            }
        }
        if(!contains){
            ids.push_back(itemId);
        }
    }
    else if(this->ids.size()==this->size&& this->size!=0){
        cout<<"You have already enough items"<<endl;
    }
    else{
        cout<<"Pick tournament size first"<<endl;
    }
}
void ResultWindow::on_TransferButton_clicked(){

    QApplication::quit();
}
void ResultWindow::on_SubmitButton_clicked(){

    if(this->size==0){
        QString str = ui->comboBox->currentText();
        this->size = str.toInt();
    }
}

