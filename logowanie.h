//
// Created by tsera on 07.05.2022.
//

#ifndef PROJEKT_SEMESTRALNY_CPP_LOGOWANIE_H
#define PROJEKT_SEMESTRALNY_CPP_LOGOWANIE_H
#include <fstream>
#include <iostream>
#include "haslo.h"
#include "Haslo_Manual.h"
#include "Switch.h"
#include "Switch_Manual.h"

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

    /**
     * Poniższy kod jest odpowiedzialny za logowanie do programu.
     * Użytkownik może wybrać czy chce zalogować się przy pomocy nazwy użytkownika czy ścieżki.
     */
    void poprzednielogowanie(){
        cout << "\nWybierz opcje: " << endl;
        cout << "0 - jezeli chcesz zalogowac sie za pomoca nazwy uzytkownika" << endl;
        cout << "1 - jezeli chcesz zalgowac sie za pomoca sciezki" << endl;
        cout << "\nTwoj wybor: ";
        cin >> odpowiedzpoprzednie;
        /**
         * Sprawdzenie input ze strony użytkownika jest poprawny.
         * Jeżeli nie jest, program prosi użytkownika o wprowadzenie prawidłowej wartości.
         * @param odpowiedzpoprzednie - decyzja użytkownika czy chce zalogować się za pomocą nazwy użytkownika czy ścieżki.
         */
        while(odpowiedzpoprzednie!='1' && odpowiedzpoprzednie!= '0'){
            cin.clear();
            cin.ignore(INT_MAX,'\n'); //usuwanie \n

            cout << "\nWprowadzono nieprawidlowa opcje - prosze wprowadzic: "
                    "\n0 - chcesz zalogowac sie za pomoca nazwy uzytkownika"
                    "\n1 - jezeli chcesz zalgowac sie za pomoca sciezki" << endl;
            cout << "\nTwoj wybor: ";
            cin >> odpowiedzpoprzednie;
        }
        /**
         * Logowanie za pomocą nazwy użytkownika.
         * @param odpowiedzpoprzednie - decyzja użytkownika czy chce zalogować się za pomocą nazwy użytkownika czy ścieżki.
         */
        if(odpowiedzpoprzednie == '0'){
            cout << "\nWprowadz nazwe uzytkownika: ";
            cin >> imie_login;

            sciezka_login.append("../");
            sciezka_login.append(imie_login);
            sciezka_login.append("_masterpassword.txt");
            /**
             * Jeżeli plik z danymi do logowania istnieje.
             * @param sciezka_login - utworzona ścieżka do pliku z głównym hasłem do logowania.
             */
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
            /**
             * Jeżeli plik z danymi do logowania NIE istnieje.
             * @param sciezka_login - utworzona ścieżka do pliku z głównym hasłem do logowania.
             */
            if(!std::filesystem::exists(sciezka_login)){
                std::cerr << "\nPodany uzytkownik nie istnieje! Prosze utworzyc konto!" << endl;
                exit(1);
            }

            readtimestamp(imie_login);
            overwritetimestamp(imie_login);
            funkcja_switch(imie_login);
        }
        /**
         * Logowanie za pomocą ścieżki.
         * @param odpowiedzpoprzednie - decyzja użytkownika czy chce zalogować się za pomocą nazwy użytkownika czy ścieżki.
         */
        if(odpowiedzpoprzednie == '1'){
            cout << "\nWprowadz sciezke do podpowiedzi:";
            cin >> sciezka_zewnetrzna_hint;

            /**
             * Jeżeli plik z podpowiedzią NIE istnieje - odnieś się do pliku z informacją.
             * @param sciezka_zewnetrzna_hint - ścieżka podana przez użytkownika do pliku z głównym hasłem do logowania.
             */
            if(!std::filesystem::exists(sciezka_zewnetrzna_hint)){
                cout << "Podany plik nie istnieje, lub podano nieprawidlowa sciezke do pliku!" << endl;
            }

            else{
                cout << "\nWybrano podana sciezke: " << sciezka_zewnetrzna_hint << endl;
            }

            cout << "\nWprowadz sciezke do glownego hasla: ";
            cin >> sciezka_zewnetrzna_master;

            /**
             * Jeżeli plik z danymi do logowania NIE istnieje.
             * @param sciezka_zewnetrzna_master - ścieżka podana przez użytkownika do pliku z głównym hasłem do logowania.
             */
            if(!std::filesystem::exists(sciezka_zewnetrzna_master)){
                std::cerr << "\nPodany uzytkownik nie istnieje! Prosze utworzyc konto!" << endl;
                exit(1);
            }

            else{
                cout << "\nWybrano podana sciezke: " << sciezka_zewnetrzna_master << endl;
            }

            cout << "\nWprowadz sciezke do pliku z informacja o ostatnim deszyfrowaniu: ";
            cin >> sciezka_zewnetrzna_last;

            /**
             * Jeżeli plik z danymi o ostatnim deszyfrowaniu NIE istnieje.
             * @param sciezka_zewnetrzna_last - ścieżka podana przez użytkownika do pliku z głównym hasłem do logowania.
             */
            if(!std::filesystem::exists(sciezka_zewnetrzna_last)){
                std::cerr << "\nPodany plik nie istnieje! Nie można zweryfikować integralności danych!" << endl;
                exit(1);
            }

            else{
                cout << "\nWybrano podana sciezke: " << sciezka_zewnetrzna_last << endl;
            }

            cout << "\nWprowadz sciezke do folderu z kategoriami hasel: ";
            cin >> sciezka_zewnetrzna_kategorie;

            /**
             * Jeżeli katalog z plikami z kategoriami haseł NIE istnieje.
             * @param sciezka_zewnetrzna_kategorie - ścieżka podana przez użytkownika do pliku z głównym hasłem do logowania.
             */
            if(!std::filesystem::exists(sciezka_zewnetrzna_kategorie)){
                std::cerr << "\nPodany katalog nie istnieje! Prosze utworzyc konto!" << endl;
                exit(1);
            }

            else{
                cout << "\nWybrano podana sciezke: " << sciezka_zewnetrzna_kategorie << endl;
            }

            /**
             * Jeżeli plik z danymi do logowania istnieje.
             * @param sciezka_zewnetrzna_master - ścieżka podana przez użytkownika do pliku z głównym hasłem do logowania.
             */
            if(std::filesystem::exists(sciezka_zewnetrzna_master)){

                wyswietlpodpowiedz(sciezka_zewnetrzna_hint);

                cout << "Wpisz glowne haslo: ";
                cin >> wpisaneHaslo;
                cout << endl;

                readpassword(sciezka_zewnetrzna_master,wpisaneHaslo);
            }

            readtimestampmanual(sciezka_zewnetrzna_last);
            overwritetimestampmanual(sciezka_zewnetrzna_last);
            funkcja_switch_manual(sciezka_zewnetrzna_hint,sciezka_zewnetrzna_master,sciezka_zewnetrzna_last,sciezka_zewnetrzna_kategorie);
        }
    }
    /**
     * Funkcja pozwalająca użytkownikowi wybrać czy posiada już konto czy nie.
     * Jeżeli posiada konto - może się zalogować.
     * Jeżeli nie posiada konta - może stworzyć nowe konto.
     */
    void login() {
        cout << "\nWybierz opcje: " << endl;
        cout << "0 - jezeli nie posiadasz konta" << endl;
        cout << "1 - jezeli posiadasz konto" << endl;
        cout << "\nTwoj wybor: ";
        cin >> odpowiedz;
        /**
         * Sprawdzenie input ze strony użytkownika jest poprawny.
         * Jeżeli nie jest, program prosi użytkownika o wprowadzenie prawidłowej wartości.
         * @param odpowiedz - decyzja użytkownika czy chce zalogować się do istniejącego konta lub czy chce utworzyć nowe.
         */
        while(odpowiedz!='1' && odpowiedz!= '0'){
            cin.clear();
            cin.ignore(INT_MAX,'\n'); //usuwanie \n

            cout << "\nWprowadzono nieprawidlowa opcje - prosze wprowadzic: "
                    "\n0 - jezeli nie uzywales/as wczesniej programu"
                    "\n1 - jezeli uzywales/as wczesniej programu" << endl;
            cout << "\nTwoj wybor: ";
            cin >> odpowiedz;
        }
        /**
         * Jeżeli użytkownik posiada już konto i chce się do niego zalogować.
         * @param odpowiedz - decyzja użytkownika czy chce zalogować się do istniejącego konta lub czy chce utworzyć nowe.
         */
        if (odpowiedz == '1') {
            poprzednielogowanie();
        }
        /**
         * Jeżeli użytkownik nie posiada konta, lub chce utworzyć nowe.
         * @param odpowiedz - decyzja użytkownika czy chce zalogować się do istniejącego konta lub czy chce utworzyć nowe.
         */
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