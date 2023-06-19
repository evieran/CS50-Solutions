// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Define the node of the linked list
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// Number of words in the dictionary
unsigned int word_count = 0;

// Hash table
node *table[N];

// Implement load
bool load(const char *dictionary)
{
    // Open dictionary file
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }

    // Buffer for a word\char word[LENGHT +1];

    // Load each word from the dictionary
    while (fscanf(file, "%s", word) != EOF)
    {
        // Create a new node
        node *new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            unload();
            return false;
        }

        // Copy word into node
        strcpy(new_node->word, word);

        // Get the hash value for the word
        unsigned int hash_value = has(word);

        // Insert the node into the hash table
        new_node->next = table[hash_value];
        table[hash_value] = new_node;

        // Increment the word count
        word_count++;
    }

    // Close dictionary file
    fclose(file);

    // Indicate success
    return true;
}

// Implement hash


// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    return false;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    return false;
}
