#ifndef IQFILEBASE_H
#define IQFILEBASE_H

#include <QObject>

    class IQFileBase : public QObject {
        Q_OBJECT

    public:
        explicit IQFileBase(QObject* parent = nullptr) : QObject(parent) {}
        virtual QVector<QString> parseFile(const QString * filename) = 0;
        virtual void ReadFileCommand(const QString * filename) = 0;
        virtual QVector<QString> getLines() const = 0;


    signals:
        void lineRead(const QString &lineContent);
        void fileErrorSignal(QString error);
};

#endif // IQFILEBASE_H
