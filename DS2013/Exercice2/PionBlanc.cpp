#include "PionBlanc.h"

PionBlanc::PionBlanc(std::string n, int x, int y): Pion(n, x, y) {

}

std::string PionBlanc::propriete() const {
	return "Propriete :: pion blanc";
}