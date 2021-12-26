#include "header2.h"

void show_arguments(int argc, char** argv) {
	if (argc <= 1) {
		fprintf(stdout, "no arguments is given\n");
		return;
	}
	fprintf(stdout, "arguments:\n");
	int it;
	for (it = 1; it < argc; it++) {
		fprintf(stdout, "%s\n", argv[it]);
	}
}

