#include "Pion.h"

Pion::~Pion() {

}

std::string Pion::getIdent() const {
	return this->identifiant;
}

int Pion::getX() const {
	return this->coordX;
}

int Pion::getY() const {
	return this->coordY;
}

void Pion::mutation() {

}

Pion::Pion(std::string n, int x, int y) {
	this->coordX = x;
	this->coordY = y;
	this->identifiant = n;
}

std::ostream& operator<<(std::ostream& os, const Pion& p) {
	os << p.getIdent() << " (" << p.getX() << ", " << p.getY() << ") : " << p.propriete() << std::endl;
	return os;
}