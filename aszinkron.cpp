﻿#include <iostream>
#include <math.h>
#include <fstream>
#include <string>
#include <windows.h>
#include <sstream>
using namespace std;

struct teljesallapotsor
{
	char sorbetu;
	short sorszam[4];
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

void lepegetes(teljesallapotsor* tas, unsigned short tassorszam, unsigned short i)
{
	switch (tassorszam)
	{
	case 1:
		tas[i + 1].sorszam[1] = 1;
		tas[i + 1].sorszam[2] = tas[i].sorszam[2];
		tas[i + 1].sorszam[3] = tas[i].sorszam[3];
		break;
	case 2:
		tas[i + 1].sorszam[1] = 0;
		tas[i + 1].sorszam[2] = tas[i].sorszam[2];
		tas[i + 1].sorszam[3] = tas[i].sorszam[3];
		break;
	case 3:
		tas[i + 1].sorszam[1] = tas[i].sorszam[1];
		tas[i + 1].sorszam[2] = 1;
		tas[i + 1].sorszam[3] = tas[i].sorszam[3];
		break;
	case 4:
		tas[i + 1].sorszam[1] = tas[i].sorszam[1];
		tas[i + 1].sorszam[2] = 0;
		tas[i + 1].sorszam[3] = tas[i].sorszam[3];
		break;
	}
}

string egyszerusit(int allosszhossz, string allossz)
{
	string seged = "";
	char aa = 96;
	int seghossz = seged.length(), a = 0;
	while (a < allosszhossz - 1)
	{
		while (allossz[a] < aa)
		{
			a++;
		}
		if (allossz[a] > aa)
		{
			for (unsigned short b = a; allossz[b] > aa && allossz[b] != aa; b++)
			{
				seged += allossz[b];
			}
			seghossz = seged.length();
		}
		for (short lep = 0; lep < allosszhossz - 1; lep++)
		{
			if (seged[0] == allossz[lep] && seged[1] != allossz[lep + 1])
			{
				for (short lep1 = 0; lep1 < allosszhossz - 1; lep1++)
				{
					if (seged[0] != allossz[lep1] && seged[1] == allossz[lep1 + 1])
					{
						if (seghossz == 3)
						{
							for (short lep2 = 0; lep2 < allosszhossz - 1; lep2++)
							{
								if (seged[3] != allossz[lep2] && (seged[1] == allossz[lep2 + 1] || seged[0] == allossz[lep2 + 2]))
								{
									allossz.erase(lep2, 3);
									allosszhossz -= 3;
								}
							}
						}
						allossz.erase(a - 1, 4);
						allosszhossz -= 4;
					}
				}
			}
		}
		switch (seghossz)
		{
		case 2:
			if (a + 2 <= allosszhossz)
			{
				a += 2;
			}
			break;
		case 3:
			if (a + 3 <= allosszhossz)
			{
				a += 3;
			}
			break;
		}
		seged.clear();
	}
	return allossz;
}

void allapotkodkiirasa(short oszlopszam, short allapotkhossz, string allapotkod)
{
	char ascii = 64;
	unsigned short b = 0;
	for (unsigned short a = 0; a < allapotkhossz; a++)
	{
		if (b == 0)
		{
			cout << "\t\t";
		}
		cout << allapotkod[a];
		if (allapotkod[a] > ascii)
		{
			cout << " -> ";
		}
		b++;
		if (oszlopszam == b)
		{
			b = 0;
			cout << endl;
		}
	}
}

unsigned short egyszerusites(short, short, short, string, string);

int main(int argc, char* argv[])
{
	unsigned short negdb = 0, oszlop = 6, neghely[2] = {};
	long double lavdb = 4;
	char igen = 'y', IGEN = 'Y', valasz, valasz1, abc[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h' };
	string xyz = "X1X2Z";
	unsigned short** lav = new unsigned short* [lavdb];

	setlocale(LC_ALL, "HUN");
rosszlav:
	do
	{
		system("cls");
		cout << "Aszinkron sorrendi hálózat tervezése\n"
			<< "(Create by Nagypál Márton)\n\n";
		cout << "\tTXT fájlból olvasod-e be a LÉNYEGES ÁLLAPOTVÁLTOZÁSokat? (y/n) ";
		cin >> valasz;
		if (valasz == igen || valasz == IGEN)
		{
			unsigned short db = 0, hiba = 0;
			cout << "\n\t\tAlábbi néven tedd az EXE (vagy a CPP) fájllal megegyező mappába a TXT fájlt: >> aszinkron.txt <<\n\t\tTartalma hasonló formában legyen, mint az alábbi példában:\n\n";
			cout << "\t\t\t0 0 0 1 1 0\n\t\t\t1 0 1 1 0 1\n\n\t\tMehet a beolvasás? ";
			system("pause");
			fstream be("aszinkron.txt");
			if (be.fail())
			{
				cerr << "\n\t\tHiba a beolvasásnál!\n";
				hiba = 1;
				system("pause");
				goto rosszlav;
			}
			//lav tömb kiterjesztése több dimenzióssá
			for (unsigned short i = 0; i <= lavdb - 1; i++)
			{
				lav[i] = new unsigned short[7]; //OSZLOPot hozza létre
			}
			cout << "\n\t\tBeolvasás folyamatban...\n";
			for (unsigned short i = 0; i < lavdb && !be.eof(); i++)
			{
				for (size_t j = 1; j < 7; j++)
				{
					be >> lav[i][j];
				}
				db++;
			}
			be.close();
			lavdb = db;
			Sleep(1000);
			cout << "\t\tBeolvasás kész!\n\t\t";
			system("pause");
		}
		else
		{
			cout << "\n\tLesz-e negáció a LÉNYEGES állapotváltozásban? (y/n)\t";
			cin >> valasz1;
			if (valasz1 == igen || valasz1 == IGEN)
			{
				do
				{
					cout << "\n\tHány darab lesz benne? (maximum 2 lehet)\t\t";
					cin >> negdb;
					if (negdb < 1 || negdb > 2)
					{
						cout << "\n\t\tNem megfelelő számot írtál be! Írj be újat!\n";
					}
				} while (negdb < 1 || negdb > 2);
				lavdb = pow(2, negdb); //hatványozás
				if (lavdb < 3)
				{
					cout << "\n\t\tEzen felül lesz-e még Lényeges Állapot Változás? (y/n) ";
					cin >> valasz;
					if (valasz == igen || valasz == IGEN)
					{
						unsigned short lavdbplus = 0;
						do
						{
							lavdb -= lavdbplus;
							cout << "\n\t\tEddig " << lavdb << " db LÁV van. Mennyi lesz még? ";
							cin >> lavdbplus;
							lavdb += lavdbplus;
							if (lavdb > 4 || lavdb < 3)
							{
								cout << "\n\t\tNem megfelelő számot írtál be! Lényeges állaposorok db száma: " << lavdb << endl;
							}
						} while (lavdb > 4 || lavdb < 3);
					}
				}
				cout << "\n";
			}
			else
			{
				do
				{
					cout << "\n\tHány LÉNYEGES állapotváltozás lesz? (1 és 4 lehet)\t";
					cin >> lavdb;
					if (lavdb < 1 || lavdb > 4)
					{
						cout << "\n\t\tNem megfelelő szám!\n\n";
					}
				} while (lavdb < 1 || lavdb > 4);
				cout << "\n";
			}

			//lav tömb kiterjesztése több dimenzióssá
			for (unsigned short i = 0; i <= lavdb - 1; i++)
			{
				lav[i] = new unsigned short[7]; //OSZLOPot hozza létre
			}

			//2essel feltöltés
			for (unsigned int i = 0; i < lavdb; i++)
			{
				for (unsigned short j = 1; j < oszlop + 1; j++)
				{
					lav[i][j] = 2;
				}
			}

			if (negdb > 0 && negdb < 3 && (valasz1 == igen || valasz1 == IGEN))
			{
				switch (negdb)
				{
				case 1:
					do
					{
						cout << "\n\tMelyik helyen lesz negáció? (X1 -> 1; X2 -> 2; Z -> 3)\t ";
						cin >> neghely[0];
						if (neghely[0] > 3 || neghely[0] == 0)
						{
							cout << "\n\t\tNem megfelelő számot írtál be!\n\n";
						}
					} while (neghely[0] > 3 || neghely[0] == 0);
					negacio(neghely, lav);
					break;
				case 2:
					do
					{
						cout << "\n\tMelyik helyen lesz negáció? (X1 -> 1; X2 -> 2; Z -> 3; Szóközzel ellátva írd be!)\t ";
						cin >> neghely[0] >> neghely[1];
						if (neghely[0] > 3 || neghely[1] > 3 || neghely[0] < 1 || neghely[1] < 1)
						{
							cout << "\n\t\tNem megfelelő számokat vagy számot írtál be!\n";
						}
					} while (neghely[0] > 3 || neghely[1] > 3 || neghely[0] < 1 || neghely[1] < 1);
					negacio(neghely, lav);
					break;
				}
			}

			if (valasz1 == igen || valasz1 == IGEN)
			{
				cout << "\n\t\tNegálás után:\n\t\t(2esek helye lesz feltöltve)\n\n";
				for (unsigned short i = 0; i < lavdb; i++)
				{
					for (unsigned short j = 1; j <= oszlop; j++)
					{
						if (j == 1)
						{
							cout << "\t\t\t" << i + 1 << ") ";
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
					cout << "\n";
				}
			}

			for (unsigned short i = 0; i < lavdb; i++)
			{
				if (i == 0 && (valasz1 == igen || valasz1 == IGEN))
				{
					cout << "\n\n";
				}
				else if (i > 0)
				{
					cout << "\n";
				}
				for (unsigned short j = 1; j < 7; j++)
				{
					if (j == 1)
					{
						cout << "\tBemeneti értékek a(z) " << i + 1 << ". elemnek:\n";
					}
					else if (j == 4)
					{
						cout << "\n\tKimeneti értékek a(z) " << i + 1 << ". elemnek:\n";
					}
					if (lav[i][j] != 2) //ha nem 2es, akkor írhat be adatot
					{
						j = j + 1;
						if (j == 4)
						{
							cout << "\n\tKimeneti értékek a(z) " << i + 1 << ". elemnek:\n";
						}
					}
					do
					{
						if (lav[i][j] == 2)
						{
							cout << "\t\t";
							if (j == 1 || j == 4)
							{
								cout << xyz[0] << xyz[1];
							}
							else if (j == 2 || j == 5)
							{
								cout << xyz[2] << xyz[3];
							}
							else if (j == 3 || j == 6)
							{
								cout << xyz[4];
							}
							cout << " értéke: ";
							cin >> lav[i][j];
						}
						if (lav[i][j] > 1)
						{
							cout << "\n\tNem megfelelő értéket adtál meg! Adj meg másikat! Értéke: " << lav[i][j] << "\n\n";
							lav[i][j] = 2;
						}
					} while (lav[i][j] > 1);
				}
			}
		}
		system("cls");
		cout << "Aszinkron sorrendi hálózat tervezése\n"
			<< "(Create by Nagypál Márton)\n\n"
			<< "\n\tLényeges állapot változások:\n\t(Értelmezés = X1, X2, Z)\n\n";
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
		cout << "\n\n\tTényleges állapot változások:\n\t(Értelmezés = X1, X2, Z)\n\n";
		teljesallapotsor tas[12] = {};
		unsigned short tasdb = 1, tasdbb = 12, tassorszam = 0, lavd = 0, abcd = 1;

		for (short i = 1; i < tasdbb; i++) //2essel való feltöltés
		{
			for (short j = 1; j < 4; j++)
			{
				tas[i].sorszam[j] = 2;
			}
		}
		tas[0].sorbetu = 'a';

		for (short i = 1; i < 4; i++)
		{
			tas[0].sorszam[0] = 2;
			tas[0].sorszam[i] = 0;
		}

		for (unsigned short i = 0; i < tasdbb; i++)
		{
			//Lényeges állapotváltozásokkal hasonlítja össze
			for (unsigned short j = 0; j < lavdb; j++)
			{
				if (tas[i].sorszam[1] == lav[j][1] && tas[i].sorszam[2] == lav[j][2] && tas[i].sorszam[3] == lav[j][3])
				{
					tas[i + 1].sorbetu = abc[abcd];
					tas[i + 1].sorszam[0] = 2;
					tas[i + 1].sorszam[1] = lav[j][4];
					tas[i + 1].sorszam[2] = lav[j][5];
					tas[i + 1].sorszam[3] = lav[j][6];
					tasdb++;
					abcd++;
				}
				lavd = lavd + 1;
			} //LÁV vége

			short k = 0;
			if (tas[i + 1].sorszam[0] != 2)
			{
				if (tas[i].sorszam[1] == 1 && tas[i].sorszam[2] == 1) //1 1
				{
					tas[i + 1].sorbetu = abc[abcd];
					if (tas[i].sorszam[2] != lav[k][2] && tas[i].sorszam[3] == lav[k][3])
					{
						tassorszam = 2;
					}
					else
					{
						tassorszam = 4;
					}
					lepegetes(tas, tassorszam, i);
					tasdb++;
					abcd++;
				}
				else if (tas[i].sorszam[1] == 0 && tas[i].sorszam[2] == 0) //0 0
				{
					tas[i + 1].sorbetu = abc[abcd];
					if (tas[i].sorszam[1] != lav[k][1] && tas[i].sorszam[3] == lav[k][3])
					{
						tassorszam = 1;
					}
					else
					{
						tassorszam = 3;
					}
					lepegetes(tas, tassorszam, i);
					tasdb++;
					abcd++;
				}
				else if (tas[i].sorszam[1] == 1 && tas[i].sorszam[2] == 0) // 1 0
				{
					tas[i + 1].sorbetu = abc[abcd];
					if (tas[i - 1].sorszam[1] == 0 && tas[i - 1].sorszam[2] == 0)
					{
						tassorszam = 3;
					}
					else
					{
						tassorszam = 2;
					}
					lepegetes(tas, tassorszam, i);
					tasdb++;
					abcd++;
				}
				else if (tas[i].sorszam[1] == 0 && tas[i].sorszam[2] == 1) // 0 1
				{
					tas[i + 1].sorbetu = abc[abcd];
					if (tas[i - 1].sorszam[1] == 0 && tas[i - 1].sorszam[2] == 0)
					{
						tassorszam = 1;
					}
					else
					{
						tassorszam = 4;
					}
					lepegetes(tas, tassorszam, i);
					tasdb++;
					abcd++;
				}
				k++;
			}
			if (tas[i + 1].sorszam[1] == 0 && tas[i + 1].sorszam[2] == 0 && tas[i + 1].sorszam[3] == 0 && lavd > 1)
			{
				//delete[] lav;
				break;
			}
			else if (i == tasdbb - 1)
			{
				cout << "\n\tEgy gomb nyomás után újraindul a program, mivel végtelen ciklusba került az egyik lényeges állapot változás miatt!\n\n";
				system("pause");
				goto rosszlav;
			}
		}
		//hiányzó sorok keresése és betöltése a TASba
		int teljestas[8][4] = { {0, 0, 0}, {0, 1, 0}, {1, 1, 0}, {1, 0, 0}, {0, 0, 1}, {0, 1, 1}, {1, 1, 1}, {1, 0, 1} }, tasdab = tasdb;

		for (short i = 0; i < tasdb; i++) //Egyezők keresése
		{
			for (short j = 0; j < 8; j++)
			{
				if (tas[i].sorszam[1] == teljestas[j][0] && tas[i].sorszam[2] == teljestas[j][1] && tas[i].sorszam[3] == teljestas[j][2])
				{
					teljestas[j][3] = 2;
				}
			}
		}
		for (short i = 0; i < 8; i++)
		{
			if (teljestas[i][3] != 2)
			{
				tas[tasdab].sorbetu = abc[abcd];
				abcd += 1;
				tas[tasdab].sorszam[1] = teljestas[i][0];
				tas[tasdab].sorszam[2] = teljestas[i][1];
				tas[tasdab].sorszam[3] = teljestas[i][2];
				tasdab = tasdab + 1;
			}
		}

		//megbetűzés
		for (short i = 0; i < tasdab - 1; i++)
		{
			for (short j = i + 1; j < tasdab; j++)
			{
				if (tas[i].sorszam[1] == tas[j].sorszam[1] && tas[i].sorszam[2] == tas[j].sorszam[2] && tas[i].sorszam[3] == tas[j].sorszam[3])
				{
					unsigned short sorszam = 0, c = 0;
					while (abc[sorszam] != tas[j].sorbetu)
					{
						sorszam += 1;
					}
					for (short b = sorszam; b < tasdab + 1; b++)
					{
						if (tas[b + 1].sorszam[0] == 3)
						{
							c = b;
							b += 1;
							tas[b + 1].sorbetu = abc[c];
						}
						else
						{
							tas[b + 1].sorbetu = abc[b];
						}
					}
					tas[j].sorszam[0] = 3;
					tas[j].sorbetu = tas[i].sorbetu;
				}
			}
		}
		//Utolsó sornak ellenőrzése, hogy kapott-e betűt
		if (tas[tasdab].sorbetu != abc[7])
		{
			tas[tasdab].sorbetu = abc[7];
		}
		//TAS kiírattatása
		for (short i = 0; i < tasdab; i++)
		{
			if (i == tasdb)
			{
				cout << "\n\t\tA sorban meg nem\n\t\tjelent állapot változások:\n\n";
			}
			cout << "\t\t" << tas[i].sorbetu << ") ";
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
		string allapotsor, tasszamm;
		short b = 0, teljestasoszlop = 9;
		for (short a = 0; a < tasdab; a++)
		{
			if (a != 0)
			{
				b = b + 1;
			}
			if (tas[a].sorszam[1] == 0 && tas[a].sorszam[2] == 0) //0 0
			{
				tasszamm = to_string(tas[a].sorszam[3]);
				if (a == 0)
				{
					allapotsor = tas[a].sorbetu; //0
				}
				else
				{
					allapotsor += tas[a].sorbetu; //0
				}
				allapotsor += tas[a].sorbetu; //1
				allapotsor += tasszamm;		  //2
				allapotsor += tasszamm;		  //3
				allapotsor += tasszamm;		  //4
				allapotsor += "XX";			  //5
				allapotsor += tasszamm;		  //6
				allapotsor += tasszamm;
			}
			else if (tas[a].sorszam[1] == 0 && tas[a].sorszam[2] == 1) // 0 1
			{
				tasszamm = to_string(tas[a].sorszam[3]);
				allapotsor += tas[a].sorbetu; //0
				allapotsor += tasszamm;
				allapotsor += tasszamm;
				allapotsor += tas[a].sorbetu;
				allapotsor += tasszamm;
				allapotsor += tasszamm;
				allapotsor += tasszamm;
				allapotsor += "XX";
			}
			else if (tas[a].sorszam[1] == 1 && tas[a].sorszam[2] == 1) // 1 1
			{
				tasszamm = to_string(tas[a].sorszam[3]);
				allapotsor += tas[a].sorbetu; //0
				allapotsor += "XX";
				allapotsor += tasszamm;
				allapotsor += tasszamm;
				allapotsor += tas[a].sorbetu;
				allapotsor += tasszamm;
				allapotsor += tasszamm;
				allapotsor += tasszamm;
			}
			else if (tas[a].sorszam[1] == 1 && tas[a].sorszam[2] == 0) // 1 0
			{
				tasszamm = to_string(tas[a].sorszam[3]);
				allapotsor += tas[a].sorbetu; //0
				allapotsor += tasszamm;
				allapotsor += tasszamm;
				allapotsor += "XX";
				allapotsor += tasszamm;
				allapotsor += tasszamm;
				allapotsor += tas[a].sorbetu;
				allapotsor += tasszamm;
			}
		}

		unsigned int hossz = allapotsor.length();
		string nulla = "0", egy = "1", allapotsor1 = "";
		//	Állapotsor hiányzó celláinak kitöltése
		for (unsigned short k = 0; k < hossz; k = k + 2)
		{
			if (allapotsor[k] == abc[k / 9] && k % 9 == 0)
			{
				k += 1;
			}
			else if (k % 9 == 0)
			{
				k += 1;
			}
			//egymás alatti értékek összehasonlítása
			if ((allapotsor[k] == nulla[0] && allapotsor[k + 1] == nulla[0]) || (allapotsor[k] == egy[0] && allapotsor[k + 1] == egy[0]))
			{
				unsigned short kj = k;
				if (k < 54)
				{
					while (kj < hossz - 9 && (allapotsor[kj] == egy[0] || allapotsor[kj] == nulla[0] || (allapotsor[kj] == 'X' && allapotsor[kj + 1] == 'X')))
					{
						kj += 9;
					}
				}
				else if (k >= 45)
				{
					while (kj < hossz && (allapotsor[kj] == egy[0] || allapotsor[kj] == nulla[0] || (allapotsor[kj] == 'X' && allapotsor[kj + 1] == 'X') || allapotsor[kj + 1] == 'X'))
					{
						kj -= 9;
					}
				}
				allapotsor[k] = allapotsor[kj];
				//kimenetváltozás figyelése
				if (allapotsor[k + 1] != allapotsor[kj + 1])
				{
					allapotsor[k + 1] = 'X';
				}
			}
		}
		if (tas[tasdab].sorbetu != abc[7])
		{
			cout << "\tA program ismeretlen hiba miatt kilép!\n\n";
			exit(1);
		}
		cout << "\n\n\tÁllapot táblázat\n\n\ty\\x1x2\t00\t01\t11\t10\n\t";
		//táblázat kiírása
		for (unsigned short a = 0; a < 35; a++)
		{
			cout << "=";
		}
		cout << endl;
		short ab = 0;
		for (unsigned short a = 0; a < 8; a++)
		{
			cout << "\t  " << abc[a];
			allapotsor1 += abc[a];
		ellenoriz:
			if (abc[a] == allapotsor[ab])
			{
				cout << "\t" << allapotsor[ab + 1] << allapotsor[ab + 2] << "\t" << allapotsor[ab + 3] << allapotsor[ab + 4] << "\t" << allapotsor[ab + 5] << allapotsor[ab + 6] << "\t" << allapotsor[ab + 7] << allapotsor[ab + 8] << "\n\n";
				for (short d = 1; d < 9; d++)
				{
					allapotsor1 += allapotsor[ab + d];
				}
			}
			else
			{
				while (abc[a] != allapotsor[ab])
				{
					ab += 9;
				}
				if (abc[a] == allapotsor[ab])
				{
					goto ellenoriz;
				}
			}
			ab += 9;
		}
		cout << "\n\tLépcsős egyszerűsítési tábla\n\n";
		string lepcsos = "", allapotossz = "";
		//sorok összehasonlítása
		for (unsigned short a = 1; a < 64; a += teljestasoszlop)
		{
			unsigned short aa = a, osszevon = 0, i = 0, bb = 0;
			for (unsigned short b = aa + 9; b < 73; b += teljestasoszlop)
			{
				i = 0;
				aa = a;
				bb = b;
				while (i < 4 && ((allapotsor1[aa] == allapotsor1[bb] && allapotsor1[aa + 1] == allapotsor1[bb + 1]) || (allapotsor1[aa] == allapotsor1[bb] && allapotsor1[bb + 1] == 'X') || (allapotsor1[aa] == allapotsor1[bb] && allapotsor1[aa + 1] == 'X') || allapotsor1[bb] == 'X' || allapotsor1[aa] == 'X'))
				{
					i++;
					osszevon++;
					bb += 2;
					aa += 2;
				}
				if (osszevon == 4)
				{
					allapotossz += abc[(a - 1) / 9];
					allapotossz += abc[(bb - 1) / 9];
					aa = 0;
					lepcsos += "+";
					osszevon = 0;
				}
				else
				{
					aa = 0;
					lepcsos += "-";
					osszevon = 0;
				}
			}
		}
		allapotsor = allapotsor1;
		allapotsor1.clear();

		//kiírattatása
		cout << "\n";
		for (short a = 1; a < 8; a++)
		{
			cout << "\t" << abc[a] << "\t";
			for (unsigned short b = a - 1; b < a; b++)
			{
				cout << lepcsos[b] << "\t";
				if (a > 1)
				{
					cout << lepcsos[b + 6] << "\t";
				}
				if (a > 2)
				{
					cout << lepcsos[b + 11] << "\t";
				}
				if (a > 3)
				{
					cout << lepcsos[b + 15] << "\t";
				}
				if (a > 4)
				{
					cout << lepcsos[b + 18] << "\t";
				}
				if (a > 5)
				{
					cout << lepcsos[b + 20] << "\t";
				}
				if (a > 6)
				{
					cout << lepcsos[b + 21];
				}
			}
			cout << "\n\n";
		}
		for (short a = 0; a < 7; a++)
		{
			if (a == 0)
			{
				cout << "\t\t";
			}
			else
			{
				cout << "\t";
			}
			cout << abc[a];
		}
		cout << "\n\n\tÁllapotok összevonása\n\n";
		string allossz = "";
		unsigned int allapothossz = allapotossz.length(), a1 = 0, aa = 0, allosszhossz;
		//kiírattatás
		for (short a = 0; a < 7; a++)
		{
			unsigned short seged1;
			cout << "\t";
			for (short b = a + 1; b < 8; b++)
			{
				cout << abc[b % 9];
				if ((b - a == 1 || b - a == 0))
				{
					seged1 = b % 9;
				}
			}
			//Keressük ki, hogy az adott oszlopban lévő állapotok összevonhatóak-e vagy nem
			aa = a1;
			while (aa < allapothossz && allapotossz[aa] < abc[seged1])
			{
				//lineáris keresés
				unsigned short b = aa + 2, seged = 0, d = 0;
				while (b < allapothossz && allapotossz[aa] != allapotossz[b])
				{
					b += 2;
				}
				if (allapotossz[aa] == allapotossz[b])
				{
					//lineáris keresés
					unsigned short c = aa + 2;
					d = b + 1;
					b = aa + 1;
					while (c < allapothossz && allapotossz[b] != allapotossz[c])
					{
						c += 2;
					}
					if (allapotossz[c] == allapotossz[b])
					{
						if (allapotossz[d] == allapotossz[b + 2])
						{
							allossz += "(";
							allossz += allapotossz[b + 1];
							allossz += allapotossz[aa + 1];
							allossz += allapotossz[d];
							allossz += ")";
							allapotossz.erase(aa + 2, 2);
							allapothossz -= 2;
							seged = 1;
						}
						else
						{
							if (egyszerusites(b + 1, b, aa + 1, allossz, allapotossz) < 2)
							{
								allossz += "(";
								allossz += allapotossz[b + 1];
								allossz += allapotossz[aa + 1];
								allossz += ")";
							}
						}
					}
					else
					{
						if (egyszerusites(aa, b = 0, aa + 1, allossz, allapotossz) < 2)
						{
							allossz += "(";
							allossz += allapotossz[aa];
							allossz += allapotossz[aa + 1];
							allossz += ")";
						}
					}
				}
				else
				{
					if (egyszerusites(aa, b = 0, aa + 1, allossz, allapotossz) < 2)
					{
						allossz += "(";
						allossz += allapotossz[aa];
						allossz += allapotossz[aa + 1];
						allossz += ")";
					}
				}
				aa += 2;
				a1 = aa;
			}
			cout << "\t" << allossz;
			if (a < 6)
			{
				cout << endl;
			}
		}

		allosszhossz = allossz.length();
		//system("pause");
		allossz = egyszerusit(allosszhossz, allossz);
		allosszhossz = allossz.length();

		int alhossz = allossz.length(), a = 0, abcszam = 0, allapotsz[8];
		short asz, j = 0;
		string ABCD = "ABCDEFGH";

		allapotossz.clear(); //allapotossz "kitisztitása"
		do
		{
			while (a < alhossz && allossz[a] != '(')
			{
				a++;
			}
			if (allossz[a] == '(')
			{
				asz = 0;
				allapotossz += ABCD[abcszam];
				allapotossz += " ";
				for (short i = a + 1; allossz[i] != ')'; i++)
				{
					allapotossz += allossz[i];
					asz++;
				}
				allapotossz += " ";
				allapotsz[j] = asz;
				if (a + 1 < alhossz)
				{
					abcszam++;
					a++;
					j++;
				}
			}
		} while (a < alhossz);
		allapothossz = allapotossz.length();
		cout << "\n\n\t\tLegegyszerűbb összevont állapot (megbetűzve) -> \t" << allapotossz;

		cout << "\n\n\tÖsszevont állapottáblázat\n\n\ty\\x1x2\t00\t01\t11\t10\n\t";
		string osszallapot = "";
		int osszallapothossz = osszallapot.length();
		for (unsigned short a = 0; a < 35; a++)
		{
			cout << "=";
		}
		for (unsigned short a = 0; a < abcszam; a++)
		{
			cout << "\n\t   " << ABCD[a] << "\t";
			osszallapot += ABCD[a];
			unsigned short b = 0;
			while (b < allapothossz && ABCD[a] != allapotossz[b])
			{
				b++;
			}
			if (ABCD[a] == allapotossz[b])
			{
				if (allapotsz[a] == 2)
				{
					unsigned short c = 0, d = 0;
					while (c < hossz && allapotossz[b + 2] != allapotsor[c])
					{
						c += 9;
					}
					while (d < hossz && allapotossz[b + 3] != allapotsor[d])
					{
						d += 9;
					}
					if (allapotossz[b + 2] == allapotsor[c] && allapotossz[b + 3] == allapotsor[d])
					{
						for (unsigned short f = 1; f < 9; f++)
						{
							char kisa = 97, at = 64, slash = 47;
							//at(@) az A előtt van, / az a 0 előtt
							unsigned short lepes = 0, nagybetuindex = 0;
							if (allapotsor[c + f] == allapotsor[d + f] && allapotsor[c + f] != 'X' && allapotsor[d + f] != 'X' && allapotsor[c + f] > at && allapotsor[d + f] > at) // egyezik a 2 betű
							{
								lepes = 0, nagybetuindex = 0;
								while (lepes < allapotossz.length() && allapotossz[lepes] != allapotsor[d + f])
								{
									if (allapotossz[lepes] < kisa && allapotossz[lepes] > at)
									{
										nagybetuindex = lepes;
									}
									lepes++;
								}
								if (allapotossz[lepes] == allapotsor[d + f])
								{
									cout << allapotossz[nagybetuindex];
									osszallapot += allapotossz[nagybetuindex];
								}
								else
								{
									cout << ABCD[a];
									osszallapot += ABCD[a];
								}
							}
							else if (allapotsor[c + f] != allapotsor[d + f] && (allapotsor[c + f] != 'X' || allapotsor[d + f] != 'X') && allapotsor[c + f] > at && allapotsor[d + f] > at) // betű - X / X-betű eset
							{
								lepes = 0, nagybetuindex = 0;
								if (allapotsor[c + f] != 'X' && allapotsor[d + f] == 'X')
								{
									//allapotsor[c+ f]-t kell megkeresni
									while (lepes < allapotossz.length() && allapotossz[lepes] != allapotsor[c + f])
									{
										if (allapotossz[lepes] < kisa && allapotossz[lepes] > at)
										{
											nagybetuindex = lepes;
										}
										lepes++;
									}
									if (allapotossz[lepes] == allapotsor[c + f])
									{
										cout << allapotossz[nagybetuindex];
										osszallapot += allapotossz[nagybetuindex];
									}
									else
									{
										cout << ABCD[a];
										osszallapot += ABCD[a];
									}
								}
								else if (allapotsor[d + f] != 'X' && allapotsor[c + f] == 'X')
								{
									//allapotsor[d + f]-t kell megkeresni
									lepes = 0, nagybetuindex = 0;
									while (lepes < allapotossz.length() && allapotossz[lepes] != allapotsor[d + f])
									{
										if (allapotossz[lepes] < kisa && allapotossz[lepes] > at)
										{
											nagybetuindex = lepes;
										}
										lepes++;
									}
									if (allapotossz[lepes] == allapotsor[d + f])
									{
										cout << allapotossz[nagybetuindex];
										osszallapot += allapotossz[nagybetuindex];
									}
									else
									{
										cout << ABCD[a];
										osszallapot += ABCD[a];
									}
								}
							}
							else if (allapotsor[c + f] != allapotsor[d + f] && (allapotsor[c + f] != 'X' || allapotsor[d + f] != 'X') && ((allapotsor[c + f] > slash && allapotsor[c + f] < at) || (allapotsor[d + f] > slash && allapotsor[d + f] < at))) //szám - X / X szám párosítás
							{
								if (allapotsor[c + f] != 'X' && allapotsor[d + f] == 'X')
								{
									cout << allapotsor[c + f];
									osszallapot += allapotsor[c + f];
								}
								else if (allapotsor[d + f] != 'X' && allapotsor[c + f] == 'X')
								{
									cout << allapotsor[d + f];
									osszallapot += allapotsor[d + f];
								}
								else
								{
									cout << "Hiba!";
								}
							}
							else if (allapotsor[c + f] == allapotsor[d + f] && (allapotsor[c + f] == '1' || allapotsor[c + f] == '0')) //szám - szám egyezés
							{
								cout << allapotsor[c + f];
								osszallapot += allapotsor[c + f];
							}
							else if (allapotsor[d + f] == 'X' && allapotsor[c + f] == 'X') //X - X
							{
								if (f % 2 == 0)
								{
									cout << "X";
									osszallapot += 'X';
								}
								else
								{
									cout << ABCD[a];
									osszallapot += ABCD[a];
								}
							}
							if (f % 2 == 0)
							{
								cout << "\t";
							}
						}
					}
				}
				else if (allapotsz[a] == 3)
				{
					unsigned short c = 0, d = 0, e = 0;
					while (c < hossz && allapotossz[b + 2] != allapotsor[c])
					{
						c += 9;
					}
					while (d < hossz && allapotossz[b + 3] != allapotsor[d])
					{
						d += 9;
					}
					while (e < hossz && allapotossz[b + 4] != allapotsor[e])
					{
						e += 9;
					}
					if (allapotossz[b + 2] == allapotsor[c] && allapotossz[b + 3] == allapotsor[d] && allapotossz[b + 4] == allapotsor[e])
					{
						for (unsigned short f = 1; f < 9; f++)
						{
							char kisa = 97, at = 64, slash = 47;
							//at(@) az A előtt van, / az a 0 előtt
							unsigned short lepes = 0, nagybetuindex = 0;
							if (allapotsor[c + f] == allapotsor[d + f] && allapotsor[c + f] == allapotsor[e + f] && allapotsor[c + f] != 'X' && allapotsor[d + f] != 'X' && allapotsor[e + f] != 'X' && allapotsor[c + f] > at && allapotsor[d + f] > at && allapotsor[e + f] > at) // egyezik a 3 betű és egyik sem lehet X
							{
								lepes = 0, nagybetuindex = 0;
								while (lepes < allapotossz.length() && allapotossz[lepes] != allapotsor[d + f])
								{
									if (allapotossz[lepes] < kisa && allapotossz[lepes] > at)
									{
										nagybetuindex = lepes;
									}
									lepes++;
								}
								if (allapotossz[lepes] == allapotsor[d + f])
								{
									cout << allapotossz[nagybetuindex];
									osszallapot += allapotossz[nagybetuindex];
								}
								else
								{
									cout << ABCD[a];
									osszallapot += ABCD[a];
								}
							}
							else if ((allapotsor[c + f] != 'X' || allapotsor[d + f] != 'X' || allapotsor[e + f] != 'X') && allapotsor[c + f] > at && allapotsor[d + f] > at && allapotsor[e + f] > at) // betű - X / X-betű eset és az egyik egyezhet a másikkal
							{
								lepes = 0, nagybetuindex = 0;
								if (allapotsor[c + f] != 'X' && allapotsor[d + f] == 'X' && allapotsor[c + f] == allapotsor[e + f]) //c-vel egyezik
								{
									//allapotsor[c+ f]-t kell megkeresni
									while (lepes < allapotossz.length() && allapotossz[lepes] != allapotsor[c + f])
									{
										if (allapotossz[lepes] < kisa && allapotossz[lepes] > at)
										{
											nagybetuindex = lepes;
										}
										lepes++;
									}
									if (allapotossz[lepes] == allapotsor[c + f])
									{
										cout << allapotossz[nagybetuindex];
										osszallapot += allapotossz[nagybetuindex];
									}
									else
									{
										cout << ABCD[a];
										osszallapot += ABCD[a];
									}
								}
								else if (allapotsor[d + f] != 'X' && allapotsor[c + f] == 'X' && allapotsor[d + f] == allapotsor[e + f]) //d-vel egyezik
								{
									//allapotsor[d + f]-t kell megkeresni
									lepes = 0, nagybetuindex = 0;
									while (lepes < allapotossz.length() && allapotossz[lepes] != allapotsor[d + f])
									{
										if (allapotossz[lepes] < kisa && allapotossz[lepes] > at)
										{
											nagybetuindex = lepes;
										}
										lepes++;
									}
									if (allapotossz[lepes] == allapotsor[d + f])
									{
										cout << allapotossz[nagybetuindex];
										osszallapot += allapotossz[nagybetuindex];
									}
								}
								else  if (allapotsor[e + f] == 'X' && allapotsor[c + f] == allapotsor[d + f]) //ha egyikkel sem egyezik, de a a másik 2 egyezik
								{
									lepes = 0, nagybetuindex = 0;
									while (lepes < allapotossz.length() && allapotossz[lepes] != allapotsor[d + f])
									{
										if (allapotossz[lepes] < kisa && allapotossz[lepes] > at)
										{
											nagybetuindex = lepes;
										}
										lepes++;
									}
									if (allapotossz[lepes] == allapotsor[d + f])
									{
										cout << allapotossz[nagybetuindex];
										osszallapot += allapotossz[nagybetuindex];
									}
								}
								else
								{
									cout << "Hiba! (Betű - X kombináció) ";

								}
							}
							else if (allapotsor[c + f] != allapotsor[d + f] && (allapotsor[c + f] != 'X' || allapotsor[d + f] != 'X') && ((allapotsor[c + f] > slash && allapotsor[c + f] < at) || (allapotsor[d + f] > slash && allapotsor[d + f] < at) || (allapotsor[e + f] > slash && allapotsor[e + f] < a))) //szám - X / X szám párosítás és a 3. vagy C-vel vagy D-vel egyezzen
							{
								if (allapotsor[c + f] != 'X' && allapotsor[d + f] == 'X' && allapotsor[e + f] == allapotsor[c + f]) // 3. a C-vel egyezzen meg
								{
									cout << allapotsor[c + f];
									osszallapot += allapotsor[c + f];
								}
								else if (allapotsor[d + f] != 'X' && allapotsor[c + f] == 'X' && allapotsor[e + f] == allapotsor[d + f])// 3. a D-vel egyezzen meg
								{
									cout << allapotsor[d + f];
									osszallapot += allapotsor[d + f];
								}
								else //if (allapotsor[e + f] == 'X')
								{
									if (allapotsor[c + f] == 'X' && allapotsor[e + f] == 'X')//ha c is X
									{
										cout << allapotsor[d + f];
										osszallapot += allapotsor[d + f];
									}
									else if (allapotsor[d + f] == 'X' && allapotsor[e + f] == 'X')//ha d is X
									{
										cout << allapotsor[c + f];
										osszallapot += allapotsor[c + f];
									}
									else if (allapotsor[d + f] == 'X' && allapotsor[c + f] == 'X') //ha C és D is X
									{
										cout << allapotsor[e + f];
										osszallapot += allapotsor[e + f];
									}
								}
								/*else
								{
									cout << "Hiba!";
								}*/
							}
							else if (allapotsor[c + f] == allapotsor[d + f] && allapotsor[c + f] == allapotsor[e + f] && (allapotsor[c + f] == '1' || allapotsor[c + f] == '0')) //szám - szám egyezés
							{
								cout << allapotsor[c + f];
								osszallapot += allapotsor[c + f];
							}
							else if (allapotsor[d + f] == 'X' && allapotsor[c + f] == 'X' && allapotsor[e + f] == 'X') //X - X
							{
								if (f % 2 == 0)
								{
									cout << "X";
									osszallapot += 'X';
								}
								else
								{
									cout << ABCD[a];
									osszallapot += ABCD[a];
								}
							}
							if (f % 2 == 0)
							{
								cout << "\t";
							}
						}
					}
				}
				else
				{
					cout << "\t\tCsak 2es és 3as összevonasokat tudok kezelni! Ezért a program kilép!\n";
					osszallapothossz = 0;
					system("pause");
					exit(1);
				}
			}
			cout << endl;
			osszallapothossz = osszallapot.length();
		}
		cout << "\n\n\tÖsszállapot: " << osszallapot << " Hossz: " << osszallapothossz;
		cout << "\n\n\tÁllapotok kódolása\n\t(Egyenlőre statikus)\n\n";
		string allapotkod = "", gray4 = "00101101", gray8 = "000010011001100110111101";
		short oszlopszam;
		if (abcszam < 5 && abcszam > 0)
		{
			int gray4sz = gray4.length(), c = 0, allapotkhossz;
			oszlopszam = 3;
			for (unsigned short a = 0; a < abcszam; a++)
			{
				allapotkod += ABCD[a];
				allapotkod += gray4[c];
				allapotkod += gray4[c + 1];
				if (c < gray4sz + 1)
				{
					c += 2;
				}
			}
			allapotkhossz = allapotkod.length();
			allapotkodkiirasa(oszlopszam, allapotkhossz, allapotkod);

		}
		else if (abcszam > 4 && abcszam < 9)
		{
			int gray8sz = gray8.length(), c = 0, allapotkhossz;
			oszlopszam = 4;
			for (unsigned short a = 0; a < abcszam; a++)
			{
				allapotkod += ABCD[a];
				allapotkod += gray8[c];
				allapotkod += gray8[c + 1];
				allapotkod += gray8[c + 2];
				if (c < gray8sz)
				{
					c += 3;
				}
			}
			allapotkhossz = allapotkod.length();
			allapotkodkiirasa(oszlopszam, allapotkhossz, allapotkod);
		}
		cout << "\n\tKódolt Állapottábla felírása\n\n\t\ta) DIREKT BEKÖTÉSI\n\n\t\t\ty\\x1x2\t00\t01\t11\t10\n\t\t\t";
		int allapotkhossz = allapotkod.length();
		for (unsigned short a = 0; a < 35; a++)
		{
			cout << "=";
		}
		char ascii = 64;
		b = 0;
		for (unsigned short a = 0; a < allapotkhossz; a++)
		{
			if (b == 0)
			{
				cout << "\n\t\t\t  ";
			}
			
			if (allapotkod[a] > ascii)
			{
				a += 1;
			}
			cout << allapotkod[a];
			b++;
			if (oszlopszam-1 == b)
			{
				b = 0;
				cout << endl;
			}
		}
		cout << "\n\n\t\tb) TÁROLÓS\n\n";
		b = 0;
		cout << "\t\t\ta) \\S1\\R1\n\n\t\t\ty\\x1x2\t00\t01\t11\t10\n\t\t\t";
		for (unsigned short a = 0; a < 35; a++)
		{
			cout << "=";
		}
		for (unsigned short a = 0; a < allapotkhossz; a++)
		{
			if (b == 0)
			{
				cout << "\n\t\t\t  ";
			}

			if (allapotkod[a] > ascii)//Betűk kihagyása
			{
				a += 1;
			}
			cout << allapotkod[a];
			b++;
			if (oszlopszam - 1 == b)
			{
				b = 0;
				cout << endl;
			}
		}
		cout << "\n\n\t\t\tb) \\S2\\R2\n\n\t\t\ty\\x1x2\t00\t01\t11\t10\n\t\t\t";
		for (unsigned short a = 0; a < 35; a++)
		{
			cout << "=";
		}
		for (unsigned short a = 0; a < allapotkhossz; a++)
		{
			if (b == 0)
			{
				cout << "\n\t\t\t  ";
			}

			if (allapotkod[a] > ascii)//Betűk kihagyása
			{
				a += 1;
			}
			cout << allapotkod[a];
			b++;
			if (oszlopszam - 1 == b)
			{
				b = 0;
				cout << endl;
			}
		}
		cout << "\nA táblázatok alapján rajzold meg a DIREKT BEKÖTÉSI és a TÁROLÓS aszinkron hálózatot!\n\nAkarsz-e új feladatot elvégezni? (y/n) ";
		cin >> valasz;
	} while (valasz == igen || valasz == IGEN);
	return 0;
}

unsigned short egyszerusites(short a, short b, short c, string allossz, string allapotossz)
{
	string seged = "";
	int sorossz = 0, seghossz = seged.length(), lep = 0, a1 = 0, ahossz = allossz.length();
	if (!allossz.empty())
	{
		seged = allapotossz[a];
		seged += allapotossz[c];
		seghossz = seged.length();
		while (lep < ahossz - 1 && (allossz[lep] != seged[a1] && allossz[lep + 1] != seged[a1 + 1]))
		{
			lep++;
		}
		if (allossz[lep] == seged[a1] && allossz[lep + 1] == seged[a1 + 1])
		{
			sorossz = 2;
		}
		else
		{
			for (short i = 0; i < seghossz; i++)
			{
				lep = 0;
				while (lep < ahossz - 1 && seged[i] != allossz[lep])
				{
					lep++;
				}
				if (seged[i] == allossz[lep])
				{
					sorossz++;
				}
				else
				{
					sorossz = 0;
					break;
				}
			}
		}
	}
	return sorossz;
}