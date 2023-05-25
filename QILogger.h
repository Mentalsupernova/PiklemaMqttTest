#ifndef QILOGGER_H
#define QILOGGER_H

#include <QObject>
#include <QString>

class QILogger :public QObject
{
public:
    Q_OBJECT

    virtual void log(const QString& message) = 0;

signals:
      virtual void messageLogged(const QString& message)=0;

};
#endif // QILOGGER_H
