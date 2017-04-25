#include <iostream>
#include <vector>
#include <list>
#include <functional>
#include <string>
#include <queue>
#include <map>


class NaprawianeAuto {

public:

	int idAuta;
	std::list<std::string> historia;
	std::priority_queue<std::string, std::vector<std::string>, std::greater<std::string>> doNaprawy;
	

	void wypHisoria() {
		
		std::cout << "Historia napraw:\n";

		for (auto& i : historia)
			std::cout <<" "<< i << std::endl;
	
	}



	NaprawianeAuto(int i):idAuta(i) {}



};


class Serwis {

public:
	int idSerwisu;
	std::string nazwaSerwisu;

	std::deque<NaprawianeAuto>auta;

	std::multimap<int, std::string> usterki;

	void naprawAuto(int id) {
		

		for(auto& i : auta ) {
			if (i.idAuta == id) {
				
				std::cout << "Naprawiono:\n";
				while (!i.doNaprawy.empty()) {

					std::cout << " -" << i.doNaprawy.top() << std::endl;

					i.historia.push_back(i.doNaprawy.top());

					usterki.insert(std::pair<int, std::string>(i.idAuta, i.doNaprawy.top()));
					
					i.doNaprawy.pop();
					
				}
			
			}
		}
		


	}


	void wyswietlNaprawy() {
		
		std::cout << "Historia serwisu:\n";

		for (auto& i:usterki) {
			
			std::cout << " -" << i.first << " " << i.second << std::endl;
		
		}
			
	
	
	
	}
		

	Serwis(int i, std::string nazwa): idSerwisu(i),nazwaSerwisu(nazwa) {}
	
};


int main() {

	
	std::vector<Serwis> serwisy;

	serwisy.emplace_back(1,"ziutekpol");
	serwisy.emplace_back(2, "napawex");

	serwisy[0].auta.emplace_front(666);
	serwisy[1].auta.emplace_front(756);

	serwisy[1].auta[0].doNaprawy.push("dwumasa");
	serwisy[0].auta[0].doNaprawy.push("pasek rozrzadu");


	


	for (auto&i : serwisy) {
	
		for (auto&k : i.auta) {
			
			i.naprawAuto(k.idAuta);

			k.wypHisoria();
		
		}
	
	}


	for (auto&i : serwisy) {

		for (auto&k : i.auta) {

			i.wyswietlNaprawy();

		}

	}




	

	serwisy.clear();

}