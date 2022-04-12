# "makefile" - Build script.
DIR_SRC := src
DIR_INC := inc
DIR_BIN := bin
DIR_OBJ := obj
APP := test
CC := gcc
CFLAGS := -std=c11 -fsanitize=address -Wall -Wextra -Wpedantic
DFLAGS := -g -DDEBUG
FLAGS := $(CFLAGS)
EXEC := $(DIR_BIN)/$(APP)
DIR_BUILD := $(DIR_BIN) $(DIR_OBJ)
FILE_INCLUDE := $(DIR_INC)/include.h
FILE_DRIVER := $(DIR_SRC)/driver.c

INC := $(shell find -regex ".*\/$(DIR_INC)\/.*\.h")
INC := $(subst ./,,$(INC))
INC := $(subst $(FILE_INCLUDE),,$(INC))
INC := $(subst $(DIR_INC)/,,$(INC))
SRC := $(shell find -regex ".*\/$(DIR_SRC)\/.*\.c")
SRC := $(subst ./,,$(SRC))
SRC := $(subst $(FILE_DRIVER),,$(SRC))
OBJ := $(patsubst $(DIR_SRC)/%.c,$(DIR_OBJ)/%.o,$(SRC))

.phony: all run debug rundbg clean test
all: $(EXEC)
run: $(EXEC)
	./$<
debug: FLAGS += $(DFLAGS)
debug: all
rundbg: FLAGS += $(DFLAGS)
rundbg: run
clean: FORCE
	rm -rf $(DIR_BUILD) $(FILE_INCLUDE) 
test:
	@echo $(OBJ)
FORCE:
$(FILE_INCLUDE): $(FILE_DRIVER)
	@echo "Generating \"$@\"..."
	@echo "/* \"include.h\" - All includes (auto-generated). */" > $@
	@echo "#ifndef INCLUDE_H" >> $@
	@echo "#define INCLUDE_H" >> $@
	@$(foreach f,$(INC),echo "#include \"$(f)\"" >> $@;)
	@echo "#endif" >> $@
$(DIR_BUILD):
	mkdir $@
$(DIR_OBJ)/%.o: $(DIR_SRC)/%.c | $(DIR_OBJ)
	$(CC) $(FLAGS) -c -o $@ $<
$(EXEC) $(EXEC)_debug: $(FILE_DRIVER) $(OBJ) | $(FILE_INCLUDE) $(DIR_BIN)
	$(CC) $(FLAGS) -o $@ $^
