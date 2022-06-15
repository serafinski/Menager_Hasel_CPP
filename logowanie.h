//
// Created by tsera on 07.05.2022.
//

#ifndef PROJEKT_SEMESTRALNY_CPP_LOGOWANIE_H
#define PROJEKT_SEMESTRALNY_CPP_LOGOWANIE_H
#include <fstream>
#include <iostream>
#include "haslo.h"
#include "Switch.h"

using std::string; using std::cout; using std::cin; using std::endl;

string imie_login;
string sciezka_login;
string sciezka_podpowiedz;
string sciezka_zewnetrzna_hint;
string sciezka_zewnetrzna_master;
string sciezka_zewnetrzna_last;
string sciezka_zewnetrzna_kategorie;

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
            cin >> odpowiedzpoprzednie;
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

                cout << "Wpisz glowne haslo: ";
                cin >> wpisaneHaslo;
                cout << endl;

                readpassword(sciezka_login,wpisaneHaslo);
            }
            if(!std::filesystem::exists(sciezka_login)){
                std::cerr << "\nPodany uzytkownik nie istnieje! Prosze utworzyc konto!" << endl;
                exit(1);
            }

            readtimestamp(imie_login);
            overwritetimestamp(imie_login);
            funkcja_switch(imie_login);
        }

        if(odpowiedzpoprzednie == '1'){
            cout << "\nWprowadz sciezke do podpowiedzi:";
            cin >> sciezka_zewnetrzna_hint;
            cout << "\nWybrano podana sciezke: " << sciezka_zewnetrzna_hint << endl;

            cout << "\nWprowadz sciezke do glownego hasla: ";
            cin >> sciezka_zewnetrzna_master;
            cout << "\nWybrano podana sciezke: " << sciezka_zewnetrzna_master << endl;

            cout << "\nWprowadz sciezke do pliku z informacja o ostatnim deszyfrowaniu: ";
            cin >> sciezka_zewnetrzna_last;
            cout << "\nWybrano podana sciezke: " << sciezka_zewnetrzna_last << endl;

            cout << "\nWprowadz sciezke do folderu z kategoriami hasel: ";
            cin >> sciezka_zewnetrzna_kategorie;
            cout << "\nWybrano podana sciezke: " << sciezka_zewnetrzna_kategorie << endl;

            if(std::filesystem::exists(sciezka_zewnetrzna_master)){

                wyswietlpodpowiedz(sciezka_zewnetrzna_hint);

                cout << "Wpisz glowne haslo: ";
                cin >> wpisaneHaslo;
                cout << endl;

                readpassword(sciezka_zewnetrzna_master,wpisaneHaslo);
            }

            if(!std::filesystem::exists(sciezka_zewnetrzna_master)){
                std::cerr << "\nPodany uzytkownik nie istnieje! Prosze utworzyc konto!" << endl;
                exit(1);
            }
            readtimestampmanual(sciezka_zewnetrzna_last);
            overwritetimestampmanual(sciezka_zewnetrzna_last);
            //tutaj manualny switch
        }
    }

    void login() {
        cout << "\nWybierz opcje: " << endl;
        cout << "0 - jezeli nie posiadasz konta" << endl;
        cout << "1 - jezeli posiadasz konto" << endl;
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
            createtimestamp();
            overwritetimestampnewuser();
            cout << "\nUtworzono nowe konto! Prosze uruchomic ponownie program."<<endl;
            exit(0);
        }
    }

private:
    string wpisaneHaslo;
};


#endif //PROJEKT_SEMESTRALNY_CPP_LOGOWANIE_H