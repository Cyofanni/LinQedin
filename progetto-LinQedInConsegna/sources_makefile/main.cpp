#include "../headers/mainwindow.h"
#include <QApplication>
#include "../headers/start_widget.h"
#include <QRect>

int main(int argc,char* argv[]){
    QApplication a(argc,argv);
    StartWidget* start = new StartWidget;
    start->show();

    return a.exec();
}
