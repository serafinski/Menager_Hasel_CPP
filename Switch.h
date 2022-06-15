//
// Created by tsera on 14.06.2022.
//

#ifndef PROJEKT_SEMESTRALNY_CPP_SWITCH_H
#define PROJEKT_SEMESTRALNY_CPP_SWITCH_H
#include <iostream>
#include "generator.h"

string nazwakategorii;

void funkcja_switch(string imie_login){
    char decyzja;
    char haslodecyzja;

    string potwierdzenieusuniecia;
    string nazwahasla;
    string login;
    string haslo;

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
    cin >> decyzja;

    switch (decyzja){
        case '1':
            cout << "\nWybrano wyszukiwanie hasla!" << endl;

            funkcja_switch(imie_login);
            break;

        case '2':
            cout << "\nWybrano sortowanie hasel!" << endl;

            funkcja_switch(imie_login);
            break;

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

            cout << "\nWpisz login:";
            cin >> login;
            addlogin(imie_login,nazwakategorii,login);

            cout << "\nCzy chcesz wpisac wlasne haslo czy wygenerowac je za pomoca generatora hasel?" << endl;
            cout << "Wpisz:" << endl;
            cout << "0 - jezeli chcesz wpisac wlasne haslo" << endl;
            cout << "1 - jezeli chcesz wygenerowac haslo przy pomocy generatora hasel" << endl;
            cout << "\nTwoj wybor: ";
            cin >> haslodecyzja;

            while(haslodecyzja != '0' && haslodecyzja != '1'){
                cin.clear();
                cin.ignore(INT_MAX,'\n'); //usuwanie \n

                cout << "Wprowadzono nieprawidlowa opcje - prosze wprowadzic: "
                        "\n0 - jezeli chcesz wpisac wlasne haslo"
                        "\n1 - jezeli chcesz wygenerowac haslo przy pomocy generatora hasel" << endl;
                cout << "\nTwoj wybor: ";
                cin >> haslodecyzja;
            }

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
            if (haslodecyzja == '1'){
                generator(imie_login,nazwakategorii);

                cout << "------------------------------------------------------------" << endl;
                cout << "\nHASLO ZOSTALO DODANE!" << endl;
                cout << "\nWybrana kategoria: " << nazwakategorii << endl;
                cout << "Nazwa hasla: " << nazwahasla << endl;
                cout << "Login: " << login << endl;
                cout << "Haslo: " << koncowehaslo <<endl;
            }

            funkcja_switch(imie_login);
            break;

        case '4':
            cout << "\nWybrano edycje hasla!" << endl;

            funkcja_switch(imie_login);
            break;

        case '5':
            cout << "\nWybrano usuwanie hasla!" << endl;

            funkcja_switch(imie_login);
            break;

        case '6':
            cout << "\nWybrano dodawanie kategorii!" << endl;
            addCategory(imie_login);
            funkcja_switch(imie_login);
            break;

        case '7':
            cout << "\nWybrano usuwanie kategorii!" << endl;

            cout << "\nWybierz kategorie z listy:" <<endl;
            showCategory(imie_login);

            cout << "\nNazwa kategorii wg. schematu to: ../<nazwa_uzytkownika>_Categories/Names\\\\<nazwa_kategorii>.txt" << endl;
            cout << "\nWPISZ TYLKO TO CO JEST W <nazwa_kategorii>!!!" << endl;
            cout<<"\nNazwa kategorii:";
            cin >> nazwakategorii;
            cout << "\nUsuwanie kategorii: " << nazwakategorii << endl;
            removeCategory(imie_login,nazwakategorii);
            cout << "Podana kategoria zostala usunieta!" << endl;
            funkcja_switch(imie_login);
            break;

        case '8':
            cout << "\nDziekujemy za skorzystanie z programu!" << endl;
            exit(0);

        case '0':
            cout << "\nWybrano wymazywanie konta!!!"<<endl;
            cout << "Czy na pewno chcesz usunac konto?" << endl;
            cout << "\nJEST TO PROCES NIEODWRACALNY!!!" << endl;
            cout << "\nWpisz: usunkonto - by usunac konto." << endl;
            cout << "Input uzytkownika: ";
            cin >> potwierdzenieusuniecia;

            if(potwierdzenieusuniecia == "usunkonto"){
                deleteaccount(imie_login);
                cout << "\nDziekujemy za skorzystanie z programu!" << endl;
                cout << "\nMamy nadzieje, ze do nas wrocisz! :)" << endl;
                exit(0);
            }
            else{
                cout << "\nWprowadzono zly input." << endl;
                cout << "Usuniecie konta nie powiodlo sie!" << endl;
                funkcja_switch(imie_login);
            }
            break;

        default:
            cin.clear();
            cin.ignore(INT_MAX,'\n');

            funkcja_switch(imie_login);
            break;
    }
}
#endif //PROJEKT_SEMESTRALNY_CPP_SWITCH_H
