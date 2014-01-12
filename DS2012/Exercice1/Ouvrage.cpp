#include "Ouvrage.h"

int Ouvrage::cpt = 0;

Ouvrage::Ouvrage() {
	this->numero = cpt;
	cpt++;
}