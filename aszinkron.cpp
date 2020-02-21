/*lav[sor][oszlop]
lavdb -> lényeges állapotváltozások darab száma
negdb -> negáció darabszáma
*/

#include<iostream>
#include <math.h>
using namespace std;

	int main(int argc, char* argv[])
	{
		unsigned int lavdb=0, negdb, oszlop = 4;
		char igen = 'y', valasz;
		unsigned int** lav = new unsigned int* [lavdb];

		setlocale(LC_ALL, "HUN");
		cout << "Aszinkron sorrendi hálózat\n" << "(Create by Nagypál Márton [Neptun kód: B3081T])\n\n";

		cout << "\tLesz-e negáció a LÉNYEGES állapotváltozásban? (y/n) \t";
		cin >> valasz;
		if (valasz == igen)
		{
			do
			{
				cout << "\tHány darab lesz benne? (max 3, min 1 lehet)\t\t";
				cin >> negdb;
				if (negdb < 1 || negdb>3)
				{
					cout << "\n\t\tNem megfelelõ számot írtál be! Írj be újat!\n\n";
				}
			} while (negdb<1 || negdb>3);
			
			cout << endl;
			lavdb = pow(2, negdb); //hatványozás
		}
		else
		{
			do
			{
				cout << "\tHány LÉNYEGES állapotváltozás lesz? (1 és 4 lehet)\t";
				cin >> lavdb;
				if (lavdb<1 || lavdb>4)
				{
					cout << "\n\t\tNem megfelelõ számot írtál be! Írj be újat!\n\n";
				}
			} while (lavdb < 1 || lavdb>4);
			cout << endl;
		}

		//lav tömb kiterjesztése több dimenzióssá tétele
			for (int i = 0; i <= lavdb - 1; i++)
			{
				lav[i] = new unsigned int[oszlop]; //OSZLOPot hozza létre
			}

		for (int i = 0; i < lavdb; i++)
		{
			for(int j=0; j<oszlop;j++)
			{ 
			cout << lav[i][j] << "\t";
			//cout << "\tKérem a(z) " << i++ << " értékét:\t" << endl;
			}
		}
		cout << endl;
	system("pause");
	return 0;
}