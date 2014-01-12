#pragma once

#include <string>

class Ouvrage {
private:
	static int cpt;

protected:
	int numero;

public:
	Ouvrage();
	virtual void imprime(std::string nomImprimante) const =0;
	virtual bool recherche(std::string a) const =0;
};