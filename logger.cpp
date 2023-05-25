#include "Logger.h"
#include <QDebug>
#include <QDateTime>

Logger::Logger()
    : QObject(nullptr)
{
}

Logger& Logger::instance()
{
    static Logger logger;
    return logger;
}

void Logger::log(const QString& message)
{
    QString formattedMessage = QString("[%1] %2").arg(QDateTime::currentDateTime().toString(), message);
    qDebug() << formattedMessage;
    emit messageLogged(formattedMessage);
}
