#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

int main() {
	int fd = open("./fakeFile.txt", O_RDONLY);
	if (fd == -1) {
		perror("open"); // Print the user-friendly error for open (since errno is global).
		printf("%d: %s\n", errno, strerror(errno)); // Access the errno programmatically.
		return -1;
	}

	return 0;
}

