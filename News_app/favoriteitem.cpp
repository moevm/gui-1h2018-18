#include "favoriteitem.h"
#include "ui_favoriteitem.h"

FavoriteItem::FavoriteItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FavoriteItem)
{
    ui->setupUi(this);
}

FavoriteItem::FavoriteItem(QString name, QString text, QWidget *parent):
    QWidget(parent),
    ui(new Ui::FavoriteItem)
{
    ui->setupUi(this);
    this->name = name;
    this->text = text;
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
    ui->newsTitle->setText(this->name);
    ui->textBrowser->setText(this->text);
}

FavoriteItem FavoriteItem::operator=(const FavoriteItem &other) const
{
    FavoriteItem* newNews = new FavoriteItem(other.name, other.text);
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
