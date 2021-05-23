// Include standard code
#include <stdio.h>
// #include "src/hash_table/hash_table_static.h"
#include "src/string.h"
#include "src/hash_table/hash_table.h"

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
    
    if(argc > 1) {

        unsigned int isDelete = FALSE; 

        for(int i = 1; i < argc; i++) {
            // Check cli (delete command)
            if(i == 1 && equal(argv[i], "delete")) {
                isDelete = TRUE;
                continue;
            }

            if(isDelete) {
                // Deleting person
                struct person * deleted = hash_table_delete((char *) argv[i]);
                
                if(deleted)
                    // Show person deleted 
                    printf("[ %s deleted (%s is %i years old) ]\n", deleted->name, deleted->sex ? "He" : "She", deleted->age);
                else 
                    // Person not found
                    printf("[ %s not found ]\n", argv[i]);

            } else {
                // Lookup person
                struct person * found = hash_table_lookup((char *) argv[i]);
                
                if(found != NULL) {
                    // Show person found
                    printf("[ %s found ", found->name);
                    printf("(%s is %i years old) ]\n", found->sex ? "He" : "She", found->age);
                } else 
                    // Person not found
                    printf("[ %s not found ]\n", argv[i]);
            }

        }
    }

    print_hash_table();

    return 1;
}
