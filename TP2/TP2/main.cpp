#include "chaine.h"
#include <cassert>

void main() {
	char *ch = "test";
	chaine ch1 = chaine(ch);
	chaine ch2 = chaine(ch1);
	assert(ch1.size() == ch2.size());

	char c1 = ch1.charAt(1);
	assert(c1 == 'e');
	char c2 = ch2.charAt(2);
	assert(c2 == 's');

	chaine ch3 = ch1+ch2;
	assert(ch3.size() == 2*ch2.size());

	assert(ch3 != ch1);
	assert(ch3 > ch1);
	assert(ch3 >= ch1);
	
	chaine newch1 = ch3.sous_chaine(0, ch1.size());
	assert(newch1 == ch1);
	newch1 = ch3.sous_chaine('t', 't');
	assert(newch1 == ch1);
}