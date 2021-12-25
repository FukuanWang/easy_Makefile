## usage
1. Only for small c/c++ project, cmake is preferred for large project.
2. This Makefile can be used for generating 
	- executed target
	- .so target
	by configurating the TGT_TYPE


## example
- project tree before make
	.
	├── include
	│   ├── h_header
	│   │   ├── header1.h
	│   │   └── header2.h
	│   └── hpp_header
	│       └── header3.hpp
	├── Makefile
	└── src
	    ├── cpp_src
	    │   └── src3.cpp
	    ├── c_src
	    │   ├── src1.c
	    │   └── src2.c
	    └── main.c

- project tree after make
	.
	├── include
	│   ├── h_header
	│   │   ├── header1.h
	│   │   └── header2.h
	│   └── hpp_header
	│       └── header3.hpp
	├── Makefile
	├── out
	│   ├── bin
	│   │   └── test
	│   └── obj
	│       ├── main.o
	│       ├── src1.o
	│       ├── src2.o
	│       └── src3.o
	├── src
	│   ├── cpp_src
	│   │   └── src3.cpp
	│   ├── c_src
	│   │   ├── src1.c
	│   │   └── src2.c
	│   └── main.c
	└── test -> ./project/out/bin/test

