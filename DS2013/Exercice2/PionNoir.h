#ifndef PIONNOIR_H
#define PIONNOIR_H

#include <stdio.h>
#include <iostream>
#include <string>
#include "Pion.h"
#include "PionDouble.h"

class PionNoir: public Pion, public PionDouble {
public:
	PionNoir(std::string n, int x, int y);
	virtual std::string propriete() const;
};

#endif