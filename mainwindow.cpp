#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>
#include <sys/stat.h>
#include <direct.h>
#include <QtCore/QThread>
#include <vector>
#include <filesystem>

QString inputTxt;
int i=0;
std::vector<std::string> foldername;
bool folderUse=true;
char Cpath[256];
std::string str(getcwd(Cpath,256));
QString cdPATH = QString::fromStdString(str);



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label_2->setText("Now Directory is  [ " + cdPATH + " ]");
}



MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_label_linkActivated(const QString &link)
{

}


void MainWindow::on_pushButton_clicked()
{
    if(i>0){
        if(inputTxt.toLocal8Bit().size()==0){
            ui->label->setText("Please Write folder name");
            goto END;
        }
        for (int var = 0; var < i; ++var) {
                if(foldername.at(var)==inputTxt.toLocal8Bit().constData()){
                folderUse  = false;
            }
        }
        if(folderUse){
            foldername.push_back(inputTxt.toLocal8Bit().constData());
        }
        else{
            ui->lineEdit->clear();
            ui->label->setText(inputTxt+"was already used");
            QThread::sleep(4);
            goto END;
        }

    }
    else{
        foldername.push_back(inputTxt.toLocal8Bit().constData());
    }
    if(folderUse){
        ui->label->setText(inputTxt);
            //foldername.at(i) = "./" + foldername.at(i);
        if(mkdir(foldername.at(i).c_str())==0){
            ui->pushButton->setText("complite");
            i++;
        }
    else{
            ui->pushButton->setText("error");
            ui->label->setText("Write folder name");
            QThread::sleep(4);
            ui->pushButton->setText("Write to push here");
        }
    }
    END:
    return;
}


void MainWindow::on_lineEdit_textEdited(const QString &arg1)
{
    inputTxt = ui->lineEdit->text();
}

void MainWindow::on_label_2_linkActivated(const QString &link)
{
}

