#include "chaine.h"

chaine::chaine() {
	size = 0;
	string = "";
 }

chaine::chaine(char * c) {
	string = c;
	size = strlen(*c);
}

chaine::chaine(char & c) {
	string = &c;
	size = strlen(c);
}

chaine::~chaine() {
	string = 0;
	size = 0;
}

chaine chaine::sous_chaine(int ind1, int ind2) {
	const int nb = ind2 - ind1;
	char res[nb];
	int i;
	for(i=0; i<nb; i++) {
		res[i] = string[i+ind1];
	}
	return chaine(res);
}

chaine sous_chaine(char deb, char fin) {

}

chaine operator+(const chaine& ch) const;


bool chaine::operator==(const chaine& ch) const {
	if (size != ch.getSize()) {
		return false;
	}
	int i;
	for(i=0; i<size; i++) {
		if (string[i] != ch.charAt(i)) {
			return false;
		}
	}
	return true;
}

char chaine::charAt(int i) const {
	return string[i];
}
	bool operator<(const chaine& ch) const;
	bool operator>(const chaine& ch) const;
	bool operator<=(const chaine& ch) const;
	bool operator>=(const chaine& ch) const;