#include <thread>
#include <iostream>
#include <string>
#include <mutex>
#include <atomic>
#include <vector>


using namespace std;



void print1(unsigned int x) {
	for (int i = 0; i < 5; i++)
		cout << x << "  ";
	cout << "\n";
}

void print2(unsigned int x) {
	static mutex mux;
	mux.lock();
	for (int i = 0; i < 5; i++)
		cout << x << "  ";
	cout << "\n";
	mux.unlock();
}

void scalarProduct(const vector<int>& v1, const vector<int>& v2, int from, int to, atomic<int>& sum) {
	int tmpSum=0;

	for (; from < to; from++)
		tmpSum += v1[from] * v2[from];

	sum += tmpSum;
}

class Employee {
public:
	string name;
	vector<string> history;
	mutex mux;
	
	Employee(string name) :name(name) {}

	void print() {
		cout << "Call History of " << name << endl;
		for (auto & i : history)
			cout << i << endl;

		cout << endl << endl;
	}




};

void call(Employee &e1, Employee &e2) {

	while (-1==try_lock(e1.mux, e2.mux)) {
		
		cout << e1.name << " i " << e2.name<<" rozmawiaja" << endl;

		e1.history.push_back(e2.name);
		e2.history.push_back(e1.name);
		
		this_thread::sleep_for(1s);
		cout << "koniec rozmowy"<<endl<<endl;
		e1.mux.unlock();
		e2.mux.unlock();
		break;
	}



}



int main() {


	vector<thread> threads(15);

	cout << "ZAD 1\n\n";

	//print1
	int k = 0;
	for (auto & i : threads)
		i = thread(print1, k++);
	
	for (auto& i : threads)
		i.join();


	cout << endl << endl;
	//print2
	k = 0;
	for (auto & i : threads)
		i = thread(print2, k++);

	for (auto& i : threads)
		i.join();

	cout << "\n\n\n\ZAD 2\n\n";

	threads.resize(thread::hardware_concurrency());

	vector<int> v1(1000),v2(1000);
	atomic_int sum = 0;

	for (auto & i : v1)
		i = 8;

	for (auto & i : v2)
		i = 8;

	int part =( v1.size() / thread::hardware_concurrency() );
	int start = 0;

	for (auto & i : threads) {	
		i = thread(scalarProduct, v1, v2, start, start + part, ref(sum));
		start += part;	
	}

	for (auto& i : threads)
		i.join();

	cout << sum << endl << endl;

	cout << "\n\n\n\ZAD 3\n\n";

	Employee Bartek("Bartek"), Janusz("Janusz"), Bartoslawa("Bartoslawa");

	threads.clear();
	threads.emplace_back(call, ref(Bartek), ref(Bartoslawa));
	threads.emplace_back(call, ref(Janusz), ref(Bartoslawa));
	threads.emplace_back(call, ref(Janusz), ref(Bartek));


	for (auto& i : threads)
		i.join();

	Bartek.print();
	Janusz.print();
	Bartoslawa.print();



}