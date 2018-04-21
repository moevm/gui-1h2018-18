#include "settingstab.h"
#include "ui_settingstab.h"
#include <QMessageBox>

SettingsTab::SettingsTab(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SettingsTab)
{
    ui->setupUi(this);
    settings = new QSettings();
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
    emit changeList();
}

void SettingsTab::on_lentaCheckBox_stateChanged(int arg1)
{
    lentaChecked = arg1;
    emit changeList();
}

void SettingsTab::setUser(const QString &value)
{
    user = value;
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

void SettingsTab::on_pushButton_clicked()
{
    QString existingPassword = this->settings->value("/users/" + user).toString();
    if (!existingPassword.isNull()) {
        QString oldPassword = ui->oldPasswordInput->text();
        if (oldPassword == existingPassword) {
            QString newPassword = ui->newPasswordInput->text();
            if (!newPassword.isEmpty()) {
                this->settings->setValue("/users/" + user, newPassword);
                QMessageBox::information(this, "Password change", "Password for user " + user + " successfully changed");
            }
            else {
                QMessageBox::warning(this, "Password change", "Password could not be empty");
            }
        }
        else {
            QMessageBox::critical(this,  "Password change", "Wrong old password entered");
        }
    }
    else {
        QMessageBox::critical(this, "Authentification error", "Try later");
    }
}
