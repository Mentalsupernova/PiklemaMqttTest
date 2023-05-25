#include "qunformatedtextfile.h"

#include <iostream>
#include <fstream>
#include <QFile>
#include <QTextStream>


QUnformatedTextFile::QUnformatedTextFile(QObject* parent) : IQFileBase(parent) {}


void QUnformatedTextFile::ReadFileCommand(const QString *  filename) {
     parseFile(filename);
    for (const QString &line : lines) {
        emit lineRead(line);
    }
}


bool QUnformatedTextFile::parseFile(const QString *filename){
    QFile file("modules");
    bool res = false;
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        res = false;
    }else{

    QTextStream in(&file);
    QString line = in.readLine();
    while (!line.isNull()) {
        lines.append(line);
        line = in.readLine();

    }
    res = true;
    }

    return res;

}


QVector<QString> QUnformatedTextFile::getLines() const{
    return lines;
}
