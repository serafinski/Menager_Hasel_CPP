//
// Created by tsera on 29.06.2022.
//
#include "generator_manual.h"

generator_manual::generator_manual() = default;

int generator_manual::liczbaznakowmanual;
char generator_manual::decyzjamanual;
char generator_manual::literydecyjamanual;
string generator_manual::koncowehaslomanual;

char malemanual[] = "abcdefghijklmnopqrstuvwxyz";
char DUZEmanual[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char cyfrymanual[] = "0123456789";
char specjalnemanual[] = "!@#$%^&*";
/**
 * Funkcja służąca do generowania hasła.
 * @param str - ciąg znaków z którego będzie generowane hasło.
 */
void generator_manual::wypiszmanual(string str){
    std::stringstream buffer;

    cout <<"Twoje haslo to: ";

    int stringsize = str.size();
    srand(time(NULL));

    for(int i = 0; i < generator_manual::liczbaznakowmanual; i++){
        buffer << str[rand() % stringsize];
    }
    generator_manual::koncowehaslomanual = buffer.str();
    cout << generator_manual::koncowehaslomanual << endl;
}


/**
 * Funkcja sprawdzająca czy podane hasło jest za krótkie.
 * Jeżeli hasło jest za krótkie (ma poniżej 10 znaków) - program pyta użytkownika czy chce zmienić długość hasła.
 * Jeżeli użytkownik chce zmienić długość hasła - funkcja wywoływana jest ponownie.
 * Jeżeli użytkownik nie chce zmienić długości hasła - funkcja wypisuje długość hasła.
 */
void generator_manual::zamaloznakowmanual(){
    cin.clear();
    cin.ignore(INT_MAX,'\n');

    cout << "\nPODANE HASLO NIE JEST ZBYT BEZPIECZNE!\nCzy chcesz wybrac dlugosc hasla jeszcze raz?" <<endl;
    cout << "Wpisz:\nt - dla tak!\nn - dla nie!\n\nTwoja decyzja:";
    cin >> generator_manual::decyzjamanual;

    /**
     * Sprawdzenie input ze strony użytkownika jest poprawny.
     * Jeżeli nie jest, program prosi użytkownika o wprowadzenie prawidłowej wartości.
     * @param decyzjamanual - decyzja użytkownika czy chce zatrzymać wpisaną długość hasła czy nie.
     */
    while (generator_manual::decyzjamanual != 't' && generator_manual::decyzjamanual != 'n'){

        //czyszczenie odpowiedzi
        cin.clear();
        cin.ignore(INT_MAX,'\n'); //usuwanie \n -> niweluje problem dublowania

        cout << "\nWprowadzono nieprawidlowa opcje - prosze sprobowac ponownie.\n" << endl;
        cout << "PODANE HASLO NIE JEST ZBYT BEZPIECZNE!\nCzy chcesz wybrac dlugosc hasla jeszcze raz?" <<endl;
        cout << "Wpisz:\nt - dla tak!\nn - dla nie!\n\nTwoja decyzja:";
        cin >> generator_manual::decyzjamanual;
    }
    /**
     * Jeżeli użytkownik chce ponownie wybrać długość hasła.
     * @param decyzjamanual - decyzja użytkownika czy chce zatrzymać wpisaną długość hasła czy nie.
     */
    if (generator_manual::decyzjamanual == 't'){
        cout << "\n###################################################################" << endl;
        cout << "\nWpisz ile znakow ma miec twoje haslo: ";
        cin >> generator_manual::liczbaznakowmanual;

        if(generator_manual::liczbaznakowmanual < 10){
            zamaloznakowmanual();
        }
    }
    /**
     * Jeżeli użytkownik chce zatrzymać długość hasła.
     * @param decyzjamanual - decyzja użytkownika czy chce zatrzymać wpisaną długość hasła czy nie.
     */
    if(generator_manual::decyzjamanual == 'n') {
        if(generator_manual::liczbaznakowmanual == 1)
            cout << "\nWybrana dlugosc hasla: " << generator_manual::liczbaznakowmanual <<" znak!" << endl;
        else if(generator_manual::liczbaznakowmanual >1 && generator_manual::liczbaznakowmanual<5){
            cout << "\nWybrana dlugosc hasla: " << generator_manual::liczbaznakowmanual <<" znaki!" << endl;
        }
        else if(generator_manual::liczbaznakowmanual>=5 && generator_manual::liczbaznakowmanual<10)
            cout << "\nWybrana dlugosc hasla: " << generator_manual::liczbaznakowmanual <<" znakow!" << endl;
    }
}

/**
 * Funkcja pozwalająca na generowanie hasła składającego się z małych i dużych liter oraz cyfr i znaków specjalnych.
 */
void generator_manual::wszystkomanual(){
    cout << "\nWybrano male i duze litery oraz cyfry i znaki specjalne!\n" << endl;

    string str = string(malemanual) + DUZEmanual + cyfrymanual + specjalnemanual;
    wypiszmanual(str);
    cout << endl;
}

/**
 * Funkcja pozwalająca na generowanie hasła składającego się małych i dużych liter oraz cyfr.
 */
void generator_manual::male_duze_cyfrymanual(){
    cout << "\nWybrano male i duze litery oraz cyfry!\n" << endl;

    string str = string(malemanual) + DUZEmanual + cyfrymanual;
    wypiszmanual(str);
    cout << endl;
}

/**
 * Funkcja pozwalająca na generowanie hasła składającego się małych i dużych liter oraz znaków specjalnych.
 */
void generator_manual::male_duze_specjalnemanual(){
    cout << "\nWybrano male i duze litery oraz znaki specjalne!\n" << endl;

    string str = string(malemanual) + DUZEmanual + specjalnemanual;
    generator_manual::wypiszmanual(str);
    cout << endl;
}
/**
 * Funkcja pozwalająca na generowanie hasła składającego się małych liter oraz cyfr i znaków specjalnych.
 */
void generator_manual::male_cyfry_specjalnemanual(){
    cout << "\nWybrano male litery oraz cyfry i znaki specjalne!\n" << endl;

    string str = string(malemanual) + cyfrymanual + specjalnemanual;
    generator_manual::wypiszmanual(str);
    cout << endl;
}
/**
 * Funkcja pozwalająca na generowanie hasła składającego się z dużych liter oraz cyfr i znaków specjalnych.
 */
void generator_manual::duze_cyfry_specjalnemanual(){
    cout << "\nWybrano duze litery oraz cyfry i znaki specjalne!\n" << endl;

    string str = string(DUZEmanual) + cyfrymanual + specjalnemanual;
    generator_manual::wypiszmanual(str);
    cout << endl;
}
/**
 * Funkcja pozwalająca na generowanie hasła składającego się z małych i dużych liter.
 */
void generator_manual::male_duzemanual(){
    cout << "\nWybrano male i duze litery!\n" << endl;

    string str = string(malemanual) + DUZEmanual;
    generator_manual::wypiszmanual(str);
    cout << endl;
}
/**
 * Funkcja pozwalająca na generowanie hasła składającego się z małych liter oraz cyfr.
 */
void generator_manual::male_cyfrymanual(){
    cout << "\nWybrano male litery oraz cyfry!\n" << endl;

    string str = string(malemanual) + cyfrymanual;
    generator_manual::wypiszmanual(str);
    cout << endl;
}
/**
 * Funkcja pozwalająca na generowanie hasła składającego się z małych liter oraz znaków specjalnych.
 */
void generator_manual::male_specjalnemanual(){
    cout << "\nWybrano male litery oraz znaki specjalne!\n" << endl;

    string str = string(malemanual) + specjalnemanual;
    generator_manual::wypiszmanual(str);
    cout << endl;
}
/**
 * Funkcja pozwalająca na generowanie hasła składającego się z dużych liter oraz cyfr.
 */
void generator_manual::duze_cyfrymanual(){
    cout << "\nWybrano duze litery oraz cyfry!\n" << endl;
    string str = string(DUZEmanual) + cyfrymanual;
    generator_manual::wypiszmanual(str);
    cout << endl;
}
/**
 * Funkcja pozwalająca na generowanie hasła składającego się z dużych liter oraz znaków specjalnych.
 */
void generator_manual::duze_specjalnemanual(){
    cout << "\nWybrano duze litery oraz znaki specjalne!\n" << endl;

    string str = string(DUZEmanual) + specjalnemanual;
    generator_manual::wypiszmanual(str);
    cout << endl;
}
/**
 * Funkcja pozwalająca na generowanie hasła składającego się z cyfr i znaków specjalnych.
 */
void generator_manual::cyfry_specjalnemanual(){
    cout << "\nWybrano cyfry i znaki specjalne!\n" << endl;

    string str = string(cyfrymanual) + specjalnemanual;
    generator_manual::wypiszmanual(str);
    cout << endl;
}
/**
 * Funkcja pozwalająca na generowanie hasła składającego się z małych liter.
 */
void generator_manual::tylkomalemanual(){
    cout << "\nwybrano tylko male litery!\n" << endl;

    string str = string(malemanual);
    generator_manual::wypiszmanual(str);
    cout << endl;
}
/**
 * Funkcja pozwalająca na generowanie hasła składającego się dużych liter.
 */
void generator_manual::tylkoduzemanual(){
    cout << "\nWYBRANO TYLKO DUZE LITERY!\n" << endl;

    string str = string(DUZEmanual);
    generator_manual::wypiszmanual(str);
    cout << endl;
}
/**
 * Funkcja pozwalająca na generowanie hasła składającego się z cyfr.
 */
void generator_manual::tylkocyfrymanual(){
    cout << "\nWybrano tylko same cyfry!\n" << endl;

    string str = string(cyfrymanual);
    generator_manual::wypiszmanual(str);
    cout << endl;
}
/**
 * Funkcja pozwalająca na generowanie hasła składającego się ze znaków specjalnych.
 */
void generator_manual::tylkospecjalnemanual(){
    cout << "\nWybrano tylko znaki specjalne!\n" << endl;

    string str = string(specjalnemanual);
    generator_manual::wypiszmanual(str);
    cout << endl;
}

/**
 * Switch umożliwiający użytkownikowi wybór typu hasła który chce wygenerować.
 */
void generator_manual::switchdecyzyjnymanual(){
    switch (generator_manual::literydecyjamanual) {
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
void generator_manual::opcjemanual(){
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
void generator_manual::zapiszhaslomanual(string sciezka_zewnetrzna_kategorie, string nazwakategorii_manual){
    string sciezka = sciezka_zewnetrzna_kategorie;

    sciezka.append("/Passwords/");
    sciezka.append(nazwakategorii_manual);
    sciezka.append("_Passwords");
    sciezka.append(".txt");

    fstream fileOut;
    fileOut.open(sciezka,std::ios::app);
    if(fileOut.is_open()){
        fileOut<<generator_manual::koncowehaslomanual;
        fileOut<<"\n";
        fileOut.close();
    }
}

/**
 * Funkcja bazowa do generowania haseł.
 * @param sciezka_zewnetrzna_kategorie - adres ścieżki zewnętrznej prowadzącej do kategorii. Potrzebna do manipulowania danymi użytkownika.
 * @param nazwakategorii_manual - informacja o nazwie kategorii. Potrzebna do manipulowania danymi użytkownika.
 */
void generator_manual::generatormanualfun(string sciezka_zewnetrzna_kategorie,string nazwakategorii_manual){
    cout << "\n###################################################################" << endl;
    cout << "\nWpisz ile znakow ma miec twoje haslo: ";
    cin >> generator_manual::liczbaznakowmanual;

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
        cin >> generator_manual::liczbaznakowmanual;
    }
    /**
     * Jeżeli input wprowadzony przez użytkownika jest równy 0.
     * @param liczbaznakowmanual - liczba znaków wprowadzona przez użytkownika
     */
    while(generator_manual::liczbaznakowmanual == 0){
        cin.clear();
        cin.ignore(INT_MAX,'\n');

        cout << "\nHaslo nie moze miec 0 znakow!\nSprobuj jeszcze raz!\n" << endl;
        generator_manual::generatormanualfun(sciezka_zewnetrzna_kategorie,nazwakategorii_manual);
    }
    /**
     * Jeżeli input wprowadzony przez użytkownika jest mniejszy od 10.
     * @param liczbaznakowmanual - liczba znaków wprowadzona przez użytkownika
     */
    if(generator_manual::liczbaznakowmanual < 10){
        zamaloznakowmanual();
    }
    /**
     * Jeżeli input wprowadzony przez użytkownika jest większy równy od 10.
     * @param liczbaznakowmanual - liczba znaków wprowadzona przez użytkownika
     */
    if(generator_manual::liczbaznakowmanual>=10){
        cout << "\nWybrana dlugosc hasla: " << generator_manual::liczbaznakowmanual <<" znakow!" << endl;
    }

    cout << "\n####################################################################################" << endl;
    cout << "# Dobre haslo powinno zawierac male i duze litery, jak i liczby i znaki specjalne! #\n";
    cout << "####################################################################################" << endl;
    cout << "\nJakie znaki zawierac Twoje haslo:" << endl;

    generator_manual::opcjemanual();

    cout<<"\nTwoja decyzja: ";
    cin >> generator_manual::literydecyjamanual;

    switchdecyzyjnymanual();
    zapiszhaslomanual(sciezka_zewnetrzna_kategorie,nazwakategorii_manual);
}


