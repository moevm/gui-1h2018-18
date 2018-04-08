#include "settingstab.h"
#include "ui_settingstab.h"

SettingsTab::SettingsTab(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SettingsTab)
{
    ui->setupUi(this);
}

SettingsTab::~SettingsTab()
{
    delete ui;
}

void SettingsTab::on_logoutButton_clicked()
{
    emit hideMainWindow();
    authWindow = new AuthWindow(this);
    authWindow->show();
}

void SettingsTab::on_meduzaCheckBox_stateChanged(int arg1)
{
    meduzaChecked = arg1;
}

void SettingsTab::on_lentaCheckBox_stateChanged(int arg1)
{
    lentaChecked = arg1;
}

int SettingsTab::getLentaChecked() const
{
    return lentaChecked;
}

void SettingsTab::setLentaChecked(int value)
{
    lentaChecked = value;
}

int SettingsTab::getMeduzaChecked() const
{
    return meduzaChecked;
}

void SettingsTab::setMeduzaChecked(int value)
{
    meduzaChecked = value;
}
