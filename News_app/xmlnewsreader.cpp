#include "xmlnewsreader.h"
#include "QBuffer"


XmlNewsReader::XmlNewsReader(QByteArray byteArray)
{
    this->inputByteArray = byteArray;
}

void XmlNewsReader::read()
{
    QBuffer buffer(&inputByteArray);
    buffer.open(QIODevice::ReadOnly);
    xml.setDevice(&buffer);
    xml.readNextStartElement();
    if (xml.readNextStartElement() && xml.name() == "channel")
          processAllNews();
    if (xml.tokenType() == QXmlStreamReader::Invalid)
            xml.readNext();

    if (xml.hasError()) {
         xml.raiseError();
    }

}

void XmlNewsReader::processAllNews()
{
       while (xml.readNextStartElement()) {
           if (xml.name() == "item")
               processNews();
           else
               xml.skipCurrentElement();
       }
}

void XmlNewsReader::processNews()
{
    if (!xml.isStartElement() || xml.name() != "item")
            return;

        QString title;
        QString description;
        QUrl link;
        QUrl imageLink;
        while (xml.readNextStartElement()) {
            if (xml.name() == "title")
                title = readNextText();
            else if (xml.name() == "guid")
                link = QUrl(readNextText());
            else if (xml.name() == "description")
                description = readNextText();
            else if (xml.name() == "enclosure")
                imageLink = xml.attributes().value("url").toString();
    #ifndef USE_READ_ELEMENT_TEXT
            xml.skipCurrentElement();
    #endif
        }

        if (!(title.isEmpty() || link.isEmpty() || description.isEmpty() || imageLink.isEmpty())) {
            ParsedNews * newsItem = new ParsedNews (link, imageLink, title, description);
            this->parsedNewsList.append(*newsItem);
        }
}

QString XmlNewsReader::readNextText()
{
#ifndef USE_READ_ELEMENT_TEXT
    xml.readNext();
    return xml.text().toString();
#else
    return xml.readElementText();
#endif
}

QString XmlNewsReader::errorString()
{

}

QList<ParsedNews> XmlNewsReader::getParsedNewsList() const
{
    return parsedNewsList;
}

void XmlNewsReader::setParsedNewsList(const QList<ParsedNews> &value)
{
    parsedNewsList = value;
}
