#pragma once

#include "Sonde.h"

using namespace std;

class Temperature: public Sonde {
public:
	void Affiche() const;
	float CalculNouvelIndice();
	Temperature(float* m, int c);
};