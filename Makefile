CC = gcc
CFLAGS = -Wall

# Directories
BIN_DIRECTORY   = bin
BUILD_DIRECTORY = build
SRC_DIRECTORY   = src
TESTS_DIRECTORY = tests

# Targets files
$(BIN_DIRECTORY):
ifeq ($(OS),Windows_NT)
	@IF NOT EXIST bin (echo [ OK ] Directory create: $@)
	@IF EXIST bin (echo [ OK ] Directory already exists: $@)
	@IF NOT EXIST bin (mkdir $@)
else
	@mkdir -p $@
endif

$(BUILD_DIRECTORY):
ifeq ($(OS),Windows_NT)
	@IF NOT EXIST build (echo [ OK ] Directory create: $@)
	@IF EXIST build (echo [ OK ] Directory already exists: $@)
	@IF NOT EXIST build (mkdir $@)
else
	@mkdir -p $@
endif

.PHONY: clean test

clean:
ifeq ($(OS),Windows_NT)
	@IF EXIST bin (echo [ OK ] Directory delete: $(BIN_DIRECTORY))
	@IF EXIST bin (rd /s /q $(BIN_DIRECTORY))
	@IF EXIST build (echo [ OK ] Directory delete: $(BUILD_DIRECTORY))
	@IF EXIST build (rd /s /q $(BUILD_DIRECTORY))
else
	@rm -rf $(BIN_DIRECTORY)
	@rm -rf $(BUILD_DIRECTORY)
endif

hashtable.o: $(BUILD_DIRECTORY)
	@$(CC) $(CFLAGS) -c $(SRC_DIRECTORY)/hashtable.c -o $(BUILD_DIRECTORY)/$@

hashtable_debug.o: $(BUILD_DIRECTORY)
	@$(CC) $(CFLAGS) -D DEBUG_MODE -c $(SRC_DIRECTORY)/hashtable.c -o $(BUILD_DIRECTORY)/$@

hashtable_create.o: $(BUILD_DIRECTORY)
	@$(CC) $(CFLAGS) -c $(TESTS_DIRECTORY)/hashtable_create.c -o $(BUILD_DIRECTORY)/$@

buid_test: $(BIN_DIRECTORY) hashtable_debug.o hashtable_create.o
	@$(CC) -o $(BIN_DIRECTORY)/test $(BUILD_DIRECTORY)/$(word 2, $^) $(BUILD_DIRECTORY)/$(word 3, $^)
	@echo [ OK ] Test builded

test: buid_test
	@echo [ OK ] Run test: $(BIN_DIRECTORY)/test
ifeq ($(OS),Windows_NT)
	@$(BIN_DIRECTORY)/test.exe
else
	@$(BIN_DIRECTORY)/test
endif