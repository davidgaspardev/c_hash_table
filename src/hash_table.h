#ifndef _HASH_TABLE_H_
#define _HASH_TABLE_H_

#include <stdio.h>
#include "string.h"

// Directive
// The #define directive allows the definition of macros within your source code.
#define MAX_SIZE   256
#define TABLE_SIZE  30

// Person data structure
struct person {
    char name[MAX_SIZE];
    unsigned int age;
    // 1 is male and 0 is fame
    unsigned int sex:1;
    // Linked list
    struct person * next;
};

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

// Ensure that the table has no data dirt
void init_hash_table() {
    for(int i = 0; i < TABLE_SIZE; i++) hash_table[i] = NULL;
}

// Show table state
void print_hash_table() {

    printf("\n========== TABLE START ==========\n");

    for(int i = 0; i < TABLE_SIZE; i++) {
        if (hash_table[i] == NULL) {
            printf("\t%i\t---\n", i);
        } else {
            printf("\t%i\t", i);
            struct person * tmp = hash_table[i];
            while (tmp != NULL) {
                printf("%s %s ", tmp->name, tmp->next == NULL ? "" : "-");
                tmp = tmp->next;
            }
            printf("\n");
        }
    }

    printf("========== TABLE END ==========\n\n");
}

// Insert person in the hash table
unsigned int hash_table_insert(struct person * person) {
    // Check if person data exists
    if(person == NULL) return 0;
    // Pass person to hash function
    int index = hash(person->name);
    // Get current person in this index and set next
    person->next = hash_table[index];
    // Set new person in hash_table
    hash_table[index] = person;
    return 1;
}

// Find a person in the table by their name
struct person * hash_table_lookup(char * name) {
    // Get location with hash function
    int index = hash(name);
    struct person * tmp = hash_table[index];
    while(tmp != NULL && !equal(tmp->name, name)) tmp = tmp->next;
    return tmp;
}

// Delete a person in the table by their name
struct person * hash_table_delete(char * name) {
    int index = hash(name);
    struct person * tmp = hash_table[index];
    struct person * prev;
    while (tmp != NULL) {
        if(equal(name, tmp->name)) {
            if(prev != NULL) prev->next = tmp->next;
            break;
        } else {
            prev = tmp;
            tmp = tmp->next;
        }
    }
    
    return tmp;
}

void run_test() {

}

#endif