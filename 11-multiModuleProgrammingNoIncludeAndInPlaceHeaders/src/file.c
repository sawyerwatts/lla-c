#include <stdio.h>
#include <fcntl.h>

#include "file.h"

int open_file_rw(char *filename) {
	int fd = open(filename, O_CREAT | O_RDWR);
	if (fd == -1) {
		perror("open");
	}
	return fd;
}

