/*===========================================================================*/
/*                               ZADANIE 94                                  */  
/*===========================================================================*/

#include <stdio.h>

#define ILE 25 //maksymalna ilosc wierszy i kolumn

enum {false,true};

/*	Wypisuje informacje dla uzytkownika.
*/

void info(){
	printf("Program sprawdza czy wszystkie elementy tabeli ponizej glownej przekatnej sa zerami.\n");
	printf("Autor programu: Lukasz Lipski\n");
}

/*	Pobiera od uzytkownika int z podanego zakresu.
*	lewy - najmniejszy element spelniacjacy warunki
*	prawy - najwiekszy element spelniajacy warunki
*/

int wczytaj_int_zakres(int lewy, int prawy) {
	int liczba = 0; //wczytywana liczba
	while (scanf_s("%d", &liczba) != 1 || liczba < lewy || liczba > prawy || getchar() != '\n') {
		printf("Blad. Popraw: ");
		while (getchar() != '\n')
			;
	}
	return liczba;
}

/*	Pobiera od uzytkownika liczbe zmiennopozycyjna.
*/

double wczytaj_double(){
	double liczba = 0.0; //wczytywana liczba
	while(scanf_s("%lf",&liczba) != 1 || getchar() != '\n'){
		printf("Blad. Popraw: ");
		while(getchar() != '\n')
			;
	}
	return liczba;
}

/*	Pobiera od uzytkownika tablice typu double.
*	tab - wskaznik na tablice
*	n - liczba kolumn
*	m - liczba wierszy
*/

void wczytaj_tablica_2D(double tab[][ILE], int n, int m){
	for(int i = 0; i < n; ++i){
		for (int j = 0; j < m; ++j){
			printf("element[%d][%d] = ", i, j);
			tab[i][j] = wczytaj_double();
		}
	}
}

/*	Sprawdza czy wartosci ponizej glownej przekatnej sa zerami
*	tab - wskaznik na tablice
*	n - liczba kolumn i wierszy
*/

_Bool sprawdz_czy_zera(double tab[][ILE], int n){
	for (int i = 0; i < n; ++i){
		for (int j = i - 1; j >= 0; --j){
			if (tab[i][j] != 0){
				return false;
			}
		}
	}
	return true;
}

int main(){
	info();
	printf("\nPodaj dlugosc kolumny i wiersza tabeli: ");
	int n = 1; //ilosc wierszy i kolumn
	n = wczytaj_int_zakres(1, ILE);
	printf("\nPodaj tabele:\n");
	double tab[ILE][ILE] = { 0 }; //wczytane elementy
	wczytaj_tablica_2D(tab, n, n);
	if (sprawdz_czy_zera(tab, n))
		printf("\nWszystkie elementy lezace ponizej glownej przekatnej sa zerami.\n");
	else
		printf("\nNiewszystkie elementy lezace ponizej glownej przekatnej sa zerami.\n");
	printf("\nKoniec programu.\n");
	return 0;
}

/*===========================================================================*/
/*                               ZADANIE 95                                  */
/*===========================================================================*/


//#include <stdio.h>
//
//#define ILE 25 //maksymalna ilosc wierszy i kolumn
//
///*	Wypisuje informacje dla uzytkownika.
//*/
//
//void info(){
//	printf("Program zamienia ze soba 2 wiersze tabeli.\n");
//	printf("Autor programu: Lukasz Lipski\n");
//}
//
///*	Pobiera od uzytkownika int z podanego zakresu.
//*	lewy - najmniejszy element spelniacjacy warunki
//*	prawy - najwiekszy element spelniajacy warunki
//*/
//
//int wczytaj_int_zakres(int lewy, int prawy){
//	int liczba = 0; //wczytywana liczba
//	while(scanf_s("%d",&liczba) != 1 || liczba < lewy || liczba > prawy|| getchar() != '\n'){
//		printf("Blad. Popraw: ");
//		while(getchar() != '\n')
//			;
//	}
//	return liczba;
//}
//
///*	Pobiera od uzytkownika liczbe zmiennopozycyjna.
//*/
//
//double wczytaj_double(){
//	double liczba = 0.0; //wczytywana liczba
//	while(scanf_s("%lf",&liczba) != 1 || getchar() != '\n'){
//		printf("Blad. Popraw: ");
//		while(getchar() != '\n')
//			;
//	}
//	return liczba;
//}
//
///*	Pobiera od uzytkownika tablice typu double.
//*	tab - wskaznik na tablice
//*	n - dlugosc wiersza tabeli
//*	m - dlugosc kolumny tabeli
//*/
//
//void wczytaj_tablica_2D(double tab[][ILE], int n, int m){
//	for(int i = 0; i < n; ++i){
//		for (int j = 0; j < m; ++j){
//			printf("element[%d][%d] = ", i, j);
//			tab[i][j] = wczytaj_double();
//		}
//	}
//}
//
///*	Wypisuje przekazana tablice typu double.
//*	tab - wskaznik na tablice
//*	n - dlugosc wiersza tabeli
//*	m - dlugosc kolumny tabeli
//*/
//
//void wypisz_tablica_2D(double tab[][ILE], int n, int m) {
//	for (int i = 0; i < n; ++i) {
//		for (int j = 0; j < m; ++j) {
//			printf("%lg ", tab[i][j]);
//		}
//		putchar('\n');
//	}
//}
//
///*	Zamienia 2 wiersze tablicy typu double.
//*	tab - wskaznik na tablice
//*	n - dlugosc wiersza tabeli
//*	m - dlugosc kolumny tabeli
//*	wiersz1 - pierwszy z zamienianych wierszy
//*	wiersz2 - drugi z zamienianych wierszy
//*/
//
//void zamiana(double tab[][ILE], int n, int m, int wiersz1, int wiersz2) {
//	for (int i = 0; i < n; ++i) {
//		int pom = tab[wiersz1][i];
//		tab[wiersz1][i] = tab[wiersz2][i];
//		tab[wiersz2][i] = pom;
//	}
//}
//
//int main(){
//	info();
//	printf("\nPodaj dlugosc kolumny: ");
//	int n = 1; //ilosc elementow w wierszy i kolumn
//	n = wczytaj_int_zakres(1, ILE);
//	printf("\nPodaj dlugosc wiersza: ");
//	int m = 1; //ilosc elementow w wierszy i kolumn
//	m = wczytaj_int_zakres(1, ILE);
//	printf("\nPodaj tabele:\n");
//	double tab[ILE][ILE] = { 0 }; //wczytane elementy
//	wczytaj_tablica_2D(tab, n, m);
//	int wiersz1 = 0;//pierwszy z zamienianych wierszy
//	int wiersz2 = 0;//drugi z zamienianych wierszy
//	printf("\nPodaj indeks pierwszego wiersza do zamiany: ");
//	wiersz1 = wczytaj_int_zakres(0, ILE - 1);
//	printf("Podaj indeks drugiego wiersza do zamiany: ");
//	wiersz2 = wczytaj_int_zakres(0, ILE - 1);
//	printf("\nOto wczytana tablica:\n");
//	wypisz_tablica_2D(tab, n, m);
//	printf("\nOto tablica z zamienionymi wierszami %d i %d.\n", wiersz1, wiersz2);
//	zamiana(tab, n, m, wiersz1 - 1, wiersz2 - 1);
//	wypisz_tablica_2D(tab, n, m);
//	printf("\nKoniec programu.\n");
//	return 0;
//}


/*===========================================================================*/
/*                               ZADANIE 96                                  */
/*===========================================================================*/


//#include <stdio.h>
//
//#define ILE 25 //maksymalna ilosc wierszy i kolumn
//
///*	Wypisuje informacje dla uzytkownika.
//*/
//
//void info(){
//	printf("Program w tabeli o takiej samej liczbie wierszy co kolumn, zamienia wiersz z kolumna, na przeciêciu których jest maksimum g³ównej przek¹tnej.\n");
//	printf("Autor programu: Lukasz Lipski\n");
//}
//
///*	Pobiera od uzytkownika int z podanego zakresu.
//*	lewy - najmniejszy element spelniacjacy warunki
//*	prawy - najwiekszy element spelniajacy warunki
//*	return liczba - pobierana liczba
//*/
//
//int wczytaj_int_zakres(int lewy, int prawy){
//	int liczba = 0; //wczytywana liczba
//	while(scanf_s("%d",&liczba) != 1 || liczba < lewy || liczba > prawy|| getchar() != '\n'){
//		printf("Blad. Popraw: ");
//		while(getchar() != '\n')
//			;
//	}
//	return liczba;
//}
//
///*	Pobiera od uzytkownika liczbe zmiennopozycyjna.
//*	return liczba - pobierana liczba
//*/
//
//double wczytaj_double(){
//	double liczba = 0.0; //wczytywana liczba
//	while(scanf_s("%lf",&liczba) != 1 || getchar() != '\n'){
//		printf("Blad. Popraw: ");
//		while(getchar() != '\n')
//			;
//	}
//	return liczba;
//}
//
///*	Pobiera od uzytkownika tablice typu double.
//*	tab - wskaznik na tablice
//*	n - dlugosc wiersza tabeli
//*	m - dlugosc kolumny tabeli
//*/
//
//void wczytaj_tablica_2D(double tab[][ILE], int n, int m){
//	for(int i = 0; i < n; ++i){
//		for (int j = 0; j < m; ++j){
//			printf("element[%d][%d] = ", i, j);
//			tab[i][j] = wczytaj_double();
//		}
//	}
//}
//
///*	Wypisuje przekazana tablice typu double.
//*	tab - wskaznik na tablice
//*	n - dlugosc wiersza tabeli
//*	m - dlugosc kolumny tabeli
//*/
//
//void wypisz_tablica_2D(double tab[][ILE], int n, int m) {
//	for (int i = 0; i < n; ++i) {
//		for (int j = 0; j < m; ++j) {
//			printf("%lg ", tab[i][j]);
//		}
//		putchar('\n');
//	}
//}
//
///*	Zanjduje pozycje najwiekszej wartosci na glownej przekatnej.
//*	tab - wskaznik na tablice
//*	n - dlugosc wiersza i kolumny tabeli
//*	return poz - pozycja maksimum na glownej przekatnej
//*/
//
//int znajdz_poz_maksimum(double tab[][ILE], int n) {
//	double maks = tab[0][0]; //maksimum
//	int poz = 0; //pozycja maksimum
//	for (int i = 1; i < n; ++i) {
//		if (tab[i][i] > maks) {
//			maks = tab[i][i];
//			poz = i;
//		}
//	}
//	return poz;
//}
//
///*	Zamienia wiersz z kolumna tablicy typu double o tej samej ilosci kolumn i wierszy.
//*	tab - wskaznik na tablice
//*	n - dlugosc wiersza i kolumny tabeli
//*	poz - pozycja 
//*/
//
//void zamiana(double tab[][ILE], int n, int poz) {
//	for (int i = 0; i < n; ++i) {
//		int pom = tab[poz][i];
//		tab[poz][i] = tab[i][poz];
//		tab[i][poz] = pom;
//	}
//}
//
//int main(){
//	info();
//	printf("\nPodaj dlugosc kolumny i wiersza: ");
//	int n = 1; //ilosc elementow w wierszy i kolumn
//	n = wczytaj_int_zakres(1, ILE);
//	printf("\nPodaj tabele:\n");
//	double tab[ILE][ILE] = { 0 }; //wczytane elementy
//	wczytaj_tablica_2D(tab, n, n);
//	printf("\nOto wczytana tablica:\n");
//	wypisz_tablica_2D(tab, n, n);
//	int poz = znajdz_poz_maksimum(tab, n);
//	printf("\nOto tablica z zamienionymi wierszami i kolumnami o indeksie: %d.\n", poz+1);
//	zamiana(tab, n, poz);
//	wypisz_tablica_2D(tab, n, n);
//	printf("\nKoniec programu.\n");
//	return 0;
//}


/*===========================================================================*/
/*                               ZADANIE 97                                  */
/*===========================================================================*/


//#include <stdio.h>
//
//#define ILE 25 //maksymalna ilosc wierszy i kolumn
//
///*	Wypisuje informacje dla uzytkownika.
//*/
//
//void info() {
//	printf("Program pobiera dwie tabele dwuwymiarowe o tych samych wymiarach i zwraca tablice bedaca efektem zsumowania elementow z tablic o tych samych indeksach.\n");
//	printf("Autor programu: Lukasz Lipski\n");
//}
//
///*	Pobiera od uzytkownika int z podanego zakresu.
//*	lewy - najmniejszy element spelniacjacy warunki
//*	prawy - najwiekszy element spelniajacy warunki
//*	return liczba - pobierana liczba
//*/
//
//int wczytaj_int_zakres(int lewy, int prawy) {
//	int liczba = 0; //wczytywana liczba
//	while (scanf_s("%d", &liczba) != 1 || liczba < lewy || liczba > prawy || getchar() != '\n') {
//		printf("Blad. Popraw: ");
//		while (getchar() != '\n')
//			;
//	}
//	return liczba;
//}
//
///*	Pobiera od uzytkownika liczbe zmiennopozycyjna.
//*	return liczba - pobierana liczba
//*/
//
//double wczytaj_double() {
//	double liczba = 0.0; //wczytywana liczba
//	while (scanf_s("%lf", &liczba) != 1 || getchar() != '\n') {
//		printf("Blad. Popraw: ");
//		while (getchar() != '\n')
//			;
//	}
//	return liczba;
//}
//
///*	Pobiera od uzytkownika tablice typu double.
//*	tab - wskaznik na tablice
//*	n - dlugosc wiersza tabeli
//*	m - dlugosc kolumny tabeli
//*/
//
//void wczytaj_tablica_2D(double tab[][ILE], int n, int m) {
//	for (int i = 0; i < n; ++i) {
//		for (int j = 0; j < m; ++j) {
//			printf("element[%d][%d] = ", i, j);
//			tab[i][j] = wczytaj_double();
//		}
//	}
//}
//
///*	Wypisuje przekazana tablice typu double.
//*	tab - wskaznik na tablice
//*	n - dlugosc wiersza tabeli
//*	m - dlugosc kolumny tabeli
//*/
//
//void wypisz_tablica_2D(double tab[][ILE], int n, int m) {
//	for (int i = 0; i < n; ++i) {
//		for (int j = 0; j < m; ++j) {
//			printf("%lg ", tab[i][j]);
//		}
//		putchar('\n');
//	}
//}
//
///*	Liczy sume elementow tabel 2D (a,b) o rownych indeksach i o tych samych wymiarach
//*	a - wskaznik na tablice a
//*	b - wskaznik na tablice b
//*	c - wskaznik na tablice c (sumujaca)
//*	n - dlugosc wiersza tabeli
//*	m - dlugosc kolumny tabeli
//*/
//
//void licz_suma(double a[][ILE], double b[][ILE], double c[][ILE], int n, int m) {
//	for (int i = 0; i < n; ++i) {
//		for (int j = 0; j < m; ++j) {
//			c[i][j] = a[i][j] + b[i][j];
//		}
//	}
//}
//
//int main() {
//	info();
//	printf("\nPodaj dlugosc wiersza tabel: ");
//	int n = 1; //ilosc elementow w kolumn
//	n = wczytaj_int_zakres(1, ILE);
//	printf("\nPodaj dlugosc kolumny tabel: ");
//	int m = 1; //ilosc elementow w wierszy
//	m = wczytaj_int_zakres(1, ILE);
//	printf("\nPodaj tabele a:\n");
//	double a[ILE][ILE] = { 0 }; //wczytana tablela a
//	double b[ILE][ILE] = { 0 }; //wczytana tabela b
//	printf("\nPodaj tabele a:\n");
//	wczytaj_tablica_2D(a, n, m);
//	printf("\nPodaj tabele b:\n");
//	wczytaj_tablica_2D(b, n, m);
//	printf("\nOto wczytana tablela a:\n");
//	wypisz_tablica_2D(a, n, m);
//	printf("\nOto wczytana tablela b:\n");
//	wypisz_tablica_2D(b, n, m);
//	printf("\nOto tablica c z sumowanymi elementami:\n");
//	double c[ILE][ILE] = { 0 }; //obliczana tabela c
//	licz_suma(a, b, c, n, m);
//	wypisz_tablica_2D(c, n, m);
//	printf("\nKoniec programu.\n");
//	return 0;
//}


/*===========================================================================*/
/*                               ZADANIE 98                                  */
/*===========================================================================*/


//#include <stdio.h>
//
//#define ILE 25 //maksymalna ilosc wierszy i kolumn
//
///*	Wypisuje informacje dla uzytkownika.
//*/
//
//void info() {
//	printf("Program wykonuje operacje mnozenia macierzy a i b. Tabela a ma ta sama ilosc kolumn co tabela b wierszy.\n");
//	printf("Autor programu: Lukasz Lipski\n");
//}
//
///*	Pobiera od uzytkownika int z podanego zakresu.
//*	lewy - najmniejszy element spelniacjacy warunki
//*	prawy - najwiekszy element spelniajacy warunki
//*	return liczba - pobierana liczba
//*/
//
//int wczytaj_int_zakres(int lewy, int prawy) {
//	int liczba = 0; //wczytywana liczba
//	while (scanf_s("%d", &liczba) != 1 || liczba < lewy || liczba > prawy || getchar() != '\n') {
//		printf("Blad. Popraw: ");
//		while (getchar() != '\n')
//			;
//	}
//	return liczba;
//}
//
///*	Pobiera od uzytkownika liczbe zmiennopozycyjna.
//*	return liczba - pobierana liczba
//*/
//
//double wczytaj_double() {
//	double liczba = 0.0; //wczytywana liczba
//	while (scanf_s("%lf", &liczba) != 1 || getchar() != '\n') {
//		printf("Blad. Popraw: ");
//		while (getchar() != '\n')
//			;
//	}
//	return liczba;
//}
//
///*	Pobiera od uzytkownika tablice typu double.
//*	tab - wskaznik na tablice
//*	n - dlugosc wiersza tabeli
//*	m - dlugosc kolumny tabeli
//*/
//
//void wczytaj_tablica_2D(double tab[][ILE], int n, int m) {
//	for (int i = 0; i < n; ++i) {
//		for (int j = 0; j < m; ++j) {
//			printf("element[%d][%d] = ", i, j);
//			tab[i][j] = wczytaj_double();
//		}
//	}
//}
//
///*	Wypisuje przekazana tablice typu double.
//*	tab - wskaznik na tablice
//*	n - dlugosc wiersza tabeli
//*	m - dlugosc kolumny tabeli
//*/
//
//void wypisz_tablica_2D(double tab[][ILE], int n, int m) {
//	for (int i = 0; i < n; ++i) {
//		for (int j = 0; j < m; ++j) {
//			printf("%lg ", tab[i][j]);
//		}
//		putchar('\n');
//	}
//}
//
///*	Liczy iloczyn macierzy tabel 2D (a,b)
//*	a - wskaznik na tablice a
//*	b - wskaznik na tablice b
//*	c - wskaznik na tablice c
//*	n - ilosc kolumn tabeli a i wierszy tabeli b
//*	m - ilosc wierszy tabeli a
//*	k - ilosc wierszy tabeli b
//*/
//
//void licz_macierz(double a[][ILE], double b[][ILE], double c[][ILE], int n, int m, int k) {
//	for (int i = 0; i < m; ++i) {
//		for (int j = 0; j < k; ++j) {
//			c[i][j] = 0;
//			for (int h = 0; h < n; ++h) {
//				c[i][j] += a[i][h] * b[h][j];
//			}
//		}
//	}
//}
//
//int main() {
//	info();
//	printf("\nPodaj ilosc kolumn tabeli a i ilosc wierszy tabeli b: ");
//	int n = 1; //ilosc kolumn tabeli a i wierszy tabeli b
//	n = wczytaj_int_zakres(1, ILE);
//	printf("\nPodaj ilosc kolumn tabeli a: ");
//	int m = 1; //ilosc wierszy tabeli a
//	m = wczytaj_int_zakres(1, ILE);
//	printf("\nPodaj ilosc wierszy tabeli b: ");
//	int k = 1; //ilosc wierszy tabeli b
//	k = wczytaj_int_zakres(1, ILE);
//	printf("\nPodaj tabele a:\n");
//	double a[ILE][ILE] = { 0 }; //wczytana tablela a
//	double b[ILE][ILE] = { 0 }; //wczytana tabela b
//	printf("\nPodaj tabele a:\n");
//	wczytaj_tablica_2D(a, n, m);
//	printf("\nPodaj tabele b:\n");
//	wczytaj_tablica_2D(b, n, m);
//	printf("\nOto wczytana tablela a:\n");
//	wypisz_tablica_2D(a, n, m);
//	printf("\nOto wczytana tablela b:\n");
//	wypisz_tablica_2D(b, n, m);
//	printf("\nOto tablica c otrzymana po mnozeniu macierzy a i b:\n");
//	double c[ILE][ILE] = { 0 }; //obliczana tabela c
//	licz_macierz(a, b, c, n, m, k);
//	wypisz_tablica_2D(c, m, k);
//	printf("\nKoniec programu.\n");
//	return 0;
//}


/*===========================================================================*/
/*                               ZADANIE 99                                  */
/*===========================================================================*/


//#include <stdio.h>
//
//#define ILE 25 //maksymalna ilosc wierszy i kolumn
//
///*	Wypisuje informacje dla uzytkownika.
//*/
//
//void info() {
//	printf("Program oblicza maksimum z sum elementow z wierszy podanej tablicy.\n");
//	printf("Autor programu: Lukasz Lipski\n");
//}
//
///*	Pobiera od uzytkownika int z podanego zakresu.
//*	lewy - najmniejszy element spelniacjacy warunki
//*	prawy - najwiekszy element spelniajacy warunki
//*	return liczba - pobierana liczba
//*/
//
//int wczytaj_int_zakres(int lewy, int prawy) {
//	int liczba = 0; //wczytywana liczba
//	while (scanf_s("%d", &liczba) != 1 || liczba < lewy || liczba > prawy || getchar() != '\n') {
//		printf("Blad. Popraw: ");
//		while (getchar() != '\n')
//			;
//	}
//	return liczba;
//}
//
///*	Pobiera od uzytkownika liczbe zmiennopozycyjna.
//*	return liczba - pobierana liczba
//*/
//
//double wczytaj_double() {
//	double liczba = 0.0; //wczytywana liczba
//	while (scanf_s("%lf", &liczba) != 1 || getchar() != '\n') {
//		printf("Blad. Popraw: ");
//		while (getchar() != '\n')
//			;
//	}
//	return liczba;
//}
//
///*	Pobiera od uzytkownika tablice typu double.
//*	tab - wskaznik na tablice
//*	n - dlugosc wiersza tabeli
//*	m - dlugosc kolumny tabeli
//*/
//
//void wczytaj_tablica_2D(double tab[][ILE], int m, int n) {
//	for (int i = 0; i < m; ++i) {
//		for (int j = 0; j < n; ++j) {
//			printf("element[%d][%d] = ", i, j);
//			tab[i][j] = wczytaj_double();
//		}
//	}
//}
//
///*	Wypisuje przekazana tablice typu double.
//*	tab - wskaznik na tablice
//*	n - dlugosc wiersza tabeli
//*	m - dlugosc kolumny tabeli
//*/
//
//void wypisz_tablica_2D(double tab[][ILE], int m, int n) {
//	for (int i = 0; i < m; ++i) {
//		for (int j = 0; j < n; ++j) {
//			printf("%lg ", tab[i][j]);
//		}
//		putchar('\n');
//	}
//}
//
///*	Oblicza modul z podanej liczby zmiennopozycyjnej
//*	liczba - podana liczba
//*/
//
//double modul(double liczba) {
//	if (liczba < 0)
//		return liczba * (-1);
//	return liczba;
//}
//
///*	Oblicza maksimum z sumy elementow z wierszy tablicy
//*	tab - wskaznik na tablice
//*	m - ilosc wierszy
//*	n - ilosc kolumn
//*/
//
//double licz_maksimum(double tab[][ILE], int m, int n) {
//	double maks = 0.0; //maksymalana suma
//	for (int i = 0; i < m; ++i) {
//		double suma = 0.0; //obliczana suma
//		for (int j = 0; j < n; ++j) {
//			suma += modul(tab[i][j]);
//		}
//		if (suma > maks) {
//			maks = suma;
//		}
//	}
//	return maks;
//}
//
//int main() {
//	info();
//	printf("\nPodaj ilosc kolumn tabeli: ");
//	int n = 1; //ilosc kolumn tabeli
//	n = wczytaj_int_zakres(1, ILE);
//	printf("\nPodaj ilosc wierszy tabeli: ");
//	int m = 1; //ilosc wierszy tabeli
//	m = wczytaj_int_zakres(1, ILE);
//	printf("\nPodaj tabele:\n");
//	double tab[ILE][ILE] = { 0 }; //wczytana tablela
//	wczytaj_tablica_2D(tab, m, n);
//	printf("\nOto wczytana tablela:\n");
//	wypisz_tablica_2D(tab, m, n);
//	double maks = licz_maksimum(tab, m, n);
//	printf("Oto obliczane maksimum: %lg\n", maks);
//	printf("\nKoniec programu.\n");
//	return 0;
//}


/*===========================================================================*/
/*                               ZADANIE 100                                 */
/*===========================================================================*/


//#include <stdio.h>
//#include <math.h>
//
//#define ILE 25 //maksymalna ilosc wierszy i kolumn
//
///*	Wypisuje informacje dla uzytkownika.
//*/
//
//void info() {
//	printf("Program oblicza wyrazenia dla podanej tablicy.\n");
//	printf("Autor programu: Lukasz Lipski\n");
//}
//
///*	Pobiera od uzytkownika int z podanego zakresu.
//*	lewy - najmniejszy element spelniacjacy warunki
//*	prawy - najwiekszy element spelniajacy warunki
//*	return liczba - pobierana liczba
//*/
//
//int wczytaj_int_zakres(int lewy, int prawy) {
//	int liczba = 0; //wczytywana liczba
//	while (scanf_s("%d", &liczba) != 1 || liczba < lewy || liczba > prawy || getchar() != '\n') {
//		printf("Blad. Popraw: ");
//		while (getchar() != '\n')
//			;
//	}
//	return liczba;
//}
//
///*	Pobiera od uzytkownika liczbe zmiennopozycyjna.
//*	return liczba - pobierana liczba
//*/
//
//double wczytaj_double() {
//	double liczba = 0.0; //wczytywana liczba
//	while (scanf_s("%lf", &liczba) != 1 || getchar() != '\n') {
//		printf("Blad. Popraw: ");
//		while (getchar() != '\n')
//			;
//	}
//	return liczba;
//}
//
///*	Pobiera od uzytkownika tablice typu double.
//*	tab - wskaznik na tablice
//*	n - dlugosc wiersza tabeli
//*	m - dlugosc kolumny tabeli
//*/
//
//void wczytaj_tablica_2D(double tab[][ILE], int m, int n) {
//	for (int i = 0; i < m; ++i) {
//		for (int j = 0; j < n; ++j) {
//			printf("element[%d][%d] = ", i, j);
//			tab[i][j] = wczytaj_double();
//		}
//	}
//}
//
///*	Wypisuje przekazana tablice typu double.
//*	tab - wskaznik na tablice
//*	n - dlugosc wiersza tabeli
//*	m - dlugosc kolumny tabeli
//*/
//
//void wypisz_tablica_2D(double tab[][ILE], int m, int n) {
//	for (int i = 0; i < m; ++i) {
//		for (int j = 0; j < n; ++j) {
//			printf("%lg ", tab[i][j]);
//		}
//		putchar('\n');
//	}
//}
//
///*	Oblicza modul z podanej liczby zmiennopozycyjnej
//*	liczba - podana liczba
//*/
//
//double modul(double liczba) {
//	if (liczba < 0)
//		return liczba * (-1);
//	return liczba;
//}
//
///*	Oblicza wartosc wyrazenia
//*	tab - wskaznik na tablice
//*	m - ilosc wierszy
//*	n - ilosc kolumn
//*/
//
//double licz_wyrazenie(double tab[][ILE], int m, int n) {
//	double wynik = 0.0; //wynik wyrazenia
//	for (int i = 0; i < m; ++i) {
//		for (int j = 0; j < n; ++j) {
//			wynik += tab[i][j] * tab[i][j];
//		}
//		
//	}
//	wynik = sqrt(wynik);
//	return wynik;
//}
//
//int main() {
//	info();
//	printf("\nPodaj ilosc kolumn tabeli: ");
//	int n = 1; //ilosc kolumn tabeli
//	n = wczytaj_int_zakres(1, ILE);
//	printf("\nPodaj ilosc wierszy tabeli: ");
//	int m = 1; //ilosc wierszy tabeli
//	m = wczytaj_int_zakres(1, ILE);
//	printf("\nPodaj tabele:\n");
//	double tab[ILE][ILE] = { 0 }; //wczytana tablela
//	wczytaj_tablica_2D(tab, m, n);
//	printf("\nOto wczytana tablela:\n");
//	wypisz_tablica_2D(tab, m, n);
//	double wartosc = licz_wyrazenie(tab, m, n);
//	printf("\nOto wartosc wyrazenia: %lg\n", wartosc);
//	printf("\nKoniec programu.\n");
//	return 0;
//}

