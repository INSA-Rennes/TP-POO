/**
 * \file Carte.h
 * \brief Delcarations pour la classe Carte.
 * \author Paul Chaignon
 * \author Xavier Fraboulet
 * \version 1.0
 * \date 11/09/13
 */


#ifndef CARTE_H
#define CARTE_H
#include <string>
#include <cstdlib>
#include <iostream>
#include <cassert>

/**
 * \enum Couleur
 * \brief Couleur possible pour une carte.
 */
enum Couleur {
	Pique = 1,
	Trefle,
	Coeur,
	Carreau
};

/**
 * \enum Hauteur
 * \brief Hauteurs possibles pour une carte.
 */
enum Hauteur {
	As = 1,
	Deux,
	Trois,
	Quatre,
	Cinq,
	Six,
	Sept,
	Huit,
	Neuf,
	Dix,
	Valet,
	Dame,
	Roi
};

/**
 * \enum Joueur
 * \brief Deux joueurs possibles.
 */
enum Joueur {
	nord = 1,
	sud
};

/**
 * \class Carte
 * \brief Decrit une carte et ses liaisons au paquet.
 */
class Carte {
private:
	Joueur joueur;
	Hauteur hauteur;
	Couleur couleur;
	/** 
	 * Successeur de la carte dans le paquet.
	 */
	Carte *succ;
	/** 
	 * Tetes et queues des deux paquets de cartes.
	 */
	static Carte *teteN, *teteS, *queueN, *queueS;

public:
	Carte(Couleur, Hauteur, char);
	Hauteur getHauteur() const;
	Joueur getJoueur();
	Couleur getCouleur() const;
	static Carte* getNTete();
	static Carte* getSTete();
	static Carte* getNQueue();
	static Carte* getSQueue();
	Carte* getSucc();
	bool supAbs(Carte);
	bool egale(Carte);
	void afficher();
	static void afficherN();
	static void afficherS();
	void passerDerriere();
	void changerProp();

};

/**
 * \fn inline Hauteur Carte::getHauteur() const
 * \brief Accesseur pour la hauteur.
 * \return La hauteur de la carte.
 */
inline Hauteur Carte::getHauteur() const {
	return this->hauteur;
}

/**
 * \fn inline Joueur Carte::getJoueur()
 * \brief Accesseur pour le joueur proprietaire.
 * \return Le joueur proprietaire de la carte.
 */
inline Joueur Carte::getJoueur() {
	return this->joueur;
}

/**
 * \fn inline Couleur Carte::getCouleur() const
 * \brief Accesseur pour la couleur.
 * \return La couleur de la carte.
 */
inline Couleur Carte::getCouleur() const {
	return this->couleur;
}

/**
 * \fn inline Carte* Carte::getNTete()
 * \brief Accesseur pour la tete du paquet N.
 * \return La tete du paquet N.
 */
inline Carte* Carte::getNTete() {
	return Carte::teteN;
}

/**
 * \fn prototype de la fontion
 * \brief Accesseur pour la tete du paquet S.
 * \return La tete du paquet S.
 */
inline Carte* Carte::getSTete() {
	return Carte::teteS;
}

/**
 * \fn prototype de la fontion
 * \brief Accesseur pour la queue du paquet N.
 * \return La queue du paquet N.
 */
inline Carte* Carte::getNQueue() {
	return Carte::queueN;
}

/**
 * \fn prototype de la fontion
 * \brief Accesseur pour la queue du paquet S.
 * \return La queue du paquet S.
 */
inline Carte* Carte::getSQueue() {
	return Carte::queueS;
}

/**
 * \fn prototype de la fontion
 * \brief Accesseur pour le successeur.
 * \return Le successeur de la carte.
 */
inline Carte* Carte::getSucc() {
	return this->succ;
}

#endif