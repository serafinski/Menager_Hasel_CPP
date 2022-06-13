//
// Created by tsera on 07.05.2022.
//

#ifndef PROJEKT_SEMESTRALNY_CPP_LOGOWANIE_H
#define PROJEKT_SEMESTRALNY_CPP_LOGOWANIE_H
#include <fstream>
#include <iostream>
#include "haslo.h"

using std::string; using std::cout; using std::cin; using std::endl;

string imie_login;
string sciezka_login;
string sciezka_podpowiedz;
string sciezka_zewnetrzna;
char odpowiedz;
char odpowiedzpoprzednie;

class logowanie {

public:

    void poprzednielogowanie(){
        cout << "\nWybierz opcje: " << endl;
        cout << "0 - jezeli chcesz zalogowac sie za pomoca nazwy uzytkownika" << endl;
        cout << "1 - jezeli chcesz zalgowac sie za pomoca sciezki" << endl;
        cout << "\nTwoj wybor: ";
        cin >> odpowiedzpoprzednie;

        while(odpowiedzpoprzednie!='1' && odpowiedzpoprzednie!= '0'){
            cin.clear();
            cin.ignore(INT_MAX,'\n'); //usuwanie \n

            cout << "\nWprowadzono nieprawidlowa opcje - prosze wprowadzic: "
                    "\n0 - chcesz zalogowac sie za pomoca nazwy uzytkownika"
                    "\n1 - jezeli chcesz zalgowac sie za pomoca sciezki" << endl;
            cout << "\nTwoj wybor: ";
            cin >> odpowiedz;
        }

        if(odpowiedzpoprzednie == '0'){
            cout << "\nWprowadz nazwe uzytkownika: ";
            cin >> imie_login;

            sciezka_login.append("../");
            sciezka_login.append(imie_login);
            sciezka_login.append("_masterpassword.txt");

            if(std::filesystem::exists(sciezka_login)){
                cout << "\nWitaj ponownie " << imie_login << "!\n" << endl;

                sciezka_podpowiedz.append("../");
                sciezka_podpowiedz.append(imie_login);
                sciezka_podpowiedz.append("_passwordhint.txt");

                wyswietlpodpowiedz(sciezka_podpowiedz);

                cout << "\nWpisz glowne haslo: ";
                cin >> wpisaneHaslo;
                cout << endl;

                readpassword(sciezka_login,wpisaneHaslo);
            }
        }

        if(odpowiedzpoprzednie == '1'){
            cout << "\nWprowadz sciezke do hasla: ";
            cin >> sciezka_zewnetrzna;

            cout << "Uzywajac tego rozwiazania - nie masz mozliwosci zobaczyc podpowiedzi!" << endl;

            if(std::filesystem::exists(sciezka_zewnetrzna)){

                cout << "\nWpisz glowne haslo: ";
                cin >> wpisaneHaslo;
                cout << endl;

                readpassword(sciezka_zewnetrzna,wpisaneHaslo);
            }
        }
    }

    void login() {
        cout << "\nWybierz opcje: " << endl;
        cout << "0 - jezeli nie uzywales/as wczesniej programu" << endl;
        cout << "1 - jezeli uzywales/as wczesniej programu" << endl;
        cout << "\nTwoj wybor: ";
        cin >> odpowiedz;

        while(odpowiedz!='1' && odpowiedz!= '0'){
            cin.clear();
            cin.ignore(INT_MAX,'\n'); //usuwanie \n

            cout << "\nWprowadzono nieprawidlowa opcje - prosze wprowadzic: "
                    "\n0 - jezeli nie uzywales/as wczesniej programu"
                    "\n1 - jezeli uzywales/as wczesniej programu" << endl;
            cout << "\nTwoj wybor: ";
            cin >> odpowiedz;
        }

        if (odpowiedz == '1') {
            poprzednielogowanie();
        }
        if(odpowiedz == '0'){
            nowy_user();
            stworzkategorie();
        }
    }

private:
    string wpisaneHaslo;
};


#endif //PROJEKT_SEMESTRALNY_CPP_LOGOWANIE_H