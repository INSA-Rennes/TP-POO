#include <iostream>

using namespace std;

class B {
public:
	virtual void trace() const {
		cout << "B::trace()" << endl;
	}
	virtual ~B() {

	}
	static void f(const B& x) {
		x.trace();
	}
	static void g(const B x) {
		x.trace();
	}
	static void h(const B* x) {
		x->trace();
	}
};

class D: public B {
public:
	virtual void trace() const {
		cout << "D::trace()" << endl;
	}
};