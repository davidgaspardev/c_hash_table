#include "hashtable.h"

hashtable_t * create_hashtable(uint_t table_size) {
#ifdef DEBUG_MODE
    printf("creating hashtable");
#endif
    hashtable_t * hashtable = (hashtable_t*) malloc(sizeof(hashtable_t));

    hashtable->cells = (cell_t *) malloc(sizeof(cell_t) * table_size);
    hashtable->size = table_size;

    return hashtable;
}

void destroy_hashtable(hashtable_t * hashtable) {
#ifdef DEBUG_MODE
    printf("detroing hashtable");
#endif
    free(hashtable->cells);
    free(hashtable);
}

int8_t hashtable_insert(hashtable_t * hashtable, cell_t cell) {
    hashtable->cells[0] = cell;

    return 1;
}

void show_hashtable(hashtable_t * hashtable) {

}