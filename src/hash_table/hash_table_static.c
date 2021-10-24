#include "hash_table_static.h"

// Ensure that the table has no data dirt
void init_hash_table() {
    for(int i = 0; i < TABLE_SIZE; i++) {
        hash_table[i] = NULL;
    }
}

// Show table state
void print_hash_table() {

    printf("\n========== TABLE START ==========\n");

    for(int i = 0; i < TABLE_SIZE; i++) {
        if (hash_table[i] == NULL) {
            printf("\t%i\t---\n", i);
        } else if(hash_table[i] == DELETE_NODE) {
            printf("\t%i\t<deleted>\n", i);
        } else {
            printf("\t%i\t%s\n", i, hash_table[i]->name);
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
    // start at the location that the hash function has provided me, 
    // if you've already found the site to keep looking for adding one more in
    // the hash function location.
    for(int i = 0; i < TABLE_SIZE; i++) {
        int looking = (i + index) % TABLE_SIZE;
        if(hash_table[looking] == NULL || hash_table[looking] == DELETE_NODE) {
            hash_table[looking] = person;
            return 1;
        }
    }
    return 0;
}

// Find a person in the table by their name
struct person * hash_table_lookup(char * name) {
    int index = hash(name);
    for(int i = 0; i < TABLE_SIZE; i++) {
        int looking = (i + index) % TABLE_SIZE;
        if(hash_table[looking] == NULL) return NULL;
        if(hash_table[looking] == DELETE_NODE) continue;
        if(hash_table[looking] != NULL && equal(name, hash_table[looking]->name)) {
            return hash_table[looking];
        }
    }

    return NULL;
}

// Delete a person in the table by their name
struct person * hash_table_delete(char * name) {
    int index = hash(name);
    for(int i = 0; i < TABLE_SIZE; i++) {
        int looking = (i + index) % TABLE_SIZE;
        if(hash_table[looking] == NULL) return NULL;
        if(hash_table[looking] == DELETE_NODE) continue;
        if(hash_table[looking] != NULL && equal(name, hash_table[looking]->name)) {
            struct person * tmp = hash_table[looking];
            hash_table[looking] = DELETE_NODE;
            return tmp;
        }
    }
    return NULL;
}