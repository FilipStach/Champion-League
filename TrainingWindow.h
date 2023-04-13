#ifndef TRAININGWINDOW_H
#define TRAININGWINDOW_H

#include "MyClub.h"
#include <QDialog>
/**

@brief Okno szkolenia piłkarzy
Klasa implementująca interfejs graficzny dla okna szkolenia piłkarzy.
Umożliwia wybór konkretnej umiejętności do treningu oraz przypisanie piłkarza do szkolenia.
*/
namespace Ui {
class TrainingWindow;
}

class TrainingWindow : public QDialog
{
    Q_OBJECT

public:
    TrainingWindow(QWidget *parent, MyClub& myClub);
    ~TrainingWindow();

private:
    Ui::TrainingWindow *ui;
    MyClub* myClub;
    bool tackleTraining = false;
    bool reflexTraining = false;
    bool headersTraining = false;
    bool passesTraining = false;
    bool shootingTraining = false;
private slots:
    void updateTable(Abilities training);
    void defaultTable();
    void deleteTableItems();
    void on_tackleButton_clicked();
    void on_headersButton_clicked();
    void on_passesButton_clicked();
    void on_shootingButton_clicked();
    void on_reflexButton_clicked();
    void on_squadTable_cellClicked(int row, int column);
};

#endif // TRAININGWINDOW_H
