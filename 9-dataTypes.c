#include <stdio.h>

int main(int argc, char *argv[]) {

	char c; // 1 byte
	short s; // 2 bytes
	int i; // 4 bytes (on 32 bit architectures); will be lower on lower architectures
	// long int was historically used to upgrade to 4 bytes
	long long int lli; // 8 bytes

	unsigned char uc;
	// etc

	float f = 3.14;
	double d = 3.14159;


	// Type casting

	// Same size
	// 4 is in range of both int and unsigned int, so no weirdness occurs.
	unsigned int x = 4;
	int sx = (int)x;

	// Downcasting
	// Hex is larger than short, so the higher bytes are truncated.
	unsigned int bigx = 0xfffffefe;
	short kindaBig = (short)bigx;

	// Upcasting and sign expansion.
	// Bits are added in upcast, and they're the same value as the last bit, and since negatives are
	// leading with a 1, an unexpected number comes out.
	short smol = -1;
	int lessSmol = (int)smol;

	// Crosscasting: round the float into an int.
	float pi = 3.14;
	int pie = (int)pi;

	short *sp = (short*)argv[0];

	return 0;
}

