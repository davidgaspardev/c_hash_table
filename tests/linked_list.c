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
    Node* head;
} List;

List* create_list()
{
    List* list = (List*) malloc(sizeof(List));
    assert(list != NULL);
    
    list->head = NULL;
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
    
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->info = info;
    
    if (position == 0) {
        new_node->next = list->head;
        list->head = new_node;
    }
    
    if (position > 0) {
        Node* prev_node = list->head;
        int prev_position = position - 1;
        
        for (int i = 0; i < prev_position; i++) {          
            prev_node = prev_node->next;
        }
        
        new_node->next = prev_node->next;
        prev_node->next = new_node;
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
    
    Node* node = list->head;
    for(int i = 0; i < position; i++) {
        node = node->next;
    }
    
    return node;
}

int remove_at(List* list, int position)
{
    assert(list != NULL);
    assert(position >= 0 && position < list->size);
    
    Node* prev_node = NULL;
    Node* target_node = list->head;
    
    for (int i = 0; i < position; i++) {
        prev_node = target_node;
        target_node = target_node->next;
    }
    
    if (prev_node == NULL) {
        list->head = target_node->next;
    } else {
        prev_node->next = target_node->next;
    }
    
    int info_removed = target_node->info;
    printf("FREE ADDR: %p\n", (void*) target_node);
    free(target_node);
    list->size--;
    
    return info_removed;
}

void show_list(List* list)
{
    assert(list != NULL);
    
    if (list->head == NULL) {
        printf("LIST IS EMPTY\n");
        return;
    }
    
    Node* current_node = list->head;
    
    printf("LIST WITH %d ELEMENTS\n", list->size);
    do {
        printf("INFO: %d (ADDR: %p)\n", current_node->info, (void*) current_node);
        
        current_node = current_node->next;
    } while(current_node != NULL);
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