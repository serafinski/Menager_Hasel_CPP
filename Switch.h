//
// Created by tsera on 14.06.2022.
//

#ifndef PROJEKT_SEMESTRALNY_CPP_SWITCH_H
#define PROJEKT_SEMESTRALNY_CPP_SWITCH_H
#include <iostream>
#include "generator.h"

string nazwakategorii;



/**
 * Funkcja umożliwiająca nawigacje po programie.
 * @param imie_login - informacja o nazwie użytkownika. Potrzebna do manipulowania danymi użytkownika.
 */
void funkcja_switch(string imie_login){
    char decyzjaswitch;
    char decyzjasortowanie;
    char haslodecyzja;
    char dodajlogindecyzja;
    char dodajwwwdecyzja;
    unsigned int nrhasla;

    string potwierdzenieusuniecia;
    string kategoriadecyzja;
    string usunieciehaslodecyzja;
    string potwierdzeniezmiany;

    string nazwahasla;
    string login;
    string haslo;
    string www;
    string nowehaslo;

    cout << "\n************************************************************" << endl;
    cout << "\nOPCJE:" << endl;
    cout << endl;
    cout << "1. Wyszukaj hasla" << endl;
    cout << "2. Posortuj hasla" << endl;
    cout << "3. Dodaj haslo" << endl;
    cout << "4. Edytuj haslo" << endl;
    cout << "5. Usun haslo" << endl;
    cout << "6. Dodaj kategorie" << endl;
    cout << "7. Usun kategorie\n" << endl;
    cout << "8. Wyjdz z programu\n\n\n"<<endl;
    cout << "0. WYMAZ KONTO" << endl;
    cout << "\n************************************************************" << endl;
    cout << endl;
    cout << "Twoj wybor: ";
    cin >> decyzjaswitch;
    /**
     * Switch umożliwiający wybór opcji w programie.
     * @param decyzjaswitch - input ze strony użytkownika. Pozwala na kontrolowanie Switch'a.
     */
    switch (decyzjaswitch){
        /**
         * Case pozwalający na wyszukiwanie haseł.
         */
        case '1':
            cout << "\nWybrano wyszukiwanie hasla!" << endl;

            funkcja_switch(imie_login);
            break;
        /**
         * Case pozwalający na sortowanie haseł
         */
        case '2':
            cout << "\nWybrano sortowanie hasel!" << endl;
            concatall(imie_login);

            cout << "\nOPCJE SORTOWANIA" << endl;
            cout << "1. Posortuj nazwy hasel alfabetycznie i według wielkości liter" << endl;
            cout << "2. Posortuj loginy alfabetycznie i według wielkości liter" << endl;
            cout << "3. Posortuj hasla alfabetycznie i według wielkości liter" << endl;
            cout << "4. Posortuj adresy stron www alfabetycznie i według wielkości liter" << endl;

            cout << "\nTwoj wybor: ";
            cin >> decyzjasortowanie;

            /**
             * Switch pozwalający na wybór posortowanych danych które mają zostać zwrócone
             * @param decyzjasortowanie - input ze strony użytkownika. Pozwala na wybór sortowania.
             */
            switch (decyzjasortowanie){
                case '1':
                    cout << "\nLista nazw hasel posortowanych alfabetycznie: " << endl;
                    sortnamesalphabet(imie_login);
                    break;
                case '2':
                    cout << "\nLista loginow posortowanych alfabetycznie: " << endl;
                    sortloginsalphabet(imie_login);
                    break;
                case '3':
                    cout << "\nLista hasel posortowanych alfabetycznie: " << endl;
                    sortpasswordsalphabet(imie_login);
                    break;
                case '4':
                    cout << "\nLista adresow www posortowanych alfabetycznie: " << endl;
                    sortwwwalphabet(imie_login);
                    break;
                default:
                    break;
            }
            funkcja_switch(imie_login);
            break;
        /**
         * Case pozwalający na dodanie hasła
         */
        case '3':
            cout << "\nWybrano dodawanie hasla!" << endl;
            cout << "\nWybierz kategorie z listy:" <<endl;
            showCategory(imie_login);

            cout << "\nNazwa kategorii wg. schematu to: ../<nazwa_uzytkownika>_Categories/Names\\\\<nazwa_kategorii>.txt" << endl;
            cout << "\nWPISZ TYLKO TO CO JEST W <nazwa_kategorii>!!!" << endl;
            cout<<"\nNazwa kategorii:";
            cin >> nazwakategorii;

            cout << "\nWpisz nazwe opisujaca do czego bedzie to haslo!" << endl;
            cout << "\nNazwa hasla: ";
            cin >> nazwahasla;
            addname(imie_login,nazwakategorii,nazwahasla);

            cout << "\nCzy chcesz dodac login?" << endl;
            cout << "\nPROPONUJEMY DODANIE GO - BY ZACHOWAC SPOJNOSC PLIKOW!" << endl;
            cout << "\nWpisz:" << endl;
            cout << "t - jezeli chcesz dodac login" << endl;
            cout << "n - jezeli nie chcesz dodawac loginu" << endl;
            cout << "\nTwoj wybor: ";
            cin >> dodajlogindecyzja;

            /**
             * Sprawdzenie input ze strony użytkownika jest poprawny.
             * Jeżeli nie jest, program prosi użytkownika o wprowadzenie prawidłowej wartości.
             * @param dodajlogindecyzja - decyzja użytkownika czy chce dodać login czy nie.
             */
            while(dodajlogindecyzja != 't' && dodajlogindecyzja != 'n'){
                cin.clear();
                cin.ignore(INT_MAX,'\n'); //usuwanie \n

                cout << "Wprowadzono nieprawidlowa opcje - prosze wprowadzic: " << endl;
                cout << "t - jezeli chcesz dodac login" << endl;
                cout << "n - jezeli nie chcesz dodawac loginu" << endl;
                cout << "\nTwoj wybor: ";
                cin >> dodajlogindecyzja;
            }
            /**
             * Dodawanie loginu do pliku.
             * @param dodajlogindecyzja - decyzja użytkownika czy chce dodać login czy nie.
             */
            if(dodajlogindecyzja == 't'){
                cout << "\nWpisz login:";
                cin >> login;
                addlogin(imie_login,nazwakategorii,login);
            }
            /**
             * Nie dodawanie loginu do pliku.
             * @param dodajlogindecyzja - decyzja użytkownika czy chce dodać login czy nie.
             */
            if(dodajlogindecyzja == 'n'){
                cout << "\nNie dodano loginu!" << endl;
                cout << "MOGA POJAWIC SIE PROBLEMY ZE SPOJNOSCIA PLIKOW!" << endl;
            }

            cout << "\nCzy chcesz adres strony WWW?" << endl;
            cout << "\nPROPONUJEMY DODANIE GO - BY ZACHOWAC SPOJNOSC PLIKOW!" << endl;
            cout << "\nWpisz:" << endl;
            cout << "t - jezeli chcesz dodac adres strony WWW" << endl;
            cout << "n - jezeli nie chcesz dodawac adresu strony WWW" << endl;
            cout << "\nTwoj wybor: ";
            cin >> dodajwwwdecyzja;

            /**
             * Sprawdzenie input ze strony użytkownika jest poprawny.
             * Jeżeli nie jest, program prosi użytkownika o wprowadzenie prawidłowej wartości.
             * @param dodajwwwdecyzja - decyzja użytkownika czy chce dodać adres strony www czy nie.
             */
            while(dodajwwwdecyzja != 't' && dodajwwwdecyzja != 'n'){
                cin.clear();
                cin.ignore(INT_MAX,'\n'); //usuwanie \n

                cout << "Wprowadzono nieprawidlowa opcje - prosze wprowadzic: " << endl;
                cout << "t - jezeli chcesz dodac adres strony WWW" << endl;
                cout << "n - jezeli nie chcesz dodawac adresu strony WWW" << endl;
                cout << "\nTwoj wybor: ";
                cin >> dodajwwwdecyzja;
            }
            /**
             * Dodawanie adresu www do pliku.
             * @param dodajwwwdecyzja - decyzja użytkownika czy chce dodać adres strony www czy nie.
             */
            if(dodajwwwdecyzja == 't'){
                cout << "\nWpisz adres strony www:";
                cin >> www;
                addwww(imie_login,nazwakategorii,www);
            }
            /**
             * Nie dodawanie adresu www do pliku.
             * @param dodajwwwdecyzja - decyzja użytkownika czy chce dodać adres strony www czy nie.
             */
            if(dodajlogindecyzja == 'n'){
                cout << "\nNie dodano adresu WWW!" << endl;
                cout << "MOGA POJAWIC SIE PROBLEMY ZE SPOJNOSCIA PLIKOW!" << endl;
            }

            cout << "\nCzy chcesz wpisac wlasne haslo czy wygenerowac je za pomoca generatora hasel?" << endl;
            cout << "Wpisz:" << endl;
            cout << "0 - jezeli chcesz wpisac wlasne haslo" << endl;
            cout << "1 - jezeli chcesz wygenerowac haslo przy pomocy generatora hasel" << endl;
            cout << "\nTwoj wybor: ";
            cin >> haslodecyzja;

            /**
             * Sprawdzenie input ze strony użytkownika jest poprawny.
             * Jeżeli nie jest, program prosi użytkownika o wprowadzenie prawidłowej wartości.
             * @param haslodecyzja - decyzja użytkownika czy chce dodać własne hasło czy wygenerowane przez generator haseł.
             */

            while(haslodecyzja != '0' && haslodecyzja != '1'){
                cin.clear();
                cin.ignore(INT_MAX,'\n'); //usuwanie \n

                cout << "Wprowadzono nieprawidlowa opcje - prosze wprowadzic: "
                        "\n0 - jezeli chcesz wpisac wlasne haslo"
                        "\n1 - jezeli chcesz wygenerowac haslo przy pomocy generatora hasel" << endl;
                cout << "\nTwoj wybor: ";
                cin >> haslodecyzja;
            }
            /**
             * Dodawanie własnego hasła do pliku.
             * @param haslodecyzja - decyzja użytkownika czy chce dodać własne hasło czy wygenerowane przez generator haseł.
             */
            if(haslodecyzja == '0'){
                cout << "\nWprowadz haslo:";
                cin >> haslo;
                addpassword(imie_login,nazwakategorii,haslo);

                cout << "------------------------------------------------------------" << endl;
                cout << "\nHASLO ZOSTALO DODANE!" << endl;
                cout << "\nWybrana kategoria: " << nazwakategorii << endl;
                cout << "Nazwa hasla: " << nazwahasla << endl;
                cout << "Login: " << login << endl;
                cout << "Haslo: " << haslo << endl;
            }
            /**
             * Dodawanie wygenerowanego hasła do pliku.
             * @param haslodecyzja - decyzja użytkownika czy chce dodać własne hasło czy wygenerowane przez generator haseł.
             */
            if (haslodecyzja == '1'){
                generator(imie_login,nazwakategorii);

                cout << "------------------------------------------------------------" << endl;
                cout << "\nHASLO ZOSTALO DODANE!" << endl;
                cout << "\nWybrana kategoria: " << nazwakategorii << endl;
                cout << "Nazwa hasla: " << nazwahasla << endl;
                cout << "Login: " << login << endl;
                cout << "Haslo: " << koncowehaslo <<endl;
            }
            concatall(imie_login);
            funkcja_switch(imie_login);
            break;
        /**
         * Case pozwalający na edycje hasła
         */
        case '4':
            cout << "\nWybrano edycje hasla!" << endl;
            cout << "\nWybierz kategorie z listy:" <<endl;
            showCategory(imie_login);

            cout << "\nNazwa kategorii wg. schematu to: ../<nazwa_uzytkownika>_Categories/Names\\\\<nazwa_kategorii>.txt" << endl;
            cout << "\nWPISZ TYLKO TO CO JEST W <nazwa_kategorii>!!!" << endl;
            cout<<"\nNazwa kategorii:";
            cin >> nazwakategorii;

            cout << "\nHasla w kategorii: " << endl;
            showcategorycontents(imie_login,nazwakategorii);

            cout << "\nWybierz numer hasla ktory chcesz edytowac:";
            cin >> nrhasla;

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
                cout << "\nWybierz numer hasla ktory chcesz edytowac:";
                cin >> nrhasla;
            }

            getline(imie_login,nazwakategorii,nrhasla);
            printpassword();

            cout << "\nCzy na pewno chcesz zmienic haslo?" << endl;
            cout << "\nJEST TO PROCES NIEODWRACALNY!!!" << endl;
            cout << "\nWpisz: zmienhaslo - by rozpoczac proces zmieniania hasla." << endl;
            cout << "Input uzytkownika: ";
            cin >> potwierdzeniezmiany;

            /**
             * Sprawdzenie czy użytkownik wprowadził prawidłowy input.
             * @param potwierdzeniezmiany - input ze strony użytkownika informujący program czy ma wykonać akcje czy nie.
             */
            if(potwierdzeniezmiany == "zmienhaslo"){
                cout << "\nCzy chcesz wpisac wlasne haslo czy wygenerowac je za pomoca generatora hasel?" << endl;
                cout << "Wpisz:" << endl;
                cout << "0 - jezeli chcesz wpisac wlasne haslo" << endl;
                cout << "1 - jezeli chcesz wygenerowac haslo przy pomocy generatora hasel" << endl;
                cout << "\nTwoj wybor: ";
                cin >> haslodecyzja;

                /**
                * Sprawdzenie input ze strony użytkownika jest poprawny.
                * Jeżeli nie jest, program prosi użytkownika o wprowadzenie prawidłowej wartości.
                * @param haslodecyzja - decyzja użytkownika czy chce dodać własne hasło czy wygenerowane przez generator haseł.
                */
                while(haslodecyzja != '0' && haslodecyzja != '1'){
                    cin.clear();
                    cin.ignore(INT_MAX,'\n'); //usuwanie \n

                    cout << "Wprowadzono nieprawidlowa opcje - prosze wprowadzic: "
                            "\n0 - jezeli chcesz wpisac wlasne haslo"
                            "\n1 - jezeli chcesz wygenerowac haslo przy pomocy generatora hasel" << endl;
                    cout << "\nTwoj wybor: ";
                    cin >> haslodecyzja;
                }
                /**
                 * Dodawanie własnego hasła do pliku.
                 * @param haslodecyzja - decyzja użytkownika czy chce dodać własne hasło czy wygenerowane przez generator haseł.
                 */
                if(haslodecyzja == '0'){
                    cout << "\nWprowadz haslo:";
                    cin >> nowehaslo;
                }
                /**
                 * Dodawanie wygenerowanego hasła do pliku.
                 * @param haslodecyzja - decyzja użytkownika czy chce dodać własne hasło czy wygenerowane przez generator haseł.
                 */
                if (haslodecyzja == '1'){
                    generator(imie_login,nazwakategorii);
                    nowehaslo = koncowehaslo;
                }
                changepassword(imie_login,nazwakategorii,nowehaslo);
                funkcja_switch(imie_login);
            }
            /**
             * Jeżeli użytkownik wprowadził nieprawidłowy input.
             */
            else{
                cout << "\nWprowadzono zly input." << endl;
                cout << "Zmiana hasla nie powiodla sie!" << endl;
                funkcja_switch(imie_login);
            }
            concatall(imie_login);
            funkcja_switch(imie_login);
            break;
        /**
         * Case pozwalający na usuwanie hasła.
         */
        case '5':
            cout << "\nWybrano usuwanie hasla!" << endl;
            cout << "\nWybierz kategorie z listy:" <<endl;
            showCategory(imie_login);

            cout << "\nNazwa kategorii wg. schematu to: ../<nazwa_uzytkownika>_Categories/Names\\\\<nazwa_kategorii>.txt" << endl;
            cout << "\nWPISZ TYLKO TO CO JEST W <nazwa_kategorii>!!!" << endl;
            cout<<"\nNazwa kategorii:";
            cin >> nazwakategorii;

            cout << "\nHasla w kategorii: " << endl;
            showcategorycontents(imie_login,nazwakategorii);
            cout << "\nWybierz NUMER hasla ktory chcesz usunac:";
            cin >> nrhasla;

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
                cin >> nrhasla;
            }

            cout << "\nCzy na pewno chcesz usunac podane haslo?" << endl;
            cout << "\nJEST TO PROCES NIEODWRACALNY!!!" << endl;
            cout << "\nWpisz: usunhaslo - by usunac haslo." << endl;
            cout << "Input uzytkownika: ";
            cin >> usunieciehaslodecyzja;

            /**
             * Sprawdzenie czy użytkownik wprowadził prawidłowy input.
             * @param usunieciehaslodecyzja - input ze strony użytkownika informujący program czy ma wykonać akcje czy nie.
             */
            if(usunieciehaslodecyzja == "usunhaslo"){
                deletename(imie_login,nazwakategorii, nrhasla);
                deletelogin(imie_login,nazwakategorii, nrhasla);
                deletepassword(imie_login,nazwakategorii, nrhasla);
                deletewww(imie_login,nazwakategorii, nrhasla);

                cout << "\nUsunieto haslo nr: " << nrhasla << endl;

                concatall(imie_login);
                funkcja_switch(imie_login);
            }
            /**
             * Jeżeli użytkownik wprowadził nieprawidłowy input.
             */
            else{
                cout << "\nWprowadzono zly input." << endl;
                cout << "Usuniecie hasla nie powiodlo sie!" << endl;
                funkcja_switch(imie_login);
            }
            break;
        /**
         * Case pozwalający na dodawanie kategorii.
         */
        case '6':
            cout << "\nWybrano dodawanie kategorii!" << endl;
            addCategory(imie_login);
            concatall(imie_login);
            funkcja_switch(imie_login);
            break;
        /**
         * Case pozwalający na usuwanie kategorii.
         */
        case '7':
            cout << "\nWybrano usuwanie kategorii!" << endl;
            cout << "\nWybierz kategorie z listy:" <<endl;
            showCategory(imie_login);

            cout << "\nNazwa kategorii wg. schematu to: ../<nazwa_uzytkownika>_Categories/Names\\\\<nazwa_kategorii>.txt" << endl;
            cout << "\nWPISZ TYLKO TO CO JEST W <nazwa_kategorii>!!!" << endl;
            cout<<"\nNazwa kategorii:";
            cin >> nazwakategorii;

            cout << "Czy na pewno chcesz usunac podana kategorie: " << nazwakategorii <<"?" << endl;
            cout << "\nJEST TO PROCES NIEODWRACALNY!!!" << endl;
            cout << "\nWpisz: usunkategorie - by usunac konto." << endl;
            cout << "Input uzytkownika: ";
            cin >> kategoriadecyzja;

            /**
             * Sprawdzenie czy użytkownik wprowadził prawidłowy input.
             * @param kategoriadecyzja - input ze strony użytkownika informujący program czy ma wykonać akcje czy nie.
             */
            if(kategoriadecyzja == "usunkategorie"){
                cout << "\nUsuwanie kategorii: " << nazwakategorii << endl;
                removeCategory(imie_login,nazwakategorii);
                cout << "Podana kategoria zostala usunieta!" << endl;
                concatall(imie_login);
                funkcja_switch(imie_login);
            }
            /**
             * Jeżeli użytkownik wprowadził nieprawidłowy input.
             */
            else{
                cout << "\nWprowadzono zly input." << endl;
                cout << "Usuniecie kategorii nie powiodlo sie!" << endl;
                funkcja_switch(imie_login);
            }
            break;
        /**
         * Case pozwalający na wyjście z programu.
         */
        case '8':
            cout << "\nDziekujemy za skorzystanie z programu!" << endl;
            exit(0);
        /**
         * Case pozwalający na usunięcie profilu użytkownika.
         */
        case '0':
            cout << "\nWybrano wymazywanie konta!!!"<<endl;
            cout << "Czy na pewno chcesz usunac konto?" << endl;
            cout << "\nJEST TO PROCES NIEODWRACALNY!!!" << endl;
            cout << "\nWpisz: usunkonto - by usunac konto." << endl;
            cout << "Input uzytkownika: ";
            cin >> potwierdzenieusuniecia;

            /**
             * Sprawdzenie czy użytkownik wprowadził prawidłowy input.
             * @param potwierdzenieusuniecia - input ze strony użytkownika informujący program czy ma wykonać akcje czy nie.
             */
            if(potwierdzenieusuniecia == "usunkonto"){
                deleteaccount(imie_login);
                cout << "\nDziekujemy za skorzystanie z programu!" << endl;
                cout << "\nMamy nadzieje, ze do nas wrocisz! :)" << endl;
                exit(0);
            }
            /**
             * Jeżeli użytkownik wprowadził nieprawidłowy input.
             */
            else{
                cout << "\nWprowadzono zly input." << endl;
                cout << "Usuniecie konta nie powiodlo sie!" << endl;
                funkcja_switch(imie_login);
            }
            break;
        /**
         * Default case - w przypadku wprowadzenia czegoś innego niż przewidziana treść.
         */
        default:
            cin.clear();
            cin.ignore(INT_MAX,'\n');

            funkcja_switch(imie_login);
            break;
    }
}
#endif //PROJEKT_SEMESTRALNY_CPP_SWITCH_H
