#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef struct node {
    int info;
    struct node *next;
} Node;

typedef struct list {
    int size;
    Node* root;
} List;

List* create_list()
{
    List* list = (List*) malloc(sizeof(List));
    assert(list != NULL);
    
    list->root = NULL;
    list->size = 0;
    
    return list;
}

bool is_empty(List* list)
{
    assert(list != NULL);
    
    return list->size == 0; 
}

void insert_at(List* list, int position, int info)
{
    assert(list != NULL);
    assert(position >= 0 && position <= list->size);
    
    Node* new_row = (Node*) malloc(sizeof(Node));
    new_row->info = info;
    
    if (position == 0) {
        new_row->next = list->root;
        list->root = new_row;
    }
    
    if (position > 0) {
        Node* prev_row = list->root;
        int prev_position = position - 1;
        
        for (int i = 0; i < prev_position; i++) {          
            prev_row = prev_row->next;
        }
        
        new_row->next = prev_row->next;
        prev_row->next = new_row;
    }
    
    list->size++;
}

void add(List* list, int info)
{
    assert(list != NULL);
    insert_at(list, list->size, info);
}

Node* get_at(List* list, int position)
{
    assert(list != NULL);
    assert(position >= 0 && position < list->size);
    
    Node* row = list->root;
    for(int i = 0; i < position; i++) {
        row = row->next;
    }
    
    return row;
}

int remove_at(List* list, int position)
{
    assert(list != NULL);
    assert(position >= 0 && position < list->size);
    
    Node* prev_row = NULL;
    Node* target_row = list->root;
    
    for (int i = 0; i < position; i++) {
        prev_row = target_row;
        target_row = target_row->next;
    }
    
    if (prev_row == NULL) {
        list->root = target_row->next;
    } else {
        prev_row->next = target_row->next;
    }
    
    int info_removed = target_row->info;
    printf("FREE ADDR: %p\n", (void*) target_row);
    free(target_row);
    list->size--;
    
    return info_removed;
}

void show_list(List* list)
{
    assert(list != NULL);
    
    if (list->root == NULL) {
        printf("LIST IS EMPTY\n");
        return;
    }
    
    Node* current_row = list->root;
    
    printf("LIST WITH %d ELEMENTS\n", list->size);
    do {
        printf("INFO: %d (ADDR: %p)\n", current_row->info, (void*) current_row);
        
        current_row = current_row->next;
    } while(current_row != NULL);
}

void destroy(List* list)
{
    assert(list != NULL);
    
    while(is_empty(list) == false) {
        remove_at(list, 0);
    }
    
    free(list);
    list = NULL;
}

int main()
{
    List* list = create_list();    

    insert_at(list, 0, 5);
    insert_at(list, 0, 3);
    insert_at(list, 2, 6);
    insert_at(list, 1, 0);
    insert_at(list, 4, 7);
    insert_at(list, 1, 2);
    insert_at(list, 5, 6);
    insert_at(list, 3, 4);
    
    add(list, 8);
    add(list, 16);
    add(list, 17);
    add(list, 18);
    add(list, 19);
    
    show_list(list);
    
    remove_at(list, 1);
    remove_at(list, 3);
    remove_at(list, 9);
    remove_at(list, 8);
    
    show_list(list);
    
    destroy(list);
    
    return 0;
}