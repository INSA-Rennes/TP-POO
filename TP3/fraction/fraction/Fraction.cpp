#include "Fraction.h"

Fraction::Fraction(int i) {
	num = i;
	den = 1;
}

Fraction::Fraction(int num, int den) {
	if(den == 0) {
		throw std::logic_error("Creation d'une fraction avec zero au denominateur");
	}
	this->num = num;
	this->den = den;
}

bool Fraction::overflowMultiplication(int a, int b) const {
	if(abs(a) > std::numeric_limits<int>::max()/abs(b)) {
		return true;
	}
	if(a > std::numeric_limits<int>::min()/b) {
		return true;
	}
	return false;
}

bool Fraction::overflowAddition(int a, int b) const {
	if(a>0 && b>0 && a>std::numeric_limits<int>::max()-b) {
		return true;
	}
	if(a<0 && b<0 && a<std::numeric_limits<int>::min()-b) {
		return true;
	}
	return false;
}

bool Fraction::overflowSoustraction(int a, int b) const {
	if(a>0 && b<0 && a>std::numeric_limits<int>::max()+b) {
		return true;
	}
	if(a<0 && b>0 && a<std::numeric_limits<int>::min()+b) {
		return true;
	}
	return false;
}

Fraction Fraction::operator+(const Fraction& f) const {
	if(this->overflowMultiplication(f.num, this->den)) {
		throw std::logic_error("Overflow sur le numerateur lors de l'addition.");
	}
	int mult1 = f.num * this->den;
	
	if(this->overflowMultiplication(f.den, this->num)) {
		throw std::logic_error("Overflow sur le numerateur lors de l'addition.");
	}
	int mult2 = f.den * this->num;

	if(this->overflowAddition(f.num, this->num)) {
		throw std::logic_error("Overflow sur le numerateur lors de l'addition.");
	}
	int numerateur = mult1 + mult2;

	if(this->overflowMultiplication(f.num, this->num)) {
		throw std::logic_error("Overflow sur le denominateur lors de l'addition.");
	}
	int deno = this->den * f.den;

	return Fraction(numerateur, deno);
}

Fraction Fraction::operator-(const Fraction& f) const {
	if(this->overflowMultiplication(f.num, this->den)) {
		throw std::logic_error("Overflow sur le numerateur lors de la soustraction.");
	}
	int mult1 = f.num * this->den;
	
	if(this->overflowMultiplication(f.den, this->num)) {
		throw std::logic_error("Overflow sur le numerateur lors de la soustraction.");
	}
	int mult2 = f.den * this->num;

	if(this->overflowSoustraction(f.num, this->num)) {
		throw std::logic_error("Overflow sur le numerateur lors de la soustraction.");
	}
	int numerateur = mult1 - mult2;

	if(this->overflowMultiplication(f.num, this->num)) {
		throw std::logic_error("Overflow sur le denominateur lors de la soustraction.");
	}
	int deno = this->den * f.den;

	return Fraction(numerateur, deno);
}

Fraction Fraction::operator/(const Fraction& f) const {
	if(f.num == 0) {
		throw std::logic_error("Division par zero.");
	}
	return this->operator*(Fraction(f.den, f.num));
}

Fraction Fraction::operator*(const Fraction& f) const {
	if(this->overflowMultiplication(f.num, this->num)) {
		throw std::logic_error("Overflow sur le numerateur lors de la multiplication.");
	}
	int numerateur = f.num * this->num;

	if(this->overflowMultiplication(f.den, this->den)) {
		throw std::logic_error("Overflow sur le numerateur lors de la multiplication.");
	}
	int deno = this->den * f.den;

	return Fraction(numerateur, deno);
}

double Fraction::eval() {
	return num / den;
}