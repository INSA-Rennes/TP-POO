#pragma once

template<class T> class Add {
protected:
	T value;

public:
	Add(T v);
	T operator()(const T& param);
};

template<class T> Add<T>::Add(T v) {
	this->value = v;
}

template<class T> T Add<T>::operator()(const T& param) {
	return this->value + param;
}