#ifndef AUSGABE_HPP_INCLUDED
#define AUSGABE_HPP_INCLUDED

class Klima;

class Ausgabe
{
public:
       virtual void print(Klima&)=0;
};

class Tabelle: public Ausgabe
{

public:
       void print(Klima&);
};


class TDiagramm: public Ausgabe
{
public:
       void print(Klima&);
};

class NDiagramm: public Ausgabe
{
public:
       void print(Klima&);
};

#endif // AUSGABE_HPP_INCLUDED
