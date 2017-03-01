#pragma once

#include<iostream>
#include "Sportowiec.h"

class Pilkarz :public Sportowiec {
protected:

	long cena;

public:

	Pilkarz(Sportowiec &s,int c): Sportowiec(s),cena(c) {};
	Pilkarz(int w, int p, int c) : Sportowiec(w, p), cena(c) {};


	virtual ~Pilkarz() {};

	void virtual dane() {

		std::cout << "Pilkarz w wieku " << wiek << " lat, zarabiajacy: " << placa << " zl, o cenie "<<cena<<" zl.\n";

	};

	void gram_w_futbol() {
	
		std::cout << "Gram zawodowo w futbol\n";

	
	};

	long getCena() {
		
		return cena;
		
	};


};