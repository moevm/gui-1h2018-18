#ifndef CURRENTNEWS_H
#define CURRENTNEWS_H

#include <QWidget>
#include <QWebView>

namespace Ui {
class CurrentNews;
}

class CurrentNews : public QWidget
{
    Q_OBJECT

public:
    explicit CurrentNews(QWidget *parent = 0);
    ~CurrentNews();

private slots:
    void on_pushButton_clicked();

signals:
    void closeNews();

private:
    Ui::CurrentNews *ui;
};

#endif // CURRENTNEWS_H
