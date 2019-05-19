#include "prerequisite.h"
#include "ui_prerequisite.h"
#include "info.h"
#include "walkthrough.h"
#include "scan.h"
#include <QProcess>
#include <QDebug>

prerequisite::prerequisite(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::prerequisite)
{
    ui->setupUi(this);
    this->ui->checkBox->setAttribute(Qt::WA_TransparentForMouseEvents);
    this->ui->checkBox->setFocusPolicy(Qt::NoFocus);

    this->ui->checkBox_2->setAttribute(Qt::WA_TransparentForMouseEvents);
    this->ui->checkBox_2->setFocusPolicy(Qt::NoFocus);
}

prerequisite::~prerequisite()
{
    delete ui;
}
// Closes the program
void prerequisite::on_pushButton_4_clicked()
{
    this ->close();
}

//Checks to see if nmap and tshark are installed
void prerequisite::on_pushButton_3_clicked()
{
    //nmap
    QProcess process;
    QStringList params;
         params << "-V";
    process.start("nmap",params);
    process.waitForFinished(-1);
    QString output(process.readAllStandardOutput());
    if(output.contains("Nmap version")){
        ui->checkBox_2->click();
        //qDebug() << "nmap found";
    }

    //tshark
    QProcess process2;
    QStringList params2;
         params << "-v";
    process.start("\"C:\\Program Files\\Wireshark\\tshark.exe\"",params);
    process.waitForFinished(-1);
    QString output2(process.readAllStandardOutput());
    //qDebug() << output2;
    if(output2.contains("TShark (Wireshark")){
        ui->checkBox->click();
        //qDebug() << "nmap found";
    }

    if(ui->checkBox->checkState() == Qt::Checked){
        ui->pushButton_5->setEnabled(true);
    }
}

//Info for wireshark
void prerequisite::on_pushButton_7_clicked()
{
    frame = new info (this,":/img/img/wireshark.png","If you were to compare a home network to a town, then each device would be its own house and the router would be the post office. Everyone in the town is able to communicate with each other through mail which is picked up by the post office and sent to the recipient. The post office is also the town’s connection to other towns and will try its best to send mail receive mail for all the people in the town. Now Tshark in this analogy would be a silent onlooker in the post office. Depending on what you tell them to do they will silently keep track of all the mail coming in and out of the post office without any of the residents of the town knowing their mail has been looked at. Since everyone in town main source of communication is through the post office, then this person can check to see if any one house is talking to anybody they shouldn’t be. ");
    frame -> show();
}

//Info for nmap
void prerequisite::on_pushButton_6_clicked()
{
    frame = new info(this,":/img/img/nmap.png","If you were to compare a home network to a town, then each device would be its own house and the router would be the post office. Everyone in the town is able to communicate with each other through mail which is picked up by the post office and sent to the recipient. Nmap in this analogy would be a private investigator. You would hire his services and he will send out specifically crafted messages to everyone in the town that will when responded to give up information on them. It can find out how many homes are in the town, who at each house is currently sending mail, it can even check for flaws in each home.");
    frame ->show();
}

//Help Installing nmap
void prerequisite::on_pushButton_2_clicked()
{
    frame2 = new walkthrough(this,":/img/img/nmap/",":/text/text/nmap/");
    frame2 ->show();
}

//Help Installing Tshark
void prerequisite::on_pushButton_clicked()
{
    frame2 = new walkthrough(this,":/img/img/tshark/",":/text/text/tshark/");
    frame2 ->show();
}

//Generate Scan Frame
void prerequisite::on_pushButton_5_clicked()
{
    frame3 = new Scan();
    frame3 -> show();
    this-> hide();
}
