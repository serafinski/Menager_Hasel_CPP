//
// Created by tsera on 09.05.2022.
//

#ifndef PROJEKT_SEMESTRALNY_CPP_HASLO_H
#define PROJEKT_SEMESTRALNY_CPP_HASLO_H
#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <cstdint>
#include <vector>

using std::string; using std::cout; using std::cin; using std::endl; using std::ofstream; using std::fstream;
class haslo{
public:
    haslo();

    static string imie;
    static string haslo1;
    static string haslo2;
    static string tekst;
    static string sciezkamaster;
    static string podpowiedzmaster;
    static string nazwaKataloguKategorie;
    static string nazwaKataloguNazwy;
    static string nazwaKataloguLoginy;
    static string nazwaKataloguHasla;
    static string nazwaKataloguWWW;
    static string nazwaKataloguConcat;
    static string liniadousuniecia;
    static void zledane();
    static void nowy_user();
    static void readpassword(string sciezka,string password);
    static bool confirmdeletion(string sciezka,string password);
    static void wyswietlpodpowiedz(string sciezka);
    static void showCategory(string imie_login);
    static void addCategory(string imie_login);
    static void addCategorynewUser();
    static void removeCategory(string imie_login,string nazwa);
    static void stworzkategorie();
    static void createtimestamp();
    static void overwritetimestampnewuser();
    static void overwritetimestamp(string imie_login);
    static void overwritetimestampmanual(string sciezka);
    static void readtimestamp(string imie_login);
    static void readtimestampmanual(string sciezka);
    static void deleteaccount(string imie_login);
    static void addname(string imie_login,string nazwakategorii, string nazwahasla);
    static void addlogin(string imie_login, string nazwakategorii, string login);
    static void addpassword(string imie_login,string nazwakategorii, string haslo);
    static void addwww(string imie_login,string nazwakategorii, string www);
    static void showcategorycontents(string imie_login,string nazwakategorii);
    static void deletename(string imie_login, string nazwakategorii, unsigned int nr);
    static void deletelogin(string imie_login, string nazwakategorii, unsigned int nr);
    static void deletepassword(string imie_login, string nazwakategorii, unsigned int nr);
    static void deletewww(string imie_login, string nazwakategorii, unsigned int nr);
    static std::fstream& GotoLine(std::fstream& file, unsigned int num);
    static void getline(string imie_login, string nazwakategorii, unsigned int nr);
    static void printpassword();
    static void changepassword(string imie_login,string nazwakategorii, string nowehaslo);
    static void concatnamefiles(string imie_login);
    static void concatloginfiles(string imie_login);
    static void concatpasswordsfiles(string imie_login);
    static void concatwwwfiles(string imie_login);
    static void concatall(string imie_login);
    static void sortnamesalphabet(string imie_login);
    static void sortloginsalphabet(string imie_login);
    static void sortpasswordsalphabet(string imie_login);
    static void sortwwwalphabet(string imie_login);
};

#endif //PROJEKT_SEMESTRALNY_CPP_HASLO_H
