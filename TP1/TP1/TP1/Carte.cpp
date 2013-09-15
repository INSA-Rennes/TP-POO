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
		if(teteN == 0) {
			teteN = this;
			queueN = this;
		} else {
			queueN->succ = this;
			queueN = this;
		}
	} else if(proprio == 'S') {
		joueur = Joueur::sud;
		if(teteS == 0) {
			teteS = this;
			queueS = this;
		} else {
			queueS->succ = this;
			queueS = this;
		}
	} else {
		assert(false);
	}
	this->succ = 0;
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
		std::cout << std::endl;
		carte = carte->getSucc();
	}
}

void Carte::afficherS() {
	Carte *carte = Carte::getSTete();
	while(carte != Carte::getSQueue()) {
		carte->afficher();
		std::cout << std::endl;
		carte = carte->getSucc();
	}
}

void Carte::passerDerriere() {
	if(this->joueur == Joueur::nord) {
		queueN->succ = this;
		queueN = this;
		teteN = teteN->succ;
		queueN->succ = 0;
	} else {
		queueS->succ = this;
		queueS = this;
		teteS = teteS->succ;
		queueS->succ = 0;
	}
}

void Carte::changerProp() {
	if(this->joueur == Joueur::nord) {
		this->joueur = Joueur::sud;
		teteN = teteN->succ;
		queueS->succ = this;
		queueS = this;
		queueS->succ = 0;
	} else {
		this->joueur = Joueur::nord;
		teteS = teteS->succ;
		queueN->succ = this;
		queueN = this;
		queueN->succ = 0;
	}
}