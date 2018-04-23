#ifndef PARSEDNEWS_H
#define PARSEDNEWS_H

#include <QString>

class ParsedNews
{
public:
    ParsedNews();
    ParsedNews(QString link, QString imageLink, QString title, QString description);
    QString getLink() const;
    void setLink(const QString &value);

    QString getImageLink() const;
    void setImageLink(const QString &value);

    QString getTitle() const;
    void setTitle(const QString &value);

    QString getDescription() const;
    void setDescription(const QString &value);

private:
    QString link;
    QString imageLink;
    QString title;
    QString description;
};

#endif // PARSEDNEWS_H
