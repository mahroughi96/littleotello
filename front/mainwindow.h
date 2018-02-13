#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
#include <vector>
#include <QPushButton>
#include <QLabel>

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT /////////???

public:
    explicit MainWindow(QWidget *parent = 0);
    void mouseMoveEvent(QMouseEvent* event);
    ~MainWindow();
    vector<QPushButton *> mapp[8];
    vector<QLabel *> counter;
    void update();
    void getmap();

private slots:
    void handleButton1();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
