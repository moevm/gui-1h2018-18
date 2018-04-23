#include "parsednews.h"

ParsedNews::ParsedNews(QString link, QString imageLink, QString title, QString description)
{
    this->link = link;
    this->imageLink = imageLink;
    this->title = title;
    this->description = description;
}

QString ParsedNews::getLink() const
{
    return link;
}

void ParsedNews::setLink(const QString &value)
{
    link = value;
}

QString ParsedNews::getImageLink() const
{
    return imageLink;
}

void ParsedNews::setImageLink(const QString &value)
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
