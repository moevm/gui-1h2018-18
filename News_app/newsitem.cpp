#include "newsitem.h"
#include "ui_newsitem.h"

NewsItem::NewsItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NewsItem)
{
    ui->setupUi(this);
}

NewsItem::NewsItem(QString name, QString text, QString link, QString settingsLink, QString img, QWidget *parent):
    QWidget(parent),
    ui(new Ui::NewsItem)
{
    ui->setupUi(this);
    this->name = name;
    this->text = text;
    this->link = link;
    this->settngsLink = settingsLink;
    this->img = img;
    ui->newsTitle->setText(this->name);
    ui->textBrowser->setText(this->text);
}

NewsItem::NewsItem(const NewsItem & other, QWidget *parent):
    QWidget(parent),
    ui(new Ui::NewsItem)
{
    ui->setupUi(this);
    this->name = other.name;
    this->text = other.text;
    this->link = other.link;
    this->settngsLink = other.settngsLink;
    this->img = other.img;
    ui->newsTitle->setText(this->name);
    ui->textBrowser->setText(this->text);
}

NewsItem NewsItem::operator=(const NewsItem &other) const
{
    NewsItem* newNews = new NewsItem(other.name, other.text, other.link, other.settngsLink, other.img);
    return (* newNews);
}

void NewsItem::setName(QString name)
{
    this->name = name;
    ui->newsTitle->setText(this->name);
}

void NewsItem::setText(QString text)
{
    this->text = text;
    ui->textBrowser->setText(this->text);
}

QString NewsItem::getName()
{
    return this->name;
}

QString NewsItem::getText()
{
    return this->text;
}

QString NewsItem::getLink()
{
    return link;
}

QString NewsItem::getSettingsLink()
{
    return settngsLink;
}

void NewsItem::setSettingsLink(QString settingsLink)
{
    this->settngsLink = settingsLink;
}


void NewsItem::setupImage(QNetworkReply *reply)
{
    if (reply->error() != QNetworkReply::NoError) {
    return;
    }

    QByteArray jpegData = reply->readAll();
    QPixmap pixmap;
    pixmap.loadFromData(jpegData);
    ui->image->setPixmap(pixmap.scaled(60, 60, Qt::KeepAspectRatio));
}

NewsItem::~NewsItem()
{
    delete ui;
}

void NewsItem::on_readButton_clicked()
{
    emit readItemNews(this->link);
}

QString NewsItem::getImg() const
{
    return img;
}

void NewsItem::setImg(QString value)
{
    img = value;
}

QString NewsItem::getLink() const
{
    return link;
}

void NewsItem::setLink(const QString &value)
{
    link = value;
}

void NewsItem::on_addToFavButton_clicked()
{
    emit addItemToFavorite(*this);
}
