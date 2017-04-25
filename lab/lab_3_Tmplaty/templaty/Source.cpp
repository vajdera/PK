#include <iostream>


using namespace std;

template <typename T,int size>
class Bufor {
	
public:
	T tab[size];

	Bufor() {
	
		for (int k = 0; k < size;k++)
			tab[k] = 0;
	
	}


};

template <typename T, int size>
class Bufor_ile :public Bufor<T,size> {

	int elem;
public:
	Bufor_ile():Bufor(),elem(0) {};

	void dodaj(T x) {
		
		if (elem >= size)
			throw elem;
		else {

			tab[elem] = x;
			elem++;
		
		}

	
	}
};

template <int size>
class Bufor_ile<char*,size> :public Bufor<char*, size> {

	int elem;
public:
	Bufor_ile() :Bufor(), elem(0) {
		for (int k = 0; k < size;k++)
			tab[k] = NULL;
	};

	~Bufor_ile() {
		for (int k = 0; k < size;k++) {
			delete[] tab[k];
			tab[k] = NULL;
		}
	}

	void dodaj(char* x) {

		if (elem >= size)
			throw elem;
		else {
			tab[elem] = new char[20];
			strcpy_s(tab[elem],20,x);
			elem++;

		}


	}
};

template<typename T>
void wypisz(T w) {
	cout <<"-"<< w << ".\n\n\n";
}


template<typename p,typename ...r>
void wypisz(p w1,r...wr) {
	cout << "-" << w1 << ";\n";

		wypisz(wr...);
}

int main() {


	Bufor<char, 20> buff1;
	Bufor<char, 10> buff2;

	if (typeid(buff1) == typeid(buff2))
		cout << "Sa takie same\n";
	else
		cout << "Nie sa takie same\n\n";

	Bufor_ile<int, 3> buff;
	
	buff.dodaj(1);
	buff.dodaj(2);
	buff.dodaj(3);
	try {
		buff.dodaj(4);
	}
	catch (int k) {
	
		cout<<"jest juz " << k << " elementow\n\n";
	
	}


	Bufor_ile<char*,2> buff3;

	char* s = "cos";
	buff3.dodaj(s);
	s = "nie cos";
	buff3.dodaj(s);
	s = "cos za duzo";
	try
	{
		buff3.dodaj(s);
	}
	catch (int k)
	{
		cout << "jest juz " << k << " elementow\n\n";
	}
	
	wypisz(buff.tab[0], buff.tab[1], buff.tab[2]);

	wypisz(buff3.tab[0], buff3.tab[1]);
}