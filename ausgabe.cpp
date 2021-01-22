#include<iostream>
#include<iomanip>
#include<cmath>
#include"ausgabe.hpp"
#include"klima.hpp"

void extrema(const double* feld, double& mini, double& maxi)
{
    mini = maxi = feld[0];
    for(int i=0; i<12; i++)
    {
        if(feld[i]<mini)
            mini = feld[i];
        if(feld[i]>maxi)
            maxi = feld[i];
    }
}

void printZeitAchse()
{
    int luecke = 6;
    const char monate[12] ={'J', 'F', 'M', 'A', 'M', 'J', 'J', 'A', 'S', 'O', 'N', 'D'};

    std::cout<<std::setw(luecke)<<"|"<<std::setfill('-')<<std::setw(12*(luecke-1))<<""<<std::setfill(' ');
    std::cout<<"\n";

    std::cout<<std::setw(luecke)<<"";
    for(int i=0; i<12; i++)
        std::cout<<"  "<<monate[i]<<"  ";
    std::cout<<std::endl<<std::endl;
}

void Tabelle::print(Klima& k)
{

   int rand = 20;
   int luecke = 6;
   const char monate[12] ={'J', 'F', 'M', 'A', 'M', 'J', 'J', 'A', 'S', 'O', 'N', 'D'};
   std::cout<<std::setprecision(1)<<std::fixed;

   std::cout<<std::setw(rand)<<std::left<<k.stadt<<std::right<<"|";//Erste Zeile Beginn
   for(int i=0; i<12; i++)
        std::cout<<std::setw(luecke)<<monate[i];
   std::cout<<"\n";//Ende erste Zeile

   std::cout<<std::setfill('-')<<std::setw(rand)<<""<<"+"<<std::setw(12*luecke)<<""<<std::setfill(' ');//2te Zeile Beginn
   std::cout<<"\n";//Ende


   std::cout<<std::setw(rand)<<std::left<<"Temperatur (C) "<<std::right<<"|";//3te Zeile Beginn
   for(int i=0; i<12; i++)
        std::cout<<std::setw(luecke)<<k.temperatur[i];
   std::cout<<"\n";//Ende 3te Zeile


   std::cout<<std::setw(rand)<<std::left<<"Niederschlag (mm) "<<std::right<<"|";//4te Zeile Beginn
   for(int i=0; i<12; i++)
        std::cout<<std::setw(luecke)<<k.niederschlag[i];
   std::cout<<std::endl<<std::endl;//Ende 4te Zeile

}


void TDiagramm::print(Klima& k)
{
    int luecke=5;
    double mini, maxi;
    extrema(k.temperatur, mini, maxi);

    maxi = (std::fmod(maxi,5.0) > 0) ? maxi - std::fmod(maxi,5.0) + 5.0 : maxi - std::fmod(maxi,5.0);
    mini = (std::fmod(mini,5.0) < 0) ? mini - std::fmod(mini,5.0) - 5.0 : mini - std::fmod(mini,5.0);

    std::cout<<"Temperatur (C) "<<k.stadt<<"\n";

    for(double i=maxi; i>=mini; i-=1.0)
    {
        if(std::fmod(i,5.0)==0.0)
            std::cout<<std::setw(luecke)<<i<<"|";
        else
            std::cout<<std::setw(luecke)<<""<<"|";
        for(int j=0; j<12; j++)
        {
            if(std::round(k.temperatur[j])==i)
                std::cout<<"  x  ";
            else
                std::cout<<"     ";
        }
        std::cout<<"\n";
    }
    printZeitAchse();

}



void NDiagramm::print(Klima& k)
{
    int luecke=5;
    double mini, maxi;
    extrema(k.niederschlag, mini, maxi);

    maxi = maxi - std::fmod(maxi,5.0) + 5.0;

    std::cout<<"Niederschlag (mm) "<<k.stadt<<"\n";
    for(double i=maxi; i>=0.0; i-=5.0)
    {
        if(std::fmod(i,10.0)==0.0)
            std::cout<<std::setw(luecke)<<i<<"|";
        else
            std::cout<<std::setw(luecke)<<""<<"|";

        for(int j=0; j<12; j++)
        {
            if((i-2.5)<=k.niederschlag[j])
                std::cout<<"  x  ";
            else
                std::cout<<"     ";

        }
        std::cout<<"\n";
    }
    printZeitAchse();
}
