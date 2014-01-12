#include "Roman.h"

Roman::Roman(std::string a, std::string c, std::string t, int n): Livre(a, t, n) {
	this->collection = c;
}

void Roman::imprime(std::string nomImprimante) const {
	std::cout << "Impression de Roman(" << this->numero << ") sur l'imprimante " << nomImprimante << std::endl;
}