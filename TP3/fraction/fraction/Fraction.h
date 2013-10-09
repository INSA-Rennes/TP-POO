#include <stdexcept>
#include <iostream>

class Fraction {
private:
	int num;
	int den;
	bool overflowMultiplication(int, int) const;
	bool overflowAddition(int, int) const;
	bool overflowSoustraction(int, int) const;

public:
	Fraction(int);
	Fraction(int, int);
	Fraction operator+(const Fraction&) const;
	Fraction operator-(const Fraction&) const;
	Fraction operator/(const Fraction&) const;
	Fraction operator*(const Fraction&) const;
	double eval();
};