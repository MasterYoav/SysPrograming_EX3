#include "StrList.h"
#include <string.h>
#include <stdio.h>

void Node_free(Node* node) {
    free(node);
}

StrList* StrList_alloc(){
    StrList* list = (StrList*)malloc(sizeof(StrList));
    list->_head = NULL;
    list->_size = 0;
    return list;
}

void StrList_free(StrList* StrList){
    if (StrList==NULL) return;
    Node* current = StrList->_head;
    Node* temp;
    while(current) { 
        temp = current;
        free(current->_data);
        current = current->_next;
        Node_free(temp);
    }
    free(StrList);
}

/*
 * Returns the number of elements in the StrList.
 */
size_t StrList_size(const StrList* StrList){
    if(StrList == NULL){
        return 0;
    }
    return StrList->_size;
}

Node* Node_alloc(const char* data, Node* next) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->_data = (char*)data;
    newNode->_next = next;
    return newNode;
}

/*
 * Inserts an element in the end of the StrList.
 */
void StrList_insertLast(StrList* StrList, const char* data){
    if(StrList == NULL){
        StrList = StrList_alloc();
        Node* newNode = Node_alloc(data, NULL);
        StrList->_head = newNode;
        StrList->_size = 1;
    }else{
        if(StrList->_size == 0){
            Node* newNode = Node_alloc(data, NULL);
            StrList->_head = newNode;
            StrList->_size = 1;
        }else{
            Node* current = StrList->_head;
            while (current->_next)
            {
                current = current->_next;
            }
            Node* newNode = Node_alloc(data, NULL);
            current->_next = newNode;
            StrList->_size++;
        }
    }
}

/*
* Inserts an element at given index
*/
void StrList_insertAt(StrList* StrList, const char* data, int index){
    if(StrList == NULL || StrList->_size <= index){
        StrList_insertLast(NULL, data);
    }else{
        Node* current = StrList->_head;
        int counter = 0;
        while(counter < index){
            current = current->_next;
            counter++;
        }
        Node* newNode = Node_alloc(data, current->_next);
        current->_next = newNode;
        StrList->_size++;
    }
}

/*
 * Returns the StrList first data.
 */
char* StrList_firstData(const StrList* StrList){
    if(StrList == NULL || StrList->_size == 0){
        return NULL;
    }
    return StrList->_head->_data;
}

/*
 * Prints the StrList to the standard output.
 */
void StrList_print(const StrList* StrList){
    if(StrList == NULL || StrList->_size == 0){return;}
    Node* current = StrList->_head;
    printf("%s", current->_data);
    current = current->_next;
    while(current){
        printf(" %s", current->_data);
        current = current->_next;
    }
    printf("\n");
}

/*
 Prints the word at the given index to the standard output.
*/
void StrList_printAt(const StrList* Strlist,int index){
    if(Strlist == NULL || Strlist->_size == 0){
        return;
    }else{
        Node* current = Strlist->_head;
        int counter = 0;
        while(counter <= index){
            current = current->_next;
            counter++;
        }
        printf("%s\n", current->_data);
    }
}

/*
 * Return the amount of chars in the list.
*/
int StrList_printLen(const StrList* Strlist){
    if(Strlist == NULL || Strlist->_size == 0){return 0;}
    Node* current = Strlist->_head;
    int counter = 0;
    while(current){
        counter = counter + strlen(current->_data);
        current = current->_next;
    }
    return counter;
}

/*
Given a string, return the number of times it exists in the list.
*/
int StrList_count(StrList* StrList, const char* data){
    if(StrList == NULL || StrList->_size == 0){return 0;}
    Node* current = StrList->_head;
    int counter = 0;
    while(current){
        if(strcmp(data, current->_data) == 0){
            counter++;
        }
        current = current->_next;
    }
    return counter;
}

/*
	Given a string and a list, remove all the appearances of this string in the list.
*/
void StrList_remove(StrList* StrList, const char* data){
    if(StrList == NULL || StrList->_size == 0){
        return;
    }
    Node* current = StrList->_head;
    Node* temp;
    while(current && strcmp(current->_data, data) == 0){
        temp = current;
        StrList->_head = current->_next;
        current = current->_next;
        free(temp->_data);
        Node_free(temp);
        StrList->_size--;
    }
    while(current->_next && strcmp(current->_next->_data, data) == 0)
    {
        temp = current->_next;
        current->_next = current->_next->_next;
        free(temp->_data);
        Node_free(temp);
        StrList->_size--;
    }
}

/*
	Given an index and a list, remove the string at that index.
*/
void StrList_removeAt(StrList* StrList, int index){
    if(StrList == NULL || StrList->_size == 0){return;}
    if(StrList->_size < index){return;}

    Node* current = StrList->_head;
    if(index == 0){
        StrList->_head = StrList->_head->_next;
        free(current->_data);
        Node_free(current);
        StrList->_size--;
        return;
    }
    int counter = 0;
    while(counter < index)
    {
        current  = current->_next;
        counter++;
    }
    Node* tempNode = current->_next;
    current->_next = current->_next->_next;
    free(tempNode->_data);
    Node_free(tempNode);
    StrList->_size--;
}

/*
 * Checks if two StrLists have the same elements
 * returns 0 if not and any other number if yes
 */
int StrList_isEqual(const StrList* StrList1, const StrList* StrList2){
    if((StrList1 == NULL && StrList2 != NULL) || (StrList1 != NULL && StrList2 == NULL) ||
     (StrList1->_size == 0 && StrList2->_size != 0) || (StrList2->_size == 0 && StrList1->_size != 0)){return 0;}
    if((StrList1 == NULL && StrList2 == NULL) || (StrList2->_size == 0 && StrList1->_size == 0)){return 1;}
    if(StrList1->_size != StrList2->_size){return 0;}
    Node* curr1 = StrList1->_head;
    Node* curr2 = StrList2->_head;
    for (size_t i = 0; i < StrList1->_size; i++)
    {
        if(strcmp(curr1->_data, curr2->_data) != 0){
            return 0;
        }
        curr1 = curr1->_next;
        curr2 = curr2->_next;
    }
    return 1;
    
}

/*
 * Clones the given StrList. 
 * It's the user responsibility to free it with StrList_free.
 */
StrList* StrList_clone(const StrList* Strlist){
    if(Strlist == NULL){return NULL;}
    if(Strlist->_size == 0){
        StrList* newList = StrList_alloc();
        return newList;
    }
    StrList* cloneList = StrList_alloc();
    Node* current = Strlist->_head;
    for (size_t i = 0; i < Strlist->_size; i++)
    {
        char* cloneData = (char*)malloc(strlen(current->_data) + 1);
        StrList_insertLast(cloneList, strcpy(cloneData, current->_data));
        current = current->_next;
        free(cloneData);
    }
    cloneList->_size = Strlist->_size;
    return cloneList;
    
}

/*
 * Reverses the given StrList. 
 */
void StrList_reverse( StrList* Strlist){
    if(Strlist == NULL || Strlist->_size == 0){return;}
    int size = Strlist->_size - 1; 
    StrList* newList = StrList_clone(Strlist); 
    Node* current = Strlist->_head;
    for (size_t i = 0; i < Strlist->_size; i++)
    {
        char* cloneData = (char*)malloc(strlen(current->_data) + 1);
        StrList_insertAt(Strlist, strcpy(cloneData, current->_data), size);
        current = current->_next;
        free(cloneData);
        size--;
    }
    StrList_free(newList);
    
}

/*
 * Sorts the given list in lexicographical order 
 */
void StrList_sort( StrList* Strlist){
    if(Strlist == NULL || Strlist->_size == 0){return ;}
    if(Strlist->_size <= 1){return;}
    StrList* newList = StrList_clone(Strlist);
    Node* current = Strlist->_head;
    Node* minNode = Strlist->_head;
    StrList_free(Strlist);
    while (newList->_size > 0)
    {
        int j = 0;
        minNode = newList->_head;
        current = newList->_head;
        for (int i = 0; i < newList->_size; i++)
        {
            if(strcmp(current->_data, minNode->_data) < 0){
                minNode = current;
                j = i;
            }
            current = current->_next;
        }
        char* cloneData = (char*)malloc(strlen(minNode->_data) + 1);
        StrList_insertLast(Strlist, strcpy(cloneData, minNode->_data));
        free(cloneData);
        StrList_removeAt(newList, j);
    }
    
}

/*
 * Checks if the given list is sorted in lexicographical order
 * returns 1 for sorted,   0 otherwise
 */
int StrList_isSorted(StrList* Strlist){
    if(Strlist == NULL || Strlist->_size == 0){return 1;}
    int ans = 0;
    StrList* newList = StrList_clone(Strlist);
    StrList_sort(newList);
    ans = StrList_isEqual(newList, Strlist);
    StrList_free(newList);
    if(ans == 0){return 0;}
    return 1;
}
