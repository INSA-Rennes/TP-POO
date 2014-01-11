#include <iostream>

using namespace std;

class Base {
public:
	Base() {
		cout << "Cons Base" << endl;
	}
	virtual void trace() {
		cout << "Base::trace()" << endl;
	}
	~Base() {
		cout << "Base::~Base()" << endl;
	}
};

class Derivee: public Base {
public:
	Derivee() {
		cout << "Cons Derivee" << endl;
	}
	virtual void trace() {
		cout << "Derivee::trace()" << endl;
	}
	~Derivee() {
		cout << "Derivee::~Derivee()" << endl;
	}
};