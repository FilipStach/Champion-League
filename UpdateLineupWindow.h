#ifndef UPDATELINEUPWINDOW_H
#define UPDATELINEUPWINDOW_H

#include "MyClub.h"
#include <QDialog>

namespace Ui {
/**
@class UpdateLineupWindow
@brief Okno służące do aktualizacji składu drużyny. W oparciu o wybór użytkownika
dokonuje edycji parametru lineup obiektu klasy MyClub
*/
class UpdateLineupWindow;
}

class UpdateLineupWindow : public QDialog
{
    Q_OBJECT

public:
    UpdateLineupWindow(QWidget *parent, MyClub& myClub);
    ~UpdateLineupWindow();
    vector<int> getIds() const;

private slots:
    void on_pushButton_clicked();

    void on_squadTable_cellClicked(int row, int column);

private:
    Ui::UpdateLineupWindow *ui;
    MyClub* myClub;
    bool update;
    vector<int> ids;

};

#endif // UPDATELINEUPWINDOW_H
