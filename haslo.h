//
// Created by tsera on 09.05.2022.
//

#ifndef PROJEKT_SEMESTRALNY_CPP_HASLO_H
#define PROJEKT_SEMESTRALNY_CPP_HASLO_H
#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <cstdint>
#include <bits/stdc++.h>

using std::string; using std::cout; using std::cin; using std::endl; using std::ofstream; using std::fstream;

string imie;
string haslo1;
string haslo2;
string tekst;
string sciezkamaster;
string podpowiedzmaster;
string nazwaKataloguKategorie;
string nazwaKataloguNazwy;
string nazwaKataloguLoginy;
string nazwaKataloguHasla;
string nazwaKataloguWWW;
string nazwaKataloguConcat;
string liniadousuniecia;

/**
 * Deklaracja funkcji zledane.
 */
void zledane();

/**
 * Funkcja służąca do utworzenia nowego użytkownika.
 */
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

    /**
     * Jeżeli wprowadzone hasło NIE jest takie samo jak potwierdzenie hasła.
     * @param haslo1 - hasło wprowadzone przez użytkownika
     * @param haslo2 - hasło wprowadzone przez użytkownika jako potwierdzenie haslo1
     */
    if(haslo1 != haslo2){
        zledane();
    }
    /**
     * Jeżeli wprowadzone hasło jest takie samo jak potwierdzenie hasła.
     * @param haslo1 - hasło wprowadzone przez użytkownika
     * @param haslo2 - hasło wprowadzone przez użytkownika jako potwierdzenie haslo1
     */
    else{
        char pod;

        cout << "Rejestracja przebiegla pomyslnie!" << endl;
        sciezkamaster.append("../");
        sciezkamaster.append(imie);
        sciezkamaster.append("_masterpassword.txt");
        fstream userpassword;

        userpassword.open(sciezkamaster,std::ios::out);


        /**
         * Tworzenie pliku o nazwie zgodnej z ze ścieżką sciezkamaster i wpisywanie do niego zmiennej haslo1.
         */
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

        /**
         * Sprawdzenie input ze strony użytkownika jest poprawny.
         * Jeżeli nie jest, program prosi użytkownika o wprowadzenie prawidłowej wartości.
         * @param pod - decyzja użytkownika czy wprowadzić podpowiedź czy nie.
         */
        while (pod != 't' && pod != 'n'){
            cin.clear();
            cin.ignore(INT_MAX,'\n'); //usuwanie \n

            cout << "Wprowadzono nieprawidlowa opcje - prosze wprowadzic: \nt - dla tak\nn - dla nie" << endl;
            cout << "\nTwoj wybor: ";
            cin >> pod;
        }
        /**
         * Jeżeli użytkownik chce wprowadzić podpowiedź.
         * @param pod - decyzja użytkownika czy wprowadzić podpowiedź czy nie.
         */
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
            /**
             * Tworzenie pliku o nazwie zgodnej ze ścieżką podpowiedzmaster i wpisanie do niego zmiennej tekst.
             */
            if(tekst_pod.is_open()){
                tekst_pod << tekst;
                tekst_pod.close();
            }

            cout << "\nPodpowiedz zostala zapisana!" << endl;
        }
        /**
         * Jeżeli użytkownik NIE chce wprowadzić podpowiedź.
         * @param pod - decyzja użytkownika czy wprowadzić podpowiedź czy nie.
         */
        else if(pod == 'n'){
            cout << "\nNie wprowadzono podpowiedzi!" << endl;
        }

    }
}

/**
 * Funkcja wywoływana kiedy użytkownik wpisuje 2 niepasujące do siebie hasła.
 */
void zledane(){
    cout << "Podane hasla nie pasuja do siebie, sprobuj ponownie!\n";
    cout << endl;
    nowy_user();
}

/**
 * Funkcja czytająca hasło z pliku i porównująca je z hasłem wprowadzonym przez użytkownika.
 * @param sciezka - ścieżka do pliku z którym porównywane jest hasło wprowadzone przez użytkownika.
 * @param password - hasło wprowadzone przez użytkownika
 */
void readpassword(string sciezka,string password){
    fstream fileIn;
    fileIn.open(sciezka,std::ios::in);

    /**
     * Funkcja sprawdzająca czy hasło wpisane przez użytkownika jest prawidłowe.
     */
    if(fileIn.is_open()){
        string line;
        while (getline(fileIn,line)){
            if(line == password){
                cout << "Wpisane haslo jest poprawne!" <<endl;
            }
            else{
                std::cerr << "\nWpisane haslo jest nie poprawne - moga wystapic problemy z deszyfrowaniem hasel!" << endl;
            }
        }
        fileIn.close();
    }
}

/**
 * Funkcja wyświetlająca podpowiedź z pliku przypisanego do konta użytkownika.
 * @param sciezka - ścieżka do pliku z podpowiedzią
 */
void wyswietlpodpowiedz(string sciezka){
    char odp;

    cout << "\nCzy pamietasz swoje haslo?\nt - tak\nn - nie, wyswietl podpowiedz" << endl;
    cout<<"\nTwoja decyzja: ";
    cin >> odp;

    /**
     * Sprawdzenie input ze strony użytkownika jest poprawny.
     * Jeżeli nie jest, program prosi użytkownika o wprowadzenie prawidłowej wartości.
     * @param odp - decyzja użytkownika czy chce wyświetlić podpowiedź czy nie.
     */
    while(odp != 't' && odp != 'n'){
        cin.clear();
        cin.ignore(INT_MAX,'\n'); //usuwanie \n

        cout << "Wprowadzono nieprawidlowa opcje - prosze wprowadzic: \nt - dla tak\nn - dla nie, wyswietl podpowiedz" << endl;
        cout << "\nTwoj wybor:";
        cin >> odp;
    }

    /**
     * Jeżeli użytkownik NIE chce wyświetlić podpowiedzi.
     * @param odp - decyzja użytkownika czy chce wyświetlić podpowiedź czy nie.
     */
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
        /*
         * Jeżeli nie utworzono pliku z podpowiedzią przy tworzeniu profilu nowego użytkownika.
         */
        else{
            cout << "Plik z podpowiedzia nie zostal utworzony przy tworzeniu glownego hasla! :(" << endl;
        }
    }
    /**
     * Jeżeli użytkownik chce wyświetlić podpowiedzi.
     * @param odp - decyzja użytkownika czy chce wyświetlić podpowiedź czy nie.
     */
    else if(odp == 't'){
        cout << endl;
    }
}
/**
 * Wyświetlanie wszystkich kategorii haseł.
 * @param imie_login - informacja o nazwie użytkownika. Potrzebna do manipulowania danymi użytkownika.
 */
void showCategory(string imie_login){
    string nazwasciezki;
    nazwasciezki.append("../");
    nazwasciezki.append(imie_login);
    nazwasciezki.append("_Categories/Names");

    /**
     * Wypisywanie wszystkich plików w danym katalogu.
     */
    for (const auto & entry : std::filesystem::directory_iterator(nazwasciezki)){
        cout << entry.path() << endl;
    }
}

/**
 * Tworzenie nowej kategorii dla użytkownika.
 * @param imie_login - informacja o nazwie użytkownika. Potrzebna do manipulowania danymi użytkownika.
 */
void addCategory(string imie_login){
    string nazwasciezki;
    string nazwasciezkinazwy;
    string nazwasciezkilogin;
    string nazwasciezkihaslo;
    string nazwasciezkiwww;
    string nazwakategorii;

    nazwasciezki.append("../");
    nazwasciezki.append(imie_login);
    nazwasciezki.append("_Categories");

    cout << "\nProsze wprowadzic nazwe kategorii: ";
    cin >> nazwakategorii;

    nazwasciezki.append("/");

    nazwasciezkinazwy = nazwasciezki;
    nazwasciezkinazwy.append("Names/");
    nazwasciezkinazwy.append(nazwakategorii);
    nazwasciezkinazwy.append(".txt");

    nazwasciezkilogin = nazwasciezki;
    nazwasciezkilogin.append("Logins/");
    nazwasciezkilogin.append(nazwakategorii);
    nazwasciezkilogin.append("_Logins");
    nazwasciezkilogin.append(".txt");

    nazwasciezkihaslo = nazwasciezki;
    nazwasciezkihaslo.append("Passwords/");
    nazwasciezkihaslo.append(nazwakategorii);
    nazwasciezkihaslo.append("_Passwords");
    nazwasciezkihaslo.append(".txt");

    nazwasciezkiwww = nazwasciezki;
    nazwasciezkiwww.append("Websites/");
    nazwasciezkiwww.append(nazwakategorii);
    nazwasciezkiwww.append("_WWW");
    nazwasciezkiwww.append(".txt");

    ofstream nazwy(nazwasciezkinazwy);
    ofstream login(nazwasciezkilogin);
    ofstream haslo(nazwasciezkihaslo);
    ofstream www(nazwasciezkiwww);

    cout << "\nUtworzono kategorie: " << nazwakategorii << endl;
}
/**
 * Tworzenie nowej kategorii dla NOWEGO użytkownika. (funkcja wykorzystywana przy tworzeniu konta)
 */
void addCategorynewUser(){
    string nazwasciezki;
    string nazwasciezkinazwy;
    string nazwasciezkilogin;
    string nazwasciezkihaslo;
    string nazwasciezkiwww;
    string nazwakategorii;

    cout << "\nProsze wprowadzic nazwe kategorii: ";
    cin >> nazwakategorii;

    nazwasciezki.append(nazwaKataloguKategorie);
    nazwasciezki.append("/");

    nazwasciezkinazwy = nazwasciezki;
    nazwasciezkinazwy.append("Names/");
    nazwasciezkinazwy.append(nazwakategorii);
    nazwasciezkinazwy.append(".txt");

    nazwasciezkilogin = nazwasciezki;
    nazwasciezkilogin.append("Logins/");
    nazwasciezkilogin.append(nazwakategorii);
    nazwasciezkilogin.append("_Logins");
    nazwasciezkilogin.append(".txt");

    nazwasciezkihaslo = nazwasciezki;
    nazwasciezkihaslo.append("Passwords/");
    nazwasciezkihaslo.append(nazwakategorii);
    nazwasciezkihaslo.append("_Passwords");
    nazwasciezkihaslo.append(".txt");

    nazwasciezkiwww = nazwasciezki;
    nazwasciezkiwww.append("Websites/");
    nazwasciezkiwww.append(nazwakategorii);
    nazwasciezkiwww.append("_WWW");
    nazwasciezkiwww.append(".txt");

    ofstream nazwy(nazwasciezkinazwy);
    ofstream login(nazwasciezkilogin);
    ofstream haslo(nazwasciezkihaslo);
    ofstream www(nazwasciezkiwww);

    cout << "\nUtworzono kategorie: " << nazwakategorii << endl;
}

/**
 * Funkcja służąca usuwaniu kategorii z bazy kategorii.
 * @param imie_login - informacja o nazwie użytkownika. Potrzebna do manipulowania danymi użytkownika.
 * @param nazwa - nazwa kategorii wybranej przez użytkownika
 */
void removeCategory(string imie_login,string nazwa){
    string nazwasciezki;
    string nazwasciezkinazwy;
    string nazwasciezkilogin;
    string nazwasciezkihaslo;
    string nazwasciezkiwww;

    nazwasciezki.append("../");
    nazwasciezki.append(imie_login);
    nazwasciezki.append("_Categories");
    nazwasciezki.append("/");

    nazwasciezkinazwy = nazwasciezki;
    nazwasciezkinazwy.append("Names/");
    nazwasciezkinazwy.append(nazwa);
    nazwasciezkinazwy.append(".txt");

    nazwasciezkilogin = nazwasciezki;
    nazwasciezkilogin.append("Logins/");
    nazwasciezkilogin.append(nazwa);
    nazwasciezkilogin.append("_Logins");
    nazwasciezkilogin.append(".txt");

    nazwasciezkihaslo = nazwasciezki;
    nazwasciezkihaslo.append("Passwords/");
    nazwasciezkihaslo.append(nazwa);
    nazwasciezkihaslo.append("_Passwords");
    nazwasciezkihaslo.append(".txt");

    nazwasciezkiwww = nazwasciezki;
    nazwasciezkiwww.append("Websites/");
    nazwasciezkiwww.append(nazwa);
    nazwasciezkiwww.append("_WWW");
    nazwasciezkiwww.append(".txt");

    remove(nazwasciezkinazwy.c_str());
    remove(nazwasciezkilogin.c_str());
    remove(nazwasciezkihaslo.c_str());
    remove(nazwasciezkiwww.c_str());
}

/**
 * Tworzenie kategoii dla nowego użytkownika.
 */
void stworzkategorie(){
    char odpkat;

    nazwaKataloguKategorie.append("../");
    nazwaKataloguKategorie.append(imie);
    nazwaKataloguKategorie.append("_Categories");

    nazwaKataloguNazwy = nazwaKataloguKategorie;
    nazwaKataloguNazwy.append("/Names");

    nazwaKataloguLoginy = nazwaKataloguKategorie;
    nazwaKataloguLoginy.append("/Logins");

    nazwaKataloguHasla = nazwaKataloguKategorie;
    nazwaKataloguHasla.append("/Passwords");

    nazwaKataloguWWW = nazwaKataloguKategorie;
    nazwaKataloguWWW.append("/Websites");

    nazwaKataloguConcat = nazwaKataloguKategorie;
    nazwaKataloguConcat.append("/Concat");

    std::filesystem::create_directories(nazwaKataloguKategorie);
    std::filesystem::create_directories(nazwaKataloguNazwy);
    std::filesystem::create_directories(nazwaKataloguLoginy);
    std::filesystem::create_directories(nazwaKataloguHasla);
    std::filesystem::create_directories(nazwaKataloguConcat);
    std::filesystem::create_directories(nazwaKataloguWWW);

    cout << "\n\n\nKazde haslo powinno miec przypisana kategorie!" << endl;
    cout << "\nProponujemy nastepujace kategorie:" << endl;
    cout << "- Rozrywka\n- Gry\n- Produktywnosc\n- Zakupy\n- Serwisy Spolecznosciowe\n- Podroze\n- Brak kategori" << endl;
    cout << "\nCzy chcesz utworzyc nastepujace kategorie?" << endl;
    cout << "Tak(t)/Nie(n)" << endl;
    cout << "\nTwoj wybor: ";
    cin >> odpkat;
    /**
     * Sprawdzenie input ze strony użytkownika jest poprawny.
     * Jeżeli nie jest, program prosi użytkownika o wprowadzenie prawidłowej wartości.
     * @param odpkat - decyzja użytkownika czy chce utworzyć predefiniowane kategorie czy nie.
     */
    while(odpkat != 't' && odpkat != 'n'){
        cin.clear();
        cin.ignore(INT_MAX,'\n'); //usuwanie \n

        cout << "Wprowadzono nieprawidlowa opcje - prosze wprowadzic: \nt - dla tak\nn - dla nie" << endl;
        cout << "\nTwoj wybor: ";
        cin >> odpkat;
    }
    /**
     * Jeżeli użytkownik chce utworzyć predefiniowane kategorie.
     * @param odpkat - decyzja użytkownika czy chce utworzyć predefiniowane kategorie czy nie.
     */
    if(odpkat == 't'){
        //NAZWY
        string rozrywkasciezkanazwy;
        string grysciezkanazwy;
        string produktywnoscsciezkanazwy;
        string zakupysciezkanazwy;
        string spolecznosciowesciezkanazwy;
        string podrozesciezkanazwy;
        string braksciezkanazwy;

        rozrywkasciezkanazwy = nazwaKataloguNazwy;
        rozrywkasciezkanazwy.append("/");
        rozrywkasciezkanazwy.append("Rozrywka.txt");

        grysciezkanazwy = nazwaKataloguNazwy;
        grysciezkanazwy.append("/");
        grysciezkanazwy.append("Gry.txt");

        produktywnoscsciezkanazwy = nazwaKataloguNazwy;
        produktywnoscsciezkanazwy.append("/");
        produktywnoscsciezkanazwy.append("Produktywnosc.txt");

        zakupysciezkanazwy = nazwaKataloguNazwy;
        zakupysciezkanazwy.append("/");
        zakupysciezkanazwy.append("Zakupy.txt");

        spolecznosciowesciezkanazwy = nazwaKataloguNazwy;
        spolecznosciowesciezkanazwy.append("/");
        spolecznosciowesciezkanazwy.append("Spolecznosciowe.txt");

        podrozesciezkanazwy = nazwaKataloguNazwy;
        podrozesciezkanazwy.append("/");
        podrozesciezkanazwy.append("Podroze.txt");

        braksciezkanazwy = nazwaKataloguNazwy;
        braksciezkanazwy.append("/");
        braksciezkanazwy.append("Brak.txt");


        ofstream rozrywkanazwa {rozrywkasciezkanazwy};
        ofstream grynazwa {grysciezkanazwy};
        ofstream produktywnoscnazwa{produktywnoscsciezkanazwy};
        ofstream zakupynazwa{zakupysciezkanazwy};
        ofstream spolecznosciowenazwa{spolecznosciowesciezkanazwy};
        ofstream podrozenazwa{podrozesciezkanazwy};
        ofstream braknazwa{braksciezkanazwy};

        //LOGINY
        string rozrywkasciezkalogins;
        string grysciezkalogins;
        string produktywnoscsciezkalogins;
        string zakupysciezkalogins;
        string spolecznosciowesciezkalogins;
        string podrozesciezkalogins;
        string braksciezkalogins;

        rozrywkasciezkalogins = nazwaKataloguLoginy;
        rozrywkasciezkalogins.append("/");
        rozrywkasciezkalogins.append("Rozrywka_Logins.txt");

        grysciezkalogins = nazwaKataloguLoginy;
        grysciezkalogins.append("/");
        grysciezkalogins.append("Gry_Logins.txt");

        produktywnoscsciezkalogins = nazwaKataloguLoginy;
        produktywnoscsciezkalogins.append("/");
        produktywnoscsciezkalogins.append("Produktywnosc_Logins.txt");

        zakupysciezkalogins = nazwaKataloguLoginy;
        zakupysciezkalogins.append("/");
        zakupysciezkalogins.append("Zakupy_Logins.txt");

        spolecznosciowesciezkalogins = nazwaKataloguLoginy;
        spolecznosciowesciezkalogins.append("/");
        spolecznosciowesciezkalogins.append("Spolecznosciowe_Logins.txt");

        podrozesciezkalogins = nazwaKataloguLoginy;
        podrozesciezkalogins.append("/");
        podrozesciezkalogins.append("Podroze_Logins.txt");

        braksciezkalogins = nazwaKataloguLoginy;
        braksciezkalogins.append("/");
        braksciezkalogins.append("Brak_Logins.txt");

        ofstream rozrywkalogin {rozrywkasciezkalogins};
        ofstream grylogin {grysciezkalogins};
        ofstream produktywnosclogin{produktywnoscsciezkalogins};
        ofstream zakupylogin{zakupysciezkalogins};
        ofstream spolecznosciowelogin{spolecznosciowesciezkalogins};
        ofstream podrozelogin{podrozesciezkalogins};
        ofstream braklogin{braksciezkalogins};

        //HASŁA
        string rozrywkasciezkapasswords;
        string grysciezkapasswords;
        string produktywnoscsciezkapasswords;
        string zakupysciezkapasswords;
        string spolecznosciowesciezkapasswords;
        string podrozesciezkapasswords;
        string braksciezkapasswords;

        rozrywkasciezkapasswords = nazwaKataloguHasla;
        rozrywkasciezkapasswords.append("/");
        rozrywkasciezkapasswords.append("Rozrywka_Passwords.txt");

        grysciezkapasswords = nazwaKataloguHasla;
        grysciezkapasswords.append("/");
        grysciezkapasswords.append("Gry_Passwords.txt");

        produktywnoscsciezkapasswords = nazwaKataloguHasla;
        produktywnoscsciezkapasswords.append("/");
        produktywnoscsciezkapasswords.append("Produktywnosc_Passwords.txt");

        zakupysciezkapasswords = nazwaKataloguHasla;
        zakupysciezkapasswords.append("/");
        zakupysciezkapasswords.append("Zakupy_Passwords.txt");

        spolecznosciowesciezkapasswords = nazwaKataloguHasla;
        spolecznosciowesciezkapasswords.append("/");
        spolecznosciowesciezkapasswords.append("Spolecznosciowe_Passwords.txt");

        podrozesciezkapasswords = nazwaKataloguHasla;
        podrozesciezkapasswords.append("/");
        podrozesciezkapasswords.append("Podroze_Passwords.txt");

        braksciezkapasswords = nazwaKataloguHasla;
        braksciezkapasswords.append("/");
        braksciezkapasswords.append("Brak_Passwords.txt");

        ofstream rozrywkahaslo {rozrywkasciezkapasswords};
        ofstream gryhaslo {grysciezkapasswords};
        ofstream produktywnoschaslo{produktywnoscsciezkapasswords};
        ofstream zakupyhaslo{zakupysciezkapasswords};
        ofstream spolecznosciowehaslo{spolecznosciowesciezkapasswords};
        ofstream podrozehaslo{podrozesciezkapasswords};
        ofstream brakhaslo{braksciezkapasswords};

        //ADRESY STRON WWW
        string rozrywkasciezkawww;
        string grysciezkawww;
        string produktywnoscsciezkawww;
        string zakupysciezkawww;
        string spolecznosciowesciezkawww;
        string podrozesciezkawww;
        string braksciezkawww;

        rozrywkasciezkawww = nazwaKataloguWWW;
        rozrywkasciezkawww.append("/");
        rozrywkasciezkawww.append("Rozrywka_WWW.txt");

        grysciezkawww = nazwaKataloguWWW;
        grysciezkawww.append("/");
        grysciezkawww.append("Gry_WWW.txt");

        produktywnoscsciezkawww = nazwaKataloguWWW;
        produktywnoscsciezkawww.append("/");
        produktywnoscsciezkawww.append("Produktywnosc_WWW.txt");

        zakupysciezkawww = nazwaKataloguWWW;
        zakupysciezkawww.append("/");
        zakupysciezkawww.append("Zakupy_WWW.txt");

        spolecznosciowesciezkawww = nazwaKataloguWWW;
        spolecznosciowesciezkawww.append("/");
        spolecznosciowesciezkawww.append("Spolecznosciowe_WWW.txt");

        podrozesciezkawww = nazwaKataloguWWW;
        podrozesciezkawww.append("/");
        podrozesciezkawww.append("Podroze_WWW.txt");

        braksciezkawww = nazwaKataloguWWW;
        braksciezkawww.append("/");
        braksciezkawww.append("Brak_WWW.txt");

        ofstream rozrywkawww{rozrywkasciezkawww};
        ofstream grywww {grysciezkawww};
        ofstream produktywnoscwww{produktywnoscsciezkawww};
        ofstream zakupywww{zakupysciezkawww};
        ofstream spolecznosciowewww{spolecznosciowesciezkawww};
        ofstream podrozewww{podrozesciezkawww};
        ofstream brakwww{braksciezkawww};

        //PLIKI KONKATENACJA
        string concatsciezkanazwy;
        string concatsciezkalogins;
        string concatsciezkapasswords;
        string concatsciezkawww;

        concatsciezkanazwy = nazwaKataloguConcat;
        concatsciezkanazwy.append("/");
        concatsciezkanazwy.append("Concat.txt");

        concatsciezkalogins = nazwaKataloguConcat;
        concatsciezkalogins.append("/");
        concatsciezkalogins.append("Concat_Logins.txt");

        concatsciezkapasswords = nazwaKataloguConcat;
        concatsciezkapasswords.append("/");
        concatsciezkapasswords.append("Concat_Passwords.txt");

        concatsciezkawww = nazwaKataloguConcat;
        concatsciezkawww.append("/");
        concatsciezkawww.append("Concat_WWW.txt");

        ofstream concatnazwy{concatsciezkanazwy};
        ofstream concatloginy{concatsciezkalogins};
        ofstream concathasla{concatsciezkapasswords};
        ofstream concatwww{concatsciezkawww};

    }
    /**
     * Jeżeli użytkownik NIE chce utworzyć predefiniowane kategorie.
     * @param odpkat - decyzja użytkownika czy chce utworzyć predefiniowane kategorie czy nie.
     */
    if(odpkat == 'n'){

        char odpn;

        cout << "\nCzy chcesz dodac wlasne kategorie?" << endl;
        cout << "Tak(t)/Nie(n)" << endl;
        cout << "\nTwoj wybor: ";
        cin >> odpn;

        /**
         * Sprawdzenie input ze strony użytkownika jest poprawny.
         * Jeżeli nie jest, program prosi użytkownika o wprowadzenie prawidłowej wartości.
         * @param odpn - decyzja użytkownika czy chce dodać własne kategorie czy nie.
         */
        while(odpn != 't' && odpn != 'n'){
            cin.clear();
            cin.ignore(INT_MAX,'\n'); //usuwanie \n

            cout << "\nWprowadzono nieprawidlowa opcje - prosze wprowadzic: \nt - dla tak\nn - dla nie" << endl;
            cout << "\nTwoj wybor: ";
            cin >> odpn;
        }
        /**
         * Jeżeli użytkownik chce dodać własne kategorie.
         * @param odpn - decyzja użytkownika czy chce dodać własne kategorie czy nie.
         */
        if(odpn == 't'){
            string braksciezkanazwy;
            string braksciezkalogin;
            string braksciezkahaslo;
            string braksciezkawww;
            char odpdodawanie;

            addCategorynewUser();
            cout << "\nCzy chcesz utworzyc kolejna kategorie?" << endl;
            cout << "Tak(t)/Nie(n)" << endl;
            cout << "\nTwoj wybor: ";
            cin >> odpdodawanie;
            /**
             * Sprawdzenie input ze strony użytkownika jest poprawny.
             * Jeżeli nie jest, program prosi użytkownika o wprowadzenie prawidłowej wartości.
             * @param odpdodawanie - decyzja użytkownika czy chce dodać kolejną własną kategorie czy nie.
             */
            while(odpdodawanie != 't' && odpdodawanie != 'n'){
                cin.clear();
                cin.ignore(INT_MAX,'\n'); //usuwanie \n

                cout << "\nWprowadzono nieprawidlowa opcje - prosze wprowadzic: \nt - dla tak\nn - dla nie" << endl;
                cout << "\nTwoj wybor: ";
                cin >> odpdodawanie;
            }

            /**
             * Jeżeli użytkownik chce utworzyć kolejną własną kategorie.
             * @param odpdodawanie - decyzja użytkownika czy chce dodać kolejną własną kategorie czy nie.
             */
            while(odpdodawanie == 't'){
                addCategorynewUser();

                cin.clear();
                cin.ignore(INT_MAX,'\n'); //usuwanie \n
                cout << "\n Czy chcesz utworzyc kolejna kategorie?" << endl;
                cout << "Tak(t)/Nie(n)" << endl;
                cout << "\nTwoj wybor: ";
                cin >> odpdodawanie;
            }

            braksciezkanazwy = nazwaKataloguNazwy;
            braksciezkanazwy.append("/");
            braksciezkanazwy.append("Brak.txt");
            ofstream braknazwa{braksciezkanazwy};

            braksciezkalogin = nazwaKataloguLoginy;
            braksciezkalogin.append("/");
            braksciezkalogin.append("Brak_Logins.txt");
            ofstream braklogin{braksciezkalogin};

            braksciezkahaslo = nazwaKataloguHasla;
            braksciezkahaslo.append("/");
            braksciezkahaslo.append("Brak_Passwords.txt");
            ofstream brakhaslo{braksciezkahaslo};

            braksciezkawww = nazwaKataloguWWW;
            braksciezkawww.append("/");
            braksciezkawww.append("Brak_WWW.txt");
            ofstream brakwww{braksciezkawww};

            string concatsciezkanazwy;
            string concatsciezkalogins;
            string concatsciezkapasswords;
            string concatsciezkawww;

            concatsciezkanazwy = nazwaKataloguConcat;
            concatsciezkanazwy.append("/");
            concatsciezkanazwy.append("Concat.txt");

            concatsciezkalogins = nazwaKataloguConcat;
            concatsciezkalogins.append("/");
            concatsciezkalogins.append("Concat_Logins.txt");

            concatsciezkapasswords = nazwaKataloguConcat;
            concatsciezkapasswords.append("/");
            concatsciezkapasswords.append("Concat_Passwords.txt");

            concatsciezkawww = nazwaKataloguConcat;
            concatsciezkawww.append("/");
            concatsciezkawww.append("Concat_WWW.txt");

            ofstream concatnazwy{concatsciezkanazwy};
            ofstream concatloginy{concatsciezkalogins};
            ofstream concathasla{concatsciezkapasswords};
            ofstream concatwww{concatsciezkawww};
        }
        /**
         * Jeżeli użytkownik NIE chce utworzyć (kolejnej) własnej kategorii.
         * @param odpdodawanie - decyzja użytkownika czy chce dodać kolejną własną kategorie czy nie.
         */
        if(odpn == 'n') {
            cout << "Nie utworzono wlasnych kategorii" << endl;

            string braksciezkanazwy;
            string braksciezkalogin;
            string braksciezkahaslo;
            string braksciezkawww;

            braksciezkanazwy = nazwaKataloguNazwy;
            braksciezkanazwy.append("/");
            braksciezkanazwy.append("Brak.txt");
            ofstream braknazwa{braksciezkanazwy};

            braksciezkalogin = nazwaKataloguLoginy;
            braksciezkalogin.append("/");
            braksciezkalogin.append("Brak_Logins.txt");
            ofstream braklogin{braksciezkalogin};

            braksciezkahaslo = nazwaKataloguHasla;
            braksciezkahaslo.append("/");
            braksciezkahaslo.append("Brak_Passwords.txt");
            ofstream brakhaslo{braksciezkahaslo};

            braksciezkawww = nazwaKataloguWWW;
            braksciezkawww.append("/");
            braksciezkawww.append("Brak_WWW.txt");
            ofstream brakwww{braksciezkawww};

            string concatsciezkanazwy;
            string concatsciezkalogins;
            string concatsciezkapasswords;
            string concatsciezkawww;

            concatsciezkanazwy = nazwaKataloguConcat;
            concatsciezkanazwy.append("/");
            concatsciezkanazwy.append("Concat.txt");

            concatsciezkalogins = nazwaKataloguConcat;
            concatsciezkalogins.append("/");
            concatsciezkalogins.append("Concat_Logins.txt");

            concatsciezkapasswords = nazwaKataloguConcat;
            concatsciezkapasswords.append("/");
            concatsciezkapasswords.append("Concat_Passwords.txt");

            concatsciezkawww = nazwaKataloguConcat;
            concatsciezkawww.append("/");
            concatsciezkawww.append("Concat_WWW.txt");

            ofstream concatnazwy{concatsciezkanazwy};
            ofstream concatloginy{concatsciezkalogins};
            ofstream concathasla{concatsciezkapasswords};
            ofstream concatwww{concatsciezkawww};
        }
    }
}

/**
 * Funkcja tworząca plik z timestampem ostantniego odszyfrowania.
 */
void createtimestamp(){
    string timestampscierzka;

    timestampscierzka.append("../");
    timestampscierzka.append(imie);
    timestampscierzka.append("_lastdeciphered.txt");

    ofstream timestamp{timestampscierzka};
}
/**
 * Wpisywanie informacji do pliku o timestampie utworzenia konta użytkownika
 */
void overwritetimestampnewuser(){
    time_t czas = time(0);
    char* timestamp = ctime(&czas);

    string timestampscierzka;

    timestampscierzka.append("../");
    timestampscierzka.append(imie);
    timestampscierzka.append("_lastdeciphered.txt");

    fstream fileOut;

    fileOut.open(timestampscierzka,std::ios::out);

    /**
     * Wpisanie timestamp'u do pliku o ścieżce timestampscierzka na temat czasu utworzenia konta.
     */
    if(fileOut.is_open()){
        fileOut << "\n########################################################\n" << endl;
        fileOut << "Timestamp utworzenia konta: " << timestamp << endl;
        fileOut << "########################################################\n" << endl;
        fileOut.close();
    }
}
/**
 * Nadpisywanie pliku z timestamp'em informacjami o ostatnim odszyfrowaniu.
 * @param imie_login - informacja o nazwie użytkownika. Potrzebna do manipulowania danymi użytkownika.
 */
void overwritetimestamp(string imie_login){
    time_t czas = time(0);
    char* timestamp = ctime(&czas);

    string timestampscierzka;

    timestampscierzka.append("../");
    timestampscierzka.append(imie_login);
    timestampscierzka.append("_lastdeciphered.txt");

    fstream fileOut;

    fileOut.open(timestampscierzka,std::ios::out);

    /**
     * Wpisanie timestamp'u do pliku o ścieżce timestampscierzka na ostatniego odszyfrowania.
     */
    if(fileOut.is_open()){
        fileOut << "\n############################################################\n" << endl;
        fileOut << "Timestamp ostatniego odszyfrowania: " << timestamp << endl;
        fileOut << "############################################################\n" << endl;
        fileOut.close();
    }
}
/**
 * Nadpisywanie pliku z timestamp'em informacjami o ostatnim odszyfrowaniu - wersja manualna.
 * @param sciezka - ścieżka do pliku z timestamp'em. Potrzebna do nadpisania danych
 */
void overwritetimestampmanual(string sciezka){
    time_t czas = time(0);
    char* timestamp = ctime(&czas);

    fstream fileOut;

    fileOut.open(sciezka,std::ios::out);

    /**
     * Wpisanie timestamp'u do pliku o ścieżce timestampscierzka na ostatniego odszyfrowania.
     */
    if(fileOut.is_open()){
        fileOut << "\n############################################################\n" << endl;
        fileOut << "Timestamp ostatniego odszyfrowania: " << timestamp << endl;
        fileOut << "############################################################\n" << endl;
        fileOut.close();
    }
}

/**
 * Funkcja służąca do odczytywania timestamp'u z pliku z Timestamp'em.
 * @param imie_login - informacja o nazwie użytkownika. Potrzebna do manipulowania danymi użytkownika.
 */
void readtimestamp(string imie_login){

    string timestampscierzka;

    timestampscierzka.append("../");
    timestampscierzka.append(imie_login);
    timestampscierzka.append("_lastdeciphered.txt");

    fstream fileIn;

    fileIn.open(timestampscierzka,std::ios::in);

    /**
     * Jeżeli plik jest otwarty - wypisywanie danych z pliku.
     */
    if(fileIn.is_open()){
        string line;
        while (getline(fileIn,line)){
            cout<<line<<endl;
        }
        fileIn.close();
    }
}

/**
 * Funkcja służąca do odczytywania timestamp'u z pliku z Timestamp'em - wersja manualna.
 * @param sciezka - ścieżka do pliku z timestamp'em. Potrzebna do odczytania danych.
 */
void readtimestampmanual(string sciezka){

    fstream fileIn;
    fileIn.open(sciezka,std::ios::in);

    /**
     * Jeżeli plik jest otwarty - wypisywanie danych z pliku.
     */
    if(fileIn.is_open()){
        string line;
        while (getline(fileIn,line)){
            cout<<line<<endl;
        }
        fileIn.close();
    }
}

/**
 * Funkcja służąca usuwaniu konta użytkownika.
 * @param imie_login - informacja o nazwie użytkownika. Potrzebna do manipulowania danymi użytkownika.
 */
void deleteaccount(string imie_login){
    string sciezka;
    string timestampsciezka;
    string mastersciezka;
    string podpowiedzsciezka;
    string katalogsciezka;

    cout << "\nUsuwanie konta! :(" << endl;

    sciezka.append("../");
    sciezka.append(imie_login);

    timestampsciezka = sciezka;
    timestampsciezka.append("_lastdeciphered.txt");

    mastersciezka = sciezka;
    mastersciezka.append("_masterpassword.txt");

    podpowiedzsciezka = sciezka;
    podpowiedzsciezka.append("_passwordhint.txt");

    katalogsciezka = sciezka;
    katalogsciezka.append("_Categories");

    remove(timestampsciezka.c_str());
    remove(mastersciezka.c_str());
    remove(podpowiedzsciezka.c_str());
    std::filesystem::remove_all(katalogsciezka.c_str());
}

/**
 * Funkcja służąca dodaniu nazwy hasła do wybranej kategorii.
 * @param imie_login - informacja o nazwie użytkownika. Potrzebna do manipulowania danymi użytkownika.
 * @param nazwakategorii - informacja o nazwie kategorii. Potrzebna do manipulowania danymi użytkownika.
 * @param nazwahasla - nazwa hasła wybrana przez użytkownika
 */
void addname(string imie_login,string nazwakategorii, string nazwahasla){
    string sciezka;

    sciezka.append("../");
    sciezka.append(imie_login);
    sciezka.append("_Categories");
    sciezka.append("/Names/");
    sciezka.append(nazwakategorii);
    sciezka.append(".txt");

    fstream fileOut;
    fileOut.open(sciezka,std::ios::app);

    /**
     * Jeżeli plik jest otwarty - dodawanie danych z pliku.
     */
    if(fileOut.is_open()){
        fileOut<<nazwahasla;
        fileOut<<"\n";
        fileOut.close();
    }
}
/**
 * Funkcja służąca dodaniu loginu do wybranej kategorii.
 * @param imie_login - informacja o nazwie użytkownika. Potrzebna do manipulowania danymi użytkownika.
 * @param nazwakategorii - informacja o nazwie kategorii. Potrzebna do manipulowania danymi użytkownika.
 * @param login - login wybrany przez użytkownika
 */
void addlogin(string imie_login, string nazwakategorii, string login){
    string sciezka;

    sciezka.append("../");
    sciezka.append(imie_login);
    sciezka.append("_Categories");
    sciezka.append("/Logins/");
    sciezka.append(nazwakategorii);
    sciezka.append("_Logins");
    sciezka.append(".txt");

    fstream fileOut;
    fileOut.open(sciezka,std::ios::app);

    /**
     * Jeżeli plik jest otwarty - dodawanie danych z pliku.
     */
    if(fileOut.is_open()){
        fileOut<<login;
        fileOut<<"\n";
        fileOut.close();
    }
}
/**
 * Funkcja służąca dodaniu hasła do wybranej kategorii.
 * @param imie_login - informacja o nazwie użytkownika. Potrzebna do manipulowania danymi użytkownika.
 * @param nazwakategorii - informacja o nazwie kategorii. Potrzebna do manipulowania danymi użytkownika.
 * @param haslo - hasło wybrane przez użytkownika
 */
void addpassword(string imie_login,string nazwakategorii, string haslo){
    string sciezka;

    sciezka.append("../");
    sciezka.append(imie_login);
    sciezka.append("_Categories");
    sciezka.append("/Passwords/");
    sciezka.append(nazwakategorii);
    sciezka.append("_Passwords");
    sciezka.append(".txt");

    fstream fileOut;
    fileOut.open(sciezka,std::ios::app);

    /**
     * Jeżeli plik jest otwarty - dodawanie danych z pliku.
     */
    if(fileOut.is_open()){
        fileOut<<haslo;
        fileOut<<"\n";
        fileOut.close();
    }
}
/**
 * Funkcja służąca dodaniu adresu www do wybranej kategorii.
 * @param imie_login - informacja o nazwie użytkownika. Potrzebna do manipulowania danymi użytkownika.
 * @param nazwakategorii - informacja o nazwie kategorii. Potrzebna do manipulowania danymi użytkownika.
 * @param www - adres www wybrany przez użytkownika
 */
void addwww(string imie_login,string nazwakategorii, string www){
    string sciezka;

    sciezka.append("../");
    sciezka.append(imie_login);
    sciezka.append("_Categories");
    sciezka.append("/Websites/");
    sciezka.append(nazwakategorii);
    sciezka.append("_WWW");
    sciezka.append(".txt");

    fstream fileOut;
    fileOut.open(sciezka,std::ios::app);

    /**
     * Jeżeli plik jest otwarty - dodawanie danych z pliku.
     */
    if(fileOut.is_open()){
        fileOut<<www;
        fileOut<<"\n";
        fileOut.close();
    }
}

/**
 * Funkcja pokazująca zawartość kategorii hasła.
 * @param imie_login - informacja o nazwie użytkownika. Potrzebna do manipulowania danymi użytkownika.
 * @param nazwakategorii - informacja o nazwie kategorii. Potrzebna do manipulowania danymi użytkownika.
 */
void showcategorycontents(string imie_login,string nazwakategorii){
    int nr = 1;
    string sciezka;
    sciezka.append("../");
    sciezka.append(imie_login);
    sciezka.append("_Categories");
    sciezka.append("/Names/");
    sciezka.append(nazwakategorii);
    sciezka.append(".txt");

    fstream file;
    file.open(sciezka.c_str());

    /**
     * Czytanie pliku linia po linii i wypisywanie go z dodanym numerem linii.
     */
    while (std::getline(file,sciezka)){
        cout << nr << ". " << sciezka << '\n';
        nr++;
    }
}

/**
 * Usuwanie nazwy hasła z wybranej kategorii.
 * @param imie_login - informacja o nazwie użytkownika. Potrzebna do manipulowania danymi użytkownika.
 * @param nazwakategorii - informacja o nazwie kategorii. Potrzebna do manipulowania danymi użytkownika.
 * @param nr - wybrany numer hasła do usunięcia
 */
void deletename(string imie_login, string nazwakategorii, unsigned int nr){
    string sciezka;

    sciezka.append("../");
    sciezka.append(imie_login);
    sciezka.append("_Categories");
    sciezka.append("/Names/");
    sciezka.append(nazwakategorii);
    sciezka.append(".txt");

    fstream file(sciezka);
    fstream output("tmp.txt",std::ios::out);

    char c;
    int nr_linii = 1;

    /**
     * Czytanie pliku i wypisywanie go do drugiego, oprócz linii która posiada wybrany numer przez użytkownika.
     */
    while (file.get(c)){

        if(c == '\n'){
            nr_linii++;
        }

        if(nr_linii!= nr){
            output << c;
        }
    }

    output.close();
    file.close();
    remove(sciezka.c_str());
    rename("tmp.txt",sciezka.c_str());
}
/**
 * Usuwanie loginu z wybranej kategorii.
 * @param imie_login - informacja o nazwie użytkownika. Potrzebna do manipulowania danymi użytkownika.
 * @param nazwakategorii - informacja o nazwie kategorii. Potrzebna do manipulowania danymi użytkownika.
 * @param nr - wybrany numer hasła do usunięcia
 */
void deletelogin(string imie_login, string nazwakategorii, unsigned int nr){
    string sciezka;

    sciezka.append("../");
    sciezka.append(imie_login);
    sciezka.append("_Categories");
    sciezka.append("/Logins/");
    sciezka.append(nazwakategorii);
    sciezka.append("_Logins");
    sciezka.append(".txt");

    fstream file(sciezka);
    fstream output("tmp.txt",std::ios::out);

    char c;
    int nr_linii = 1;

    /**
     * Czytanie pliku i wypisywanie go do drugiego, oprócz linii która posiada wybrany numer przez użytkownika.
     */
    while (file.get(c)){
        if(c == '\n'){
            nr_linii++;
        }
        if(nr_linii!= nr){
            output << c;
        }
    }
    output.close();
    file.close();
    remove(sciezka.c_str());
    rename("tmp.txt",sciezka.c_str());
}
/**
 * Usuwanie hasła z wybranej kategorii.
 * @param imie_login - informacja o nazwie użytkownika. Potrzebna do manipulowania danymi użytkownika.
 * @param nazwakategorii - informacja o nazwie kategorii. Potrzebna do manipulowania danymi użytkownika.
 * @param nr - wybrany numer hasła do usunięcia
 */
void deletepassword(string imie_login, string nazwakategorii, unsigned int nr){
    string sciezka;

    sciezka.append("../");
    sciezka.append(imie_login);
    sciezka.append("_Categories");
    sciezka.append("/Passwords/");
    sciezka.append(nazwakategorii);
    sciezka.append("_Passwords");
    sciezka.append(".txt");

    fstream file(sciezka);
    fstream output("tmp.txt",std::ios::out);

    char c;
    int nr_linii = 1;

    /**
     * Czytanie pliku i wypisywanie go do drugiego, oprócz linii która posiada wybrany numer przez użytkownika.
     */
    while (file.get(c)){
        if(c == '\n'){
            nr_linii++;
        }
        if(nr_linii!= nr){
            output << c;
        }
    }
    output.close();
    file.close();
    remove(sciezka.c_str());
    rename("tmp.txt",sciezka.c_str());
}
/**
 * Usuwanie adresu www z wybranej kategorii.
 * @param imie_login - informacja o nazwie użytkownika. Potrzebna do manipulowania danymi użytkownika.
 * @param nazwakategorii - informacja o nazwie kategorii. Potrzebna do manipulowania danymi użytkownika.
 * @param nr - wybrany numer adresu www do usunięcia
 */
void deletewww(string imie_login, string nazwakategorii, unsigned int nr){
    string sciezka;

    sciezka.append("../");
    sciezka.append(imie_login);
    sciezka.append("_Categories");
    sciezka.append("/Websites/");
    sciezka.append(nazwakategorii);
    sciezka.append("_WWW");
    sciezka.append(".txt");

    fstream file(sciezka);
    fstream output("tmp.txt",std::ios::out);

    char c;
    int nr_linii = 1;

    /**
     * Czytanie pliku i wypisywanie go do drugiego, oprócz linii która posiada wybrany numer przez użytkownika.
     */
    while (file.get(c)){
        if(c == '\n'){
            nr_linii++;
        }
        if(nr_linii!= nr){
            output << c;
        }
    }
    output.close();
    file.close();
    remove(sciezka.c_str());
    rename("tmp.txt",sciezka.c_str());
}

/**
 * Funkcja powodująca przejście do wybranej linijki pliku.
 * @param file - nazwa strumienia
 * @param num -numer linii
 * @return zwróć plik
 */
std::fstream& GotoLine(std::fstream& file, unsigned int num){
    //przesunięcie wskaźnika na początek pliku.
    file.seekg(std::ios::beg);

    //ignorowanie pierwszych n-1 linii pliku
    for(int i=0; i < num - 1; ++i){
        file.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }
    return file;
}

/**
 * Funkcja pozwalająca dostanie wybranej linijki z pliku - który ma być usunięty.
 * @param imie_login - informacja o nazwie użytkownika. Potrzebna do manipulowania danymi użytkownika.
 * @param nazwakategorii - informacja o nazwie kategorii. Potrzebna do manipulowania danymi użytkownika.
 * @param nr - numer linii wskazany przez użytkownika
 */
void getline(string imie_login, string nazwakategorii, unsigned int nr){
    string sciezka;

    sciezka.append("../");
    sciezka.append(imie_login);
    sciezka.append("_Categories");
    sciezka.append("/Passwords/");
    sciezka.append(nazwakategorii);
    sciezka.append("_Passwords");
    sciezka.append(".txt");

    fstream file(sciezka);

    GotoLine(file,nr);
    file >> liniadousuniecia;
    cin.get();
}

/**
 * Wypisanie hasła które będzie zmienione.
 */
void printpassword(){
    cout<<"\nZmieniane haslo:" << liniadousuniecia << endl;
}


/**
 * Zmiana hasła w podanej kategorii.
 * @param imie_login - informacja o nazwie użytkownika. Potrzebna do manipulowania danymi użytkownika.
 * @param nazwakategorii - informacja o nazwie kategorii. Potrzebna do manipulowania danymi użytkownika.
 * @param nowehaslo - nowe hasło podane przez użytkownika na które ma zostać zmienione stare
 */
void changepassword(string imie_login,string nazwakategorii, string nowehaslo){
    string sciezka;
    string starehaslo = liniadousuniecia;

    sciezka.append("../");
    sciezka.append(imie_login);
    sciezka.append("_Categories");
    sciezka.append("/Passwords/");
    sciezka.append(nazwakategorii);
    sciezka.append("_Passwords");
    sciezka.append(".txt");

    cout << "Stare hasło: " << starehaslo << endl;
    cout << "Nowe hasło: " << nowehaslo;

    string strtmp;
    bool found = false;
    fstream file(sciezka);
    fstream output("tmp.txt",std::ios::out);

    /**
     * Znalezienie starego hasła w pliku i zamiana go na nowe/
     */
    while (file >> strtmp){
        if(strtmp == starehaslo){
            strtmp = nowehaslo;
            found = true;
        }
        strtmp += '\n';
        output << strtmp;
        if(found){
            break;
        }
    }

    output.close();
    file.close();
    remove(sciezka.c_str());
    rename("tmp.txt",sciezka.c_str());

}

/**
 * Konkatenacja wszystkich plików z nazwami haseł.
 * @param imie_login - informacja o nazwie użytkownika. Potrzebna do manipulowania danymi użytkownika.
 */
void concatnamefiles(string imie_login){
    string nazwasciezki;
    string nazwaconcat;

    nazwaconcat.append("../");
    nazwaconcat.append(imie_login);
    nazwaconcat.append("_Categories/Concat/Concat.txt");
    fstream concat(nazwaconcat,std::ios::out);

    nazwasciezki.append("../");
    nazwasciezki.append(imie_login);
    nazwasciezki.append("_Categories/Names");

    /**
     * Dla każdego pliku w danym katalogu otwarcie strumienia i wypisanie go linia po linii do pliku zbiorczego.
     */
    for (const auto & entry : std::filesystem::directory_iterator(nazwasciezki)){
        fstream element(entry.path(),std::ios::in);
        if(element.is_open()){
            string line;
            while (getline(element,line)){
                concat << line << endl;
            }
            element.close();
        }
    }
    concat.close();
}
/**
 * Konkatenacja wszystkich plików z loginami.
 * @param imie_login - informacja o nazwie użytkownika. Potrzebna do manipulowania danymi użytkownika.
 */
void concatloginfiles(string imie_login){
    string nazwasciezki;
    string nazwaconcat;

    nazwaconcat.append("../");
    nazwaconcat.append(imie_login);
    nazwaconcat.append("_Categories/Concat/Concat_Logins.txt");
    fstream concat(nazwaconcat,std::ios::out);

    nazwasciezki.append("../");
    nazwasciezki.append(imie_login);
    nazwasciezki.append("_Categories/Logins");

    /**
     * Dla każdego pliku w danym katalogu otwarcie strumienia i wypisanie go linia po linii do pliku zbiorczego.
     */
    for (const auto & entry : std::filesystem::directory_iterator(nazwasciezki)){
        fstream element(entry.path(),std::ios::in);
        if(element.is_open()){
            string line;
            while (getline(element,line)){
                concat << line << endl;
            }
            element.close();
        }
    }
    concat.close();
}
/**
 * Konkatenacja wszystkich plików z hasłami.
 * @param imie_login - informacja o nazwie użytkownika. Potrzebna do manipulowania danymi użytkownika.
 */
void concatpasswordsfiles(string imie_login){
    string nazwasciezki;
    string nazwaconcat;

    nazwaconcat.append("../");
    nazwaconcat.append(imie_login);
    nazwaconcat.append("_Categories/Concat/Concat_Passwords.txt");
    fstream concat(nazwaconcat,std::ios::out);

    nazwasciezki.append("../");
    nazwasciezki.append(imie_login);
    nazwasciezki.append("_Categories/Passwords");

    /**
     * Dla każdego pliku w danym katalogu otwarcie strumienia i wypisanie go linia po linii do pliku zbiorczego.
     */
    for (const auto & entry : std::filesystem::directory_iterator(nazwasciezki)){
        fstream element(entry.path(),std::ios::in);
        if(element.is_open()){
            string line;
            while (getline(element,line)){
                concat << line << endl;
            }
            element.close();
        }
    }
    concat.close();
}
/**
 * Konkatenacja wszystkich plików z adresami www.
 * @param imie_login - informacja o nazwie użytkownika. Potrzebna do manipulowania danymi użytkownika.
 */
void concatwwwfiles(string imie_login){
    string nazwasciezki;
    string nazwaconcat;

    nazwaconcat.append("../");
    nazwaconcat.append(imie_login);
    nazwaconcat.append("_Categories/Concat/Concat_WWW.txt");
    fstream concat(nazwaconcat,std::ios::out);

    nazwasciezki.append("../");
    nazwasciezki.append(imie_login);
    nazwasciezki.append("_Categories/Websites");

    /**
     * Dla każdego pliku w danym katalogu otwarcie strumienia i wypisanie go linia po linii do pliku zbiorczego.
     */
    for (const auto & entry : std::filesystem::directory_iterator(nazwasciezki)){
        fstream element(entry.path(),std::ios::in);
        if(element.is_open()){
            string line;
            while (getline(element,line)){
                concat << line << endl;
            }
            element.close();
        }
    }
    concat.close();
}

/**
 * Funkcja zbiorcza wykonująca konkatenacje dla nazw haseł, loginów, haseł i witryn www
 * @param imie_login - informacja o nazwie użytkownika. Potrzebna do manipulowania danymi użytkownika.
 */
void concatall(string imie_login){
    concatnamefiles(imie_login);
    concatloginfiles(imie_login);
    concatpasswordsfiles(imie_login);
    concatwwwfiles(imie_login);
}


/**
 * Sortowanie nazw haseł alfabetycznie oraz według wielkości znaków.
 * @param imie_login - informacja o nazwie użytkownika. Potrzebna do manipulowania danymi użytkownika.
 */
void sortnamesalphabet(string imie_login){
    std::vector<string> names;
    string nazwaconcat;

    nazwaconcat.append("../");
    nazwaconcat.append(imie_login);
    nazwaconcat.append("_Categories/Concat/Concat.txt");
    fstream concat(nazwaconcat,std::ios::in);

    string word;

    /**
     * Czytanie pliku linia po linii i dodawanie linii do wektora
     */
    while (getline(concat,word)){
        names.push_back(word);
    }
    sort(names.begin(),names.end());


    /**
     * Wypisywanie zawartości wektora
     */
    for(size_t i = 0 ; i<names.size(); i++){
        cout << names[i] << '\n';
    }
}
/**
 * Sortowanie loginów alfabetycznie oraz według wielkości znaków.
 * @param imie_login - informacja o nazwie użytkownika. Potrzebna do manipulowania danymi użytkownika.
 */
void sortloginsalphabet(string imie_login){
    std::vector<string> names;
    string nazwaconcat;

    nazwaconcat.append("../");
    nazwaconcat.append(imie_login);
    nazwaconcat.append("_Categories/Concat/Concat_Logins.txt");
    fstream concat(nazwaconcat,std::ios::in);

    string word;

    /**
     * Czytanie pliku linia po linii i dodawanie linii do wektora
     */
    while (getline(concat,word)){
        names.push_back(word);
    }
    sort(names.begin(),names.end());

    /**
     * Wypisywanie zawartości wektora
     */
    for(size_t i = 0 ; i<names.size(); i++){
        cout << names[i] << '\n';
    }
}
/**
 * Sortowanie haseł alfabetycznie oraz według wielkości znaków.
 * @param imie_login - informacja o nazwie użytkownika. Potrzebna do manipulowania danymi użytkownika.
 */
void sortpasswordsalphabet(string imie_login){
    std::vector<string> names;
    string nazwaconcat;

    nazwaconcat.append("../");
    nazwaconcat.append(imie_login);
    nazwaconcat.append("_Categories/Concat/Concat_Passwords.txt");
    fstream concat(nazwaconcat,std::ios::in);

    string word;
    /**
     * Czytanie pliku linia po linii i dodawanie linii do wektora
     */
    while (getline(concat,word)){
        names.push_back(word);
    }
    sort(names.begin(),names.end());

    /**
     * Wypisywanie zawartości wektora
     */
    for(size_t i = 0 ; i<names.size(); i++){
        cout << names[i] << '\n';
    }
}
/**
 * Sortowanie adresów stron www alfabetycznie oraz według wielkości znaków.
 * @param imie_login - informacja o nazwie użytkownika. Potrzebna do manipulowania danymi użytkownika.
 */
void sortwwwalphabet(string imie_login){
    std::vector<string> names;
    string nazwaconcat;

    nazwaconcat.append("../");
    nazwaconcat.append(imie_login);
    nazwaconcat.append("_Categories/Concat/Concat_WWW.txt");
    fstream concat(nazwaconcat,std::ios::in);

    string word;
    while (getline(concat,word)){
        names.push_back(word);
    }
    sort(names.begin(),names.end());

    for(size_t i = 0 ; i<names.size(); i++){
        cout << names[i] << '\n';
    }
}

#endif //PROJEKT_SEMESTRALNY_CPP_HASLO_H
