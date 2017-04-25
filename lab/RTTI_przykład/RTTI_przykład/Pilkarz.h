#ifndef PILKARZ
#define PILKARZ
#include "Sportowiec.h"

class Pilkarz :public Sportowiec
{
protected:
	long cena;
public:
	Pilkarz(int w, long p, long c) : Sportowiec(w, p), cena(c) {};
	Pilkarz(Sportowiec & s, long c) :Sportowiec(s), cena(c) {};
	long getCena() { return cena; };
	virtual ~Pilkarz() {};
	void virtual daneSportowca();
	void virtual gram_w_futbol();

};
void Pilkarz::daneSportowca()
{

	std::cout << "Pilkarz w wieku: " << wiek << " zarabia: " << placa << " zl\n";
	std::cout << "Jego cena rynkowa wynosi: " << cena << std::endl << std::endl;
}
void Pilkarz::gram_w_futbol()
{
	std::cout << "Gram zawodowo w futbol\n";
}

#endif
