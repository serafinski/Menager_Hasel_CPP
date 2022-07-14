//
// Created by tsera on 12.05.2022.
//

#ifndef PROJEKT_SEMESTRALNY_CPP_GENERATOR_H
#define PROJEKT_SEMESTRALNY_CPP_GENERATOR_H
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>


using std::cout; using std::cin; using std::endl; using std::string; using std::fstream;
class generator{
public:
    generator();

    static int liczbaznakow;
    static char decyzja;
    static char literydecyja;
    static string koncowehaslo;

    static void generatorname(string imie_login, string nazwakategorii);
    static void wypisz(string str);
    static void zamaloznakow();

    static void wszystko();
    static void male_duze_cyfry();
    static void male_duze_specjalne();
    static void male_cyfry_specjalne();
    static void duze_cyfry_specjalne();
    static void male_duze();
    static void male_cyfry();
    static void male_specjalne();
    static void duze_cyfry();
    static void duze_specjalne();
    static void cyfry_specjalne();
    static void tylkomale();
    static void tylkoduze();
    static void tylkocyfry();
    static void tylkospecjalne();
    static void switchdecyzyjny();
    static void opcje();
    static void zapiszhaslo(string imie_login, string nazwakategorii);
};
extern string imie_login;
extern string nazwakategorii;


#endif //PROJEKT_SEMESTRALNY_CPP_GENERATOR_H
