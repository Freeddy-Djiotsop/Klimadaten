#include <iostream>
#include "klima.hpp"
#include "ausgabe.hpp"



using namespace std;

// Menue zur Auwahl einer Stadt
string stadtauswahl()
{
	string res = "undefined";
	do {
		char input;
		cout << "Waehlen Sie einen Ort aus:\n";
		cout << "   a) Wuppertal\n";
		cout << "   b) Doha\n";
		cout << "   c) Honolulu\n";
		cout << "   d) Spitzbergen\n";
		cout << "\n";
		cout << "   x) Beenden\n  >";
		cin >> input;
		cout << endl;

		switch(input) {
			case 'a':
				res = "wuppertal.in";
				break;
			case 'b':
				res = "doha.in";
				break;
			case 'c':
				res = "honolulu.in";
				break;
			case 'd':
				res = "spitzbergen.in";
				break;
			case 'x':
				res = "beenden";
				break;
			default:
				cout << "Falsche Auswahl!" << endl << endl;
		}
	} while(res == "undefined");

	return res;
}

// Menue zur Auswahl der Ausgabe (Tabelle, Temperaturdiagramm, Niederschlagsdiagramm)
char ausgabeauswahl()
{
	char res = '/';
	do {
		char input;
		cout << "Waehlen Sie eine Ausgabeform aus:\n";
		cout << "   a) Tabelle\n";
		cout << "   b) Temperaturdiagramm\n";
		cout << "   c) Niederschlagsdiagramm\n";
		cout << "   d) Alles\n";
		cout << "\n";
		cout << "   x) vorheriges Menue\n  >";
		cin >> input;
		cout << endl;

		switch(input) {
			case 'a':
				res = 'a';
				break;
			case 'b':
				res = 'b';
				break;
			case 'c':
				res = 'c';
				break;
			case 'd':
				res = 'd';
				break;
			case 'x':
				res = 'x';
				break;
			default:
				cout << "Falsche Auwahl!" << endl << endl;
		}
	} while(res == '/');

	return res;
}


int main()
{
	Tabelle tab;
	TDiagramm tdiag;
	NDiagramm ndiag;

	bool weiter = true;

	cout << "Im folgenden Koennen Sie eine Stadt auswaehlen und ihre Klimadaten sehen" << endl << endl;
	do {
		string stadt = stadtauswahl();

		if(stadt != "beenden") {
			Klima k(stadt, &tab);

			bool weiter2 = true;
			do {
				char methode = ausgabeauswahl();

				switch(methode) {
					case 'a':
						k.setAusgabe(&tab);
						k.print();
						break;
					case 'b':
						k.setAusgabe(&tdiag);
						k.print();
						break;
					case 'c':
						k.setAusgabe(&ndiag);
						k.print();
						break;
                    case 'd':
						k.setAusgabe(&tab);
						k.print();
                        cout<<endl;
                        k.setAusgabe(&tdiag);
                        k.print();
                        cout<<endl;
                        k.setAusgabe(&ndiag);
                        k.print();
                        cout<<endl;
						break;
					case 'x':
						weiter2 = false;
						break;
					default:
						break;
				}
			} while(weiter2);
		}
		else
			weiter = false;
	} while(weiter);

	return 0;
}


/*#include<stdio.h>



int main(){
    int x,y;
    printf("firs integr = ");
    scanf("%d",&x);
    printf("second integer = ");
    scanf("%d",&y);
    printf("\n\n\n");
    for(x;x<y;y--){
    if(y==0)
    return 0;
    printf("   **\n");
    }
    for(x;x>y;x--){
    if(x==0)
    return 0;
    printf("**\n");


    }
    for(x;x<=y;x--){
    if(x==0)
    return 0;
    printf("** **\n");
    }


    return 0;
}*/

/*int main()
{


    Tabelle t;
    TDiagramm d;
    NDiagramm n;

    Klima k = Klima("wuppertal.in",&t);

    k.print();
    cout<<endl;


    k.setAusgabe(&d);

    k.print();
    cout<<endl;


    k.setAusgabe(&n);

    k.print();
    cout<<endl;


}*/


