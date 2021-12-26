#include <stdio.h>
#include "header1.h"
#include "header2.h"
#include "header3.hpp"

int main(int argc, char** argv) {
	fprintf(stdout, "hello world\n");

#ifdef __HEADER1_H__
	show_myname(argv[0]);
#endif
	
#ifdef __HEADER2_H__
	show_arguments(argc, argv);
#endif

	return 0;
}
