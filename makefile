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

.phony: all run debug rundbg test clean
all: $(EXEC)
run: $(EXEC)
	./$@
debug: $(EXEC)_debug
rundbg: $(EXEC)_debug
	./$@
clean:
	rm -rf $(DIR_BUILD)
test:
	@echo $(OBJ)
$(DIR_BUILD):
	mkdir $@
$(DIR_OBJ)/%.o: $(DIR_SRC)/%.c | $(DIR_OBJ)
	$(COMPILE) -c -o $@ $<
$(EXEC): $(OBJ) | $(DIR_BIN)
	$(COMPILE) -o $@ $^
