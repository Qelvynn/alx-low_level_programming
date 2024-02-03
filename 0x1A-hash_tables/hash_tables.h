// A header guard to prevent multiple inclusions of the same header file
#pragma once

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * struct hash_node_s - Node of a hash table
 *
 * @key: The key, string
 * The key is unique in the HashTable
 * @value: The value corresponding to a key
 * @next: A pointer to the next node of the List
 */
typedef struct hash_node_s
{
	char *key;
	char *value;
	struct hash_node_s *next;
} hash_node_t;

/**
 * struct hash_table_s - Hash table data structure
 *
 * @size: The size of the array
 * @array: An array of size @size
 * Each cell of this array is a pointer to the first node of a linked list,
 * because we want our HashTable to use a Chaining collision handling
 */
typedef struct hash_table_s
{
	size_t size;
	hash_node_t **array;
} hash_table_t;

/**
 * hash_table_create - Creates a hash table
 * @size: The size of the array
 * Return: A pointer to the newly created hash table, or NULL if something went wrong
 */
hash_table_t *hash_table_create(size_t size);

/**
 * hash_djb2 - Implements the djb2 hash function
 * @str: The string to be hashed
 * Return: The hash value of the string
 */
unsigned long int hash_djb2(const unsigned char *str);

/**
 * key_index - Gives the index of a key in a hash table
 * @key: The key to be indexed
 * @size: The size of the hash table
 * Return: The index where the key should be stored
 */
size_t key_index(const unsigned char *key, size_t size);

/**
 * hash_table_set - Adds an element to the hash table
 * @ht: The hash table to add or update the key/value to
 * @key: The key, cannot be an empty string
 * @value: The value associated with the key, can be an empty string
 * Return: 1 if it succeeded, 0 otherwise
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value);

/**
 * hash_table_get - Retrieves a value associated with a key
 * @ht: The hash table to look into
 * @key: The key to look for
 * Return: The value associated with the key, or NULL if key couldn’t be found
 */
char *hash_table_get(const hash_table_t *ht, const char *key);

/**
 * hash_table_print - Prints a hash table
 * @ht: The hash table to be printed
 * Prints the key/value in the order that they appear in the array of hash table
 * Order: array, list
 */
void hash_table_print(const hash_table_t *ht);

/**
 * hash_table_delete - Deletes a hash table
 * @ht: The hash table to be deleted
 * Frees the memory allocated for the hash table
 */
void hash_table_delete(hash_table_t *ht);

/**
 * struct shash_node_s - Node of a sorted hash table
 *
 * @key: The key, string
 * The key is unique in the HashTable
 * @value: The value corresponding to a key
 * @next: A pointer to the next node of the List
 * @sprev: A pointer to the previous element of the sorted linked list
 * @snext: A pointer to the next element of the sorted linked list
 */
typedef struct shash_node_s
{
	char *key;
	char *value;
	struct shash_node_s *next;
	struct shash_node_s *sprev;
	struct shash_node_s *snext;
} shash_node_t;

/**
 * struct shash_table_s - Sorted hash table data structure
 *
 * @size: The size of the array
 * @array: An array of size @size
 * Each cell of this array is a pointer to the first node of a linked list,
 * because we want our HashTable to use a Chaining collision handling
 * @shead: A pointer to the first element of the sorted linked list
 * @stail: A pointer to the last element of the sorted linked list
 */
typedef struct shash_table_s
{
	size_t size;
	shash_node_t **array;
	shash_node_t *shead;
	shash_node_t *stail;
} shash_table_t;

/**
 * shash_table_create - Creates a sorted hash table
 * @size: The size of the array
 * Return: A pointer to the newly created hash table, or NULL if something went wrong
 */
shash_table_t *shash_table_create(size_t size);

/**
 * shash_table_set - Adds an element to the sorted hash table
 * @ht: The sorted hash table to add or update the key/value to
 * @key: The key, cannot be an empty string
 * @value: The value associated with the key, can be an empty string
 * Return: 1 if it succeeded, 0 otherwise
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value);

/**
 * shash_table_print - Prints a sorted hash table
 * @ht: The sorted hash table to be printed
 * Prints the key/value in the order that they are sorted in the linked list
 */
void shash_table_print(const shash_table_t *ht);

/**
 * shash_table_get - Retrieves a value associated with a key
 * @ht: The sorted hash table to look into
 * @key: The key to look for
 * Return: The value associated with the key, or NULL if key couldn’t be found
 */
char *shash_table_get(const shash_table_t *ht, const char *key);

/**
 * shash_table_print_rev - Prints a sorted hash table in reverse order
 * @ht: The sorted hash table to be printed
 * Prints the key/value in the reverse order that they are sorted in the linked list
 */
void shash_table_print_rev(const shash_table_t *ht);

/**
 * shash_table_delete - Deletes a sorted hash table
 * @ht: The sorted hash table to be deleted
 * Frees the memory allocated for the sorted hash table
 */
void shash_table_delete(shash_table_t *ht);
