#include "groupstab.h"
#include "ui_groupstab.h"
#include <QVariant>
#include <QDesktopServices>

GroupsTab::GroupsTab(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GroupsTab)
{
    ui->setupUi(this);
    settings = new QSettings();
    allNews = new QList<FavoriteItem>();
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
    foreach (FavoriteItem newsitem, (*allNews)) {
        QListWidgetItem * widgetItem = new QListWidgetItem;
        addItemToList(widgetItem, &newsitem);
    }
}

void GroupsTab::removeFromFavorite(FavoriteItem news)
{
    settings->remove(news.getSettingsLink());
    updateList();
}

void GroupsTab::readNews(QString link)
{
    QDesktopServices::openUrl(QUrl(link));
}

void GroupsTab::loadFromSettings()
{
    QStringList list = settings->allKeys();
    QStringList indexesForUser = QStringList();
    foreach (QString key, list) {
        if(key.contains("fav/"+ user) && key.endsWith("text")){
            indexesForUser << key.left(key.lastIndexOf(QChar('/')));
        }
    }
    foreach (QString key, indexesForUser){
        QString text = settings->value(key + "/text").toString();
        QString name = settings->value(key + "/name").toString();
        QString link = settings->value(key + "/link").toString();
        FavoriteItem* news = new FavoriteItem();
        news->setText(text);
        news->setName(name);
        news->setLink(link);
        news->setSettingsLink(key);

        allNews->append(*news);
    }
    createNewsList();
}

void GroupsTab::addItemToList(QListWidgetItem *item, FavoriteItem *news)
{
    item->setSizeHint(QSize(0, 100));
    ui->listWidget->addItem(item);
    ui->listWidget->setItemWidget(item, transformToWidget(news));
}

QWidget *GroupsTab::transformToWidget(FavoriteItem *news)
{
    FavoriteItem *w = new FavoriteItem();
    w->setText(news->getText());
    w->setName(news->getName());
    w->setLink(news->getLink());
    w->setSettingsLink(news->getSettingsLink());
    connect(w, SIGNAL(readItemNews(QString)), this, SLOT(readNews(QString)));
    connect(w, SIGNAL(reoveItemFromFavorite(FavoriteItem)), this, SLOT(removeFromFavorite(FavoriteItem)));
    return w;
}
