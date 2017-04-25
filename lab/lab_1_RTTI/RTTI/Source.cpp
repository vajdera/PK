#include <iostream>
#include "Sportowiec.h"
#include "Pilkarz.h"
#include "Gwiazda.h"

#include <time.h>

using namespace std;

Sportowiec* tworz_obiekt(){

	Sportowiec* wsk=NULL;

	switch (rand() % 3) {
	
		case 0:
			wsk = new Sportowiec(rand() % 120, rand() % 10000);
		break;
		case 1:
			wsk = new Pilkarz(rand() % 120, rand() % 10000,rand()%200*1000000);
		break;
		case 2:
			wsk = new Gwiazda(rand() % 120, rand() % 10000, rand() % 200 * 1000000);
		break;
	
	}

	return wsk;

}

int main() {

	srand(time(NULL));

	Sportowiec* tab[6];

	for (int i = 0;i < 6;i++) {

		tab[i] = tworz_obiekt();

		tab[i]->dane();

	}

	int s = 0, p = 0, g = 0;

	for (int i = 0;i < 6;i++) {

		if (typeid(*tab[i]) == typeid(Sportowiec))
			s++;
		if (typeid(*tab[i]) == typeid(Pilkarz))
			p++;
		if (typeid(*tab[i]) == typeid(Gwiazda))
			g++;
	}

	cout << endl << endl << "Jest:" <<endl<< s << " Sportowcow" << endl << p << " Pilkarzy" << endl << g << " Gwiazd" <<endl <<endl;

	Pilkarz* pil;

	for (int i = 0;i < 6;i++) {

		if (pil = dynamic_cast<Pilkarz*>(tab[i]))
			pil->gram_w_futbol();
		
	}


	long cp = 0, cg = 0;
	Gwiazda* gw=NULL;

	for (int i = 0;i < 6;i++) {

		if (pil = dynamic_cast<Pilkarz*>(tab[i])) {
			if (gw = dynamic_cast<Gwiazda*>(pil)) {
				if (gw->getCena() > cg) {
					cg = gw->getCena();
				}
			}
			else {
				if (pil->getCena() > cp) 
					cp = pil->getCena();
				
			}
		}
	}

		cout << cp << endl << cg << endl;

}