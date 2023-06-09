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
    bool parseFileNumerics(const QString *  filename) ;
public slots:
    bool ReadFileCommand(const QString & filename) override;
    QVector<QString> getLines() const override;
    void CommandsetNumericsState(const bool& state) override;
private:
   bool numericState= false;
    bool checkLineNumerics(const QString line);

    QVector<QString> lines;


};

#endif // QUNFORMATEDTEXTFILE_H
