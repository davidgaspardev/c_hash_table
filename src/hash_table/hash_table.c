#include "hash_table.h"

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
    // Get table index
    int index = hash(name);

    struct person * tmp = hash_table[index];
    struct person * prev = NULL;

    while (tmp != NULL) {
        if(equal(name, tmp->name)) {
            if(prev != NULL) prev->next = tmp->next;
            else hash_table[index] = tmp->next;
            break;
        } else {
            prev = tmp;
            tmp = tmp->next;
        }
    }
    
    return tmp;
}