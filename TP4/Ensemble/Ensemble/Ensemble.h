#ifndef ENSEMBLE_H
#define ENSEMBLE_H

#include "List.h"

template <class T> class Ensemble: public List<T> {
public:
	Ensemble<T> operator+(const Ensemble<T>& e) const {
		Ensemble<T> result(*this);
		result.addAllElements(e);
		return result;
	}

	Ensemble<T> operator-(const Ensemble<T>& e) const {
		Ensemble<T> result(*this);
		result.delAllElements(e);
		return result;
	}

	Ensemble<T> operator/(const Ensemble<T>& e) const {
		return (*this - e) + (e - *this);
	}

	Ensemble<T> operator*(const Ensemble<T>& e) const {
		Ensemble<T> result;
		ListIterator<T> it = e.beg();
		while(!it.finished()) {
			T el = it.get();
			if(*this == el) {
				result.addElement(el);
			}
			it++;
		}
		return result;
	}

	virtual void addElement(const T& e, eListPosition pos = LP_first) {
		if(!(*this == e)) {
			List::addElement(e);
		}
	}
};

#endif