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
        char pod;

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
            cout << "\nTwoj wybor: ";
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
                std::cerr << "\nWpisane haslo jest nie poprawne - moga wystapic problemy z deszyfrowaniem hasel!" << endl;
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
        cout << "\nTwoj wybor:";
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

void showCategory(string imie_login){
    string nazwasciezki;
    nazwasciezki.append("../");
    nazwasciezki.append(imie_login);
    nazwasciezki.append("_Categories/Names");

    for (const auto & entry : std::filesystem::directory_iterator(nazwasciezki)){
        cout << entry.path() << endl;
    }
}

void addCategory(string imie_login){
    string nazwasciezki;
    string nazwasciezkinazwy;
    string nazwasciezkilogin;
    string nazwasciezkihaslo;
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


    ofstream nazwy(nazwasciezkinazwy);
    ofstream login(nazwasciezkilogin);
    ofstream haslo(nazwasciezkihaslo);

    cout << "\nUtworzono kategorie: " << nazwakategorii << endl;
}

void addCategorynewUser(){
    string nazwasciezki;
    string nazwasciezkinazwy;
    string nazwasciezkilogin;
    string nazwasciezkihaslo;
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

    ofstream nazwy(nazwasciezkinazwy);
    ofstream login(nazwasciezkilogin);
    ofstream haslo(nazwasciezkihaslo);

    cout << "\nUtworzono kategorie: " << nazwakategorii << endl;
}

void removeCategory(string imie_login,string nazwa){
    string nazwasciezki;
    string nazwasciezkinazwy;
    string nazwasciezkilogin;
    string nazwasciezkihaslo;

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

    remove(nazwasciezkinazwy.c_str());
    remove(nazwasciezkilogin.c_str());
    remove(nazwasciezkihaslo.c_str());
}

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

    std::filesystem::create_directories(nazwaKataloguKategorie);
    std::filesystem::create_directories(nazwaKataloguNazwy);
    std::filesystem::create_directories(nazwaKataloguLoginy);
    std::filesystem::create_directories(nazwaKataloguHasla);

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
        cout << "\nTwoj wybor: ";
        cin >> odpkat;
    }

    if(odpkat == 't'){
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

        ///
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

        ///
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
    }

    if(odpkat == 'n'){

        char odpn;

        cout << "\nCzy chcesz dodac wlasne kategorie?" << endl;
        cout << "Tak(t)/Nie(n)" << endl;
        cout << "\nTwoj wybor: ";
        cin >> odpn;

        while(odpn != 't' && odpn != 'n'){
            cin.clear();
            cin.ignore(INT_MAX,'\n'); //usuwanie \n

            cout << "\nWprowadzono nieprawidlowa opcje - prosze wprowadzic: \nt - dla tak\nn - dla nie" << endl;
            cout << "\nTwoj wybor: ";
            cin >> odpn;
        }

        if(odpn == 't'){
            string braksciezkanazwy;
            string braksciezkalogin;
            string braksciezkahaslo;
            char odpdodawanie;

            addCategorynewUser();
            cout << "\nCzy chcesz utworzyc kolejna kategorie?" << endl;
            cout << "Tak(t)/Nie(n)" << endl;
            cout << "\nTwoj wybor: ";
            cin >> odpdodawanie;

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
        }

        if(odpn == 'n') {
            cout << "Nie utworzono wlasnych kategorii" << endl;

            string braksciezkanazwy;
            string braksciezkalogin;
            string braksciezkahaslo;

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
        }
    }
}

void createtimestamp(){
    string timestampscierzka;

    timestampscierzka.append("../");
    timestampscierzka.append(imie);
    timestampscierzka.append("_lastdeciphered.txt");

    ofstream timestamp{timestampscierzka};
}

void overwritetimestampnewuser(){
    time_t czas = time(0);
    char* timestamp = ctime(&czas);

    string timestampscierzka;

    timestampscierzka.append("../");
    timestampscierzka.append(imie);
    timestampscierzka.append("_lastdeciphered.txt");

    fstream fileOut;

    fileOut.open(timestampscierzka,std::ios::out);

    if(fileOut.is_open()){
        fileOut << "\n########################################################\n" << endl;
        fileOut << "Timestamp pierwszego logowania: " << timestamp << endl;
        fileOut << "########################################################\n" << endl;
        fileOut.close();
    }
}

void overwritetimestamp(string imie_login){
    time_t czas = time(0);
    char* timestamp = ctime(&czas);

    string timestampscierzka;

    timestampscierzka.append("../");
    timestampscierzka.append(imie_login);
    timestampscierzka.append("_lastdeciphered.txt");

    fstream fileOut;

    fileOut.open(timestampscierzka,std::ios::out);

    if(fileOut.is_open()){
        fileOut << "\n############################################################\n" << endl;
        fileOut << "Timestamp ostatniego odszyfrowania: " << timestamp << endl;
        fileOut << "############################################################\n" << endl;
        fileOut.close();
    }
}

void readtimestamp(string imie_login){

    string timestampscierzka;

    timestampscierzka.append("../");
    timestampscierzka.append(imie_login);
    timestampscierzka.append("_lastdeciphered.txt");

    fstream fileIn;

    fileIn.open(timestampscierzka,std::ios::in);

    if(fileIn.is_open()){
        string line;
        while (getline(fileIn,line)){
            cout<<line<<endl;
        }
        fileIn.close();
    }
}

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
    if(fileOut.is_open()){
        fileOut<<nazwahasla;
        fileOut<<"\n";
        fileOut.close();
    }
}

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
    if(fileOut.is_open()){
        fileOut<<login;
        fileOut<<"\n";
        fileOut.close();
    }
}

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
    if(fileOut.is_open()){
        fileOut<<haslo;
        fileOut<<"\n";
        fileOut.close();
    }
}

#endif //PROJEKT_SEMESTRALNY_CPP_HASLO_H
