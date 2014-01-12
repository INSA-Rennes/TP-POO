#include "Temperature.h"
#include "Hygrometrie.h"
#include "SystemePrevision.h"
#include <iostream>

int main() {
	float mesuresTemperature1[NB_MESURES] = {17.2, 3.8, -22.0};
	float mesuresTemperature2[NB_MESURES] = {15.2, 2.8, -19.0};
	float mesuresHygrometrie[NB_MESURES] = {47.0, 93.0, 50.0};
	
	Temperature sondeTemperature1(mesuresTemperature1, 5);
	Temperature sondeTemperature2(mesuresTemperature2, 4);
	Hygrometrie sondeHygrometrie(mesuresHygrometrie, 3);

	SystemePrevision systemePrevisions;
	systemePrevisions.AjoutSonde(sondeTemperature1);
	systemePrevisions.AjoutSonde(sondeTemperature2);
	systemePrevisions.AjoutSonde(sondeHygrometrie);

	for(int i=0; i<NB_MESURES; i++) {
		cout << "Prevision " << i+1 << endl;
		cout << "---------" << endl;
		int moyenneIndices = systemePrevisions.CalculMoyenneIndices();
		cout << " -> " << moyenneIndices << endl;
		systemePrevisions.Affiche();
		cout << endl;
	}

	system("pause");
}