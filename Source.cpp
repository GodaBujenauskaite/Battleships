#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <array>
#include "Utils.h"
#include "Objects.h"
#include "define.h"
using namespace std;

bool ar_visas_laivas = true;
char pasidavimas;

void Ar_visas_laivas(Lentele laivu_vietos_x_skaiciuoja, Lentele laivu_vietos_naujas, int kordy, int kordx)
{
	if ((kordy + 1 < n && laivu_vietos_x_skaiciuoja.board[kordy + 1][kordx] == 'x' || kordy - 1 >= 0 && laivu_vietos_x_skaiciuoja.board[kordy - 1][kordx] == 'x' || kordx + 1 < n && laivu_vietos_x_skaiciuoja.board[kordy][kordx + 1] == 'x' || kordx - 1 >= 0 && laivu_vietos_x_skaiciuoja.board[kordy][kordx - 1] == 'x')) {
		ar_visas_laivas = false;			//iseina is va sitos kazko.... don't ask
		return;								//jeigu bent vienoj vietoj aplinkui stovi x iskart paneigia kad nusautas visas laivas ir iseina
	}

	if (ar_visas_laivas == false) return;	//iseina is kazkokiu nesamoningu rekursiju (nzn kas tai) iseina visiskai 

	//jeigu aplinkui nerado x nei vieno tai tada eina ir toliau tikrina
	//eina i visas puses ir tikrina ar nera x, eina vis gyliau, jei randa * tada vel kviecia funkcija ir eina i ta puse, keiciant i taskus, kad neuzsiciklintu
	//dar tikrina ar tai nera uz ribu boardo

	//apacion
	if (kordy + 1 >= 0 && kordy + 1 < n && laivu_vietos_x_skaiciuoja.board[kordy + 1][kordx] == '*') {
		laivu_vietos_x_skaiciuoja.board[kordy + 1][kordx] = '.';
		Ar_visas_laivas(laivu_vietos_x_skaiciuoja, laivu_vietos_naujas, kordy + 1, kordx);
	}
	//i desine
	if (kordx + 1 >= 0 && kordx + 1 < n && laivu_vietos_x_skaiciuoja.board[kordy][kordx + 1] == '*') {
		laivu_vietos_x_skaiciuoja.board[kordy][kordx + 1] = '.';
		Ar_visas_laivas(laivu_vietos_x_skaiciuoja, laivu_vietos_naujas, kordy, kordx + 1);
	}
	//aukstyn
	if (kordy - 1 >= 0 && kordy - 1 < n && laivu_vietos_x_skaiciuoja.board[kordy - 1][kordx] == '*') {
		laivu_vietos_x_skaiciuoja.board[kordy - 1][kordx] = '.';
		Ar_visas_laivas(laivu_vietos_x_skaiciuoja, laivu_vietos_naujas, kordy - 1, kordx);
	}
	//kairen
	if (kordx - 1 >= 0 && kordx - 1 < n && laivu_vietos_x_skaiciuoja.board[kordy][kordx - 1] == '*') {
		laivu_vietos_x_skaiciuoja.board[kordy][kordx - 1] = '.';
		Ar_visas_laivas(laivu_vietos_x_skaiciuoja, laivu_vietos_naujas, kordy, kordx - 1);
	}

}

void Speliojimas(int kiekis, const int n, Lentele laivu_vietos_x_skaiciuoja, Lentele& laivu_vietos_naujas, long long& Pointsgained, long long& Shots, array <string, 2> smiley) { //grazina reiksmes pakeistas

	int kordy, kordx;
	string skordy, skordx;
	while (kiekis != 0) {				// kol neissaunami visi laivai (yra x) vyksta speliojimas
		cout << "Kur norite sauti?";
		cin >> skordy >> skordx;		//ivedamos reiksmes i stringa

		kordx = atoi(skordx.c_str());	//stringe esancius skaicius konvertina i inta, si funkcija... bet jei raides buna tai konvertina i nuli ir tai yra negerai ir todel atsiranda bool funkcija
		kordy = atoi(skordy.c_str());

		while (kordy > 9 || kordy < 0 || kordx > 9 || kordx < 0 || is_number(skordy) == false || is_number(skordx) == false) { //jeigu tai ne skaicius netinka arba uz bounds
			cout << "Neteisingai ivedete ";
			cin >> skordy >> skordx;
			kordx = atoi(skordx.c_str());
			kordy = atoi(skordy.c_str());
		}
		Shots++;													//kiek kartu saudyta buvo
		if (laivu_vietos_x_skaiciuoja.board[kordy][kordx] == 'x') { //jei pataiko
			cout << "Pataikete! Saukite toliau " << "    " << smiley[1] << endl; //༼ つ ◕_◕ ༽つ
			cout << endl;
			laivu_vietos_naujas.board[kordy][kordx] = '*';			//nusauta - main board
			laivu_vietos_x_skaiciuoja.board[kordy][kordx] = '*';	//nusauta - bordas x skaiciavimui
			Pointsgained++;											//prideda prie tasku

			ar_visas_laivas = true;									//assumina kad tai tikrai nusautas visas laivas, reikia tai paneigti
			Ar_visas_laivas(laivu_vietos_x_skaiciuoja, laivu_vietos_naujas, kordy, kordx);
			if (ar_visas_laivas == true) Nuliukai(laivu_vietos_x_skaiciuoja, laivu_vietos_naujas, kordy, kordx);//jeigu visdelto nusautas tai kviecia funkcija kuri isprintina aplink laiva nuliukus		

		}
		else {
			cout << "Nepataikete. Kito ejimas " << "    " << smiley[0] << endl;
			if (laivu_vietos_naujas.board[kordy][kordx] != '*') {	//jeigu ten jau nebuvo sauta
				laivu_vietos_naujas.board[kordy][kordx] = 'o';		//parodo kad tuscia - suvi parodo, nepataikyta
				laivu_vietos_x_skaiciuoja.board[kordy][kordx] = 'o';

			}

		}
		Printinimas(laivu_vietos_naujas, n);						//printina nauja tik su saudymais masyva
		kiekis = Kiek_x(laivu_vietos_x_skaiciuoja, n);				//su kopijuotu masyvu tikrina kiek x liko

		if (kiekis != 0) {											//jeigu ciklas dar tesiasi
			cout << "Ar  nori pasiduoti, y - yes, n - no " << endl; //cheat cheat kad greiciau baigt zaidima
			cin >> pasidavimas;

			if (pasidavimas == 'y') {								//jei pasiduoda
				cout << endl;
				return;												//iseina is ciklo tuo paciu ir ir funkcijos
			}
		}

	}

}

int main() {
	ifstream read("duom.txt");
	ifstream reading("unicorn.txt");
	ofstream draw("taskai.txt");

	//char laivu_vietos[10][10], laivu_vietos_x_skaiciuoja[10][10], laivu_vietos_naujas[10][10]  //1 - lyg kopija
	char padetis, a;
	int kordx, kordy;
	int FinalScore = 0;
	int kiekis = 0;
	char bruksnys = '-';						//lambda kad naudot galetu
	string siaip_sau;


	Vienaragis unicornas;						//struktura piesinuko
	Lentele laivu_vietos;						//bordu strukturos
	Lentele laivu_vietos_x_skaiciuoja;
	Lentele laivu_vietos_naujas;

	void(*ptrunicorn)(Vienaragis);				//sukuriamas pointeris i funkcija  tipas_funkcijos(pavadinimas)(atributai)
	ptrunicorn = Unicorn;						//pointeriui priskiriu fukncija

	//string unicorn[20];

	array<string, 2> smiley = { "(-_-)","^-^" };//masyvas is stringu, kuriame du elementai du emoji
	//array<string, 3> happysmiley = {"^-^"};

	//unicorn gauna paveiksliuka
	for (int i = 0; i < 19; i++) {
		getline(reading, siaip_sau);
		unicornas.unicorn.push_back(siaip_sau); //i vektoriaus gala ideda, i sekancia vis vieta ideda, lyg i kita eilute
	}

	//visas bordas uzpildomas bruksneliais
	auto bruksniai = [bruksnys](Lentele& bark, int a, int b) {bark.board[a][b] = bruksnys; }; //lambda kaip funkcija miniatiurine
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			bruksniai(laivu_vietos_naujas, i, j);
			//laivu_vietos_naujas.board[i][j] = '-';
		}
	}

	// is dokumento sudeda i masyva simbolius - laivus sustato
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			read >> a;
			laivu_vietos.board[i][j] = a;
		}
	}

	vector <PradLentele> Galutine;										//vector is strukturos kur bus paprasta galutine zaidimo lenta - rodo kur buvo laivai 

	//padaro kopija laivu vietu
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			laivu_vietos_x_skaiciuoja.board[i][j] = laivu_vietos.board[i][j];
			PradLentele kint(laivu_vietos_x_skaiciuoja.board[i][j]);	//isideda charas i objekta...sukuriamas objektas
			Galutine.push_back(kint);									//ideda kintamaji i vectoriaus gala
		}
	}

	//Padarom galutine lenta, kuri bus atspausdinta zaidimo pabaigoje, kuri parodys kur buvo laivai
	//suskaiciuoja kiek isviso borde yra laivu - veliau tikrins ar skaicius !=0
	kiekis = Kiek_x(laivu_vietos, n);

	map <int, char> score;												//sukuriamas butinas mapas gautam rezultatui rasti :(

	//taskas uz kiekviena pataikyta laiva, shots - kiek kartu sovei
	long long Pointsgained = 0;
	long long Shots = 0;

	//funkcija kuri vykdo speliojima - saudymas i laivus
	Speliojimas(kiekis, n, laivu_vietos_x_skaiciuoja, laivu_vietos_naujas, Pointsgained, Shots, smiley);

	//pabaigoje patikrinama ar buvo pasiduota
	//jei taip paraso kad pralaimejo ir parodo kur stovejo laivai
	if (pasidavimas == 'y') {
		cout << "Pralaimejote" << endl;
		cout << endl;
		Printinimas2(Galutine, n);										// isprintina kas buvo
		draw << "Pasidavete!";
	}

	//jeigu nebuvo pasiduota ir praejo visa zaidima vadinasi laimejo ir parodo kiek tasku gavo bei laivu vietas
	else {
		cout << "Laimejote! " << endl;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
			{
				score[j + (i * n)] = laivu_vietos_naujas.board[i][j];	//sukuriamas mapas, kad butu galima suskaiciuoti score
			}
		for (auto x : score)											//ciklas einantis per visus mapo elemantus
		{
			if (x.second == '*')										//jei laivas pasautas tai reikia sumuoti score
			{
				FinalScore++;
			}
		}
		cout << "Jusu taskai " << FinalScore << "/" << Shots << endl;  //kiek tasku gauni is tiek kiek saudei kartu
		cout << endl;
		Printinimas2(Galutine, n);
		draw << "Jusu taskai " << FinalScore << "/" << Shots;
	}

	cout << endl;

	//bonus isprintina unicorna
	ptrunicorn(unicornas); //rodykle i funkcija

	//istrinami dinaminiai masyvai

	for (int i = 0; i < n; i++) {
		delete[] laivu_vietos.board[i];
	}
	delete[] laivu_vietos.board;

	for (int i = 0; i < n; i++) {
		delete[] laivu_vietos_x_skaiciuoja.board[i];
	}
	delete[] laivu_vietos_x_skaiciuoja.board;

	for (int i = 0; i < n; i++) {
		delete[] laivu_vietos_naujas.board[i];
	}
	delete[] laivu_vietos_naujas.board;


	draw.close();
	read.close();
	reading.close();

	return 0;
}