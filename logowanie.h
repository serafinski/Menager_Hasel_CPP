//
// Created by tsera on 07.05.2022.
//

#ifndef PROJEKT_SEMESTRALNY_CPP_LOGOWANIE_H
#define PROJEKT_SEMESTRALNY_CPP_LOGOWANIE_H

#include <iostream>
#include "logo.h"
using std::string; using std::cout; using std::cin; using std::endl;


class logowanie {

public:
    string wpisaneHaslo;

    logowanie(){
        przyznajDostep = false;
    }


    void login(){
        string logo = "logo.txt";
        printASCII(logo);

        cout << "Wpisz glowne haslo: ";
        cin >> wpisaneHaslo;
        cout << endl;

        if(wpisaneHaslo == glowneHaslo){
            cout << "Wpisane haslo jest poprawne! Witaj!" <<endl;
        }
        else{
            cout << "Wpisane haslo jest nie poprawne, sprobuj ponownie!" << endl;
            login();
        }
    }

private:
    string glowneHaslo = "haslo";
    bool przyznajDostep;
};



#endif //PROJEKT_SEMESTRALNY_CPP_LOGOWANIE_H
