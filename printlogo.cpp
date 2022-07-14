//
// Created by tsera on 29.06.2022.
//
#include "printlogo.h"

printlogo::printlogo() = default;

/**
* Funkcja pozwalająca wypisać napis zawarty w pliku tekstowym.
*/
void printlogo::printlogofun(){

    fstream fileIn;

    fileIn.open("../logo.txt",std::ios::in);

    if(fileIn.is_open()){
        string line;
        while (getline(fileIn,line)){
            cout<<line<<endl;
        }
        fileIn.close();
    }
}


