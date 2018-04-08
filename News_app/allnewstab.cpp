#include "allnewstab.h"
#include "ui_allnewstab.h"
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QXmlStreamReader>
#include <QXmlStreamAttribute>


AllNewsTab::AllNewsTab(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AllNewsTab)
{
    ui->setupUi(this);

    allNews = new QList<NewsItem>();

    QNetworkAccessManager* networkManager = new QNetworkAccessManager(this);

    QUrl url("https://meduza.io/api/v3/search?chrono=news&locale=ru&page=0&per_page=24");
    QNetworkRequest request(url);

    QNetworkReply* currentReply = networkManager->get(request);

    connect(networkManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(getNewsFromJson(QNetworkReply*)));
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
    return &(*allNews)[1];
}

void AllNewsTab::accessJson()
{

}

void AllNewsTab::getNewsFromJson(QNetworkReply* reply)
{
    if (reply->error() != QNetworkReply::NoError)
            return;

    qint64 resSize = reply->size();
    QString res = (QString) reply->readAll();
    QJsonDocument doc = QJsonDocument::fromJson(res.toUtf8());
    QJsonObject root = doc.object();
    QJsonObject documents = root["documents"].toObject();
    QStringList	allKeys = documents.keys();
    QList<NewsItem> news = QList<NewsItem>();
    foreach(QString str, allKeys){
        QJsonObject post = documents[str].toObject();
        NewsItem newItem = NewsItem();
        QString t1 = post["url"].toString();
        QString t2 = post["title"].toString();
        newItem.setName(post["url"].toString());
        newItem.setText(post["title"].toString());
        news.append(newItem);
    }

    allNews->append(news);

    onFinishJsonParse();

}

QList<NewsItem> AllNewsTab::getNewsFromXML(QString xmlt)
{



}


void AllNewsTab::onFinishJsonParse()
{
    QList<QListWidgetItem> widgetItems = QList<QListWidgetItem>();
    for(int i = 0; i < allNews->size(); i++){
        widgetItems.append((*(new QListWidgetItem(ui->newsListWidget))));
    }
    int i = 0;
    foreach (NewsItem newsitem, (*allNews)) {
        addItemToList((&widgetItems[i]), (&newsitem));
    }

}

void AllNewsTab::addItemToList(QListWidgetItem *item, NewsItem* news)
{
    ui->newsListWidget->addItem(item);
    item->setSizeHint(QSize(0, 100));
    ui->newsListWidget->setItemWidget(item, news);
}
