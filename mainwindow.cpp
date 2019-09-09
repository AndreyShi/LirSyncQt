#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include <windows.h>

MainWindow::CreateMenu()
{
    QAction *itemMenu;
    QMenuBar * mnu = new QMenuBar(this);
        QMenu * pMnu = new QMenu("Меню");
        QMenu * pMnu2 = new QMenu("Справка");
        pMnu->addAction("Настройки");
        pMnu->addAction("Тест соединения");
        pMnu->addAction("Редактор параметров");
        
        itemMenu = new QAction("Перекрывающее окно",this);        
        itemMenu->setCheckable(true);
        itemMenu->setChecked(true);
        pMnu->addAction(itemMenu);

        pMnu->addAction("Открыть текущую папку",this,SLOT(clickOpenFolder()),QKeySequence(tr("F12")));
        pMnu->addSeparator();
        pMnu->addAction("Выход",this,SLOT (clickMenuExit()));

        pMnu2->addAction("О программе...",this,SLOT(clickAboutitem()));


        mnu->setGeometry(QRect(0,0,130,21));
        mnu->addMenu(pMnu);
        mnu->addMenu(pMnu2);
        mnu->show();
        return 0;
}

MainWindow::CreateButton(QString name, int x, int y, int w, int h)
{
    QPushButton *but = new QPushButton(name,this);
   // but->setText(name);
    but->setGeometry(QRect(x,y,w,h));
    but->show();
    if(name == "Inc")
    connect(but, SIGNAL (released()), this, SLOT (clickincButton()));
    if(name == "Dec")
    connect(but, SIGNAL (released()), this, SLOT (clickdecButton()));

    return 0;
}

MainWindow::CreateStaticText(QString name, int x, int y)
{
    QPalette palette;
      palette.setColor(QPalette::Background, Qt::white);
      //palette.setBrush(QPalette::Background,QBrush(Qt::red));
      palette.setColor(QPalette::WindowText, Qt::blue);

    lbl = new QLabel(this);
    lbl->move(x,y);
    lbl->setText(name);
    lbl->setPalette(palette);
    lbl->setAutoFillBackground(true);
    lbl->show();
    return 0;
}

MainWindow::CreatePic(QString filename, int x, int y, int w, int h)
{

}



void MainWindow::SetNoResize()
{
    QSize sizec;
    sizec = size();
    setMinimumSize(sizec);
    setMaximumSize(sizec);
}



void MainWindow::SetNoResize(QDialog &ob)
{
    QSize sizec;
    sizec = ob.size();
    ob.setMinimumSize(sizec);
    ob.setMaximumSize(sizec);
}

MainWindow::SetVersion(int version_device, int ver, int subver)
{
    CurlirVersion = version_device;
    version = ver;
    subversion = subver;

    Strversion.sprintf("LirSync, версия %d.%d.%03d", CurlirVersion, version, subversion);
    return 0;
}

void MainWindow::clickdecButton()
{
    lbl->setText("dec");
}

void MainWindow::clickMenuExit()
{
    QCoreApplication::quit();
}

void MainWindow::clickOpenFolder()
{
    QDesktopServices::openUrl(QUrl(QDir::currentPath(), QUrl::TolerantMode));
}

void MainWindow::clickAboutitem()
{
   about = new QDialog(this);
   about->resize(230,130);
   about->setWindowTitle("О Программе...");
   SetNoResize(*about);

   QPixmap pic("icon1");

   QLabel *label = new QLabel(about);
   label->move(30,15);
   label->setPixmap(pic);

    QLabel *txtver = new QLabel(about);
    txtver->setGeometry(80,20,150,15);
    txtver->setText(Strversion);
    txtver->show();

    QPushButton *butok = new QPushButton("Ok",about);
    butok->move(75,85);
    butok->show();

    connect(butok, SIGNAL (released()), this, SLOT (clickOkinAboutDlg()));

    about->setModal(true);
    about->show();
    about->exec();

}

void MainWindow::clickOkinAboutDlg()
{
    delete about;
}

MainWindow::MainWindow(QWidget *parent) :QMainWindow(parent),ui(new Ui::MainWindow)
{
   // ui->setupUi(this);  // подключение формы



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::clickincButton()
{
     lbl->setText("inc");
}




AboutWindow::AboutWindow(QWidget *parent)
{

}

AboutWindow::~AboutWindow()
{

}
