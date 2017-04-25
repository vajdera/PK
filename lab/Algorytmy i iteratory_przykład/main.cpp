#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <numeric>
#include <ctime>
#include <string>


using namespace std;

class Student {

	int id;
	vector<int> oceny;
	float srednia = 0;
public:
	void LiczSrednia() {

		srednia = (float)accumulate(oceny.begin(), oceny.end(), 0) / (float)oceny.size();

	}
	Student(int i = 0) :id(i) {
		for (int i = 0; i < 5; i++) {
			oceny.push_back((rand() % 4) + 2);
		}
		LiczSrednia();
	};

	void Wyswietl() {
		cout << "Student o id = " << id << " i sredniej = " << srednia << endl;
		for (auto iter = oceny.begin(); iter != oceny.end(); iter++)
			cout << *iter << " ";

		cout << endl << endl;
	}

	float getSrednia() {
		return srednia;
	}


};


// FUNKCJE POTRZEBNE W PRZYPADKU GDY NIE UZYWAMY LAMBDY
bool czyWiekszy(Student& A,Student& B)
{
	return (A.getSrednia() > B.getSrednia());

}
void drukuj(Student& student)
{
	student.Wyswietl();
}
/////////////////////////////////////////////////////////////
class Grupa {

	string nazwa;
	int idG;
	list<Student> lista;
	//float sredniaG = 0;
public:

	Grupa(string n, int id) : nazwa(n), idG(id) {

		for (int i = 1; i < 16; i++) {
			lista.push_back(Student(i));
		}
	}




	void Wyswietl() {
		cout << "Grupa " << nazwa << " o id = " << idG << endl;

		for_each(lista.begin(), lista.end(), drukuj);
		// ZA POMOCA LAMBDY
		/*for_each(lista.begin(), lista.end(), [](Student iter) {
			iter.Wyswietl();

		});*/
	}

	void WyswietlNaOdwrot() {
		cout << "Grupa " << nazwa << " o id = " << idG << endl;
		for (list<Student>::reverse_iterator iter = lista.rbegin(); iter != lista.rend(); iter++)
			iter->Wyswietl();

	}

	
	void Sortuj() {
		lista.sort(czyWiekszy);// mozliwosc zastosowania wyrazenia lambda zamiast pisania w³asnej funkcje
		// jezeli kontener by³by np. vectorem to mo¿na zastosowac funkcje sort z biblioteki 
		// algorithm sort(it poczatek, it koniec, opcjonalny funktor)

		//ZA POMOCA LAMBDY:
		/*lista.sort([](const Student& a,const Student& b){
			return (a.srednia > b.srednia); });*/

	}
	// UWAGA: remove_if nie zmienia rozmiaru kontenera, tzn. ¿e je¿eli coœ zosta³o usuniête to dope³nia puste miejsce 
	// na koñcu niezdefiiowana wartoscia
	
	void Usun() {
		auto it=remove_if(lista.begin(), lista.end(), [](Student& s) {return (s.getSrednia() < 3.0); }); // moze zostaæ lambda czy funkcja?
		lista.erase(it,lista.end());
	}


};






int main()
{
	srand(time(NULL));


	Grupa moja("X", 3);
	cout << "Wygenerowana grupa...\n\n";
	moja.Wyswietl();
	cout << endl;
	moja.Usun();
	cout << "Grupa po usunieciu uczniow ze srednia ponizej 3.0\n\n";
	moja.Wyswietl();
	cout << endl;

	Grupa inna("Y", 5);
	cout << "Grupa wyswietlona od konca\n\n";
	inna.WyswietlNaOdwrot();
	cout << "Grupa posortowana wg sredniej\n\n";
	inna.Sortuj();
	inna.Wyswietl();
	cout << endl;
	

	return 0;
};
