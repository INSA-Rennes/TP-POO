/**
* \ file nom du fichier
* \ brief breve description de son contenu
* \ author nom prenom
* \ version X.Y
* \ date date de creation
*
* Description plus detaillee du contenu du fichier
*
*/

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

/**
* \fn prototype de la fontion
* \ brief des
ription breve de la fon
tion
*
* \ param [in]
* \ param [out]
* \ param [in ,out] 
*
* \ return le type de retour et sa des
ription
*/
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
	Carte *carte = teteN;
	while(carte != 0) {
		carte->afficher();
		std::cout << std::endl;
		carte = carte->getSucc();
	}
}

void Carte::afficherS() {
	Carte *carte = teteS;
	while(carte != 0) {
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