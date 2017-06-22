#ifndef FACEPLUSPLUS_H
#define FACEPLUSPLUS_H

#include <QObject>
#include <QtNetwork>

class FacePlusPlus : public QObject
{
  Q_OBJECT
public:
  explicit FacePlusPlus(QObject *parent = nullptr);

  void RequestData();

private:
  QNetworkAccessManager *network_manager_;

signals:

private slots:
  void PostAnswer(QNetworkReply*);
};

#endif // FACEPLUSPLUS_H
