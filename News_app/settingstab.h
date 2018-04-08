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

private slots:
    void on_logoutButton_clicked();

    void on_meduzaCheckBox_stateChanged(int arg1);

    void on_lentaCheckBox_stateChanged(int arg1);

signals:
    void hideMainWindow();

private:
    Ui::SettingsTab *ui;
    AuthWindow *authWindow;
    int meduzaChecked;
    int lentaChecked;
};

#endif // SETTINGSTAB_H
