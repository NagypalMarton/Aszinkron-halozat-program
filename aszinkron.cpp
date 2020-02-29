﻿#include <iostream>
#include <math.h>
using namespace std;

struct teljesallapotsor
{
	char sorbetu;
	int sorszam[4];
};

void negacio(unsigned short* neghely, unsigned short** lav)
{
	if (neghely[0] != 0 && neghely[0] < 4)
	{
		switch (neghely[0])
		{
		case 1:
			lav[0][1] = 0;
			lav[0][4] = 1;
			lav[1][1] = 1;
			lav[1][4] = 0;
			break;
		case 2:
			lav[0][2] = 0;
			lav[0][5] = 1;
			lav[1][2] = 1;
			lav[1][5] = 0;

			break;
		case 3:
			lav[0][3] = 0;
			lav[0][6] = 1;
			lav[1][3] = 1;
			lav[1][6] = 0;

			break;
		}
	}
	if (neghely[1] > 0 && neghely[1] < 4 && neghely[0] != 0)
	{
		switch (neghely[1])
		{
		case 1:
			lav[2][1] = 0;
			lav[2][4] = 1;
			lav[3][1] = 1;
			lav[3][4] = 0;
			break;
		case 2:
			lav[2][2] = 0;
			lav[2][5] = 1;
			lav[3][2] = 1;
			lav[3][5] = 0;
			break;
		case 3:
			lav[2][3] = 0;
			lav[2][6] = 1;
			lav[3][3] = 1;
			lav[3][6] = 0;
			break;
		}
	}
}

int main(int argc, char* argv[])
{
	unsigned short lavdb = 0, negdb = 0, oszlop = 6, neghely[1] = {};
	char igen = 'y', valasz, abc[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h' }, xyz[] = { 'X', 'X', 'Z', 'X', 'X', 'Z' };
	unsigned short** lav = new unsigned short* [lavdb];

	setlocale(LC_ALL, "HUN");
	do
	{
		system("cls");
		cout << "Aszinkron sorrendi hálózat\n"
			<< "(Create by Nagypál Márton [Neptun kód: B3081T])\n\n";

		cout << "\tLesz-e negáció a LÉNYEGES állapotváltozásban? (y/n) \t";
		cin >> valasz;
		if (valasz == igen)
		{
			do
			{
				cout << "\tHány darab lesz benne? (maximum 2 lehet)\t\t";
				cin >> negdb;
				if (negdb < 1 || negdb > 2)
				{
					cout << "\n\t\tNem megfelelõ számot írtál be! Írj be újat!\n\n";
				}
			} while (negdb < 1 || negdb > 2);

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
		for (unsigned short i = 0; i <= lavdb - 1; i++)
		{
			lav[i] = new unsigned short[oszlop]; //OSZLOPot hozza létre
		}

		//2essel feltöltés
		for (unsigned int i = 0; i < lavdb; i++)
		{
			for (unsigned short j = 1; j < oszlop + 1; j++)
			{
				lav[i][j] = 2;
			}
		}

		if (negdb > 0 && negdb < 3 && valasz == igen)
		{
			switch (negdb)
			{
			case 1:
				cout << "\n\tMelyik helyen lesz negáció? (X1 -> 1; X2 -> 2; Z -> 3)\t ";
				cin >> neghely[0];
				negacio(neghely, lav);
				break;
			case 2:
				do
				{
					cout << "\n\tMelyik helyen lesz negáció? (X1 -> 1; X2 -> 2; Z -> 3; Szóközzel ellátva írd be!)\t ";
					cin >> neghely[0] >> neghely[1];
					if (neghely[0] && neghely[1] > 3 || neghely[0] && neghely[1] < 0)
					{
						cout << "\n\tNem megfelelő számokat írtál be!";
					}
				} while (neghely[0] && neghely[1] > 3 || neghely[0] && neghely[1] < 0);
				negacio(neghely, lav);
				break;
			}
		}

		if (lav[0][1] != 2 || lav[0][2] != 2 || lav[0][3] != 2)
		{
			cout << "\tBekérés előtt:\n\n";
			oszlop = 6;
			for (unsigned short i = 0; i < lavdb; i++)
			{
				for (unsigned short j = 1; j < oszlop + 1; j++)
				{
					if (j == 1)
					{
						cout << "\t\t" << i + 1 << ") ";
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
				cout << endl;
			}
		}

		for (unsigned short i = 0; i < lavdb; i++)
		{
			for (unsigned short j = 1; j < oszlop + 1; j++)
			{
				if (j == 1)
				{
					cout << "\n\tBemeneti értékek a(z) " << i + 1 << ". elemnek:\n";
				}
				else if (j == 4)
				{
					cout << "\tKimeneti értékek a(z) " << i + 1 << ". elemnek:\n";
				}
				if (lav[i][j] != 2) //ha nem 2es, akkor írhat be adatot
				{
					j = j + 1;
					if (j == 4)
					{
						cout << "\tKimeneti értékek a(z) " << i + 1 << ". elemnek:\n";
					}
				}
				do
				{
					cout << "\t\t" << xyz[j - 1];
					if (j < 3 && j != 6)
					{
						cout << j;
					}
					if (j == 4)
					{
						cout << j - 3;
					}
					else if (j == 5)
					{
						cout << j - 3;
					}
					if (lav[i][j] == 2)
					{
						cout << " értéke: ";
						cin >> lav[i][j];
					}
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
		system("cls");
		cout << "Aszinkron sorrendi hálózat\n"
			<< "(Create by Nagypál Márton [Neptun kód: B3081T])\n\n";
		cout << "\tLényeges állapot változások:\n\t(Értelmezés = X1, X2, Z)\n\n";
		for (unsigned short i = 0; i < lavdb; i++)
		{
			for (unsigned short j = 1; j <= oszlop; j++)
			{
				if (j == 1)
				{
					cout << "\t\t" << i + 1 << ") ";
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
			cout << endl;
		}
		cout << "\n\n\tTényeges állapot változások:\n\t(Értelmezés = X1, X2, Z)\n\n";
		teljesallapotsor tas[12] = { 2 };

		for (short i = 1; i < 12; i++)
		{
			cout << "\tMűveletek előtt:\n" << "\t";
			for (short j = 1; j < 4; j++)
			{
				cout << tas[i].sorszam[j];
				if (j == 3)
				{
					cout << "\n";
				}
				else
				{
					cout << " ";
				}
			}
		}
		cout << "\n\n";
		tas[0].sorbetu = 'a';
		cout << "\t" << tas[0].sorbetu << ") ";

		for (short i = 1; i < 4; i++)
		{
			tas[0].sorszam[0] = 2;
			tas[0].sorszam[i] = 0;
			cout << tas[0].sorszam[i] << " ";
			if (i == 3)
			{
				cout << "\n";
			}
		}

		for (unsigned short i = 0; i < 12; i++)
		{
			//Lényeges állapotváltozásokkal összehasonlítani
			for (unsigned short j = 0; j < lavdb; j++)
			{
				if (tas[i].sorszam[1] == lav[j][1] && tas[i].sorszam[2] == lav[j][2] && tas[i].sorszam[3] == lav[j][3])
				{
					tas[i + 1].sorszam[1] = lav[j][4];
					tas[i + 1].sorszam[2] = lav[j][5];
					tas[i + 1].sorszam[3] = lav[j][6];
					tas[i + 1].sorszam[0] = 0;
				}
			} //LÁV vége
			  //Ha 2 LÁV között 2 bit külömbség van, akkor a LÁVnak megfelelően legyen megváltoztatva a X1 vagy az X2
		//	if (lavdb > 1)
//			{
//				for (unsigned short j = 0; j < lavdb - 1; j++)
//				{
//					if (lav[j][5] == lav[j + 1][2] && lav[j][6] == lav[j + 1][3])
//					{
//						tas[i + 1].sorszam[1] = 1;
//					}
//					else if (lav[j][4] == lav[j + 1][1] && lav[j][6] == lav[j + 1][3])
//					{
//						tas[i + 1].sorszam[2] = 1;
//					}
//				}
//			}
		}

		for (short i = 1; i < 12; i++)
		{
			cout << "\t";
			for (short j = 1; j < 4; j++)
			{
				cout << tas[i].sorszam[j];
				if (j == 3)
				{
					cout << "\n";
				}
				else
				{
					cout << " ";
				}
			}
		}
		cout << "\n\n";
		cout << "Akarsz-e új feladatot elvégezni? (y/n) ";
		cin >> valasz;
	} while (valasz == igen);
	system("pause");
	return 0;
}