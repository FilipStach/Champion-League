#ifndef TRANSFERDIALOG_H
#define TRANSFERDIALOG_H

#include "CoachesContainer.h"
#include "PlayersContainer.h"
#include <QDialog>
using namespace std;
/**TransferDialog
@class
@brief Klasa TransferDialog reprezentuje okno dialogowe służące do przeprowadzania transferów piłkarzy i trenerów.
Klasa umożliwia wybieranie piłkarzy i trenerów oraz przeprowadzanie transakcji kupna.
*/
namespace Ui {
class TransferDialog;
}

class TransferDialog : public QDialog
{
    Q_OBJECT

public:
    TransferDialog(QWidget *parent, PlayersContainer& playersContainer, CoachesContainer& coachesContainer, int budget);
    ~TransferDialog();
    vector<int> getIds() const;
    int getCoachId();

private slots:


    void on_buyButton_clicked();
    void onTableItemClicked();
    void onPlayersTableItemClicked();

    void on_TransferButton_clicked();

    void on_ExitButton_clicked();

private:
    Ui::TransferDialog *ui;
    vector<int> ids;
    int coachId;
    PlayersContainer* players;
    CoachesContainer* coaches;
    int budget;
};

#endif // TRANSFERDIALOG_H
