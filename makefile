DIR_SRC := src
DIR_INC := inc
DIR_BIN := bin
DIR_OBJ := obj
CC := gcc
CFLAGS := -std=c11 -fsanitize=address -Wall -Wextra -Wpedantic
DFLAGS := -g -DDEBUG
DIR_BUILD := $(DIR_BIN) $(DIR_OBJ)
COMPILE := $(CC) $(CFLAGS)

.phony: run% clean
run%: $(DIR_BIN)/% | $(DIR_BIN)
	./$<
clean:
	rm -rf $(DIR_BUILD)
$(DIR_BUILD):
	mkdir $@
$(DIR_SRC)/%.c: $(DIR_INC)/%.h | $(DIR_INC)
$(DIR_OBJ)/%.o: $(DIR_SRC)/%.c | $(DIR_OBJ)
	$(COMPILE) -c -o $@ $^
$(DIR_BIN)/%: $(DIR_SRC)/driver.c $(DIR_OBJ)/util.o $(DIR_OBJ)/%.o | $(DIR_BUILD)
	$(COMPILE) -o $@ $^
2.1: $(DIR_OBJ)/2.1.o
