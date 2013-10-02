#include <iostream>
#include <string>

class chaine {
private:
	int size;
	char * string;

public:
	chaine();
	chaine(const char *);
	chaine(const char &);
	~chaine();

	chaine sous_chaine(int ind1, int ind2);
	chaine sous_chaine(char deb, char fin);
	chaine operator+(const chaine& ch) const;
	bool operator==(const chaine& ch) const;
	bool operator<(const chaine& ch) const;
	bool operator>(const chaine& ch) const;
	bool operator<=(const chaine& ch) const;
	bool operator>=(const chaine& ch) const;
	int getSize() const;
	char charAt(int i) const;

	
};

inline int chaine::getSize() const {
	return this->size;
}