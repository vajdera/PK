#include <vector>
#include <deque>
#include <list>
#include <map>
#include <queue>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <functional>
using namespace std;

class NaprawianeAuto
{
public:	
	int idAuta;
	list<string> historiaNapraw;
	priority_queue<string, vector<string>, greater<string>> rzeczyDoNaprawy;

	void WyswietlHistorie()
	{
		cout << "Historia naprawa auta o id " << idAuta << endl;
		
		for (auto iter = historiaNapraw.begin(); iter != historiaNapraw.end(); iter++)
			cout << *iter << endl;

		list <int> kontener;
		for (auto it = kontener.begin(); it != kontener.end(); it++)
			cout << *it << endl;
	}
	NaprawianeAuto(int idAuta_) : idAuta(idAuta_) {}
};

class Serwis
{
public:	
	int idSerwisu;
	string nazwaSerwisu;
	deque<NaprawianeAuto> naprawianeAuta;
	multimap <int, string> naprawioneUsterki; // int - idAuta, string - nazwa usterki
	Serwis(int idSerwisu_, string nazwaSerwisu_) : idSerwisu(idSerwisu_), nazwaSerwisu(nazwaSerwisu_){}
	~Serwis() { }

	// zwraca true jezeli poprawnie wykonano naprawe, zwraca false jezeli nie ma auta o takim id
	bool NaprawAuto(int idAuta_) 
	{
		int i = 0, n = naprawianeAuta.size();
		while (i < n && naprawianeAuta[i].idAuta != idAuta_)
			i++;

		if (naprawianeAuta[i].idAuta == idAuta_)
		{
			cout << "W aucie o nr " << naprawianeAuta[i].idAuta << " naprawiono " << endl;
			while (!naprawianeAuta[i].rzeczyDoNaprawy.empty())
			{	
				string usterka = naprawianeAuta[i].rzeczyDoNaprawy.top();
				cout << usterka << endl;
				naprawianeAuta[i].historiaNapraw.push_back(usterka);
				naprawioneUsterki.insert(pair<int, string>(idAuta_, usterka));
				naprawianeAuta[i].rzeczyDoNaprawy.pop();
			}
			return true;
		}
		else
		{
			cout << "Nie ma auta o id " << idAuta_ << endl;
			return false;
		}
	}

	void WyswietlWszystkieNaprawy()
	{
		pair<int, string> usterka;
		cout << "Wszystkie wykonane naprawy w serwisie o id " << idSerwisu << " i nazwie " << nazwaSerwisu << endl;
		for (auto iter = naprawioneUsterki.begin(); iter != naprawioneUsterki.end(); iter++)
		{
			usterka = *iter;
			cout << "Id auta " << usterka.first << " naprawiono " << usterka.second << endl;
		}
		
	}
};

int losujLiczbe(int start, int koniec)
{
	return (rand() % (koniec - start) + 1);
}

int main()
{
	srand(time(NULL));
	const int start = 1, koniec = 100;
	int idSerwis1 = losujLiczbe(start, koniec);
	int idSerwis2 = idSerwis1;
	while (idSerwis1 == idSerwis2)
		idSerwis2 = losujLiczbe(start, koniec);
	int idAuta1 = losujLiczbe(start, koniec);
	int idAuta2 = idAuta1;
	while (idAuta1 == idAuta2)
		idAuta2 = losujLiczbe(start, koniec);
	int idAuta3 = losujLiczbe(start, koniec);
	
	vector <Serwis> serwisy;
	Serwis serwisMarian(idSerwis1, "Warsztat u Mariana");	

	
	NaprawianeAuto auto1(idAuta1);
	auto1.rzeczyDoNaprawy.push("Wymiana oleju");
	auto1.rzeczyDoNaprawy.push("Wymiana filtrow");

	NaprawianeAuto auto2(idAuta2);
	auto2.rzeczyDoNaprawy.push("Wymiana czujnika temperatury oleju");
	

	Serwis serwisGienek(idSerwis2, "Naprawy Gienek i kumple");
	
	NaprawianeAuto auto3(idAuta3);
	auto3.rzeczyDoNaprawy.push("Wymiana cewki zaplonowej");
	
	serwisMarian.naprawianeAuta.push_front(auto1);
	serwisMarian.naprawianeAuta.push_front(auto2);
	serwisy.push_back(serwisMarian);

	serwisGienek.naprawianeAuta.push_front(auto3);
	serwisy.push_back(serwisGienek);

	
	
	for (auto iter = serwisy.begin(); iter < serwisy.end(); iter++)
	{
		for (auto iterSerwis = iter->naprawianeAuta.begin(); iterSerwis < iter->naprawianeAuta.end(); iterSerwis++)
			iter->NaprawAuto(iterSerwis->idAuta);
	}

	for (auto iter = serwisy.begin(); iter < serwisy.end(); iter++)
	{
		for (auto iterSerwis = iter->naprawianeAuta.begin(); iterSerwis < iter->naprawianeAuta.end(); iterSerwis++)
			iterSerwis->WyswietlHistorie();
	}

	for (auto iter = serwisy.begin(); iter < serwisy.end(); iter++)
	{
		iter->WyswietlWszystkieNaprawy();
	}
	
	serwisy.clear();
}
