#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QApplication>
#include <QMenuBar>
#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QDesktopServices>
#include <QUrl>
#include <QMessageBox>
#include <QDir>
#include <QAction>
#include <QPicture>
#include <QPixmap>





namespace Ui {
class MainWindow;
}

class AboutWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit AboutWindow(QWidget *parent);
    ~AboutWindow();
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    CreateMenu();
    CreateButton(QString name,int x,int y,int w,int h);
    CreateStaticText(QString name,int x,int y);
    CreatePic(QString filename,int x,int y,int w,int h);

    void SetNoResize();
    void SetNoResize(QDialog &ob);

    SetVersion(int version_device,int ver,int subver);
    QString Strversion;
    int CurlirVersion;  // версия прибора
    int version;        // 0 -WinApi, 1 -QtApi , 2 - MFC
    int subversion;

private:
    Ui::MainWindow *ui;
    QLabel *lbl;
    QDialog *about;


public slots:
    void clickincButton();
    void clickdecButton();
    void clickMenuExit();
    void clickOpenFolder();
    void clickAboutitem();
    void clickOkinAboutDlg();
};

#endif // MAINWINDOW_H
