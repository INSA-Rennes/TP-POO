/**
 * \file Fraction.cpp
 * \brief Methodes de la classe Fraction
 * \author Paul Chaignon
 * \author Xavier Fraboulet
 * \version 1.0
 * \date 09/10/13
 */
#include "Fraction.h"

/**
 * \fn Fraction
 * \brief Constructeur avec denominateur a 1.
 * \param[in] i Le numerateur (la valeur de la fraction).
 */
Fraction::Fraction(int i) {
	num = i;
	den = 1;
}

/**
 * \fn Fraction
 * \brief Constructeur
 * \param[in] num Le numerateur.
 * \param[in] den Le denominateur, doit etre different de 0.
 * \throw logic_error Si le denominateur est a 0.
 */
Fraction::Fraction(int num, int den) {
	if(den == 0) {
		throw std::logic_error("Creation d'une fraction avec zero au denominateur");
	}
	this->num = num;
	this->den = den;
}

/**
 * \fn overflowMultiplication
 * \brief Verifie qu'aucun overflow ou underflow n'a lieu lors de la multiplication de 2 entiers.
 * \param[in] a Le premier entier.
 * \param[in] b Le deuxieme entier. 
 * \return Vrai si un overflow ou underflow a lieu.
 */
bool Fraction::overflowMultiplication(int a, int b) const {
	if(abs(a) > std::numeric_limits<int>::max()/abs(b)) {
		return true;
	}
	if(a > std::numeric_limits<int>::min()/b) {
		return true;
	}
	return false;
}

/**
 * \fn overflowAddition
 * \brief Verifie qu'aucun overflow ou underflow n'a lieu lors de l'addition de 2 entiers.
 * \param[in] a Le premier entier.
 * \param[in] b Le deuxieme entier. 
 * \return Vrai si un overflow ou underflow a lieu.
 */
bool Fraction::overflowAddition(int a, int b) const {
	if(a>0 && b>0 && a>std::numeric_limits<int>::max()-b) {
		return true;
	}
	if(a<0 && b<0 && a<std::numeric_limits<int>::min()-b) {
		return true;
	}
	return false;
}

/**
 * \fn overflowSoustraction
 * \brief Verifie qu'aucun overflow ou underflow n'a lieu lors de la soustraction de 2 entiers.
 * \param[in] a Le premier entier.
 * \param[in] b Le deuxieme entier. 
 * \return Vrai si un overflow ou underflow a lieu.
 */
bool Fraction::overflowSoustraction(int a, int b) const {
	if(a>0 && b<0 && a>std::numeric_limits<int>::max()+b) {
		return true;
	}
	if(a<0 && b>0 && a<std::numeric_limits<int>::min()+b) {
		return true;
	}
	return false;
}

/**
 * \fn operator+
 * \brief Redefinie l'operation d'addition pour deux fractions.
 * \param[in] f La fraction a ajouter a la fraction courante.
 * \return La fraction resultat.
 * \throw logic_error Si un overflow ou underflow a lieu.
 */
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

/**
 * \fn operator-
 * \brief Redefinie l'operation de soustraction pour deux fractions.
 * \param[in] f La fraction a soustraire a la fraction courante.
 * \return La fraction resultat.
 * \throw logic_error Si un overflow ou underflow a lieu.
 */
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

/**
 * \fn operator/
 * \brief Redefinie l'operation de division pour deux fractions.
 * \param[in] f La fraction qui doit diviser la fraction courante.
 * \return La fraction resultat.
 * \throw logic_error Si un overflow ou underflow a lieu.
 */
Fraction Fraction::operator/(const Fraction& f) const {
	if(f.num == 0) {
		throw std::logic_error("Division par zero.");
	}
	return this->operator*(Fraction(f.den, f.num));
}

/**
 * \fn operator*
 * \brief Redefinie l'operation de multiplication pour deux fractions.
 * \param[in] f La fraction a multiplier a la fraction courante.
 * \return La fraction resultat.
 * \throw logic_error Si un overflow ou underflow a lieu.
 */
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

/**
 * \fn eval
 * \brief Evalue une fraction.
 * \return La valeur decimale resultat de l'evaluation de la fraction.
 */
double Fraction::eval() {
	return num / den;
}