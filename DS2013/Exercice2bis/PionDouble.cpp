#include "PionDouble.h"

PionDouble::~PionDouble() {

}

void PionDouble::mutation() {
	if(this->_mode == TPionBlanc) {
		this->_mode = TPionNoir;
	} else {
		this->_mode = TPionBlanc;
	}
}

PionDouble::PionDouble(std::string n, int x, int y): Pion(n, x, y), PionBlanc(n, x, y), PionNoir(n, x, y) {
	this->_mode = TPionNoir;
}

std::string PionDouble::propriete() const {
	if(this->_mode == TPionNoir) {
		return PionNoir::propriete();
	}
	return PionBlanc::propriete();
}