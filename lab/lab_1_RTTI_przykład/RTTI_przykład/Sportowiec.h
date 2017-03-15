#ifndef SPORTOWIEC
#define SPORTOWIEC
#include <iostream>
class Sportowiec
{
protected:
	int wiek;
	long placa;
public:
	Sportowiec(int w, long p) :wiek(w), placa(p) {};
	virtual ~Sportowiec() {};
	void virtual daneSportowca();

};
void Sportowiec::daneSportowca()
{
	std::cout << "Sportowiec w wieku: " << wiek << " zarabia " << placa << " zl" << std::endl << std::endl;
}
#endif

