#include "mainwindow.h"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QMessageBox msgbox;


    MainWindow w;
    w.SetVersion(540,1,2);

    w.setWindowTitle("LirSync");
    w.setGeometry(QRect(500,250,400,300));
    w.SetNoResize();


    w.CreateStaticText("Static",80,25);
    w.CreateMenu();
    w.CreateButton("Inc",30,60,60,30);
    w.CreateButton("Dec",100,60,60,30);
    w.show();


    //msgbox.setText("hello");
   // msgbox.exec();

    return app.exec();
}
