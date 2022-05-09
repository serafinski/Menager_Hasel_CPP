//
// Created by tsera on 07.05.2022.
//

#ifndef PROJEKT_SEMESTRALNY_CPP_LOGOWANIE_H
#define PROJEKT_SEMESTRALNY_CPP_LOGOWANIE_H
#include <fstream>
#include <iostream>
#include "logo.h"
#include "haslo.h"

using std::string; using std::cout; using std::cin; using std::endl;


class logowanie {

public:

    logowanie(){
        przyznajDostep = false;
    }

    void login(){
        //string logo = "logo.txt";
        //printASCII(logo);

        ifstream userdata;
        userdata.open("userdata.txt");

        if(userdata){
            cout << "Wpisz glowne haslo: ";
            cin >> wpisaneHaslo;
            cout << endl;

            if(wpisaneHaslo == glowneHaslo){
                cout << "Wpisane haslo jest poprawne! Witaj!" <<endl;
            }
            else{
                cout << "Wpisane haslo jest nie poprawne - moga wystapic problemy!" << endl;
            }
        }
        else{
            nowy_user();
            }

        }

private:
    string wpisaneHaslo;
    string glowneHaslo = "haslo";
    bool przyznajDostep;
};


#endif //PROJEKT_SEMESTRALNY_CPP_LOGOWANIE_H
