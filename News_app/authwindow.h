#ifndef AUTHWINDOW_H
#define AUTHWINDOW_H

#include <QMainWindow>
#include "mainwindow.h"
#include <QSettings>

namespace Ui {
class AuthWindow;
}

class AuthWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AuthWindow(QWidget *parent = 0);
    ~AuthWindow();

private slots:
    void on_signInButton_clicked();

    void on_signUpButton_clicked();

private:
    Ui::AuthWindow *ui;
    MainWindow *mainWindow;
    QSettings *settings;
};

#endif // AUTHWINDOW_H
