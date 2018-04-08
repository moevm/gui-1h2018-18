#include "authwindow.h"
#include "ui_authwindow.h"
#include <QMessageBox>

AuthWindow::AuthWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AuthWindow)
{
    settings = new QSettings();
    settings->setValue("/users/admin", "admin");
    ui->setupUi(this);
    ui->passwordInput->setEchoMode(QLineEdit::Password);
    ui->passwordInput->setInputMethodHints(Qt::ImhHiddenText| Qt::ImhNoPredictiveText|Qt::ImhNoAutoUppercase);
}

AuthWindow::~AuthWindow()
{
    delete ui;
}

void AuthWindow::on_signInButton_clicked()
{
    QString login = ui->loginInput->text();
    QString pwd = ui->passwordInput->text();
    if (settings->value("/users/" + login) == pwd) {
        hide();
        mainWindow = new MainWindow(this);
        mainWindow->show();
    }
    else {
        if (settings->value("/users/" + login).toBool()){
            QMessageBox::critical(this, "Authenrification error", "Wrong password");
            ui->passwordInput->clear();
        }
        else{
            QMessageBox::critical(this, "Authenrification error", "Unregistered user");
            ui->passwordInput->clear();
        }
    }
}

void AuthWindow::on_signUpButton_clicked()
{

    QString login = ui->loginInput->text();
    QString pwd = ui->passwordInput->text();
    if (pwd.isEmpty()){
        QMessageBox::warning(this, "Registration error", "Password could not be empty");
    }
    else {
        if (settings->value("/users/" + login).toBool()) {
            QMessageBox::warning(this, "Registration error", "This user already existent");
            ui->loginInput->clear();
            ui->passwordInput->clear();
        }
        else {
            settings->setValue("/users/" + login, pwd);
            QMessageBox::information(this, "Registration result", "User with login " + login + " successfully registered!");
            hide();
            mainWindow = new MainWindow(this);
            mainWindow->show();
        }
    }
}
