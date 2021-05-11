#pragma once
#include "define.h"
#include "Objects.h"
#include <vector>
#include <iostream>

using namespace std;

//strukturos
struct PradLentele						    //leteles struktura, tos kurioje parodytos visos laivu vietos su x
{
	PradLentele(char bet_kas) {				//konstruktorius
		lent = bet_kas;						
	} 
	char lent;								//strukturos atributas
};

struct Lentele {							//lenteles boardas


	//~Lentele() {							//destruktorius neveikiantis
	//	for (int i = 0; i < n; i++) {
	//		delete[] board[i];
	//	}
	//	delete[] board;
	//}

	Lentele(int x, int y, char b[10][10]) { //konstruktorius, paduodi objektui parametrus. 
		kordx = x;
		kordy = y;

	//	char** board = new char* [n];		//dinaminis masyvas
		for (int i = 0; i < n; ++i) {
			board[i] = new char[n];
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				board[i][j] = b[i][j];		
			}
		}
	}

	Lentele() {
		kordx = NULL;						//uzsinulina vienu zodziu viskas safety precaution
		kordy = NULL;

		
		//char** board = new char* [n];
		for (int i = 0; i < n; ++i) {
			board[i] = new char[n];
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				board[i][j] = NULL;		   //uzsipildo kad nebutu tuscias
			}
		}
	}

	//strukturos atributai
	int kordx, kordy;

	char** board = new char* [n];	

	
};


struct Vienaragis {							//unicorno piesinukas, inevitable for the game 🙂

	Vienaragis(vector <string> uni, bool ar) {
		unicorn = uni;
		ar_reikia_piesti = ar;
	}
	Vienaragis() {
		unicorn.emplace_back();			    //kitaip ideda i vectoriu
		ar_reikia_piesti = NULL;
	}

	//strukturos atributai
	//string unicorn[20]; 
	vector <string> unicorn;			   //vectorius is stringu - jis yra dinaminis
	bool ar_reikia_piesti;
};