#include <stdio.h>
#include "StrList.h"
#include <string.h>

#define maxLength 501

int main()
{
    int option;
    StrList *list = StrList_alloc();
    int index;
    char str[maxLength];
    if (scanf("%d", &option) == EOF)
    {
        StrList_free(list);
        return 0;
    }
    while (option != 0)
    {
        switch (option)
        {
        case 1:
            int wordCount = 0;
            scanf("%d", &wordCount);
            int wordIndex = 0;
            while (wordIndex < wordCount)
            {
                scanf("%s", str);
                char *newWord = (char*)malloc(strlen(str) + 1);
                if (newWord == NULL)
                {
                    return 0;
                }
                strcpy(newWord, str);
                StrList_insertLast(list, newWord);
                wordIndex++;
            }
            break;

        case 2:
            scanf("%d", &index);
            scanf("%s", str);
            char *insertedWord = (char *)malloc(strlen(str) + 1);
            if (insertedWord == NULL)
            {
                break;
            }
            strcpy(insertedWord, str);
            StrList_insertAt(list, insertedWord, index);
            break;

        case 3:
            StrList_print(list);
            break;

        case 4:
            printf("%ld\n", StrList_size(list));
            break;

        case 5:
            scanf("%d", &index);
            StrList_printAt(list, index);
            break;

        case 6:
            printf("%d\n", StrList_printLen(list));
            break;

        case 7:
            scanf("%s", str);
            char *countedWord = (char *)malloc(strlen(str) + 1);
            if (countedWord == NULL)
            {
                break;
            }
            strcpy(countedWord, str);
            printf("%d\n", StrList_count(list, countedWord));
            free(countedWord);
            break;

        case 8:
            scanf("%s", str);
            char *removedWord = (char *)malloc(strlen(str) + 1);
            if (removedWord == NULL)
            {
                break;
            }
            strcpy(removedWord, str);
            StrList_remove(list, removedWord);
            free(removedWord);
            break;

        case 9:
            scanf("%d", &index);
            StrList_removeAt(list, index);
            break;

        case 10:
            StrList_reverse(list);
            break;

        case 11:
            StrList_free(list);
            break;

        case 12:
            StrList_sort(list);
            break;

        case 13:
            printf("%d\n", StrList_isSorted(list));
            break;
        }
        if (scanf("%d", &option) == EOF)
        {
            StrList_free(list);
            return 0;
        }
    }
    StrList_free(list);
    return 0;
}
