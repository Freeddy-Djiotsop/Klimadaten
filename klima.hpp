#ifndef KLIMA_HPP_INCLUDED
#define KLIMA_HPP_INCLUDED

class Ausgabe;
class Klima
{

    std::string stadt;
    double temperatur[12];
    double niederschlag[12];
    Ausgabe* ausgabe;

public:
    Klima(std::string, Ausgabe*);
    void setAusgabe(Ausgabe*);
    void print();

    friend class Ausgabe;
    friend class Tabelle;
    friend class TDiagramm;
    friend class NDiagramm;


};

#endif // KLIMA_HPP_INCLUDED
