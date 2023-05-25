#ifndef MQTTCLIENT_H
#define MQTTCLIENT_H

#include <QObject>
#include <QtMqtt>

class MqttClient : public QObject
{
Q_OBJECT
public:
    explicit MqttClient(QObject *parent = nullptr);
    ~MqttClient();

    void disconnectFromBroker();

signals:
    void connected();
    void disconnected();
    void messagePublished(const QString &topic, const QString &message);

public slots:
    void connectToBroker(const QString &host, quint16 port);
    void onConnected();
    void onDisconnected();
    void onStateChanged(QMqttClient::ClientState state);
    void onMessageReceived(const QByteArray &message, const QMqttTopicName &topic);
    void publishMessage(const QString &topic,const QVector<QString> &lines);

private:
    QMqttClient *client;
};

#endif // MQTTCLIENT_H
