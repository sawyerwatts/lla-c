#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct Employee {
    int id;
    float income;
    bool staff;
};

int initialize_employee(struct Employee *e) {
    // Static allocation
    // The first time this func is ran, numEmployees will be created and initialized, but it's
    // inaccessible outside of this func.
    static int numEmployees = 0;
    // Pretty sure this is not thread safe.
    numEmployees++;

    e->id = numEmployees;
    e->income = 13.50;
    e->staff = false;
    return numEmployees;
}

// However, funcs usually return statuses (enums, types, etc). As such, if an op needs to realloc a
// pointer, then it'd need a pointer to a pointer.
typedef enum {
    STATUS_GOOD,
    STATUS_BAD,
} status;

status grow(int **data, int newLen) {
    int *tmp = realloc(*data, newLen);
    if (tmp == NULL) {
        *data = NULL;
        return STATUS_BAD;
    }

    *data = tmp;
    return STATUS_GOOD;
}

// NOTE: To detect memory leaks, Valgrind (from valgrind.org) is our friend. Note that Valgrind is a
// runtime analysis tool, not a static analysis tool.
// Compile with -g to add debug symbols.
// $ valgrind --leak-check=full ./6-allocations -s

int main() {
    {
        int employeesLen = 4;

        // Dynamic allocation
        struct Employee *employees = malloc(sizeof(struct Employee) * employeesLen);
        if (employees == NULL) {
            printf("The allocator failed\n");
            return -1;
        }

        for (int i = 0; i < employeesLen; i++) {
            initialize_employee(&employees[i]);
            printf("%d\n", employees[i].id);
        }

        // Comment this line out to cause a memory leak to be found by Valgrind.
        free(employees);
        employees = NULL;
    }

    {
        // To initialize and malloc a pointer, here's an example.
        int *pn = (int *)malloc(sizeof(int));
        *pn = 13;
        printf("%d\n", *pn);
        free(pn);
    }

    {
        int *first = malloc(64);
        if (STATUS_BAD == grow(&first, 128)) {
            printf("uh oh\n");
            return -1;
        }
        free(first);
    }

    return 0;
}

