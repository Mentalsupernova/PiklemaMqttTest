#include "ILogger.h"
#include "mqttclient.h"

#include <IQFileBase.h>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QStringLiteral>
#include <QUnformatedTextFile.h>
#include <QQmlContext>
#include <Logger.h>
#include <QQmlEngine>

#include <QObject>


#include <QDebug>
class A{

};

int main(int argc, char *argv[])
{

    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;



    qmlRegisterType<MqttClient>("MqttClient", 1, 0, "MqttClient");
    qmlRegisterType<QUnformatedTextFile>("QUnformatedTextFile", 1, 0, "QUnformatedTextFile");

    engine.rootContext()->setContextProperty("Logger", &Logger::instance());

    IQFileBase *fileReader = new QUnformatedTextFile(&app);
    MqttClient *mqttClient = new MqttClient(&app);
    engine.rootContext()->setContextProperty("fileReader", fileReader);
    engine.rootContext()->setContextProperty("mqttClient", mqttClient);

    engine.load(QUrl(QStringLiteral("qrc:/PiklemaMqttTest/Main.qml")));

    return app.exec();

}
