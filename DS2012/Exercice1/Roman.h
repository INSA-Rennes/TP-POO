#pragma once

#include "Livre.h"
#include <string>
#include <iostream>

class Roman: public Livre {
private:
	std::string collection;

public:
	Roman(std::string a, std::string c, std::string t, int n);
	virtual void imprime(std::string nomImprimante) const;
};