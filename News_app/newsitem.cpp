#include "newsitem.h"
#include "ui_newsitem.h"

NewsItem::NewsItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NewsItem)
{
    ui->setupUi(this);
}

NewsItem::NewsItem(QString name, QString text, QWidget *parent):
    QWidget(parent),
    ui(new Ui::NewsItem)
{
    ui->setupUi(this);
    this->name = name;
    this->text = text;
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
    ui->newsTitle->setText(this->name);
    ui->textBrowser->setText(this->text);
    ui->addToFavButton->setText("Remove");
}

NewsItem NewsItem::operator=(const NewsItem &other) const
{

    NewsItem* newNews = new NewsItem(other.name, other.text);

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

NewsItem::~NewsItem()
{
    delete ui;
}

void NewsItem::on_readButton_clicked()
{
    emit readItemNews(this->link);
}

QPixmap *NewsItem::getImg() const
{
    return img;
}

void NewsItem::setImg(QPixmap *value)
{
    img = value;
    ui->label->setPixmap(*img);
}

QUrl NewsItem::getLink() const
{
    return link;
}

void NewsItem::setLink(const QUrl &value)
{
    link = value;
}

QDataStream& operator<<(QDataStream& out, const NewsItem& v) {
    out << v.name << v.text << v.link;
    return out;
}

QDataStream& operator>>(QDataStream& in, NewsItem& v) {
    in >> v.name;
    in >> v.text;
    in >> v.link;
    return in;
}


void NewsItem::on_addToFavButton_clicked()
{
    emit addItemToFavorite(*this);
}
