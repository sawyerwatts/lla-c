#include <stdio.h>

// gcc -o 0-varsAndPreprocessors 0-varsAndPreprocessors.c && ./0-syntaxRefresher
// can also -DDEBUG to `#define DEBUG`

#define MAX_PERSONS 1024
// #define DEBUG

int g_NumPersons = 0;

void local_vars() {
	int personID = 0;
	int personID2 = personID + 1;

	{
		// Sub-scoping and shadowing is in C too
		int personID = 13;
	}
}

void preprocessor() {
	#ifdef DEBUG
	printf("WE ARE IN DEBUG MODE: %s:%d\n", __FILE__, __LINE__);
	#endif
}

int main() {
	printf("Hello, world!\n");
	local_vars();
	preprocessor();

	return 0;
}

