//
// Created by tsera on 12.05.2022.
//

#ifndef PROJEKT_SEMESTRALNY_CPP_GENERATOR_H
#include <iostream>
#include <string>
#include <vector>

using std::cout; using std::cin; using std::endl;

int liczbaznakow;
char decyzja;
char literydecyja;

//składowe hasła
char male[] = "abcdefghijklmnopqrstuvwxyz";
char DUZE[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char cyfry[] = "0123456789";
char specjalne[] = "!@#$%^&*";

void generator();


void wypisz(string str){
    cout <<"Twoje haslo to: ";

    int stringsize = str.size();
    srand(time(NULL));

    for(int i = 0; i < liczbaznakow; i++){
        cout << str[rand() % stringsize];
    }
}


void zamaloznakow(){
    cin.clear();
    cin.ignore(INT_MAX,'\n');

    cout << "PODANE HASLO NIE JEST ZBYT BEZPIECZNE!\nCzy chcesz wybrac dlugosc hasla jeszcze raz?" <<endl;
    cout << "Wpisz:\nt - dla tak!\nn - dla nie!\n\nTwoja decyzja:";
    cin >> decyzja;

    //tutaj się coś wysypuje...
    while (decyzja != 't' && decyzja != 'n'){

        //czyszczenie odpowiedzi
        cin.clear();
        cin.ignore(INT_MAX,'\n'); //usuwanie \n -> niweluje problem dublowania

        cout << "Wprowadzono nieprawidlowa opcje - prosze sprobowac ponownie.\n" << endl;
        cout << "PODANE HASLO NIE JEST ZBYT BEZPIECZNE!\nCzy chcesz wybrac dlugosc hasla jeszcze raz?" <<endl;
        cout << "Wpisz:\nt - dla tak!\nn - dla nie!\n\nTwoja decyzja:";
        cout << endl;
        cin >> decyzja;
    }

    if (decyzja == 't'){
        generator();
    }

    else if(decyzja == 'n') {
        if(liczbaznakow == 1)
        cout << "Wybrana dlugosc hasla: " << liczbaznakow <<" znak!" << endl;
        else if(liczbaznakow >1 && liczbaznakow<5){
            cout << "Wybrana dlugosc hasla: " << liczbaznakow <<" znaki!" << endl;
        }
        else
            cout << "Wybrana dlugosc hasla: " << liczbaznakow <<" znakow!" << endl;
    }
}

void wszystko(){
    cout << "\nWybrano male i duze litery oraz cyfry i znaki specjalne!\n" << endl;

    string str = string(male) + DUZE + cyfry + specjalne;
    wypisz(str);
    cout << endl;
}

void male_duze_cyfry(){
    cout << "\nWybrano male i duze litery oraz cyfry!\n" << endl;

    string str = string(male) + DUZE + cyfry;
    wypisz(str);
    cout << endl;
}

void male_duze_specjalne(){
    cout << "\nWybrano male i duze litery oraz znaki specjalne!\n" << endl;

    string str = string(male) + DUZE + specjalne;
    wypisz(str);
    cout << endl;
}

void male_cyfry_specjalne(){
    cout << "\nWybrano male litery oraz cyfry i znaki specjalne!\n" << endl;

    string str = string(male) + cyfry + specjalne;
    wypisz(str);
    cout << endl;
}

void duze_cyfry_specjalne(){
    cout << "\nWybrano duze litery oraz cyfry i znaki specjalne!\n" << endl;

    string str = string(DUZE) + cyfry + specjalne;
    wypisz(str);
    cout << endl;
}

void male_duze(){
    cout << "\nWybrano male i duze litery!\n" << endl;

    string str = string(male) + DUZE;
    wypisz(str);
    cout << endl;
}

void male_cyfry(){
    cout << "\nWybrano male litery oraz cyfry!\n" << endl;

    string str = string(male) + cyfry;
    wypisz(str);
    cout << endl;
}

void male_specjalne(){
    cout << "\nWybrano male litery oraz znaki specjalne!\n" << endl;

    string str = string(male) + specjalne;
    wypisz(str);
    cout << endl;
}

void duze_cyfry(){
    cout << "\nWybrano duze litery oraz cyfry!\n" << endl;
    string str = string(DUZE) + cyfry;
    wypisz(str);
    cout << endl;
}

void duze_specjalne(){
    cout << "\nWybrano duze litery oraz znaki specjalne!\n" << endl;

    string str = string(DUZE) + specjalne;
    wypisz(str);
    cout << endl;
}

void cyfry_specjalne(){
    cout << "\nWybrano cyfry i znaki specjalne!\n" << endl;

    string str = string(cyfry) + specjalne;
    wypisz(str);
    cout << endl;
}

void tylkomale(){
    cout << "\nwybrano tylko male litery!\n" << endl;

    string str = string(male);
    wypisz(str);
    cout << endl;
}

void tylkoduze(){
    cout << "\nWYBRANO TYLKO DUZE LITERY!\n" << endl;

    string str = string(DUZE);
    wypisz(str);
    cout << endl;
}

void tylkocyfry(){
    cout << "\nWybrano tylko same cyfry!\n" << endl;

    string str = string(cyfry);
    wypisz(str);
    cout << endl;
}

void tylkospecjalne(){
    cout << "\nWybrano tylko znaki specjalne!\n" << endl;

    string str = string(specjalne);
    wypisz(str);
    cout << endl;
}


void switchdecyzyjny(){
    switch (literydecyja) {
        case '1':
            wszystko();
            break;
        case '2':
            male_duze_cyfry();
            break;
        case '3':
            male_duze_specjalne();
            break;
        case '4':
            male_cyfry_specjalne();
            break;
        case '5':
            duze_cyfry_specjalne();
            break;
        case '6':
            male_duze();
            break;
        case '7':
            male_cyfry();
            break;
        case '8':
            male_specjalne();
            break;
        case '9':
            duze_cyfry();
            break;
        case 'q':
            duze_specjalne();
            break;
        case 'w':
            cyfry_specjalne();
            break;
        case 'm':
            tylkomale();
            break;
        case 'd':
            tylkoduze();
            break;
        case '0':
            tylkocyfry();
            break;
        case '#':
            tylkospecjalne();
            break;

        default:
            cin.clear();
            cin.ignore(INT_MAX,'\n');

            cout << "\nJakie znaki zawierac Twoje haslo:" << endl;
            switchdecyzyjny();

    }
}

void opcje(){
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


void generator(){
    cout << "###################################################################" << endl;
    cout << "Wpisz ile znakow ma miec twoje haslo: ";
    cin >> liczbaznakow;


    //do momentu aż input nie będzie poprawny (czytaj nie będzie int)
    while(!cin.good()){
        cin.clear(); //czyszczenie cin

        //INT_MAX - ile znaków ma zignorować (to jest mega duża liczba)
        cin.ignore(INT_MAX,'\n'); //usuwanie \n
        cout << "Prosze wprowadzic liczbe!" << endl;
        cin >> liczbaznakow;
    }

    if(liczbaznakow == 0){
        cin.clear();
        cin.ignore(INT_MAX,'\n');

        cout << "\nHaslo nie moze miec 0 znakow!\nSprobuj jeszcze raz!\n" << endl;
        generator();
    }

    if(liczbaznakow < 10){
        zamaloznakow();
    }

    else{
        if(liczbaznakow == 1)
            cout << "Wybrana dlugosc hasla: " << liczbaznakow <<" znak!" << endl;
        else if(liczbaznakow >1 && liczbaznakow<5){
            cout << "Wybrana dlugosc hasla: " << liczbaznakow <<" znaki!" << endl;
        }
        else
            cout << "Wybrana dlugosc hasla: " << liczbaznakow <<" znakow!" << endl;
    }
    cout << "\n####################################################################################" << endl;
    cout << "# Dobre haslo powinno zawierac male i duze litery, jak i liczby i znaki specjalne! #\n";
    cout << "####################################################################################" << endl;
    cout << "\nJakie znaki zawierac Twoje haslo:" << endl;
    opcje();
    cout<<"\nTwoja decyzja: ";
    cin >> literydecyja;
    switchdecyzyjny();
}

#define PROJEKT_SEMESTRALNY_CPP_GENERATOR_H

#endif //PROJEKT_SEMESTRALNY_CPP_GENERATOR_H
