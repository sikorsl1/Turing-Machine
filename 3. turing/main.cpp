#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

void wczyt(int *m, int *n) {
	cout << " Maszyna Turinga obliczajaca roznice wlasciwa." << endl;
	cout << " Postac MT M = ({q0,q1,q2,q3,q4,q5,q6},{0,1},{0,1,B},delta,q0,B,0)" << endl;
	cout << "Podaj liczbe calkowita m" << endl;
	cin >> *m;
	cout << "Podaj liczbe calkowita n" << endl;
	cin >> *n;

}



int main()
{
	int m, n,q;
	wczyt(&m, &n);

	if (m < n)
	{
		cout << "Liczba m musi byc wieksza od n" << endl;
		getchar(); getchar();
		exit(1);
	}

	int tur[7][3][3] = {
	{ { 1, 2 , 1},{ 5, 2, 1 },{ 0, 0, 0 } },
	{ { 1, 0 , 1},{ 2, 1, 1 },{ 0, 0, 0 } },
	{ { 3, 1, -1 },{ 2, 1, 1 },{ 4, 2, -1} },
	{ { 3, 0, -1 },{ 3, 1, -1 },{ 0, 2, 1} },
	{ { 4, 0, -1 },{ 4, 2, -1 },{ 6, 0, 1} },
	{ { 5, 2, 1 },{ 5, 2, 1 },{ 6, 2, 1 } },
	{ { 0, 0, 0 },{ 0, 0, 0 },{ 0, 0, 0 } }
	};

	int tasma[10000];
	tasma[0] = 2;

	for (int i = 1; i <= m; i++)
	{
		tasma[i] = 0;
	}
	tasma[m + 1] = 1;
	for (int j = m + 2; j < m + n + 2; j++)
	{
		tasma[j] = 0;
	}
	tasma[m + n + 2] = 2;
	tasma[m + n + 3] = 2;
	for (int i = 0; i <= m + n + 2; i++)
	{
		cout << tasma[i];

	}
	cout << endl;
	int stan = 0;
	int pozycja = 1;
	int x = tasma[pozycja];
	while (stan != 6)
	{

		if (stan == 0 && tasma[pozycja] == 2)
			break;
		if (stan == 1 && tasma[pozycja] == 2)
			break;
		int stanp = stan;
		int x = tasma[pozycja];
		tasma[pozycja] = tur[stan][x][1];
		stan = tur[stanp][x][0];
		pozycja += tur[stanp][x][2];
		//cout << "q" << stan << endl;
		for (int i = 0; i <m+n+3; i++)
		{
			/*
			if ( i == pozycja - 1) {
				cout << "q" << stan;
			}
			*/
			cout << tasma[i];

		}

		cout << endl;
	}
	int licznik = 0;
	for (int i = 0; i < m + n + 2; i++) {
		if (tasma[i] == 0)
		{
			licznik++;
		}

	}

	cout << licznik << endl;
	system("pause");

	return 0;
}
