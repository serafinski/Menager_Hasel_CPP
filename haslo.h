//
// Created by tsera on 09.05.2022.
//

#ifndef PROJEKT_SEMESTRALNY_CPP_HASLO_H
#define PROJEKT_SEMESTRALNY_CPP_HASLO_H
#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

using std::string; using std::cout; using std::cin; using std::endl; using std::ofstream; using std::fstream;

void zledane();

void readpassword(string password){
    fstream fileIn;
    fileIn.open(R"(D:\PJATK\Semestr_2\PJC\Projekt_Semestralny_CPP\user-password.txt)",std::ios::in);


    if(fileIn.is_open()){
        string line;
        while (getline(fileIn,line)){
            if(line == password){
                cout << "Wpisane haslo jest poprawne!" <<endl;
            }
            else{
                cout << "Wpisane haslo jest nie poprawne - moga wystapic problemy!" << endl;
            }
        }
        fileIn.close();
    }
}

void wyswietlpodpowiedz(){
    char odp;

    cout << "Czy pamietasz swoje haslo?\nt - tak\nn - nie, wyswietl podpowiedz" << endl;
    cout<<"\nTwoja decyzja: ";
    cin >> odp;

    while(odp != 't' && odp != 'n'){
        cin.clear();
        cin.ignore(INT_MAX,'\n'); //usuwanie \n

        cout << "Wprowadzono nieprawidlowa opcje - prosze wprowadzic: \nt - dla tak\nn - dla nie, wyswietl podpowiedz" << endl;
        cin >> odp;
    }

    if (odp == 'n'){
        //trzeba wyczyścić po wyborze?
        cin.clear();
        cin.ignore(INT_MAX,'\n');
        if(std::filesystem::exists(R"(D:\PJATK\Semestr_2\PJC\Projekt_Semestralny_CPP\podpowiedz.txt)")){
            fstream input;
            input.open(R"(D:\PJATK\Semestr_2\PJC\Projekt_Semestralny_CPP\podpowiedz.txt)",std::ios::in);
            if(input.is_open()){
                string line;

                while (getline(input,line)){
                    cout << line << endl;
                }
                input.close();
            }
        }

        else{
            cout << "Plik z podpowiedzia nie zostal utworzony przy tworzeniu glownego hasla! :(" << endl;
        }
    }
    else if(odp == 't'){
        cout << endl;
    }
}


void nowy_user(){
    string haslo1;
    string haslo2;
    string tekst;
    char pod;

    cout << "\nWyglada na to, ze jest to twoje pierwsze uzycie programu!" << endl;
    cout << "Witaj w Managerze Hasel! Prosze wprowadz swoje glowne haslo, ktore bedzie sluzylo do odblokowania portfela!" << endl;
    cout << "\nWprowadz haslo: ";
    cin >> haslo1;
    cout << endl;
    cout << "Wprowadz haslo jeszcze raz!: ";
    cin >> haslo2;
    cout << endl;

    if(haslo1 != haslo2){
        zledane();
    }
    else{
        cout << "Rejestracja przebiegla pomyslnie!" << endl;

        fstream userpassword;
        //R przed bo CLion zamienia na Raw-String Literal
        userpassword.open(R"(D:\PJATK\Semestr_2\PJC\Projekt_Semestralny_CPP\user-password.txt)",std::ios::out);

        if(userpassword.is_open()){
            userpassword << haslo1;
            userpassword.close();
        }

        cout << "Twoje haslo to: " << haslo1 << endl;

        cout << endl;

        cout << "Czy chcesz wprowadzic podpowiedz - w razie zapomnienia hasla?" << endl;
        cout << "Tak(t)/Nie(n)" << endl;
        cout<<"\nTwoja decyzja: ";
        cin >> pod;


        while (pod != 't' && pod != 'n'){
            cin.clear();
            cin.ignore(INT_MAX,'\n'); //usuwanie \n

            cout << "Wprowadzono nieprawidlowa opcje - prosze wprowadzic: \nt - dla tak\nn - dla nie" << endl;
            cin >> pod;
        }

        if (pod == 't'){
            //trzeba wyczyścić po wyborze?
            cin.clear();
            cin.ignore(INT_MAX,'\n');

            cout << "Prosze wprowadzic swoja podpowiedz:" << endl;


            fstream tekst_pod;
            tekst_pod.open(R"(D:\PJATK\Semestr_2\PJC\Projekt_Semestralny_CPP\podpowiedz.txt)",std::ios::out);
            getline(cin,tekst);

            if(tekst_pod.is_open()){
               tekst_pod << tekst;
               tekst_pod.close();
            }

            cout << "\nPodpowiedz zostala zapisana!" << endl;
        }

        else if(pod == 'n'){
            cout << "\nNie wprowadzono podpowiedzi!" << endl;
        }

    }
}

void zledane(){
    cout << "Podane hasla nie pasuja do siebie, sproboj ponownie!\n";
    cout << endl;
    nowy_user();
}

#endif //PROJEKT_SEMESTRALNY_CPP_HASLO_H
