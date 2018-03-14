#include "allnewstab.h"
#include "ui_allnewstab.h"

AllNewsTab::AllNewsTab(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AllNewsTab)
{
    ui->setupUi(this);

    itemWidget = new NewsItem();
    QListWidgetItem *item = new QListWidgetItem();
    item->setSizeHint(QSize(0,100));
    ui->newsListWidget->addItem(item);
    ui->newsListWidget->setItemWidget(item, itemWidget);
}

AllNewsTab::~AllNewsTab()
{
    delete ui;
}

QListWidgetItem * AllNewsTab::getCurrentItem()
{
    return ui->newsListWidget->currentItem();
}

QWidget * AllNewsTab::getCurrentItemWidget()
{
    return itemWidget;
}
