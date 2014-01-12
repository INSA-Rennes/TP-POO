#include "SystemePrevision.h"

void SystemePrevision::Affiche() {
	for(std::vector<Sonde*>::iterator it = this->sondes.begin(); it!=this->sondes.end(); ++it) {
		(*it)->Affiche();
	}
}

void SystemePrevision::AjoutSonde(Sonde& s) {
	this->sondes.push_back(&s);
}

float SystemePrevision::CalculMoyenneIndices() {
	int nb = 0;
	float moyenne = 0;
	for(std::vector<Sonde*>::iterator it = this->sondes.begin(); it!=this->sondes.end(); ++it) {
		(*it)->ObtenirNouvelleMesure();
		try {
			moyenne += (*it)->CalculNouvelIndice() * (*it)->GetIndicateurConfiance();
		} catch(const std::exception& e) {
			std::cout << e.what() << std::endl;
		}
		nb++;
	}
	return moyenne / nb;
}