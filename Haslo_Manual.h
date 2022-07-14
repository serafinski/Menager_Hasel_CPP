//
// Created by tsera on 16.06.2022.
//

#ifndef PROJEKT_SEMESTRALNY_CPP_HASLO_MANUAL_H
#define PROJEKT_SEMESTRALNY_CPP_HASLO_MANUAL_H
#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <cstdint>
#include <vector>

using std::string; using std::cout; using std::cin; using std::endl; using std::ofstream; using std::fstream;
class Haslo_Manual{
public:
    Haslo_Manual();

    static string liniadousunieciamanual;
    static void showCategory_Manual(string sciezka_zewnetrzna_kategorie);
    static void addCategory_Manual(string sciezka_zewnetrzna_kategorie);
    static void removeCategory_Manual(string sciezka_zewnetrzna_kategorie,string nazwa);
    static void deleteaccount_Manual(string sciezka_zewnetrzna_hint,
                              string sciezka_zewnetrzna_master,
                              string sciezka_zewnetrzna_last,
                              string sciezka_zewnetrzna_kategorie);
    static void addname_Manual(string sciezka_zewnetrzna_kategorie,string nazwakategorii, string nazwahasla);
    static void addlogin_Manual(string sciezka_zewnetrzna_kategorie, string nazwakategorii, string login);
    static void addpassword_Manual(string sciezka_zewnetrzna_kategorie,string nazwakategorii, string haslo);
    static void addwww_Manual(string sciezka_zewnetrzna_kategorie,string nazwakategorii, string www);
    static void showcategorycontents_Manual(string sciezka_zewnetrzna_kategorie,string nazwakategorii);
    static void deletename_Manual(string sciezka_zewnetrzna_kategorie, string nazwakategorii, unsigned int nr);
    static void deletelogin_Manual(string sciezka_zewnetrzna_kategorie, string nazwakategorii, unsigned int nr);
    static void deletepassword_Manual(string sciezka_zewnetrzna_kategorie, string nazwakategorii, unsigned int nr);
    static void deletewww_Manual(string sciezka_zewnetrzna_kategorie, string nazwakategorii, unsigned int nr);
    static std::fstream& GotoLineManual(std::fstream& file, unsigned int num);
    static void getline_Manual(string sciezka_zewnetrzna_kategorie, string nazwakategorii, unsigned int nr);
    static void printpassword_Manual();
    static void changepassword_Manual(string sciezka_zewnetrzna_kategorie,string nazwakategorii, string nowehaslo);
    static void concatnamefiles_Manual(string sciezka_zewnetrzna_kategorie);
    static void concatloginfiles_Manual(string sciezka_zewnetrzna_kategorie);
    static void concatpasswordsfiles_Manual(string sciezka_zewnetrzna_kategorie);
    static void concatwwwfiles_Manual(string sciezka_zewnetrzna_kategorie);
    static void concatall_Manual(string sciezka_zewnetrzna_kategorie);
    static void sortnamesalphabet_Manual(string sciezka_zewnetrzna_kategorie);
    static void sortloginsalphabet_Manual(string sciezka_zewnetrzna_kategorie);
    static void sortpasswordsalphabet_Manual(string sciezka_zewnetrzna_kategorie);
    static void sortwwwalphabet_Manual(string sciezka_zewnetrzna_kategorie);
};
#endif //PROJEKT_SEMESTRALNY_CPP_HASLO_MANUAL_H
