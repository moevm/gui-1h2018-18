#ifndef ALLNEWSTAB_H
#define ALLNEWSTAB_H

#include <QWidget>
#include <QListWidgetItem>
#include "newsitem.h"
#include <QList>

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
    QWidget * getCurrentW2();
    QList<NewsItem> getNewsFromJson(QString);
    QList<NewsItem> getNewsFromXML (QString);


private:
    Ui::AllNewsTab *ui;
    NewsItem *itemWidget;
    QList<NewsItem> *allNews;
};

#endif // ALLNEWSTAB_H
