#ifndef PIONDOUBLE_H
#define PIONDOUBLE_H

#include <stdio.h>
#include <iostream>
#include <string>
#include "Pion.h"
#include "PionNoir.h"
#include "PionBlanc.h"

enum Mode {
	TPionNoir, TPionBlanc
};

class PionBlanc;
class PionNoir;

class PionDouble {
private:
	Pion* pionBN;
	Mode _mode;

public:
	~PionDouble() {
		delete this->pionBN;
	}

	std::string getIdent() const {
		return this->pionBN->getIdent();
	}

	int getX() const {
		return this->pionBN->getX();
	}

	int getY() const {
		return this->pionBN->getY();
	}

	virtual void mutation() {
		int x = this->getX();
		int y = this->getY();
		std::string ident = this->getIdent();
		if(this->_mode == TPionBlanc) {
			this->pionBN = new PionNoir(ident, x, y);
		} else {
			this->pionBN = new PionBlanc(ident, x, y);
		}
	}

	PionDouble(std::string n, int x, int y) {
		this->_mode = TPionNoir;
		this->pionBN = new PionNoir(n, x, y);
	}

	virtual std::string propriete() const {
		return "Pion double";
	}

	friend std::ostream& operator<<(std::ostream& os, const PionDouble& p);
};

std::ostream& operator<<(std::ostream& os, const PionDouble& p) {
	os << *p.pionBN;
	return os;
}

class PionBlanc: public Pion, public PionDouble {
public:
	PionBlanc(std::string n, int x, int y): Pion(n, x, y) {

	}

	virtual std::string propriete() const {
		return "Propriete :: pion blanc";
	}
};

class PionNoir: public Pion, public PionDouble {
public:
	PionNoir(std::string n, int x, int y): Pion(n, x, y) {

	}

	virtual std::string propriete() const {
		return "Propriete :: pion noir";
	}
};

#endif