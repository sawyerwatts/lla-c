
#include "parse.h"

struct dbheader_t {
	unsigned short version;
	unsigned short count;
};

int parse_file_header(int fd, int *numEmployeesOut) {
	if (fd == -1) {
		return -1;
	}

	return 0;
}

