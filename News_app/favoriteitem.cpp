#include "favoriteitem.h"
#include "ui_favoriteitem.h"

FavoriteItem::FavoriteItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FavoriteItem)
{
    ui->setupUi(this);
}

FavoriteItem::FavoriteItem(QString name, QString text, QString link, QString settingsLink, QWidget *parent):
    QWidget(parent),
    ui(new Ui::FavoriteItem)
{
    ui->setupUi(this);
    this->name = name;
    this->text = text;
    this->link = link;
    this->settngsLink = settingsLink;
    ui->newsTitle->setText(this->name);
    ui->textBrowser->setText(this->text);
}

FavoriteItem::FavoriteItem(const FavoriteItem & other, QWidget *parent):
    QWidget(parent),
    ui(new Ui::FavoriteItem)
{
    ui->setupUi(this);
    this->name = other.name;
    this->text = other.text;
    this->link = other.link;
    this->settngsLink = other.settngsLink;
    ui->newsTitle->setText(this->name);
    ui->textBrowser->setText(this->text);
}

FavoriteItem FavoriteItem::operator=(const FavoriteItem &other) const
{
    FavoriteItem* newNews = new FavoriteItem(other.name, other.text, other.link, other.settngsLink);
    return (* newNews);
}

FavoriteItem::~FavoriteItem()
{
    delete ui;
}

QString FavoriteItem::getText() const
{
    return text;
}

void FavoriteItem::setText(const QString &value)
{
    text = value;
    ui->textBrowser->setText(this->text);
}

QString FavoriteItem::getName() const
{
    return name;
}

void FavoriteItem::setName(const QString &value)
{
    name = value;
    ui->newsTitle->setText(this->name);
}

QString FavoriteItem::getLink() const
{
    return link;
}

void FavoriteItem::setLink(const QString &value)
{
    link = value;
}

QString FavoriteItem::getSettingsLink()
{
    return settngsLink;
}

void FavoriteItem::setSettingsLink(QString settingsLink)
{
    this->settngsLink = settingsLink;
}

void FavoriteItem::on_addToFavButton_clicked()
{
    emit reoveItemFromFavorite(*this);
}

void FavoriteItem::on_readButton_clicked()
{
    emit readItemNews(this->link);
}
