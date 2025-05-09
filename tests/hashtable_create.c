#include "../src/hashtable.h"
#include <stdio.h>

#pragma pack(1) // Disable padding
typedef struct _Person {
    char name[50];
    int age;
    float height;
    float weight;
} Person;
#pragma pack() // Enable padding

void insert_data(hashtable_t *hashtable) {
    Person you = {
        .name = "David Gaspar",
        .age = 26,
        .height = 1.85,
        .weight = 75.0
    };

    Person girlfriend = {
        .name = "Heloisa Kirchner Feldhaus",
        .age = 27,
        .height = 1.68,
        .weight = 60.0
    };

    uint8_t person_len = sizeof(Person);

    hashtable_set(hashtable, you.name, (void *) &you, person_len);
    hashtable_set(hashtable, girlfriend.name, (void *) &girlfriend, person_len);
}

int main() {
    hashtable_t * hashtable = create_hashtable(75);

    insert_data(hashtable);

    hashtable_print(hashtable);

    Person * person = (Person *) hashtable_get(hashtable, "David Gaspar");
    if (person != NULL) {
        printf("Person found: %s - %d - %.2f - %.2f\n", person->name, person->age, person->height, person->weight);
    } else {
        printf("Not found\n");
    }

    destroy_hashtable(hashtable);
    
    return 0;
}