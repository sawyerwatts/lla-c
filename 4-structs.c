#include <stdio.h>
#include <stdbool.h>

#define MAX_EMPLOYEES 1024

// The compilation and runtime systems may add padding chars b/w fields. As such, diff systems can
// be hard to get the offsets of fields. However, prepending `__attribute__((__packed__)) ` before
// the struct keyword will disable this optimization to preserve that compatibility when sharing
// data between systems or storing as binary to disk.
struct Employee {
	int id;
	char firstname[64];
	char lastname[64];
	float income;
	bool ismanager;
};

// unions only allocate enough memory for the largest mebmer - here, the int. As such, when
// accessing c or s, those view the subset of bytes of x (all starting from the start). So since x
// has 4 bytes, c is a window over that first byte. These are more useful in embedded programming.
union MyUnion {
	int x;
	char c;
	short s;
};

int main() {

	{
		// Just like arrays, {0} can be used to zero the entire structure.
		struct Employee fred = {0};
		fred.income = 100.00;
		fred.ismanager = true;
		printf("%f\n", fred.income);
	}

	struct Employee employees[MAX_EMPLOYEES];
	for (int i = 0; i < MAX_EMPLOYEES; i++) {
		employees[i].id = i;
		employees[i].income = 0;
		employees[i].ismanager = false;
	}
	printf("%f\n", employees[9].income);

	{
		union MyUnion u;
		u.x = 0x412342;
		// Half, HalfHalf
		printf("%hx %hhx\n", u.s, u.c);
	}

	printf("sizeof employee: %ld bytes\n", sizeof(struct Employee));

	return 0;
}

