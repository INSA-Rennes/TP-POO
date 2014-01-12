#include <iostream>
#include "Calcul.h"

using namespace std;

int main(int argc, char* argv[]) {
	Calcul<int> a;
	Calcul<int> t;
	
	cout << "a: " << a << endl;
	cout << "t: " << t << endl << endl;

	a = t.plus(1).plus(1);
	cout << "a: " << a << endl;
	cout << "t: " << t << endl << endl;

	a = t.Nplus(1).Nplus(1);
	cout << "a: " << a << endl;
	cout << "t: " << t << endl << endl;

	a = t.plus(1).Nplus(1);
	cout << "a: " << a << endl;
	cout << "t: " << t << endl << endl;

	cout << "SUITE:" << endl;
	
	Calcul<int> ap;
	Calcul<int> dt;

	ap.prog(Add<int>(30));
	cout << "ap: +30 " << ap << endl;

	ap.prog(Mul<int>(10));
	cout << "ap: *10 " << ap << endl;

	ap = dt.Nprog(Add<int>(1)).prog(Add<int>(1));
	cout << "ap: " << ap << endl;
	cout << "dt: " << dt << endl << endl;

	system("pause");

	return 0;
}