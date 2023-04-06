#ifndef MENAGERWINDOW_H
#define MENAGERWINDOW_H

#include <QDialog>

namespace Ui {
class MenagerWindow;
}

class MenagerWindow : public QDialog
{
    Q_OBJECT

public:
    explicit MenagerWindow(QWidget *parent = nullptr);
    ~MenagerWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MenagerWindow *ui;
};

#endif // MENAGERWINDOW_H
