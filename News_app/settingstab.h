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

private slots:
    void on_logoutButton_clicked();

signals:
    void hideMainWindow();

private:
    Ui::SettingsTab *ui;
    AuthWindow *authWindow;
};

#endif // SETTINGSTAB_H
