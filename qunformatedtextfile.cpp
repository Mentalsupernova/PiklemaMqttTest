#include "qunformatedtextfile.h"

#include <iostream>
#include <fstream>
#include <QFile>
#include <QTextStream>
#include "Logger.h"


QUnformatedTextFile::QUnformatedTextFile(QObject* parent) : IQFileBase(parent) {}

void QUnformatedTextFile::CommandsetNumericsState(const bool& state)  {

    numericState  =state;
}

bool QUnformatedTextFile::ReadFileCommand(const QString &  filename) {
    if(numericState){
        return parseFileNumerics(&filename);
    }
        else{

     return parseFile(&filename);
        }
}

bool QUnformatedTextFile::checkLineNumerics(const QString line){
     for(QChar c : line){
         if(!c.isDigit()){
             return false;
         }
     }
     return true;
}

bool QUnformatedTextFile::parseFileNumerics(const QString *  filename) {
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
             if(checkLineNumerics(line)){

        lines.append(line);
             }
        line = in.readLine();
        counter++;

    }
    res = true;
    }

    return res;

}
bool QUnformatedTextFile::parseFile(const QString *filename){
    lines = QVector<QString>();
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
