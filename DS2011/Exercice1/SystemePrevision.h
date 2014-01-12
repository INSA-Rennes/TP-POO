#pragma once

#include "Sonde.h"
#include <vector>
#include <iostream>

class SystemePrevision {
private:
	std::vector<Sonde*> sondes;

public:
	void Affiche();
	void AjoutSonde(Sonde& s);
	float CalculMoyenneIndices();
};