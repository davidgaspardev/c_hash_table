#ifndef _HASH_H_
#define _HASH_H_

#include "../string.h"

#define MAX_SIZE   256
#define TABLE_SIZE  30

// Hash table declared
struct person * hash_table[TABLE_SIZE];

unsigned int hash(char * name);

#endif