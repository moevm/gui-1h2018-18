#include "authwindow.h"
#include "ui_authwindow.h"

AuthWindow::AuthWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AuthWindow)
{
    ui->setupUi(this);
}

AuthWindow::~AuthWindow()
{
    delete ui;
}

void AuthWindow::on_signInButton_clicked()
{
    hide();
    mainWindow = new MainWindow(this);
    mainWindow->show();
}

void AuthWindow::on_signUpButton_clicked()
{
    hide();
    mainWindow = new MainWindow(this);
    mainWindow->show();
}
