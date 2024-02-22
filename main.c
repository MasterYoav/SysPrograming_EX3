#include <stdio.h>
#include "StrList.h"
#include <string.h>
#define maxLength 101
int main(){
    int option;
    StrList* list = StrList_alloc();
    char* str[maxLength];
    int index;
    if(scanf("%d", &option) == EOF){
        StrList_free(list);
        return 0;
    }
    while(option != 0){
        switch (option)
        {
            case 1: //needs to check what data will be, and if dynamic should we add free the data in the StrList.c ?
                int sizeOfWords = 0;
                scanf("%d", &sizeOfWords);

                for (size_t i = 0; i < sizeOfWords; i++)
                {
                    scanf("%s", str);
                    char* word[] = (char*)malloc(strlen(str) + 1);
                    strcpy(word, str);
                }

                break;

            case 2:
                break;

            case 3:

                StrList_print();
                break;

            case 4:
                printf("%d", StrList_size());
                break;

            case 5:
                scanf("%d", &index);
                StrList_printAt(list, index);
                break;

            case 6:
                printf("%d", StrList_printLen());
                break;

            case 7:
                break;

            case 8:
                break;

            case 9:
                scanf("%d", &index);
                StrList_removeAt(List, index);
                break;

            case 10:
                StrList_reverse(List);
                break;

            case 11:
                StrList_free();
                break;

            case 12:
                StrList_sort(StrList);
                break;

            case 13:
                printf("%d", StrList_isSorted(List));
                break;

        }
    }
    StrList_free(list);
    return 0;
}
