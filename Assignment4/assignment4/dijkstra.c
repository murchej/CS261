/*
 * In this file, you'll implement Dijkstra's algorithm to find the least
 * expensive paths in the graph defined in `airports.dat`.  Don't forget to
 * include your name and @oregonstate.edu email address below.
 *
 * Name: Joseph Murche
 * Email: murchej@oregonstate.edu
 */

#include <stdio.h>
#include <stdlib.h>

#define DATA_FILE "airports.dat"
#define START_NODE 0
#define MAXCOST 100000 //top of cost range, used for calculations

struct node {
	
	int key;
	
	int cost;
	
	struct node* prev;

};



void print_path(struct node* node) {
	
	if (node->prev != NULL) {
		
		print_path(node->prev);
		
		printf(" -> "); //arrowing indicating best path for airplane
	}
	
	printf("%d", node->key);
}



struct node* nw_node(int key) {
	
	struct node* new_node = malloc(sizeof(struct node));
	
	new_node->key = key;
	
	new_node->cost = MAXCOST;
	
	new_node->prev = NULL;
	
	return new_node;
}




struct node_t {
	
	struct node* prev;
	
	struct node* next;

};


struct node_t* nw_nodet(struct node* node, struct node* prev) {
	
	struct node_t* nodet = malloc(sizeof(struct node_t));
  	
	nodet->prev = prev;
	
	nodet->next = node;
  	
	return nodet;
}



void Dijkstra(int** graph, int n_nodes, int start_node) {  //function storing algorithm
	
	struct node** new_node = malloc(n_nodes * sizeof(struct node*));
	
	for (int i = 0; i < n_nodes; i++) {
		
		new_node[i] = nw_node(i);
	}

	
	struct pq* pq = pq_create();
	
	pq_insert(pq, nw_nodet(new_node[START_NODE], NULL), 0);

	while (!pq_isempty(pq)) {
		
		int c = pq_first_priority(pq);
		
		struct node_t* nodet = pq_remove_first(pq);
		
		struct node* n = nodet->next;

		if (c < n->cost) {
			
			n->cost = c;
			
			n->prev = nodet->prev;

			for (int i = 0; i < n_nodes; i++) {
				
				if (graph[n->key][i]) {
          				
					pq_insert(pq, nw_nodet(new_node[i], n), c + graph[n->key][i]);
				}
			}
		}

		free(nodet);
	}

	for (int i = 0; i < n_nodes; i++) {
		
		print_path(new_node[i]);
		
		printf(": %d\n", new_node[i]->cost);
	}

	pq_free(pq);
	
	for (int i = 0; i < n_nodes; i++) free(new_node[i]);
	
	free(new_node);


}




int main(int argc, char const *argv[]) {

	int n_nodes, n_edges, xnode, ynode;
	
	FILE* file = fopen(DATA_FILE, "r");
	
	fscanf(file, " %d %d ", &n_nodes, &n_edges);
	
	
	int** matrix = malloc(n_nodes * sizeof(int*));
	
	for (int i = 0; i < n_nodes; i++) matrix[i] = calloc(n_nodes, sizeof(int));

	for (int j = 0; j < n_edges; j++) {
		
		fscanf(file, "%d", &ynode);
		
		fscanf(file, "%d", &xnode);
		
		fscanf(file, "%d", &matrix[ynode][xnode]);
	}
	

	fclose(file);

	printf("\n\n\nMatrix:\n\n");
	
	for (int i = 0; i < n_nodes; i++) {
  		
		  printf("[");
  		
		  for (int j = 0; j < n_nodes; j++) {
    			
				printf("%5d", matrix[i][j]); //print the matrix 
    			
				if (j < n_nodes - 1){
					
					printf(", ");
  		}
  		
		  printf("]\n");
	}

	printf("\n\n\nPath Sum:\n\n");
	
	Dijkstra(matrix, n_nodes, START_NODE);

	for (int i = 0; i < n_nodes; i++) {
		
		free(matrix[i]); //iterate through to free memory

		
	}
	
	free(matrix); //free memory

	 
  return 0;
}

}