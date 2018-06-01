#ifndef WORDWITHFILES_H
#define WORDWITHFILES_H

#include<QString>

void Write(QString fileName, const std::vector<ulong> &outputData);

void Read(QString fileName, std::vector<ulong> &outputData);

#endif // WORDWITHFILES_H
