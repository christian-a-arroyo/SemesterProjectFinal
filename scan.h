#ifndef SCAN_H
#define SCAN_H
#include <QDialog>
#include <QMovie>
#include <results.h>

namespace Ui {
class Scan;
}

class Scan : public QDialog
{
    Q_OBJECT

public:
    explicit Scan(QWidget *parent = nullptr);
    ~Scan();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::Scan *ui;
    QMovie *movie = new QMovie(":/img/img/ajax_loader.gif");
    results *frame;
};

#endif // SCAN_H
