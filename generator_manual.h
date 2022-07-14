//
// Created by tsera on 17.06.2022.
//

#ifndef PROJEKT_SEMESTRALNY_CPP_GENERATOR_MANUAL_H
#define PROJEKT_SEMESTRALNY_CPP_GENERATOR_MANUAL_H
#include <iostream>
#include <string>
#include <vector>
#include <sstream>


using std::cout; using std::cin; using std::endl;

int liczbaznakowmanual;
char decyzjamanual;
char literydecyjamanual;
extern string sciezka_zewnetrzna_kategorie;
extern string nazwakategorii_manual;
string koncowehaslomanual;

//składowe hasła
char malemanual[] = "abcdefghijklmnopqrstuvwxyz";
char DUZEmanual[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char cyfrymanual[] = "0123456789";
char specjalnemanual[] = "!@#$%^&*";

/**
 * Deklaracja funkcji generator.
 * @param sciezka_zewnetrzna_kategorie - adres ścieżki zewnętrznej prowadzącej do kategorii. Potrzebna do manipulowania danymi użytkownika.
 * @param nazwakategorii - informacja o nazwie kategorii. Potrzebna do manipulowania danymi użytkownika.
 */
void generatormanual(string sciezka_zewnetrzna_kategorie,string nazwakategorii_manual);


/**
 * Funkcja służąca do generowania hasła.
 * @param str - ciąg znaków z którego będzie generowane hasło.
 */
void wypiszmanual(string str){
    std::stringstream buffer;

    cout <<"Twoje haslo to: ";

    int stringsize = str.size();
    srand(time(NULL));

    for(int i = 0; i < liczbaznakowmanual; i++){
        buffer << str[rand() % stringsize];
    }
    koncowehaslomanual = buffer.str();
    cout << koncowehaslomanual << endl;
}


/**
 * Funkcja sprawdzająca czy podane hasło jest za krótkie.
 * Jeżeli hasło jest za krótkie (ma poniżej 10 znaków) - program pyta użytkownika czy chce zmienić długość hasła.
 * Jeżeli użytkownik chce zmienić długość hasła - funkcja wywoływana jest ponownie.
 * Jeżeli użytkownik nie chce zmienić długości hasła - funkcja wypisuje długość hasła.
 */
void zamaloznakowmanual(){
    cin.clear();
    cin.ignore(INT_MAX,'\n');

    cout << "\nPODANE HASLO NIE JEST ZBYT BEZPIECZNE!\nCzy chcesz wybrac dlugosc hasla jeszcze raz?" <<endl;
    cout << "Wpisz:\nt - dla tak!\nn - dla nie!\n\nTwoja decyzja:";
    cin >> decyzjamanual;

    /**
     * Sprawdzenie input ze strony użytkownika jest poprawny.
     * Jeżeli nie jest, program prosi użytkownika o wprowadzenie prawidłowej wartości.
     * @param decyzjamanual - decyzja użytkownika czy chce zatrzymać wpisaną długość hasła czy nie.
     */
    while (decyzjamanual != 't' && decyzjamanual != 'n'){

        //czyszczenie odpowiedzi
        cin.clear();
        cin.ignore(INT_MAX,'\n'); //usuwanie \n -> niweluje problem dublowania

        cout << "\nWprowadzono nieprawidlowa opcje - prosze sprobowac ponownie.\n" << endl;
        cout << "PODANE HASLO NIE JEST ZBYT BEZPIECZNE!\nCzy chcesz wybrac dlugosc hasla jeszcze raz?" <<endl;
        cout << "Wpisz:\nt - dla tak!\nn - dla nie!\n\nTwoja decyzja:";
        cin >> decyzjamanual;
    }
    /**
     * Jeżeli użytkownik chce ponownie wybrać długość hasła.
     * @param decyzjamanual - decyzja użytkownika czy chce zatrzymać wpisaną długość hasła czy nie.
     */
    if (decyzjamanual == 't'){
        cout << "\n###################################################################" << endl;
        cout << "\nWpisz ile znakow ma miec twoje haslo: ";
        cin >> liczbaznakowmanual;

        if(liczbaznakowmanual < 10){
            zamaloznakowmanual();
        }
    }
    /**
     * Jeżeli użytkownik chce zatrzymać długość hasła.
     * @param decyzjamanual - decyzja użytkownika czy chce zatrzymać wpisaną długość hasła czy nie.
     */
    if(decyzjamanual == 'n') {
        if(liczbaznakowmanual == 1)
            cout << "\nWybrana dlugosc hasla: " << liczbaznakowmanual <<" znak!" << endl;
        else if(liczbaznakowmanual >1 && liczbaznakowmanual<5){
            cout << "\nWybrana dlugosc hasla: " << liczbaznakowmanual <<" znaki!" << endl;
        }
        else if(liczbaznakowmanual>=5 && liczbaznakowmanual<10)
            cout << "\nWybrana dlugosc hasla: " << liczbaznakowmanual <<" znakow!" << endl;
    }
}

/**
 * Funkcja pozwalająca na generowanie hasła składającego się z małych i dużych liter oraz cyfr i znaków specjalnych.
 */
void wszystkomanual(){
    cout << "\nWybrano male i duze litery oraz cyfry i znaki specjalne!\n" << endl;

    string str = string(malemanual) + DUZEmanual + cyfrymanual + specjalnemanual;
    wypiszmanual(str);
    cout << endl;
}

/**
 * Funkcja pozwalająca na generowanie hasła składającego się małych i dużych liter oraz cyfr.
 */
void male_duze_cyfrymanual(){
    cout << "\nWybrano male i duze litery oraz cyfry!\n" << endl;

    string str = string(malemanual) + DUZEmanual + cyfrymanual;
    wypiszmanual(str);
    cout << endl;
}

/**
 * Funkcja pozwalająca na generowanie hasła składającego się małych i dużych liter oraz znaków specjalnych.
 */
void male_duze_specjalnemanual(){
    cout << "\nWybrano male i duze litery oraz znaki specjalne!\n" << endl;

    string str = string(malemanual) + DUZEmanual + specjalnemanual;
    wypiszmanual(str);
    cout << endl;
}
/**
 * Funkcja pozwalająca na generowanie hasła składającego się małych liter oraz cyfr i znaków specjalnych.
 */
void male_cyfry_specjalnemanual(){
    cout << "\nWybrano male litery oraz cyfry i znaki specjalne!\n" << endl;

    string str = string(malemanual) + cyfrymanual + specjalnemanual;
    wypiszmanual(str);
    cout << endl;
}
/**
 * Funkcja pozwalająca na generowanie hasła składającego się z dużych liter oraz cyfr i znaków specjalnych.
 */
void duze_cyfry_specjalnemanual(){
    cout << "\nWybrano duze litery oraz cyfry i znaki specjalne!\n" << endl;

    string str = string(DUZEmanual) + cyfrymanual + specjalnemanual;
    wypiszmanual(str);
    cout << endl;
}
/**
 * Funkcja pozwalająca na generowanie hasła składającego się z małych i dużych liter.
 */
void male_duzemanual(){
    cout << "\nWybrano male i duze litery!\n" << endl;

    string str = string(malemanual) + DUZEmanual;
    wypiszmanual(str);
    cout << endl;
}
/**
 * Funkcja pozwalająca na generowanie hasła składającego się z małych liter oraz cyfr.
 */
void male_cyfrymanual(){
    cout << "\nWybrano male litery oraz cyfry!\n" << endl;

    string str = string(malemanual) + cyfrymanual;
    wypiszmanual(str);
    cout << endl;
}
/**
 * Funkcja pozwalająca na generowanie hasła składającego się z małych liter oraz znaków specjalnych.
 */
void male_specjalnemanual(){
    cout << "\nWybrano male litery oraz znaki specjalne!\n" << endl;

    string str = string(malemanual) + specjalnemanual;
    wypiszmanual(str);
    cout << endl;
}
/**
 * Funkcja pozwalająca na generowanie hasła składającego się z dużych liter oraz cyfr.
 */
void duze_cyfrymanual(){
    cout << "\nWybrano duze litery oraz cyfry!\n" << endl;
    string str = string(DUZEmanual) + cyfrymanual;
    wypiszmanual(str);
    cout << endl;
}
/**
 * Funkcja pozwalająca na generowanie hasła składającego się z dużych liter oraz znaków specjalnych.
 */
void duze_specjalnemanual(){
    cout << "\nWybrano duze litery oraz znaki specjalne!\n" << endl;

    string str = string(DUZEmanual) + specjalnemanual;
    wypiszmanual(str);
    cout << endl;
}
/**
 * Funkcja pozwalająca na generowanie hasła składającego się z cyfr i znaków specjalnych.
 */
void cyfry_specjalnemanual(){
    cout << "\nWybrano cyfry i znaki specjalne!\n" << endl;

    string str = string(cyfrymanual) + specjalnemanual;
    wypiszmanual(str);
    cout << endl;
}
/**
 * Funkcja pozwalająca na generowanie hasła składającego się z małych liter.
 */
void tylkomalemanual(){
    cout << "\nwybrano tylko male litery!\n" << endl;

    string str = string(malemanual);
    wypiszmanual(str);
    cout << endl;
}
/**
 * Funkcja pozwalająca na generowanie hasła składającego się dużych liter.
 */
void tylkoduzemanual(){
    cout << "\nWYBRANO TYLKO DUZE LITERY!\n" << endl;

    string str = string(DUZEmanual);
    wypiszmanual(str);
    cout << endl;
}
/**
 * Funkcja pozwalająca na generowanie hasła składającego się z cyfr.
 */
void tylkocyfrymanual(){
    cout << "\nWybrano tylko same cyfry!\n" << endl;

    string str = string(cyfrymanual);
    wypiszmanual(str);
    cout << endl;
}
/**
 * Funkcja pozwalająca na generowanie hasła składającego się ze znaków specjalnych.
 */
void tylkospecjalnemanual(){
    cout << "\nWybrano tylko znaki specjalne!\n" << endl;

    string str = string(specjalnemanual);
    wypiszmanual(str);
    cout << endl;
}

/**
 * Switch umożliwiający użytkownikowi wybór typu hasła który chce wygenerować.
 */
void switchdecyzyjnymanual(){
    switch (literydecyjamanual) {
        case '1':
            wszystkomanual();
            break;
        case '2':
            male_duze_cyfrymanual();
            break;
        case '3':
            male_duze_specjalnemanual();
            break;
        case '4':
            male_cyfry_specjalnemanual();
            break;
        case '5':
            duze_cyfry_specjalnemanual();
            break;
        case '6':
            male_duzemanual();
            break;
        case '7':
            male_cyfrymanual();
            break;
        case '8':
            male_specjalnemanual();
            break;
        case '9':
            duze_cyfrymanual();
            break;
        case 'q':
            duze_specjalnemanual();
            break;
        case 'w':
            cyfry_specjalnemanual();
            break;
        case 'm':
            tylkomalemanual();
            break;
        case 'd':
            tylkoduzemanual();
            break;
        case '0':
            tylkocyfrymanual();
            break;
        case '#':
            tylkospecjalnemanual();
            break;

        default:
            cin.clear();
            cin.ignore(INT_MAX,'\n');

            cout << "\nJakie znaki zawierac Twoje haslo:" << endl;
            switchdecyzyjnymanual();

    }
}
/**
 * Funkcja wypisująca wszystkie możliwe opcje użytkownikowi.
 */
void opcjemanual(){
    cout<<"1 - male litery | DUZE litery | cyfry | znaki specjalne" << endl;
    cout<<"2 - male litery | DUZE litery | cyfry" << endl;
    cout<<"3 - male litery | DUZE litery | znaki specjalne" << endl;
    cout<<"4 - male litery | cyfry | znaki specjalne" << endl;
    cout<<"5 - DUZE litery | cyfry | znaki specjalne" << endl;
    cout<<"6 - male litery | DUZE litery" << endl;
    cout<<"7 - male litery | cyfry" << endl;
    cout<<"8 - male litery | znaki specjalne" << endl;
    cout<<"9 - DUZE litery | cyfry" << endl;
    cout<<"q - DUZE litery | znaki specjalne" << endl;
    cout<<"w - cyfry | znaki specjalne" << endl;
    cout<<"m - male litery " << endl;
    cout<<"d - DUZE litery " << endl;
    cout<<"0 - cyfry " << endl;
    cout<<"# - znaki specjalne " << endl;
}

/**
 * Zapisywnanie hasła do pliku.
 * @param sciezka_zewnetrzna_kategorie - adres ścieżki zewnętrznej prowadzącej do kategorii. Potrzebna do manipulowania danymi użytkownika.
 * @param nazwakategorii_manual - informacja o nazwie kategorii. Potrzebna do manipulowania danymi użytkownika.
 */
void zapiszhaslomanual(string sciezka_zewnetrzna_kategorie, string nazwakategorii_manual){
    string sciezka = sciezka_zewnetrzna_kategorie;

    sciezka.append("/Passwords/");
    sciezka.append(nazwakategorii_manual);
    sciezka.append("_Passwords");
    sciezka.append(".txt");

    fstream fileOut;
    fileOut.open(sciezka,std::ios::app);
    if(fileOut.is_open()){
        fileOut<<koncowehaslomanual;
        fileOut<<"\n";
        fileOut.close();
    }
}

/**
 * Funkcja bazowa do generowania haseł.
 * @param sciezka_zewnetrzna_kategorie - adres ścieżki zewnętrznej prowadzącej do kategorii. Potrzebna do manipulowania danymi użytkownika.
 * @param nazwakategorii_manual - informacja o nazwie kategorii. Potrzebna do manipulowania danymi użytkownika.
 */
void generatormanual(string sciezka_zewnetrzna_kategorie,string nazwakategorii_manual){
    cout << "\n###################################################################" << endl;
    cout << "\nWpisz ile znakow ma miec twoje haslo: ";
    cin >> liczbaznakowmanual;

    /**
     * Sprawdzenie czy input użytkownika jest cyfrą.
     * Jeżeli nie jest cyfrą, czyszczenie cin, ignorowanie input'u
     * zapytanie użytkownika by ponownie wpisał numer.
     */
    while(!cin.good()){
        cin.clear(); //czyszczenie cin

        //INT_MAX - ile znaków ma zignorować (to jest mega duża liczba)
        cin.ignore(INT_MAX,'\n'); //usuwanie \n
        cout << "Prosze wprowadzic liczbe!" << endl;
        cin >> liczbaznakowmanual;
    }
    /**
     * Jeżeli input wprowadzony przez użytkownika jest równy 0.
     * @param liczbaznakowmanual - liczba znaków wprowadzona przez użytkownika
     */
    while(liczbaznakowmanual == 0){
        cin.clear();
        cin.ignore(INT_MAX,'\n');

        cout << "\nHaslo nie moze miec 0 znakow!\nSprobuj jeszcze raz!\n" << endl;
        generatormanual(sciezka_zewnetrzna_kategorie,nazwakategorii_manual);
    }
    /**
     * Jeżeli input wprowadzony przez użytkownika jest mniejszy od 10.
     * @param liczbaznakowmanual - liczba znaków wprowadzona przez użytkownika
     */
    if(liczbaznakowmanual < 10){
        zamaloznakowmanual();
    }
    /**
     * Jeżeli input wprowadzony przez użytkownika jest większy równy od 10.
     * @param liczbaznakowmanual - liczba znaków wprowadzona przez użytkownika
     */
    if(liczbaznakowmanual>=10){
        cout << "\nWybrana dlugosc hasla: " << liczbaznakowmanual <<" znakow!" << endl;
    }

    cout << "\n####################################################################################" << endl;
    cout << "# Dobre haslo powinno zawierac male i duze litery, jak i liczby i znaki specjalne! #\n";
    cout << "####################################################################################" << endl;
    cout << "\nJakie znaki zawierac Twoje haslo:" << endl;

    opcjemanual();

    cout<<"\nTwoja decyzja: ";
    cin >> literydecyjamanual;

    switchdecyzyjnymanual();
    zapiszhaslomanual(sciezka_zewnetrzna_kategorie,nazwakategorii_manual);
}
#endif //PROJEKT_SEMESTRALNY_CPP_GENERATOR_MANUAL_H
