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
    QList<NewsItem> fromJson = getNewsFromJson("[{\"name\":\"«Травля идет со всех сторон». Тулеев заявил о попытках «раскачать ситуацию» в регионе\", \"text\":\"Губернатор Кузбасса Аман Тулеев записал 10-минутное видеообращение, в котором, в частности, рассказал о том, что «определенные силы целенаправленно пытаются стравить людей» и «раскачать ситуацию» в регионе. \" }, {\"name\":\"«Первому игроку приготовиться» Стивена Спилберга: не гениальный фильм, но фильм гения\", \"text\":\"В российский прокат выходит «Первому игроку приготовиться» — новый фильм Стивена Спилберга о мире будущего, в котором все обитатели Земли проводят время в виртуальной реальности, вдохновленной 1980-ми, временем расцвета самого Спилберга как режиссера.\" }]");
//    QList<NewsItem> fromXML = getNewsFromXML("<?xml version=\"1.0\" encoding=\"utf-8\"?><newslist><news><name>Новость</name><text>Текст новости</text></news><news><name>Новость2</name><text>Текст новости2</text></news></newslist>");
    allNews = new QList<NewsItem>(fromJson);
//    allNews->append(fromXML);


    QListWidgetItem *item = new QListWidgetItem(ui->newsListWidget);
    ui->newsListWidget->addItem(item);
    NewsItem* newNews = &(allNews->first());
    QString name = newNews->getName();
    QString text = newNews->getText();

    item->setSizeHint(QSize(0, 100));
    ui->newsListWidget->setItemWidget(item, newNews);


    QListWidgetItem *item2 = new QListWidgetItem(ui->newsListWidget);
    ui->newsListWidget->addItem(item2);
    NewsItem* newNews2 = &((*allNews)[1]);

    item2->setSizeHint(QSize(0, 100));
    ui->newsListWidget->setItemWidget(item2, newNews2);



//    QListWidgetItem *item3 = new QListWidgetItem(ui->newsListWidget);
//    ui->newsListWidget->addItem(item3);
//    NewsItem* newNews3 = &((*allNews)[2]);

//    item2->setSizeHint(QSize(0, 100));
//    ui->newsListWidget->setItemWidget(item3, newNews3);




//    QListWidgetItem *item4 = new QListWidgetItem(ui->newsListWidget);
//    ui->newsListWidget->addItem(item4);
//    NewsItem* newNews4 = &((*allNews)[3]);

//    item2->setSizeHint(QSize(0, 100));
//    ui->newsListWidget->setItemWidget(item4, newNews2);




//    foreach (NewsItem value, (*allNews)) {
//        QListWidgetItem *item = new QListWidgetItem(ui->newsListWidget);
//        ui->newsListWidget->addItem(item);
//        NewsItem* newNews = &value;
//        QString name = newNews->getName();
//        QString text = newNews->getText();

//        item->setSizeHint(QSize(0,100));
//        ui->newsListWidget->setItemWidget(item, newNews);
//    }


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

QList<NewsItem> AllNewsTab::getNewsFromJson(QString json)
{
    QJsonDocument doc = QJsonDocument::fromJson(json.toUtf8());
    QJsonArray array = doc.array();
    QList<NewsItem> news = QList<NewsItem>();
    for(int i = 0; i < array.size(); ++i){
        QJsonObject obj = array[i].toObject();
        NewsItem newItem = NewsItem();
        newItem.setName(obj["name"].toString());
        newItem.setText(obj["text"].toString());

        news.append(newItem);
    }

    return news;

}

QList<NewsItem> AllNewsTab::getNewsFromXML(QString xmlt)
{



}
