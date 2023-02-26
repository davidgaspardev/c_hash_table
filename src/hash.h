#ifndef HASH_H_
#define HASH_H_

#ifdef DEBUG_MODE
#include <stdio.h>
#endif

#include <cbytes.h>

unsigned int hash(const char * key, unsigned int max_size);

#endif