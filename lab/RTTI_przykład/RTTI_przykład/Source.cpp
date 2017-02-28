#include "Sportowiec.h"
#include "Pilkarz.h"
#include "GwiazdaFutbolu.h"
#include <time.h>
#include <vector>
Sportowiec* tworz_obiekt();//funkcja tworzy losowy obiekt typu Sportowiec Pilkarz lub GwiazdaFutbolu

int main()
{
	srand(time(NULL));
	Sportowiec* tablica[8];
	Pilkarz* pp;

	//ZAD1
	std::cout << "ZAD1\n";
	//inicjalizacja tablicy losowymi sportowcami pilkarzami lub gwiazdami_futbolu
	for (int i = 0; i < 8; i++)
	{
		tablica[i] = tworz_obiekt();//przypisuje elementowi tablicy wskaznik na nowy obiekt
		tablica[i]->daneSportowca();//wywolanie wirtualnej metody dla wskaznika odpowiedniego typu
	}

	std::cout << "ZAD2\n";

	//ZAD2
	for (int i = 0; i < 8; i++)
	{
		if (pp = dynamic_cast<Pilkarz*>(tablica[i]))//rzutowanie udaje sie tylko wtedy gdy element tablica[i] wskazuje na obiekt klasy Pilkarz lub klasy do niej pochodnej
			pp->gram_w_futbol();
		else
			std::cout << "Jestem tylko Sportowcem\n";
	}


	//ZAD3
	std::cout << "\nZAD3\n";
	int liczba_gwiazd = 0;
	int liczba_pilkarzy = 0;
	int liczba_sportowcow = 0;
	for (int i = 0; i < 8; i++)
	{
		if (typeid(Sportowiec) == typeid(*tablica[i]))
			liczba_sportowcow++;
		else if (typeid(Pilkarz) == typeid(*tablica[i]))
			liczba_pilkarzy++;
		else if (typeid(GwiazdaFutbolu) == typeid(*tablica[i]))
			liczba_gwiazd++;
	}
	std::cout << "Jest dokladnie " << liczba_sportowcow << " Sportowcow " << liczba_pilkarzy << " Pilkarzy " << liczba_gwiazd << " Gwiazdy\n";

	//ZAD4
	std::cout << "\nZAD4";
	long max_cena_Pilkarz = 0;
	long max_cena_GwiazdyFutbolu = 0;
	for (int i = 0; i < 8; i++)
	{
		if (pp = dynamic_cast<GwiazdaFutbolu*>(tablica[i]))//rzutowanie udaje sie tylko wtedy gdy element tablica[i] wskazuje na obiekt klasy GwiazdaFutbolu 
		{
			if (pp->getCena()>max_cena_GwiazdyFutbolu)
				max_cena_GwiazdyFutbolu = pp->getCena();
		}
		else if (pp = dynamic_cast<Pilkarz*>(tablica[i]))//rzutowanie udaje sie tylko wtedy gdy element tablica[i] wskazuje na obiekt klasy Pilkarz lub klasy do niej pochodnej
		{
			if (pp->getCena() > max_cena_Pilkarz)
				max_cena_Pilkarz = pp->getCena();
		}
	}
	std::cout << "\n najwieksza cena za pilkarza: " << max_cena_Pilkarz << " zl, za gwiazde: " << max_cena_GwiazdyFutbolu << " zl";

	//Sportowiec* wsk = new Sportowiec(rand() % 20 + 20, rand() % 2000);
	//Pilkarz* wsk1 = (Pilkarz*) wsk;
	//wsk1->daneSportowca();

	getchar();
	return 0;
}
Sportowiec* tworz_obiekt()
{
	Sportowiec* wsk = NULL;
	switch (rand() % 3)
	{
	case(0): wsk = new Sportowiec(rand() % 20 + 20, rand() % 2000);
		break;
	case(1): wsk = new Pilkarz(rand() % 20 + 20, rand() % 2000, rand() % 10000 + 5000);
		break;
	case(2): wsk = new GwiazdaFutbolu(rand() % 20 + 20, rand() % 2000, rand() % 40 * 1000000);
		break;
	}
	return wsk;

}