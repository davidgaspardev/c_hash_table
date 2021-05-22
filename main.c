// Include standard code
#include <stdio.h>
// Include internal code
#include "src/string.h"

// Directive
// The #define directive allows the definition of macros within your source code.
#define MAX_SIZE   256
#define TABLE_SIZE  15
#define DELETE_NODE (struct person*)(0xFFFFFFFFFFFFFFFFUL)

// Person data structure
struct person {
    char name[MAX_SIZE];
    unsigned int age;

    // 1 is male and 0 is fame
    unsigned int sex:1;
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
        int try = (i + index) % TABLE_SIZE;
        if(hash_table[try] == NULL || hash_table[try] == DELETE_NODE) {
            hash_table[try] = person;
            return 1;
        }
    }
    return 0;
}

// Find a person in the table by their name
struct person * hash_table_lookup(char * name) {
    int index = hash(name);
    for(int i = 0; i < TABLE_SIZE; i++) {
        int try = (i + index) % TABLE_SIZE;
        if(hash_table[try] == NULL) return NULL;
        if(hash_table[try] == DELETE_NODE) continue;
        if(hash_table[try] != NULL && equal(name, hash_table[try]->name)) {
            return hash_table[try];
        }
    }

    return NULL;
}

// Delete a person in the table by their name
struct person * hash_table_delete(char * name) {
    int index = hash(name);
    for(int i = 0; i < TABLE_SIZE; i++) {
        int try = (i + index) % TABLE_SIZE;
        if(hash_table[try] == NULL) return NULL;
        if(hash_table[try] == DELETE_NODE) continue;
        if(hash_table[try] != NULL && equal(name, hash_table[try]->name)) {
            struct person * tmp = hash_table[try];
            hash_table[try] = DELETE_NODE;
            return tmp;
        }
    }
    return NULL;
}

// Entry pointer
int main(unsigned int argc, const char ** argv) {

    init_hash_table();

    struct person p1 = {
        .name = "Emma Watson",
        .age = 31,
        .sex = 1
    };

    struct person p2 = {
        .name = "Cara Delevingne",
        .age = 28,
        .sex = 0
    };

    struct person p3 = {
        .name = "Steve Wozniak",
        .age = 70,
        .sex = 1
    };

    struct person p4 = {
        .name = "Jeff Bezos",
        .age = 57,
        .sex = 0
    };

    struct person p5 = {
        .name = "Mark Zuckerberg",
        .age = 36,
        .sex = 1
    };

    struct person p6 = {
        .name = "Bill Gates",
        .age = 65,
        .sex = 1
    };

    struct person p7 = {
        .name = "Elon Musk",
        .age = 49,
        .sex = 1
    };

    struct  person p8 = {
        .name = "David Gaspar",
        .age = 22,
        .sex = 1
    };
    

    hash_table_insert(&p1);
    hash_table_insert(&p2);
    hash_table_insert(&p3);
    hash_table_insert(&p4);
    hash_table_insert(&p5);
    hash_table_insert(&p6);
    hash_table_insert(&p7);
    hash_table_insert(&p8);
    
    print_hash_table();

    if(argc > 1) {

        for(int i = 1; i < argc; i++) {

            struct person * found = hash_table_lookup((char *) argv[i]);

            if(found != NULL) {
                printf("[ %s found ", found->name);
                printf("(%s is %i years old) ]\n", found->sex ? "He" : "She", found->age);
            } else {
                printf("[ %s not found ]\n", argv[i]);
            }

        }

    }

    return 1;
}
