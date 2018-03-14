#ifndef ALLNEWSTAB_H
#define ALLNEWSTAB_H

#include <QWidget>
#include <QListWidgetItem>
#include "newsitem.h"

namespace Ui {
class AllNewsTab;
}

class AllNewsTab : public QWidget
{
    Q_OBJECT

public:
    explicit AllNewsTab(QWidget *parent = 0);
    ~AllNewsTab();
    QListWidgetItem *getCurrentItem();
    QWidget * getCurrentItemWidget();

private:
    Ui::AllNewsTab *ui;
    NewsItem *itemWidget;
};

#endif // ALLNEWSTAB_H
