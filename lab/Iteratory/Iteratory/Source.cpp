#include<algorithm>
#include<iostream>
#include<vector>
#include<list>
#include<numeric>
#include<string>

class Student {

	int id;
	std::vector<int> oceny;
	float srednia;

public:

	void liczSrednia() {
	
		srednia = (float)std::accumulate(oceny.begin(), oceny.end(), 0)/oceny.size();
			
	}
	
	Student(int id_):id(id_) {
		
	
		for (size_t i = 0; i < 5; i++)
		{
			oceny.push_back(rand()%4+2);
		}
	
		liczSrednia();
	}

	void wyswietl() {
	
		std::cout <<"id=" <<id << "    ";

		for (auto o : oceny) {
			std::cout << o << " ";
		
		}

		std::cout <<"srednia="<< srednia << "\n";
	
	
	}

	float getSrednia() {

		return srednia;

	}

};

class Grupa {

	int idg;
	std::string name;
	std::vector<Student> studenci;

public:




	Grupa(int idg_,std::string name_):name(name_),idg(idg_) {
	
		for (size_t i = 0; i < 11; i++)
		{
			studenci.emplace_back(rand()%1000);
		}

	
	
	}

	void wyswietl() {
	
	
		std::cout << name << "   idg=" << idg << "\n";
		for_each(studenci.begin(), studenci.end(), [](Student &i) {i.wyswietl();});
	
	}

	void wyswietlOdwrotnie() {


		std::cout << name << "   idg=" << idg << "\n";
		for_each(studenci.rbegin(), studenci.rend(), [](Student &i) {i.wyswietl();});

	}


	void sortuj() {
	
	
		sort(studenci.begin(), studenci.end(), [](Student& a, Student& b) {return(a.getSrednia() > b.getSrednia());}  );
	
	}

	void usun() {
	
		studenci.erase(std::remove_if(studenci.begin(),
			studenci.end(),
			[](Student& s) {return (s.getSrednia()<4.0f);}),
			studenci.end());
	
	}


};


int main() {






	Grupa g1(2,"g1");
	g1.sortuj();
	g1.wyswietl();
	g1.wyswietlOdwrotnie();
	g1.usun();
	g1.wyswietl();


















}