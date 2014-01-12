#ifndef PIONBLANC_H
#define PIONBLANC_H

#include <stdio.h>
#include <iostream>
#include <string>
#include "Pion.h"

class PionBlanc: virtual public Pion {
public:
	PionBlanc(std::string n, int x, int y);
	virtual std::string propriete() const;
};

#endif