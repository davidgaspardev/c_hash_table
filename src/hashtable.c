#include "hashtable.h"

const cell_t EMPTY_CELL = {
    .key = {0},
    .data = NULL,
    .next = NULL
};

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

    // Start empty
    for (int i = 0; i < table_size; i++) {
        hashtable->cells[i] = EMPTY_CELL;
    }

#ifdef DEBUG_MODE
    console("calling hash function");
#endif
    return hashtable;
}

void destroy_hashtable(hashtable_t * hashtable) {
#ifdef DEBUG_MODE
    console("destroying hashtable");
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

int8_t hashtable_set(hashtable_t* hashtable, char key[20], void* data, uint8_t data_len) {
    byte_t* data_heap = malloc(sizeof(byte_t) * data_len);
    if(data_heap == NULL) {
        return -1;
    }

    load_data_bytes((byte_t*) data, data_heap, data_len);

    uint8_t index_hash = hash(key, hashtable->size);

    if (hashtable->cells[index_hash].data == NULL) {
#ifdef DEBUG_MODE
        console("Save data in empty indexs");
#endif
        copy(key, hashtable->cells[index_hash].key, 20);
        hashtable->cells[index_hash].data = data_heap;
    } else {
        cell_t* current_cell = hashtable->cells;
        while (true) {
            if (current_cell->next != NULL) {
                current_cell = current_cell->next;
                continue;
            }

            copy(key, current_cell->key, 20);
            current_cell->data = data_heap;
            current_cell->next = NULL;
        }
    }

    return 0;
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
        printf("[ %d ] ", i);
        if(hashtable->cells[i].data == NULL) {
            printf("--- EMPTY ---");
        } else {
            printf("address: %p", hashtable->cells[i].data);
        }
        printf("\n");
    }
#endif
}

static void load_data_bytes(byte_t* src, byte_t* dst, uint8_t size) {
    printf("size: %d\n", size);
    for(int i = 0; i < size; i++) {
        dst[i] = src[i];
#ifdef DEBUG_MODE
        printf("%d,", src[i]);
#endif
    }
#ifdef DEBUG_MODE
    printf("\n");
#endif
}

// void show_hashtable(hashtable_t * hashtable) {
//     uint32_t cell_number = length(hashtable->cells);

//     for (int i = 0; i < cell_number; i++) {
        
//     }
// }