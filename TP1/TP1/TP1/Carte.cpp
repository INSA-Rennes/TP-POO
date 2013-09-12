#include "Carte.h"

Carte *Carte::teteN = 0;
Carte *Carte::teteS = 0;
Carte *Carte::queueN = 0;
Carte *Carte::queueS = 0;
	
std::string hauteurs[] = {"As", "Deux", "Trois", "Quatre", "Cinq", "Six", "Sept", "Huit", "neuf", "Dix", "Valet", "Dame", "Roi"};
std::string couleurs[] = {"Pique", "Trefle", "Coeur", "Carreau"};

Carte::Carte(Couleur c, Hauteur h, char proprio): couleur(c), hauteur(h) {
	if(proprio == 'N') {
		joueur = Joueur::nord;
	} else if(proprio == 'S') {
		joueur = Joueur::sud;
	} else {
		assert(false);
	}

}

bool Carte::supAbs(Carte carte) {
	return this->hauteur > carte.hauteur;
}

bool Carte::egale(Carte carte) {
	return this->hauteur == carte.hauteur;
}

void Carte::afficher() {
	std::cout << hauteurs[this->hauteur-1] << " de " << couleurs[this->couleur - 1] << " (" << this->hauteur << ", " << this->couleur << ")";
}

void Carte::afficherN() {
	Carte *carte = Carte::getNTete();
	while(carte != Carte::getNQueue()) {
		carte->afficher();
		carte = carte->getSucc();
	}
}

void Carte::afficherS() {
	Carte *carte = Carte::getSTete();
	while(carte != Carte::getSQueue()) {
		carte->afficher();
		carte = carte->getSucc();
	}
}

void Carte::passerDerriere() {
	if(this->joueur == Joueur::nord) {
		Carte::getNQueue()->succ = this;
		Carte::queueN = this;
	} else {
		Carte::getSQueue()->succ = this;
		Carte::queueS = this;
	}
}

void Carte::changerProp() {
	if(this->joueur == Joueur::nord) {
		this->joueur = Joueur::sud;
	} else {
		this->joueur = Joueur::nord;
	}
}