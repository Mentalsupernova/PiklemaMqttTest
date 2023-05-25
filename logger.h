#ifndef LOGGER_H
#define LOGGER_H

#include <QObject>
#include <QString>
#include "ILogger.h"

class Logger : public QObject, public ILogger
{
    Q_OBJECT

public:
    static Logger& instance();

public slots:
    void log(const QString& message) ;

signals:
    void messageLogged(const QString& message);

private:
    Logger();
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;
};

#endif // LOGGER_H
