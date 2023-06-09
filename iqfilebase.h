#ifndef IQFILEBASE_H
#define IQFILEBASE_H

#include <QObject>

    class IQFileBase : public QObject {
        Q_OBJECT

    public:
        explicit IQFileBase(QObject* parent = nullptr) : QObject(parent) {}
        virtual bool parseFile(const QString * filename) = 0;

   public slots:
        virtual bool ReadFileCommand(const QString& filename) = 0;
        virtual QVector<QString> getLines() const = 0;
    virtual void CommandsetNumericsState(const bool& state) =0;
    signals:
        void lineRead(const QString &lineContent);
        void fileErrorSignal(QString error);
};

#endif // IQFILEBASE_H
