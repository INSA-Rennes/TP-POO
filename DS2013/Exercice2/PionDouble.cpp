#include "PionDouble.h"

PionDouble::~PionDouble() {
	delete this->pionBN;
}

std::string PionDouble::getIdent() const {
	return this->pionBN->getIdent();
}

int PionDouble::getX() const {
	return this->pionBN->getX();
}

int PionDouble::getY() const {
	return this->pionBN->getY();
}

void PionDouble::mutation() {
	int x = this->getX();
	int y = this->getY();
	std::string ident = this->getIdent();
	if(this->_mode == TPionBlanc) {
		this->pionBN = new PionNoir(ident, x, y);
	} else {
		this->pionBN = new PionBlanc(ident, x, y);
	}
}

PionDouble::PionDouble(std::string n, int x, int y) {
	this->_mode = TPionNoir;
	this->pionBN = new PionNoir(n, x, y);
}

std::string PionDouble::propriete() const {
	return "Pion double";
}

std::ostream& operator<<(std::ostream& os, const PionDouble& p) {
	os << *p.pionBN;
	return os;
}