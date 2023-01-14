#include "../src/hashtable.h"

int main() {
    hashtable_t * hashtable = create_hashtable(10);

    destroy_hashtable(hashtable);
    
    return 0;
}