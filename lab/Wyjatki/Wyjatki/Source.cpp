#include<iostream>
#include<fstream>
#include<vector>
using namespace std;


struct Element{

	double l;

};

class Blad {

public:

	virtual void write() {
		cout << "Blad\n";

	};

	Blad() {}

};

class DzielZero :public Blad {

public:

	void write() {

		
		cout << "wystapilo dzielenie przez zero\n";
	}

	DzielZero() {}

};

class BladPliku :public Blad {

public:

	void write() {

		
		cout << "wystapil zly plik\n";
	}

	BladPliku() {}

};



void wczytaj(vector<Element*> v)
{
	fstream plik;


	try {
		plik.open("dane.txt");
		if (!plik.good())
		{
			throw BladPliku();
		}
	}
	catch (BladPliku &b)
	{
		b.write();
		throw;
	}

	try {
		
		while(!plik.eof()) {
			Element* e = new Element;
			plik >> e->l;
			v.push_back(e);
		}
	
	}
	catch (bad_alloc) {
	
		cout << "badalloc\n";
	
	}


	return;
}

void podziel(vector<Element*> v, double n) {
	
	if (n == 0)
		throw DzielZero();

	for (auto c : v) {
	
		c->l = (c->l )/ n;
	}

	
}

int main() {


	vector<Element*> vec;

	try {

		wczytaj(vec);

	}
	catch (Blad &b) {

		b.write();

	}


	try {
	podziel(vec, 1);
	}
	catch (Blad &b) {
	
		b.write();
	}









}