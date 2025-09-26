#include <stdio.h>
#include <stdbool.h>

struct Employee {
	int id;
	float income;
	bool staff;
};

void initialize_employee(struct Employee *e) {
	e->id = 1;
	e->income = 13.50;
	e->staff = false;
	return;
}

int main() {
	{
		int x = 3;
		int *px = &x;
		printf("x contains %d", *px);
		printf(" and is at %p\n", px);
	}

	struct Employee ralph;
	initialize_employee(&ralph);
	printf("id: %d; income: %f\n", ralph.id, ralph.income);

	return 0;
}

