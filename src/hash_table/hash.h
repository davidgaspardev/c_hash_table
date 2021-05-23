#ifndef _HASH_H_
#define _HASH_H_

#include "../string.h"

#define MAX_SIZE   256
#define TABLE_SIZE  30

// Hash table declared
struct person * hash_table[TABLE_SIZE];

// Hash function
unsigned int hash(char * name) {

    unsigned int len = length(name);

    unsigned int hash_value = 0;

    for(int i = 0; i < len; i++) {
        hash_value += name[i];
        hash_value *= name[i];
        hash_value %= TABLE_SIZE;
    }

    return hash_value;
}

#endif