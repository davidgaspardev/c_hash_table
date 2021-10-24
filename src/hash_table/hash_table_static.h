#ifndef _HASH_TABLE_H_
#define _HASH_TABLE_H_

// Include internal code
#include "hash.h"
#include "../string.h"

// Directive
// The #define directive allows the definition of macros within your source code.
#define DELETE_NODE (struct person*)(0xFFFFFFFFFFFFFFFFUL)

// Person data structure
struct person {
    char name[MAX_SIZE];
    unsigned int age;

    // 1 is male and 0 is fame
    unsigned int sex:1;
};

void init_hash_table();
void print_hash_table();
unsigned int hash_table_insert(struct person * person);
struct person * hash_table_lookup(char * name);
struct person * hash_table_delete(char * name);

#endif