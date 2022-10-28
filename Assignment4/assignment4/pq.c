/*
 * In this file, you will write the structures and functions needed to
 * implement a priority queue.  Feel free to implement any helper functions
 * you need in this file to implement a priority queue.  Make sure to add your
 * name and @oregonstate.edu email address below:
 *
 * Name: Joseph Murche
 * Email: murchej@oregonstate.edu
 */

#include <stdlib.h>

#include "pq.h"
#include "dynarray.h"

/*
 * This is the structure that represents a priority queue.  You must define
 * this struct to contain the data needed to implement a priority queue.
 */

struct pq_node {
	int priority;
	void* value;

};


struct pq {
	struct dynarray* array;

};



/*
 * This function should allocate and initialize an empty priority queue and
 * return a pointer to it.
 */
struct pq* pq_create() {
	
	struct pq* pq = malloc(sizeof(struct pq));

	pq->array = dynarray_create();
	 
	return pq;
}


/*
 * This function should free the memory allocated to a given priority queue.
 * Note that this function SHOULD NOT free the individual elements stored in
 * the priority queue.  That is the responsibility of the caller.
 *
 * Params:
 *   pq - the priority queue to be destroyed.  May not be NULL.
 */
void pq_free(struct pq* pq) {
	
	dynarray_free(pq->array);

	free(pq);

	return;
}


/*
 * This function should return 1 if the specified priority queue is empty and
 * 0 otherwise.
 *
 * Params:
 *   pq - the priority queue whose emptiness is to be checked.  May not be
 *     NULL.
 *
 * Return:
 *   Should return 1 if pq is empty and 0 otherwise.
 */
int pq_isempty(struct pq* pq) {
	
	if(dynarray_size(pq->array) == 0){

		return 1;
	}
	
	else{

		return 0;
	}
}


/*
 * This function should insert a given element into a priority queue with a
 * specified priority value.  Note that in this implementation, LOWER priority
 * values are assigned to elements with HIGHER priority.  In other words, the
 * element in the priority queue with the LOWEST priority value should be the
 * FIRST one returned.
 *
 * Params:
 *   pq - the priority queue into which to insert an element.  May not be
 *     NULL.
 *   value - the value to be inserted into pq.
 *   priority - the priority value to be assigned to the newly-inserted
 *     element.  Note that in this implementation, LOWER priority values
 *     should correspond to elements with HIGHER priority.  In other words,
 *     the element in the priority queue with the LOWEST priority value should
 *     be the FIRST one returned.
 */
void pq_insert(struct pq* pq, void* value, int priority) {
	
	struct pq_node* new_node = malloc(sizeof(struct pq_node));

	new_node->priority = priority;

	new_node->value = value;

	//int index = dynarray_size(pq->array);

	dynarray_insert(pq->array, new_node);

	heapify(pq, dynarray_size(pq->array) - 1); //calls heapify

	
}



void heapify(struct pq* pq, int index){ //percolates up
  
  	while (index > 0) {
		
		int parent_node = (index - 1) / 2;
		
		struct pq_node* idx = dynarray_get(pq->array, index);
		
		struct pq_node* parent = dynarray_get(pq->array, parent_node);
		
		if (idx->priority >= parent->priority){

			break;
		} 

		
		dynarray_set(pq->array, index, parent);
		
		dynarray_set(pq->array, parent_node, idx);
		
		index = parent_node;
	}


}




void heapify_down(struct pq* pq, int index) { //percolate down 
	
	int left = (2 * index) + 1;
	
	int right = (2 * index) + 2;
	
	struct pq_node* left_pri;
	
	struct pq_node* right_pri;
	
	struct pq_node* index_pri;

	
	if(left >= dynarray_size(pq->array)) {
		
		left_pri = NULL;
	} 
	
	else {
		
		left_pri = dynarray_get(pq->array, left);
	}
	
	if(right >= dynarray_size(pq->array)) {
		
		right_pri = NULL;
	} 
	
	else {
		
		right_pri = dynarray_get(pq->array, right);
	}

	if(index >= dynarray_size(pq->array)) {
		
		return;
	} 
	
	else {
		
		index_pri = dynarray_get(pq->array, index);
	}

	if(left_pri == NULL && right_pri == NULL){

		return;
	}
	
	if(left_pri != NULL && right_pri == NULL) {
		
		if(index_pri->priority > left_pri->priority) {
			
			dynarray_set(pq->array, index, left_pri);
			
			dynarray_set(pq->array, left, index_pri);
			
			heapify_down(pq, left);
		} 
		
		else{
			
			return;
		} 
	} 
	
	else if (left_pri == NULL && right_pri != NULL) {
		
		if (index_pri->priority > right_pri->priority) {
			
			dynarray_set(pq->array, index, right_pri);
			
			dynarray_set(pq->array, right, index_pri);
			
			index = right;
			
			heapify_down(pq, right);
		} 
		else{
			
			return;
		}
	} 
	
	else if(left_pri != NULL && right_pri != NULL) {
		
		if(left_pri->priority < right_pri->priority) {
			
			dynarray_set(pq->array, index, left_pri);
			
			dynarray_set(pq->array, left, index_pri);
			
			heapify_down(pq, left);
		} 
		
		else {
			
			dynarray_set(pq->array, index, right_pri);
			
			dynarray_set(pq->array, right, index_pri);
			
			heapify_down(pq, right);
		}
	}
}



void swap(int *a, int *b){
   
    int temp = *a;
    *a = *b;
    *b = temp;
}



/*
 * This function should return the value of the first item in a priority
 * queue, i.e. the item with LOWEST priority value.
 *
 * Params:
 *   pq - the priority queue from which to fetch a value.  May not be NULL or
 *     empty.
 *
 * Return:
 *   Should return the value of the first item in pq, i.e. the item with
 *   LOWEST priority value.
 */
void* pq_first(struct pq* pq) {

	struct pq_node* first = dynarray_get(pq->array, 0); //gets first element in the queue 
	
	void * value = first->value;
	
	return value;
}


/*
 * This function should return the priority value of the first item in a
 * priority queue, i.e. the item with LOWEST priority value.
 *
 * Params:
 *   pq - the priority queue from which to fetch a priority value.  May not be
 *     NULL or empty.
 *
 * Return:
 *   Should return the priority value of the first item in pq, i.e. the item
 *   with LOWEST priority value.
 */
int pq_first_priority(struct pq* pq) {
	
	struct pq_node* node = dynarray_get(pq->array, 0);

	int priority = node->priority; //set to integer variable

	return priority;
}


/*
 * This function should return the value of the first item in a priority
 * queue, i.e. the item with LOWEST priority value, and then remove that item
 * from the queue.
 *
 * Params:
 *   pq - the priority queue from which to remove a value.  May not be NULL or
 *     empty.
 *
 * Return:
 *   Should return the value of the first item in pq, i.e. the item with
 *   LOWEST priority value.
 */
void* pq_remove_first(struct pq* pq) {

	struct pq_node* first_node = dynarray_get(pq->array, 0);

	void* temp = first_node->value;

	free(first_node); //free memory

	dynarray_set(pq->array, 0, dynarray_get(pq->array, dynarray_size(pq->array) - 1));
	
	dynarray_remove(pq->array, dynarray_size(pq->array) - 1);
	
	heapify_down(pq, 0);

  	return temp;
	
}
