//
// Created by Wiktoria on 21.12.2020.
//

#ifndef DROZDZWIKTORIA_FILE_H
#define DROZDZWIKTORIA_FILE_H

#include <iostream>
#include <string>
#include <fstream>
static std::ifstream file;
class readFile {
public:
    readFile() = default;
    static int rInt();   // method of the readFile class: decides whether to read the data from the file,
    static int rInt(int w); // if it has been detected, or forces the user to enter the data
    static float rfloat(float f);
    static std::string rString();
    ~readFile() = default;
};

#endif //DROZDZWIKTORIA_FILE_H
