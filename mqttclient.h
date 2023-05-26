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
    void setCount(int value);

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
    void publishMessage(const QString &topic,const QVector<QString> &lines,const QString &user,const QString &password);

private:
    QMqttClient *client;
    void logStat(QString topic);
    int m_count;
};

#endif // MQTTCLIENT_H
