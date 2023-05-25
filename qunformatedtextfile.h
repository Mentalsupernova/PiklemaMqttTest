#ifndef QUNFORMATEDTEXTFILE_H
#define QUNFORMATEDTEXTFILE_H

#include "iqfilebase.h"
#include <QObject>

class QUnformatedTextFile :public  IQFileBase
{
    Q_OBJECT

public:
    explicit QUnformatedTextFile(QObject* parent = nullptr);
    QUnformatedTextFile();
    bool parseFile(const QString *  filename) override;
    QVector<QString> getLines() const override;
public slots:
    void ReadFileCommand(const QString & filename) override;
private:

    QVector<QString> lines;


};

#endif // QUNFORMATEDTEXTFILE_H
