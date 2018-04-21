#ifndef SETTINGSTAB_H
#define SETTINGSTAB_H

#include <QWidget>
#include "authwindow.h"

namespace Ui {
class SettingsTab;
}

class SettingsTab : public QWidget
{
    Q_OBJECT

public:
    explicit SettingsTab(QWidget *parent = 0);
    ~SettingsTab();

    int getMeduzaChecked() const;
    void setMeduzaChecked(int value);

    int getLentaChecked() const;
    void setLentaChecked(int value);

    void setUser(const QString &value);

private slots:
    void on_logoutButton_clicked();

    void on_meduzaCheckBox_stateChanged(int arg1);

    void on_lentaCheckBox_stateChanged(int arg1);

    void on_pushButton_clicked();

signals:
    void hideMainWindow();
    void changeList();

private:
    Ui::SettingsTab *ui;
    AuthWindow *authWindow;
    int meduzaChecked;
    int lentaChecked;
    QString user;
    QSettings *settings;
};

#endif // SETTINGSTAB_H
