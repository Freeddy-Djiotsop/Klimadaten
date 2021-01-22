#include<iostream>
#include <fstream>
#include <string>
#include"ausgabe.hpp"
#include"klima.hpp"


Klima::Klima(std::string datei, Ausgabe* a)
:ausgabe(a), stadt("")
{
    std::ifstream input(datei);//Datei �ffnen

    if(!input)
    {
        std::cout<<"FEHLERMELDUNG: Datei \""<<datei<<"\" konnte nicht geoeffnet werden."<<std::endl;
        std::exit(-1);
    }

    //Stadtname speichern
    input>>stadt;

    for(int i=0; i<12; i++)//Die n�tschen 12 Werte sind f�r die Temperatur gedacht
        input>>temperatur[i];

    for(int i=0; i<12; i++)//Die enderen letzten 12 f�r den Niederschlag
        input>>niederschlag[i];



}

void Klima::setAusgabe(Ausgabe* a){ausgabe=a;}



void Klima::print()
{
    ausgabe->print(*this);
}
