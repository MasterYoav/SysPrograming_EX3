#include <stdlib.h>
#include "StrList.h" // Assuming StrList.h contains declarations related to this code
#include <string.h>
#include <stdio.h>

// Define a structure for a node in the linked list
typedef struct _node {
    char* _data;         // Data of the node (a string)
    struct _node* _next; // Pointer to the next node in the list
} Node;

// Define a structure for the string list
struct StrList {
    Node* _head;    // Pointer to the first node in the list
    size_t _size;   // Number of elements in the list
};

// Function to free memory allocated for a node
void Node_free(Node* node) {
    free(node);
}

// Allocate memory for a new string list
StrList* StrList_alloc(){
    StrList* list = (StrList*)malloc(sizeof(StrList));
    list->_head = NULL;
    list->_size = 0;
    return list;
}

// Free memory allocated for the string list and its nodes
void StrList_free(StrList* StrList){
    if (StrList == NULL) return;
    Node* p1 = StrList->_head;
    Node* p2;
    while (p1) { 
        p2 = p1;
        p1 = p1->_next;
        Node_free(p2);
    }
    free(StrList);
}

// Returns the number of elements in the StrList
size_t StrList_size(const StrList* StrList){
    if(StrList == NULL){
        return 0;
    }
    return StrList->_size;
}

// Allocate memory for a new node
Node* Node_alloc(char* data, Node* next) {
    Node* p = (Node*)malloc(sizeof(Node));
    p->_data = data;
    p->_next = next;
    return p;
}

// Inserts an element at the end of the StrList
void StrList_insertLast(StrList* StrList, const char* data){
    if(StrList == NULL){
        // If the list is NULL, create a new list with the provided data
        Node* newNode = Node_alloc(data, NULL);
        StrList* newList = (StrList*)malloc(sizeof(StrList));
        newList->_head = newNode;
        newList->_size = 1;
    } else {
        // Traverse the list to find the last node and insert the new node
        Node* curr = StrList->_head;
        while (curr->_next) {
            curr = curr->_next;
        }
        Node* newNode = Node_alloc(data, NULL);
        curr->_next = newNode;
        StrList->_size++;
    }
}

// Inserts an element at a given index
void StrList_insertAt(StrList* StrList, const char* data, int index){
    if(StrList == NULL || StrList->_size <= index){
        // If the list is NULL or index exceeds the list size, insert at the last position
        StrList_insertLast(NULL, data);
    } else {
        // Traverse the list to find the position and insert the new node
        Node* curr = StrList->_head;
        int counter = 0;
        while(counter < index) {
            curr = curr->_next;
            counter++;
        }
        Node* p = Node_alloc(data, curr->_next);
        curr->_next = p;
        StrList->_size++;
    }
}

// Returns the data of the first node in the StrList
char* StrList_firstData(const StrList* StrList){
    if(StrList == NULL){
        return NULL;
    }
    return StrList->_head;
}

// Prints all elements in the StrList to standard output
void StrList_print(const StrList* StrList){
    if(StrList == NULL) {
        return;
    }
    Node *curr = StrList->_head;
    while(curr){
        printf("%s", curr->_data);
        curr = curr->_next;
    }
}

// Prints the word at the given index to standard output
void StrList_printAt(const StrList* Strlist, int index){
    if(StrList == NULL) {
        return;
    } else {
        Node* curr = StrList->_head;
        int counter = 0;
        while(counter <= index) {
            curr = curr->_next;
        }
        printf("%s", curr->_data);
    }
}

// Returns the total number of characters in the list
int StrList_printLen(const StrList* Strlist){
    if(StrList == NULL) {
        return 0;
    }
    Node *curr = StrList->_head;
    int counter = 0;
    while(curr) {
        counter = counter + strlen(curr->_data);
        curr = curr->_next;
    }
    return counter;
}

// Returns the number of times a given string appears in the list
int StrList_count(StrList* StrList, const char* data){
    if(StrList == NULL) {
        return 0;
    }
    Node *curr = StrList->_head;
    int counter = 0;
    while(curr) {
        if(strcmp(data,curr->_data) == 0) {
            counter++;
        }
        curr = curr->_next;
    }
    return counter;
}

// Removes all occurrences of a given string from the list
void StrList_remove(StrList* StrList, const char* data){
    if(StrList == NULL) {
        return;
    }
    Node* curr = StrList->_head;
    Node* temp;
    while(curr && strcmp(curr->_data, data) == 0) {
        temp = curr;
        StrList->_head = curr->_next;
        curr = curr->_next;
        Node_free(temp);
        StrList->_size--;
    }
    while(curr->_next && strcmp(curr->_next->_data, data) == 0) {
        temp = curr->_next;
        curr->_next = curr->_next->_next;
        Node_free(temp);
        StrList->_size--;
    }
}

// Removes the string at a given index in the list
void StrList_removeAt(StrList* StrList, int index){
    if(StrList == NULL) {
        return;
    }
    if(StrList->_size < index) {
        return;
    }
    Node* curr = StrList->_head;
    if(index == 0) {
        StrList->_head = StrList->_head->_next;
        Node_free(curr);
        StrList->_size--;
        return;
    }
    int counter = 0;
    while(counter < index) {
        curr = curr->_next;
        counter++;
    }
    Node* temp = curr->_next;
    curr->_next = curr->_next->_next;
    Node_free(temp);
    StrList->_size--;
}

// Checks if two StrLists have the same elements
// Returns 0 if not and any other number if yes
int StrList_isEqual(const StrList* StrList1, const StrList* StrList2){
    if(StrList1 == NULL && StrList2 != NULL || StrList1 != NULL && StrList2 == NULL) {
        return 0;
    }
    if(StrList1 == NULL && StrList2 == NULL) {
        return 1;
    }
    if(Str
