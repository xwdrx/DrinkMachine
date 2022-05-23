//
// Created by Wiktoria on 23.11.2020.
//
#include <iostream>
#include <string>
#include "Drink.h"
#include "Automat.h"
#include "readFile.h"
#include "Exception.h"

using namespace std;
//std::ifstream plik;

int main(int argc, char **argv) {

    if (argc > 1) {
        file.open(argv[1]);                         // checking if the file was successfully readed
        if (file.is_open()) {
            cout << "the file was read successfully" << endl;
            for (int i = 0; i < argc; i++) {
                cout << i << ":" << argv[i] << endl;
            }
        }
    }else std::cout<<"Data file not found" <<std::endl;

    std::cout << "___________________________________________" << std::endl;
    bool out = true;
    string uChoise;
    Automat start;
    do {
        start.show();
        start.nominal();
        start.show();
        if (!start.isEmpty()) {
            cout << "Do you want to buy one more product? yes or no (enter answer):" << endl;
            uChoise = readFile::rString();
            if (uChoise == "yes")
                out = false;
            if (uChoise != "no" && uChoise != "yes") {
                cout << "error, message not recognized" << endl;
                out = true;
            }
            if (uChoise == "no") out = true;
        } else out = true;
    } while (!out);
    if (argc > 1) file.close();
    return 0;
}

// method of the readFile class: decides whether to read the data from the file, if it has been detected, or forces the user to enter the data
int readFile::rInt() {
    std::string string1;
    if (file.is_open())
    {
        std::getline(file, string1);
        while (string1.find(' ') != std::string::npos)
            string1.erase(string1.find(' '),1);
    } else {
        std::getline(std::cin, string1);
        while (string1.find(' ') != std::string::npos) string1.erase(string1.find(' '), 1);
    }
    int tmp = atoi(string1.c_str());
    if (tmp < 1 || tmp > 3) throw Apayment();
    return tmp;
}

int readFile::rInt(int w) {
    std::string string1;
    if (file.is_open())
    {
        std::getline(file, string1);
        while (string1.find(' ') != std::string::npos)
            string1.erase(string1.find(' '),
                          1);
    } else {
        std::getline(std::cin, string1);
        while (string1.find(' ') != std::string::npos) string1.erase(string1.find(' '), 1);
    }
    int tmp = atoi(string1.c_str());
    if (tmp < 0 || tmp > 3) throw Aid();
    return tmp;
}

float readFile::rfloat(float f) {
    std::string string1;
    if (file.is_open())
    {
        std::getline(file, string1);
        while (string1.find(' ') != std::string::npos)
            string1.erase(string1.find(' '),1);
    } else {
        std::getline(std::cin, string1);
        while (string1.find(' ') != std::string::npos) string1.erase(string1.find(' '), 1);
    }
    return stof(string1);
}

std::string readFile::rString() {
    std::string string1;
    if (file.is_open()) {
        std::getline(file, string1);
        while (string1.find(' ') != std::string::npos) string1.erase(string1.find(' '), 1);
    } else {
        std::getline(std::cin, string1);
        while (string1.find(' ') != std::string::npos) string1.erase(string1.find(' '), 1);
    }
    return string1;
}