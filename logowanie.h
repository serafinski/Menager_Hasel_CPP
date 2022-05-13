//
// Created by tsera on 07.05.2022.
//

#ifndef PROJEKT_SEMESTRALNY_CPP_LOGOWANIE_H
#define PROJEKT_SEMESTRALNY_CPP_LOGOWANIE_H
#include <fstream>
#include <iostream>
#include "haslo.h"

using std::string; using std::cout; using std::cin; using std::endl;


class logowanie {

public:

    logowanie(){
        przyznajDostep = false;
    }

    void login(){
        fstream userdata;
        userdata.open("userdata.txt");

        if(std::filesystem::exists(R"(D:\PJATK\Semestr_2\PJC\Projekt_Semestralny_CPP\user-password.txt)")){
            cout << "\nWitaj ponownie!\n" << endl;
            wyswietlpodpowiedz();

            cout << "Wpisz glowne haslo: ";
            cin >> wpisaneHaslo;
            cout << endl;

            readpassword(wpisaneHaslo);
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
