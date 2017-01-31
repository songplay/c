/*
 * Hash Table
 *	12/28/2016
 */
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef	struct node {
	int	key;
	void	*payload;
} NODE;

typedef struct linkedlist {
	NODE *node;
	struct linkedlist *next;
} LinkedList;

#define		HASH_TABLE_SIZE	100	
LinkedList	*HashTable[HASH_TABLE_SIZE];

void 
HashTableInit()
{
	int	k;

	for(k=0; k<HASH_TABLE_SIZE; k++)
		HashTable[k] = NULL;
}

/* caculate the hash table key */
uint32_t
HashKey(int key)
{
	uint32_t	index;

	index = key % HASH_TABLE_SIZE;
	return	index;
}

/* caculate the hash table key */
uint32_t
HashKey2(char *key_str)
{
	uint32_t	index = 0;
	int	k,  len;
	uint8_t	*c;

	len = strlen(key_str);
	c = (uint8_t *) key_str;
	for (k =0; k < len; k++) {
		index += ((uint8_t) *c) * k;
		c++;
	}

	index = index % HASH_TABLE_SIZE;
	return	index;
}

/* Add one node to hash table */
HashAdd(NODE *node)
{
	uint32_t	index;
	LinkedList	*p;
	LinkedList	*new;

	new = (LinkedList *) malloc(sizeof (LinkedList));
	new->node = node;
	new->next = NULL;
	
	index = HashKey(node->key);
	if (HashTable[index] == NULL)
		HashTable[index] = new;
	else {
		p = HashTable[index];
		while (p->next != NULL)
			p = p->next;
	
		p->next = new;
	}
	return	index;
}


/* Search one node in hash table */
NODE *
HashFind(int key)
{
	uint32_t	index;
	LinkedList	*p;

	index = HashKey(key);
	p = HashTable[index];

	if (p == NULL)
		return	NULL;

	while (p->next != NULL)
		if (p->node->key == key)
			return	p->node;
		else
			p = p->next;

	return	NULL;
}

/* Remove one node from hash table */
NODE *
HashDel(int key)
{
	uint32_t	index;
	LinkedList	*p;
	NODE		*n;

	index = HashKey(key);
	p = HashTable[index];

	if (p == NULL)
		return	NULL;

	if (p->node->key == key) { // found it
		HashTable[index] = p->next;
		n = p->node;
		free(p);
		return	n;
	}

	while (p->next != NULL)
		if (p->next->node->key == key) { // found it
			n = p->next->node;
			p->next = p->next->next;
			free(p->next);
			return	n;
		} else
			p = p->next;

	return	NULL;
}


main()
{
	printf("index=%d\n", HashKey2("acb"));
	printf("index=%d\n", HashKey2("abc"));
	printf("index=%d\n", HashKey2("cba"));

	printf("index=%d\n", HashKey2("song"));
	printf("index=%d\n", HashKey2("ongs"));

}
