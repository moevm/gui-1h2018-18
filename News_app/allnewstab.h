#ifndef ALLNEWSTAB_H
#define ALLNEWSTAB_H

#include <QWidget>
#include <QListWidgetItem>
#include "newsitem.h"
#include <QList>
#include <QtNetwork>


namespace Ui {
class AllNewsTab;
}

class AllNewsTab : public QWidget
{
    Q_OBJECT

private slots:
    void getNewsFromJson(QNetworkReply* reply);

public:
    explicit AllNewsTab(QWidget *parent = 0);
    ~AllNewsTab();
    QListWidgetItem *getCurrentItem();
    QWidget * getCurrentItemWidget();
    QWidget * getCurrentW2();
    void accessJson();
    QList<NewsItem> getNewsFromXML (QString);
    void onFinishJsonParse();
    void addItemToList(QListWidgetItem* item, NewsItem* news);

private:
    Ui::AllNewsTab *ui;
    NewsItem *itemWidget;
    QList<NewsItem> *allNews;
};

#endif // ALLNEWSTAB_H
