
/*bool Ar_teisingai_irasyta(int kordy, int kordx, int x, const int n, char padetis) {
	bool neteisingai = false;
	if (padetis == 'v') {
		if (kordy + x > n) {
			cout << "Negalima deti. Bandykite dar karta" << endl;
			neteisingai = true;
			return neteisingai;
		}
	}
	if (padetis == 'h') {
		if (kordx + x > n) {
			cout << "Negalima deti. Bandykite dar karta" << endl;
			neteisingai = true;
			return neteisingai;
		}
	}

	return neteisingai;
}
*/


//sudedi savo laivus
/*
for (int x = 4; x > 0; x--) {	//kokio dydzio laivas
	for (int a = 0; a < kiek; a++) { //kiek tokiu laivu
		cout << "Kur norite padeti " << x << " dydzio laiva";
		cin >> kordy >> kordx;

		//jei laivas vienvietis nereikia klausti ar jis eis horizontaliai ar vertikaliai
		if (x == 1) {
			if (kordy > n || kordx > n) {
				x++;
				continue;
			}
			laivu_vietos[kordy][kordx] = 'x';
			continue;
		}

		cout << "horizontaliai - h, vertikaliai v";
		cin >> padetis;

		bool neteisingai = Ar_teisingai_irasyta(kordy, kordx, x, n, padetis);
		if (neteisingai == true) {
			x++;
			kiek--;
			a--;
			continue;
		}

		if (padetis == 'h') {
			for (int j = kordx; j < kordx + x; j++) {
				laivu_vietos[kordy][j] = 'x';
			}
		}

		else if (padetis == 'v') {
			for (int i = kordy; i < kordy + x; i++) {
				laivu_vietos[i][kordx] = 'x';
			}
		}

		else {
		cout<<"Ivedete ne ta raide";
		x++;
		continue;
		}

	}
	kiek++;
}

for (int i = 0; i < n; i++) {
	for (int j = 0; j < n; j++) {
		laivu_vietos_x_skaiciuoja[i][j] = laivu_vietos[i][j];
	}
}


*/


/*
//speliojimas
while (kiekis!= 0) {

	cout << "Kur norite sauti?";
	cin >> kordy >> kordx;

	if (laivu_vietos_x_skaiciuoja[kordy][kordx] == 'x') {
		cout << "Pataikete! Saukite toliau " << endl;
		laivu_vietos_naujas[kordy][kordx] = '*'; //nusauta
		laivu_vietos_x_skaiciuoja[kordy][kordx] = '*'; //nusauta

		if (laivu_vietos[kordy - 1][kordx - 1] != 'x') laivu_vietos_naujas[kordy - 1][kordx - 1] = 'o';
		if (laivu_vietos[kordy - 1][kordx] != 'x') laivu_vietos_naujas[kordy - 1][kordx] = 'o';
		if (laivu_vietos[kordy - 1][kordx + 1] != 'x') laivu_vietos_naujas[kordy - 1][kordx + 1] = 'o';
		if (laivu_vietos[kordy][kordx - 1] != 'x') laivu_vietos_naujas[kordy][kordx - 1] = 'o';
		if (laivu_vietos[kordy][kordx + 1] != 'x') laivu_vietos_naujas[kordy + 1][kordx] = 'o';
		if (laivu_vietos[kordy + 1][kordx - 1] != 'x') laivu_vietos_naujas[kordy + 1][kordx - 1] = 'o';
		if (laivu_vietos[kordy + 1][kordx] != 'x') laivu_vietos_naujas[kordy + 1][kordx] = 'o';
		if (laivu_vietos[kordy + 1][kordx + 1] != 'x') laivu_vietos_naujas[kordy + 1][kordx + 1] = 'o';

	}
	else {
		cout << "Nepataikete. Kito ejimas " << endl;
		if (laivu_vietos_naujas[kordy][kordx] != '*') {
			laivu_vietos_naujas[kordy][kordx] = 'o';
			laivu_vietos_x_skaiciuoja[kordy][kordx] = 'o';
		}

	}



	Printinimas(laivu_vietos_naujas, n);    //printina nauja tik su saudymais masyva

	kiekis = Kiek_x(laivu_vietos_x_skaiciuoja, n);		//su kopijuotu masyvu tikrina kiek x liko
}
*/