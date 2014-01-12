#include "Bd.h"

Bd::Bd(std::string a, std::string d, std::string t, int n): Livre(a, t, n) {
	this->dessinateur = d;
}

void Bd::imprime(std::string nomImprimante) const {
	std::cout << "Impression du Bd(" << this->numero << ") sur l'imprimante " << nomImprimante << std::endl;
}