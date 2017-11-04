// Wycieczka_v1.cpp : Problem plecakowy dla jednego plecaka na razie.
//

#include <iostream>

using namespace std;

int main() {

	double ua = 0; // udŸwig plecaka Ani
	double ub = 0; // udŸwig plecaka Bartka
	double w = 0; // waga aktualnego przedmiotu
	int n = 0; // liczba przedmiotów
	int x = 0, y = 0; // wymiary tablicy
	int c = 0; // cena aktualnego przedmiotu
	int a = 0; // cena aktualnego predmiotu
	int p = 0; // poprzednia wartoœæ max
	int skok = 0;
	int i = 0, j = 0; // aktualne wspó³rzêdne na tablicy

	cout << "Podaj udzwig plecaka Ani: ";
	cin >> ua;
	cout << "\nPodaj udzwig plecaka Bartka: ";
	cin >> ub;
	cout << "\nPodaj liczbe przedmiotow: ";
	cin >> n;

	x = ua * 10 + 1;
	y = n + 1;
	cout << "\n x = " << x << ", y = " << y;

	double *tablica_A;
	tablica_A = new double[x, y];

	for (i = 0; j = x; i++) {
		tablica_A[i, 0] = 0;
	}

	for (j = 0; j = y; j++) {
		tablica_A[0, j] = 0;
	}

	for (j = 1; j = n; j++) {
		cout << "\nPodaj wage przedmiotu nr " << j << ": ";
		cin >> w;
		cout << "\nPodaj cene przedmiotu nr " << j << ": ";
		cin >> c;
		for (i = 1; i < x; i++) {
			p = tablica_A[i, j - 1];
			skok = w * 10;
			a = c + tablica_A[i - skok, j - 1];
			if (p > a) tablica_A[i, j] = p;
			else tablica_A[i, j] = a;
		}
	}

	cout << "Wynik koncowy: " << tablica_A[x, y];

	system("pause");

	return 0;
}

