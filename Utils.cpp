#include "define.h"
#include "Utils.h"
#include "Objects.h"
#include <iostream>
#include <vector>

using namespace std;

//funkcijos
int Kiek_x(Lentele &laivu_vietos_x_skaiciuoja, const int n) {						 //kad nekurtu kopijos - &

	int kiek_x = 0;
	//skaiciuoja kiek x visame borde
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (laivu_vietos_x_skaiciuoja.board[i][j] == 'x') {						 //jei randa x, prideda prie kiekio
				kiek_x += 1;														 //prideda prie kiekio
			}
		}
	}
	return kiek_x;
}

void Unicorn(Vienaragis unicornas) {												 //gale isprintina unicorna 🙂

	for (auto it = unicornas.unicorn.begin(); it != unicornas.unicorn.end(); ++it) { //iteratorius eina per visas vectoriaus eilutes (is stringo) 
		cout << *it << endl;														 //be pointerio neveikia
	}

	//for (int i = 0; i < 19; i++) cout << unicornas.unicorn[i] << endl;			 //paveiksliukas uzima 20 liniju mazdaug - string
}

void Nuliukai(Lentele &laivu_vietos_x_skaiciuoja, Lentele &laivu_vietos_naujas, int kordy, int kordx) { // references nes negrazindavo reiksmiu be ju, masyvu nepakeisdavo
	//nuo to tasko kuriame sove sudedami nuliai (nuo kaires virsuj iki desines apacioj 3x3
	for (int i = kordy - 1; i <= kordy + 1; i++) {
		for (int j = kordx - 1; j <= kordx + 1; j++) {
			if (i >= 0 && j >= 0 && i < n && j < n && laivu_vietos_x_skaiciuoja.board[i][j] == '-' ) { //jei randa bruksneli ir ne galas boardo
				laivu_vietos_naujas.board[i][j] = 'o';
			}
		}
	}
	//tada tikrina ar tikrai jau visur sudejo tas pats kaip tikrinimas vis eina i visas puses ir keikviena karta jei randa . arba * ji pakeicia kad nebesiciklintu ir kviecia fukncija tam taske
	if (kordy + 1 >= 0 && kordy + 1 < n && (laivu_vietos_x_skaiciuoja.board[kordy + 1][kordx] == '.' || laivu_vietos_x_skaiciuoja.board[kordy + 1][kordx] == '*')) {
		laivu_vietos_x_skaiciuoja.board[kordy + 1][kordx] = '#';
		Nuliukai(laivu_vietos_x_skaiciuoja, laivu_vietos_naujas, kordy + 1, kordx);
	}
	if (kordx + 1 >= 0 && kordx + 1 < n && (laivu_vietos_x_skaiciuoja.board[kordy][kordx + 1] == '.' || laivu_vietos_x_skaiciuoja.board[kordy][kordx + 1] == '*')) {
		laivu_vietos_x_skaiciuoja.board[kordy][kordx + 1] = '#';
		Nuliukai(laivu_vietos_x_skaiciuoja, laivu_vietos_naujas, kordy, kordx + 1);
	}
	if ((kordy - 1 >= 0 && kordy - 1 < n && ( laivu_vietos_x_skaiciuoja.board[kordy - 1][kordx] == '.' || laivu_vietos_x_skaiciuoja.board[kordy - 1][kordx] == '*'))) {
		laivu_vietos_x_skaiciuoja.board[kordy - 1][kordx] = '#';
		Nuliukai(laivu_vietos_x_skaiciuoja, laivu_vietos_naujas, kordy - 1, kordx);
	}
	if (kordx - 1 >= 0 && kordx - 1 < n && (laivu_vietos_x_skaiciuoja.board[kordy][kordx - 1] == '.' || laivu_vietos_x_skaiciuoja.board[kordy][kordx - 1] == '*')) {
		laivu_vietos_x_skaiciuoja.board[kordy][kordx - 1] = '#';
		Nuliukai(laivu_vietos_x_skaiciuoja, laivu_vietos_naujas, kordy, kordx - 1);
	}
}
bool is_number(const string &s)
{
	auto it = s.begin();											//iteratorius rodo i stringo pradzia  
	while (it != s.end() && isdigit(*it)) ++it;						//ima reiksme o ne adresa, eina per stringa ir tikrina ar tai skaicius
	return !s.empty() && it == s.end();								//stringas ne tuscias ir iteratorius pabaigoje to stringo...
}

void Printinimas(Lentele  &laivu_vietos_naujas, const int n) {		//kiekviena kart isprintina tai kur tu sovei

	cout << "  ";

	for (int i = 0; i < 10; i++) {
		cout << i << " ";											//su antrastem nuo 0 iki 9
		if (i == 9) cout << endl;
	}
	for (int i = 0; i < 10; i++) {
		cout << i << " ";
		for (int j = 0; j < n; j++) {
			cout << laivu_vietos_naujas.board[i][j] << " ";			//printina pakeista su suviais esanti boarda
			if (j == n - 1) cout << endl;
		}
	}
	cout << endl;
}

void Printinimas2(vector<PradLentele> laivu_vietos, const int n) { //gale isprintina lentele kaip stovejo laivai

	cout << "  ";

	for (int i = 0; i < 10; i++) {
		cout << i << " ";										  //su antrastem nuo 0 iki 9
		if (i == 9) cout << endl;								  //jei jau 9 isprintino, kita eilute
	}
	for (int i = 0; i < 10; i++) {
		cout << i << " ";										  //kiekvienos eilutes pirmas elementas skaicius antraste 0-9
		for (int j = 0; j < n; j++) {
			cout << laivu_vietos[j + (i * n)].lent << " ";		  //isprintina nepakeista boarda nepaliesta kuriame stovi laivai - x, eina per eilutes nes vienmatis masyvas, nes poto j tarkim 0 o i jau 1*10 nes n yra 10
			if (j == n - 1) cout << endl;						  //jei paskutinis elementas eilutes
		}
	}
	cout << endl;
}
