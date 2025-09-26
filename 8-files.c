#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/stat.h>

// fd, file descriptor, is the file number that the kernel understands. and in on Linux,
// everything is a file, like sockets and stuff too.
// fd 0 is stdin
// fd 1 is stdout
// fd 2 is stderr

void write_file(char *fileName) {
	printf("Opening (and creating if does not exist) %s\n", fileName);
	int fd = open(fileName, O_CREAT | O_RDWR, 0664);
	if (fd == -1) {
		perror("open");
		return;
	}

	char *buffer = "hello!\n";
	printf("Writing '%s' to file\n", buffer);
	write(fd, buffer, strlen(buffer));

	if (close(fd) == -1) {
		perror("close");
		return;
	}
}

struct database_header_t {
	unsigned short version;
	unsigned short numemployees;
	unsigned int filesize;
};

// init file w/: $ echo -ne "\x01\x00\xff\x00\x08\x00\x00\x00" > ./8-db.db
int read_file(char *fileName) {
	int fd = open(fileName, O_CREAT | O_RDWR, 0664);
	if (fd == -1) {
		perror("open");
		return -1;
	}

	int status = -99;
	struct database_header_t head = {0};
	if (read(fd, &head, sizeof(head)) != sizeof(head)) {
		perror("head");
		status = -2;
		goto end;
	}
	printf("DB header's version: %u\n", head.version);
	printf("DB header's num employees: %u\n", head.numemployees);
	printf("DB header's file size: %u\n", head.filesize);
	// DB version: 1
	// DB num employees: 255
	// DB file size: 8

	// stat is a Linux command to get meta data about a file, and glibc also has a few stat
	// functions to do this too.
	struct stat dbStat = {0};
	if (fstat(fd, &dbStat) == -1) {
		perror("fstat");
		status = -3;
		goto end;
	}
	printf("DB file size, reported by stat: %lu\n", dbStat.st_size);

	// Test by updating file size: $ echo -ne "\x01\x00\xff\x00\x09\x00\x00\x00" > ./8-db.db
	if (head.filesize != dbStat.st_size) {
		printf("DB header's file size and fstat's file size disagree\n");
		status = -4;
		goto end;
	}

	status = 0;
end:
	if (close(fd) == -1) {
		perror("close");
		status = -4;
	}
	return status;
}

int main(int argc, char *argv[]) {
	if (argc != 3) {
		printf("Usage: $ %s <filename> <dbfilename>\n", argv[0]);
		return -1;
	}

	write_file(argv[1]);

	return read_file(argv[2]);
}

