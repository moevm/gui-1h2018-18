#include "parsednews.h"

ParsedNews::ParsedNews(QUrl link, QUrl imageLink, QString title, QString description)
{
    this->link = link;
    this->imageLink = imageLink;
    this->title = title;
    this->description = description;
}

QUrl ParsedNews::getLink() const
{
    return link;
}

void ParsedNews::setLink(const QUrl &value)
{
    link = value;
}

QUrl ParsedNews::getImageLink() const
{
    return imageLink;
}

void ParsedNews::setImageLink(const QUrl &value)
{
    imageLink = value;
}

QString ParsedNews::getTitle() const
{
    return title;
}

void ParsedNews::setTitle(const QString &value)
{
    title = value;
}

QString ParsedNews::getDescription() const
{
    return description;
}

void ParsedNews::setDescription(const QString &value)
{
    description = value;
}
