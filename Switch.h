//
// Created by tsera on 14.06.2022.
//

#ifndef PROJEKT_SEMESTRALNY_CPP_SWITCH_H
#define PROJEKT_SEMESTRALNY_CPP_SWITCH_H
#include <iostream>


void funkcja_switch(){
    char decyzja;

    cout << "\n**************************************************" << endl;
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
    cout << "\n**************************************************" << endl;
    cout << endl;
    cout << "Twoj wybor: ";
    cin >> decyzja;

    switch (decyzja){
        case '1':
            cout << "\nWybrano wyszukiwanie hasla!" << endl;

            break;

        case '2':
            cout << "\nWybrano sortowanie hasel!" << endl;

            break;

        case '3':
            cout << "\nWybrano dodawanie hasla!" << endl;

            break;

        case '4':
            cout << "\nWybrano edycje hasla!" << endl;

            break;

        case '5':
            cout << "\nWybrano usuwanie hasla!" << endl;

            break;

        case '6':
            cout << "\nWybrano dodawanie kategorii!" << endl;
            addCategory();
            funkcja_switch();
            break;

        case '7':
            cout << "\nWybrano usuwanie kategorii!" << endl;

            break;

        case '8':
            cout << "\nDziekujemy za skorzystanie z programu!" << endl;
            exit(0);

        case '0':
            cout << "\n Wybrano wymazywanie konta!!!"<<endl;

            break;

        default:
            cin.clear();
            cin.ignore(INT_MAX,'\n');

            funkcja_switch();
            break;
    }
}
#endif //PROJEKT_SEMESTRALNY_CPP_SWITCH_H
