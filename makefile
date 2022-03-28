DIR_SRC := src
DIR_INC := inc
DIR_BIN := bin
DIR_OBJ := obj
EXT_SRC := c
APP := test
CC := gcc
CFLAGS := -std=c11 -fsanitize=address -Wall -Wextra -Wpedantic
DFLAGS := -g -DDEBUG
EXEC := $(DIR_BIN)/$(APP)
DIR_BUILD := $(DIR_BIN) $(DIR_OBJ)
COMPILE := $(CC) $(CFLAGS)

MT :=
SP := $(MT) $(MT)
SRC_FIND_REGEX := $(subst $(SP),\|,\($(EXT_SRC)\))
SRC_FIND := $(shell find -regex ".*\/$(DIR_SRC)\/.*.$(SRC_FIND_REGEX)")
SRC := $(subst ./,,$(SRC_FIND))
OBJ := $(patsubst $(DIR_SRC)/%.c,$(DIR_OBJ)/%.o, $(SRC))
INC := $(shell find -regex ".*\/$(DIR_INC)\/.*.h")
INC := $(subst ./$(DIR_INC)/,,$(INC))

.phony: all run debug rundbg clean test
FORCE:
all: $(EXEC)
run: $(EXEC)
	./$<
debug: $(EXEC)_debug
rundbg: $(EXEC)_debug
	./$<
clean: FORCE
	rm -rf $(DIR_BUILD) $@ 
test:
	@echo $(OBJ)
$(DIR_INC)/include.h: FORCE
	@echo "=== Generating \"$@\"... ==="
	echo "/* \"include.h\" - All includes (auto-generated). */" > $@
	echo "#ifndef INCLUDE_H" >> $@
	echo "#define INCLUDE_H" >> $@
	$(foreach f,$(INC),echo "#include \"$(f)\"" >> $@;)
	echo "#endif" >> $@
	@echo "=== Generated \"$@\". ==="
$(DIR_BUILD):
	mkdir $@
$(DIR_OBJ)/%.o: $(DIR_SRC)/%.c | $(DIR_OBJ)
	$(COMPILE) -c -o $@ $<
$(EXEC): $(DIR_INC)/include.h $(OBJ) | $(DIR_BIN)
	$(COMPILE) -o $@ $^
