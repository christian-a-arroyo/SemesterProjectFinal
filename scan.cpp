#include "scan.h"
#include "ui_scan.h"
#include <QProcess>
#include "results.h"


Scan::Scan(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Scan)
{
    ui->setupUi(this);
}

Scan::~Scan()
{
    delete ui;
}

void Scan::on_pushButton_3_clicked()
{
    this->close();
}

void Scan::on_pushButton_2_clicked()
{
    ui->pushButton_2->setEnabled(false);

    ui->label_2->setMovie(movie);
    movie->start();
    QProcess process;
    QStringList args;
    args << "-T4" <<"-A" <<"--script" <<"vuln" << "-oN"<< "output.txt" << "192.168.0.20";
    process.startDetached("nmap",args);

    //process.waitForFinished(-1);

    QString secOutput;

    //ui->label_2->setText("Completed!!!");

    ui->pushButton->setEnabled(true);
}

void Scan::on_pushButton_clicked()
{
    frame = new results();
    frame->show();
    this->hide();
}
