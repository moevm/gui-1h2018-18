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
#include "xmlnewsreader.h"

const QString BASE_MEDUZA_URL = "https://meduza.io/rss/all";
const QString BASE_LENTA_URL = "https://lenta.ru/rss/news";

AllNewsTab::AllNewsTab(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AllNewsTab)
{
    ui->setupUi(this);

    allNews = new QList<NewsItem>();
    loadNews();
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
        tempImage = QImage(64, 64, QImage::Format_RGB888);
        NewsItem * newsItem = new NewsItem ();
        newsItem->setName(parsedItem.getTitle());
        newsItem->setText(parsedItem.getDescription());
        downloadImage(parsedItem.getImageLink());
        newsItem->setImg(tempImage);
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
    ui->newsListWidget->addItem(item);
    ui->newsListWidget->setItemWidget(item, transformToWidget(news));
}

QWidget *AllNewsTab::transformToWidget(NewsItem * news)
{
    NewsItem *w = new NewsItem();
    w->setText(news->getText());
    w->setName(news->getName());
    w->setImg(news->getImg());
    w->setLink(news->getLink());
    connect(w, SIGNAL(readItemNews(QUrl)), this, SLOT(readNews(QUrl)));
    return w;
}

void AllNewsTab::loadNews()
{

    QNetworkAccessManager* networkManager = new QNetworkAccessManager(this);

//    QUrl url(BASE_LENTA_URL);
    QUrl url(BASE_MEDUZA_URL);
    QNetworkRequest request(url);

    QNetworkReply* currentReply = networkManager->get(request);
    connect(networkManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(getParsedNews(QNetworkReply*)));
}

void AllNewsTab::downloadImage(QUrl url)
{
    QNetworkAccessManager* networkManager = new QNetworkAccessManager(this);
    QNetworkRequest request(url);
    QNetworkReply* currentReply = networkManager->get(request);
    connect(networkManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(convertReplyToImage(QNetworkReply*)));
}

void AllNewsTab::convertReplyToImage(QNetworkReply* reply)
{
    if (reply->error() != QNetworkReply::NoError)
            return;
    tempImage = QImage::fromData(reply->readAll());
}

void AllNewsTab::readNews(QUrl link)
{
    emit readNewsSignal(link);
}
