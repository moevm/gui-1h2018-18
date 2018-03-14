#include "currentnews.h"
#include "ui_currentnews.h"

CurrentNews::CurrentNews(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CurrentNews)
{
    ui->setupUi(this);
}

CurrentNews::~CurrentNews()
{
    delete ui;
}

void CurrentNews::on_pushButton_clicked()
{
    emit closeNews();
}
