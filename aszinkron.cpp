#include <iostream>
#include <math.h>
#include <string>
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

int main(int argc, char* argv[])
{
	unsigned short negdb = 0, oszlop = 6, neghely[2] = {};
	double lavdb = 1;
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

		cout << "\tLesz-e negáció a LÉNYEGES állapotváltozásban? (y/n)\t";
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
		system("cls");
		cout << "Aszinkron sorrendi hálózat tervezése\n"
			<< "(Create by Nagypál Márton)\n\n"
			<< "\tLényeges állapot változások:\n\t(Értelmezés = X1, X2, Z)\n\n";
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
		string nulla = "0", egy = "1";
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

		cout << "\n\n\tÁllapot táblázat\n\n"
			<< "\ty\\x1x2\t00\t01\t11\t10\n\t";
		//táblázat kiírása
		for (unsigned short a = 0; a < 35; a++)
		{
			cout << "=";
		}
		cout << endl;
		for (unsigned short a = 0; a < 8; a++)
		{
			cout << "\t  " << abc[a];
			for (unsigned short ab = 0; a < hossz; ab = ab + teljestasoszlop)
			{
				if (abc[a] == allapotsor[ab])
				{
					cout << "\t" << allapotsor[ab + 1] << allapotsor[ab + 2] << "\t" << allapotsor[ab + 3] << allapotsor[ab + 4] << "\t" << allapotsor[ab + 5] << allapotsor[ab + 6] << "\t" << allapotsor[ab + 7] << allapotsor[ab + 8] << "\n\n";
					break;
				}
			}
		}
		cout << "\n\tLépcsős egyszerűsítési tábla\n\n";
		string lepcsos;
		//sorok összehasonlítása
		for (unsigned short a = 1; a < hossz - 18; a += teljestasoszlop)
		{
			unsigned short c = a, c1 = 0, osszevon = 0;
			//cout << "\nSorszám: " << c - 1 << "\n";
			for (unsigned short b = a + 9; b < hossz - 1; b += 2)
			{
				if (allapotsor[b] == abc[b / 9] && b % 9 == 0)
				{
					b += 1;
				}
				else if (b % 9 == 0)
				{
					b += 1;
				}
				//Egymás alatti sorok összehasonlítása
				if ((allapotsor[c] == allapotsor[b] && allapotsor[c + 1] == allapotsor[b + 1]) || (allapotsor[c] == allapotsor[b] && allapotsor[b + 1] == 'X') || (allapotsor[c] == allapotsor[b] && allapotsor[c + 1] == 'X') || allapotsor[b] == 'X' || allapotsor[c] == 'X') //Összevonható-e
				{
					osszevon++;
				}
				else
				{
					c1 = 0;
					continue;
				}
				c += 2;
				c1++;
				if (c1 == 4)
				{
					c = a;
					c1 = 0;
					if (osszevon % 4 == 0)
					{
						lepcsos += allapotsor[c];//FOR ciklussal feltölteni
							//cout << "\n\tA(z) " << abc[a / 9] << " sor összevonható a(z) " << abc[b / 9] << " sorral.\n";
					}
					else
					{
						cout << endl;
					}
				}
			}
			cout << endl;
		}
		//kiírattatása
		cout << "\n";
		for (short a = 1; a < 8; a++)
		{
			cout << "\t" << abc[a] << "\n\n";
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
		for (short a = 0; a < 7; a++)
		{
			cout << "\t";
			for (short b = a + 1; b < 8; b++)
			{
				cout << abc[b];
			}
			if (a < 6)
			{
				cout << endl;
			}
		}
		//ha 4 állapotot tudunk összevonni, akkor ABCD; esetleg ki is lehetne írattatni a 4et, pl.: A (ab)\tB (cde)...
		string ABCD = "ABCD", ABCD1 = "A00B01C11D10";
		cout << "\n\n\tÖsszevont állapottáblázat\n\n";
		cout << "\n\n\tÁllapotok kódolása\n\n";
		for (unsigned short a = 0; a < 12; a += 3)
		{
			cout << "\t\t" << ABCD1[a] << " -> " << ABCD1[a + 1] << ABCD1[a + 2] << endl;
		}
		cout << "\n\tKódolt Állapottábla felírása\n\n\t\ta) DIREKT BEKÖTÉSI\n\n\t\tb) TÁROLÓS\n\n";
		cout << "\nA táblázatok alapján rajzold meg a DIREKT BEKÖTÉSI és a TÁROLÓS aszinkron hálózatot!\n\nAkarsz-e új feladatot elvégezni? (y/n) ";
		cin >> valasz;
	} while (valasz == igen || valasz == IGEN);
	return 0;
}