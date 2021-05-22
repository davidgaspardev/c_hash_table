#ifndef _STRING_H_
#define _STRING_H_

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

void copy(char * destination, const char * source) {
    unsigned int destination_length = length(destination);
    unsigned int source_length = length(source);

    if(destination_length > source_length) {
        return;
    }

    for(int i = 0; i < (source_length + 1); i++) {
        if(i == source_length) {
            destination[i] = '\0';
        } else {
            destination[i] = source[i];
        }
    }
}

#endif