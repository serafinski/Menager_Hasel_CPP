//
// Created by tsera on 07.05.2022.
//

#include "main.h"
#include "logowanie.h"
#include <string>
#include <fstream>
#include "generator.h"

int main(){
    cout << "###################################################################\n" << endl;
    cout << "Jest: " << __DATE__ ", godzina: " << __TIME__ << "\n"<< endl;

    logowanie logowanieObjekt;

    logowanieObjekt.login();

    //generator();
}