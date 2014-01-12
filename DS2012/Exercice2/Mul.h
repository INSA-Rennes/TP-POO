#pragma once

template<class T> class Mul {
protected:
	T value;

public:
	Mul(T v);
	T operator()(const T& param);
};

template<class T> Mul<T>::Mul(T v) {
	this->value = v;
}

template<class T> T Mul<T>::operator()(const T& param) {
	return this->value * param;
}