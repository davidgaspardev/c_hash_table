DEBUG_MODE = false

INCLUES_CBYTES = includes/cbytes/src

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

CC = clang
CFLAGS = -c -Wall
CINCLUDES =             \
	-Isrc               \
	-I$(INCLUES_CBYTES)

# Targets files
$(BIN_DIRECTORY):
	@mkdir $@
	@echo [ OK ] Directory created: $@

$(OBJ_DIRECTORY):
	@mkdir $@
	@echo [ OK ] Directory created: $@

.PHONY: clean debug build library clean_library test test_hash_create

clean:
ifeq ($(OS),Windows_NT)
	@$(foreach dir, $(TMP_DIRECTORIES), del /s /q $(dir))
else
	@$(foreach dir, $(TMP_DIRECTORIES), rm -rf $(dir))
endif
	@echo "[ OK ] Removed directories if they existed: $(TMP_DIRECTORIES)"

library:
	@$(MAKE) -C includes/cbytes library

clean_library:
	@$(MAKE) -C includes/cbytes clean

build: $(OBJECTS)

debug:
	@$(eval DEBUG_MODE = true)

# Compile for object files
$(OBJ_DIRECTORY)/%.o: $(OBJ_DIRECTORY) $(SRC_DIRECTORY)/%.c
	@if [ $(DEBUG_MODE) = "true" ]; then \
		$(CC) $(CFLAGS) $(CINCLUDES) -D DEBUG_MODE $(word 2, $^) -o $@; \
	else \
		$(CC) $(CFLAGS) $(CINCLUDES) $(word 2, $^) -o $@; \
	fi

build_test: debug $(BIN_DIRECTORY) $(OBJECTS)
	@$(CC) $(CINCLUDES) $(TESTS_DIRECTORY)/hash_create.c -o $(BIN_DIRECTORY)/test $(OBJECTS) -Lincludes/cbytes/lib -lcbytes
	@echo [ OK ] Test builded

test_hash_create: $(BIN_DIRECTORY) $(OBJECTS)
	@echo "[ OK ] Compile hash creation test"
	@$(CC) $(CINCLUDES) $(TESTS_DIRECTORY)/hash_create.c -o $(BIN_DIRECTORY)/$@ $(OBJECTS) -Lincludes/cbytes/lib -lcbytes
	@echo "[ OK ] Run hash creation test: $(BIN_DIRECTORY)/$@"
	@$(BIN_DIRECTORY)/$@

test_hashtable_create: $(BIN_DIRECTORY) $(OBJECTS)
	@echo "[ OK ] Compile hashtable creation test"
	@$(CC) $(CINCLUDES) $(TESTS_DIRECTORY)/hashtable_create.c -o $(BIN_DIRECTORY)/$@ $(OBJECTS) -Lincludes/cbytes/lib -lcbytes
	@echo "[ OK ] Run hashtable createtion test: $(BIN_DIRECTORY)/$@"
	@$(BIN_DIRECTORY)/$@

test: test_hash_create test_hashtable_create
