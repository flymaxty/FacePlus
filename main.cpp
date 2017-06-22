#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "faceplusplus.h"

int main(int argc, char *argv[])
{
  QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
  QGuiApplication app(argc, argv);

  QQmlApplicationEngine engine;
  engine.load(QUrl(QLatin1String("qrc:/main.qml")));
  if (engine.rootObjects().isEmpty())
    return -1;

  FacePlusPlus faceplusplus;

  faceplusplus.RequestData();

  return app.exec();
}
