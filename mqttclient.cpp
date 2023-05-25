#include "mqttclient.h"
#include "logger.h"

MqttClient::MqttClient(QObject *parent) : QObject(parent)
{
    client = new QMqttClient(parent);

    connect(client, &QMqttClient::connected, this, &MqttClient::onConnected);
    connect(client, &QMqttClient::disconnected, this, &MqttClient::onDisconnected);
    connect(client, &QMqttClient::stateChanged, this, &MqttClient::onStateChanged);
    connect(client, &QMqttClient::messageReceived, this, &MqttClient::onMessageReceived);

    Logger::instance().log("Constructing client;");
}

MqttClient::~MqttClient()
{
    if (client->state() == QMqttClient::Connected) {
        client->disconnectFromHost();
    }
    delete client;
}

void MqttClient::connectToBroker(const QString &host, quint16 port)
{
    QString clearHost =host;
    clearHost.replace("\n\n","");
    qDebug()<< clearHost << " " << port;

    client->setHostname(clearHost);
    client->setPort(port);
    client->connectToHost();
}

void MqttClient::disconnectFromBroker()
{
    client->disconnectFromHost();
}

void MqttClient::publishMessage(const QString &topic,const QVector<QString> &lines)
{
    if (client->state() == QMqttClient::Connected) {

        for(auto i: lines){
            Logger::instance().log("Sending line : "+i);
        }
        //QByteArray payload = message.toUtf8();
        //QMqttTopicName mqttTopic(topic);
        //QMqttPublishProperties properties;
        //client->publish(mqttTopic, payload);
        //Logger::instance().log("message");
    }
}

void MqttClient::onConnected()
{
    emit connected();
}

void MqttClient::onDisconnected()
{
    emit disconnected();
}

void MqttClient::onStateChanged(QMqttClient::ClientState state)
{
    Q_UNUSED(state)
    // Handle state changes if needed
}

void MqttClient::onMessageReceived(const QByteArray &message, const QMqttTopicName &topic)
{
    Q_UNUSED(message)
    Q_UNUSED(topic)
    // Handle incoming messages if needed

}



