#include "hashtable.h"

const cell_t EMPTY_CELL = {
    .key = {0},
    .data = NULL,
    .next = NULL
};

#ifdef DEBUG_MODE
static char msg[255];
static void console(char * msg) {
    printf("[ DEBUG ] %s\n", msg);
}
#endif

hashtable_t* create_hashtable(uint_t table_size) {
    return create_hashtable_with_entry_size(table_size, 0);
}

hashtable_t* create_hashtable_with_entry_size(uint_t table_size, uint_t entry_size) {
#ifdef DEBUG_MODE
    sprintf(msg, "Creating hashtable with sizes: %d (table) %d (entry)", table_size, entry_size);
    console(msg);
#endif
    hashtable_t * hashtable = (hashtable_t*) malloc(sizeof(hashtable_t));

    hashtable->cells = (cell_t *) malloc(sizeof(cell_t) * table_size);
    hashtable->size = table_size;
    hashtable->entry_size = entry_size;

    // Start empty
    for (int i = 0; i < table_size; i++) {
        hashtable->cells[i] = EMPTY_CELL;
    }

#ifdef DEBUG_MODE
    console("Calling hash function");
#endif
    return hashtable;
}

void destroy_hashtable(hashtable_t * hashtable) {
#ifdef DEBUG_MODE
    console("Destroying hashtable");
#endif
    free(hashtable->cells);
    free(hashtable);
}

int8_t hashtable_insert(hashtable_t * hashtable, cell_t cell) {
#ifdef DEBUG_MODE
    console("Inserting in hashtable");
#endif
    hashtable->cells[0] = cell;

    hash("test", 100);

    return 1;
}

int8_t hashtable_set(hashtable_t* hashtable, char key[20], void* data) {
    uint8_t index_hash = hash(key, hashtable->size);

    if (hashtable->cells[index_hash].data == EMPTY_CELL.data) {
#ifdef DEBUG_MODE
        sprintf(msg, "Save data (key: %s) in empty index: %d", key, index_hash);
        console(msg);
#endif
        copy(key, hashtable->cells[index_hash].key, 20);
        hashtable->cells[index_hash].data = data;
    } else {
#ifdef DEBUG_MODE
        sprintf(msg, "Collision detected for key: %s (index: %d), adding to linked list\n", key, index_hash);
        console(msg);
#endif
        cell_t* current_cell = &hashtable->cells[index_hash];
        while(current_cell->next != EMPTY_CELL.next) {
            current_cell = current_cell->next;
        }

        current_cell->next = (cell_t*) malloc(sizeof(cell_t));

        copy(key, ((cell_t*)current_cell->next)->key, 20);
        ((cell_t*)current_cell->next)->data = data;
        ((cell_t*)current_cell->next)->next = EMPTY_CELL.next;
    }

    return 0;
}

int8_t hashtable_set_copy(hashtable_t* hashtable, char key[20], void* data) {
    if (hashtable->entry_size < 1) {
        return -1;
    }
    return hashtable_set_copy_custom(hashtable, key, data, hashtable->entry_size);
}

int8_t hashtable_set_copy_custom(hashtable_t* hashtable, char key[20], void* data, uint8_t data_len) {
    byte_t* data_heap = malloc(sizeof(byte_t) * data_len);
    if(data_heap == NULL) {
        return -1;
    }

    load_data_bytes((byte_t*) data, data_heap, data_len);

    return hashtable_set(hashtable, key, data_heap);
}

void* hashtable_get(hashtable_t* hashtable, char key[20]) {
    uint8_t index_hash = hash(key, hashtable->size);

    if (hashtable->cells[index_hash].data != NULL) {
        if (equal(hashtable->cells[index_hash].key, key)) {
            return hashtable->cells[index_hash].data;
        }
    }

    return NULL;
}

void hashtable_print(hashtable_t* hashtable) {
    printf("hashtable size: %d\n", hashtable->size);
#ifdef DEBUG_MODE
    for(int i = 0; i < hashtable->size; i++) {
        printf("[ %02d ] ", i);
        if(hashtable->cells[i].data == NULL) {
            printf("--- EMPTY ---");
        } else {
            printf("%s", hashtable->cells[i].key);
            cell_t* current_cell = hashtable->cells[i].next;
            while (current_cell != NULL) {
                printf(" -> %s", current_cell->key);
                current_cell = current_cell->next;
            }
        }
        printf("\n");
    }
#endif
}

static void load_data_bytes(byte_t* src, byte_t* dst, uint8_t size) {
    for(int i = 0; i < size; i++) {
        dst[i] = src[i];
    }
}
