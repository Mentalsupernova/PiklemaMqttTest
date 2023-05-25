#ifndef QCONSOLEUILOGGER_H
#define QCONSOLEUILOGGER_H

#include "QILogger.h"



class QConsoleUiLogger : public QILogger
{
public:
    static QConsoleUiLogger& instance();

    // QILogger interface
private:
    QConsoleUiLogger();
    void log(const QString &message);

};

#endif // QCONSOLEUILOGGER_H
