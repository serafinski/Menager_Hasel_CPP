//
// Created by tsera on 13.05.2022.
//

#ifndef PROJEKT_SEMESTRALNY_CPP_PRINTLOGO_H
#include <iostream>
#include <string>
#include <fstream>

using std::fstream; using std::string; using std::getline; using std::cout; using std::endl;

void printlogo(){
    fstream fileIn;
    fileIn.open(R"(D:\PJATK\Semestr_2\PJC\Projekt_Semestralny_CPP\logo.txt)",std::ios::in);
    if(fileIn.is_open()){
        string line;
        while (getline(fileIn,line)){
            cout<<line<<endl;
        }
        fileIn.close();
    }
}

#define PROJEKT_SEMESTRALNY_CPP_PRINTLOGO_H

#endif //PROJEKT_SEMESTRALNY_CPP_PRINTLOGO_H
