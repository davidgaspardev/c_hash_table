CC = clang
CFLAGS = -c -Wall

# Directories
BIN_DIRECTORY   = bin
OBJ_DIRECTORY   = obj
SRC_DIRECTORY   = src
TESTS_DIRECTORY = tests

# Directories that can be removed
TMP_DIRECTORIES =    \
	$(BIN_DIRECTORY) \
	$(OBJ_DIRECTORY)

SOURCES = $(wildcard $(SRC_DIRECTORY)/*.c)
OBJECTS = $(patsubst $(SRC_DIRECTORY)/%.c, $(OBJ_DIRECTORY)/%.o, $(SOURCES))

# Targets files
$(BIN_DIRECTORY):
	@mkdir $@
	@echo [ OK ] Directory created: $@

$(OBJ_DIRECTORY):
	@mkdir $@
	@echo [ OK ] Directory created: $@

.PHONY: clean test build_test

clean:
ifeq ($(OS),Windows_NT)
	@$(foreach dir, $(TMP_DIRECTORIES), del /s /q $(dir))
else
	@$(foreach dir, $(TMP_DIRECTORIES), rm -rf $(dir))
endif
	@echo "[ OK ] Removed directories if they existed: $(TMP_DIRECTORIES)"

build: $(OBJECTS)

$(OBJ_DIRECTORY)/%.o: $(OBJ_DIRECTORY) $(SRC_DIRECTORY)/%.c
	$(CC) $(CFLAGS) $(word 2, $^) -o $@

hashtable.o: $(OBJ_DIRECTORY)
	@$(CC) $(CFLAGS) $(SRC_DIRECTORY)/hashtable.c -o $(OBJ_DIRECTORY)/$@

hashtable_debug.o: $(OBJ_DIRECTORY)
	@$(CC) $(CFLAGS) -D DEBUG_MODE $(SRC_DIRECTORY)/hashtable.c -o $(OBJ_DIRECTORY)/$@

hashtable_create.o: $(OBJ_DIRECTORY)
	@$(CC) $(CFLAGS) $(TESTS_DIRECTORY)/hashtable_create.c -o $(OBJ_DIRECTORY)/$@

build_test: $(BIN_DIRECTORY) hashtable_debug.o hashtable_create.o
	@$(CC) -o $(BIN_DIRECTORY)/test $(OBJ_DIRECTORY)/$(word 2, $^) $(OBJ_DIRECTORY)/$(word 3, $^)
	@echo [ OK ] Test builded

test: build_test
	@echo [ OK ] Run test: $(BIN_DIRECTORY)/test
ifeq ($(OS),Windows_NT)
	@$(BIN_DIRECTORY)/test.exe
else
	@$(BIN_DIRECTORY)/test
endif