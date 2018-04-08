#ifndef XMLNEWSREADER_H
#define XMLNEWSREADER_H

#include "QString"
#include "QXmlStreamReader"
#include "parsednews.h"

class XmlNewsReader
{
public:
    XmlNewsReader(QByteArray byteArray);

    void read();

    QList<ParsedNews> getParsedNewsList() const;
    void setParsedNewsList(const QList<ParsedNews> &value);

private:
    void processAllNews();
    void processNews();
    QString readNextText();
    QString errorString();

    QByteArray inputByteArray;
    QXmlStreamReader xml;
    QList<ParsedNews> parsedNewsList;
};

#endif // XMLNEWSREADER_H
