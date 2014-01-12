#include "Livre.h"

Livre::Livre(std::string a, std::string t, int n) {
	this->auteur = a;
	this->titre = t;
	this->nbPages = n;
}

bool Livre::recherche(std::string a) const {
	if(this->auteur == a) {
		return true;
	}
	return false;
}