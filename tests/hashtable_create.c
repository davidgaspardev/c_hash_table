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

    Person friend1 = {
        .name = "John Doe",
        .age = 30,
        .height = 1.80,
        .weight = 80.0
    };

    Person friend2 = {
        .name = "Jane Smith",
        .age = 25,
        .height = 1.70,
        .weight = 65.0
    };

    Person friend3 = {
        .name = "Alice Johnson",
        .age = 28,
        .height = 1.75,
        .weight = 68.0
    };

    Person friend4 = {
        .name = "Bob Brown",
        .age = 32,
        .height = 1.82,
        .weight = 85.0
    };

    Person friend5 = {
        .name = "Charlie Davis",
        .age = 29,
        .height = 1.78,
        .weight = 72.0
    };

    Person friend6 = {
        .name = "Diana Evans",
        .age = 24,
        .height = 1.65,
        .weight = 55.0
    };

    Person friend7 = {
        .name = "Ethan Harris",
        .age = 35,
        .height = 1.90,
        .weight = 90.0
    };

    Person friend8 = {
        .name = "Fiona Green",
        .age = 31,
        .height = 1.68,
        .weight = 62.0
    };

    Person friend9 = {
        .name = "George Hill",
        .age = 27,
        .height = 1.76,
        .weight = 70.0
    };

    Person friend10 = {
        .name = "Hannah Scott",
        .age = 26,
        .height = 1.72,
        .weight = 64.0
    };

    Person friend11 = {
        .name = "Ian Clark",
        .age = 33,
        .height = 1.85,
        .weight = 78.0
    };

    Person friend12 = {
        .name = "Julia Adams",
        .age = 29,
        .height = 1.67,
        .weight = 58.0
    };

    Person friend13 = {
        .name = "Kevin Lewis",
        .age = 34,
        .height = 1.88,
        .weight = 82.0
    };

    Person friend14 = {
        .name = "Laura Walker",
        .age = 28,
        .height = 1.66,
        .weight = 59.0
    };

    Person friend15 = {
        .name = "Michael Young",
        .age = 36,
        .height = 1.92,
        .weight = 95.0
    };

    Person friend16 = {
        .name = "Natalie King",
        .age = 30,
        .height = 1.70,
        .weight = 63.0
    };

    Person friend17 = {
        .name = "Oliver Wright",
        .age = 25,
        .height = 1.74,
        .weight = 68.0
    };

    Person friend18 = {
        .name = "Paula Martinez",
        .age = 27,
        .height = 1.69,
        .weight = 61.0
    };

    Person friend19 = {
        .name = "Quentin Lopez",
        .age = 31,
        .height = 1.81,
        .weight = 77.0
    };

    Person friend20 = {
        .name = "Rachel Perez",
        .age = 26,
        .height = 1.64,
        .weight = 56.0
    };

    Person friend21 = {
        .name = "Samuel Turner",
        .age = 29,
        .height = 1.79,
        .weight = 73.0
    };

    Person friend22 = {
        .name = "Tina Collins",
        .age = 28,
        .height = 1.71,
        .weight = 60.0
    };

    Person friend23 = {
        .name = "Ursula Baker",
        .age = 32,
        .height = 1.68,
        .weight = 65.0
    };

    Person friend24 = {
        .name = "Victor Carter",
        .age = 35,
        .height = 1.86,
        .weight = 88.0
    };

    Person friend25 = {
        .name = "Wendy Mitchell",
        .age = 30,
        .height = 1.73,
        .weight = 66.0
    };

    Person friend26 = {
        .name = "Xavier Rivera",
        .age = 27,
        .height = 1.80,
        .weight = 75.0
    };

    Person friend27 = {
        .name = "Yvonne Reed",
        .age = 29,
        .height = 1.69,
        .weight = 62.0
    };

    Person friend28 = {
        .name = "Zachary Howard",
        .age = 33,
        .height = 1.84,
        .weight = 83.0
    };

    Person friend29 = {
        .name = "Angela Brooks",
        .age = 25,
        .height = 1.62,
        .weight = 54.0
    };

    Person friend30 = {
        .name = "Brian Foster",
        .age = 28,
        .height = 1.77,
        .weight = 71.0
    };

    Person friend31 = {
        .name = "Catherine Simmons",
        .age = 34,
        .height = 1.65,
        .weight = 57.0
    };

    Person friend32 = {
        .name = "Daniel Morris",
        .age = 36,
        .height = 1.89,
        .weight = 92.0
    };

    uint8_t person_len = sizeof(Person);

    hashtable_set(hashtable, you.name, (void *) &you, person_len);
    hashtable_set(hashtable, girlfriend.name, (void *) &girlfriend, person_len);
    hashtable_set(hashtable, friend1.name, (void *) &friend1, person_len);
    hashtable_set(hashtable, friend2.name, (void *) &friend2, person_len);
    hashtable_set(hashtable, friend3.name, (void *) &friend3, person_len);
    hashtable_set(hashtable, friend4.name, (void *) &friend4, person_len);
    hashtable_set(hashtable, friend5.name, (void *) &friend5, person_len);
    hashtable_set(hashtable, friend6.name, (void *) &friend6, person_len);
    hashtable_set(hashtable, friend7.name, (void *) &friend7, person_len);
    hashtable_set(hashtable, friend8.name, (void *) &friend8, person_len);
    hashtable_set(hashtable, friend9.name, (void *) &friend9, person_len);
    hashtable_set(hashtable, friend10.name, (void *) &friend10, person_len);
    hashtable_set(hashtable, friend11.name, (void *) &friend11, person_len);
    hashtable_set(hashtable, friend12.name, (void *) &friend12, person_len);
    hashtable_set(hashtable, friend13.name, (void *) &friend13, person_len);
    hashtable_set(hashtable, friend14.name, (void *) &friend14, person_len);
    hashtable_set(hashtable, friend15.name, (void *) &friend15, person_len);
    hashtable_set(hashtable, friend16.name, (void *) &friend16, person_len);
    hashtable_set(hashtable, friend17.name, (void *) &friend17, person_len);
    hashtable_set(hashtable, friend18.name, (void *) &friend18, person_len);
    hashtable_set(hashtable, friend19.name, (void *) &friend19, person_len);
    hashtable_set(hashtable, friend20.name, (void *) &friend20, person_len);
    hashtable_set(hashtable, friend21.name, (void *) &friend21, person_len);
    hashtable_set(hashtable, friend22.name, (void *) &friend22, person_len);
    hashtable_set(hashtable, friend23.name, (void *) &friend23, person_len);
    hashtable_set(hashtable, friend24.name, (void *) &friend24, person_len);
    hashtable_set(hashtable, friend25.name, (void *) &friend25, person_len);
    hashtable_set(hashtable, friend26.name, (void *) &friend26, person_len);
    hashtable_set(hashtable, friend27.name, (void *) &friend27, person_len);
    hashtable_set(hashtable, friend28.name, (void *) &friend28, person_len);
    hashtable_set(hashtable, friend29.name, (void *) &friend29, person_len);
    hashtable_set(hashtable, friend30.name, (void *) &friend30, person_len);
    hashtable_set(hashtable, friend31.name, (void *) &friend31, person_len);
    hashtable_set(hashtable, friend32.name, (void *) &friend32, person_len);
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