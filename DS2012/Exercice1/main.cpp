#include "Bd.h"
#include "Roman.h"
#include <vector>

void main() {
	std::vector<Ouvrage*> bibli;
	bibli.push_back(new Bd("a1", "d1", "t1", 50));
	bibli.push_back(new Bd("a2", "d2", "t2", 45));
	bibli.push_back(new Roman("a3", "c1", "t3", 500));
	bibli.push_back(new Roman("a4", "c2", "t4", 402));

	for(std::vector<Ouvrage*>::iterator it=bibli.begin(); it!=bibli.end(); ++it) {
		try {
			Bd& bd = dynamic_cast<Bd&>(**it);
			bd.imprime("impCouleur");
		} catch(const std::exception& e) {
			try {
				Roman& roman = dynamic_cast<Roman&>(**it);
				roman.imprime("impN&B");
			} catch(const std::exception& e1) {
				(*it)->imprime("imp1");
			}
		}
	}

	std::cout << "Recherche..." << std::endl;
	for(std::vector<Ouvrage*>::iterator it=bibli.begin(); it!=bibli.end(); ++it) {
		if((*it)->recherche("a3")) {
			std::cout << "Resultat: " << std::endl;
			(*it)->imprime("stdout");
			break;
		}
	}

	system("pause");
}