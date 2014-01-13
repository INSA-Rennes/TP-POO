#include <iostream>
#include <exception>

using namespace std;

class MonException: public exception {
private:
	int val;

public:
	MonException():val(0) {
		cout << "MonException()" << endl;
	}
	MonException(const MonException& mex) {
		val = mex.val;
		cout << "MonException(const MonException& mex)" << endl;
	}
	MonException(int v):val(v) {
		cout << "MonException(int v)" << endl;
	}
	int get_val() {
		return val;
	}
};

class Test {
public:
	void f(int v) {
		if(v==2012) {
			throw MonException(v);
		} else {
			throw exception();
		}
	}
};

void terminaison(void) {
	cout << "Exception non geree !!" << endl;
	exit(1);
}