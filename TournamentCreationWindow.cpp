#include "TournamentCreationWindow.h"
#include "ui_TournamentCreationWindow.h"
#include "FileReader.h"
/**
 * @brief Konstruktor klasy TournamentCreationWindow.
 *
 * @param parent Wskaźnik na obiekt QWidget reprezentujący rodzica okna.
 * @param clubsContainer Obiekt klasy ClubsContainer przechowujący informacje o klubach.
 */
TournamentCreationWindow::TournamentCreationWindow(QWidget *parent,string clubsFile):
    QDialog(parent),
    ui(new Ui::TournamentCreationWindow)
{
    QFont f;
    f.setFamily("Champions");
    std::vector<std::vector<std::string>> vector3 = FileReader::readFile(clubsFile);
    f.setPointSize(12);
    ui->setupUi(this);
    this->size = 0;
    this->clubs = new ClubsContainer(vector3);;
    unordered_map<int,Club*> clubsMap = this->clubs->getClubs();
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
/**
 * @brief Destruktor klasy TournamentCreationWindow.
 */
TournamentCreationWindow::~TournamentCreationWindow(){
    int itemCount = ui->listWidget->count();

    for (int i = 0; i < itemCount; ++i) {
        delete ui->listWidget->item(i);
    }
    delete ui->listWidget;
    delete this->clubs;
    delete ui;
}
/**
 * @brief Metoda zwracająca wektor identyfikatorów klubów biorących udział w rozgrywkach.
 *
 * @return Wektor identyfikatorów klubów.
 */
vector<int> TournamentCreationWindow::getIds(){
    return this->ids;
}
/**
 * @brief Slot obsługujący kliknięcie przycisku AddButton.
 */
void TournamentCreationWindow::on_AddButton_clicked()
{
    if(this->size!=0 && this->ids.size()<(this->size-1) &&
            !ui->listWidget->selectedItems().isEmpty()){
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
    else if(this->ids.size()==0){
        cout<<"Pick tournament size first"<<endl;
    }
    else{
        cout<<"Pick club first"<<endl;
    }
}
/**
 * @brief Slot obsługujący kliknięcie przycisku SubmitButton.
 */
void TournamentCreationWindow::on_SubmitButton_clicked(){

    if(this->size==0){
        QString str = ui->comboBox->currentText();
        this->size = str.toInt();
    }
    else{
        cout<<"You have already picked tournament size"<<endl;
    }
}
/**
 * @brief Slot obsługujący kliknięcie przycisku ExitButton.
 */
void TournamentCreationWindow::on_ExitButton_clicked(){
    if(this->ids.size()==this->size-1){
        QApplication::quit();
    }
    else{
        cout<<"Pick clubs first"<<endl;
    }
}
