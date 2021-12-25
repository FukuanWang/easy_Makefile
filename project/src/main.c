#include <stdio.h>
#include "header1.h"
#include "header2.h"

int main(int argc, char** argv) {
	fprintf(stdout, "hello world\n");

#ifdef __HEADER_1__
	show_myname(argv[0]);
#endif
	
#ifdef __HEADER_2__
	show_arguments(argc, argv);
#endif

	return 0;
}
