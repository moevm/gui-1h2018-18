#ifndef NEWSITEM_H
#define NEWSITEM_H

#include <QWidget>

namespace Ui {
class NewsItem;
}

class NewsItem : public QWidget
{
    Q_OBJECT

public:
    explicit NewsItem(QWidget *parent = 0);
    ~NewsItem();

private slots:
    void on_readButton_clicked();

signals:
    void readNews();
private:
    Ui::NewsItem *ui;
};

#endif // NEWSITEM_H
