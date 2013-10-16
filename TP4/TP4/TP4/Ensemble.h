#ifndef ENSEMBLE_H
#define ENSEMBLE_H

#include "List.h"

template <class T> class Ensemble;
template <class T> class EnsembleIterator;

template <class T> class EnsembleElement: public ListElement {

};

template <class T> class Ensemble;

template <class T> class Ensemble: public List {

};

template <class T> class EnsembleIterator: public ListIterator  {

};

#endif