#pragma once

#include <iostream>
#include "Add.h"
#include "Mul.h"

template<class T> class Calcul {
private:
	T val;
	static const int valDefaut = 0;

public:
	Calcul(const Calcul<T>& c);
	Calcul();
	Calcul(T v);
	Calcul Nplus(T n) const;
	Calcul& plus(T n);
	template<class A> Calcul& prog(A& objf);
	template<class A> Calcul Nprog(A& objf) const;
	T valeur();
	friend std::ostream& operator<<(std::ostream& os, const Calcul<int>& c);
};

template<class T> Calcul<T>::Calcul(const Calcul<T>& c) {
	this->val = c->val;
}

template<class T> Calcul<T>::Calcul(T v) {
	this->val = v;
}

Calcul<int>::Calcul() {
	this->val = valDefaut;
}

template<class T> Calcul<T> Calcul<T>::Nplus(T n) const {
	return Calcul(this->val + n);
}

template<class T> Calcul<T>& Calcul<T>::plus(T n) {
	this->val += n;
	return *this;
}

template<class T> template<class A> Calcul<T>& Calcul<T>::prog(A& objf) {
	this->val = objf(this->val);
	return *this;
}

template<class T> template<class A> Calcul<T> Calcul<T>::Nprog(A& objf) const {
	return Calcul(objf(this->val));
}

template<class T> T Calcul<T>::valeur() {
	return this->val;
}

std::ostream& operator<<(std::ostream& os, const Calcul<int>& c) {
    os << c.val;
    return os;
}