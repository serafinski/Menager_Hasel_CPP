//
// Created by tsera on 17.06.2022.
//

#ifndef PROJEKT_SEMESTRALNY_CPP_GENERATOR_MANUAL_H
#define PROJEKT_SEMESTRALNY_CPP_GENERATOR_MANUAL_H
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>


using std::cout; using std::cin; using std::endl; using std::string; using std::fstream;
class generator_manual{
public:
    generator_manual();

    static int liczbaznakowmanual;
    static char decyzjamanual;
    static char literydecyjamanual;
    static string koncowehaslomanual;

//składowe hasła


/**
 * Deklaracja funkcji generator.
 * @param sciezka_zewnetrzna_kategorie - adres ścieżki zewnętrznej prowadzącej do kategorii. Potrzebna do manipulowania danymi użytkownika.
 * @param nazwakategorii - informacja o nazwie kategorii. Potrzebna do manipulowania danymi użytkownika.
 */
    static void generatormanualfun(string sciezka_zewnetrzna_kategorie,string nazwakategorii_manual);
    static void wypiszmanual(string str);
    static void zamaloznakowmanual();
    static void wszystkomanual();
    static void male_duze_cyfrymanual();
    static void male_duze_specjalnemanual();
    static void male_cyfry_specjalnemanual();
    static void duze_cyfry_specjalnemanual();
    static void male_duzemanual();
    static void male_cyfrymanual();
    static void male_specjalnemanual();
    static void duze_cyfrymanual();
    static void duze_specjalnemanual();
    static void cyfry_specjalnemanual();
    static void tylkomalemanual();
    static void tylkoduzemanual();
    static void tylkocyfrymanual();
    static void tylkospecjalnemanual();
    static void switchdecyzyjnymanual();
    static void opcjemanual();
    static void zapiszhaslomanual(string sciezka_zewnetrzna_kategorie, string nazwakategorii_manual);
};
extern string sciezka_zewnetrzna_kategorie;
extern string nazwakategorii_manual;

#endif //PROJEKT_SEMESTRALNY_CPP_GENERATOR_MANUAL_H
