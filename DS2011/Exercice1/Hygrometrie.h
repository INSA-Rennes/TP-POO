#pragma once

#include "Sonde.h"
#include <math.h>

using namespace std;

class Hygrometrie: public Sonde {
public:
	void Affiche() const;
	float CalculNouvelIndice();
	Hygrometrie(float* m, int c);
};