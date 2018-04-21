#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent, QString userLogin) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    QWidget *newsItem = ui->allNewsTab->getCurrentItemWidget();
//    QWidget *newsItem2 = ui->allNewsTab->getCurrentW2();
    QObject::connect(ui->allNewsTab, SIGNAL(readNewsSignal(QUrl)), this, SLOT(nextPage()));
//    QObject::connect(newsItem2, SIGNAL(readNews()), this, SLOT(nextPage()));
    QObject::connect(ui->page_2, SIGNAL(closeNews()), this, SLOT(prevoiusPage()));
    QObject::connect(ui->settingsTab, SIGNAL(hideMainWindow()), this, SLOT(hide()));
    QObject::connect(ui->settingsTab, SIGNAL(changeList()), this, SLOT(updateNewsTab()));
    ui->settingsTab->setUser(userLogin);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::nextPage()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::prevoiusPage()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::updateNewsTab()
{
    ui->allNewsTab->clearList();
    int meduza = ui->settingsTab->getMeduzaChecked();
    int lenta = ui->settingsTab->getLentaChecked();
    if (meduza == Qt::Checked) {
        ui->allNewsTab->loadNewsFromMeduza();
    }
    if (lenta == Qt::Checked) {
        ui->allNewsTab->loadNewsFromLenta();
    }
}
