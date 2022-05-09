//
// Created by tsera on 09.05.2022.
//

#ifndef PROJEKT_SEMESTRALNY_CPP_HASLO_H
#define PROJEKT_SEMESTRALNY_CPP_HASLO_H
#include <iostream>
#include <fstream>
using std::string; using std::cout; using std::cin; using std::endl;

void zledane();

void nowy_user(){
    string haslo1;
    string haslo2;
    char pod;
    string podpowiedz;

    cout << "Wyglada na to, ze jest to twoje pierwsze uzycie programu!" << endl;
    cout << "Witaj w Managerze Hasel! Prosze wprowadz swoje glowne haslo, ktore bedzie sluzylo do odblokowania portfela!" << endl;
    cout << "\nWprowadz haslo: ";
    cin >> haslo1;
    cout << endl;
    cout << "Wprowadz haslo jeszcze raz!: ";
    cin >> haslo2;
    cout << endl;

    if(haslo1 != haslo2){
        zledane();
    }
    else{
        cout << "Rejestracja przebiegla pomyslnie!" << endl;
        cout << "Twoje haslo to: " << haslo1 << endl;

        cout << endl;

        cout << "Czy chcesz wprowadzic podpowiedz - w razie zapomnienia hasla?" << endl;
        cout << "Tak(t)/Nie(n)" << endl;
        cin >> pod;


        //tutaj za kazdym wprowadzonym znakiem wyskakuje to samo! (jak zrobic by wyskakiwalo tylko raz)
        while (pod != 't' && pod != 'n'){
            cout << "Wprowadzono nieprawidlowa opcje - prosze wprowadzic: \nt - dla tak\nn - dla nie" << endl;
            cin >> pod;

        if (pod == 't'){
            cout << "Prosze wprowadzic swoja podpowiedz:" << endl;
            cin >> podpowiedz;
            cout << "Podpowiedz zostala zapisana!" << endl;
        }

        else{
            cout << "Nie wprowadzono podpowiedzi!" << endl;
        }

        }

    }
}

void zledane(){
    cout << "Podane hasla nie pasuja do siebie, sproboj ponownie!\n";
    cout << endl;
    nowy_user();
}

#endif //PROJEKT_SEMESTRALNY_CPP_HASLO_H
