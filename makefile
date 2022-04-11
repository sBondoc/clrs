# "makefile" - Build script.
DIR_SRC := src
DIR_INC := inc
DIR_BIN := bin
DIR_OBJ := obj
APP := test
CC := gcc
CFLAGS := -std=c11 -fsanitize=address -Wall -Wextra -Wpedantic
DFLAGS := -g -DDEBUG
EXEC := $(DIR_BIN)/$(APP)
DIR_BUILD := $(DIR_BIN) $(DIR_OBJ)
COMPILE := $(CC) $(CFLAGS)
FILE_INCLUDE := $(DIR_INC)/include.h
FILE_DRIVER := $(DIR_SRC)/driver.c

INC := $(shell find -regex ".*\/$(DIR_INC)\/.*\.h")
INC := $(subst ./,,$(INC))
INC := $(subst $(FILE_INCLUDE),,$(INC))
SRC := $(shell find -regex ".*\/$(DIR_SRC)\/.*\.c")
OBJ := $(patsubst $(DIR_SRC)/%.c,$(DIR_OBJ)/%.o,$(SRC))
INC := $(subst $(DIR_INC)/,,$(INC))

.phony: all run debug rundbg clean test
all: $(EXEC)
run: $(EXEC)
	./$<
debug: $(EXEC)_debug
rundbg: $(EXEC)_debug
	./$<
clean: FORCE
	rm -rf $(DIR_BUILD) $(FILE_INCLUDE) 
test:
	@echo $(SRC)
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
	$(COMPILE) -c -o $@ $<
$(EXEC): $(FILE_INCLUDE) $(FILE_DRIVER) $(OBJ) | $(DIR_BIN)
	$(COMPILE) -o $@ $^
$(EXEC)_debug: $(FILE_INCLUDE) $(FILE_DRIVER) $(OBJ) | $(DIR_BIN)
	$(COMPILE) $(DFLAGS) -o $@ $^
