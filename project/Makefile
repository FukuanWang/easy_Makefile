#####################################################
# Author		: Fukuan
# Date			: 2021-12-25
#####################################################

#####################################################
#				user definition part				#
#####################################################

#here determine your target name
TARGET			:= test

# target type: 
# -SHR			:  .so file
# -EXE			:  executable file
TGT_TYPE		:= EXE

# here determine your compiler: default is g++
COMPILER		:= g++

# here add neccessary libraries
# .so or .a 
LIBS			:=

# here determin system root
SYSROOT 		:= 

# current path
CUR_DIR 		:= $(shell pwd)

#include path
#you can add your own include path below
INCLUDE 		:= -I$(CUR_DIR) \
				   -I$(CUR_DIR)/include \
				   -I$(CUR_DIR)/include/h_header \
				   -I$(CUR_DIR)/include/hpp_header

#source path
#you can add your own source path below
SRC_DIR 		:= $(CUR_DIR) \
				   $(CUR_DIR)/src \
				   $(CUR_DIR)/src/c_src \
				   $(CUR_DIR)/src/cpp_src

#determine complilation flags
# - SHR_FLAGS for shared library
# - EXE_FLAGS for executed file
SHR_FLAGS 		:= -fPIC -shared -Wall
EXE_FLAGS 		:= -Wall -O3 

#####################################################
#  			  end user definition part  			#
#####################################################


#get .c file and .cpp file
SRC_C 			:= $(foreach src, $(SRC_DIR), $(wildcard $(src)/*.c))
SRC_CPP 	 	:= $(foreach src, $(SRC_DIR), $(wildcard $(src)/*.cpp))
SRC			 	:= $(SRC_C) $(SRC_CPP)

#object file
OBJ 		 	:= $(patsubst %.c, %.o, $(SRC_C))
OBJ 			+= $(patsubst %.cpp, %.o, $(SRC_CPP))

# out path
OUT_DIR		 	:= $(CUR_DIR)/out
OBJ_DIR		 	:= $(OUT_DIR)/obj
EXE_DIR			:= $(OUT_DIR)/bin
SHR_DIR			:= $(OUT_DIR)/lib
OBJ_WOUT_DIR	:= $(notdir $(OBJ))
OBJ_WITH_DIR	:= $(addprefix $(OBJ_DIR)/, $(OBJ_WOUT_DIR))

# target path
TGT_DIR			:= $($(TGT_TYPE)_DIR)
TGT_WITH_DIR	:= $(TGT_DIR)/$(TARGET)

#a soft link of target file to current directory
TGT_SLINK		:= $(CUR_DIR)/$(TARGET)

#  compiler flags
CML_FLAGS		:= $($(TGT_TYPE)_FLAGS)

# define a function to create directories
define CRT_DIR
	[ -d $(1) ] || mkdir -p $(1)
endef

.PHONY		 	: clean all crt_dirs

all				: crt_dirs $(TGT_SLINK)

crt_dirs		:
	@$(call CRT_DIR, $(OUT_DIR))
	@$(call CRT_DIR, $(OBJ_DIR))
	@$(call CRT_DIR, $(TGT_DIR))

$(TGT_SLINK)	: $(TARGET)
ifeq ($(TGT_TYPE), EXE)
	@echo "creating a soft link of exe file to current directory..."
	ln -s $(TGT_WITH_DIR) $^ 
endif
        
$(TARGET)		:$(OBJ_WITH_DIR)
	@echo "linking object file..."
	$(COMPILER) $(CML_FLAGS) $(INCLUDE) $(LIBS) $^ -o $@ $(SYSROOT)
	mv $@ $(TGT_DIR) 

$(OBJ_WITH_DIR)	:$(SRC)
	@echo "compiling source file..."
	$(COMPILER) $(CML_FLAGS) $(INCLUDE) $(LIBS) -c $(SRC) $(SYSROOT)
	mv $(CUR_DIR)/*.o $(OBJ_DIR)/

clean			:
	rm -rf $(OUT_DIR)
	rm -rf $(TGT_SLINK)

