#include "mainwindow.h"
#include <QApplication>
#include <QtGui>
#include <iostream>
#include <vector>
#include <QMouseEvent>
#include <fstream>
#include <unistd.h>

using namespace std;

int a[8][8] = {{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,3,0,0,0,0},{0,0,3,2,1,0,0,0},{0,0,0,1,2,3,0,0},{0,0,0,0,3,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0}};
vector<QPushButton *> mapp[8];

void update(QWidget*, int[][8]);
void getmap();

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainWindow Main_Window;
    QPushButton Bu_Quit("Quit" , &Main_Window);
    QObject::connect(&Bu_Quit , SIGNAL(clicked()), qApp , SLOT(quit()));
    Bu_Quit.setGeometry(215,550,50,50);
    Main_Window.getmap();
    Main_Window.resize(480, 600);
    Main_Window.show();


    return app.exec();
}


////updates the UI
void update(QWidget *Main_Window, int board[][8])
{
    QPixmap pixmap0("/home/mahdis/Desktop/AP_project/icons/1.png");
    QPixmap pixmap1("/home/mahdis/Desktop/AP_project/icons/3.png");
    QPixmap pixmap2("/home/mahdis/Desktop/AP_project/icons/2.png");
    QPixmap pixmap3("/home/mahdis/Desktop/AP_project/icons/4.png");

    QIcon buttonIcon0(pixmap0);
    QIcon buttonIcon1(pixmap1);
    QIcon buttonIcon2(pixmap2);
    QIcon buttonIcon3(pixmap3);
    for(int i = 0; i < 8 ; ++ i){
        for(int j = 0; j < 8; ++ j){
            if(a[i][j]==0) mapp[i][j]->setIcon(buttonIcon0);
            if(a[i][j]==1) mapp[i][j]->setIcon(buttonIcon1);
            if(a[i][j]==-1) mapp[i][j]->setIcon(buttonIcon2);
            if(a[i][j]==3) mapp[i][j]->setIcon(buttonIcon3);
            mapp[i][j]->setGeometry(j*60, i*60, 60, 60);
            mapp[i][j]->setIconSize(pixmap0.rect().size());
        }
    }

    return;
}


////reads map file
void getmap()
{
    ifstream myfile;
    myfile.open("/home/mahdis/Desktop/AP_project/data/map.txt");
    if(myfile.is_open()){
        for(int i = 0; i < 8; ++i)
        {
            for(int j = 0; j < 8; ++j)
            {
                myfile >> a[i][j];
            }
        }
        myfile.close();
        ofstream myfile2;
        myfile2.open("/home/mahdis/Desktop/AP_project/data/map.txt");
        myfile2 << "\n";
        myfile2.close();
    }
    return;
}
