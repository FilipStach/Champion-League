#include "TransferDialog.h"

#include "ui_TransferDialog.h"

TransferDialog::TransferDialog(QWidget *parent,PlayersContainer& playersContainer, CoachesContainer& coachesContainer,int budget) :
    QDialog(parent),
    ui(new Ui::TransferDialog)

{
    this->coachId=0;
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
}

TransferDialog::~TransferDialog()
{
    delete ui;
}
void TransferDialog::onTableItemClicked(){
    int row =ui->coachesTable->currentItem()->row();
    ui->coachesTable->item(row,0)->setBackground(Qt::blue);
    ui->coachesTable->item(row,1)->setBackground(Qt::blue);
    ui->coachesTable->item(row,2)->setBackground(Qt::blue);
}
void TransferDialog::on_buyButton_clicked()
{
   if(coachId == 0){
       int row = ui->coachesTable->currentItem()->row();
       this->budget -= ui->coachesTable->item(row,2)->text().toInt();
       ui->budgetBrowser->setText(QString::fromStdString(to_string(budget)));
       ui->coachesTable->item(row,0)->setBackground(Qt::red);
       ui->coachesTable->item(row,1)->setBackground(Qt::red);
       ui->coachesTable->item(row,2)->setBackground(Qt::red);
       this->coachId = this->coaches->returnId((ui->coachesTable->item(row,0)->text().toStdString()));
   }
   else{
       cout<<"You have alread bought coach, go to players transfer now"<<endl;
   }
}


void TransferDialog::on_ExitButton_clicked()
{
        QApplication::quit();
}


void TransferDialog::on_TransferButton_clicked()
{
    if(coachId!=0){
        ui->playersTable->show();
        ui->label_2->show();
        ui->coachesTable->hide();
        ui->TransferButton->hide();
        ui->label_3->hide();
        ui->playersTable->setColumnWidth(2,160);
        ui->playersTable->setColumnWidth(1,160);
        ui->playersTable->setColumnWidth(0,100);
        ui->playersTable->setColumnWidth(3,60);
        unordered_map<int,Coach*> playersMap = coaches->getElements();
        unordered_map<int, Coach*>::iterator it
                = playersMap.begin();
        vector<Coach*> items;
        while (it != playersMap.end()) {
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

    }
    else{
        cout<<"Buy coach first"<<endl;
    }
}

