#include "qconsoleuilogger.h"

QConsoleUiLogger &QConsoleUiLogger::instance()
{
    static QConsoleUiLogger logger;
    return logger;
}

QConsoleUiLogger::QConsoleUiLogger()
{

}

void QConsoleUiLogger::log(const QString &message)
{

}
