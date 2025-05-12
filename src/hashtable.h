#ifndef HASHTABLE_H_
#define HASHTABLE_H_

#include <stdlib.h>
#include <stdint.h>
#include "hash.h"

#ifdef DEBUG_MODE
#include <stdio.h>
#endif

typedef unsigned int uint_t;

typedef struct cell {
    byte_t key[20];
    void * data;
    void * next;
} cell_t;

typedef struct hashtable {
    cell_t* cells;
    uint_t size;
    uint_t entry_size;
} hashtable_t;

hashtable_t* create_hashtable(uint_t table_size);
hashtable_t* create_hashtable_with_entry_size(uint_t table_size, uint_t entry_size);
void destroy_hashtable(hashtable_t* hashtable);

// Store a reference to the data in the hashtable (WRITE/INPUT).
// The hashtable will store a pointer to the provided data without copying it.
// The caller is responsible for ensuring the data remains valid while in the hashtable.
int8_t hashtable_set(hashtable_t* hashtable, char key[20], void* data);

// Store a copy of the data in the hashtable (WRITE/INPUT).
// The hashtable will allocate memory using the predefined entry_size
// and copy the provided data into the allocated memory.
int8_t hashtable_set_copy(hashtable_t* hashtable, char key[20], void* data);

// Store a copy of the data in the hashtable (WRITE/INPUT).
// The hashtable will allocate memory based on the provided size
// and copy the provided data into the allocated memory.
int8_t hashtable_set_copy_custom(hashtable_t* hashtable, char key[20], void* data, uint8_t size);

void*  hashtable_get(hashtable_t* hashtable, char key[20]);
void   hashtable_print(hashtable_t* hashtable);

static void load_data_bytes(byte_t* src, byte_t* dst, uint8_t size);

#endif