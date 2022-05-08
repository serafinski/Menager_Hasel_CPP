//
// Created by tsera on 07.05.2022.
//

#ifndef PROJEKT_SEMESTRALNY_CPP_LOGO_H
#define PROJEKT_SEMESTRALNY_CPP_LOGO_H

#include <iostream>
#include <string>
#include <fstream>

using std::string; using std::ifstream; using std::getline; using std::cout; using std::endl;

void printASCII(string nazwapliku){

    string line = "";
    ifstream wPliku;
    wPliku.open("logo.txt");

    if(wPliku.is_open()){
        while (getline(wPliku,line)){
            cout << line << endl;
        }
    }
    else{
        cout << "Nie udalo sie wczytac loga! :(" << endl;
    }

    wPliku.close();
}

#endif //PROJEKT_SEMESTRALNY_CPP_LOGO_H
