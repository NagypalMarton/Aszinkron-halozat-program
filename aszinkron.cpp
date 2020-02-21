/*lav[sor][oszlop]
lavdb -> l�nyeges �llapotv�ltoz�sok darab sz�ma
negdb -> neg�ci� darabsz�ma
*/

#include<iostream>
#include <math.h>
using namespace std;

	int main(int argc, char* argv[])
	{
		unsigned int lavdb, negdb, oszlop = 4;
		char igen = 'y', valasz;

		setlocale(LC_ALL, "HUN");
		cout << "Aszinkron sorrendi h�l�zat\n" << "(Create by Nagyp�l M�rton [Neptun k�d: B3081T])\n\n";

		cout << "\tLesz-e neg�ci� a L�NYEGES �llapotv�ltoz�sban? (y/n) \t";
		cin >> valasz;
		if (valasz == igen)
		{
			do
			{
				cout << "\tH�ny darab lesz benne? (max 3, min 1 lehet)\t\t";
				cin >> negdb;
				if (negdb < 1 || negdb>3)
				{
					cout << "\n\t\tNem megfelel� sz�mot �rt�l be! �rj be �jat!\n\n";
				}
			} while (negdb<1 || negdb>3);
			
			cout << endl;
			lavdb = pow(2, negdb); //hatv�nyoz�s
			int **lav = new int*[lavdb]; //dinamikus  t�mb l�trehoz�s SOR L�TREHOZ�SA

			//lav t�mb kiterjeszt�se t�bb dimenzi�ss� t�tele
			for (int i = 0; i <= lavdb - 1; i++)
			{
				lav[i] = new int[oszlop];//OSZLOPot hozza l�tre
			}
		}
		else
		{
			do
			{
				cout << "\tH�ny L�NYEGES �llapotv�ltoz�s lesz? (1 �s 4 lehet)\t";
				cin >> lavdb;
				if (lavdb<1 || lavdb>4)
				{
					cout << "\n\t\tNem megfelel� sz�mot �rt�l be! �rj be �jat!\n\n";
				}
			} while (lavdb < 1 || lavdb>4);
			
			cout << endl;
			int **lav = new int*[lavdb]; //dinamikus  t�mb l�trehoz�s SOR L�TREHOZ�SA

			//lav t�mb kiterjeszt�se t�bb dimenzi�ss� t�tele
			for (int i = 0; i <= lavdb - 1; i++)
			{
				lav[i] = new int[oszlop]; //OSZLOPot hozza l�tre
			}
		}

		for (int i = 0; i < lavdb; i++)
		{
			cout << i+1 << "\t";
			//cout << "\tK�rem a(z) " << i++ << " �rt�k�t:\t" << endl;
		}
		cout << endl;
	system("pause");
	return 0;
}