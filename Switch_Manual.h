//
// Created by tsera on 16.06.2022.
//

#ifndef PROJEKT_SEMESTRALNY_CPP_SWITCH_MANUAL_H
#define PROJEKT_SEMESTRALNY_CPP_SWITCH_MANUAL_H
#include <iostream>
#include "generator_manual.h"
#include "Haslo_Manual.h"
#include "Switch.h"

class Switch_Manual{
public:
    static string nazwakategorii_manual;
    static void funkcja_switch_manual(string sciezka_zewnetrzna_hint,
                               string sciezka_zewnetrzna_master,
                               string sciezka_zewnetrzna_last,
                               string sciezka_zewnetrzna_kategorie);
};

#endif //PROJEKT_SEMESTRALNY_CPP_SWITCH_MANUAL_H
