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

class PionDouble {
private:
	Pion* pionBN;
	Mode _mode;

public:
	~PionDouble();
	std::string getIdent() const;
	int getX() const;
	int getY() const;
	virtual void mutation();
	PionDouble(std::string n, int x, int y);
	virtual std::string propriete() const;
	friend std::ostream& operator<<(std::ostream& os, const PionDouble& p);
};

#endif