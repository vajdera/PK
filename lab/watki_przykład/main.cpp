#include <thread>
#include <iostream>
#include <string>
#include <mutex>
#include <atomic>
#include <vector>

using namespace std;
using namespace chrono;

void print1(unsigned int i) {
	for(int j = 0; j < 20; ++j)
		cout << i << " ";
	cout << endl;
}

void print2(unsigned int i) {
	static mutex ioMutex;
	ioMutex.lock();
	for(int j = 0; j < 20; ++j)
		cout << i << " ";
	cout << endl;
	ioMutex.unlock();
}

void scalar(vector<int>& vec1, vector<int>& vec2, unsigned int start, unsigned int end, atomic<int>& sum) {
	int partialSum = 0;
	for(;start < end; ++start)
		partialSum += vec1[start] * vec2[start];
	sum += partialSum;
}

class Employee {
public:
	Employee(string _name): name(_name) {}
	string name;
	vector<string> callHistory;
	mutex m;

	void output() const {
		cout << "Employee " << name << " was talking to: ";
		for( const auto& x: callHistory)
			cout << x << " ";
		cout << endl;
	}
};

void call(Employee& e1, Employee& e2) {
	static mutex ioMutex;
	{
		lock_guard<mutex> guard(ioMutex);
		cout << e1.name << " and " << e2.name << " are waiting for locks" << endl;
	}
	{
		lock(e1.m, e2.m);
		lock_guard<mutex> guard1(e1.m, adopt_lock);
		lock_guard<mutex> guard2(e2.m, adopt_lock);
		{
			lock_guard<mutex> guard(ioMutex);
			cout << e1.name << " and " << e2.name << " are talking" << endl;
		}
		e1.callHistory.push_back(e2.name);
		e2.callHistory.push_back(e1.name);
		this_thread::sleep_for(seconds(1));
	}

}

int main() {
	unsigned short nrThreads = 15;
	vector<thread> threads(nrThreads);
	cout << "Zadnie 1" << endl << endl;

	for(unsigned int i = 0; i < threads.size(); ++i)
		threads[i] = thread(print1, i);

	for(auto& x: threads)
		x.join();

	cout << endl << "print2" << endl << endl;

	for(unsigned int i = 0; i < threads.size(); ++i)
		threads[i] = thread(print2, i);

	for(auto& x: threads)
		x.join();

	cout << endl << "Zadnie 2" << endl << endl;

	nrThreads = thread::hardware_concurrency();
	threads.resize(nrThreads - 1);

	vector<int> vec1(1000);
	vector<int> vec2(vec1.size());
	atomic<int> sum(0);

	for(int& x: vec1)
		x = 1;

	for(int& x: vec2)
		x = 2;

	unsigned int slice = vec1.size() / nrThreads;
	unsigned int remainder = vec1.size() - slice * nrThreads;
	unsigned int start = 0, end = slice;
	for(auto& x: threads) {
		x = thread(scalar, ref(vec1), ref(vec2), start,  end, ref(sum));
		start = end;
		end = start + slice;
	}

	scalar(vec1, vec2, start, end + remainder, sum);

	for(auto& x: threads)
		x.join();

	cout << sum << endl;

	cout << endl << "Zadnie 3" << endl << endl;

	Employee alice("alice"), bob("bob"), christina("christina"), dave("dave");

	threads.clear();
	threads.emplace_back(call, ref(alice), ref(bob));
	threads.emplace_back(call, ref(christina), ref(bob));
	threads.emplace_back(call, ref(christina), ref(alice));
	threads.emplace_back(call, ref(dave), ref(bob));

	for(auto& x: threads)
		x.join();

	alice.output();
	bob.output();
	christina.output();
	dave.output();

	return 0;
}
