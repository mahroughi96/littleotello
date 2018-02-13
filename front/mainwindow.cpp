#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QCursor>
#include <fstream>
#include <QPixmap>
#include <QIcon>
#include <unistd.h>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    for(int i = 0; i < 8 ; ++ i){
        for(int j = 0; j < 8; ++ j){
            mapp[i].push_back(new QPushButton("", this));
            mapp[i][j]->setGeometry(j*60, i*60, 60, 60);
            QObject::connect(mapp[i][j] , SIGNAL(clicked()), this , SLOT (handleButton1())); //cursor click
        }
    }
    counter.push_back(new QLabel("", this));
    counter.push_back(new QLabel("", this));
    counter.push_back(new QLabel("", this));
    counter.push_back(new QLabel("", this));
    counter[0]->setGeometry(20, 500, 95, 40);
    counter[0]->setText("Black:"); //black scoreboard
    counter[1]->setGeometry(135, 500, 95, 40);
    counter[1]->setNum(2);
    counter[2]->setGeometry(250, 500, 95, 40);
    counter[2]->setText("White:"); //white scoreboard
    counter[3]->setGeometry(365, 500, 95, 40);
    counter[3]->setNum(2);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mouseMoveEvent(QMouseEvent* event)
{
    return;
}



////takes the cursor coordinates
void MainWindow::handleButton1()
{
    ofstream myfile;
    myfile.open("/home/mahdis/Desktop/AP_project/data/data.txt");
    cout << "button pressed!!\n";
    int winX = this->mapFromGlobal(QCursor::pos()).x();
    int winY = this->mapFromGlobal(QCursor::pos()).y();
    cout << "x:\t" << winX/60;
    cout << "\ty:\t" << winY/60 << endl;
    myfile << winX/60 << "\t" << winY/60 << endl;
    myfile.close();
    getmap();
    sleep(1);
    getmap();
    sleep(1);
    getmap();
    sleep(1);
    getmap();
    sleep(1);
    return getmap();
}



/////reads the map and converts the graphics
void MainWindow::getmap()
{
    QPixmap pixmap0("/home/mahdis/Desktop/AP_project/icons/1.png");
    QPixmap pixmap1("/home/mahdis/Desktop/AP_project/icons/3.png");
    QPixmap pixmap2("/home/mahdis/Desktop/AP_project/icons/2.png");
    QPixmap pixmap3("/home/mahdis/Desktop/AP_project/icons/4.png");

    QIcon buttonIcon0(pixmap0);
    QIcon buttonIcon1(pixmap1);
    QIcon buttonIcon2(pixmap2);
    QIcon buttonIcon3(pixmap3);

    int a;


    ifstream myfile;
    myfile.open("/home/mahdis/Desktop/AP_project/data/map.txt");
    int blcount = 0;
    int wtcount = 0;
    if(myfile.is_open())
    {
        for(int i = 0; i < 8; ++i)
        {
            for(int j = 0; j < 8; ++j)
            {
                myfile >> a;
                if(a==0) mapp[i][j]->setIcon(buttonIcon0);
                if(a==-1)
                {
                    mapp[i][j]->setIcon(buttonIcon1);
                    blcount++;
                }
                if(a==1)
                {
                    mapp[i][j]->setIcon(buttonIcon2);
                    wtcount++;
                }
                if(a==3) mapp[i][j]->setIcon(buttonIcon3);
                mapp[i][j]->setIconSize(pixmap0.rect().size());
            }
        }
        myfile.close();
        counter[1]->setNum(blcount);
        counter[3]->setNum(wtcount);
    }
    return ;
}
