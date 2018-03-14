#ifndef GROUPSTAB_H
#define GROUPSTAB_H

#include <QWidget>

namespace Ui {
class GroupsTab;
}

class GroupsTab : public QWidget
{
    Q_OBJECT

public:
    explicit GroupsTab(QWidget *parent = 0);
    ~GroupsTab();

private:
    Ui::GroupsTab *ui;
};

#endif // GROUPSTAB_H
