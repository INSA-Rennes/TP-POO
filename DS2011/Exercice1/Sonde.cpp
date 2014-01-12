#include "Sonde.h"
#include <iostream>

int Sonde::GetIndicateurConfiance() const {
	return this->indicateurConfiance;
}

void Sonde::ObtenirNouvelleMesure() {
	this->derniereMesure = this->mesures[this->nbAppels++];
}

Sonde::Sonde(float* m, int c) {
	this->nbAppels = 0;
	this->derniereMesure = -1;
	this->dernierIndice = -1;
	this->indicateurConfiance = c;
	this->mesures = m;
}