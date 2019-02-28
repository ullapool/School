#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QKeyEvent>
#include <QString>
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    refreshWord();
    refreshNumbersOfFailures();
    // ui->background->setPixmap(QPixmap(QString::fromUtf8(":/background/Hangman12.png")));

}
void MainWindow::keyPressEvent(QKeyEvent *event){
    int numberOfFailures = getNumberOfFailures();
    if( numberOfFailures == 11){
        return;
    }

    QString input = event->text().toLower();
    if(!input.isEmpty()){
        keyStrokes.append(input);
        refreshWord();
        refreshNumbersOfFailures();
        std::cout <<"Key: "<< input.toStdString()<<std::endl;
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::getNumberOfFailures(){
    int numberOfFailures = 0;
    for(QString key : keyStrokes){
        if(!guessWord.contains(key.at(0))){
            numberOfFailures++;
        }
    }
    return numberOfFailures;
}
void MainWindow::refreshNumbersOfFailures(){
    int numberOfFailures = getNumberOfFailures();
    ui->faults->setText(QString::number(numberOfFailures));

    //refresh image

    QVector <QString> image ={
        ":/background/Hangman01.png",
        ":/background/Hangman02.png",
        ":/background/Hangman03.png",
        ":/background/Hangman04.png",
        ":/background/Hangman05.png",
        ":/background/Hangman06.png",
        ":/background/Hangman07.png",
        ":/background/Hangman08.png",
        ":/background/Hangman09.png",
        ":/background/Hangman10.png",
        ":/background/Hangman11.png",
        ":/background/Hangman12.png"
    };
    ui->background->setPixmap(QPixmap(image.at(numberOfFailures)));
}

void MainWindow::refreshWord(){

    int numberOfFailures = getNumberOfFailures();
    QString output = "";
    for(int i = 0; i < guessWord.length(); i++){
        if(i != 0){
            output+=" ";
        }
        if(numberOfFailures == 11 || keyStrokes.contains(QString(guessWord[i]))){
           output +=guessWord[i];
        }
        else {
            output+="_";
        }

    }
    ui->word->setText(output);
}
