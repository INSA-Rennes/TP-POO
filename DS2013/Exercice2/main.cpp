#include "PionDouble.h"
#include "PionBlanc.h"
#include "PionNoir.h"
#include <iostream>
#include <stdio.h>

void main() {
	PionDouble** eTab = (PionDouble**)malloc(5 * sizeof(PionDouble));
	eTab[1] = new PionDouble("PionDouble1", 10, 10);
	eTab[2] = new PionDouble("PionDouble2", 20, 20);
	eTab[3] = eTab[1];
	eTab[4] = new PionNoir("PionNoir1", 15, 15);
	eTab[5] = new PionBlanc("PionBlanc1", 25, 25);
	for(int i=0; i<5; i++) {
		std::cout << eTab[i];
	}
	
	for(int i=0; i<5; i++) {
		eTab[i]->mutation();
	}
	std::cout << "--- APRES MUTATION ---" << std::endl;
	for(int i=0; i<5; i++) {
		std::cout << eTab[i];
	}

	system("pause");
}