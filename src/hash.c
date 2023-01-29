#include "hash.h"

#ifdef DEBUG_MODE
static void console(char * msg) {
    printf("[ DEBUG ] %s\n", msg);
}
#endif

// Hash function that takes a string as an input and returns an index between 0 and max_size
unsigned int hash(const char* key, unsigned int max_size) {
#ifdef DEBUG_MODE
    char msg[50];
    sprintf("create hash index - key: %s (max size: %d)", key, max_size);
    console(msg);
#endif
    unsigned int hash = 0;
    unsigned int i;

    for (i = 0; i < strlen(key); i++) {
        hash = hash * 31 + key[i];
    }

    return hash % max_size;
}