#include "TournamentCreationWindow.h"
#include "ui_TournamentCreationWindow.h"

TournamentCreationWindow::TournamentCreationWindow(QWidget *parent,ClubsContainer& clubsContainer):
    QDialog(parent),
    ui(new Ui::TournamentCreationWindow)
{
    QFont f;
    f.setFamily("Champions");
    f.setPointSize(12);
    ui->setupUi(this);
    this->size = 0;
    this->clubs=&clubsContainer;
    unordered_map<int,Club*> clubsMap = clubsContainer.getClubs();
    unordered_map<int, Club*>::iterator it
            = clubsMap.begin();
    vector<QListWidgetItem*> items;
    while (it != clubsMap.end()) {
        items.push_back(new QListWidgetItem(QString::fromStdString(it->second->getName())));
           it++;
       }
    for(QListWidgetItem* item: items){
      item->setTextAlignment(Qt::AlignCenter);
      item->setBackground(QColor(	0,	0,	153));
      item->setFont(f);
      ui->listWidget->addItem(item);
    }
}

TournamentCreationWindow::~TournamentCreationWindow(){
    int itemCount = ui->listWidget->count();

    for (int i = 0; i < itemCount; ++i) {
        delete ui->listWidget->item(i);
    }
    delete ui->listWidget;
    delete ui;
}
vector<int> TournamentCreationWindow::getIds(){
    return this->ids;
}
void TournamentCreationWindow::on_AddButton_clicked()
{
    if(this->size!=0 && this->ids.size()<(this->size-1)){
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
    else if(this->ids.size()==(this->size-1)&& this->size!=0){
        cout<<"You have already enough clubs"<<endl;
    }
    else{
        cout<<"Pick tournament size first"<<endl;
    }
}
void TournamentCreationWindow::on_SubmitButton_clicked(){

    if(this->size==0){
        QString str = ui->comboBox->currentText();
        this->size = str.toInt();
    }
}
void TournamentCreationWindow::on_ExitButton_clicked(){
    QApplication::quit();
}
