#include "workwithfiles.h"

#include <QFile>
#include <QDebug>

void Write(QString fileName, const std::vector<ulong> &outputData) {
    QString path = "../data/" + fileName + ".txt";
    QFile myFile(path);
    if (!myFile.open(QFile::WriteOnly | QFile::Text)) {
        qDebug() << "from Write";
        qDebug() << "\nWrong address to the file";
        qDebug() << path;
        return;
    }

    QTextStream out(&myFile);
    for (auto iter : outputData) {
        out << " ";
        out << iter;
    }

    myFile.flush();
    myFile.close();
}

void Read(QString fileName, std::vector<ulong> &outputData) {
    QString path = "../data/" + fileName + ".txt";
    QFile myFile(path);
    if (!myFile.open(QFile::ReadOnly | QFile::Text)) {
        qDebug() << "from Read";
        qDebug() << "\nWrong address to the file";
        qDebug() << path;
        return;
    }

    outputData.clear();
    QTextStream in(&myFile);
    QString data = in.readAll();
    std::string temp = data.toUtf8().constData();

    std::string delimiter = " ";
    std::string tempData;
    unsigned long startPos;
    unsigned long endPos = 0;
    unsigned long tempValue;
    while (temp.find(delimiter, endPos + 1) != std::string::npos) {
        startPos = endPos + 1;
        endPos = temp.find(delimiter, startPos);
        tempData = temp.substr(startPos, endPos - startPos);
        tempValue = std::stoul(tempData);
        outputData.push_back(tempValue);
    }
    myFile.close();
}
