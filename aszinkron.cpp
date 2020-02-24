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

int main(int argc, char* argv[])
{
	unsigned int lavdb = 0, negdb, oszlop = 7, neghely[1], abcd = 8;
	char igen = 'y', valasz, abc[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h' };
	char xyz[] = { 'x', 'y', 'z', 'x', 'y', 'z' };
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
	cout << "\tNegáció száma: " << negdb << "\tSorok száma: " << lavdb << "\n\n";

	if (negdb > 0)
	{
		switch (negdb)
		{
		case 1:
			cout << "\n\tX1(-> 1-gyes), X2 (-> 2-es) vagy a Z (-> 3-as) lesz? ";
			cin >> neghely[0];
			break;
		case 2:
			cout << "\n\tX1(-> 1-gyes), X2 (-> 2-es) vagy a Z (-> 3-as) lesz? ";
			for (int a = 0; a < 2; a++)
			{
				if (a == 1)
				{
					cout << "\tMásik szám: ";
					cin >> neghely[a];
				}
				else
				{
					cin >> neghely[a];
				}
			}
			break;
		}
	}
	if (negdb != 3)
	{
		for (unsigned int i = 0; i < lavdb; i++)
		{
			for (unsigned int j = 1; j < oszlop + 1; j++)
			{
				lav[i][0] = i + 1; //láv sorszáma
				if (j == 1)
				{
					cout << "\tBemeneti értékek a(z) " << i + 1 << ". elemnek:\n";
				}
				else if (j == 4)
				{
					cout << "\tKimeneti értékek a(z) " << i + 1 << ". elemnek:\n";
				}
				do
				{
					//Ha egy  negáció van
					/*		if (*neghely == 1 && i == 0 && j == 1 || j == 4)
					{
						lav[i][1] = 0;
						lav[i][4] = 1;
						j = j + 1;
						cout << "\n\tTeljesül a " << i + 1 << ". sornál!\n";
					}
			if (*neghely == 1 && i == 1 && j == 1 || j == 4)
					{
						lav[i][1] = 1;
						lav[i][4] = 0;
						j = j + 1;
						cout << "\t\nTTeljesül a " << i + 1 << ". sornál!!\n";
					}*/

					cout << "\t\t" << xyz[j - 1] << " értéke: ";
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
	//IDE AZ KELL LEPROGRAMOZNI, AMIKOR 3 NEGÁLÁS VAN
	system("cls");
	cout << "Aszinkron sorrendi hálózat\n"
		<< "(Create by Nagypál Márton [Neptun kód: B3081T])\n\n";
	cout << "\tLényeges állapot változások:\n\t(Értelmezés = x1, x2, z)\n\n";
	for (unsigned int i = 0; i < lavdb; i++)
	{
		for (unsigned int j = 1; j <= oszlop; j++)
		{
			if (j == 1 && i == 0)
			{
				cout << "\t";
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