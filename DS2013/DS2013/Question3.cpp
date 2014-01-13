#include "Question3.h"

void main() {
	std::set_terminate(terminaison);
	Test t;
	try {
		try {
			t.f(2012);
			cout << "suite1" << endl;
		} catch(MonException x) {
			cout << "catch1: " << x.get_val() << endl;
		}
		t.f(2013);
		cout << "suite2" << endl;
	} catch(MonException& x) {
		cout << "catch2: " << x.get_val() << endl;
	}
	cout << "fin prog" << endl;

	system("pause");
}