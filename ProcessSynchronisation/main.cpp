// Run:  g++ -pthread -std=c++14 -o main main.cpp
#include <bits/stdc++.h>
#include <thread>
#include "Semaphore.h"


int main() {
	Atomic_var atomic_var; // Either declare globally or pass the object by reference.

	auto cnt = [&atomic_var](char x) {
		for (int i = 0; i < 50; i++) {atomic_var.increment(x);}
	};
	std::thread A(cnt, 'A');
	std::thread B(cnt, 'B');

	A.join();
	B.join();

	std::cout << atomic_var.print() << "\n";
}
