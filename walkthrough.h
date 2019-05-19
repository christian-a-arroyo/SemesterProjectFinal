#ifndef WALKTHROUGH_H
#define WALKTHROUGH_H

#include <QDialog>

namespace Ui {
class walkthrough;
}

class walkthrough : public QDialog
{
    Q_OBJECT

public:
    explicit walkthrough(QWidget *parent = nullptr,QString img ="", QString text = "");
    ~walkthrough();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::walkthrough *ui;
};

#endif // WALKTHROUGH_H
