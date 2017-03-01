#pragma once

#include<iostream>

class Sportowiec {
protected:

	int wiek;
	int placa;

public:

	Sportowiec(int w, int p) : wiek(w), placa(p) {}
	
	virtual ~Sportowiec() {};

	void virtual dane() {
	
		std::cout << "sportowiec w wieku " << wiek << " lat, zarabiajacy: " << placa << " zl.\n";
	
	};




};