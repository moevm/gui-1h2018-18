#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QWidget *newsItem = ui->allNewsTab->getCurrentItemWidget();
    QWidget *newsItem2 = ui->allNewsTab->getCurrentW2();
    QObject::connect(newsItem, SIGNAL(readNews()), this, SLOT(nextPage()));
    QObject::connect(newsItem2, SIGNAL(readNews()), this, SLOT(nextPage()));
    QObject::connect(ui->page_2, SIGNAL(closeNews()), this, SLOT(prevoiusPage()));
    QObject::connect(ui->settingsTab, SIGNAL(hideMainWindow()), this, SLOT(hide()));
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
