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


#ifndef CARTE_H
#define CARTE_H
#include <string>
#include <cstdlib>
#include <iostream>
#include <cassert>

enum Couleur {
	Pique = 1,
	Trefle,
	Coeur,
	Carreau
};

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

enum Joueur {
	nord = 1,
	sud
};

class Carte {
private:
	Joueur joueur;
	Hauteur hauteur;
	Couleur couleur;
	Carte *succ;
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

inline Hauteur Carte::getHauteur() const {
	return this->hauteur;
}

inline Joueur Carte::getJoueur() {
	return this->joueur;
}

inline Couleur Carte::getCouleur() const {
	return this->couleur;
}

inline Carte* Carte::getNTete() {
	return Carte::teteN;
}

inline Carte* Carte::getSTete() {
	return Carte::teteS;
}

inline Carte* Carte::getNQueue() {
	return Carte::queueN;
}

inline Carte* Carte::getSQueue() {
	return Carte::queueS;
}

inline Carte* Carte::getSucc() {
	return this->succ;
}

#endif