#include "faceplusplus.h"

#include <QDebug>
#include <QImage>

FacePlusPlus::FacePlusPlus(QObject *parent) : QObject(parent) {
  network_manager_ = new QNetworkAccessManager(this);
  connect(network_manager_, SIGNAL(finished(QNetworkReply*)), this, SLOT(PostAnswer(QNetworkReply*)));
}

void FacePlusPlus::PostAnswer(QNetworkReply* reply) {
  QByteArray data = reply->readAll();
  qDebug() << data;
}

void FacePlusPlus::RequestData() {
  QNetworkRequest request(QUrl("https://api-cn.faceplusplus.com/facepp/v3/detect"));

  QHttpMultiPart *multi_part = new QHttpMultiPart(QHttpMultiPart::FormDataType);

  QHttpPart imagePart;
  QImage image;
  image.load("/home/ye/test.png");
  QByteArray byteArray;
  QBuffer buffer(&byteArray);
  buffer.open(QIODevice::ReadWrite);
  image.save(&buffer, "PNG");
  imagePart.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("image/png"));
  imagePart.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant("form-data; name=\"image_file\"; filename=\" \""));
  imagePart.setBody(byteArray);

  QHttpPart textPart1;
  textPart1.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("text/plain"));
  textPart1.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant("form-data; name=\"api_key\""));
  textPart1.setBody("f4eahP-9gRA3NocaJK9X81LSkVaKGf6r");

  QHttpPart textPart2;
  textPart2.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("text/plain"));
  textPart2.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant("form-data; name=\"api_secret\""));
  textPart2.setBody("TbJIBNCvN4Yyo_GZruecQ1HmH5VdZTF5");

  multi_part->append(textPart1);
  multi_part->append(textPart2);
  multi_part->append(imagePart);

  //network_manager_->post(request, post_data.toString().toUtf8());
  QNetworkReply *reply = network_manager_->post(request, multi_part);
  multi_part->setParent(reply);
}
