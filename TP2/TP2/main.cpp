#include "chaine.h"
#include <cassert>

void main() {
	char *ch = "test";
	chaine ch1 = chaine(ch);
	chaine ch2 = chaine(ch1);
	char c1 = ch1.charAt(1);
	assert(c1 == 'e');
	assert
}