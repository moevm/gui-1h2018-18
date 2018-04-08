#include "mainwindow.h"
#include "authwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QCoreApplication::setOrganizationName("MOEVM Production");
    QCoreApplication::setOrganizationDomain("mo-evm.ru");
    QCoreApplication::setApplicationName("News Agregator");
    QApplication a(argc, argv);
    AuthWindow w;
    w.show();

    return a.exec();
}
