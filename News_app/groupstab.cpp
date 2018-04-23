#include "groupstab.h"
#include "ui_groupstab.h"
#include <QVariant>

GroupsTab::GroupsTab(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GroupsTab)
{
    ui->setupUi(this);
    settings = new QSettings();
    allNews = new QList<NewsItem>();
}

GroupsTab::~GroupsTab()
{
    delete ui;
}

void GroupsTab::setUser(const QString &value)
{
    user = value;
}

void GroupsTab::updateList()
{
    allNews->clear();
    ui->listWidget->clear();
    loadFromSettings();
}

void GroupsTab::createNewsList()
{
    foreach (NewsItem newsitem, (*allNews)) {
        QListWidgetItem * widgetItem = new QListWidgetItem;
        addItemToList(widgetItem, &newsitem);
    }
}

void GroupsTab::loadFromSettings()
{
    int index = settings->value("/fav/" + user + "/count").toInt();
    for (int i = 0; i<index; i++) {
        QString text = settings->value("/fav/" + user + "/" + QString::number(i) + "/text").toString();
        QString name = settings->value("/fav/" + user + "/" + QString::number(i) + "/name").toString();
        QUrl link = settings->value("/fav/" + user + "/" + QString::number(i) + "/link").toString();
        NewsItem* news = new NewsItem();
        news->setText(text);
        news->setName(name);
        news->setLink(link);
        allNews->append(*news);
    }
    createNewsList();
}

void GroupsTab::addItemToList(QListWidgetItem *item, NewsItem* news)
{
    item->setSizeHint(QSize(0, 100));
    ui->listWidget->addItem(item);
    ui->listWidget->setItemWidget(item, transformToWidget(news));
}

QWidget *GroupsTab::transformToWidget(NewsItem * news)
{
    NewsItem *w = new NewsItem();
    w->setText(news->getText());
    w->setName(news->getName());
    w->setLink(news->getLink());
//    connect(w, SIGNAL(readItemNews(QUrl)), this, SLOT(readNews(QUrl)));
    return w;
}
