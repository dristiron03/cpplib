#include <iostream>

class Semaphore {
	int ctr;
public:
	Semaphore() {ctr = 1;}
	void wait() {
		while (ctr == 0); // issue here is busy waiting and we are wasting CPU cycles.
		// instead we can use ready queue for binary semaphores.
		ctr--;
	}
	void signal() {
		ctr++;
	}
};

class Atomic_var {
	int val;
	Semaphore sm;
public:
	void increment(char x) {
		// we will use semaphore here.
		sm.wait();
		std::cout << x << "\n";
		val = val + 1;
		sm.signal();
	}
	int print() {
		return val;
	}
};
