#include "ScoreTable.h"
#include "ui_mainwindow.h"
ScoreTable::ScoreTable(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainUi)
{
    ui->setupUi(this);
    ui->Display->setText("Pogon Skwierzyna");
    QPushButton* button;
    QString butName = "Button1";
    button = ScoreTable::findChild<QPushButton*>(butName);
    connect(button, SIGNAL(realeased()),this,SLOT(NumPressed()));

}
ScoreTable::~ScoreTable(){
    delete ui;
}
void ScoreTable::NumPressed(){
    QPushButton *button = (QPushButton*) sender();
    QString butval = button->text();
    QString displayVal = ui->Display->text();
}
