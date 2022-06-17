//
// Created by tsera on 16.06.2022.
//

#ifndef PROJEKT_SEMESTRALNY_CPP_HASLO_MANUAL_H
#define PROJEKT_SEMESTRALNY_CPP_HASLO_MANUAL_H
#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <cstdint>
#include <bits/stdc++.h>

using std::string; using std::cout; using std::cin; using std::endl; using std::ofstream; using std::fstream;

string liniadousunieciamanual;

/**
 * Wyświetlanie wszystkich kategorii haseł.
 * @param sciezka_zewnetrzna_kategorie - adres ścieżki zewnętrznej prowadzącej do kategorii. Potrzebna do manipulowania danymi użytkownika.
 */
void showCategory_Manual(string sciezka_zewnetrzna_kategorie){
    string nazwasciezki = sciezka_zewnetrzna_kategorie;
    nazwasciezki.append("/Names");
    /**
     * Wypisywanie wszystkich plików w danym katalogu.
     */
    for (const auto & entry : std::filesystem::directory_iterator(nazwasciezki)){
        cout << entry.path() << endl;
    }
}

/**
 * Tworzenie nowej kategorii dla użytkownika.
 * @param sciezka_zewnetrzna_kategorie - adres ścieżki zewnętrznej prowadzącej do kategorii. Potrzebna do manipulowania danymi użytkownika.
 */
void addCategory_Manual(string sciezka_zewnetrzna_kategorie){
    string nazwasciezki;
    string nazwasciezkinazwy;
    string nazwasciezkilogin;
    string nazwasciezkihaslo;
    string nazwasciezkiwww;
    string nazwakategorii;

    nazwasciezki = sciezka_zewnetrzna_kategorie;

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
 * Funkcja służąca usuwaniu kategorii z bazy kategorii.
 * @param sciezka_zewnetrzna_kategorie - adres ścieżki zewnętrznej prowadzącej do kategorii. Potrzebna do manipulowania danymi użytkownika.
 * @param nazwa - nazwa kategorii wybranej przez użytkownika
 */
void removeCategory_Manual(string sciezka_zewnetrzna_kategorie,string nazwa){
    string nazwasciezki;
    string nazwasciezkinazwy;
    string nazwasciezkilogin;
    string nazwasciezkihaslo;
    string nazwasciezkiwww;

    nazwasciezki = sciezka_zewnetrzna_kategorie;

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
 * Funkcja służąca usuwaniu konta użytkownika.
 * @param sciezka_zewnetrzna_hint - adres ścieżki zewnętrznej prowadzącej do podpowiedzi do głównego hasła. Potrzebna do manipulowania danymi użytkownika.
 * @param sciezka_zewnetrzna_master - adres ścieżki zewnętrznej prowadzącej do głównego hasła. Potrzebna do manipulowania danymi użytkownika.
 * @param sciezka_zewnetrzna_last - adres ścieżki zewnętrznej prowadzącej do timestamp'u. Potrzebna do manipulowania danymi użytkownika.
 * @param sciezka_zewnetrzna_kategorie - adres ścieżki zewnętrznej prowadzącej do kategorii. Potrzebna do manipulowania danymi użytkownika.
 */
void deleteaccount_Manual(string sciezka_zewnetrzna_hint,
                          string sciezka_zewnetrzna_master,
                          string sciezka_zewnetrzna_last,
                          string sciezka_zewnetrzna_kategorie){

    cout << "\nUsuwanie konta! :(" << endl;

    remove(sciezka_zewnetrzna_last.c_str());
    remove(sciezka_zewnetrzna_master.c_str());
    remove(sciezka_zewnetrzna_hint.c_str());
    std::filesystem::remove_all(sciezka_zewnetrzna_kategorie.c_str());
}

/**
 * Funkcja służąca dodaniu nazwy hasła do wybranej kategorii.
 * @param sciezka_zewnetrzna_kategorie - adres ścieżki zewnętrznej prowadzącej do kategorii. Potrzebna do manipulowania danymi użytkownika.
 * @param nazwakategorii - informacja o nazwie kategorii. Potrzebna do manipulowania danymi użytkownika.
 * @param nazwahasla - nazwa hasła wybrana przez użytkownika
 */
void addname_Manual(string sciezka_zewnetrzna_kategorie,string nazwakategorii, string nazwahasla){
    string sciezka;

    sciezka = sciezka_zewnetrzna_kategorie;

    sciezka.append("/Names/");
    sciezka.append(nazwakategorii);
    sciezka.append(".txt");
    /**
     * Jeżeli plik nie istnieje!
     */
    if(!std::filesystem::exists(sciezka)){
        std::cerr << "Podana kategoria nie istnieje!" << endl;
        exit(1);
    }
    else{
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
}
/**
 * Funkcja służąca dodaniu loginu do wybranej kategorii.
 * @param sciezka_zewnetrzna_kategorie - adres ścieżki zewnętrznej prowadzącej do kategorii. Potrzebna do manipulowania danymi użytkownika.
 * @param nazwakategorii - informacja o nazwie kategorii. Potrzebna do manipulowania danymi użytkownika.
 * @param login - login wybrany przez użytkownika
 */
void addlogin_Manual(string sciezka_zewnetrzna_kategorie, string nazwakategorii, string login){
    string sciezka;

    sciezka = sciezka_zewnetrzna_kategorie;

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
 * @param sciezka_zewnetrzna_kategorie - adres ścieżki zewnętrznej prowadzącej do kategorii. Potrzebna do manipulowania danymi użytkownika.
 * @param nazwakategorii - informacja o nazwie kategorii. Potrzebna do manipulowania danymi użytkownika.
 * @param haslo - hasło wybrane przez użytkownika
 */
void addpassword_Manual(string sciezka_zewnetrzna_kategorie,string nazwakategorii, string haslo){
    string sciezka;

    sciezka = sciezka_zewnetrzna_kategorie;

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
 * @param sciezka_zewnetrzna_kategorie - adres ścieżki zewnętrznej prowadzącej do kategorii. Potrzebna do manipulowania danymi użytkownika.
 * @param nazwakategorii - informacja o nazwie kategorii. Potrzebna do manipulowania danymi użytkownika.
 * @param www - adres www wybrany przez użytkownika
 */
void addwww_Manual(string sciezka_zewnetrzna_kategorie,string nazwakategorii, string www){
    string sciezka;

    sciezka = sciezka_zewnetrzna_kategorie;

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
 * @param sciezka_zewnetrzna_kategorie - adres ścieżki zewnętrznej prowadzącej do kategorii. Potrzebna do manipulowania danymi użytkownika.
 * @param nazwakategorii - informacja o nazwie kategorii. Potrzebna do manipulowania danymi użytkownika.
 */
void showcategorycontents_Manual(string sciezka_zewnetrzna_kategorie,string nazwakategorii){
    int nr = 1;
    string sciezka;
    sciezka = sciezka_zewnetrzna_kategorie;

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
 * @param sciezka_zewnetrzna_kategorie - adres ścieżki zewnętrznej prowadzącej do kategorii. Potrzebna do manipulowania danymi użytkownika.
 * @param nazwakategorii - informacja o nazwie kategorii. Potrzebna do manipulowania danymi użytkownika.
 * @param nr - wybrany numer hasła do usunięcia
 */
void deletename_Manual(string sciezka_zewnetrzna_kategorie, string nazwakategorii, unsigned int nr){
    string sciezka;

    sciezka = sciezka_zewnetrzna_kategorie;

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
 * @param sciezka_zewnetrzna_kategorie - adres ścieżki zewnętrznej prowadzącej do kategorii. Potrzebna do manipulowania danymi użytkownika.
 * @param nazwakategorii - informacja o nazwie kategorii. Potrzebna do manipulowania danymi użytkownika.
 * @param nr - wybrany numer hasła do usunięcia
 */
void deletelogin_Manual(string sciezka_zewnetrzna_kategorie, string nazwakategorii, unsigned int nr){
    string sciezka;

    sciezka = sciezka_zewnetrzna_kategorie;

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
 * @param sciezka_zewnetrzna_kategorie - adres ścieżki zewnętrznej prowadzącej do kategorii. Potrzebna do manipulowania danymi użytkownika.
 * @param nazwakategorii - informacja o nazwie kategorii. Potrzebna do manipulowania danymi użytkownika.
 * @param nr - wybrany numer hasła do usunięcia
 */
void deletepassword_Manual(string sciezka_zewnetrzna_kategorie, string nazwakategorii, unsigned int nr){
    string sciezka;

    sciezka = sciezka_zewnetrzna_kategorie;

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
 * @param sciezka_zewnetrzna_kategorie - adres ścieżki zewnętrznej prowadzącej do kategorii. Potrzebna do manipulowania danymi użytkownika.
 * @param nazwakategorii - informacja o nazwie kategorii. Potrzebna do manipulowania danymi użytkownika.
 * @param nr - wybrany numer adresu www do usunięcia
 */
void deletewww_Manual(string sciezka_zewnetrzna_kategorie, string nazwakategorii, unsigned int nr){
    string sciezka;

    sciezka = sciezka_zewnetrzna_kategorie;

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
std::fstream& GotoLineManual(std::fstream& file, unsigned int num){
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
 * @param sciezka_zewnetrzna_kategorie - adres ścieżki zewnętrznej prowadzącej do kategorii. Potrzebna do manipulowania danymi użytkownika.
 * @param nazwakategorii - informacja o nazwie kategorii. Potrzebna do manipulowania danymi użytkownika.
 * @param nr - numer linii wskazany przez użytkownika
 */
void getline_Manual(string sciezka_zewnetrzna_kategorie, string nazwakategorii, unsigned int nr){
    string sciezka;

    sciezka = sciezka_zewnetrzna_kategorie;

    sciezka.append("/Passwords/");
    sciezka.append(nazwakategorii);
    sciezka.append("_Passwords");
    sciezka.append(".txt");

    fstream file(sciezka);

    GotoLineManual(file,nr);
    file >> liniadousunieciamanual;
    cin.get();
}

/**
 * Wypisanie hasła które będzie zmienione.
 */
void printpassword_Manual(){
    cout<<"\nZmieniane haslo:" << liniadousunieciamanual << endl;
}


/**
 * Zmiana hasła w podanej kategorii.
 * @param sciezka_zewnetrzna_kategorie - adres ścieżki zewnętrznej prowadzącej do kategorii. Potrzebna do manipulowania danymi użytkownika.
 * @param nazwakategorii - informacja o nazwie kategorii. Potrzebna do manipulowania danymi użytkownika.
 * @param nowehaslo - nowe hasło podane przez użytkownika na które ma zostać zmienione stare
 */
void changepassword_Manual(string sciezka_zewnetrzna_kategorie,string nazwakategorii, string nowehaslo){
    string sciezka;
    string starehaslo = liniadousunieciamanual;

    sciezka = sciezka_zewnetrzna_kategorie;

    sciezka.append("/Passwords/");
    sciezka.append(nazwakategorii);
    sciezka.append("_Passwords");
    sciezka.append(".txt");

    cout << "Stare haslo: " << starehaslo << endl;
    cout << "Nowe haslo: " << nowehaslo;

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
 * @param sciezka_zewnetrzna_kategorie - adres ścieżki zewnętrznej prowadzącej do kategorii. Potrzebna do manipulowania danymi użytkownika.
 */
void concatnamefiles_Manual(string sciezka_zewnetrzna_kategorie){
    string nazwasciezki = sciezka_zewnetrzna_kategorie;
    string nazwaconcat =sciezka_zewnetrzna_kategorie;

    nazwaconcat.append("/Concat/Concat.txt");
    fstream concat(nazwaconcat,std::ios::out);

    nazwasciezki.append("/Names");

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
 * @param sciezka_zewnetrzna_kategorie - adres ścieżki zewnętrznej prowadzącej do kategorii. Potrzebna do manipulowania danymi użytkownika.
 */
void concatloginfiles_Manual(string sciezka_zewnetrzna_kategorie){
    string nazwasciezki = sciezka_zewnetrzna_kategorie;
    string nazwaconcat =sciezka_zewnetrzna_kategorie;

    nazwaconcat.append("/Concat/Concat_Logins.txt");
    fstream concat(nazwaconcat,std::ios::out);

    nazwasciezki.append("/Logins");

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
 * @param sciezka_zewnetrzna_kategorie - adres ścieżki zewnętrznej prowadzącej do kategorii. Potrzebna do manipulowania danymi użytkownika.
 */
void concatpasswordsfiles_Manual(string sciezka_zewnetrzna_kategorie){
    string nazwasciezki = sciezka_zewnetrzna_kategorie;
    string nazwaconcat =sciezka_zewnetrzna_kategorie;

    nazwaconcat.append("/Concat/Concat_Passwords.txt");
    fstream concat(nazwaconcat,std::ios::out);

    nazwasciezki.append("/Passwords");

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
 * @param sciezka_zewnetrzna_kategorie - adres ścieżki zewnętrznej prowadzącej do kategorii. Potrzebna do manipulowania danymi użytkownika.
 */
void concatwwwfiles_Manual(string sciezka_zewnetrzna_kategorie){
    string nazwasciezki = sciezka_zewnetrzna_kategorie;
    string nazwaconcat =sciezka_zewnetrzna_kategorie;

    nazwaconcat.append("/Concat/Concat_WWW.txt");
    fstream concat(nazwaconcat,std::ios::out);

    nazwasciezki.append("/Websites");

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
 * @param sciezka_zewnetrzna_kategorie - adres ścieżki zewnętrznej prowadzącej do kategorii. Potrzebna do manipulowania danymi użytkownika.
 */
void concatall_Manual(string sciezka_zewnetrzna_kategorie){
    concatnamefiles_Manual(sciezka_zewnetrzna_kategorie);
    concatloginfiles_Manual(sciezka_zewnetrzna_kategorie);
    concatpasswordsfiles_Manual(sciezka_zewnetrzna_kategorie);
    concatwwwfiles_Manual(sciezka_zewnetrzna_kategorie);
}


/**
 * Sortowanie nazw haseł alfabetycznie oraz według wielkości znaków.
 * @param sciezka_zewnetrzna_kategorie - adres ścieżki zewnętrznej prowadzącej do kategorii. Potrzebna do manipulowania danymi użytkownika.
 */
void sortnamesalphabet_Manual(string sciezka_zewnetrzna_kategorie){
    std::vector<string> names;
    string nazwaconcat;

    nazwaconcat = sciezka_zewnetrzna_kategorie;

    nazwaconcat.append("/Concat/Concat.txt");
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
 * @param sciezka_zewnetrzna_kategorie - adres ścieżki zewnętrznej prowadzącej do kategorii. Potrzebna do manipulowania danymi użytkownika.
 */
void sortloginsalphabet_Manual(string sciezka_zewnetrzna_kategorie){
    std::vector<string> names;
    string nazwaconcat;

    nazwaconcat = sciezka_zewnetrzna_kategorie;

    nazwaconcat.append("/Concat/Concat_Logins.txt");
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
 * @param sciezka_zewnetrzna_kategorie - adres ścieżki zewnętrznej prowadzącej do kategorii. Potrzebna do manipulowania danymi użytkownika.
 */
void sortpasswordsalphabet_Manual(string sciezka_zewnetrzna_kategorie){
    std::vector<string> names;
    string nazwaconcat;

    nazwaconcat = sciezka_zewnetrzna_kategorie;

    nazwaconcat.append("/Concat/Concat_Passwords.txt");
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
 * @param sciezka_zewnetrzna_kategorie - adres ścieżki zewnętrznej prowadzącej do kategorii. Potrzebna do manipulowania danymi użytkownika.
 */
void sortwwwalphabet_Manual(string sciezka_zewnetrzna_kategorie){
    std::vector<string> names;
    string nazwaconcat;

    nazwaconcat = sciezka_zewnetrzna_kategorie;

    nazwaconcat.append("/Concat/Concat_WWW.txt");
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

#endif //PROJEKT_SEMESTRALNY_CPP_HASLO_MANUAL_H
