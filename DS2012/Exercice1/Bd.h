#pragma once

#include "Livre.h"
#include <string>
#include <iostream>

class Bd: public Livre {
private:
	std::string dessinateur;

public:
	Bd(std::string a, std::string d, std::string t, int n);
	virtual void imprime(std::string nomImprimante) const;
};