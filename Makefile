CC = gcc
CFLAGS = -Wall

BIN_DIR   = bin
BUILD_DIR = build
SRC_DIR   = src
TESTS_DIR = tests

create_bin_dir:
ifeq ($(OS),Windows_NT)
	@IF NOT EXIST bin (echo [ OK ] Directory create: $(BIN_DIR))
	@IF EXIST bin (echo [ OK ] Directory already exists: $(BIN_DIR))
	@IF NOT EXIST bin (mkdir $(BIN_DIR))
else
	@mkdir -p $(BIN_DIR)
endif

delete_bin_dir:
ifeq ($(OS),Windows_NT)
	@IF EXIST bin (echo [ OK ] Directory delete: $(BIN_DIR))
	@IF EXIST bin (rd /s /q $(BIN_DIR))
else
	@rm -rf $(BIN_DIR)
endif

create_build_dir:
ifeq ($(OS),Windows_NT)
	@IF NOT EXIST build (echo [ OK ] Directory create: $(BUILD_DIR))
	@IF EXIST build (echo [ OK ] Directory already exists: $(BUILD_DIR))
	@IF NOT EXIST build (mkdir $(BUILD_DIR))
else
	@mkdir -p $(BUILD_DIR)
endif

delete_build_dir:
ifeq ($(OS),Windows_NT)
	@IF EXIST build (echo [ OK ] Directory delete: $(BUILD_DIR))
	@IF EXIST build (rd /s /q $(BUILD_DIR))
else
	@rm -rf $(BUILD_DIR)
endif

clean: delete_bin_dir delete_build_dir

hashtable.o: create_build_dir
	@$(CC) $(CFLAGS) -c $(SRC_DIR)/hashtable.c -o $(BUILD_DIR)/$@

hashtable_debug.o: create_build_dir
	@$(CC) $(CFLAGS) -D DEBUG_MODE -c $(SRC_DIR)/hashtable.c -o $(BUILD_DIR)/$@

hashtable_create.o: create_build_dir
	@$(CC) $(CFLAGS) -c $(TESTS_DIR)/hashtable_create.c -o $(BUILD_DIR)/$@

buid_test: create_bin_dir hashtable.o hashtable_create.o
	@$(CC) -o $(BIN_DIR)/test $(BUILD_DIR)/$(word 2, $^) $(BUILD_DIR)/$(word 3, $^)
	@echo [ OK ] Test builded

test: buid_test
	@echo [ OK ] Run test: $(BIN_DIR)/test
ifeq ($(OS),Windows_NT)
	@$(BIN_DIR)/test.exe
else
	@$(BIN_DIR)/test
endif