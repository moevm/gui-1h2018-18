#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0, QString userLogin = "");
    ~MainWindow();

private slots:
    void nextPage();
    void prevoiusPage();
    void updateNewsTab();
    void updateGroupsTab();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
