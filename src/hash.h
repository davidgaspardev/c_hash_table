#ifndef HASH_H_
#define HASH_H_

#ifdef DEBUG_MODE
#include <stdio.h>
#endif

#include <cbytes.h>

typedef unsigned long hash_t;

unsigned int hash(const char * key, unsigned int max_size);

static hash_t knuth_hash(const char* input);
static hash_t djb2_hash(const char* input);

#endif