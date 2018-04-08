#ifndef PARSEDNEWS_H
#define PARSEDNEWS_H

#include <QUrl>

class ParsedNews
{
public:
    ParsedNews();
    ParsedNews(QUrl link, QUrl imageLink, QString title, QString description);
    QUrl getLink() const;
    void setLink(const QUrl &value);

    QUrl getImageLink() const;
    void setImageLink(const QUrl &value);

    QString getTitle() const;
    void setTitle(const QString &value);

    QString getDescription() const;
    void setDescription(const QString &value);

private:
    QUrl link;
    QUrl imageLink;
    QString title;
    QString description;
};

#endif // PARSEDNEWS_H
