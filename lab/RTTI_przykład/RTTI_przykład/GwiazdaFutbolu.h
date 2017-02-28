#ifndef GWIAZDAFUTBOLU
#define GWIAZDAFUTBOLU
#include "Sportowiec.h"
#include "Pilkarz.h"
class GwiazdaFutbolu :public Pilkarz
{
public:
	GwiazdaFutbolu(int w, long p, long c) : Pilkarz(w, p, c) {};
	GwiazdaFutbolu(Pilkarz & p) :Pilkarz(p) {};
	virtual ~GwiazdaFutbolu() {};
	void virtual daneSportowca();
	void virtual gram_w_futbol();
};
void GwiazdaFutbolu::daneSportowca()
{
	std::cout.width(2);
	std::cout << "Gwiazda futbolu w wieku: " << wiek << " zarabia: " << placa << " zl\n";
	std::cout.width(2);
	std::cout.precision(2);
	std::cout << "Jego cena rynkowa wynosi: " << cena << " zl" << std::endl << std::endl;
}
void GwiazdaFutbolu::gram_w_futbol()
{
	std::cout << "Gram zawodowo w futbol i jestem gwiazda\n";
}

#endif
