#include "results.h"
#include "ui_results.h"
#include <QString>
#include "QFile"
#include "QTextStream"
#include "QDebug"

results::results(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::results)
{

    ui->setupUi(this);
    int count =0;

    QString temp2 = ":/text/text/scan.txt";

    QFile inputFile(temp2);
    if (inputFile.open(QIODevice::ReadOnly|QIODevice::Text))
    {
       QTextStream in(&inputFile);
       while (!in.atEnd())
       {
          QString line = in.readLine();
          QString label2 = "label_"+QString::number(count);
          if(line.contains("Nmap scan report for")){
              line.remove("Nmap scan report for");
              qDebug() << line;
              ui->label_0->setText(line);
          }
          if(line.contains("Nmap scan report for")){
              line.remove("Nmap scan report for");
              qDebug() << line;
              ui->label_0->setText(line);
          }
          count+=1;
       }
       inputFile.close();
    }
    else {
        qDebug()<<"file not opened";
    }
}

results::~results()
{
    delete ui;
}
