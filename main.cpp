//
// Created by tsera on 07.05.2022.
//

#include <fstream>
#include <ctime>
#include "logowanie.h"
#include "printlogo.h"

/**
* Wypisuje aktualny czas i date, następnie wywołuje funckje printlogo(),
 * następnie tworzy obiekt klasy logowanie
 * i wywołuje funckje login().
 */
int main(){
    time_t czas = time(0);
    char* timestamp = ctime(&czas);
    cout << "##############################\n" << endl;
    cout << "Jest: "<< timestamp << endl;
    cout << "##############################\n" << endl;
    printlogo();

    logowanie logowanieObjekt;

    logowanieObjekt.login();
}