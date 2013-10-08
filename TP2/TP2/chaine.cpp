/**
 * \file chaine.cpp
 * \brief Methodes pour la classe Chaine.
 * \author Paul Chaignon
 * \author Xavier Fraboulet
 * \version 1.0
 * \date 08/10/13
 */
#include "chaine.h"

/**
 * \fn chaine()
 * \brief Constructeur par defaut de chaine.
 * \param[in] c La couleur.
 * \param[in] h La hauteur.
 * \param[in] proprio Le proprietaire sous forme de charactere.
 */
chaine::chaine() {
	this->length = 0;
	this->string = "";
}

/**
 * \fn chaine(const char *)
 * \brief Constructeur de chaine a partir d'une string.
 * \param[in] c la string.
 */
chaine::chaine(const char * c) {
	this->length = 0;
	while(c[this->length] != '\0') {
		this->length++;
	}
	this->string = (char*)malloc(this->length);
	int i;
	for(i=0; i<this->length; i++) {
		this->string[i] = c[i];
	}
}

/**
 * \fn chaine(const chaine & c)
 * \brief Constructeur par recopie de chaine.
 * \param[in] c la chaine.
 */
chaine::chaine(const chaine & c) {
	this->length = c.size();
	this->string = (char*)malloc(this->length);
	int i;
	for(i=0; i<this->length; i++) {
		string[i] = c.charAt(i);
	}
}

/**
 * \fn chaine::~chaine()
 * \brief Destructeur de chaine.
 */
chaine::~chaine() {
	delete[] this->string;
	// same as free(this->string); ?
}

/**
 * \fn chaine chaine::sous_chaine(int ind1, int ind2)
 * \brief Donne la sous chaine de la chaine courante.
 * \param[in] ind1 Indice de debut.
 * \param[in] ind2 Indice de fin de chaine + 1 (non inclus).
 * \return La sous chaine.
 */
chaine chaine::sous_chaine(int ind1, int ind2) {
	int nb = ind2 - ind1;
	char *res = new char[nb+1];
	int i;
	for(i=0; i<nb; i++) {
		res[i] = string[i+ind1];
	}
	res[i] = '\0';
	return chaine(res);
}

/**
 * \fn chaine chaine::sous_chaine(char deb, char fin) 
 * \brief Donne la sous chaine de la chaine courante.
 * \param[in] deb Caractere de debut de la sous chaine.
 * \param[in] fin Caractere de fin de la sous chaine.
 * \return La sous chaine.
 */
chaine chaine::sous_chaine(char deb, char fin) {
	int i;
	int ind1 = -1;
	for(i=0; i<this->length; i++) {
		if(ind1==-1 && this->string[i]==deb) {
			ind1 = i;
		} else if(this->string[i] == fin) {
			return sous_chaine(ind1, i+1);
		}
	}
}

/**
 * \fn chaine chaine::operator+(const chaine& ch) const
 * \brief Concatene la chaine courante avec la chaine en parametre.
 * \param[in] ch La chaine a concatener
 * \return La nouvelle chaine concatenee.
 */
chaine chaine::operator+(const chaine& ch) const {
	int nb = this->length + ch.size();
	char *res = new char[nb+1];
	int i;
	for(i=0; i<this->length; i++) {
		res[i] = string[i];
	}
	for(; i<nb; i++) {
		res[i] = ch.charAt(i - this->length);
	}
	res[i] = '\0';
	return chaine(res);
}

/**
 * \fn char chaine::charAt(int i) const
 * \brief Retourne le caracere a l'indice i
 * \param[in] i L'indice.
 * \return La caractere a l'indice i.
 */
char chaine::charAt(int i) const {
	return string[i];
}

/**
 * \fn int chaine::compare(const chaine& ch) const 
 * \brief Compare deux chaines
 * \param[in] ch La chaine a comparer.
 * \return Retourne 0 si les deux chaines sont identiques, >0 si la chaine courante est plus grande que celle en parametre, <0 sinon.
 */
int chaine::compare(const chaine& ch) const {
	int i;
	for(i=0; i<this->length && i<ch.size(); i++) {
		if(this->charAt(i) < ch.charAt(i)) {
			return -1;
		} else if(this->charAt(i) > ch.charAt(i)) {
			return 1;
		}
	}
	if(this->length < ch.size()) {
		return -1;
	} 
	if(this->length > ch.size()) {
		return 1;
	}
	return 0;
}

/**
 * \fn bool chaine::operator<(const chaine& ch) const
 * \brief Compare deux chaines.
 * \param[in] ch La chaine a comparer.
 * \return Retourne vrai si la chaine courante est inferieure a la chaine en parametre.
 */
bool chaine::operator<(const chaine& ch) const {
	return this->compare(ch) == -1;
}

/**
 * \fn bool chaine::operator>(const chaine& ch) const
 * \brief Compare deux chaines.
 * \param[in] ch La chaine a comparer.
 * \return Retourne vrai si la chaine courante est superieure a la chaine en parametre.
 */
bool chaine::operator>(const chaine& ch) const {
	return this->compare(ch) == 1;
}

/**
 * \fn bool chaine::operator<=(const chaine& ch) const
 * \brief Compare deux chaines.
 * \param[in] ch La chaine a comparer.
 * \return Retourne vrai si la chaine courante est inferieure ou egale a la chaine en parametre.
 */
bool chaine::operator<=(const chaine& ch) const {
	int delta = this->compare(ch);
	return delta==-1 || delta==0;
}

/**
 * \fn bool chaine::operator>=(const chaine& ch) const
 * \brief Compare deux chaines.
 * \param[in] ch La chaine a comparer.
 * \return Retourne vrai si la chaine courante est superieure ou egale a la chaine en parametre.
 */
bool chaine::operator>=(const chaine& ch) const {
	int delta = this->compare(ch);
	return delta==1 || delta==0;
}

/**
 * \fn bool chaine::operator<(const chaine& ch) const
 * \brief Compare deux chaines.
 * \param[in] ch La chaine a comparer.
 * \return Retourne vrai si les deux chaines sont identiques.
 */
bool chaine::operator==(const chaine& ch) const {
	return this->compare(ch) == 0;
}

/**
 * \fn bool chaine::operator!=(const chaine& ch) const
 * \brief Compare deux chaines.
 * \param[in] ch La chaine a comparer.
 * \return Retourne vrai si les deux chaines sont differentes.
 */
bool chaine::operator!=(const chaine& ch) const {
	return this->compare(ch) != 0;
}