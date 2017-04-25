#pragma once

#include<iostream>
#include "Sportowiec.h"
#include "Pilkarz.h"

class Gwiazda :public Pilkarz {
protected:

public:

	Gwiazda(Pilkarz &p) : Pilkarz(p) {};
	Gwiazda(int w, int p, int c) : Pilkarz(w, p,c){}


	virtual ~Gwiazda() {};

	void virtual dane() {

		std::cout << "Gwiazda futbolu w wieku " << wiek << " lat, zarabiajaca: " << placa << " zl, o cenie " << cena << " zl.\n";

	};

	virtual void gram_w_futbol() {

		std::cout << "Gram zawodowo w futbol i jestem gwiazda\n";


	};




};