//
// tcflush: Flush data from the buffer of a serial port
//
// Last edited: 02/16/2018 by Taylor Berg
//

#include <termios.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

int main(int argc, char* argv[]) {
	if (argc != 2) {
		printf("%s: Specify a serial port!\n", argv[0]);
		return -1;
	}

	int fd = open(argv[1], O_RDWR);
	
	if (fd == -1) {
		printf("%s: Could not open %s (%s)\n", argv[0], argv[1], strerror(errno));
		return errno;
	}

	tcflush(fd, TCIFLUSH);
	return 0;
}

