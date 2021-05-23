#ifndef _STRING_H_
#define _STRING_H_

#include <stdio.h>

#define FALSE  0
#define TRUE   1

// Get argument length
unsigned int length(const char * arg) {
    unsigned int offset = 0;
    unsigned int count = 0;

    while (*(arg + offset) != '\0') {
        ++offset;
        ++count;
    }

    return count;
}

// Check that the values of two string (char *) are equal.
unsigned int equal(const char * data_1, const char * data_2) {
    unsigned int data_1_length = length(data_1);
    unsigned int data_2_length = length(data_2);

    if(data_1_length != data_2_length) return FALSE;

    for(int i = 0; i < data_1_length; i++) {
        if(data_1[i] != data_2[i]) return FALSE;
    }

    return TRUE;
}

// Copy data from the source argument to the target argument
//
// Impotant: destination needs to be declared as "char [n]", because if 
// it is declared as "char *", it will not be possible to modify the data.
// char * is a literal string read-only declaration.
void copy(char * destination, const char * source, size_t size_of_destination) {
    unsigned int source_length = length(source);
    printf("destination %u\n", sizeof(destination));
    printf("source %u\n", sizeof(source));

    if(source_length > size_of_destination) {
        printf("[ insufficient defined memory ]: %u (%s) > %u (%s) - It's dangerous to invade memory \n", source_length, source, size_of_destination, destination);
        return;
    }

    for(int i = 0; i < (source_length + 1); i++) {
        *(destination + i) = source[i];
    }

    *(destination + source_length) = '\0';
}

#endif