/* ZADANIE nr 1 na SPOX - Grafowe Modelowanie Systemów */
/* Bartosz Przesmycki  71103 */
/* wersja 1.0 */

//  ZnajdŸ d³ugoœci najkrótszych œcie¿ek od pierwszego wierzcho³ka digrafu przy pomocy algorytmu Bellmana - Forda
//
//  dane: V(G), E(g) //zbiór wierzcho³ków, zbiór krawêdzi grafu G
//	d[1..n] //tablica odleg³oœci
//	d[0] = 0;
//	  foreach(v in V(G) / v0)
//		  d[v] = +inf;
//	  for (i = 1; i< n; i++) // I
//		  foreach((u, v) in E(G)) // II
//		  if (d[u] + waga((u, v)) < d[v])
//			  d[v] = d[u] + waga((u, v));

#include <iostream>
using namespace std;


int main()
{
	int lg;  // liczba grafow
	int lw;  // liczba wierzcho³ków

	int graf[100][100];  //deklaracja tablicy dla grafu
	int d[100];			  //deklaracja tablicy dla wyniku iteracji

	cout << "Podaj liczbe grafow: " << endl;
	cin >> lg;  // wczytujemy pierwsz¹ zmienn¹

	for (int i = 1; i <= lg; i++)
	{
		cout << endl;
		cout << "Podaj liczbe wierzcholkow: " << endl;
		cin >> lw;  // liczba wierzcho³ków
		cout << endl;


		// wstêpne uzupe³nienie tablicy wyniku iteracji
		d[0] = 0;

		for (int x = 1; x < lw; x++)
		{
			d[x] = 999999;  // nieskoñczonoœæ
		}


		// uzupe³nienie tablicy z wagami krawêdzi
		for (int y = 0; y < lw; y++)
		{
			for (int x = 0; x < lw; x++)
			{
				cin >> graf[x][y];
			}
		}


		// algorytm w³aœciwy
		for (i = 1; i < lw; i++)  // I
		{
			for (int u = 0; u < lw; u++)  // II
			{
				for (int v = 0; v < lw; v++)
				{
					// if (graf[v][u] != 0)  // na razie wy³¹czamy
					if (d[u] + graf[v][u] < d[v])
						d[v] = d[u] + graf[v][u];

					// cout << endl;  // do debugowania
					// cout << "d[u]: " << d[u] << ", d[v]: " << d[v] << " , graf[u,v]: " << graf[u][v] << endl;

					// poni¿ej wg treœci zadania, ale ja mam odwrotnie tablicê
					// if (d[u] + waga((u, v)) < d[v])
					//   d[v] = d[u] + waga((u, v));
				}
			}

			//  wypisanie wyniku
			cout << endl;
			for (int x = 0; x < lw; x++)
			{
				if (d[x] == 999999) 
					cout << 0 << " ";
				else
					cout << d[x] << " ";
			}
		}

		//  wypisanie wyniku
		cout << endl;
		cout << "Dla sprawdzenia - tablica wejsciowa:" << endl;

		for (int y = 0; y < lw; y++)
		{
			for (int x = 0; x < lw; x++)
			{
				cout << graf[x][y] << " ";
			}

			cout << endl;
		}
	}

	system("pause");

	return 0;
}
