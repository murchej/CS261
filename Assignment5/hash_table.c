/*
 * In this file, you will write the structures and functions needed to
 * implement a hash ht.  Feel free to implement any helper functions
 * you need in this file to implement a hash ht.  Make sure to add your
 * name and @oregonstate.edu email address below:
 *
 * Name: Joseph Murche
 * Email: murchej@oregonstate.edu
 */

#include <stdlib.h>

#include "dynarray.h"
#include "list.h"
#include "hash_table.h"
#include <ctype.h>
#include <assert.h>
#include <math.h>

/*
 * This is the structure that represents a hash ht.  You must define
 * this struct to contain the data needed to implement a hash ht.
 */

typedef struct item item;
typedef struct ht ht;

struct item{
void *key;
void *value;
};

struct ht{
item** items;
int size;
int capacity;
};

struct item* dummy;



/*
 * This function should allocate and initialize an empty hash ht and
 * return a pointer to it.
 */
struct ht* ht_create(){
    
    ht* ht = calloc((size_t) ht->capacity, sizeof(ht));

    ht->size = 0;

    ht->capacity = 2;

    ht->items = calloc((size_t) ht->capacity, sizeof(item*));

    

    return ht;
}

/*
 * This function should free the memory allocated to a given hash ht.
 * Note that this function SHOULD NOT free the individual elements stored in
 * the hash ht.  That is the responsibility of the caller.
 *
 * Params:
 *   ht - the hash ht to be destroyed.  May not be NULL.
 */
void ht_free(struct ht* ht){
    
   for(int i = 0; i < ht->capacity; i++){

       free(ht->items[i]->key);
   }
   
   free(ht->items);

    free(ht);
}


/*
 * This function should return 1 if the specified hash ht is empty and
 * 0 otherwise.
 *
 * Params:
 *   ht - the hash ht whose emptiness is to be checked.  May not be
 *     NULL.
 *
 * Return:
 *   Should return 1 if ht is empty and 0 otherwise.
 */
int ht_isempty(struct ht* ht){
    
    if(ht->items[0] != NULL){

        return 0;
    }
    else{

        return 1;
    }
}


/*
 * This function returns the size of a given hash ht (i.e. the number of
 * elements stored in it, not the capacity).
 */
int ht_size(struct ht* ht){
    
    int size = ht->size;

    return size;
}


/*
 * This function takes a key, maps it to an integer index value in the hash ht,
 * and returns it. The hash algorithm is totally up to you. Make sure to consider
 * Determinism, Uniformity, and Speed when design the hash algorithm
 *
 * Params:
 *   ht - the hash ht into which to store the element.  May not be NULL.
 *   key - the key of the element to be stored
 *   convert - pointer to a function that can be passed the void* key from
 *     to convert it to a unique integer hashcode
 */
int ht_hash_func(struct ht* ht, void* key, int (*convert)(void*)){
   
    int hashval = convert_int(key);

    
    hashval += ht->size;

    return hashval;
}

int cmp(void* x, void* y){
	int* a = x, *b = y;
	
    return *a > *b ? 1 : 0;
}

/*
 * This function should insert a given element into a hash ht with a
 * specified key.  Note that you cannot have two same keys in one hash ht.
 * If the key already exists, update the value associated with the key.  
 * This function is passed a function pointer that is used to convert the key (void*) 
 * to a unique hashcode (int). 
 * Resolution of collisions is requried, use either chaining or open addressing.
 * If using chaining, double the number of buckets when the load factor is >= 4
 * If using open addressing, double the array capacity when the load factor is >= 0.75
 * load factor = (number of elements) / (hash ht capacity)
 *
 * Params:
 *   ht - the hash ht into which to insert an element.  May not be NULL.
 *   key - the key of the element
 *   value - the value to be inserted into ht.
 *   convert - pointer to a function that can be passed the void* key from
 *     to convert it to a unique integer hashcode
 */

void ht_insert(struct ht* ht, void* key, void* value, int (*convert)(void*)){


    item* new = malloc(sizeof(struct item));

    new->key = key;

    new->value = value;

     int hash_index = ht_hash_func(ht->items, key, convert_int(key));

    item* curr = ht->items[hash_index];

    if(ht->capacity == ht->size){

        ht->capacity *= 2;
    }


    while (ht->items[hash_index] != 0){

        hash_index++;
        hash_index %= ht->capacity;
    }
    
    if(curr == 0){

        ht->size++;

        ht->items[hash_index] = new;

    }

    else if(curr == ht->items[hash_index]){

        hash_index++;
        ht->items[hash_index]->value = value;
    }
    
    ht->capacity--;
    
}



/*
 * This function should search for a given element in a hash ht with a
 * specified key provided.   
 * This function is passed a function pointer that is used to convert the key (void*) 
 * to a unique hashcode (int). 
 * If the key is found, return the corresponding value (void*) of the element,
 * otherwise, return NULL
 *
 * Params:
 *   ht - the hash ht into which to loop up for an element.  May not be NULL.
 *   key - the key of the element to search for
 *   convert - pointer to a function that can be passed the void* key from
 *     to convert it to a unique integer hashcode
 */
void* ht_lookup(struct ht* ht, void* key, int (*convert)(void*)){

    int hash_index = ht_hash_func(ht->items, key, convert_int(key));

    item* temp = ht->items[hash_index]; 
    
    int count = 0;

    while(ht->items[hash_index] != 0){

        

        if(count++ > ht->capacity)
            break;
        

        if(ht->items[hash_index]->key == key){

            return temp->value;
        

            hash_index++;
            hash_index %= ht->capacity;

        }

        else{

            return NULL;
        }
        }
        
    
}


/*
 * This function should remove a given element in a hash ht with a
 * specified key provided.   
 * This function is passed a function pointer that is used to convert the key (void*) 
 * to a unique hashcode (int). 
 * If the key is found, remove the element and return, otherwise, do nothing and return 
 *
 * Params:
 *   ht - the hash ht into which to remove an element.  May not be NULL.
 *   key - the key of the element to remove
 *   convert - pointer to a function that can be passed the void* key from
 *     to convert it to a unique integer hashcode
 */
void ht_remove(struct ht* ht, void* key, int (*convert)(void*)){

    int hash_index = ht_hash_func(ht->items, key, convert_int(key)); 

    item* temp = ht->items[hash_index];

    int i = 1;

    while(temp != NULL){

        if(temp->key == key){

            ht->items[hash_index] = dummy;

            free(temp);

            ht->size--;

            return;
        }

        else{

            return;
        }
    }


} 
