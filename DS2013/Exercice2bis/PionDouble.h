#ifndef PIONDOUBLE_H
#define PIONDOUBLE_H

#include <stdio.h>
#include <iostream>
#include <string>
#include "Pion.h"
#include "PionBlanc.h"
#include "PionNoir.h"

class PionNoir;
class PionBlanc;

enum Mode {
	TPionNoir, TPionBlanc
};

class PionDouble: public PionBlanc, public PionNoir {
private:
	Mode _mode;

public:
	~PionDouble();
	virtual void mutation();
	PionDouble(std::string n, int x, int y);
	virtual std::string propriete() const;
	friend std::ostream& operator<<(std::ostream& os, const PionDouble& p);
};

#include "PionNoir.h"
#include "PionBlanc.h"

#endif