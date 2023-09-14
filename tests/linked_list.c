#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

// Define a structure for a doubly-linked list node
typedef struct node {
    int info;
    struct node *next;
    struct node *prev;
} Node;

// Define a structure for the doubly-linked list itself
typedef struct list {
    int size;
    Node* head;
    Node* tail;
} List;

// Function to create an empty doubly-linked list
List* create_list()
{
    List* list = (List*) malloc(sizeof(List));
    assert(list != NULL);
    
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    
    return list;
}

// Function to check if the doubly-linked list is empty
bool is_empty(List* list)
{
    assert(list != NULL);
    
    return list->size == 0; 
}

// Function to insert a new element at a specified position in the list
void insert_at(List* list, int position, int info)
{
    assert(list != NULL);
    assert(position >= 0 && position <= list->size);
    
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->info = info;

    // Determine whether to start the iterator from the tail or head
    bool from_tail = (list->size / 2) < (position + 1);

    if (position == 0) {     
        if (list->size == 0) {
            list->tail = new_node;
        } else {
            list->head->prev = new_node;
        }

        new_node->next = list->head;
        new_node->prev = NULL;
        list->head = new_node;
    }

    else if (position == list->size) {
        new_node->prev = list->tail;
        new_node->next = list->tail->next;
        list->tail->next = new_node;
        list->tail = new_node;
    }
    
    else if (position > 0) {
        if(from_tail) {
            // Iterate from the tail to find the insertion point
            Node* next_node = list->tail;
            int next_position = list->size - position - 1;

            for (int i = 0; i < next_position; i++) {
                next_node = next_node->prev;
            }

            new_node->next = next_node;
            new_node->prev = next_node->prev;
            next_node->prev->next = new_node;
            next_node->prev = new_node;
            
        } else {
            // Iterate from the head to find the insertion point
            Node* prev_node = list->head;
            int prev_position = position - 1;
            
            for (int i = 0; i < prev_position; i++) {          
                prev_node = prev_node->next;
            }

            new_node->next = prev_node->next;
            prev_node->next->prev = new_node;
            new_node->prev = prev_node;
            prev_node->next = new_node;
        }
    }
    
    list->size++;
}

// Function to add a new element at the end of the list
void add(List* list, int info)
{
    assert(list != NULL);
    insert_at(list, list->size, info);
}

// Function to get the node at a specified position in the list
Node* get_at(List* list, int position)
{
    assert(list != NULL);
    assert(position >= 0 && position < list->size);

    Node* node;
    bool from_tail = (list->size / 2) < (position + 1);
    
    if(from_tail) {
        // Iterate from the tail to find the node at the specified position
        node = list->tail;
        for(int i = (list->size - 1); i < position; i--) {
            node = node->prev;
        }
    } else {
        // Iterate from the head to find the node at the specified position
        node = list->head;
        for(int i = 0; i < position; i++) {
            node = node->next;
        }
    }
    
    return node;
}

// Function to remove an element at a specified position from the list
int remove_at(List* list, int position)
{
    assert(list != NULL);
    assert(position >= 0 && position < list->size);
    
    bool from_tail = (list->size / 2) < (position + 1);

    Node* target_node = from_tail ? list->tail : list->head;
    int target_position = from_tail ? (list->size - position - 1) : position;

    for (int i = 0; i < target_position; i++) {
        target_node = from_tail ? target_node->prev : target_node->next;
    }

    if(target_node->next == NULL) {
        list->tail = target_node->prev;
        if(list->tail != NULL) list->tail->next = NULL;
    } else {
        target_node->next->prev = target_node->prev;
    }
    
    if (target_node->prev == NULL) {
        list->head = target_node->next;
        if(list->head != NULL) list->head->prev = NULL;
    } else {
        target_node->prev->next = target_node->next;
    }
    
    int info_removed = target_node->info;
    printf("FREE ADDR: %p\n", (void*) target_node);
    free(target_node);
    list->size--;
    
    return info_removed;
}

// Function to display the elements of the list
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

// Function to destroy the list and free all memory
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
    printf("LINKED LIST\n");
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