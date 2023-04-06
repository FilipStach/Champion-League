#include "MenagerWindow.h"
#include "ui_MenagerWindow.h"
#include "ui_ResultWindow.h"
#include "ResultsWindow.h"
MenagerWindow::MenagerWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MenagerWindow)
{
    ui->setupUi(this);
}

MenagerWindow::~MenagerWindow()
{
    delete ui;
}

void MenagerWindow::on_pushButton_clicked()
{


}

