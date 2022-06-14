//
// Created by tsera on 07.05.2022.
//

#include <string>
#include <fstream>
#include <ctime>
#include "logowanie.h"
#include "generator.h"
#include "printlogo.h"

int main(){
    time_t czas = time(0);
    char* timestamp = ctime(&czas);
    cout << "##############################\n" << endl;
    cout << "Jest: "<< timestamp << endl;
    cout << "##############################\n" << endl;
    printlogo();

    logowanie logowanieObjekt;

    logowanieObjekt.login();

    //generator();
}