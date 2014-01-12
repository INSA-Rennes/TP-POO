#include "Hygrometrie.h"

void Hygrometrie::Affiche() const {
	cout << "Hygrometrie: " << this->derniereMesure << " -> " << this->dernierIndice << endl;
}

float Hygrometrie::CalculNouvelIndice() {
	if(this->derniereMesure<10 || this->derniereMesure>90) {
		throw exception("Hygrometrie aberrante.");
	}

	if(this->derniereMesure <= 50.0) {
		this->dernierIndice = this->derniereMesure / 10.0;
	} else {
		this->dernierIndice = (100.0 - this->derniereMesure) / 10.0;
	}
	return this->dernierIndice;
}

Hygrometrie::Hygrometrie(float* m, int c): Sonde(m, c) {
	
}