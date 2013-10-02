#include <iostream>
#include <string>

class chaine {
private:
	int length;
	char * string;
	int compare(const chaine& ch) const;

public:
	chaine();
	chaine(const char *);
	chaine(const chaine &);
	~chaine();

	chaine sous_chaine(int ind1, int ind2);
	chaine sous_chaine(char deb, char fin);
	chaine operator+(const chaine& ch) const;
	bool operator==(const chaine& ch) const;
	bool operator!=(const chaine& ch) const;
	bool operator<(const chaine& ch) const;
	bool operator>(const chaine& ch) const;
	bool operator<=(const chaine& ch) const;
	bool operator>=(const chaine& ch) const;
	int size() const;
	char charAt(int i) const;

	
};

inline int chaine::size() const {
	return this->length;
}