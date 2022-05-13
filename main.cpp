//
// Created by tsera on 07.05.2022.
//

#include "main.h"
#include "logowanie.h"
#include <string>
#include <fstream>
#include "generator.h"
#include "printlogo.h"

int main(){
    cout << "########################################" << endl;
    cout << "# Jest: " << __DATE__ ", godzina: " << __TIME__ << " #"<< endl;
    cout << "########################################\n" << endl;
    printlogo();

    logowanie logowanieObjekt;

    logowanieObjekt.login();

    //generator();
}