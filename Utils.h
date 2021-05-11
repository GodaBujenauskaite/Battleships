#pragma once
#include "define.h"
#include "Objects.h"
using namespace std;
//funkciju pavadinimai...
void Printinimas(Lentele &laivu_vietos_naujas, const int n);
void Printinimas2(std::vector<PradLentele> laivu_vietos, const int n);
bool is_number(const string &s);
void Nuliukai(Lentele &laivu_vietos_x_skaiciuoja, Lentele &laivu_vietos_naujas, int kordy, int kordx);
int Kiek_x(Lentele &laivu_vietos_x_skaiciuoja, const int n);
void Unicorn(Vienaragis unicornas);