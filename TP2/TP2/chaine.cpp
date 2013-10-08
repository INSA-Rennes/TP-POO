#include "chaine.h"

chaine::chaine() {
	this->length = 0;
	this->string = "";
 }

chaine::chaine(const char * c) {
	this->length = 0;
	while(c[this->length] != '\0') {
		this->length++;
	}
	this->string = (char*)malloc(this->length);
	int i;
	for (i=0; i<this->length; i++) {
		this->string[i] = c[i];
	}
}

chaine::chaine(const chaine & c) {
	this->length = c.size();
	this->string = (char*)malloc(this->length);
	int i;
	for (i=0; i<this->length; i++) {
		string[i] = c.charAt(i);
	}
}

chaine::~chaine() {
	// TODO
}

chaine chaine::sous_chaine(int ind1, int ind2) {
	int nb = ind2 - ind1;
	char *res = new char[nb+1];
	int i;
	for(i=0; i<nb; i++) {
		res[i] = string[i+ind1];
	}
	res[i] = '\0';
	return chaine(res);
}

chaine chaine::sous_chaine(char deb, char fin) {
	int i;
	int ind1 = -1;
	for(i=0; i<this->length; i++) {
		if(ind1==-1 && this->string[i]==deb) {
			ind1 = i;
		} else if(this->string[i] == fin) {
			return sous_chaine(ind1, i+1);
		}
	}
}

chaine chaine::operator+(const chaine& ch) const {
	int nb = this->length + ch.size();
	char *res = new char[nb+1];
	int i;
	for(i=0; i<this->length; i++) {
		res[i] = string[i];
	}
	for(; i<nb; i++) {
		res[i] = ch.charAt(i - this->length);
	}
	res[i] = '\0';
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