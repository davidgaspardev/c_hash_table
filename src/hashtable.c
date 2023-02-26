#include "hashtable.h"

#ifdef DEBUG_MODE
static void console(char * msg) {
    printf("[ DEBUG ] %s\n", msg);
}
#endif

hashtable_t * create_hashtable(uint_t table_size) {
#ifdef DEBUG_MODE
    console("creating hashtable");
#endif
    hashtable_t * hashtable = (hashtable_t*) malloc(sizeof(hashtable_t));

    hashtable->cells = (cell_t *) malloc(sizeof(cell_t) * table_size);
    hashtable->size = table_size;

#ifdef DEBUG_MODE
    console("calling hash function");
#endif
    hash("test", 100);

    return hashtable;
}

void destroy_hashtable(hashtable_t * hashtable) {
#ifdef DEBUG_MODE
    console("detroing hashtable");
#endif
    free(hashtable->cells);
    free(hashtable);
}

int8_t hashtable_insert(hashtable_t * hashtable, cell_t cell) {
#ifdef DEBUG_MODE
    console("inserting in hashtable");
#endif
    hashtable->cells[0] = cell;

    hash("test", 100);

    return 1;
}

void show_hashtable(hashtable_t * hashtable) {

}