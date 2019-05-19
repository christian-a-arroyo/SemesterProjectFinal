#ifndef PREREQUISITE_H
#define PREREQUISITE_H

#include <QDialog>
#include "info.h"
#include "walkthrough.h"
#include "scan.h"

namespace Ui {
class prerequisite;
}

class prerequisite : public QDialog
{
    Q_OBJECT

public:
    explicit prerequisite(QWidget *parent = nullptr);
    ~prerequisite();

private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::prerequisite *ui;
    info *frame;
    walkthrough *frame2;
    Scan *frame3;
};

#endif // PREREQUISITE_H
