#include "PionDouble.h"
#include <iostream>
#include <stdio.h>

void main() {
	PionDouble* e1 = new PionDouble("PionDouble1", 10, 10);
	PionDouble* e2 = new PionDouble("PionDouble2", 20, 20);
	PionDouble* e3 = e1;
	PionNoir* e4 = new PionNoir("PionNoir1", 15, 15);
	PionBlanc* e5 = new PionBlanc("PionBlanc1", 25, 25);
	std::cout << *e1 << *e2 << *e3 << *e4 << *e5;
	
	e1->mutation();
	e2->mutation();
	e3->mutation();
	e4->mutation();
	e5->mutation();
	std::cout << "--- APRES MUTATION ---" << std::endl;
	std::cout << *e1 << *e2 << *e3 << *e4 << *e5;

	system("pause");
}