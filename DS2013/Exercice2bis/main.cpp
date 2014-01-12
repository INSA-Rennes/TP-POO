#include "PionDouble.h"
#include <iostream>
#include <stdio.h>

void main() {
	Pion** eTab = (Pion**)malloc(6 * sizeof(Pion));
	eTab[0] = new PionDouble("PionDouble1", 10, 10);
	eTab[1] = new PionDouble("PionDouble2", 20, 20);
	eTab[2] = eTab[0];
	eTab[3] = new PionNoir("PionNoir1", 15, 15);
	eTab[4] = new PionBlanc("PionBlanc1", 25, 25);
	eTab[5] = new PionDouble("PionDouble3", 20, 20);
	for(int i=0; i<6; i++) {
		std::cout << *(eTab[i]);
	}
	
	for(int i=0; i<6; i++) {
		eTab[i]->mutation();
	}
	std::cout << "--- APRES MUTATION ---" << std::endl;
	for(int i=0; i<6; i++) {
		std::cout << *(eTab[i]);
	}

	system("pause");
}