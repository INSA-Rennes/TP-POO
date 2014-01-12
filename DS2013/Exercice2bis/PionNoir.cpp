#include "PionNoir.h"

PionNoir::PionNoir(std::string n, int x, int y): Pion(n, x, y) {

}

std::string PionNoir::propriete() const {
	return "Propriete :: pion noir";
}