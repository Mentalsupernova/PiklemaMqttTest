#include "qunformatedtextfile.h"

#include <iostream>
#include <fstream>
#include <QFile>
#include <QTextStream>
#include "Logger.h"


QUnformatedTextFile::QUnformatedTextFile(QObject* parent) : IQFileBase(parent) {}


bool QUnformatedTextFile::ReadFileCommand(const QString &  filename) {
     return parseFile(&filename);
}


bool QUnformatedTextFile::parseFile(const QString *filename){
    QString rawPath = *filename;
    rawPath.replace("file:","");
    QFile file(rawPath);
    bool res = false;
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        Logger::instance().log("Error, file open error!");
        res = false;
    }else{


    QTextStream in(&file);
    QString line = in.readLine();
    int counter = 0;
    while (!line.isNull()) {
        lines.append(line);
        QString loggerOut = "File line number %1 : %2";
        QString tmp= loggerOut.arg(counter).arg(line);
        Logger::instance().log(tmp);
        line = in.readLine();
        counter++;

    }
    res = true;
    }

    return res;

}


QVector<QString> QUnformatedTextFile::getLines() const{
    return lines;
}
