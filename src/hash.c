#include "hash.h"

#ifdef DEBUG_MODE
static char msg[255];
static void console(char * msg) {
    printf("[ DEBUG ] %s\n", msg);
}
#endif

byte_t is_int_even(int integer) {
    return (integer % 2) == 0;
}

// Hash function that takes a inputing as an input and returns an index between 0 and max_size
unsigned int hash(const char* key, unsigned int max_size) {
#ifdef DEBUG_MODE
        sprintf(msg, "create hash index - key: %s (max size: %d)", key, max_size);
        console(msg);
#endif
    unsigned long hash;

    if (is_int_even(length(key))) {
        hash = knuth_hash(key);
    } else {
        hash = djb2_hash(key);
    }

    unsigned int result = (hash % max_size);
#ifdef DEBUG_MODE
    if (is_int_even(length(key))) {
        sprintf(msg, "hash created using knuth: %d (raw: %lu)", result, hash);
        console(msg);
    } else {
        sprintf(msg, "hash created using djb2: %d (raw: %lu)", result, hash);
        console(msg);
    }
#endif
    return result;
}

static hash_t knuth_hash(const char* input) {
    hash_t hash = 0;
    int c;
    while ((c = *input++)) {
        hash = ((hash << 5) ^ (hash >> 27)) ^ c;
    }
    return hash;
}

static hash_t djb2_hash(const char* input) {
    hash_t hash = 5381;
    int c;
    while ((c = *input++)) {
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    }
    return hash;
}