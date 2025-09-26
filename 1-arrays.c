#include <stdio.h>

#define MAX_IDS 32

void arrays() {
	// Partially initilize array
	int ids[MAX_IDS] = {1, 1, 2, 3, 5};
	//int idsAlt[] = {1, 1, 2, 3, 5};

	printf("%d\n", ids[4]);

	// Can use hex
	ids[4] = 0x41;
	printf("%d\n", ids[4]);

	// This syntax will initialize the whole array to 0.
	int zeroed[MAX_IDS] = {0};
}

void strings() {
	// Don't forget the null termination!! 0 or '\0'
	// Tons of stdlib funcs use null termiation
	// Since it's a literal element of the array, can just acces.
	char myStr[] = {'H', 'e', 'l', 'l', 'o', 0};
	printf("%s\n", myStr);

	// Compiler will null terminate for us when using this syntax
	// Still an "array" since pointer arithmetic
	char* myOtherStr = "Hello";
	printf("%s\n", myOtherStr);
	printf("%c\n", myOtherStr[1]);
}

int main() {
	arrays();
	strings();
	return 0;
}

