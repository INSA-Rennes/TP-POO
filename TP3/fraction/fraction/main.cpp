#include "Fraction.h"
#include <cassert>
#include "stdafx.h"

void main() {
	try {
		Fraction(5, 0);
		assert(false);
	} catch(std::exception& e) {}

	Fraction f1 = Fraction(10);
	Fraction f2 = Fraction(0, 2);
	try {
		Fraction mult = f1 / f2;
		assert(false);
	} catch(std::exception& e) {}
}

