#pragma once

#include "Ouvrage.h"
#include <string>

class Livre: public Ouvrage {
protected:
	std::string auteur;
	int nbPages;
	std::string titre;

public:
	Livre(std::string a, std::string t, int n);
	virtual bool Livre::recherche(std::string a) const;
};