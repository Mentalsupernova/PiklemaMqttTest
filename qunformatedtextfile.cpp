#include "qunformatedtextfile.h"

#include <iostream>
#include <fstream>
#include <QFile>
#include <QTextStream>


QUnformatedTextFile::QUnformatedTextFile(QObject* parent) : IQFileBase(parent) {}


void QUnformatedTextFile::ReadFileCommand(const QString *  filename) {
    lines = parseFile(filename);
    for (const QString &line : lines) {
        emit lineRead(line);
    }
}


QVector<QString> QUnformatedTextFile::parseFile(const QString *filename){
    QFile file("modules");
    QVector<QString> lines;
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){

    }


    QTextStream in(&file);
    QString line = in.readLine();
    while (!line.isNull()) {
        lines.append(line);
        line = in.readLine();

    }
    return lines;

}


QVector<QString> QUnformatedTextFile::getLines() const{
    return lines;
}
