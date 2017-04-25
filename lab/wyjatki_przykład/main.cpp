#include <iostream>
#include <fstream>

using namespace std;

struct Element
{
	Element* next;
	double liczba;
};

class Blad
{
public:
	Blad() {}
	void Write()
	{
		cout << "Blad typu Blad\n";
	}
};

class BladOtwarcia: public Blad
{
public:
	BladOtwarcia() {}
	void Write()
	{
		cout << "Blad typu BladOtwarcia\n";
	}
};

class DzieleniePrzezZero : public Blad
{
public:
	DzieleniePrzezZero() {}
	void Write()
	{
		Blad::Write();
		cout << "Blad typu DzieleniePrzezZero\n";
	}
};


void Wczytaj(Element *&el) 
{
	fstream plik;


		try {
			plik.open("sciezka.txt");
			if (!plik.good()) 
			{
				throw BladOtwarcia();
			}
		}
		catch (BladOtwarcia &b) 
		{
			b.Write();
			cout <<"blad 1" << endl;
			throw ;
		}
	
	
	try
	{
		el = new Element;
		el->next = nullptr;
		plik >> el->liczba;
		while (!plik.eof())
		{

			Element *tmp = new Element;
	
			plik >> tmp->liczba;
			tmp->next = el;
			el = tmp;
		}
		
	}
	catch (bad_alloc)
	{
		cout << "Nie mozna zaalokowac pammieci\n";
		exit(1);
	}
	return;
}

void Podziel(Element *el, double n)
{
	
		if (n == 0) throw DzieleniePrzezZero();
		Element *tmp = el;
		while (tmp)
		{
			tmp->liczba /= n;
			tmp = tmp->next;
		}
	
}

int main() 
{
	Element *el;
	try
	{
		Wczytaj(el);

	}
	catch (BladOtwarcia &b)
	{
		b.Write();
		cout << "blad 2" << endl;
		return 0;
	}
	cout << "Podaj liczbe, przez ktora chcesz podzielic: ";
	double n;
	cin >> n;
	try
	{
		Podziel(el, n);
	}
	catch (DzieleniePrzezZero &b)
	{
		b.Write();
	}
	catch (Blad &b)
	{
		b.Write();
		
	}
	Element *tmp = el->next;
	while (el)
	{
		Element *tmp = el->next;
		delete el;
		el = tmp;
		
	}
	return 0;
}