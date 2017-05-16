#include <iostream>
#include "conio2.h"
#include<ctime>
#include <istream>
#include <fstream>
#include <string>
#define kol 5			//wspolrzedna poczatkowa do umieszczania planszy sudoku,   przemieszcza sie w poziomie
#define wier 5			//wspolrzedna poczatkowa do umieszczania planszy sudoku,   przemieszcza sie w pionie
#define blkol 2			//wspolrzedna komunikatu z bledem
#define blwier 2		//wspolrzedna komunikatu z bledem
#define komx 35			//wspolrzedna x panelu info
#define komy 5			//wspolrzedna y panelu info
clock_t start;

using namespace std;
bool blad=false;		//do sprawdzania w tablicy 3x3 w wpisywaniu

void wpiszSpacje(int komorka[9][9])				//zapelnia na poczatku wszystkie elementy tablicy spacjami
{
	for (int i = 0; i < 9; i++)
	{
		for (int p = 0; p < 9; p++)
		{komorka[i][p] =(char) 32;}	
	}
}

void rysuj()			//rysowanie planszy sudoku w punkcie kol,wier
{
	gotoxy(kol, wier);
	cout << (char)201 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)203
		<< (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)203
		<< (char)205 << (char)205 << (char)205 << (char)205 << (char)205<< (char)187;

	gotoxy(kol, wier+1);
	cout << (char)186 << (char)NULL << (char)179<< (char)NULL << (char)179 << (char)NULL << (char)186
		<< (char)NULL << (char)179 << (char)NULL << (char)179 << (char)NULL << (char)186
		<< (char)NULL << (char)179 << (char)NULL << (char)179 << (char)NULL << (char)186;


	gotoxy(kol, wier + 2);
	cout << (char)186 << (char)196 << (char)197 << (char)196 << (char)197 << (char)196 << (char)186
		<< (char)196 << (char)197 << (char)196 << (char)197 << (char)196 << (char)186
		<< (char)196 << (char)197 << (char)196 << (char)197 << (char)196 << (char)186;

	gotoxy(kol, wier + 3);
	cout << (char)186 << (char)NULL << (char)179 << (char)NULL << (char)179 << (char)NULL << (char)186
		<< (char)NULL << (char)179 << (char)NULL << (char)179 << (char)NULL << (char)186
		<< (char)NULL << (char)179 << (char)NULL << (char)179 << (char)NULL << (char)186;

	gotoxy(kol, wier + 4);
	cout << (char)186 << (char)196 << (char)197 << (char)196 << (char)197 << (char)196 << (char)186
		<< (char)196 << (char)197 << (char)196 << (char)197 << (char)196 << (char)186
		<< (char)196 << (char)197 << (char)196 << (char)197 << (char)196 << (char)186;

	gotoxy(kol, wier + 5);
	cout << (char)186 << (char)NULL << (char)179 << (char)NULL << (char)179 << (char)NULL << (char)186
		<< (char)NULL << (char)179 << (char)NULL << (char)179 << (char)NULL << (char)186
		<< (char)NULL << (char)179 << (char)NULL << (char)179 << (char)NULL << (char)186;

	gotoxy(kol, wier + 6);
	cout << (char)204 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)206
		<< (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)206
		<< (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)185;

	gotoxy(kol, wier + 7);
	cout << (char)186 << (char)NULL << (char)179 << (char)NULL << (char)179 << (char)NULL << (char)186
		<< (char)NULL << (char)179 << (char)NULL << (char)179 << (char)NULL << (char)186
		<< (char)NULL << (char)179 << (char)NULL << (char)179 << (char)NULL << (char)186;


	gotoxy(kol, wier + 8);
	cout << (char)186 << (char)196 << (char)197 << (char)196 << (char)197 << (char)196 << (char)186
		<< (char)196 << (char)197 << (char)196 << (char)197 << (char)196 << (char)186
		<< (char)196 << (char)197 << (char)196 << (char)197 << (char)196 << (char)186;

	gotoxy(kol, wier + 9);
	cout << (char)186 << (char)NULL << (char)179 << (char)NULL << (char)179 << (char)NULL << (char)186
		<< (char)NULL << (char)179 << (char)NULL << (char)179 << (char)NULL << (char)186
		<< (char)NULL << (char)179 << (char)NULL << (char)179 << (char)NULL << (char)186;

	gotoxy(kol, wier + 10);
	cout << (char)186 << (char)196 << (char)197 << (char)196 << (char)197 << (char)196 << (char)186
		<< (char)196 << (char)197 << (char)196 << (char)197 << (char)196 << (char)186
		<< (char)196 << (char)197 << (char)196 << (char)197 << (char)196 << (char)186;

	gotoxy(kol, wier + 11);
	cout << (char)186 << (char)NULL << (char)179 << (char)NULL << (char)179 << (char)NULL << (char)186
		<< (char)NULL << (char)179 << (char)NULL << (char)179 << (char)NULL << (char)186
		<< (char)NULL << (char)179 << (char)NULL << (char)179 << (char)NULL << (char)186;

	gotoxy(kol, wier + 12);
	cout << (char)204 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)206
		<< (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)206
		<< (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)185;

	gotoxy(kol, wier + 13);
	cout << (char)186 << (char)NULL << (char)179 << (char)NULL << (char)179 << (char)NULL << (char)186
		<< (char)NULL << (char)179 << (char)NULL << (char)179 << (char)NULL << (char)186
		<< (char)NULL << (char)179 << (char)NULL << (char)179 << (char)NULL << (char)186;


	gotoxy(kol, wier + 14);
	cout << (char)186 << (char)196 << (char)197 << (char)196 << (char)197 << (char)196 << (char)186
		<< (char)196 << (char)197 << (char)196 << (char)197 << (char)196 << (char)186
		<< (char)196 << (char)197 << (char)196 << (char)197 << (char)196 << (char)186;

	gotoxy(kol, wier + 15);
	cout << (char)186 << (char)NULL << (char)179 << (char)NULL << (char)179 << (char)NULL << (char)186
		<< (char)NULL << (char)179 << (char)NULL << (char)179 << (char)NULL << (char)186
		<< (char)NULL << (char)179 << (char)NULL << (char)179 << (char)NULL << (char)186;

	gotoxy(kol, wier + 16);
	cout << (char)186 << (char)196 << (char)197 << (char)196 << (char)197 << (char)196 << (char)186
		<< (char)196 << (char)197 << (char)196 << (char)197 << (char)196 << (char)186
		<< (char)196 << (char)197 << (char)196 << (char)197 << (char)196 << (char)186;

	gotoxy(kol, wier + 17);
	cout << (char)186 << (char)NULL << (char)179 << (char)NULL << (char)179 << (char)NULL << (char)186
		<< (char)NULL << (char)179 << (char)NULL << (char)179 << (char)NULL << (char)186
		<< (char)NULL << (char)179 << (char)NULL << (char)179 << (char)NULL << (char)186;

	gotoxy(kol, wier + 18);
	cout << (char)200 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205
		<< (char)202 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205
		<< (char)202 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)188;
}

void stworzPlansze(int komorka[9][9])		//rysowanie planszy funkcja rysuj+wpisanie wprowawdzonych wartosci
{
	
	rysuj();
	/* to na dole uzupelnia to co na gorze wartosciami */
	for (int i = 0, w=wier; i < 9; i++,w += 2)
	{
		for (int p = 0,k=kol; p < 9; p++,k += 2)
		{
			gotoxy(k + 1, w + 1);
				if((int)komorka[i][p]==32)cout << (char)komorka[i][p];		//zeby nie pokazywalo 32 zamiast spacji
				else cout << (int)komorka[i][p];							//zeby pokazywalo wartosci rozne od spacji
		}
		
	}

}


void poruszanie(int *zn,int *y, int *x, int * wsky, int * wskx,int * attr)
{
	if (*zn == 0) {
		*zn = getch();
		if ((*zn == 0x48) && (*y > wier + 1))			//poruszanie w gore
		{
			(*y) -= 2;
			(*wsky)--;
		}
		else if ((*zn == 0x50) && (*y<wier + 17)) 		//poruszanie w dol
		{
			(*y) += 2;
			(*wsky)++;
		}
		else if ((*zn == 0x4b) && (*x>kol + 1)) 		//poruszanie w lewo	
		{
			(*x) -= 2;
			(*wskx)--;
		}
		else if ((*zn == 0x4d) && (*x < kol + 17)) 		//poruszanie w prawo
		{
			(*x) += 2;
			(*wskx)++;
		}
	}
	else if (*zn == ' ') *attr = (*attr + 1) % 16;	//zmiana koloru

}

bool trzynatrzy(int warx, int wary, int cyfra, int tablica[9][9])		//sprawdza czy w tabeli sudoku 3x3 nie ma juz takiej cyfry
{
	if (((warx) % 3) == 0){						//pierwsza z 3 kolumn
		if (((wary) % 3) == 0){					//pierwszy z 3 wierszy
			if ((tablica[wary + 1][warx + 1] == cyfra) || (tablica[wary + 1][warx + 2] == cyfra) || (tablica[wary + 2][warx + 2] == cyfra)
				|| (tablica[wary + 2][warx + 1] == cyfra))return false;
		}

		else if (((wary) % 3) == 1){		//drugi z 3 wierszy
			if ((tablica[wary-1][warx] == cyfra) || (tablica[wary-1][warx+1] == cyfra) || (tablica[wary-1][warx+2] == cyfra) || (tablica[wary][warx+1] == cyfra) || (tablica[wary][warx+2] == cyfra) ||
				(tablica[wary+1][warx] == cyfra) || (tablica[wary+1][warx+1] == cyfra) || (tablica[wary+1][warx+2] == cyfra)  )return false;				
		}		

		else	if (((wary) % 3) == 2){			//trzeci z 3 wierszy
			if ((tablica[wary-2][warx] == cyfra) || (tablica[wary-2][warx+1] == cyfra) || (tablica[wary-2][warx+2] == cyfra) || (tablica[wary-1][warx] == cyfra)
				|| (tablica[wary - 1][warx + 1] == cyfra) || (tablica[wary - 1][warx + 2] == cyfra)
				|| (tablica[wary][warx] == cyfra) || (tablica[wary][warx + 2] == cyfra) ||(tablica[wary][warx+2] == cyfra)  )return false;							
		}
	}
//////////////////////
	if (((warx) % 3) == 1){			//druga z 3 kolumn
		if (((wary) % 3) == 0){		//pierwszy z 3 wierszy
			if ((tablica[wary][warx - 1] == cyfra) || (tablica[wary][warx + 1] == cyfra) || (tablica[wary + 1][warx - 1] == cyfra) || (tablica[wary + 1][warx] == cyfra) || (tablica[wary + 1][warx + 1] == cyfra) ||
				(tablica[wary + 2][warx - 1] == cyfra) || (tablica[wary + 2][warx] == cyfra) || (tablica[wary + 2][warx + 1] == cyfra))return false;
		}	

		else if (((wary) % 3) == 1){		//drugi z 3 wierszy
			if ((tablica[wary -1][warx -1] == cyfra) || (tablica[wary -1][warx ] == cyfra) || (tablica[wary -1][warx + 1] == cyfra)
				|| (tablica[wary][warx - 1] == cyfra) || (tablica[wary][warx] == cyfra) || (tablica[wary][warx + 1] == cyfra) || (tablica[wary + 1][warx - 1] == cyfra) 
				|| (tablica[wary + 1][warx] == cyfra) || (tablica[wary + 1][warx + 1] == cyfra))return false;	
		}
								
		else	if (((wary) % 3) == 2){		//trzeci z 3 wierszy
			if ((tablica[wary - 2][warx-1] == cyfra) || (tablica[wary - 2][warx ] == cyfra) || (tablica[wary - 2][warx + 1] == cyfra) || (tablica[wary - 1][warx-1] == cyfra)
				|| (tablica[wary - 1][warx ] == cyfra) || (tablica[wary - 1][warx + 1] == cyfra) 
				|| (tablica[wary][warx-1] == cyfra) || (tablica[wary][warx ] == cyfra) || (tablica[wary][warx + 1] == cyfra))return false;		
		}
	}
/////////////////////////
	if (((warx) % 3) == 2){				//trzecia z 3 kolumn
		if (((wary) % 3) == 0){			//pierwszy z 3 wierszy
			if ((tablica[wary][warx-2 ] == cyfra) || (tablica[wary][warx -1] == cyfra) || (tablica[wary + 1][warx - 2] == cyfra) || (tablica[wary + 1][warx-1] == cyfra) || (tablica[wary + 1][warx ] == cyfra) ||
				(tablica[wary + 2][warx - 2] == cyfra) || (tablica[wary + 2][warx-1] == cyfra) || (tablica[wary + 2][warx ] == cyfra))return false;				
		}

		else if (((wary) % 3) == 1){	//drugi z 3 wierszy
			if ((tablica[wary - 1][warx - 2] == cyfra) || (tablica[wary - 1][warx-1] == cyfra) || (tablica[wary - 1][warx ] == cyfra)
				|| (tablica[wary][warx - 2] == cyfra) || (tablica[wary][warx-1] == cyfra) || (tablica[wary][warx] == cyfra) || (tablica[wary + 1][warx - 2] == cyfra)
				|| (tablica[wary + 1][warx-1] == cyfra) || (tablica[wary + 1][warx] == cyfra))	return false;	
		}
			
		else if (((wary) % 3) == 2){		//trzeci z 3 wierszy
			if ((tablica[wary - 2][warx - 2] == cyfra) || (tablica[wary - 2][warx-1] == cyfra) || (tablica[wary - 2][warx ] == cyfra) || (tablica[wary - 1][warx - 2] == cyfra)
				|| (tablica[wary - 1][warx-1] == cyfra) || (tablica[wary - 1][warx ] == cyfra) || (tablica[wary][warx - 2] == cyfra)
				|| (tablica[wary][warx-1] == cyfra) || (tablica[wary][warx ] == cyfra))return false;	
		}
	}

	return true;
}

int sprawdz(int wsknax, int wsknay, int wartosc, int tabela[9][9])
{
	for (int i = 0; i < 9 ; i++){						//sprawdzenie czy poziomo nie ma tej samej cyfry

			if ((i < wsknax) && (tabela[wsknay][i] == wartosc)) return 0;
			else if ((i > wsknax) && (tabela[wsknay][i] == wartosc)) return 0;
	}


	for (int i = 0; i < 9; i++){					//sprawdzenie czy pionowo nie ma tej samej cyfry

		if ((i < wsknay) && (tabela[i][wsknax] == wartosc))return 0;
		else if ((i > wsknay) && (tabela[i][wsknax] == wartosc)) return 0;				
	}


	if(trzynatrzy(wsknax, wsknay, wartosc, tabela)==false)return 0;		//sprawdzanie w tabeli 3x3 czy nie ma juz cyfry 'wartosc' w ktores komorce

		

	tabela[wsknay][wsknax] = wartosc;		//jesli predzej zadna petla nie skonczyla sie returnem to znaczy ze w pole mozna wpisac dana cyfre
	return  tabela[wsknay][wsknax];
}

void podpowiedz1(int ox, int oy, int wx, int wy, int tabl[9][9])		//wyswietla mozliwe wartosci dla danego pola
{
	for (int q = 1, w = 12; q <= 9; q++, w++)
	{
			gotoxy(komx, komy+w);
			if (sprawdz(wx, wy, q, tabl) > 0)cout << q;
			else cout << "x";

		tabl[wy][wx] = (char)32;
	}
}

int specjalna(int tabela[9][9],int xs,int ys,int e)	//funkcja uzyta w jednpodp; zwraca ile cyfr mozna wpisac w dana komorke
{
	int suma = 0;
	int tabelka[9][9];
	for (int q = 0; q < 9; q++)//stworzenie nowej tabeli z zawartoscia starej zeby nie zmieniac starej przy sprawdzaniu
	
	{
		for (int w = 0; w < 9; w++)
		{
			tabelka[q][w] = tabela[q][w];
		}
	}
	
	if ((tabelka[ys][xs] == (char)32) && (sprawdz(xs, ys, e, tabelka) == e))suma++;
	return suma;

}
void jednpodp(int wpx, int wpy, int skx, int sky, int tabel[9][9])		//podpowiedz jednoznaczna, zlicza ile razy moze wystapic dana cyfra w komorce
{
	static int suma = 0;
	int j = 0;
	int wx , wy ;
	for ( wy = 0; wy < 9; wy++)
	{
		for ( wx = 0; wx < 9; wx++)
		{
			suma = 0;
			for (int a = 1; a <= 9; a++)
			{
				if (specjalna(tabel, wx, wy, a)>0){
					suma += specjalna(tabel, wx, wy, a);
						j = a;							//przypisz cyfre ktora mozna wpisac w komorke
				}			
			}
			if (suma == 1){			//jesli jakas komorka ma jedna mozliwosc to spytaj czy wpisac
				gotoxy(komx, komy+12 );
				cout << "w kolumnie nr " << wx+1 << " i wierszu nr " << wy+1 << " mozesz wpisac " << j ;
				gotoxy(komx, komy+13 );
				cout << "wcisnij p jesli chcesz to zrobic: ";
				int kei = getch();
				if (kei == 112){
				tabel[wy][wx] = j;
				break;
				}
				else break;
			}
			if (suma == 1)break;								
		}
		if (suma == 1)	break;		
	}
}
	
void wczytaj(string nap, int k[9][9])
{
	int xx = 0, yy = 0;
	int liczby[90];
	
	string linia;
	fstream plik(nap + ".txt",ios::in);	//wczytuje plik o nazwie nap z zawartoscia sudoku
	if (plik.good() == false){		//jeœli niepoprawnie wczytano
		gotoxy(komx , komy + 11);
		cout << "nie udalo sie zaladowac planszy ";
	}
	else{int licznik = 0;
	while (!plik.eof()){		//poki sie nie skonczy plik	, eof zwraca prawde gdy osiagniemy koniec pliku
		getline(plik, linia);
		liczby[licznik] = atoi(linia.c_str());		//konwersja z string na int
		
		licznik++;

	}
	
	for (int a = 0, b = 0; a < 9, b < 9; a++, b++){if (liczby[b] != 0)k[0][a] = liczby[b];
		else k[0][a] = (char)32;
	}
	
	for (int a = 0, b = 9; a < 9, b < 18; a++, b++){if (liczby[b] != 0)k[1][a] = liczby[b];
	else k[1][a] = (char)32;}
	
	for (int a = 0, b = 18; a < 9, b < 27; a++, b++){if (liczby[b] != 0)k[2][a] = liczby[b];
	else k[2][a] = (char)32;}
	
	for (int a = 0, b = 27; a < 9, b < 36; a++, b++){if (liczby[b] != 0) k[3][a] = liczby[b];
	else k[3][a] = (char)32;}
	
	for (int a = 0, b = 36; a < 9, b < 45; a++, b++){if (liczby[b] != 0)k[4][a] = liczby[b];
	else k[4][a] = (char)32;}
	
	for (int a = 0, b = 45; a < 9, b < 54; a++, b++){if (liczby[b] != 0) k[5][a] = liczby[b];
	else k[5][a] = (char)32;}
	
	for (int a = 0, b = 54; a < 9, b < 63; a++, b++){if (liczby[b] != 0) k[6][a] = liczby[b];
	else k[6][a] = (char)32;}
	
	for (int a = 0, b = 63; a < 9, b < 72; a++, b++){if (liczby[b] != 0) k[7][a] = liczby[b];
	else k[7][a] = (char)32;}
	
	for (int a = 0, b = 72; a < 9, b < 81; a++, b++){if (liczby[b] != 0) k[8][a] = liczby[b];
	else k[8][a] = (char)32;}
	
	plik.close();

	}
}



void zapisz(string napis,int km[9][9])	
{
	
	int i = napis.length();
		if (napis[i - 4] == '.'){
			if ((napis[i - 3] == 't') && (napis[i - 1] == 't')){
				if ((napis[i - 2] == 'x')) {
					ofstream plik(napis);
					for (int i = 0; i < 9; i++){
						for (int b = 0; b < 9; b++){

							if (km[i][b] == (char)32) plik << 0 << endl;
							else plik << km[i][b] << endl;

						}

					}
				}
			}
		}
		
		if (napis[i - 4] != '.'){
			ofstream plik(napis + ".txt");
			for (int i = 0; i < 9; i++){
				for (int b = 0; b < 9; b++){

					if (km[i][b] == (char)32) plik << 0 << endl;
					else plik << km[i][b] << endl;

				}
			}

	}
	//ofstream plik(napis + ".txt");	//tworzy plik o nazwie napis z zawartoscia sudoku

	/*for (int i = 0; i < 9; i++){
		for (int b = 0; b < 9; b++){
			
			if (km[i][b] == (char)32) plik << 0<<endl;
			else plik << km[i][b]<<endl;
			
			}*/
	
}
void nazwanie(int kom[9][9],int aski)
{
	int klawisz;
	int a = 0;
	char nazwa[40];
	gotoxy(komx -10, komy + 15);
	cout << "podaj nazwe dokumentu : ";
	
	do						//wpisywanie nazwy pliku do ktorego zapisac
	{
		klawisz = getch();
		if ((klawisz != 13)){		//jesli rozny od entera
			nazwa[a] = klawisz;
			a++;
			putch(klawisz);
		}
		if (klawisz == 13)		//jesli enter
		{
			nazwa[a] = NULL;
			a++;
		}
		if ((klawisz == (char)8) && (a>1)	)	//jesli backspace i jest jakis napis to cofnij kursor o 1
		{	
			a -= 2;
			nazwa[a] = NULL;
		}

		 else if ((klawisz == (char)8) && (a == 1))	//jesli backspace i jest kursor w 1 komorce to wyjdz
			 break;
			
		
	
	} while (klawisz != 13);
	
	

	if(aski==115)	zapisz(nazwa,kom);	//jesli ma kod asci = s= zapisz
	
	else if (aski == 111)	wczytaj(nazwa, kom);	//jesli ma kod asci = o= wczytaj
}

void wpisywanie(const int asci, int y, int x, int  wsky, int  wskx, int komorka[9][9],int *liczruchy)
{

	if (asci == 49){
		cout << sprawdz(wskx, wsky, 1, komorka);		//1	
		(*liczruchy)++;
	}
	else if (asci == 50){cout << sprawdz(wskx, wsky, 2, komorka); //2
	(*liczruchy)++;
	}
	else if (asci == 51){cout << sprawdz(wskx, wsky, 3, komorka);	//3
	(*liczruchy)++;
	}
	else if (asci == 52){cout << sprawdz(wskx, wsky, 4, komorka);	//4
	(*liczruchy)++;
	}
	else if (asci == 53){cout << sprawdz(wskx, wsky, 5, komorka);	//5
	(*liczruchy)++;
	}
	else if (asci == 54){cout << sprawdz(wskx, wsky,6, komorka);		//6
	(*liczruchy)++;
	}
	else if (asci == 55){cout << sprawdz(wskx, wsky, 7, komorka);	//7
	(*liczruchy)++;
	}
	else if (asci == 56){cout << sprawdz(wskx, wsky, 8, komorka);	//8
	(*liczruchy)++;
	}
	else if (asci == 57){cout << sprawdz(wskx, wsky, 9, komorka);	//9
	(*liczruchy)++;
	}
	else if (asci == 8){ komorka[wsky][wskx] = (char)32; //backspace- usuwanie zawartosci komorki
	(*liczruchy)++;
	}
	else if (asci == 108) {
		podpowiedz1(x, y, wskx, wsky, komorka);
		(*liczruchy)++;
	}
	else if (asci == 115)nazwanie(komorka,115);			//zapis
	else if (asci == 111)nazwanie(komorka, 111);			//odczytanie

	else if (asci == 112) {
		jednpodp(x, y, wskx, wsky, komorka);
		(*liczruchy)++;
	}
}

void info(int liczruch, int czass)
{
	gotoxy(komx, komy);
	cputs("1...9=wpisywanie lub nadpisywanie");
	gotoxy(komx, komy + 1);
	cputs("q = wyjscie");
	gotoxy(komx, komy + 2);
	cputs("strzalki = poruszanie");
	gotoxy(komx, komy + 3);
	cputs("spacja = zmiana koloru");
	gotoxy(komx, komy + 4);
	cputs("l= wskazanie_mozliwych_liczb");
	gotoxy(komx, komy + 5);
	cputs("s=zapis");
	gotoxy(komx, komy + 6);
	cputs("o=odczyt");
	gotoxy(komx, komy + 7);
	cputs("backspace=usuniecie");
	gotoxy(komx, komy + 8);
	cputs("p=jednoznaczna podpowiedz");
	gotoxy(komx, komy + 9);
	printf("ilosc ruchow: %d", liczruch);
	gotoxy(komx, komy + 10);
	printf("Czas: %d sekund(y)", czass);


}
int main()
{
		int czas=0;
	int komorka[9][9];
	int liczruchy = 0;
	int zn, x = kol+1, y = wier + 1, attr = 7,wskx=0,wsky=0;	//x,y-wspolrzedne pierwszej komorki sudoku(tych wartosci sie nie zmienia); 
	settitle("Darek Asztemborski 155021");						//wskx,wsky-uzyte w tablicy: tab[wsky][wskx]
	textbackground(BLACK);
	
	wpiszSpacje(komorka);
	do {	
		czas = (int)((clock() - start) / CLOCKS_PER_SEC);		//okreslenie czasu
		textcolor(7);
		info(liczruchy, czas);
		gotoxy(kol, wier);
		textcolor(attr);
		stworzPlansze(komorka);		//RYSOWANIE PLANSZY Z WPROWADZONYMI ELEMENTAMI
		gotoxy(x, y);		//polozenie kursora	
		zn = getch();
		poruszanie(&zn, &y, &x, &wsky, &wskx, &attr );		//PORUSZANIE SIE PO PLANSZY
		clrscr();											//czysci plansze z powiadomien
		wpisywanie(zn, y, x, wsky, wskx, komorka, &liczruchy);		//WPISYWANIE WARTOSCI
		
	} while (zn != 'q');
	return 0;
}

