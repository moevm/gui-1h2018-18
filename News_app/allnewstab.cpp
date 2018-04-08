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
    itemWidget = &(allNews->first());
    return itemWidget;
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
    const QStringList	allKeys = documents.keys();
    foreach(QString str, allKeys){
        QJsonObject post = documents[str].toObject();
        NewsItem newItem = NewsItem();
        QString t1 = post["url"].toString();
        QString t2 = post["title"].toString();
        newItem.setName(post["url"].toString());
        newItem.setText(post["title"].toString());
        allNews->append(newItem);
    }
    onFinishJsonParse();

}

void AllNewsTab::getNewsFromXML()
{
    onFinishXMLParse();
}


void AllNewsTab::onFinishJsonParse()
{
    getNewsFromXML();
}

void AllNewsTab::onFinishXMLParse()
{
    foreach (NewsItem newsitem, (*allNews)) {
//        QListWidgetItem itemWidget = QListWidgetItem(ui->newsListWidget);
//        itemWidget.setText(newsitem.getText());
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
    QWidget* w = new QWidget();

    QVBoxLayout* vbl = new QVBoxLayout(w);
    QLabel * lab_01 = new QLabel(news->getName());
    QLabel * lab_02 = new QLabel(news->getText());
    QPushButton* pb = new QPushButton("button");

    vbl->addWidget(lab_01);
    vbl->addWidget(lab_02);
    vbl->addWidget(pb);
    vbl->setSizeConstraint( QLayout::SetFixedSize );
    w->setLayout(vbl);

    return w;
}
