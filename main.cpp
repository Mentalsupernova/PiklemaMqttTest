#include <IQFileBase.h>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QStringLiteral>
#include <QUnformatedTextFile.h>
#include <QQmlContext>>
#include <QStringLiteral>


int main(int argc, char *argv[])
{
QGuiApplication app(argc, argv);

QQmlApplicationEngine engine;

qmlRegisterType<QUnformatedTextFile>("QUnformatedTextFile", 1, 0, "QUnformatedTextFile");

IQFileBase *fileReader = new QUnformatedTextFile(&app);
engine.rootContext()->setContextProperty("fileReader", fileReader);

engine.load(QUrl(QStringLiteral("qrc:/PiklemaMqttTest/Main.qml")));

return app.exec();
}
