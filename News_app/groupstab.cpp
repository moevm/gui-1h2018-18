#include "groupstab.h"
#include "ui_groupstab.h"

GroupsTab::GroupsTab(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GroupsTab)
{
    ui->setupUi(this);
}

GroupsTab::~GroupsTab()
{
    delete ui;
}
