/*
lav[sor][oszlop] -> tartalma: x. lav szám,x1,x2,z
lavdb -> lényeges állapotváltozások darab száma
negdb -> negáció darabszáma
*/

#include <iostream>
#include <math.h>
using namespace std;

struct teljesallapotsor
{
	char sorbetu;
	int sorszam[3];
};

void negacio(unsigned int* neghely, unsigned int** lav)
{
	if (neghely[0] != 0 && neghely[0] < 4)
	{
		switch (neghely[0])
		{
		case 1:
			lav[0][0] = 2;
			lav[0][1] = 0;
			lav[0][4] = 1;
			lav[1][0] = 2;
			lav[1][1] = 1;
			lav[1][4] = 0;
			cout << "Megy!!\n";
			break;
		case 2:
			lav[0][0] = 2;
			lav[0][2] = 0;
			lav[0][5] = 1;
			lav[1][0] = 2;
			lav[1][2] = 1;
			lav[1][5] = 0;
			cout << "Megy!!\n";
			break;
		case 3:
			lav[0][0] = 2;
			lav[0][3] = 0;
			lav[0][6] = 1;
			lav[1][0] = 2;
			lav[1][3] = 1;
			lav[1][6] = 0;
			cout << "Megy!!\n";
			break;
		}
	}
	if (neghely[1] > 0 && neghely[1] < 4 && neghely[0]!=0)
	{
		switch (neghely[1])
		{
		case 1:
			lav[2][0] = 3;
			lav[2][1] = 0;
			lav[2][4] = 1;
			lav[3][0] = 2;
			lav[3][1] = 1;
			lav[3][4] = 0;
			cout << "Meggy!!\n";
			break;
		case 2:
			lav[2][0] = 3;
			lav[2][2] = 0;
			lav[2][5] = 1;
			lav[3][0] = 2;
			lav[3][2] = 1;
			lav[3][5] = 0;
			cout << "Meggy!!\n";
			break;
		case 3:
			lav[2][0] = 3;
			lav[2][3] = 0;
			lav[2][6] = 1;
			lav[3][0] = 2;
			lav[3][3] = 1;
			lav[3][6] = 0;
			cout << "Meggy!!\n";
			break;
		}
	}
}

int main(int argc, char* argv[])
{
	unsigned int lavdb = 0, negdb=0, oszlop = 6, neghely[1] = { 0 }, abcd = 8;
	char igen = 'y', valasz, abc[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h' }, xyz[] = { 'X', 'X', 'Z', 'X', 'X', 'Z', };
	unsigned int** lav = new unsigned int* [lavdb];
	teljesallapotsor tas[8] = {};

	setlocale(LC_ALL, "HUN");
	cout << "Aszinkron sorrendi hálózat\n"
		<< "(Create by Nagypál Márton [Neptun kód: B3081T])\n\n";

	cout << "\tLesz-e negáció a LÉNYEGES állapotváltozásban? (y/n) \t";
	cin >> valasz;
	if (valasz == igen)
	{
		do
		{
			cout << "\tHány darab lesz benne? (max 3, min 1 lehet)\t\t";
			cin >> negdb;
			if (negdb < 1 || negdb > 3)
			{
				cout << "\n\t\tNem megfelelõ számot írtál be! Írj be újat!\n\n";
			}
		} while (negdb < 1 || negdb > 3);

		cout << endl;
		lavdb = pow(2, negdb); //hatványozás
	}
	else
	{
		do
		{
			cout << "\tHány LÉNYEGES állapotváltozás lesz? (1 és 8 lehet)\t";
			cin >> lavdb;
			if (lavdb < 1 || lavdb > 8)
			{
				cout << "\n\t\tNem megfelelõ számot írtál be! Írj be újat!\n\n";
			}
		} while (lavdb < 1 || lavdb > 8);
		cout << endl;
	}

	//lav tömb kiterjesztése több dimenzióssá tétele
	for (unsigned int i = 0; i <= lavdb - 1; i++)
	{
		lav[i] = new unsigned int[oszlop]; //OSZLOPot hozza létre
	}

	//2essel feltöltés
	for (unsigned int i = 0; i < lavdb; i++)
	{
		for (unsigned int j = 1; j < oszlop + 1; j++)
		{
			lav[i][j] = 2;
		}
	}

//	cout << "\tNegáció száma: " << negdb << "\tSorok száma: " << lavdb << "\n\n";

	if (negdb > 0 && negdb < 4)
	{
		switch (negdb)
		{
		case 1:
			cout << "\n\tX1(-> 1-gyes), X2 (-> 2-es) vagy a Z (-> 3-as) lesz? ";
			cin >> neghely[0];
			negacio(neghely, lav);
			break;
		case 2:
			cout << "\n\tX1(-> 1-gyes), X2 (-> 2-es) vagy a Z (-> 3-as) lesz? ";
			for (int a = 0; a < 2; a++)
			{
				do
				{
					if (a == 1)
					{
						cout << "\tMásik szám: ";
						cin >> neghely[a];
						cout << endl;
					}
					else
					{
						cin >> neghely[a];
					}
					if (neghely[a] < 0 || neghely[a] > 3)
					{
						cout << "\n\n\tNem értelmezhető! Írj be újra!\n";
					}
				} while (neghely[a] < 0 || neghely[a] > 3);
			}
			negacio(neghely, lav);
			break;
		case 3:
			cout << "\n\n\tIDE KERÜL A 3AS NEGÁCIÓ!\n\n";
			break;
		}
	}

	if (negdb < 3)
	{
		for (unsigned int i = 0; i < lavdb; i++)
		{
			for (unsigned int j = 1; j < oszlop + 1; j++)
			{
				if (j == 1)
				{
					cout << "\tBemeneti értékek a(z) " << i + 1 << ". elemnek:\n";
				}
				else if (j == 4)
				{
					cout << "\tKimeneti értékek a(z) " << i + 1 << ". elemnek:\n";
				}
				if (lav[i][j] != 2)// ha 2es, akkor írhat be adatot
				{
					j = j + 1;
				}
				do
				{
					cout << "\t\t" << xyz[j - 1];
					if (j<3 && j!=6)
					{
						cout << j;
					}
					if (j==4)
					{
						cout << j - 3;
					}
					else if (j == 5)
					{
						cout << j - 3;
					}
					cout << " értéke: ";
					cin >> lav[i][j];
					if (lav[i][j] < 0 || lav[i][j] > 1)
					{
						cout << "\n\tNem megfelelő értéket adtál meg! Adj meg másikat!\n\n";
					}
				} while (lav[i][j] < 0 || lav[i][j] > 1);
				if (j % 3 == 0)
				{
					cout << "\n";
				}
			}
		}
	}
	system("cls");
	cout << "Aszinkron sorrendi hálózat\n"
		<< "(Create by Nagypál Márton [Neptun kód: B3081T])\n\n";
	cout << "\tLényeges állapot változások:\n\t(Értelmezés = X1, X2, Z)\n\n";
	for (unsigned int i = 0; i < lavdb; i++)
	{
		for (unsigned int j = 1; j <= oszlop; j++)
		{
			if (j == 1 && i == 0)
			{
				cout<< "\t"<<i+1<<") ";
			}
			cout << lav[i][j];
			if (j == 3)
			{
				cout << " -> ";
			}
			if (j != 6)
			{
				cout << " ";
			}
		}
		cout << endl
			<< "\t";
	}
	cout << endl
		<< endl;
	system("pause");
	return 0;
}