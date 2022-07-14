//
// Created by tsera on 29.06.2022.
//
#include "generator.h"

generator::generator() = default;
int generator::liczbaznakow;
char generator::decyzja;
char generator::literydecyja;
string generator::koncowehaslo;

char male[] = "abcdefghijklmnopqrstuvwxyz";
char DUZE[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char cyfry[] = "0123456789";
char specjalne[] = "!@#$%^&*";

/**
 * Funkcja służąca do generowania hasła.
 * @param str - ciąg znaków z którego będzie generowane hasło.
 */
void generator::wypisz(string str){
    std::stringstream buffer;

    cout <<"Twoje haslo to: ";

    int stringsize = str.size();
    srand(time(NULL));

    for(int i = 0; i < generator::liczbaznakow; i++){
        buffer << str[rand() % stringsize];
    }
    generator::koncowehaslo = buffer.str();
    cout << generator::koncowehaslo << endl;
}


/**
 * Funkcja sprawdzająca czy podane hasło jest za krótkie.
 * Jeżeli hasło jest za krótkie (ma poniżej 10 znaków) - program pyta użytkownika czy chce zmienić długość hasła.
 * Jeżeli użytkownik chce zmienić długość hasła - funkcja wywoływana jest ponownie.
 * Jeżeli użytkownik nie chce zmienić długości hasła - funkcja wypisuje długość hasła.
 */
void generator::zamaloznakow(){
    cin.clear();
    cin.ignore(INT_MAX,'\n');

    cout << "\nPODANE HASLO NIE JEST ZBYT BEZPIECZNE!\nCzy chcesz wybrac dlugosc hasla jeszcze raz?" <<endl;
    cout << "Wpisz:\nt - dla tak!\nn - dla nie!\n\nTwoja decyzja:";
    cin >> generator::decyzja;

    /**
     * Sprawdzenie input ze strony użytkownika jest poprawny.
     * Jeżeli nie jest, program prosi użytkownika o wprowadzenie prawidłowej wartości.
     * @param decyzja - decyzja użytkownika czy chce zatrzymać wpisaną długość hasła czy nie.
     */
    while (generator::decyzja != 't' && generator::decyzja != 'n'){

        //czyszczenie odpowiedzi
        cin.clear();
        cin.ignore(INT_MAX,'\n'); //usuwanie \n -> niweluje problem dublowania

        cout << "\nWprowadzono nieprawidlowa opcje - prosze sprobowac ponownie.\n" << endl;
        cout << "PODANE HASLO NIE JEST ZBYT BEZPIECZNE!\nCzy chcesz wybrac dlugosc hasla jeszcze raz?" <<endl;
        cout << "Wpisz:\nt - dla tak!\nn - dla nie!\n\nTwoja decyzja:";
        cin >> generator::decyzja;
    }
    /**
     * Jeżeli użytkownik chce ponownie wybrać długość hasła.
     * @param decyzja - decyzja użytkownika czy chce zatrzymać wpisaną długość hasła czy nie.
     */
    if (generator::decyzja == 't'){
        cout << "\n###################################################################" << endl;
        cout << "\nWpisz ile znakow ma miec twoje haslo: ";
        cin >> generator::liczbaznakow;

        if(generator::liczbaznakow < 10){
            zamaloznakow();
        }
    }
    /**
     * Jeżeli użytkownik chce zatrzymać długość hasła.
     * @param decyzja - decyzja użytkownika czy chce zatrzymać wpisaną długość hasła czy nie.
     */
    if(generator::decyzja == 'n') {
        if(generator::liczbaznakow == 1)
            cout << "\nWybrana dlugosc hasla: " << generator::liczbaznakow <<" znak!" << endl;
        else if(generator::liczbaznakow >1 && generator::liczbaznakow<5){
            cout << "\nWybrana dlugosc hasla: " << generator::liczbaznakow <<" znaki!" << endl;
        }
        else if(generator::liczbaznakow>=5 && generator::liczbaznakow<10)
            cout << "\nWybrana dlugosc hasla: " << generator::liczbaznakow <<" znakow!" << endl;
    }
}

/**
 * Funkcja pozwalająca na generowanie hasła składającego się z małych i dużych liter oraz cyfr i znaków specjalnych.
 */
void generator::wszystko(){
    cout << "\nWybrano male i duze litery oraz cyfry i znaki specjalne!\n" << endl;

    string str = string(male) + DUZE + cyfry + specjalne;
    wypisz(str);
    cout << endl;
}

/**
 * Funkcja pozwalająca na generowanie hasła składającego się małych i dużych liter oraz cyfr.
 */
void generator::male_duze_cyfry(){
    cout << "\nWybrano male i duze litery oraz cyfry!\n" << endl;

    string str = string(male) + DUZE + cyfry;
    wypisz(str);
    cout << endl;
}

/**
 * Funkcja pozwalająca na generowanie hasła składającego się małych i dużych liter oraz znaków specjalnych.
 */
void generator::male_duze_specjalne(){
    cout << "\nWybrano male i duze litery oraz znaki specjalne!\n" << endl;

    string str = string(male) + DUZE + specjalne;
    wypisz(str);
    cout << endl;
}
/**
 * Funkcja pozwalająca na generowanie hasła składającego się małych liter oraz cyfr i znaków specjalnych.
 */
void generator::male_cyfry_specjalne(){
    cout << "\nWybrano male litery oraz cyfry i znaki specjalne!\n" << endl;

    string str = string(male) + cyfry + specjalne;
    wypisz(str);
    cout << endl;
}
/**
 * Funkcja pozwalająca na generowanie hasła składającego się z dużych liter oraz cyfr i znaków specjalnych.
 */
void generator::duze_cyfry_specjalne(){
    cout << "\nWybrano duze litery oraz cyfry i znaki specjalne!\n" << endl;

    string str = string(DUZE) + cyfry + specjalne;
    wypisz(str);
    cout << endl;
}
/**
 * Funkcja pozwalająca na generowanie hasła składającego się z małych i dużych liter.
 */
void generator::male_duze(){
    cout << "\nWybrano male i duze litery!\n" << endl;

    string str = string(male) + DUZE;
    wypisz(str);
    cout << endl;
}
/**
 * Funkcja pozwalająca na generowanie hasła składającego się z małych liter oraz cyfr.
 */
void generator::male_cyfry(){
    cout << "\nWybrano male litery oraz cyfry!\n" << endl;

    string str = string(male) + cyfry;
    wypisz(str);
    cout << endl;
}
/**
 * Funkcja pozwalająca na generowanie hasła składającego się z małych liter oraz znaków specjalnych.
 */
void generator::male_specjalne(){
    cout << "\nWybrano male litery oraz znaki specjalne!\n" << endl;

    string str = string(male) + specjalne;
    wypisz(str);
    cout << endl;
}
/**
 * Funkcja pozwalająca na generowanie hasła składającego się z dużych liter oraz cyfr.
 */
void generator::duze_cyfry(){
    cout << "\nWybrano duze litery oraz cyfry!\n" << endl;
    string str = string(DUZE) + cyfry;
    wypisz(str);
    cout << endl;
}
/**
 * Funkcja pozwalająca na generowanie hasła składającego się z dużych liter oraz znaków specjalnych.
 */
void generator::duze_specjalne(){
    cout << "\nWybrano duze litery oraz znaki specjalne!\n" << endl;

    string str = string(DUZE) + specjalne;
    wypisz(str);
    cout << endl;
}
/**
 * Funkcja pozwalająca na generowanie hasła składającego się z cyfr i znaków specjalnych.
 */
void generator::cyfry_specjalne(){
    cout << "\nWybrano cyfry i znaki specjalne!\n" << endl;

    string str = string(cyfry) + specjalne;
    wypisz(str);
    cout << endl;
}
/**
 * Funkcja pozwalająca na generowanie hasła składającego się z małych liter.
 */
void generator::tylkomale(){
    cout << "\nwybrano tylko male litery!\n" << endl;

    string str = string(male);
    wypisz(str);
    cout << endl;
}
/**
 * Funkcja pozwalająca na generowanie hasła składającego się dużych liter.
 */
void generator::tylkoduze(){
    cout << "\nWYBRANO TYLKO DUZE LITERY!\n" << endl;

    string str = string(DUZE);
    wypisz(str);
    cout << endl;
}
/**
 * Funkcja pozwalająca na generowanie hasła składającego się z cyfr.
 */
void generator::tylkocyfry(){
    cout << "\nWybrano tylko same cyfry!\n" << endl;

    string str = string(cyfry);
    wypisz(str);
    cout << endl;
}
/**
 * Funkcja pozwalająca na generowanie hasła składającego się ze znaków specjalnych.
 */
void generator::tylkospecjalne(){
    cout << "\nWybrano tylko znaki specjalne!\n" << endl;

    string str = string(specjalne);
    generator::wypisz(str);
    cout << endl;
}

/**
 * Switch umożliwiający użytkownikowi wybór typu hasła który chce wygenerować.
 */
void generator::switchdecyzyjny(){
    switch (generator::literydecyja) {
        case '1':
            generator::wszystko();
            break;
        case '2':
            generator::male_duze_cyfry();
            break;
        case '3':
            generator::male_duze_specjalne();
            break;
        case '4':
            generator::male_cyfry_specjalne();
            break;
        case '5':
            generator::duze_cyfry_specjalne();
            break;
        case '6':
            generator::male_duze();
            break;
        case '7':
            generator::male_cyfry();
            break;
        case '8':
            generator::male_specjalne();
            break;
        case '9':
            generator::duze_cyfry();
            break;
        case 'q':
            generator::duze_specjalne();
            break;
        case 'w':
            generator::cyfry_specjalne();
            break;
        case 'm':
            generator::tylkomale();
            break;
        case 'd':
            generator::tylkoduze();
            break;
        case '0':
            generator::tylkocyfry();
            break;
        case '#':
            generator::tylkospecjalne();
            break;

        default:
            cin.clear();
            cin.ignore(INT_MAX,'\n');

            cout << "\nJakie znaki zawierac Twoje haslo:" << endl;
            switchdecyzyjny();

    }
}
/**
 * Funkcja wypisująca wszystkie możliwe opcje użytkownikowi.
 */
void generator::opcje(){
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
 * @param imie_login - informacja o nazwie użytkownika. Potrzebna do manipulowania danymi użytkownika.
 * @param nazwakategorii - informacja o nazwie kategorii. Potrzebna do manipulowania danymi użytkownika.
 */
void generator::zapiszhaslo(string imie_login, string nazwakategorii){
    string sciezka;

    sciezka.append("../");
    sciezka.append(imie_login);
    sciezka.append("_Categories");
    sciezka.append("/Passwords/");
    sciezka.append(nazwakategorii);
    sciezka.append("_Passwords");
    sciezka.append(".txt");

    fstream fileOut;
    fileOut.open(sciezka,std::ios::app);
    if(fileOut.is_open()){
        fileOut<<generator::koncowehaslo;
        fileOut<<"\n";
        fileOut.close();
    }
}

/**
 * Funkcja bazowa do generowania haseł.
 * @param imie_login - informacja o nazwie użytkownika. Potrzebna do manipulowania danymi użytkownika.
 * @param nazwakategorii - informacja o nazwie kategorii. Potrzebna do manipulowania danymi użytkownika.
 */
void generator::generatorname(string imie_login,string nazwakategorii){
    cout << "\n###################################################################" << endl;
    cout << "\nWpisz ile znakow ma miec twoje haslo: ";
    cin >> generator::liczbaznakow;

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
        cin >> generator::liczbaznakow;
    }
    /**
     * Jeżeli input wprowadzony przez użytkownika jest równy 0.
     * @param liczbaznakow - liczba znaków wprowadzona przez użytkownika
     */
    while(generator::liczbaznakow == 0){
        cin.clear();
        cin.ignore(INT_MAX,'\n');

        cout << "\nHaslo nie moze miec 0 znakow!\nSprobuj jeszcze raz!\n" << endl;
        generatorname(imie_login,nazwakategorii);
    }
    /**
     * Jeżeli input wprowadzony przez użytkownika jest mniejszy od 10.
     * @param liczbaznakow - liczba znaków wprowadzona przez użytkownika
     */
    if(generator::liczbaznakow < 10){
        generator::zamaloznakow();
    }
    /**
     * Jeżeli input wprowadzony przez użytkownika jest większy równy od 10.
     * @param liczbaznakow - liczba znaków wprowadzona przez użytkownika
     */
    if(generator::liczbaznakow>=10){
        cout << "\nWybrana dlugosc hasla: " << generator::liczbaznakow <<" znakow!" << endl;
    }

    cout << "\n####################################################################################" << endl;
    cout << "# Dobre haslo powinno zawierac male i duze litery, jak i liczby i znaki specjalne! #\n";
    cout << "####################################################################################" << endl;
    cout << "\nJakie znaki zawierac Twoje haslo:" << endl;

    generator::opcje();

    cout<<"\nTwoja decyzja: ";
    cin >> generator::literydecyja;

    generator::switchdecyzyjny();
    generator::zapiszhaslo(imie_login,nazwakategorii);
}