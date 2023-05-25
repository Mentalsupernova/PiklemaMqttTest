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
    /*
    A a;

    QMqttClient *m_client = new QMqttClient(QObject\obj);
    m_client->setHostname("test.mosquitto.org");
    m_client->setPort(static_cast<quint16>(1883));
    //m_client->subscribe("piklema/test");

    QString message = "123";
    QByteArray payload = message.toUtf8();
    QMqttTopicName mqttTopic("piklema/test");
    QMqttPublishProperties properties;
    QObject::connect(m_client, &QMqttClient::messageReceived, m_client, [m_client](const QByteArray &payload, const QMqttTopicName &topic) {
        const QString content = QDateTime::currentDateTime().toString()
                                + QLatin1String(" Received Topic: ")
                                + topic.name()
                                + QLatin1String(" Message: ")
                                + payload
                                + QLatin1Char('\n');
        qDebug() <<content;
    });

    m_client->publish(mqttTopic, payload);
*/
//    if(m_client->requestPing())
 //       qDebug()<<"im alive!";


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
