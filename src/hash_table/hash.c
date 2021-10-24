#include "hash.h"

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