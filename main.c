#include <stdio.h>

// Directive
// The #define directive allows the definition of macros within your source code.
#define MAX_SIZE   256
#define TABLE_SIZE  10

// Person data structure
struct person {
    char name[MAX_SIZE];
    unsigned int age;

    // 1 is male and 0 is fame
    unsigned int sex:1;
};

// Get argument length
unsigned int length(char * arg) {

    unsigned int offset = 0;

    unsigned int count = 0;

    while (*(arg + offset) != '\0') {
        ++offset;
        ++count;
    }

    return count;
}

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

void init_hash_table() {
    for(int i = 0; i < TABLE_SIZE; i++) {
        hash_table[i] = NULL;
    }
}

void print_hash_table() {
    for(int i = 0; i < TABLE_SIZE; i++) {
        if (hash_table[i] == NULL) {
            printf("\t%i\t---\n", i);
        } else {
            printf("\t%i\t%s\n", i, hash_table[i]->name);
        }
    }
}

int hash_table_insert(struct person * person) {
    if(person == NULL) return 0;

    int index = hash(person->name);
    if(hash_table[index] != NULL) {
        return 0;
    }
    hash_table[index] = person;
    return 1;
}

// Entry pointer
int main(unsigned int argc, const char ** argv) {

    init_hash_table();

    struct person p1 = {
        .name = "David",
        .age = 22,
        .sex = 1
    };

    struct person p2 = {
        .name = "Elizabete",
        .age = 40,
        .sex = 0
    };

    struct person p3 = {
        .name = "Samuel",
        .age = 40,
        .sex = 1
    };

    struct person p4 = {
        .name = "Marta",
        .age = 79,
        .sex = 0
    };

    struct person p5 = {
        .name = "Abel",
        .age = 80,
        .sex = 1
    };

    struct person p6 = {
        .name = "Adelina",
        .age = 20,
        .sex = 0
    };

    hash_table_insert(&p1);
    hash_table_insert(&p2);
    hash_table_insert(&p3);
    hash_table_insert(&p4);
    hash_table_insert(&p5);
    hash_table_insert(&p6);
    

    print_hash_table();

    return 1;
}