/**
 * \file Carte.cpp
 * \brief Methodes et initialisation de la classe Carte.
 * \author Paul Chaignon
 * \author Xavier Fraboulet
 * \version 1.0
 * \date 11/09/13
 */

#include "Carte.h"

Carte *Carte::teteN = 0;
Carte *Carte::teteS = 0;
Carte *Carte::queueN = 0;
Carte *Carte::queueS = 0;

/**
 * Tableau avec les correspondances structures - noms pour la methode afficher.
 */
std::string hauteurs[] = {"As", "Deux", "Trois", "Quatre", "Cinq", "Six", "Sept", "Huit", "neuf", "Dix", "Valet", "Dame", "Roi"};
std::string couleurs[] = {"Pique", "Trefle", "Coeur", "Carreau"};

/**
 * \fn Carte(Couleur, Hauteur, char)
 * \brief Constructeur de Carte.
 * \param[in] c La couleur.
 * \param[in] h La hauteur.
 * \param[in] proprio Le proprietaire sous forme de charactere.
 */
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
 * \fn bool Carte::supAbs(Carte)
 * \brief Compare la hauteur d'une carte avec la carte courante.
 * \param[in] carte La carte a comparer avec la carte courante.
 * \return Vrai si la carte courante est "superieure" a la carte en parametre.
 */
bool Carte::supAbs(Carte carte) {
	return this->hauteur > carte.hauteur;
}

/**
 * \fn bool Carte::egale(Carte)
 * \brief Compare la hauteur d'une carte avec la carte courante.
 * \param[in] carte La carte a comparer avec la carte courante.
 * \return Vrai si les deux carte sont de meme hauteur.
 */
bool Carte::egale(Carte carte) {
	return this->hauteur == carte.hauteur;
}

/**
 * \fn void Carte::afficher()
 * \brief Affiche la carte.
 */
void Carte::afficher() {
	std::cout << hauteurs[this->hauteur-1] << " de " << couleurs[this->couleur - 1] << " (" << this->hauteur << ", " << this->couleur << ")";
}

/**
 * \fn void Carte::afficherN()
 * \brief Affiche l'ensemble des cartes du paquet N.
 */
void Carte::afficherN() {
	Carte *carte = teteN;
	while(carte != 0) {
		carte->afficher();
		std::cout << std::endl;
		carte = carte->getSucc();
	}
}

/**
 * \fn void Carte::afficherS()
 * \brief Affiche l'ensemble des cartes du paquet S.
 */
void Carte::afficherS() {
	Carte *carte = teteS;
	while(carte != 0) {
		carte->afficher();
		std::cout << std::endl;
		carte = carte->getSucc();
	}
}

/**
 * \fn void Carte::passerDerriere()
 * \brief Passe la carte a la fin du paquet.
 */
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

/**
 * \fn void Carte::changerProp()
 * \brief Change le proprietaire de la carte.
 */
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