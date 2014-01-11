#ifndef PION_H
#define PION_H

#include <stdio.h>
#include <iostream>
#include <string>

class Pion {
private:
	int coordX;
	int coordY;
	std::string identifiant;

public:
	~Pion();
	std::string getIdent() const;
	int getX() const;
	int getY() const;
	virtual void mutation();
	Pion(std::string n, int x, int y);
	virtual std::string propriete() const =0;
	friend std::ostream& operator<<(std::ostream& os, const Pion& p);
};

#endif