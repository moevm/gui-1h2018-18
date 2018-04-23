#ifndef GROUPSTAB_H
#define GROUPSTAB_H

#include <QWidget>
#include <QListWidgetItem>
#include "newsitem.h"
#include <QList>
#include <QSettings>

namespace Ui {
class GroupsTab;
}

class GroupsTab : public QWidget
{
    Q_OBJECT

public:
    explicit GroupsTab(QWidget *parent = 0);
    ~GroupsTab();

    void setUser(const QString &value);
    void updateList();
    void loadFromSettings();

private:
    Ui::GroupsTab *ui;
    QSettings *settings;
    QString user;
    void addItemToList(QListWidgetItem *item, NewsItem* news);
    QWidget* transformToWidget(NewsItem * news);
    void createNewsList();
    NewsItem *itemWidget;
    QList<NewsItem> *allNews;
};

#endif // GROUPSTAB_H
