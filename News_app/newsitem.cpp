#include "newsitem.h"
#include "ui_newsitem.h"

NewsItem::NewsItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NewsItem)
{
    ui->setupUi(this);
}

NewsItem::~NewsItem()
{
    delete ui;
}

void NewsItem::on_readButton_clicked()
{
    emit readNews();
}
