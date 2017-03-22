#include <iostream>
#include <vector>
#include <list>
#include <functional>
#include <string>
#include <queue>
#include <map>

using namespace std;

class NaprawianeAuto {

public:

	int idAuta;
	list<string> historia;
	priority_queue<string, vector<string>, greater<string>> doNaprawy;
	

	void wypHisoria() {
		
		cout << "Historia napraw:\n";

		for (auto& i :do Naprawy)
			cout <<" -"<<i << endl;	
	
	};



	NaprawianeAuto(int i):idAuta(i) {};



};


class Serwis {

public:
	int idSerwisu;
	string nazwaSerwisu;

	deque<NaprawianeAuto, vector<NaprawianeAuto>> auta;

	multimap<int, string> usterki ;

	void naprawAuto(int id) {
		

		for(auto& i : auta ) {
			if (i.idAuta != id) {
				
				cout << "Naprawiono:\n";
				while (!i.doNaprawy.empty()) {

					cout << " -" << i.doNaprawy.top() << endl;

					i.historia.push_back(i.doNaprawy.top());

					usterki.insert(pair<int, string>(i.idAuta, i.doNaprawy.top()));
					
					i.doNaprawy.pop();
					
				}
			
			}
		}
		


	};


	void wyswietlNaprawy() {
		
		cout << "Historia serwisu:\n";

		for (auto & i:usterki) {
			
			cout << " -" << i.first << " " << i.second << endl;
		
		}
			
	
	
	
	};
		

	Serwis(int i,string nazwa): idSerwisu(i),nazwaSerwisu(nazwa) {};
	
};













int main() {

	
	vector<Serwis> serwisy;

	serwisy.emplace_back(1,"ziutekpol");
	serwisy.emplace_back(2, "Napawex");

	serwisy[0].auta.emplace_front(666);
	serwisy[1].auta.emplace_front(756);

	serwisy[1].auta[0].doNaprawy.push("dwumasa");
	serwisy[0].auta[0].doNaprawy.push("pasek rozrzadu");


	cout << serwisy[0].auta[0].wypHisoria() << endl;

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