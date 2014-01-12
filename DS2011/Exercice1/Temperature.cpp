#include "Temperature.h"

void Temperature::Affiche() const {
	cout << "Temperature: " << this->derniereMesure << " -> " << this->dernierIndice << endl;
}

float Temperature::CalculNouvelIndice() {
	if(this->derniereMesure<-20 && this->derniereMesure>40) {
		throw exception("Temperature aberrante.");
	}

	if(this->derniereMesure<0 || this->derniereMesure>25) {
		this->dernierIndice = 0;
	} else {
		this->dernierIndice = this->derniereMesure / 5;
	}
	return this->dernierIndice;
}

Temperature::Temperature(float* m, int c): Sonde(m, c) {

}