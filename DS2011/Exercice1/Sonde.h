#pragma once

#define NB_MESURES 3
#include <iostream>

class Sonde {
private:
	int nbAppels;

protected:
	float derniereMesure;
	float dernierIndice;
	int indicateurConfiance;
	float* mesures;

public:
	virtual void Affiche() const =0;
	virtual float CalculNouvelIndice() =0;
	int GetIndicateurConfiance() const;
	void ObtenirNouvelleMesure();
	Sonde(float* m, int c);
};