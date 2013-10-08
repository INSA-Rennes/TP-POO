/**
 * \file chaine.h
 * \brief Delcarations pour la classe Chaine.
 * \author Paul Chaignon
 * \author Xavier Fraboulet
 * \version 1.0
 * \date 08/10/13
 */

#ifndef CHAINE_H
#define CHAINE_H
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

/**
 * \class chaine
 * \brief Decrit une chaines et ses operations.
 */
class chaine {
private:
	int length;
	char * string;
	int compare(const chaine& ch) const;

public:  
	chaine();
	chaine(const char *);
	chaine(const chaine &);
	~chaine();

	chaine sous_chaine(int ind1, int ind2);
	chaine sous_chaine(char deb, char fin);
	chaine operator+(const chaine& ch) const;
	bool operator==(const chaine& ch) const;
	bool operator!=(const chaine& ch) const;
	bool operator<(const chaine& ch) const;
	bool operator>(const chaine& ch) const;
	bool operator<=(const chaine& ch) const;
	bool operator>=(const chaine& ch) const;
	int size() const;
	char charAt(int i) const;
};

/**
 * \fn inline int chaine::size() const 
 * \brief Accesseur pour la taille de la chaine
 * \return La taille de la chaine
 */
inline int chaine::size() const {
	return this->length;
}

#endif