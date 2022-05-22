# "makefile" - Build script.
DIR_SRC := src
DIR_INC := inc
DIR_BIN := bin
DIR_OBJ := obj
APP := test
CC := gcc
CFLAGS := -std=c11 -fsanitize=address -Wall -Wextra -Wpedantic
DFLAGS := -g -DDEBUG
SFX_DBG := _dbg

FLAGS := $(CFLAGS) -I"$(DIR_INC)"
EXEC := $(DIR_BIN)/$(APP)
EXEC_DBG = $(EXEC)$(SFX_DBG)
DIR_BUILD := $(DIR_BIN) $(DIR_OBJ)
FILE_INCLUDE := $(DIR_INC)/include.h
FILE_MAIN := $(DIR_SRC)/main.c

INC := $(shell find -regex ".*\/$(DIR_INC)\/.*\.h")
INC := $(subst ./,,$(INC))
INC := $(subst $(FILE_INCLUDE),,$(INC))
INC := $(subst $(DIR_INC)/,,$(INC))
SRC := $(shell find -regex ".*\/$(DIR_SRC)\/.*\.c")
SRC := $(subst ./,,$(SRC))
SRC := $(subst $(FILE_MAIN),,$(SRC))
OBJ := $(patsubst $(DIR_SRC)/%.c,$(DIR_OBJ)/%.o,$(SRC))
OBJ_DBG := $(patsubst %.o,%$(SFX_DBG).o,$(OBJ))

.phony: all run debug rundbg clean test
all: $(EXEC)
run: $(EXEC)
	./$<
alldbg: FLAGS += $(DFLAGS)
alldbg: $(EXEC_DBG)
rundbg: FLAGS += $(DFLAGS)
rundbg: $(EXEC_DBG)
	./$<
clean: FORCE
	rm -rf $(DIR_BUILD) $(FILE_INCLUDE) 
test:
	@echo $(OBJ_DBG)
FORCE:
$(FILE_INCLUDE):
	@echo "Generating \"$@\"..."
	@echo "/* \"include.h\" - All includes (auto-generated). */" > $@
	@echo "#ifndef INCLUDE_H" >> $@
	@echo "#define INCLUDE_H" >> $@
	@$(foreach f,$(INC),echo "#include \"$(f)\"" >> $@;)
	@echo "#endif" >> $@
$(DIR_BUILD):
	mkdir $@
$(DIR_OBJ)/%.o $(DIR_OBJ)/%$(SFX_DBG).o: $(DIR_SRC)/%.c | $(FILE_INCLUDE) $(DIR_OBJ)
	$(CC) $(FLAGS) -c -o $@ $<
$(EXEC): $(FILE_MAIN) $(OBJ) | $(DIR_BIN)
	$(CC) $(FLAGS) -o $@ $^
$(EXEC_DBG): $(FILE_MAIN) $(OBJ_DBG) | $(DIR_BIN)
	$(CC) $(FLAGS) -o $@ $^
