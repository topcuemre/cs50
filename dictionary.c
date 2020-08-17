// Implements a dictionary's functionality
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "dictionary.h"
#include <stdlib.h>
#include <stdio.h>

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 676;
unsigned int wcntr = 0;
bool load_check = false;

// Hash table
node *table[N];

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    char check_word[strlen(word)];
    strcpy(check_word, word);
    for (int i = 0; check_word[i] != '\0'; i++)
    {
        check_word[i] = tolower(check_word[i]);
        
    }  
    int ind = hash(check_word);
    if (table[ind] != NULL)
    {
        for (node* nodeptr = table[ind]; nodeptr != NULL; nodeptr = nodeptr->next)
            if (strcmp(nodeptr->word, check_word) == 0)
                return true;
                
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    int a = (int)word[0];
    int b = (int)word[1];
    if (strlen(word) == 0)
    {
        return 1;
    }
    if (97 <= a &&  a <= 122)
    {
        a -= 96;
    }
    if (97 <= b &&  b <= 122)
    {
        b -= 96;
    }
    
    else
        a -= 64;
        b -= 64;
    return a*b;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    char word[LENGTH + 1];
    node *ptr;
    FILE *files = fopen(dictionary,"r");
    if (files == NULL)
    {
        return false;
    }
    //read from file
    for (int i = 0; i < N ; i++)
        table[i] = NULL;
    while (fscanf(files, "%s", word) != EOF)
    {
        if (ptr == NULL)
        {
            return 1;
        }
        do
        {
            ptr = malloc(sizeof(node));
            if (ptr == NULL)
                free(ptr);
        } while (ptr == NULL);
        wcntr++;    
        strcpy(ptr->word, word);
        int ind = hash(word);
        ptr->next = table[ind];
        table[ind] = ptr;
    }
    
    fclose(files);
    load_check = true;
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    if (!load_check)
        return 0;
    return wcntr;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    if (!load_check)
        return false;
    
    for (int i = 0; i < N; i++)
    {
        if (table[i] != NULL)
        {
            node *pt = table[i];
            while (pt != NULL)
            {
                node *p = pt;
                pt = pt->next;
                free(p);
            }
        }
    }
    return true;
}
