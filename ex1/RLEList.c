#include "RLEList.h"

#define FAILED -1
#define NOT_SUCCESS 0
#define CHAR_AND_NEWLINE 2
#define BASE_TEN 10

#include <stdlib.h>
#include <string.h>

/**
 *   UpdateResult: Update result to value
 * @param result - Pointer to be used to store the result of the operation, if it is NULL, the result will not be saved.
 */
static void updateResult(RLEListResult *result, RLEListResult value);

/**
 *   ReverseInt: Reverses the digits of a given positive integer.
 *
 * @param num - The integer needed to reverse.
 * @return - The reversed integer.
 */
static int reverseInt(int num);

/**
 *   NumOfDigits: Returns number of digits in an integer.
 *
 * @param num - The integer
 * @return - The number of digits in num.
 */
static int findNumOfDigits(int num);


typedef struct RLEList_t {
    char letter;
    int count;
    struct RLEList_t *next;
} RLEList_t;

RLEList RLEListCreate()
{
    RLEList list = malloc(sizeof(*list));
    if (!list)
    {
        return NULL;
    }
    list->letter = '\0';
    list->count = 0;
    list->next = NULL;
    return list;
}

void RLEListDestroy(RLEList list)
{
    while (list)
    {
        RLEList to_free = list;
        list = list->next;
        free(to_free);
    }
}

RLEListResult RLEListAppend(RLEList list, char value)
{
    if (!list || !value)
    {
        return RLE_LIST_NULL_ARGUMENT;
    }
    if (list->letter == '\0')
    {
        list->letter = value;
        list->count = 1;
        return RLE_LIST_SUCCESS;
    }
    else
    {
        while (list->next != NULL)
        {
            list = list->next;
        }
        if (list->letter == value)
        {
            list->count++;
            return RLE_LIST_SUCCESS;
        }
        else
        {
            RLEList toAdd = malloc(sizeof(*toAdd));
            if (!toAdd)
            {
                return RLE_LIST_OUT_OF_MEMORY;
            }
            toAdd->letter = value;
            toAdd->count = 1;
            toAdd->next = NULL;
            list->next = toAdd;
            return RLE_LIST_SUCCESS;
        }
    }
}

int RLEListSize(RLEList list)
{
    if (!list)
    {
        return FAILED;
    }
    int size = 0;
    while (list)
    {
        size += list->count;
        list = list->next;
    }
    return size;
}

RLEListResult RLEListRemove(RLEList list, int index)
{
    if (!list)
    {
        return RLE_LIST_NULL_ARGUMENT;
    }
    if (index >= RLEListSize(list) || index < 0)
    {
        return RLE_LIST_INDEX_OUT_OF_BOUNDS;
    }

    if (RLEListSize(list) == 1)
    {
        list->letter = '\0';
        list->count = 0;
        return RLE_LIST_SUCCESS;
    }

    if (index < list->count)
    {
        if (list->count > 1)
        {
            list->count--;
            return RLE_LIST_SUCCESS;
        }
        else
        {
            RLEList toDelete = list->next;
            list->letter = toDelete->letter;
            list->count = toDelete->count;
            list->next = toDelete->next;
            free(toDelete);
            return RLE_LIST_SUCCESS;
        }
    }
    else
    {
        int i = list->count;       
        while (1)
        {
            i += (list->next)->count;
            if (i > index)
            {
                break;
            }
            list = list->next;
        }
        
        RLEList toDelete = list->next;
        
        if (toDelete->count > 1)
        {
            list = toDelete;
            list->count--;
            return RLE_LIST_SUCCESS;
        }
        else
        {
            list->next = toDelete->next;
            free(toDelete);
            if (list->next == NULL)
            {
                return RLE_LIST_SUCCESS;
            }
            RLEList nextNode = list->next;
            if (nextNode->letter == list->letter)
            {
                list->count += nextNode->count;
                list->next = nextNode->next;
                free(nextNode);
            }

            return RLE_LIST_SUCCESS;
        }
    }
}


char RLEListGet(RLEList list, int index, RLEListResult *result)
{
    if (!list)
    {
        updateResult(result , RLE_LIST_NULL_ARGUMENT);
        return NOT_SUCCESS;
    }
    if (index >= RLEListSize(list) || index < 0)
    {
        updateResult(result , RLE_LIST_INDEX_OUT_OF_BOUNDS);
        return NOT_SUCCESS;
    }

    int i = 0;
    while (1)
    {
        i += list->count;
        if (i > index)
        {
            break;
        }
        list = list->next;
    }


    updateResult(result , RLE_LIST_SUCCESS);
    return list->letter;
}



//The string MUST be freed in the external code after end of use! 
char *RLEListExportToString(RLEList list, RLEListResult *result)
{
    if (!list)
    {
        updateResult(result , RLE_LIST_NULL_ARGUMENT);
        return NULL;
    }

    if (list->letter == '\0')
    {
        updateResult(result , RLE_LIST_SUCCESS);
        char *str = malloc(sizeof(*str));
        *str = '\0';
        return str;
    }

    int charAmount = 0;
    RLEList tmp = list;

    while (tmp)
    {
        charAmount += findNumOfDigits(tmp->count) + CHAR_AND_NEWLINE;
        tmp = tmp->next;
    }
    char *str = malloc(sizeof(*str) * charAmount + 1);
    if (!str)
    {
        updateResult(result , RLE_LIST_OUT_OF_MEMORY);
        return NULL;
    }

    int i = 0;
    while (i < charAmount)
    {
        *(str + i++) = list->letter;

        int reversedCount = reverseInt(list->count);
        while (reversedCount)
        {
            *(str + i++) = '0' + reversedCount % BASE_TEN;
            reversedCount /= BASE_TEN;
        }
        reversedCount = reverseInt(list->count);
        for (int j = 0; j < findNumOfDigits(list->count) - findNumOfDigits(reversedCount); j++)
        {
            *(str + i++) = '0';
        }

        *(str + i++) = '\n';
        list = list->next;
    }
    *(str + i) = '\0';

    updateResult(result , RLE_LIST_SUCCESS);
    return str;
}

RLEListResult RLEListMap(RLEList list, MapFunction map_function)
{
    if (!list || !map_function)
    {
        return RLE_LIST_NULL_ARGUMENT;
    }

    int size = RLEListSize(list);
    RLEList newList = RLEListCreate();
    RLEListResult result;
    for (int i = 0; i < size; i++)
    {
        char newLetter = map_function(RLEListGet(list, i, &result));
        RLEListAppend(newList, newLetter);
        if (result != RLE_LIST_SUCCESS)
        {
            return RLE_LIST_ERROR;
        }
    }

    RLEListDestroy(list->next);
    list->letter = newList->letter;
    list->count = newList->count;
    list->next = newList->next;
    free(newList);

    return RLE_LIST_SUCCESS;
}

static void updateResult(RLEListResult *result, RLEListResult value)
{
    if (result)
    {
        *result = value;
    }
}

static int reverseInt(int num)
{
    int reversed = 0;
    while(num != 0){
        reversed = reversed * BASE_TEN + num % BASE_TEN;
        num = num / BASE_TEN;
    }
    return reversed;
}

static int findNumOfDigits(int num)
{
    int numOfDigits = 0;
    while (num)
    {
        numOfDigits++;
        num /= BASE_TEN;
    }
    return numOfDigits;
}

