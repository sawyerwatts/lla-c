#include <stdio.h>

#include "file.h"
#include "parse.h"
#include "net/http.h"

// manual compilation and linking
// $ gcc -o obj/file.o -I$(pwd)/include src/file.c -c
// $ gcc -o obj/parse.o -I$(pwd)/include src/parse.c -c
// $ gcc -o obj/main.o -I$(pwd)/include src/main.c -c
// $ gcc obj/*.o -o bin/newout
//		may need to add: -I$(pwd)/include
// $ ./bin/newout

int main(int argc, char *argv[]) {
	if (argc != 2) {
		printf("Usage: %s <filename>\n", argv[0]);
		return 1;
	}

	int fd = open_file_rw(argv[1]);
	if (fd == -1) {
		return -1;
	}

	int numEmployees = 0;
	if (parse_file_header(fd, &numEmployees) == -1) {
		return -1;
	}

	stuff();

	// TODO: need to close fd

	return 0;
}

