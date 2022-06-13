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

string imie;
string haslo1;
string haslo2;
string tekst;
string sciezkamaster;
string podpowiedzmaster;
string nazwaKataloguKategorie;
char pod;
char odpkat;

void zledane();

void nowy_user(){
    cout << "\nHej! Wyglada na to, ze jest to twoje pierwsze uzycie programu!\n" << endl;
    cout << "Podaj swoja nazwe uzytkownika: ";
    cin >> imie;
    cout << "\nWitaj w Managerze Hasel " << imie << "! Prosze wprowadz swoje glowne haslo, ktore bedzie sluzylo do odblokowania portfela!" << endl;
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
        sciezkamaster.append("../");
        sciezkamaster.append(imie);
        sciezkamaster.append("_masterpassword.txt");
        fstream userpassword;

        //R przed bo CLion zamienia na Raw-String Literal
        userpassword.open(sciezkamaster,std::ios::out);

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

            cout << "\nProsze wprowadzic swoja podpowiedz:" << endl;

            podpowiedzmaster.append("../");
            podpowiedzmaster.append(imie);
            podpowiedzmaster.append("_passwordhint.txt");

            fstream tekst_pod;
            tekst_pod.open(podpowiedzmaster,std::ios::out);
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

void readpassword(string sciezka,string password){
    fstream fileIn;
    fileIn.open(sciezka,std::ios::in);


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

void wyswietlpodpowiedz(string sciezka){
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
        cout << "\nTwoja podopowiedz: ";
        if(std::filesystem::exists(sciezka)){
            fstream input;
            input.open(sciezka,std::ios::in);
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

void stworzkategorie(){
    nazwaKataloguKategorie.append("../");
    nazwaKataloguKategorie.append(imie);
    nazwaKataloguKategorie.append("_Categories");
    std::filesystem::create_directories(nazwaKataloguKategorie);

    cout << "\n\n\nKazde haslo powinno miec przypisana kategorie!" << endl;
    cout << "\nProponujemy nastepujace kategorie:" << endl;
    cout << "- Rozrywka\n- Gry\n- Produktywnosc\n- Zakupy\n- Serwisy Spolecznosciowe\n- Podroze\n- Brak kategori" << endl;
    cout << "\nCzy chcesz utworzyc nastepujace kategorie?" << endl;
    cout << "Tak(t)/Nie(n)" << endl;
    cout << "\nTwoj wybor: ";
    cin >> odpkat;

    while(odpkat != 't' && odpkat != 'n'){
        cin.clear();
        cin.ignore(INT_MAX,'\n'); //usuwanie \n

        cout << "Wprowadzono nieprawidlowa opcje - prosze wprowadzic: \nt - dla tak\nn - dla nie" << endl;
        cin >> odpkat;
    }

    if(odpkat == 't'){
        
    }

    if(odpkat == 'n'){

    }
}

#endif //PROJEKT_SEMESTRALNY_CPP_HASLO_H
