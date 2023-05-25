#ifndef QUILOGGER_H
#define QUILOGGER_H

#include <QObject>

class  QUiLogger
{
public:
    QUiLogger();
signals:
    void static onNewLog(QString newMessage);
};

#endif // QUILOGGER_H
