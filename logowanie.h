//
// Created by tsera on 07.05.2022.
//

#ifndef PROJEKT_SEMESTRALNY_CPP_LOGOWANIE_H
#define PROJEKT_SEMESTRALNY_CPP_LOGOWANIE_H
#include <fstream>
#include <iostream>
#include "Switch_Manual.h"

using std::string; using std::cout; using std::cin; using std::endl;
class logowanie {

public:
    logowanie();

    void poprzednielogowanie();
    void login();

    static string imie_login;
    static string sciezka_login;
    static string sciezka_podpowiedz;
    static string sciezka_zewnetrzna_hint;
    static string sciezka_zewnetrzna_master;
    static string sciezka_zewnetrzna_last;
    static string sciezka_zewnetrzna_kategorie;
private:
    static string wpisaneHaslo;
};


#endif //PROJEKT_SEMESTRALNY_CPP_LOGOWANIE_H