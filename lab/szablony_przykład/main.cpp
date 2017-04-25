#include <iostream>
#include <string>

using namespace std;


//Zadanie 1. - szablon klasy 
template<typename Typ, int rozm>
class Bufor
{
public:
	Typ tab[rozm];
	Bufor() {
		for (int i = 0; i < rozm; i++)
		{
			tab[i] = 0;
		}
	}
};

//Zadanie 2. - szablon klasy pochodnej
template<typename Typ, int rozm>
class Bufor_ile : public Bufor<Typ, rozm> {
	int ile_elem;
public:
	Bufor_ile() : Bufor(), ile_elem(0) {};
	void dodaj_elem() {
		cout << "Nowy element: ";
		if (ile_elem < rozm)
		{
			cin >> tab[ile_elem];
			ile_elem++;
		}
		else   // w przypadku gdy pojemnik pelny, wyrzucany jest wyjatek
			throw ile_elem;
	}
};

//Zadanie 3. - szablon klasy szczególnej
template<int rozm>
class Bufor_ile<char*, rozm> : public Bufor<char *, rozm> {
	int ile_elem;
public:
	Bufor_ile() {
		for (int i = 0; i < rozm; i++)
		{
			tab[i] = NULL;
		}
		ile_elem = 0;
	}
	~Bufor_ile() {
		for (int i = 0; i < rozm; i++)
		{
			delete tab[i];
		}
		ile_elem = 0;
	};
	void dodaj_elem() {
		cout << "Nowy element: ";
		if (ile_elem < rozm)
		{
			tab[ile_elem] = new char[20];
			cin >> tab[ile_elem];
			ile_elem++;
		}
		else   // w przypadku gdy pojemnik pelny, wyrzucany jest wyjatek
			throw ile_elem;
	}
};

//Zadanie 4. - szablon funkcji o zmiennej liczbie argumentow
template <typename T>
void wypiszListe(T wartosc) {
	cout << " - " << wartosc << "." << endl << endl;
}

template <typename Pierwszy, typename ... Reszta>
void wypiszListe(Pierwszy wartosc1, Reszta ... wartoscn) {
	cout << " - " << wartosc1 << ";" << endl;
	wypiszListe(wartoscn...);
}


int main()
{
	//zadanie 1.
	Bufor<char, 20> b1;
	Bufor<char, 10> b2;
	if (typeid(b1) == typeid(b2))
		cout << "Identyczne typy" << endl; //Dwa typy wygenerowane ze wspolnego wzorca sa identyczne tylko gdy identyczne sa argumenty wzorca
	else
		cout << "Porownywane typy sa rozne" << endl;

	//zadanie 2.
	Bufor_ile<int, 2> bi;
	try {
		for (int i = 0; i < 2; i++) {
			bi.dodaj_elem();
		}
	}
	catch (int pelny) {
		cout << "Bufor pelny: liczba elementow=rozmiar bufora=" << pelny << endl;
	}
	wypiszListe(bi.tab[0], bi.tab[1]);

	//zadanie 3.
	Bufor_ile<char*, 3> ci;
	try {
		for (int i = 0; i < 3; i++) {
			ci.dodaj_elem();
		}
	}
	catch (int pelny) {
		cout << "Bufor pelny: liczba elementow=rozmiar bufora=" << pelny << endl;
	}
	wypiszListe(ci.tab[0], ci.tab[1], ci.tab[2]);

	//zadanie 4.
	wypiszListe("Jak to skopiujecie to bedzie", 0, 'a', 0.5, "puntow wszyscy chcecie!");

	getchar();
	getchar();
	return 0;
}