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
    char key[20];
    void * data;
    void * next;
} cell_t;

typedef struct hashtable {
    cell_t* cells;
    uint_t size;
} hashtable_t;

hashtable_t * create_hashtable(uint_t table_size);

void destroy_hashtable(hashtable_t * hashtable);

// Insert cell in the hashtable (WRITE/INPUT)
int8_t hashtable_insert(hashtable_t * hashtable, cell_t cell);

// Show all cell data from hashtable
void show_hashtable(hashtable_t * hashtable);

#endif