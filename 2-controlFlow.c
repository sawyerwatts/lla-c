#include <stdio.h>

// gcc -Wall -Werror -o 2-controlFlow 2-controlFlow.c && ./2-controlFlow

void conditionals() {
	int temp;
	printf("Please enter an integer temperature: ");
	scanf("%d/n", &temp);

	if (temp >= 70) {
		printf("It's hot!\n");
	} else if (temp >= 30) {
		printf("It's mild\n");
	} else {
		printf("It's cold\n");
	}
}

void loops() {
	#define MAX_IDS 32

	// for, while, and do-while loops exist in C

	int ids[MAX_IDS] = {0};
	for (int i = 0; i < MAX_IDS; i++) {
		ids[i] = i;
	}
}

int main() {
	conditionals();
	loops();
	return 0;
}

