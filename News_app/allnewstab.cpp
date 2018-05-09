#include "allnewstab.h"
#include "ui_allnewstab.h"
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QXmlStreamReader>
#include <QXmlStreamAttribute>
#include <QLabel>
#include <QPushButton>
#include <QDesktopServices>
#include "xmlnewsreader.h"

const QString BASE_MEDUZA_URL = "https://meduza.io/rss/all";
const QString BASE_LENTA_URL = "https://lenta.ru/rss/news";

AllNewsTab::AllNewsTab(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AllNewsTab)
{
    ui->setupUi(this);
    settings = new QSettings();
    allNews = new QList<NewsItem>();
    loadNewsFromMeduza();
}

AllNewsTab::~AllNewsTab()
{
    delete ui;
}

QListWidgetItem * AllNewsTab::getCurrentItem()
{
    return ui->newsListWidget->currentItem();
}

QWidget * AllNewsTab::getCurrentItemWidget()
{
    itemWidget = &(allNews->first());
    return itemWidget;
}

QWidget *AllNewsTab::getCurrentW2()
{
    itemWidget = &(allNews->first());
    return itemWidget;
}

void AllNewsTab::getParsedNews(QNetworkReply *reply)
{
    if (reply->error() != QNetworkReply::NoError)
            return;

    XmlNewsReader *reader = new XmlNewsReader(reply->readAll());
    reader->read();
    foreach(ParsedNews parsedItem, reader->getParsedNewsList()) {
        NewsItem * newsItem = new NewsItem ();
        newsItem->setName(parsedItem.getTitle());
        newsItem->setText(parsedItem.getDescription());
        newsItem->setImg(parsedItem.getImageLink());
        newsItem->setLink(parsedItem.getLink());
        allNews->append(*newsItem);
    }
    onFinishXMLParse();
}

void AllNewsTab::onFinishXMLParse()
{
    foreach (NewsItem newsitem, (*allNews)) {
        QListWidgetItem * widgetItem = new QListWidgetItem;
        addItemToList(widgetItem, &newsitem);
    }
}

void AllNewsTab::addItemToList(QListWidgetItem *item, NewsItem* news)
{
    item->setSizeHint(QSize(0, 100));
    checkFavorites(news);
    ui->newsListWidget->addItem(item);
    ui->newsListWidget->setItemWidget(item, transformToWidget(news));
}

QWidget *AllNewsTab::transformToWidget(NewsItem * news)
{
    NewsItem *w = new NewsItem();
    w->setText(news->getText());
    w->setName(news->getName());
    QString imageLink = news->getImg();
    if(!imageLink.endsWith(".jpg") || !imageLink.endsWith(".jpeg")){
        imageLink.insert(4, 's');
    }
    w->setImg(imageLink);
    w->setLink(news->getLink());
    QNetworkAccessManager * m_netwManager = new QNetworkAccessManager(this);
    connect(m_netwManager, SIGNAL(finished(QNetworkReply*)), w, SLOT(setupImage(QNetworkReply*)));
    QUrl url(w->getImg());
    QNetworkRequest request(url);
    m_netwManager->get(request);
    w->setIsInFavorites(news->getIsInFavorites());
    connect(w, SIGNAL(readItemNews(QString)), this, SLOT(readNews(QString)));
    connect(w, SIGNAL(addItemToFavorite(NewsItem *)), this, SLOT(addFavoriteNews(NewsItem *)));
    return w;
}

void AllNewsTab::loadNewsFromLenta()
{
    QNetworkAccessManager* networkManager = new QNetworkAccessManager(this);

    QString url(BASE_LENTA_URL);
    QNetworkRequest request(url);

    QNetworkReply* currentReply = networkManager->get(request);
    connect(networkManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(getParsedNews(QNetworkReply*)));
}

void AllNewsTab::loadNewsFromMeduza()
{
    QNetworkAccessManager* networkManager = new QNetworkAccessManager(this);

    QString url(BASE_MEDUZA_URL);
    QNetworkRequest request(url);

    QNetworkReply* currentReply = networkManager->get(request);
    connect(networkManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(getParsedNews(QNetworkReply*)));
}

void AllNewsTab::clearList()
{
    ui->newsListWidget->clear();
}

void AllNewsTab::clearAllNews()
{
    allNews->clear();
}

void AllNewsTab::setUser(const QString &value)
{
    user = value;
}

void AllNewsTab::checkFavorites(NewsItem* news)
{
    QStringList list = settings->allKeys();
    QStringList indexesForUser = QStringList();
    foreach (QString key, list) {
        if(key.contains("fav/"+ user) && key.endsWith("text")){
            indexesForUser << key.left(key.lastIndexOf(QChar('/')));
        }
    }
    foreach (QString key, indexesForUser){
        QString link = settings->value(key + "/link").toString();
        if (!QString::compare(link, news->getLink(), Qt::CaseInsensitive)){
            news->setIsInFavorites(true);
        }
    }

}

void AllNewsTab::downloadImage(QString url)
{
    QNetworkAccessManager* networkManager = new QNetworkAccessManager(this);
    QNetworkRequest request(url);
    QNetworkReply* currentReply = networkManager->get(request);
    connect(networkManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(convertReplyToImage(QNetworkReply*)));
}

void AllNewsTab::addFavoriteNews(NewsItem *news)
{
    QStringList list = settings->allKeys();
    QList<int> indexesForUser = QList<int>();
        foreach (QString key, list) {
            if(key.contains("fav/"+ user) && key.endsWith("text")){
                QString withoutSuffix = key.left(key.lastIndexOf(QChar('/')));
                QString withoutPrefix = withoutSuffix.right(withoutSuffix.indexOf(QChar('/')));
                QString readyToUse = withoutPrefix.right(withoutPrefix.indexOf(QChar('/')));
                indexesForUser << readyToUse.toInt();
            }
        }
        int index = 0;
        if(!indexesForUser.isEmpty()){
            qSort(indexesForUser);
            index = ++indexesForUser.last();
        }
        news->setSettingsLink("/fav/" + user + "/" + QString::number(index));
        settings->setValue(news->getSettingsLink() + "/text", news->getText());
        settings->setValue(news->getSettingsLink() + "/name", news->getName());
        settings->setValue(news->getSettingsLink() + "/link", news->getLink());
        news->setIsInFavorites(true);
        emit updateFavorites();
}

void AllNewsTab::convertReplyToImage(QNetworkReply* reply)
{
    if (reply->error() != QNetworkReply::NoError)
            return;
    tempPixmap.loadFromData(reply->readAll(), "jpeg");
}

void AllNewsTab::readNews(QString link)
{
    QDesktopServices::openUrl(QUrl(link));
}
