#include "chaine.h"

chaine::chaine() {
	this->length = 0;
	string = "";
 }

chaine::chaine(const char * c) {
	this->length = 0;
	while(c[this->length] != '\0') {
		this->length++;
	}
	string[this->length];
	int i;
	for (i=0; i<this->length; i++) {
		string[i] = c[i];
	}
}

chaine::chaine(const chaine & c) {
	this->length = c.size();
	string[this->length];
	int i;
	for (i=0; i<this->length; i++) {
		string[i] = c.charAt(i);
	}
}

chaine::~chaine() {
	std::cout << "delete chaine" << std::endl;
}

chaine chaine::sous_chaine(int ind1, int ind2) {
	int nb = ind2 - ind1;
	char *res = new char[nb];
	int i;
	for(i=0; i<nb; i++) {
		res[i] = string[i+ind1];
	}
	return chaine(res);
}

chaine chaine::sous_chaine(char deb, char fin) {
	int i;
	int ind1 = 0;
	for(i=0; i<this->length; i++) {
		if(!ind1 && this->string[i] == deb) {
			ind1 = i;
		} else if(this->string[i] == fin) {
			return sous_chaine(ind1, i);
		}
	}
}

chaine chaine::operator+(const chaine& ch) const {
	int nb = this->length + ch.size();
	char *res = new char[nb];
	int i;
	for(i=0; i<nb; i++) {
		if(i < this->length) {
			res[i] = string[i];
		} else {
			res[i] = ch.charAt(i - this->length);
		}
	}
	return chaine(res);
}

char chaine::charAt(int i) const {
	return string[i];
}

int chaine::compare(const chaine& ch) const {
	int i;
	for(i=0; i<this->length && i<ch.size(); i++) {
		if(this->charAt(i) < ch.charAt(i)) {
			return -1;
		} else if(this->charAt(i) > ch.charAt(i)) {
			return 1;
		}
	}
	if(this->length < ch.size()) {
		return -1;
	} 
	if(this->length > ch.size()) {
		return 1;
	}
	return 0;
}

bool chaine::operator<(const chaine& ch) const {
	return this->compare(ch) == -1;
}

bool chaine::operator>(const chaine& ch) const {
	return this->compare(ch) == 1;
}

bool chaine::operator<=(const chaine& ch) const {
	int delta = this->compare(ch);
	return delta==-1 || delta==0;
}

bool chaine::operator>=(const chaine& ch) const {
	int delta = this->compare(ch);
	return delta==1 || delta==0;
}

bool chaine::operator==(const chaine& ch) const {
	return this->compare(ch) == 0;
}

bool chaine::operator!=(const chaine& ch) const {
	return this->compare(ch) != 0;
}