/* ZADANIE nr 1 na SPOX - Grafowe Modelowanie System�w */
/* Bartosz Przesmycki  71103 */
/* wersja 1.0 */

//  Znajd� d�ugo�ci najkr�tszych �cie�ek od pierwszego wierzcho�ka digrafu przy pomocy algorytmu Bellmana - Forda
//
//  dane: V(G), E(g) //zbi�r wierzcho�k�w, zbi�r kraw�dzi grafu G
//	d[1..n] //tablica odleg�o�ci
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
	int lw;  // liczba wierzcho�k�w

	int graf[100][100];  //deklaracja tablicy dla grafu
	int d[100];			  //deklaracja tablicy dla wyniku iteracji

	cout << "Podaj liczbe grafow: " << endl;
	cin >> lg;  // wczytujemy pierwsz� zmienn�

	for (int i = 1; i <= lg; i++)
	{
		cout << endl;
		cout << "Podaj liczbe wierzcholkow: " << endl;
		cin >> lw;  // liczba wierzcho�k�w
		cout << endl;


		// wst�pne uzupe�nienie tablicy wyniku iteracji
		d[0] = 0;

		for (int x = 1; x < lw; x++)
		{
			d[x] = 999999;  // niesko�czono��
		}


		// uzupe�nienie tablicy z wagami kraw�dzi
		for (int y = 0; y < lw; y++)
		{
			for (int x = 0; x < lw; x++)
			{
				cin >> graf[x][y];
			}
		}


		// algorytm w�a�ciwy
		for (i = 1; i < lw; i++)  // I
		{
			for (int u = 0; u < lw; u++)  // II
			{
				for (int v = 0; v < lw; v++)
				{
					// if (graf[v][u] != 0)  // na razie wy��czamy
					if (d[u] + graf[v][u] < d[v])
						d[v] = d[u] + graf[v][u];

					// cout << endl;  // do debugowania
					// cout << "d[u]: " << d[u] << ", d[v]: " << d[v] << " , graf[u,v]: " << graf[u][v] << endl;

					// poni�ej wg tre�ci zadania, ale ja mam odwrotnie tablic�
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
