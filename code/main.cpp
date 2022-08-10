#include "mainwindow.h"
#include "addialog.h"
#include <QApplication>
#include<QSplashScreen>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QPixmap pixmap(":/Images/Images/zndx.jpg");
    QSplashScreen splash(pixmap);//程序启动画面
    for(qint64 i=5555555;i>0;i--)
        splash.show();
    MainWindow w;
    w.show();
    AdDialog m;
    m.show();

    splash.finish(&w);


    return a.exec();
}
