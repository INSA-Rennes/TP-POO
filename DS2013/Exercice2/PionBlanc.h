#ifndef PIONBLANC_H
#define PIONBLANC_H

#include <stdio.h>
#include <iostream>
#include <string>
#include "Pion.h"
#include "PionDouble.h"

class PionBlanc: public Pion, public PionDouble {
public:
	PionBlanc(std::string n, int x, int y);
	virtual std::string propriete() const;
};

#endif